#include "PegSolitare.h"



int PegSolitare::totalNumberOfPegsOfAllBoards = 0;




PegSolitare::Cell::Cell( const std::string xPosition , const std::string yPosition , const CellState stateOfCell)  
{
	linePosition = xPosition;
	columnPosition = yPosition;
	state = stateOfCell;
}




PegSolitare::PegSolitare()
{
	totalScore = 0;


	boardWidth = 5;
	boardHeigth = 5;
	gameMode = "Player";
	moveDirection = "Vertical/Horizental";



	for( int columnIndex = 0 ; columnIndex < getBoardHeigth() ; columnIndex++)  //creates game board line by line with createAndReturnBoardLine()
	{

			board.push_back( createAndReturnBoardLine( getBoardWidth() , (columnIndex+1) , 31 ) );

	}
    
    board[2][2].setState( CellState::empty );

    totalNumberOfPegsOfAllBoards += returnNumOfPegs();

}





PegSolitare::PegSolitare( int type )
{

	totalScore = 0;

	if( type == 1 )
	{
		board = returnTypeOneBoard();
		boardWidth = 7;
		boardHeigth = 7;
		gameMode = "Player";
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 2 )
	{
		board = returnTypeTwoBoard();
		boardWidth = 9;
		boardHeigth = 9;
		gameMode = "Player";
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 3 )
	{
		board = returnTypeThreeBoard();
		boardWidth = 8;
		boardHeigth = 8;
		gameMode = "Player";
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 4 )
	{
		board = returnTypeFourBoard();
		boardWidth = 7;
		boardHeigth = 7;
		gameMode = "Player";
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 5 )
	{
		board = returnTypeFiveBoard();
		boardWidth = 9;
		boardHeigth = 9;
		gameMode = "Player";
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 6 )
	{
		board = returnTypeSixBoard();
		boardWidth = 9;
		boardHeigth = 5;
		gameMode = "Player";
		moveDirection = "Diagonal";
	}

	if( isGameCorrupted() )
	{
		std::cerr << std::endl << "Game corrupted,program terminating..." << std::endl;
		exit(1);
	}

	totalNumberOfPegsOfAllBoards += returnNumOfPegs();

}









void PegSolitare::setBoardType( const int type )
{

	totalNumberOfPegsOfAllBoards -= returnNumOfPegs();  //decrements total num of pegged cells because board will change



	//Board gets set to a specific type
	if( type == 1 )
	{
		board = returnTypeOneBoard();
		boardWidth = 7;
		boardHeigth = 7;
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 2 )
	{
		board = returnTypeTwoBoard();
		boardWidth = 9;
		boardHeigth = 9;
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 3 )
	{
		board = returnTypeThreeBoard();
		boardWidth = 8;
		boardHeigth = 8;
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 4 )
	{
		board = returnTypeFourBoard();
		boardWidth = 7;
		boardHeigth = 7;
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 5 )
	{
		board = returnTypeFiveBoard();
		boardWidth = 9;
		boardHeigth = 9;
		moveDirection = "Vertical/Horizental";
	}
	else if( type == 6 )
	{
		board = returnTypeSixBoard();
		boardWidth = 9;
		boardHeigth = 5;
		moveDirection = "Diagonal";
	}

	if( isGameCorrupted() )
	{
		std::cerr << std::endl << "Game corrupted,program terminating..." << std::endl;
		exit(1);
	}

	totalNumberOfPegsOfAllBoards += returnNumOfPegs();  //increments total num of pegged cells with created new board
}








PegSolitare::PegSolitare( std::string loadFileName )
{
	load( "LOAD " + loadFileName );  //loads game from file
	totalNumberOfPegsOfAllBoards += returnNumOfPegs();  //adds total number of pegged cells with new game
}





const bool PegSolitare::isGameCorrupted() const
{


	if( boardWidth == 0 )
	{
		return true;
	}
	else if( boardHeigth == 0 )
	{
		return true;
	}
	else if(  (gameMode!="Player") && (gameMode!="Computer") && (gameMode!="Semi-Computer")  )
	{
		return true;
	}
	else if(  (moveDirection!="Vertical/Horizental") && (moveDirection!="Diagonal")  )
	{
		return true;
	}
	else
	{
		return false;
	}


}











void PegSolitare::printBoard()
{

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

			if( board[columnIndex][lineIndex].getState() == CellState::empty )
				std::cout << " .";

			else if( board[columnIndex][lineIndex].getState() == CellState::pegged ) 
				std::cout << " P";
			else
			{
				std::cout << "  ";
			}
		}
	}


}









