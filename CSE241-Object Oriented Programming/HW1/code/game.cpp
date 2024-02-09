#include"game.h"
#include"functions.h"




std::vector< std::vector<Cell> > createUndefinedBoard()
{
	const size_t boardSize = 9;  //maximum size of all board type's width and heigth

	std::vector< Cell > line( boardSize , Cell::undefined );  //creates a line line with undefined cells

	std::vector< std::vector<Cell> > board( boardSize , line );   //initializes board with created line

	return board;
}








//initializer functions send required integer,this integer is used to create a line which belongs to specific board type 
//decimalLineValue gets converted to a binary value and 0's represent undefined cells,1's represent pegged cells
std::vector<Cell> createLine( int decimalLineValue )
{
	std::vector<Cell> line(9,Cell::undefined);

	int value=decimalLineValue;

	for(int power=8 ; power>=0 ; power--)
	{
		if( pow(2,power) <= value )
		{
			line[power] = Cell::pegged;
			value -= pow(2,power);
		}
	}

	return line;
}






//sets board type by using initializer functions
void setBoardType( std::vector< std::vector<Cell> >& board )
{


	std::string type = "";

	std::cout << std::endl << "Please choose board type in [1,6] interval-->";

	std::cin >> type;




	if( (type.length()!=1) || ((type[0]-48)<1) || ((type[0]-48)>6) )  //checks if user entered a board type between 1-6
	{	
		std::cerr << std::endl << "Invalid board type " << std::endl;

		setBoardType(board); //function calls itself recursively until user made a valid board type choice
	}




	if( type == "1" )
	{
		board = initializeTypeOneBoard();
	}
	else if( type == "2" )
	{
		board = initializeTypeTwoBoard();
	}
	else if( type == "3" )
	{
		board = initializeTypeThreeBoard();
	}
	else if( type == "4" )
	{
		board = initializeTypeFourBoard();
	}
	else if( type == "5" )
	{
		board = initializeTypeFiveBoard();
	}
	else if( type == "6" )
	{
		board = initializeTypeSixBoard();
	}

}









std::vector< std::vector<Cell> > initializeTypeOneBoard()
{

	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created


	const size_t boardSize = board.size();  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
	{
		if( (columnIndex==0) || (columnIndex==6) )
		{
			board[columnIndex] = createLine( 28 );
		}
		else if( (columnIndex==1) || (columnIndex==5) )
		{
			board[columnIndex] =  createLine( 62 );
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			board[columnIndex] =  createLine( 127 ) ;
		}

	}
    
    board[2][3] = Cell::empty;

	return board;
     
}








std::vector< std::vector<Cell> > initializeTypeTwoBoard()
{
	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize = board.size();  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) || (columnIndex==8)  )
		{
			board[columnIndex] =  createLine( 56 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			board[columnIndex] =  createLine( 511 ) ;
		}

	}
    
    board[4][4] = Cell::empty;


    return board;
}










std::vector< std::vector<Cell> > initializeTypeThreeBoard()
{
	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created


	const size_t boardSize{9};  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) )
		{

			board[columnIndex] =  createLine( 28 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			board[columnIndex] =  createLine( 255 ) ;
		}
	}

    
    board[4][3] = Cell::empty;

	return board;
}












std::vector< std::vector<Cell> > initializeTypeFourBoard()
{
	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize = board.size();  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==5) || (columnIndex==6) )
		{
			board[columnIndex] =  createLine( 28 ) ;
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			board[columnIndex] =  createLine( 127 ) ;
		}

	}
    
    board[3][3] = Cell::empty;

	return board;
}













std::vector< std::vector<Cell> > initializeTypeFiveBoard()
{
	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created


    const size_t boardSize = board.size();  //size of initial board


    for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
    {
        if( (columnIndex==0) || (columnIndex==8) )
        {
            board[columnIndex] =  createLine( 16 ) ;
        }
        else if( (columnIndex==1) || (columnIndex==7) )
        {
            board[columnIndex] =  createLine( 56 ) ;
        }
        else if( (columnIndex==2) || (columnIndex==6) )
        {
            board[columnIndex] =  createLine( 124 ) ;
        }
        else if( (columnIndex==3) || (columnIndex==5) )
        {
           board[columnIndex] =  createLine( 254 ) ;
        }
        else if( columnIndex==4 )
        {
            board[columnIndex] =  createLine( 511 ) ;
        }

    }
    
    board[4][4] = Cell::empty;

	return board;
     
}







std::vector< std::vector<Cell> > initializeTypeSixBoard()
{

	std::vector< std::vector<Cell> > board = createUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize = board.size();  //size of initial board


    for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createLine()
    {
        if( columnIndex==0 )
        {
            board[columnIndex] =  createLine( 16 ) ;
        }
        else if( columnIndex==1 )
        {
            board[columnIndex] =  createLine( 40 ) ;
        }
        else if( columnIndex==2 )
        {
            board[columnIndex] =  createLine( 84 ) ;
        }
        else if( columnIndex==3 )
        {
            board[columnIndex] =  createLine( 170 ) ;
        }
        else if( columnIndex==4 )
        {
           board[columnIndex] =  createLine( 341 ) ;
        }
    }
    
    board[0][4] = Cell::empty;

	return board;
}








