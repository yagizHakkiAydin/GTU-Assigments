#include "game.h"







bool isGameCorrupted( const game& pegSolitareGame)
{

	if( pegSolitareGame.boardWidth == 0 )
	{
		return false;
	}
	else if( pegSolitareGame.boardHeigth == 0 )
	{
		return false;
	}
	else if(  (pegSolitareGame.gameMode!="Player") && (pegSolitareGame.gameMode!="Computer")  )
	{
		return false;
	}
	else if(  (pegSolitareGame.moveDirection!="Vertical/Horizental") && (pegSolitareGame.gameMode!="Diagonal")  )
	{
		return false;
	}
	else
	{
		return true;
	}

}









std::vector< std::vector<Cell> > returnUndefinedBoard(const int width,const int heigth)
{
	std::vector< Cell > line( width , Cell::undefined );  //creates a line line with undefined cells

	std::vector< std::vector<Cell> > board( heigth , line );   //initializes board with created line

	return board;
}






std::vector<Cell> createAndReturnBoardLine( int decimalLineValue )
{
	std::vector<Cell> line(9,Cell::undefined);

	decltype( decimalLineValue ) value = decimalLineValue;

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












bool isCommandValid(  const game& pegSolitareGame ,  const std::string& command )
{


		const std::string moveDirection{ pegSolitareGame.moveDirection };


		if( ( pegSolitareGame.moveDirection == "Vertical/Horizental") && (command.length()!=4) )//checks command length
		{
			return false;
		}
		else if( (pegSolitareGame.moveDirection == "Diagonal") && (command.length()!=5) )//checks command length
		{
			return false;
		}


		const int lineIndex { command[0] - 65 };     //
		const int columnIndex { command[1] - 49 };  //Indexes of corresponding cell

		//const size_t boardSize {  pegSolitareGame.board.size() };

		int nextColumnIndex { columnIndex };         //
		int nextNextColumnIndex { columnIndex };    //  Indexes of the next and next-next cells
		int nextLineIndex { lineIndex };           //
		int nextNextLineIndex { lineIndex };      //

		std::string direction { command.substr(3) };   





		//these if-else statements sets indexes of next and next-next cells with given direction

		if( (direction=="U") || (direction=="UL") || (direction=="UR") )
		{
			nextColumnIndex -= 1;
			nextNextColumnIndex -= 2;
		}
		if( (direction=="D") || (direction=="DL") || (direction=="DR") )
		{
			nextColumnIndex += 1;
			nextNextColumnIndex += 2;
		}
		if( (direction=="L") || (direction=="UL") || (direction=="DL") )
		{
			nextLineIndex -= 1;
			nextNextLineIndex -= 2;
		}
		if( (direction=="R") || (direction=="UR") || (direction=="DR") )
		{
			nextLineIndex += 1;
			nextNextLineIndex += 2;
		}




		//these if-else statements checks if all indexes are in 0-9 to avoid segmentation fault

		if( (lineIndex>=pegSolitareGame.boardWidth) || (lineIndex<0) || (columnIndex>=pegSolitareGame.boardHeigth) || (columnIndex<0) )
		{
			return false;
		}
		else if( (nextLineIndex>=pegSolitareGame.boardWidth) || (nextLineIndex<0) || (nextColumnIndex>=pegSolitareGame.boardHeigth) || (nextColumnIndex<0) )
		{
			return false;
		}
		else if( (nextNextLineIndex>=pegSolitareGame.boardWidth) || (nextNextLineIndex<0) || (nextNextColumnIndex>=pegSolitareGame.boardHeigth) || (nextNextColumnIndex<0) )
		{
			return false;
		}
		





		//this command checks corresponding,next and next-next cells if all of them is at correct state to make move
		if(  (pegSolitareGame.board[nextColumnIndex][nextLineIndex]!=Cell::pegged) || (pegSolitareGame.board[nextNextColumnIndex][nextNextLineIndex]!=Cell::empty) || (pegSolitareGame.board[columnIndex][lineIndex]!=Cell::pegged)  )
		{
			return false;
		}


	return true;
}














std::vector< std::vector<Cell> > returnTypeOneBoard()
{

	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created


	const size_t boardSize{ 9 };  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==6) )
		{
			board[columnIndex] = createAndReturnBoardLine( 28 );
		}
		else if( (columnIndex==1) || (columnIndex==5) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 62 );
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 127 ) ;
		}

	}
    
    board[2][3] = Cell::empty;

	return board;
     
}






