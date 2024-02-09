(load "gpp_lexer.lisp")
(defvar input-string "")


(defvar shift-reduce-parser-stack (list))   ;This list represents stack of shift reduce parser,keeps in format (("(" "OP")("+" "OP_OLUS") ("id1" "3f5")...)


(defvar id-keeper (list))  ;This list keeps list of id's and their values  in format   ( ("id1" "3f5") ("id2" "2f7") ("id4" "8f9999") )

(defvar function-keeper (list))      ;This list keeps list of function id's and their strings  in format   ( ("foo1" "(deffun foo1(   ...") ... )




(defvar fcall-counter 0)



(defun get-int-part-int-value(fraction-string)

	(setq int-val 0)

	(setq int-val (parse-integer (subseq fraction-string 0 (position #\f fraction-string))))

)

(defun get-frac-part-int-value(fraction-string)

	(setq frac-val 0)

	(setq frac-val 
		(parse-integer (subseq fraction-string  (+ 1 (position #\f fraction-string)) (length fraction-string))
		)
	)
)




(defun simplify-fraction-helper(int-part frac-part divisor)

	(if(eq divisor 1)

		(progn
			(setq result (concatenate 'string (write-to-string int-part) "f" (write-to-string frac-part)))
		)

		(if(and (eq (mod int-part divisor) 0) (eq (mod frac-part divisor) 0) )
			(simplify-fraction-helper ( / int-part divisor ) (/ frac-part divisor) divisor)
			(simplify-fraction-helper  int-part  frac-part ( - divisor 1) )
		)
	)
	
)





;This function simplifies fractions
;Ex:
;	"12f28"  ==>  "3f7"
(defun  simplify-fraction(frac)
	(setq result "")
	(setq int-part (get-int-part-int-value frac))
	(setq frac-part (get-frac-part-int-value frac))
	(if( < int-part frac-part) 
		(simplify-fraction-helper int-part frac-part frac-part)
		(simplify-fraction-helper int-part frac-part int-part)
	)
	result
)






;This function adds two fraction and returns result
;Ex:
;"8f9" and "1f2"
;	8   1      16    9       25
;	- + -   =  --  + -    =  --     ===>    "25f18"
;	9   2      18    18		 18
(defun add-fraction(frac1 frac2)

	(setq frac1-int-part (get-int-part-int-value frac1))
	(setq frac1-frac-part (get-frac-part-int-value frac1))
	(setq frac2-int-part (get-int-part-int-value frac2))
	(setq frac2-frac-part (get-frac-part-int-value frac2))

	(setq result-frac-part ( *  frac1-frac-part  frac2-frac-part ))

	(setq result-int-part (+ ( * frac1-int-part frac2-frac-part) ( * frac2-int-part frac1-frac-part)))


	(setq result (concatenate 'string (write-to-string result-int-part) "f" (write-to-string result-frac-part)))

	(setq result (simplify-fraction result))

)




;This function subtracts frac2 from frac1 and returns result
;So,it sums frac1 + -(frac2)
(defun subtract-fraction(frac1 frac2)
	(setq subtracted-frac (concatenate 'string "-" frac2))
	(setq result (add-fraction frac1 subtracted-frac))
)




;This function multiplies two fraction and returns result
;Ex:
;"8f9" and "1f2"
;	8   1     8    4
;	- * -  = --  = -  ===>    "4f9"
;	9   2    18    9

(defun mult-fraction(frac1 frac2)
	(setq frac1-int-part (get-int-part-int-value frac1))
	(setq frac1-frac-part (get-frac-part-int-value frac1))
	(setq frac2-int-part (get-int-part-int-value frac2))
	(setq frac2-frac-part (get-frac-part-int-value frac2))

	(setq result-frac-part ( *  frac1-frac-part  frac2-frac-part ))

	(setq result-int-part ( * frac1-int-part frac2-int-part) )


	(setq result (concatenate 'string (write-to-string result-int-part) "f" (write-to-string result-frac-part)))

	(setq result (simplify-fraction result))
)








;This function divides frac1 to frac2 and returns result
;Ex: 
;"8f9" and "1f2"
;	8   1     8   2    16
;	- % -  =  - * -  = -     ===>    "16f9"
;	9   2     9   1    9
(defun div-fraction(frac1 frac2)
	(setq frac1-int-part (get-int-part-int-value frac1))
	(setq frac1-frac-part (get-frac-part-int-value frac1))
	(setq frac2-int-part (get-frac-part-int-value frac2))
	(setq frac2-frac-part (get-int-part-int-value frac2))

	(setq result-frac-part ( *  frac1-frac-part  frac2-frac-part ))

	(setq result-int-part ( * frac1-int-part frac2-int-part) )


	(setq result (concatenate 'string (write-to-string result-int-part) "f" (write-to-string result-frac-part)))

	(setq result (simplify-fraction result))
)





;Checks equality of two fractions
;Ex:
;	"2f4" "3f6" returns "1"
;	"3f4" "4f3" returns "0"
(defun isFractionEqual(frac1 frac2)
	(setq res "0")
	(if(string= (simplify-fraction frac1) (simplify-fraction frac2))
		(setq res "1")
	)
	res
)



;This function is given two strings like "3f2" "2f5"...
;Applies subtraction as frac1-frac2
;Checks if result contains minus at the beginning to check if frac1 is greater or not
(defun isFractionGT(frac1 frac2)
	(setq diff (subtract-fraction frac1 frac2))
	(setq res "0")


	(if(not (char= #\- (char diff 0)))
		(setq res "1")
	)

	res
)


;And operation
(defun expb-and(expb1 expb2)
	(setq res "0")
	(if(and (string= expb1 "1") (string= expb2 "1"))
		(setq res "1")
	)

	res
)


;Or operation
(defun expb-or(expb1 expb2)
	(setq res "0")
	(if(or (string= expb1 "1") (string= expb2 "1"))
		(setq res "1")
	)

	res
)


;Not operation
(defun expb-not(expb1)
	(setq res "0")
	(if(string= expb1 "0")
		(setq res "1")
	)

	res
)




;This function applies shift operation
;mainlist represents input buffer
;shift-reduce-parser-stack represents stack
(defun parser-shift()
	(setf temp (copy-tree (car mainlist)))
	(setf shift-reduce-parser-stack (append shift-reduce-parser-stack (list temp)))
	(setf mainlist (cdr mainlist))
)






;This function checks if programmer tries to declare a variable with the same name of existing ones
(defun has-id-declared-before(index id-str)
	(setq res nil)
	(if(eq index (length id-keeper))
		(progn
			(setq res nil)
			res
		)
		(progn
			(if(string= (nth 0 (nth index id-keeper)) id-str)
				(progn
					(setq res t)
					res
				)
				(has-id-declared-before (+ 1 index) id-str)
			)

		)
	)
	res
)




;This function is given an id name and returns it's value
;Ex: if variable x has declared before with value "2f5",this function returns "2f5"
(defun get-id-value-from-id-keeper(index id-str)
	(setq res nil)
	(if(eq index (length id-keeper))
		(progn
			(setq res nil)
			res
		)
		(progn
			(if(string= (nth 0 (nth index id-keeper)) id-str)
				(progn
					(setq res (copy-tree (nth 1 (nth index id-keeper))))
					res
				)
				(get-id-value-from-id-keeper (+ 1 index) id-str)
			)

		)
	)
	res
)



;This function looks for existing id s declared before
;Changes it's value to new-val
;Used for set operation
(defun set-id-value-from-id-keeper(index id-str new-val)
	(if(eq index (length id-keeper))
		(progn
			(setq res nil)
		)
		(progn
			(if(string= (nth 0 (nth index id-keeper)) id-str)
				(progn
					(setf (nth 1 (nth index id-keeper)) new-val)
					(setq res new-val)
				)
				(set-id-value-from-id-keeper (+ 1 index) id-str new-val)
			)

		)
	)
)





;when a function is defined,this function looks at stack and generates a string "( deffun ( x ) ( ...."
;This string is stored for later fcalls
(defun get-function-body-from-stack (index func-body)
	(setq res nil)
	(if(eq index (length shift-reduce-parser-stack))
		(progn
			(setq res func-body)
		)
		(progn
			#|(if(string= (nth 0 (nth index id-keeper)) id-str)
				(progn
					(setf (nth 1 (nth index id-keeper)) new-val)
					(setq res new-val)
				)
				(set-id-value-from-id-keeper (+ 1 index) id-str new-val)
			)|#
	
			(get-function-body-from-stack (+ 1 index) (concatenate 'string func-body (nth 0 (nth index shift-reduce-parser-stack)) " "))
		)
	)
	res

)





;This function checks if programmer tries to declare a variable with the same name of existing ones
(defun has-func-declared-before(index func-name)
	(setq res nil)
	(if(eq index (length function-keeper))
		(progn
			(setq res nil)
			res
		)
		(progn
			(if(string= (nth 0 (nth index function-keeper)) func-name)
				(progn
					(setq res t)
					res
				)
				(has-func-declared-before (+ 1 index) func-name)
			)

		)
	)
	res
)



(defun add-function-to-function-keeper(func-name func-body)
	(if( not (has-func-declared-before 0 func-name) )
		(setf function-keeper (append function-keeper (list (list func-name func-body))))
		(progn
			(write-line "Function has declared before,terminating...")
		)
	)
	
)





;This function is given an id name and returns it's value
;Ex: if variable x has declared before with value "2f5",this function returns "2f5"
(defun get-function-body-from-function-keeper(index id-str)
	(setq res nil)
	(if(eq index (length function-keeper))
		(progn
			(setq res nil)
			res
		)
		(progn
			(if(string= (nth 0 (nth index function-keeper)) id-str)
				(progn
					(setq res (copy-tree (nth 1 (nth index function-keeper))))
					res
				)
				(get-function-body-from-function-keeper (+ 1 index) id-str)
			)

		)
	)
	res
)









;
;This function takes series of tokens in format (("(" "OP")("+" "OP_OLUS") ("id1" "3f5")...)
;Applies grammar rules
;Returns reduced version of tokens
;EX:
;
;	if tokens are (("(" "OP")("+" "OP_OLUS") ("3f5" "exp") ("4f5" "exp")(")""CP"))
;	returned result is ==> (("7f5" "exp"))
;
;	if send (("7f5" "exp")) again
;	result is (("7f5" "input"))
;
;	reduce-sublists-of-stack reduced ("3f5" "exp") and ("4f5" "exp") from valuef or id before by using this function again
;
(defun reduce-given-list(tokens)
	(setq result (copy-tree tokens))
	(setq token-names (copy-tree (mapcar #'cadr tokens)))

	(cond
		((equal token-names (list "input"))
			(progn
				(setf result (list (copy-tree (list (nth 0 (nth 0 result)) "start"))))
			)
		)
	
		( ( or (equal token-names (list "exp"))(equal token-names (list "explist")) 
			(equal token-names (list "function"))(equal token-names (list "fcall")))
			(progn
				(setf result (list (copy-tree (list (nth 0 (nth 0 result)) "input"))))
			)
		)



		((equal token-names (list "OP" "OP_PLUS" "exp" "exp" "CP"))
			(progn
				(setq val1 (nth 0 (nth 2 result)))
				(setq val2 (nth 0 (nth 3 result)))
				(setq result-val (add-fraction val1 val2))
				(setf result (list (copy-tree (list result-val "exp"))))
			)
		)

		((equal token-names (list "OP" "OP_MINUS" "exp" "exp" "CP"))
			(progn
				(setq val1 (nth 0 (nth 2 result)))
				(setq val2 (nth 0 (nth 3 result)))
				(setq result-val (subtract-fraction val1 val2))
				(setf result (list (copy-tree (list result-val "exp"))))
			)
		)

		((equal token-names (list "OP" "OP_DIV" "exp" "exp" "CP"))
			(progn
				(setq val1 (nth 0 (nth 2 result)))
				(setq val2 (nth 0 (nth 3 result)))
				(setq result-val (div-fraction val1 val2))
				(setf result (list (copy-tree (list result-val "exp"))))
			)
		)
		((equal token-names (list "OP" "OP_MULT" "exp" "exp" "CP"))
			(progn
				(setq val1 (nth 0 (nth 2 result)))
				(setq val2 (nth 0 (nth 3 result)))
				(setq result-val (mult-fraction val1 val2))
				(setf result (list (copy-tree (list result-val "exp"))))
			)
		)
		((equal token-names (list "VALUEF"))
			(progn
				(setf (nth 1 (nth 0 result)) "exp")
			)
		)



		((equal token-names (list "OP" "KW_IF" "expb" "exp" "CP"))
			(progn
				(if(string= (nth 0 (nth 2 result)) "1")
							(progn
								(setq result-val (nth 0 (nth 3 result)))
								(setf result (list (copy-tree (list result-val "exp"))))
							)
							(progn
								(setf result (list (copy-tree (list "nil" "exp"))))
							)
						)
			)
		)

		;Checks if id has declared before,if not adds id and its value to id-keeper
		((equal token-names (list "OP" "DEFV" "ID" "exp" "CP"))

				(setq has-declared-before (has-id-declared-before 0 (nth 0 (nth 2 result))) )


				(if(eq nil has-declared-before)
					(progn
						(setq temp-id (list (nth 0 (nth 2 result)) (nth 0 (nth 3 result))))
						(setf id-keeper (append id-keeper (list temp-id)))
						(setf result (list (copy-tree (list (nth 1 temp-id) "exp") )) )
					)
					(progn
						(write-line "Id has declared before...")

						(setf result (list (copy-tree (list "0f1" "exp") )) )
					)
				)
		)

		;Reduces ID to exp
		;Checks exceptions,if id is part of expressions of defvar set and deffun
		((and (equal token-names (list "ID")) (not (has-func-declared-before 0 (nth 0 (nth 0 result)))))
			(if(< 2 (length shift-reduce-parser-stack))
				(if (and ( not ( equal (nth 1 shift-reduce-parser-stack) (list "defvar" "DEFV") ) )
						 ( not ( equal (nth 1 shift-reduce-parser-stack) (list "set" "KW_SET") ) ) 
						 (or (not ( equal (nth 1 shift-reduce-parser-stack) (list "deffun" "DEFF") ) ) (not (string= (nth 0 ( nth 2 shift-reduce-parser-stack ))(nth 0 ( nth 0 result))  ))  ) 
					)
					(progn

						(if(has-id-declared-before 0 (nth 0 (nth 0 result)))
							(progn
								(setf result (list (copy-tree (list (get-id-value-from-id-keeper 0 (nth 0 (nth 0 result))) "exp") )) )
							)
							(progn
								(write-line (concatenate 'string "ID #\"" (nth 0 (nth 0 result)) "#\" has not declared before,terminating..." ))
								(exit)
							)
						)
					)
				)
				(progn
					(setf result (list (copy-tree (list "0f1" "exp") )) )
				)
			)
		)
		((equal token-names (list "fcall"))
			(setf result (list (copy-tree (list (nth 0 (nth 0 result)) "exp") )) )
		)
		((equal token-names (list "asg"))
			(setf result (list (copy-tree (list (nth 0 (nth 0 result)) "exp") )) )
		)
		((equal token-names (list "fcall"))		
			(setf result (list (copy-tree (list (nth 0 (nth 0 result)) "exp") )) )
		)

		((equal token-names (list "OP" "KW_WHILE" "expb" "exp" "CP"))
			(progn
				(if(string= (nth 0 (nth 2 result)) "1" ) ;while condition met

				)
				(setf result (list (copy-tree (list (nth 0 (nth 3 result)) "exp") )) )
			)
		)
		((equal token-names (list "OP" "OP_EQ" "exp" "exp" "CP"))
			(setq val1 (nth 0 (nth 2 result)))
			(setq val2 (nth 0 (nth 3 result)))
			(setq result-val (isFractionEqual val1 val2))
			(setf result (list (copy-tree (list result-val "expb"))))

		)
		((equal token-names (list "OP" "OP_GT" "exp" "exp" "CP"))
			(setq val1 (nth 0 (nth 2 result)))
			(setq val2 (nth 0 (nth 3 result)))
			(setq result-val (isFractionGT val1 val2))
			(setf result (list (copy-tree (list result-val "expb"))))
		)



		;expb rules , uses functions "expb_and" "expb_or" "expb_not"
		((equal token-names (list "KW_TRUE"))
			(setf result (list (copy-tree (list "1" "expb"))))
		)
		((equal token-names (list "KW_FALSE"))
			(setf result (list (copy-tree (list "0" "expb"))))
		)
		((equal token-names (list "OP" "OP_AND" "expb" "expb" "CP"))
			(setq val1 (nth 0 (nth 2 result)))
			(setq val2 (nth 0 (nth 3 result)))
			(setq result-val (expb-and val1 val2))
			(setf result (list (copy-tree (list result-val "expb"))))
		)
		((equal token-names (list "OP" "OP_OR" "expb" "expb" "CP"))
			(setq val1 (nth 0 (nth 2 result)))
			(setq val2 (nth 0 (nth 3 result)))
			(setq result-val (expb-or val1 val2))
			(setf result (list (copy-tree (list result-val "expb"))))
		)
		((equal token-names (list "OP" "OP_NOT" "expb" "CP"))
			(setq val1 (nth 0 (nth 2 result)))
			(setq result-val (expb-not val1 val1))
			(setf result (list (copy-tree (list result-val "expb"))))
		)



		;Conditions for explist to accept inputs like ( (+ 2f2 3f3) (/ 5f2 22f1) .... )
		((equal token-names (list "OP" "exp" "CP"))
			(setf result (list (copy-tree (list (nth 0 (nth 1 result)) "exp") )) )
		)
		((equal token-names (list "OP" "exp" "exp"))
			(setf result (copy-tree (append (list (list "(" "OP")) (list (list (nth 0 (nth 2 result)) "exp"))) ))
		)





		;if a variable declared before,finds it in id-keeper and changes it's value
		(  (equal token-names (list "OP" "KW_SET" "ID" "exp" "CP"))
		    
						(if(has-id-declared-before 0 (nth 0 (nth 2 result)))
							(progn
								(set-id-value-from-id-keeper 0 (nth 0 (nth 2 result)) (nth 0 (nth 3 result)))
								(setf result (list (copy-tree (list (nth 0 (nth 3 result)) "asg") )) )
							)
							(progn
								(write-line (concatenate 'string "ID #\"" (nth 0 (nth 0 result)) "#\" has not declared before..." ))
								(setf result (list (copy-tree (list "0f1" "exp") )) )
							)
						)
		)

		;handles function definitions
		;adds function-keeper list function and it's name(explained at top)
		(  (or  (equal token-names (list "OP" "DEFF" "ID" "OP" "CP" "exp" "CP"))
				(equal token-names (list "OP" "DEFF" "ID" "OP" "ID" "CP" "exp" "CP"))
				(equal token-names (list "OP" "DEFF" "ID" "OP" "ID" "ID" "CP" "exp" "CP"))
				(equal token-names (list "OP" "DEFF" "ID" "OP" "ID" "ID" "ID" "CP" "exp" "CP"))
		   )
			(progn

				(add-function-to-function-keeper (nth 0 (nth 2 result)) (get-function-body-from-stack 0 "") )
				(setf result (list (copy-tree (list "0f1" "exp") )) )
			)
		)
		((and (equal token-names (list "OP""ID" "CP"))( not ( equal (nth 1 shift-reduce-parser-stack) (list "deffun" "DEFF") ) ) )
			(progn
				(setf mainlist nil)
				(setf shift-reduce-parser-stack nil)
				(setq new-str (get-function-body-from-function-keeper 0 (nth 0 (nth 1 result))))
				(tokenize-string new-str 0)
				(setf mainlist (reverse (cdr (reverse mainlist))))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(parse-exp)
			)
		)
		((equal token-names (list "OP""ID" "exp" "CP"))
			(progn
				(setf mainlist nil)
				(setf shift-reduce-parser-stack nil)
				(setq new-str (get-function-body-from-function-keeper 0 (nth 0 (nth 1 result))))
				(tokenize-string new-str 0)
				(setq temp-id (list (nth 0 (nth 4 mainlist)) (nth 0 (nth 2 result))))
				(setf id-keeper (append (list temp-id) id-keeper))
				(incf fcall-counter)
				(setf mainlist (reverse (cdr (reverse mainlist))))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(setf mainlist (cdr mainlist))
				(parse-exp)
			)
		)
	)

	result
)





;this function starts to check stack
;(There exists no "n" for this function , it's there to understand how function performs...)
;n = 0 at the beginning
;it increments n for every step
;if last n elements of the stack can be reduced
;this elements get reduced and replaced by the reduced result
;if not,n gets incremented
;if n equals to stack size,this means this stack could not reduced 
(defun reduce-sublists-of-stack(index)
	(if(eq index 0)
		(setf shift-reduce-parser-stack (reduce-given-list shift-reduce-parser-stack))
		(if( not (equal (subseq shift-reduce-parser-stack index (length shift-reduce-parser-stack)) (reduce-given-list (subseq shift-reduce-parser-stack index (length shift-reduce-parser-stack)))) )
			(progn

					(setq new-stack (append (subseq shift-reduce-parser-stack 0 index) (reduce-given-list (subseq shift-reduce-parser-stack index (length shift-reduce-parser-stack)))))
					(setf shift-reduce-parser-stack new-stack)
			)
		)
	)
	(if(> index 0  )
		(reduce-sublists-of-stack (- index 1))
	)
)

































(defun is-input-string-completed-helper(index paranthesis)
	(setq result t)

	(if(eq index (length input-string))
		(progn
			(if(eq paranthesis 0)
				(setq result t)
				(setq result nil)
			)

		)
		(progn
			(if( char= #\( (aref input-string index) )
						(setq result (is-input-string-completed-helper (+ index 1) (+ paranthesis 1)))
			)
			(if( char= #\) (aref input-string index) )
						(setq result (is-input-string-completed-helper (+ index 1) (- paranthesis 1)))
			)
			(if(and  (not( char= #\( (aref input-string index) ))  (not( char= #\) (aref input-string index) )) )
				(setq result (is-input-string-completed-helper (+ index 1) paranthesis))
			)
		)
	)

	result
)

(defun is-input-string-completed() (is-input-string-completed-helper 0 0))


















;This function parses the expression
;If success or fail happened is checked in main function
(defun parse-exp()


			(if(not(equal mainlist nil))

				;if parser can be shifted,stacks gets new element
				;then stack gets reduced as much as it can get
				(progn
						(parser-shift)
						(reduce-sublists-of-stack (length shift-reduce-parser-stack))
						(parse-exp)
				)

				(progn
					(setf tmp (reduce-given-list shift-reduce-parser-stack))
					(if(not (equal tmp shift-reduce-parser-stack))
						(progn
							(setf shift-reduce-parser-stack tmp)
							(parse-exp)
						)
					)

				)
			)


)











(defun main()

	(princ " > ")

	(setq input (read-line))

	(setq input-string (concatenate 'string input-string input))

	(if(string= input-string "(exit)")
		(exit)
	)


	(if(is-input-string-completed)
		(progn
			(tokenize-input input-string)
			(parse-exp)

			(if(string= (nth 1 (nth 0 shift-reduce-parser-stack))  "start")
				(progn
					(write-line "Syntax ok.")
					(write-line (concatenate 'string "Result : " (nth 0 (nth 0 shift-reduce-parser-stack))))
				)
				(progn
					(write-line "Error,expression could not get parsed,terminating...")
					(exit)
				)
			)




			(setf shift-reduce-parser-stack nil)

			(setf input-string "")

		)
	)


	(if(eq fcall-counter 1)
		(progn
			(setq id-keeper (cdr id-keeper))
			(decf fcall-counter)
		)
	)

	(main)
)






(main)












