(defvar keywords (list "and" "or" "not" "eq" "gt" "nil" "set" "defvar" "deffun" 
                       "while" "if" "load" "disp" "true" "false"))

(defvar keywordTokenNames (list "OP_AND" "OP_OR" "OP_NOT" "OP_EQ" "OP_GT" "KW_NIL"
							     "KW_SET" "DEFV" "DEFF" "KW_WHILE" "KW_IF" 
								 "KW_LOAD" "KW_DISP" "KW_TRUE" "KW_FALSE"))


(defvar operators (list "+" "-" "/" "*" "(" ")" "," ) )



(defvar operatorTokenNames (list "OP_PLUS" "OP_MINUS" "OP_DIV" "OP_MULT" 
								 "OP" "CP" "OP_COMMA" ))








(defvar currentToken "")	;used to keep the string ,changes during every step


(defvar isCommentOpened nil )    


(defvar mainlist nil)	;the list that keeps tokens and token names,printed as result

(defvar onlyTokenTypesList nil)






(defun integer-DFA-state-two(strinput)

	(if(eq (length strinput) 0)
		t
		(progn
			( if( or (char< (aref strinput 0 ) #\0) (char> (aref strinput 0 ) #\9)) 
				(progn 
					nil
				)
				(integer-DFA-state-two (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
)

(defun integer-DFA-state-one(strinput)

			(if(eq (length strinput) 0)
				nil
				(if(and (eq (length strinput) 1) (string= "0" strinput))

					t  ;it's integer if it's only "0"

					(progn 
						(if(char= (aref strinput 0 ) #\0)
							nil    ;if it starts with "0" and it is not only "0",then it is not an integer

							(integer-DFA-state-two strinput);
						)

					)

				)

			)
)


(defun is-integer(str)   ;checks if given string is integer by starting dfa
	(setq isint nil)
	(setq isInt (integer-DFA-state-one str))


	isint
)







(defun ID-DFA-state-two(strinput)
	(if(eq (length strinput) 0)
		t
		(progn
			( if( and ( or (char< (aref strinput 0 ) #\A) (char> (aref strinput 0 ) #\Z)) ( or (char< (aref strinput 0 ) #\0) 
			               (char> (aref strinput 0 ) #\9)) ( or (char< (aref strinput 0 ) #\a) (char> (aref strinput 0 ) #\z) ) 
			               (not (char= (aref strinput 0 ) #\_)) ) 
				(progn 
					nil
				)
				(ID-DFA-state-two (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
)

(defun ID-DFA-state-one(strinput)
	(if(eq (length strinput) 0)
		nil
		(progn
			( if( and ( or (char< (aref strinput 0 ) #\A) (char> (aref strinput 0 ) #\Z)) 
					  ( or (char< (aref strinput 0 ) #\a) (char> (aref strinput 0 ) #\z) ) 
					  (not (char= (aref strinput 0 ) #\_)) ) 
				(progn 
					nil
				)
				(ID-DFA-state-two (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
)

(defun is-ID(strinput)   ;checks if given string is ID by starting dfa
	(setq isInt (ID-DFA-state-one strinput))
)








(defun fraction-DFA-state-five(strinput)
	(if(eq (length strinput) 0)
		t
		(progn
			( if( or (char< (aref strinput 0 ) #\0) (char> (aref strinput 0 ) #\9)) 
				(progn 
					nil
				)
				(fraction-DFA-state-five (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
)

(defun fraction-DFA-state-four(strinput)
	(if(eq (length strinput) 0)
		nil
		(progn
			( if( or (char< (aref strinput 0 ) #\1) (char> (aref strinput 0 ) #\9)) 
				(progn 
					nil
				)
				(fraction-DFA-state-five (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
	
)

(defun fraction-DFA-state-three(strinput)
	(if(eq   (length (string-left-trim (string (aref strinput 0))strinput))    (- (length strinput) 1)    )
		(fraction-DFA-state-four (string-left-trim (string (aref strinput 0)) strinput))
		nil
	)
)

(defun fraction-DFA-state-two(strinput)
	(if(eq (length strinput) 0)
		nil
		(progn
			(if( char= (aref strinput 0 ) #\f )
				(fraction-DFA-state-three  strinput )

				(progn
					( if( or (char< (aref strinput 0 ) #\0) (char> (aref strinput 0 ) #\9)) 
						(progn 
							nil
						)
						(fraction-DFA-state-two (string-left-trim (string (aref strinput 0)) strinput))
					)							
				)
						
			)


		)
	)
	
)

(defun fraction-DFA-state-one(strinput)
	(if(eq (length strinput) 0)
		nil
		(progn
			( if( or (char< (aref strinput 0 ) #\1) (char> (aref strinput 0 ) #\9)) 
				(progn 
					nil
				)
				(fraction-DFA-state-two (string-left-trim (string (aref strinput 0)) strinput))
			)
		)
	)
)




(defun is-fraction(str)   ;checks if given string is fraction by starting dfa

	(setq isInt (fraction-DFA-state-one str))
)







(defun is-chr-operator(chr)   ;checks if given char is operator,needed because
							  ; operators are used as delimeter as newlines and spaces and program reads char by char

	(setq isOperator nil)
	(if(or (char= chr #\+) (char= chr #\-) (char= chr #\*) (char= chr #\/) (char= chr #\() (char= chr #\))  (char= chr #\,) )
		(progn
			(setq isOperator t)
		)
	)

	isOperator
)





(defun is-keyword(str)   ;checks if given string is keyword
	(setq isKW nil)

		(if( not(eq (find str keywords :test #'string=) nil) )
			(setq isKW t)
		)
	isKW
)


(defun is-str-operator(str)    ;checks if given string is operator
	(setq isOP nil)

		(if( not(eq (find str operators :test #'string=) nil) )
			(setq isOP t)
		)
	isOP
)





(defun getTokenType()    ;Checks if currentToken string belongs to the one of the token types

	(setq tokenidentified nil)    ;if any of the conditions below does not happen(an type of token gets cannot be idenified) makes lexer to terminate

	(setq type (list nil nil))

	(if(is-fraction currenttoken)
		(progn
			(setq tokenidentified t)
			(setq type (list currenttoken "VALUEF"))
		)
	)
	(if(is-ID currenttoken)
		(progn
			(setq tokenidentified t)
			(setq type (list currenttoken "ID"))
		)
	)
	(if(is-keyword currenttoken)
		(progn
				(setq tokenidentified t)
				(setq type (list currenttoken (nth (position currenttoken keywords :test #'string=) keywordTokenNames) ))
		)	
	)

	(if(is-str-operator currenttoken)
		(progn
				(setq tokenidentified t)
				(setq type (list currenttoken (nth (position currenttoken operators :test #'string=) operatorTokenNames) ))
		)
	)




	(if( not tokenidentified )	  ;if currentToken string could not tokenized by expressions above,terminates the program with error
		(progn
			(print currenttoken)
			(princ #\Newline)(princ currenttoken)(princ " cannot be tokenized,terminating...")(princ #\Newline)
			(exit)
		)
	)


	type
)

















;Gets the chars at every step and appends that char to currentToken string
;If it gets newline,space or operator,it stops appending that char to currentToken string and tokenizes that string
(defun build-token(chr)

			(if(eq isCommentOpened t)
				(progn
					(if(char= chr #\Newline)
						(progn   ;When gets newline,this means comment reading has ended and currentToken string contains the comment

							(setq isCommentOpened nil)	;Terminates comment reading

							(setq mainlist (append mainlist (list (list currenttoken "COMMENT"))) )  ;Appends that token to the main list

							(setq currenttoken "")

						)
						(progn   ;Appends every char to currenttoken string until it gets a new line

							(setq currenttoken (concatenate 'string currenttoken (string chr) ))

						)
					)

				)
			)


			(if(not isCommentOpened)
				
							(progn
								 (if(or (char= chr #\Space) (char= chr #\Newline) (is-chr-operator chr))   

									(progn  ;if it gets newline,space or an operator this means currentToken is ready to get tokenized

										(if(not (string= currenttoken ""))    ;tokenizes string before appending last element			
											(progn			
												(setq tokenlist (gettokentype) )
												(setq mainlist (append mainlist (list tokenlist)))
												(setq tokenlist (cdr tokenlist))
												(setq onlyTokenTypesList (append onlyTokenTypesList tokenlist))
												(setq currenttoken "")
											)
										)

										(if(and (is-chr-operator chr))

												(progn    ;If delimeter is an operator,this condition tokenizes that operator too after previous 
														  ;expression that has tokenized already and made currentToken string ""

															(setq currenttoken (concatenate 'string currenttoken (string chr) ))
															(setq tokenlist (gettokentype) )
															(setq mainlist (append mainlist (list tokenlist)))
															(setq tokenlist (cdr tokenlist))
															(setq onlyTokenTypesList (append onlyTokenTypesList tokenlist))
															(setq currenttoken "")
												)
										)
									)

									(progn	;Till it gets newline,space or an operator appending to the curentToken continues

										(setq currenttoken (concatenate 'string currenttoken (string chr) ))

										(if(string= currenttoken ";;")
											(setq isCommentOpened t)
										)

										(if(is-chr-operator chr)
											(progn
												(setq tokenlist (gettokentype) )
															(setq mainlist (append mainlist (list tokenlist)))
															(setq tokenlist (cdr tokenlist))
															(setq onlyTokenTypesList (append onlyTokenTypesList tokenlist))
															(setq currenttoken "")
											)
										)
									)
								 )


							)

				
			)


)




(defun read_source_file_char_by_char(stream-in stream-out)    ;reads file char by char recursively and sends every char to build-token function

	(let ( ( char (read-char stream-in nil) ) )
	    (unless (null char)
		    ( build-token char )
		    ( read_source_file_char_by_char stream-in stream-out )
	    )
	)
)





(defun tokenize-string(userInputString strindex)
	(if (not (eq strindex (length userInputString)  ) ) 
		(progn

			(build-token (aref userInputString strindex) )      ;tokenizes the string by modifying currenttoken string,sends chars of the given string
																;at every recursive call

			(tokenize-string userInputString (+ strindex 1))	;recursive call

		)
	)
)





(defun tokenize-input(str)	;asks user to enter a line,tokenizes it , prints the result and asks for another line

	(if(not (string= str ""))
		(progn	

			(setq str (concatenate 'string str (string #\Newline)))    ;adds an newline to the end of the line to tokenize correctly

			(tokenize-string str 0)    ;tokenizes the line and fills mainlist

			(setq str "")    ;sets the line string empty for next read


		)
	)
	
)