std::vector< std::vector< PegSolitare::Cell > > PegSolitare::returnUndefinedBoard(const int width,const int heigth)
{

	std::vector< std::vector< Cell > > undefinedBoard; //empty board with size 0x0




	for( int countColumnPosition=0 ; countColumnPosition<width ; countColumnPosition++ )
	{
		undefinedBoard.push_back( createAndReturnBoardLine(width,countColumnPosition,0) );  //empty line with given length gets added to the board
	}



	return undefinedBoard;

}










std::vector<PegSolitare::Cell> PegSolitare::createAndReturnBoardLine(int width , int columnPositionOfLine, int decimalLineValue )
{

	std::vector< PegSolitare::Cell > line;  //empty line vector with length 0;


	const char beginLinePosition{ 'A' };  //Line position indicator for corresponding cell of the line that will be created

	const int beginColumnPosition{ 1 };  //Column position indicator for corresponding cell of the line that will be created

	std::string correspondingLinePosition{ "" };
	std::string correspondingColumnPosition{ "" };





	for( int countLinePosition=0 ; countLinePosition<width ; countLinePosition++)
	{
		correspondingLinePosition += (beginLinePosition + countLinePosition);   //Line position indicator for corresponding cell of the line gets set
		correspondingColumnPosition = std::to_string( columnPositionOfLine );   //Column position indicator for corresponding cell of the line gets set

		line.push_back( Cell( correspondingLinePosition  , correspondingColumnPosition ,  CellState::undefined ) );  //Created cell gets pushed end of the line created

		correspondingLinePosition.clear();
		correspondingColumnPosition.clear();
	}

	


	decltype( decimalLineValue ) value = decimalLineValue;

	for(int power=8 ; power>=0 ; power--)  //this loop sets required cells to pegged,pegged cells are decided with "decimalLineValue"
	{
		if( pow(2,power) <= value )
		{
			line[power].setState( CellState::pegged );
			value -= pow(2,power);
		}
	}

	return line;
}


























std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeOneBoard()	
{

	const size_t width{ 7 };

	const size_t heigth{ 7 };


	std::vector< std::vector<PegSolitare::Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created



	for( int columnIndex = 0 ; columnIndex < heigth ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==6) )
		{
			tempBoard[columnIndex] = createAndReturnBoardLine( width , (columnIndex+1) , 28 );
		}
		else if( (columnIndex==1) || (columnIndex==5) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 62 );
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 127 ) ;
		}

	}
    
    tempBoard[2][3].setState( CellState::empty );  //Sets a cell to empty to make game playable

	return tempBoard;
}















std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeTwoBoard()	
{

	const size_t width{ 9 };

	const size_t heigth{ 9 };



	std::vector< std::vector<Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created


	for( int columnIndex = 0 ; columnIndex < width ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) || (columnIndex==8)  )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 56 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 511 ) ;
		}

	}
    
    tempBoard[4][4].setState( CellState::empty );  //Sets a cell to empty to make game playable


    return tempBoard;
}















std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeThreeBoard()	
{

	const size_t width{ 8 };

	const size_t heigth{ 8 };

	std::vector< std::vector<Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created

	for( int columnIndex = 0 ; columnIndex < width ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==2) || (columnIndex==6) || (columnIndex==7) )
		{

			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 28 ) ;

		}

		else if( (columnIndex==3) || (columnIndex==4) || (columnIndex==5) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 255 ) ;
		}
	}

    
    tempBoard[4][3].setState( CellState::empty );  //Sets a cell to empty to make game playable
	return tempBoard;
}















std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeFourBoard()	
{

	const size_t width{ 7 };

	const size_t heigth{ 7 };


	std::vector< std::vector<PegSolitare::Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created



	for( int columnIndex = 0 ; columnIndex < width ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
	{
		if( (columnIndex==0) || (columnIndex==1) || (columnIndex==5) || (columnIndex==6) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine(  width , (columnIndex+1) , 28 ) ;
		}

		else if( (columnIndex==2) || (columnIndex==3) || (columnIndex==4) )
		{
			tempBoard[columnIndex] =  createAndReturnBoardLine(  width , (columnIndex+1) , 127 ) ;
		}

	}
    
    tempBoard[3][3].setState( CellState::empty );  //Sets a cell to empty to make game playable

	return tempBoard;
}















std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeFiveBoard()	
{

	const size_t width{ 9 };

	const size_t heigth{ 9 };


	std::vector< std::vector<Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created




    for( int columnIndex = 0 ; columnIndex < width ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
    {
        if( (columnIndex==0) || (columnIndex==8) )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 16 ) ;
        }
        else if( (columnIndex==1) || (columnIndex==7) )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 56 ) ;
        }
        else if( (columnIndex==2) || (columnIndex==6) )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 124 ) ;
        }
        else if( (columnIndex==3) || (columnIndex==5) )
        {
           tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 254 ) ;
        }
        else if( columnIndex==4 )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 511 ) ;
        }

    }
    
    tempBoard[4][4].setState( CellState::empty );  //Sets a cell to empty to make game playable

	return tempBoard;
}