std::vector< std::vector<Cell> > returnTypeTwoBoard()
{
	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize{ 9 };  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) || (columnIndex==8)  )
		{
			board[columnIndex] =  createAndReturnBoardLine( 56 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 511 ) ;
		}

	}
    
    board[4][4] = Cell::empty;


    return board;
}













std::vector< std::vector<Cell> > returnTypeThreeBoard()
{
	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created


	const size_t boardSize{9};  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) )
		{

			board[columnIndex] =  createAndReturnBoardLine( 28 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 255 ) ;
		}
	}

    
    board[4][3] = Cell::empty;

	return board;
}











std::vector< std::vector<Cell> > returnTypeFourBoard()
{
	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize{ 9 };  //size of initial board


	for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==5) || (columnIndex==6) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 28 ) ;
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			board[columnIndex] =  createAndReturnBoardLine( 127 ) ;
		}

	}
    
    board[3][3] = Cell::empty;

	return board;
}












std::vector< std::vector<Cell> > returnTypeFiveBoard()
{
	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created


    const size_t boardSize{ 9 };  //size of initial board


    for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
    {
        if( (columnIndex==0) || (columnIndex==8) )
        {
            board[columnIndex] =  createAndReturnBoardLine( 16 ) ;
        }
        else if( (columnIndex==1) || (columnIndex==7) )
        {
            board[columnIndex] =  createAndReturnBoardLine( 56 ) ;
        }
        else if( (columnIndex==2) || (columnIndex==6) )
        {
            board[columnIndex] =  createAndReturnBoardLine( 124 ) ;
        }
        else if( (columnIndex==3) || (columnIndex==5) )
        {
           board[columnIndex] =  createAndReturnBoardLine( 254 ) ;
        }
        else if( columnIndex==4 )
        {
            board[columnIndex] =  createAndReturnBoardLine( 511 ) ;
        }

    }
    
    board[4][4] = Cell::empty;

	return board;
}




















std::vector< std::vector<Cell> > returnTypeSixBoard()
{

	std::vector< std::vector<Cell> > board = returnUndefinedBoard();  //an board with full of undefined cells is created

	const size_t boardSize = board.size();  //size of initial board


    for( int columnIndex = 0 ; columnIndex < boardSize ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
    {
        if( columnIndex==0 )
        {
            board[columnIndex] =  createAndReturnBoardLine( 16 ) ;
        }
        else if( columnIndex==1 )
        {
            board[columnIndex] =  createAndReturnBoardLine( 40 ) ;
        }
        else if( columnIndex==2 )
        {
            board[columnIndex] =  createAndReturnBoardLine( 84 ) ;
        }
        else if( columnIndex==3 )
        {
            board[columnIndex] =  createAndReturnBoardLine( 170 ) ;
        }
        else if( columnIndex==4 )
        {
           board[columnIndex] =  createAndReturnBoardLine( 341 ) ;
        }
    }
    
    board[0][4] = Cell::empty;

	return board;
}














void printBoard( const game& pegSolitareGame )
{

	const int boardWidth{ pegSolitareGame.boardWidth };
	const int boardHeigth{ pegSolitareGame.boardHeigth };


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

			if( pegSolitareGame.board[columnIndex][lineIndex] == Cell::empty )
				std::cout << " .";

			else if( pegSolitareGame.board[columnIndex][lineIndex] == Cell::pegged ) 
				std::cout << " P";
			else
			{
				std::cout << "  ";
			}
		}
	}

}











