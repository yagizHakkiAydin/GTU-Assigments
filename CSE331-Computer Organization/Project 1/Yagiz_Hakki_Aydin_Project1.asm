#In this section, I defined registers with certain ways of using explained here ____________________



li $s0 , 0  # $s0 will always remain as array index for all loops, it changes in every loop and for next loop it gets 0 again

li $s1 , 46	  # $s1 register takes ascii value of '.' character , content does not change during program
li $s2 , 79   # $s2 register takes ascii value of 'O' character , content does not change during program



#________________________________________________________________________________________________









#Messages section
.data
EnterStepCountMessage: .asciiz "Enter number of seconds to play -> "
SecondsLeft: .asciiz " seconds left to play..."
EnterGridWidthMessage: .asciiz "Enter grid width -> "
EnterGridHeightMessage: .asciiz "Enter grid height -> "
EnterCellPositionMessage: .asciiz "Enter cell number to plant bomb,enter '-1' to end planting -> "

IndexOutOfRangeMessage: .asciiz "Cell position given by you is either higher than number of all cells or less than 1,please enter a valid cell position..."
InvalidWidthInputMessage: .asciiz "Board width cannot be less than 2, please enter a valid width...\n"
InvalidHeightInputMessage: .asciiz "Board height cannot be less than 2, please enter a valid height...\n"
InvalidSecondsMessage: .asciiz "Number of seconds must be at least 3, please enter a valid value...\n"

Newline: .asciiz "\n"

#________________________________________________________________________________________________














#In this section, I still keeping grid dimentions and second counter at specific registers ( $s3,$s4,$s5 )
#These registers will be used to keep those values during the execution


.text


WidthInput:

	li $v0 , 4						#Firstly I set $v0 to 0, so syscall prints given message
	la $a0 , EnterGridWidthMessage  #Secondly loading message by loading address of message to $a0
	syscall							#Printing message
	li $v0 , 5						#Setting syscall to read integer
	syscall							#Getting grid width from user
	move $s3 , $v0					#Setting $s3 to grid width, will have same number during whole execution

	blt $s3,2,InvalidWidth
	nop
	j HeightInput
	nop


InvalidWidth:
	li $v0 , 4			   #
	la $a0 , InvalidWidthInputMessage  #Print message to give invalid width error
	syscall				
	j WidthInput	#Go back to get grid width again
	nop 







HeightInput:

	li $v0 , 4							#
	la $a0 , EnterGridHeightMessage				        #
	syscall								#Doing exact same operation above to get height of grid
	li $v0 , 5							#
	syscall								#
	move $s4 , $v0							#

	blt $s4,2,InvalidHeight	#Print message to give invalid height error
	nop
	j SecondsInput	#Go back to get grid height again
	nop



InvalidHeight:
	li $v0 , 4				
	la $a0 , InvalidHeightInputMessage  #Print message to give invalid height error
	syscall				    #
	j HeightInput	#Go back to get grid height again
	nop




SecondsInput:

	li $v0 , 4						#
	la $a0 , EnterStepCountMessage				#
	syscall							#Printing message to enter how many seconds will be played
	li $v0 , 5						#
	syscall							#
	move $t9 , $v0					        #Result of user input will be kept in $t9

	blt $t9,3,InvalidSecondsInput
	nop
	j InputsDone
	nop



InvalidSecondsInput:
	li $v0 , 4						#Firstly I set $v0 to 0, so syscall prints given message
	la $a0 , InvalidSecondsMessage  #Secondly loading message by loading address of message to $a0
	syscall	
	j SecondsInput
	nop

#At the end $s3 and $s4 are initialized for grid width and height, they remain with same value

#$t9 will have second counter, after every second it gets decremented
#It is also used to decide weather end program or go to the next step


#________________________________________________________________________________________________











#________________________________________________________________________________________________
#In this section, we allocate two arrays to play game





InputsDone:

	mul $s5 , $s4 , $s3 	#Multiplying $s4 and $s3, so it keeps grid total size by mult. of width and height


	#Now we will allocate two arrays so each byte represents a cell of a grid
	move $a0 , $s5 #set number of bytes to allocate


	li $v0 , 9		#
	syscall			#
	move $s6 , $v0          #Firstly we allocated an array and $s6 keeps asdress of it
	li $v0 , 9		#
	syscall			#
	move $s7 , $v0          #Secondly we allocated another array and $s7 keeps address of it