std::vector< std::vector<PegSolitare::Cell> > PegSolitare::returnTypeSixBoard()	
{

	const size_t width{ 9 };

	const size_t heigth{ 5 };

	std::vector< std::vector<Cell> > tempBoard = returnUndefinedBoard(width,heigth);  //an board with full of undefined cells is created

	const size_t boardSize = board.size();  //size of initial board


    for( int columnIndex = 0 ; columnIndex < width ; columnIndex++)  //shapes board line by line with createAndReturnBoardLine()
    {
        if( columnIndex==0 )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine(  width , (columnIndex+1) , 16 ) ;
        }
        else if( columnIndex==1 )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 40 ) ;
        }
        else if( columnIndex==2 )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 84 ) ;
        }
        else if( columnIndex==3 )
        {
            tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 170 ) ;
        }
        else if( columnIndex==4 )
        {
           tempBoard[columnIndex] =  createAndReturnBoardLine( width , (columnIndex+1) , 341 ) ;
        }
    }
    
    tempBoard[0][4].setState( CellState::empty );  //Sets a cell to empty to make game playable

	return tempBoard;
}













void PegSolitare::load( const std::string loadCommand )
{


	totalNumberOfPegsOfAllBoards -= returnNumOfPegs();  //Decrements corresponing number of all pegged cells because different game will be loaded

	setBoardWidth(0);  //These lines sets board width and board heigth 0
	setBoardHeigth(0);  //because game width and heigth will be set from load file


	int lineIndex=0,columnIndex=0;  //Indexes for the board vector


	std::ifstream file( loadCommand.substr(5) );  //this line gets loadCommand's substring which is file name and opens the file

	std::string tempLine{ "" };  //used at reading load file with getline()







	while( getline(file,tempLine) )  //this loop reads file line by line until game properties line,sets board width and heigth
	{
		if( tempLine.substr(0,4) == "Game" )  //This line ends loop if corresponding line doesn't keep a board line,but it keeps game property
		{
			break;
		}

		boardHeigth++;  //increaases board heigth for every board line read from load file

		if( tempLine.length() > boardWidth )  //sets board width to widthest board line of load file
		{
			setBoardWidth( tempLine.length() );
		}
	}



	tempLine.clear();  //clears tempLine because it will be used again to read file again 
	file.close();  //closes load file,because it will be read again



	board = returnUndefinedBoard(boardWidth,boardHeigth);  //creates a undefined board with width and heigth read from load file




	file.open( loadCommand.substr(5) );  //opens loadFile to set created undefined board to the shape which is given in loadFile



	while( getline(file,tempLine) )  //reads load file to set board,move direction , total score and game mode.
	{
		lineIndex=0;  //line index of the board vector,used to fill board from loadFile

		if( tempLine.substr(0,4) == "Game" )  //Sets game mode from needed line
		{
			setGameMode( tempLine.substr(11) );
		}
		else if( tempLine.substr(0,4) == "Move" )  //Sets move direction from needed line
		{
			setMoveDirection( tempLine.substr(17) );
		}
		else if( tempLine.substr(0,5) == "Total" )  //Sets total score from needed line
		{
			setTotalScore(  stoi( tempLine.substr(14) )  );
		}
		else //sets board from needed lines
		{
			for( auto cellChar : tempLine )  //reads every character of given line and sets every cell of the board
			{	

				if( cellChar == 'P' )
				{
					board[columnIndex][lineIndex].setState( CellState::pegged );
					board[columnIndex][lineIndex].setColumnPosition( std::to_string( columnIndex+1 ) );
				}
				else if( cellChar == '.' )
				{
					board[columnIndex][lineIndex].setState( CellState::empty );
					board[columnIndex][lineIndex].setColumnPosition( std::to_string( columnIndex+1 ) );
				}
				else
				{
					board[columnIndex][lineIndex].setState( CellState::undefined );
					board[columnIndex][lineIndex].setColumnPosition( std::to_string( columnIndex+1 ) );
				}
				lineIndex++;
			}
			columnIndex++;
		}
		
	}
	if( isGameCorrupted() )
	{
		system("CLEAR");
		std::cerr << "load() can't load game from given file name,program terminating...";
		testBoard();
		exit(1);
	}

	totalNumberOfPegsOfAllBoards += returnNumOfPegs();

}