bool isGameEnded(  const std::vector< std::vector<Cell> >& board   )
{


	const std::string up { "U" };		         //
	const std::string down { "D" };		        //
	const std::string left { "L" };		       //
	const std::string right { "R" };          //
	const std::string upperLeft { "UL" };    //directions,used to create temporary commands
	const std::string downLeft { "DL" };    //
	const std::string upperRight { "UR" }; //
	const std::string downRight { "DR" }; //

	std::string correspondingCellCoordinates = "";  //coordinates of the cell which gets checked







	for(int i=0;i<9;i++)		  //
	{							 //Nested loops to create commands for every cell of the board and every cell of the board is checked if there 
		for(int m=0;m<9;m++)	//is a valid move to any direction.If there is a valid move,this means game hasn't ended yet
		{

			correspondingCellCoordinates.clear();  //comand gets cleared for every step

			correspondingCellCoordinates += 'A'+i;   //Corresponding cell coordinates and '-' character of the command string is added
			correspondingCellCoordinates += '1'+m;  //to the command.Corresponding cell at created command gets checked by if-else statements
			correspondingCellCoordinates += '-';   //below if the cell can move to any directions.


			if(  isCommandValid( board , (correspondingCellCoordinates+up) )  )
			{
				return false;	
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+down) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+left) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+right) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+upperLeft) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+upperRight) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+downLeft) )  )
			{
				return false;
			}
			else if(  isCommandValid( board , (correspondingCellCoordinates+downRight) )  )
			{
				return false;
			}

		}
	}


	return true;
}














int getBoardType( const std::vector< std::vector<Cell> >& board )
{

	//every board type has a pegged cell at a unique coordinate
	//with this information,board type gets returned by if-else statements below 

	
	if( board[1][1] != Cell::undefined )
	{
		return 1;
	}
	else if( board[0][5] != Cell::undefined )
	{
		return 2;
	}
	else if( board[7][2] != Cell::undefined )
	{
		return 3;
	}
	else if( board[0][3] != Cell::undefined )
	{
		return 4;
	}
	else if( board[1][4] != Cell::undefined )
	{
		return 5;
	}
	else
	{
		return 6;
	}
}











int getBoardWidth( const std::vector< std::vector<Cell> >& board )
{

	int boardWidth;

	const int boardType = getBoardType(board);

	if( boardType==2  ||  boardType==5 || boardType==6)
	{
		boardWidth=9;
	}
	else if( boardType==1  ||  boardType==4 )
	{
		boardWidth=7;
	}
	else
	{
		boardWidth=8;
	}

	return boardWidth;
}












int getBoardHeigth( const std::vector< std::vector<Cell> >& board )
{

	int boardHeigth;

	const int boardType = getBoardType(board);

	if( boardType==1  ||  boardType==4 )
	{
		boardHeigth=7;
	}
	else if( boardType==2  ||  boardType==5 )
	{
		boardHeigth=9;
	}
	else if( boardType==3 )
	{
		boardHeigth=8;
	}

	else if( boardType == 6 )
	{
		boardHeigth=5;
	}

	return boardHeigth;
}










void printBoard( const std::vector< std::vector<Cell> >& board )
{


	const int boardWidth = getBoardWidth(board);
	const int boardHeigth = getBoardHeigth(board);


	char columnIndicator='A'; 



	for( int countColumnIndicatorLines=0 ; countColumnIndicatorLines<3 ; countColumnIndicatorLines++ )  //counts 3 times to print letters and indicator arrows
	{
		std::cout << std::endl << "      ";


		for( int countColumnIndicatorPosition=0 ; countColumnIndicatorPosition<boardWidth ; countColumnIndicatorPosition++ )
		{
			if( countColumnIndicatorLines == 0 )
			{
				std::cout << columnIndicator << " ";
			}
			else if( countColumnIndicatorLines == 1 )
			{
				std::cout << '|' << " ";
			}
			else if( countColumnIndicatorLines == 2 )
			{
				std::cout << 'V' << " ";
			}
			columnIndicator += 1;  //sets next indicator letter
		}

	}

	




	for( int columnIndex=0 ; columnIndex<boardHeigth ; columnIndex++)
	{

		std::cout << std::endl;

		if(columnIndex<boardHeigth)
		{
			std::cout << columnIndex+1 << " -> ";  //prints line indicator numbers
		}


		for( int lineIndex=0 ; lineIndex<boardWidth ; lineIndex++)  //prints cells;if cell is undefined,prints space
		{
			if( board[columnIndex][lineIndex] == Cell::undefined )
				std::cout << "  ";

			else if( board[columnIndex][lineIndex] == Cell::empty )
				std::cout << " .";

			else if( board[columnIndex][lineIndex] == Cell::pegged ) 
				std::cout << " P";
		}
	}


}








int getFinalScore( const std::vector< std::vector<Cell> >& board )
{
	const int maxBoardSize{ 9 };

	int countFinalScore{ 0 };



	//these nested loops scans board to count pegged cells

	for( int lineIndex=0 ; lineIndex<maxBoardSize ; lineIndex++ )
	{
		for( int columnIndex=0 ; columnIndex<maxBoardSize ; columnIndex++ )
		{
			if( board[columnIndex][lineIndex] == Cell::pegged )
			{
				countFinalScore++;
			}
		}
	}


	return countFinalScore;

}