#________________________________________________________________________________________________








#______________________________________________________________________

#At this point of the program,we have two arrays with size of grid $s6 as first grid, $s7 as second grid
#Now we fill first grid with '.' and second grid with 'O'



initializeGrids:	#This is a loop and fills every cell

	add $t6 , $s6 , $s0	 # $t6 and $t7 keeps adresses of array elements at that step
	add $t7 , $s7 , $s0	 #
	
	
	sb $s1,($t6)		#  grid[ $t6 ] = '.'
	sb $s2,($t7)		#  secondGrid[ $t7 ] = 'O'
	
	addi $s0 , $s0 , 1    # index++
	
	beq $s0 , $s5 , getInitialBombPositions	# if( index == 256 ){ end loop }
	nop
	
	j initializeGrids    #If all cells are not filled, continue filling cells
	nop

#________________________________________________________________________________________________________








#________________________________________________________________________________________________________
#Now before game starts, program takes input from user one by one
getInitialBombPositions:
	

	li $v0 , 4							#
	la $a0 , EnterCellPositionMessage	#Printing message to get user input 
	syscall								#User enters a number 'n' such that  '  0 =< n <total size  '
	li $v0 , 5							#Get user input as integer (Position of bomb)
	syscall								#
	
	
	beq $v0 , -1 , BombsArePlanted	#If user wants to end adding bomb and start to play game,enters '-1' as input
	nop
	
	bgt $v0 , $s5 , IndexOutOfRange	 #If user enters a bomb position greater than grid size,it gives an error and
	nop								 #continues to loop
	
	
	blt $v0 , -1 , IndexOutOfRange    #If user enters a bomb position less than -1 ,it gives an error and
	nop								  #continues to loop
	
	
	
	#If program reached here,means user entered a valid input for bomb position
	move $t6 , $s6		 # $t6 gets start adress of the grid array
	add $t6 , $t6 , $v0 # $v0 has value of new bomb index, so $t6 after this line has address of n'th element
	sb $s2 , ($t6)		 # set n'th element as 'O'  -->  firstGrid[index] = 'O'
	


	
	j getInitialBombPositions    #User entered a valid input, bomb has planted so keeps continue to get another bomb inputs
	nop
	
	
	
	
	#Only reaches here if user entered a invalid position for a new bomb
	IndexOutOfRange:
		li $v0 , 4						#
		la $a0 , IndexOutOfRangeMessage	#
		syscall							#Printing index error
		la $a0 , Newline				#
		syscall							#
		
		
		j getInitialBombPositions		#After giving error for invalid bomb position, goes back to loop
		nop								#to get bomb position again




BombsArePlanted:

	li $v0 , 1
	move $a0 , $t9
	syscall
	li $v0 , 4
	la $a0 , SecondsLeft
	syscall




	li $s0 , 0


	printInitialGridLoop:
		li $v0, 11 # Set syscall
		li $a0,10 # Set printed char as newline
		syscall   #print newline
	
		j printInitialGridLineLoop 
		nop


		printInitialGridLineLoop:

			add $t6 , $s6 , $s0
			lb  $a0 , ($t6)  #Load cell character of corresponding adress
			syscall    #Print cell
	
			li $a0 , 20  #Print space after cell
			syscall
			syscall
			
	
			addi $s0 ,$s0 , 1 #index += 1   so, we can check if (index+1)%16 == 0  to check border
	
		
	
	       		            #
			div $s0 , $s3  #  $t0 = ($s0 % width)
			mfhi $t0      # 
	

			beq $s0 , $s5 , InitialGridPrinted	#If all 256 cells printed, jumps to FirstStepCompleted
			nop
	
			beq $t0 , 0 , printInitialGridLoop #If line printed,go outer loop to print new line 
			nop
	
			j printInitialGridLineLoop #If all cells are not printed and corresponding line is still incomplete,continue loop to print all line
			nop



	InitialGridPrinted: 

		li $s0 , 0 #initialize index of grid array


		addi $t9 , $t9 , -1
		li $v0, 11 # Set syscall
		li $a0,10  # Set printed char as newline
		syscall    #print newline
		li $v0 , 1
		move $a0 , $t9
		syscall
		li $v0 , 4				#
		la $a0 , SecondsLeft	#Print seconds left
		syscall					#
		beq $t9 , 0 , end