void chooseBoardType( game& pegSolitareGame )
{

	std::cout << std::endl << "Select board type -->";

	std::string boardType = "";


	pegSolitareGame.boardWidth = 9;   //Board width and heigth are 9
	pegSolitareGame.boardHeigth = 9; //for specific board types


	getline( std::cin , boardType );


	if( boardType == "1" )
	{
		pegSolitareGame.board = returnTypeOneBoard();
	}
	else if( boardType == "2" )
	{
		pegSolitareGame.board = returnTypeTwoBoard();
	}
	else if( boardType == "3" )
	{
		pegSolitareGame.board = returnTypeThreeBoard();
	}
	else if( boardType == "4" )
	{
		pegSolitareGame.board = returnTypeFourBoard();
	}
	else if( boardType == "5" )
	{
		pegSolitareGame.board = returnTypeFiveBoard();
	}
	else if( boardType == "6" )
	{
		pegSolitareGame.board = returnTypeSixBoard();
		pegSolitareGame.moveDirection = "Diagonal";  //only type six board from specific types is being played to diagonal directions
	}
	else //calls chooseBoardType() to be sure if player selected board type correctly
	{
		std::cerr << std::endl << "Wrong board type selection,please make a valid selection";
		chooseBoardType( pegSolitareGame );
	}
}













bool hasGameEnded( const game& pegSolitareGame )
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





	//This nested loops checks every command,if one of them is valid,then game hasn't ended

	for(int linePosCount=0;linePosCount<pegSolitareGame.boardWidth;linePosCount++)
	{
		for(int columnPosCount=0;columnPosCount<pegSolitareGame.boardHeigth;columnPosCount++)
		{

			correspondingCellCoordinates.clear();  //comand gets cleared for every step

			correspondingCellCoordinates += 'A'+linePosCount;
			correspondingCellCoordinates += '1'+columnPosCount;
			correspondingCellCoordinates += '-';


			if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+up) )  )
			{
				return false;	
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+down) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+left) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+right) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+upperLeft) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+upperRight) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+downLeft) )  )
			{
				return false;
			}
			else if(  isCommandValid( pegSolitareGame , (correspondingCellCoordinates+downRight) )  )
			{
				return false;
			}

		}
	}


	return true;
}
















std::string generateRandomValidCommand( const  game &pegSolitareGame )
{

		srand( time(NULL) );


		char columnIndicator{' '}; //indicates horizental position of the corresponding cell
		char lineIndicator{' '}; //indicates vertical position of the corresponding cell
		const std::vector< std::string  > directions {   "U","D","L","R","UL","DL","UR","DR"   };  //directions vector,used to select a random move direction  
		int directionIndex{ 0 };  //index of the directions vector above



		std::string command = "";  //temporary command to play,created randomly

		while( !isCommandValid(pegSolitareGame,command) )  //creates a random command until it's valid
		{

			command.clear();  //command cleared to create a new command

			columnIndicator = 'A' + rand()%pegSolitareGame.boardWidth;  //  Corresponding cell coordinates
			lineIndicator= '1' + rand()%pegSolitareGame.boardHeigth;  //  selected randomly

			if( pegSolitareGame.moveDirection == "Diagonal" )  //these if-else conditions makes a random move direction for random command
			{
				directionIndex = (rand()%4)+4;
			}
			else
			{
				directionIndex = rand() % 4;
			}


			command += columnIndicator;			      //
			command += lineIndicator;			     // A random command gets created and
			command +=  + '-';					    //	it will be checked if it's valid,
			command += directions[directionIndex]; //	if it's not a new random command gets created

		}

		return command;

}















void selectGameMode( game& pegSolitareGame )
{

	std::string selection{ "" };

	std::cout << std::endl << "To select computer game,enter 'C' ; to select player game,enter 'P' --> ";

	getline( std::cin , selection );


	if( selection == "P" )
	{
		pegSolitareGame.gameMode = "Player";
	}
	else if( selection == "C" )
	{
		pegSolitareGame.gameMode = "Computer";
	}
	else  //calls selectGameMode() to be sure if player selected gameMode correctly
	{
		std::cerr << "Please make a valid gamemode selection...";
		selectGameMode( pegSolitareGame );
	}

}
