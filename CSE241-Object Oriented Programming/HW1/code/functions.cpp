#include"functions.h"





bool isCommandValid( const std::vector< std::vector<Cell> >& board  ,  const std::string& command )
{

		const int boardType { getBoardType(board) };


		if( (boardType!=6) && (command.length()!=4) )//checks command length
		{
			return false;
		}
		else if( (boardType==6) && (command.length()!=5) )//checks command length
		{
			return false;
		}


		const int lineIndex { command[0] - 65 };     //
		const int columnIndex { command[1] - 49 };  //Indexes of corresponding cell

		const size_t boardSize {  board.size() };

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

		if( (lineIndex>=boardSize) || (lineIndex<0) || (columnIndex>=boardSize) || (columnIndex<0) )
		{
			return false;
		}
		else if( (nextLineIndex>=boardSize) || (nextLineIndex<0) || (nextColumnIndex>=boardSize) || (nextColumnIndex<0) )
		{
			return false;
		}
		else if( (nextNextLineIndex>=boardSize) || (nextNextLineIndex<0) || (nextNextColumnIndex>=boardSize) || (nextNextColumnIndex<0) )
		{
			return false;
		}
		




		//checks if next and corresponding cells are pegged and next-next cell is empty
		if(  (board[nextColumnIndex][nextLineIndex]!=Cell::pegged) || (board[nextNextColumnIndex][nextNextLineIndex]!=Cell::empty) || (board[columnIndex][lineIndex]!=Cell::pegged)  )
		{
			return false;
		}


	return true;
}










void play( std::vector< std::vector<Cell> >& board  ,  std::string& command )
{

		//command validity must be checked in playerPlay() and computerPlay() functions,if invalid command is
		//given to this function this means an exception occured and program gets terminated

		if( !isCommandValid(board,command) )
		{
			std::cerr << std::endl << "Invalid command for play() function , program terminated..." << std::endl;
			exit(1);
		}



		const int lineIndex{ command[0] - 65 };      //  Line and column indexes are converted to integer
		const int columnIndex{ command[1] - 49 };   // from characters of command string



		const std::string direction ={ command.substr(3) };  //direction string gets set from substring of command string 



		board[columnIndex][lineIndex] = Cell::empty;  //Wherever corresponding cell moves,corresponding cell's coordinate will be empty after move



		//these if-else statements makes move to given direction

		if( direction == "U" )
		{
			board[columnIndex-1][lineIndex] = Cell::empty;
			board[columnIndex-2][lineIndex] = Cell::pegged;
		}
		else if( direction == "D" )
		{
			board[columnIndex+1][lineIndex] = Cell::empty;
			board[columnIndex+2][lineIndex] = Cell::pegged;
		}
		else if( direction == "L" )
		{
			board[columnIndex][lineIndex-1] = Cell::empty;
			board[columnIndex][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "R" )
		{
			board[columnIndex][lineIndex+1] = Cell::empty;
			board[columnIndex][lineIndex+2] = Cell::pegged;
		}
		else if( direction == "UL" )
		{
			board[columnIndex-1][lineIndex-1] = Cell::empty;
			board[columnIndex-2][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "DL" )
		{
			board[columnIndex+1][lineIndex-1] = Cell::empty;
			board[columnIndex+2][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "UR" )
		{
			board[columnIndex-1][lineIndex+1] = Cell::empty;
			board[columnIndex-2][lineIndex+2] = Cell::pegged;
		}
		else if( direction == "DR" )	
		{
			board[columnIndex+1][lineIndex+1] = Cell::empty;
			board[columnIndex+2][lineIndex+2] = Cell::pegged;
		}

}

















void computerPlay(  std::vector< std::vector<Cell> >& board  )
{


	srand( time(NULL) );

	const int boardType { getBoardType(board) };
	const int boardWidth { getBoardWidth(board) };
	const int boardHeigth { getBoardHeigth(board) };



	const std::vector< std::string  > directions {   {"U","D","L","R","UL","DL","UR","DR"}   };         //   Vectors of every direction,column and line
	const std::vector< std::string  > columnIndicator {   {"A","B","C","D","E","F","G","H","I"}   };   // indicator,used to make random choices with
	const std::vector< std::string  > lineIndicator {   {"1","2","3","4","5","6","7","8","9"}   };    //  randomly decided indexes for these vectors


	int columnIndex = 0;        //
	int lineIndex = 0;	       // Indexes of vectors above
	int directionIndex = 0;   //



	while( !isGameEnded(board) )  //Makes computer play until game has ended
	{

		std::string command = "";  //temporary command to play,created randomly


		columnIndex = rand()%boardWidth;  //  Corresponding cell coordinates
		lineIndex = rand()%boardHeigth;  //  selected randomly



		//this if-else statement sets correct directon;if board type is 6,cell can only move diagonal
		if( boardType == 6 )
		{
			directionIndex = (rand()%4)+4;
		}
		else
		{
			directionIndex = rand() % 4;
		}


		//temporary command gets created
		command += columnIndicator[columnIndex]+lineIndicator[lineIndex]+"-"+directions[directionIndex];



		//if command is valid,play() function called with given command and after playing,recent state of board gets printed
		if( isCommandValid(board,command) )
		{
			play(board,command);
			std::cout << std::endl << std::endl;
			std::cout << "Computer played \"" << command << "\"" << std::endl;
			printBoard(board);
			std::cout << std::endl;
		}


	}


}







void playerPlay(  std::vector< std::vector<Cell> >& board  )
{

	std::string command{ "" };

	while( !isGameEnded(board) )
	{
		std::cout << std::endl << "Enter command-->";

		getline(std::cin,command);

		if( isCommandValid(board,command) )
		{   
			system("clear");  //clears terminal after every move

			play(board,command);  //play function called with given command

			std::cout << "You played-->" << command << std::endl << std::endl;
			std::cout << "Here is your board" << std::endl;

			printBoard(board);
		}
		else
			std::cout <<" Invalid command " << std::endl;

	}


}