#When program is here, first grid is printed with initial bombs from user input

startNewPeriod:
	li $s0 , 0	#Set index to 0





	#printFirstGrid
	printBombsFilledGridLoop:
		li $v0, 11 # Set syscall
		li $a0,10 # Set printed char as newline
		syscall   #print newline
	
		j printBombsFilledGridLineLoop
		nop


		printBombsFilledGridLineLoop:
	
			add $t7 , $s7 , $s0
			lb  $a0 , ($t7)  #Load cell character of corresponding adress
			syscall    #Print cell
	
			li $a0 , 20  #Print space after cell
			syscall
			syscall
			
	
			addi $s0 ,$s0 , 1 #  $s0++
					 	#incrementing index to be able to check if index is border of grid by mod 16
	
		
	
	      		   		    #
			div $s0 , $s3  #  $t0 = ($s0 % width)
			mfhi $t0      # 
	

			beq $s0 , $s5 , BombsFilledGridPrinted	#If all 256 cells printed, jumps to FirstStepCompleted
			nop
	
			beq $t0 , 0 , printBombsFilledGridLoop #If line printed,go outer loop to print new line 
			nop
	
			j printBombsFilledGridLineLoop #If all cells are not printed and corresponding line is still incomplete,continue loop to print all line
			nop


	#firstGrid
	BombsFilledGridPrinted: 

		li $s0 , -1 #Set index to 0 for gameplay loop

		addi $t9 , $t9 , -1
	
	
		li $v0, 11 # Set syscall
		li $a0,10 # Set printed char as newline
		syscall   #print newline
		
		li $v0 , 1		#
		move $a0 , $t9	#Decrement second counter
		syscall			#
		
		li $v0 , 4           #
		la $a0 , SecondsLeft #Print number of seconds left
		syscall              #
		
		beq $t9 , 0 , end #If second counter is 0,end gameplay period so end game
		nop               #
	


	#With this loop,game gets played
	#First grid keeps bombs those will be detonated
	#We look at firstGrid[ index ],if that cell contains bomb,then secondGrid[ index ] cell and all adjacents
	#of that cell gets '.' so secondGrid keeps updated version of the grid
	
	PlayLoop:
		addi $s0 , $s0 , 1 #s0 keeps index
		
		add $t6 , $s6 , $s0 # $t6 keeps address of firstGrid[index] element
		add $t7 , $s7 , $s0 # $t7 keeps address of secondGrid[index] element
	
	
	
		beq $s0 , $s5 , printNewBoard  #index equals to grid size, so PlayLoop ends by jumping to print updated board
		nop
	
		lb $t0 ,($t6) # $t0 = firstGrid[index]
		beq $t0 , $s2 , bombDetectedAtCell # if firstGrid[index] == 'O',jump 'bombDetectedAtCell' to handle 
		nop                                # secondGrid[index] and it's adjacents
	
	
		j PlayLoop	#At firstGrid[index], there is not a bomb,so continue PlayLoop
		nop
	
	
	
	bombDetectedAtCell:
		move $t0 , $s1  # $t0 = '.'
		sb $t0 , ($t7) # secondGrid[ index ] = '.'
	
	
	
		addi $t1 , $s0 , 1 # $t1 = index + 1
		div $t1 , $s3  #
		mfhi $t2      # $t2 = (index+1)%width, used for border check for adjacents
	
	
		bne $t2 , 0 , detonateRightCell  #jumps to detonateRightCell if secondGrid[ index ] is not at most-right cell
		nop
    		rightCellHandled: #right cell gets '.' then program continues from here


		bne $t2 , 1 , detonateLeftCell #jumps to detonateLeftCell if secondGrid[ index ] is not at most-left cell
		nop
    		leftCellHandled: #left cell gets '.' then program continues from here


		move $t3,$s3
		div $t3 , $s0 , $t3	# $t3 has greater value than 0 if firstGrid[index] is not in first line
		bgt $t3 , 0 , detonateUpperCell	
		nop
    		upperCellHandled:

		sub $t3,$s5,$s3
		sub $t3,$t3,1
		blt $s0 , $t3 , detonateLowerCell
		nop
    		lowerCellHandled:

	
	
	
	j PlayLoop   #Continue to play loop
	nop




	detonateLeftCell:
	
		addi $t4 , $s0 , -1  #$t4 = index - 1
		add $t7 , $s7 , $t4	 # $t7 has address of secondGrid[index-1]
		sb $s1 , ($t7) #secondGrid[index-1] = '.'
		j leftCellHandled  #continue to playGame loop
		nop
	
	detonateRightCell:
		addi $t4 , $s0 , 1 #$t4 = index + 1
		add $t7 , $s7 , $t4 # $t7 has address of secondGrid[index+1]
		sb $s1 , ($t7) #secondGrid[index+1] = '.'
		j rightCellHandled #continue to playGame loop
		nop
	
	detonateUpperCell:
		move $t2 , $s3  # $t2 = width
		mul $t2 , $t2 , -1 # $t2 = -width
		add $t4 , $s0 , $t2 # $t4 = index + width , so $t4 has index of upper cell
		add $t7 , $s7 , $t4 # $t7  has address of secondGrid[index-width]
		sb $s1 , ($t7) #secondGrid[index-width] = '.'
		j upperCellHandled #continue to playGame loop
		nop
	detonateLowerCell:
		move $t2 , $s3  # $t2 = width
		add $t4 , $s0 , $t2 #$t4 = index + width
		add $t7 , $s7 , $t4 # $t7  has address of secondGrid[index+width]
		sb $s1 , ($t7) #secondGrid[index+width] = '.'
		j lowerCellHandled #continue to playGame loop
		nop






	
	printNewBoard:
		li $s0 , 0 #setting index to 0

	
	printSecondGridLoop:
		li $v0, 11 # Set syscall
		li $a0,10 # Set printed char as newline
		syscall   #print newline
	
		j printSecondGridLineLoop
		nop


		printSecondGridLineLoop:
			add $t7 , $s7 , $s0
			lb  $a0 , ($t7)  #Load cell character of corresponding adress
			syscall    #Print secondGrid[index]
	
			li $a0 , 20  #Print space after cell secondGrid[index]
			syscall
			syscall
			
	
			addi $s0 ,$s0 , 1 #  index++
	
		
			div $s0 , $s3  
			mfhi $t0 # $t0 = (index + 1 % width)
	

			beq $s0 , $s5 , SecondGridPrinted #If all cells printed, jumps to SecondGridPrinted
			nop
	
			beq $t0 , 0 , printSecondGridLoop #If line printed,go outer loop to print new line 
			nop
	
			j printSecondGridLineLoop #If all cells are not printed and corresponding line is still incomplete,continue loop to print all line
			nop




	SecondGridPrinted:

		addi $t9 , $t9 , -1 #decrement second counter
		li $v0, 11 # Set syscall
		li $a0,10 # Set printed char as newline
		syscall   #print newline
		
		li $v0 , 1
		move $a0 , $t9 
		syscall #print num of seconds left
		
		li $v0 , 4
		la $a0 , SecondsLeft
		syscall #print num of seconds left message
	
		li $s0 , 0
		beq $t9 , 0 , end #if second counter is 0,terminate program



	setGridsForNewPeriod:
		beq $t9 , 0 , end
		nop

		add $t6 , $s6 , $s0
		add $t7 , $s7 , $s0
		lb $t8, ($t7)
		sb $t8,($t6)		#  firstGrid[ index ] = secondGrid[ index ]
		sb $s2,($t7)		#  secondGrid[ index ] = 'O'
		
		addi $s0 , $s0 , 1    # index++
	
	
		beq $s0 , $s5 , startNewPeriod	#Grids are ready for next period
		nop
	
		j setGridsForNewPeriod    #index is not max value, continue loop so make grids ready for next period
		nop








end:
		li $v0 , 10
		syscall
	
	
	
	
	
	
	
	
	
	
	