void PegSolitare::save( const std::string saveCommand ) const
{

	std::ofstream saveFile( saveCommand.substr(5) );  //opens a file with given name by command

	int columnIndex{ 0 };  //column index of board vector of the game

	for( auto line : board )  //counts every line of the board
	{
		for( auto boardCell : board[columnIndex] )  //writes necessary character to the saveFile for every cell of the board
		{
			if( boardCell.getState() == CellState::pegged )
			{
				saveFile << "P";
			}
			else if( boardCell.getState() == CellState::empty )
			{
				saveFile << ".";
			}
			else
			{
				saveFile << " ";
			}
		}
		saveFile << std::endl;
		columnIndex++;
	}



	saveFile << "Gamemode = " << getGameMode() << std::endl;				  //
	saveFile << "Move Direction = " << getMoveDirection() << std::endl;   //Writes game mode,move direction and total score to the saveFile
	saveFile << "Total Score = " << getTotalScore();					    //


	saveFile.close();



}












const bool PegSolitare::isCommandValid( const std::string& command ) const
{


		if( ( getMoveDirection() == "Vertical/Horizental") && (command.length()!=4) )//checks command length
		{
			return false;
		}
		else if( (getMoveDirection() == "Diagonal") && (command.length()!=5) )//checks command length
		{
			return false;
		}


		const int lineIndex { command[0] - 65 };     //
		const int columnIndex { command[1] - 49 };  //Indexes of corresponding cell

		//const size_t boardSize {  board.size() };

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

		if( (lineIndex>=getBoardWidth() ) || (lineIndex<0) || (columnIndex>=getBoardHeigth() ) || (columnIndex<0) )
		{
			return false;
		}
		else if( (nextLineIndex>=getBoardWidth() ) || (nextLineIndex<0) || (nextColumnIndex>=getBoardHeigth() ) || (nextColumnIndex<0) )
		{
			return false;
		}
		else if( (nextNextLineIndex>=getBoardWidth() ) || (nextNextLineIndex<0) || (nextNextColumnIndex>=getBoardHeigth() ) || (nextNextColumnIndex<0) )
		{
			return false;
		}
		





		//this command checks corresponding,next and next-next cells if all of them is at correct state to make move
		if(  (board[nextColumnIndex][nextLineIndex].getState()!=CellState::pegged) || (board[nextNextColumnIndex][nextNextLineIndex].getState()!=CellState::empty) || (board[columnIndex][lineIndex].getState()!=CellState::pegged)  )
		{
			return false;
		}


	return true;
}






















const bool PegSolitare::hasGameEnded() const
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

	for(int linePosCount=0 ; linePosCount< getBoardWidth() ; linePosCount++)
	{
		for(int columnPosCount=0 ; columnPosCount<getBoardHeigth() ; columnPosCount++)
		{

			correspondingCellCoordinates.clear();  //comand gets cleared for every step

			correspondingCellCoordinates += 'A'+linePosCount;
			correspondingCellCoordinates += '1'+columnPosCount;
			correspondingCellCoordinates += '-';


			if(  isCommandValid( correspondingCellCoordinates+up) )  
			{
				return false;	
			}
			else if(  isCommandValid( correspondingCellCoordinates+down) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+left) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+right) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+upperLeft) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+upperRight) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+downLeft) )  
			{
				return false;
			}
			else if(  isCommandValid( correspondingCellCoordinates+downRight) )  
			{
				return false;
			}

		}
	}


	return true;
}














void PegSolitare::play()
{

	play( generateRandomValidCommand() );  //Plays the game with randomly generated command

}






void PegSolitare::play( std::string command )
{


		if( command.substr(0,4) == "LOAD" )
		{
			load( command );
		}
		else if( command.substr(0,4) == "SAVE" )
		{
			save( command );
		} 

		else if( isCommandValid(command) )
        {
			const int lineIndex{ command[0] - 65 };      //  Line and column indexes are converted to integer
			const int columnIndex{ command[1] - 49 };   // from characters of command string



			const std::string direction ={ command.substr(3) };  //direction string gets set from substring of command string 



			board[columnIndex][lineIndex].setState( CellState::empty );  //Wherever corresponding cell moves,corresponding cell's coordinate will be empty after move



			//these if-else statements makes move to given direction

			if( direction == "U" )
			{
				board[columnIndex-1][lineIndex].setState( CellState::empty );
				board[columnIndex-2][lineIndex].setState( CellState::pegged );
			}
			else if( direction == "D" )
			{
				board[columnIndex+1][lineIndex].setState( CellState::empty );
				board[columnIndex+2][lineIndex].setState( CellState::pegged );
			}
			else if( direction == "L" )
			{
				board[columnIndex][lineIndex-1].setState( CellState::empty );
				board[columnIndex][lineIndex-2].setState( CellState::pegged );
			}
			else if( direction == "R" )
			{
				board[columnIndex][lineIndex+1].setState( CellState::empty );
				board[columnIndex][lineIndex+2].setState( CellState::pegged );
			}
			else if( direction == "UL" )
			{
				board[columnIndex-1][lineIndex-1].setState( CellState::empty );
				board[columnIndex-2][lineIndex-2].setState( CellState::pegged );
			}
			else if( direction == "DL" )
			{
				board[columnIndex+1][lineIndex-1].setState( CellState::empty );
				board[columnIndex+2][lineIndex-2].setState( CellState::pegged );
			}
			else if( direction == "UR" )
			{
				board[columnIndex-1][lineIndex+1].setState( CellState::empty );
				board[columnIndex-2][lineIndex+2].setState( CellState::pegged );
			}
			else if( direction == "DR" )	
			{
				board[columnIndex+1][lineIndex+1].setState( CellState::empty );
				board[columnIndex+2][lineIndex+2].setState( CellState::pegged );
			}

			setTotalScore( getTotalScore() + 1 );

			totalNumberOfPegsOfAllBoards -= 1;
		}


		else if( gameMode=="Player" )  //To make a move,this function calls itself until it gets a valid command
		{
			std::cerr << std::endl << "Invalid command,please enter a valid command"<< std::endl << command <<std::endl;
			std::cout << "Your Command --> ";
			command.clear();
			std::cin >> command;
			play( command );
		}


}















std::string PegSolitare::generateRandomValidCommand()
{
		srand( time(NULL) );


		char columnIndicator{' '}; //indicates horizental position of the corresponding cell
		char lineIndicator{' '}; //indicates vertical position of the corresponding cell
		const std::vector< std::string  > directions {   "U","D","L","R","UL","DL","UR","DR"   };  //directions vector,used to select a random move direction  
		int directionIndex{ 0 };  //index of the directions vector above



		std::string command = "";  //temporary command to play,created randomly

		while( !isCommandValid(command) )  //creates a random command until it's valid
		{

			command.clear();  //command cleared to create a new command

			columnIndicator = 'A' + rand()%getBoardWidth();  //  Corresponding cell coordinates
			lineIndicator= '1' + rand()%getBoardHeigth();  //  selected randomly

			if( getMoveDirection() == "Diagonal" )  //these if-else conditions makes a random move direction for random command
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

























void PegSolitare::playGame()
{

	std::string command;

	system( "CLEAR" );

	printBoard(  );

	while( !hasGameEnded() )  //Makes computer play until game has ended
	{

			command = generateRandomValidCommand();
			play( command  );
			printBoard(  );
			command.clear();
	}


	std::cout << std::endl << "Game Over,total score --> " << getTotalScore() << std::endl;


}










const int PegSolitare::returnNumOfPegs() const
{

	int numOfPegs{ 0 };

	int lineIndex{ 0 };

	for( auto line:board )
	{
		for( auto cell:board[lineIndex] )
		{
			if( cell.getState() == CellState::pegged )
			{
				numOfPegs++;
			}
		}
		lineIndex++;
	}

	return numOfPegs;
}















const int PegSolitare::returnNumOfEmpty() const
{

	int numOfEmpty{ 0 };

	int lineIndex{ 0 };

	for( auto line:board )
	{
		for( auto cell:board[lineIndex] )
		{
			if( cell.getState() == CellState::empty )
			{
				numOfEmpty++;
			}
		}
		lineIndex++;
	}

	return numOfEmpty;
}



















void PegSolitare::testBoard()
{

	std::cout << std::endl << "Board width --> " << boardWidth;
	std::cout << std::endl << "Board heigth --> " << boardHeigth;
	std::cout << std::endl << "GameMode --> " << gameMode;
	std::cout << std::endl << "Move Direction --> " << moveDirection;
	std::cout << std::endl << "Total score --> " << totalScore;
	board[1][1].testCell();
}



void PegSolitare::Cell::testCell()
{
std::cout << std::endl << "board[1][1] --> linePosition --> " << linePosition;
std::cout << std::endl << "board[1][1] --> columnPosition --> " << columnPosition;	
}

