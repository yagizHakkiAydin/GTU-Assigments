#include "pegsolitare.h"





void cse241hw5::PegSolitare::initialize()
{

	boardWidth = 9;
	boardHeigth = 9;

	board = std::vector< std::vector<char> >( 9 , std::vector<char>(9,'e') );


	for( int lineIndicator=0 ; lineIndicator<9 ; lineIndicator++ )
	{
		for( int columnIndicator=0 ; columnIndicator<9 ; columnIndicator++ )
		{
			if( columnIndicator==3 || columnIndicator==4 || columnIndicator==5 )
			{
				board[lineIndicator][columnIndicator] = 'p';
			}
			else if( lineIndicator==3 || lineIndicator==4 || lineIndicator==5 )
			{
				board[lineIndicator][columnIndicator] = 'p';
			}
			else
			{
				board[lineIndicator][columnIndicator] = 'u';
			}
		}
	}

	board[4][4] = 'e';

}












void cse241hw5::PegSolitare::print()
{
	const int boardWidth{ getBoardWidth() };
	const int boardHeigth{ getBoardHeigth() };


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
			if( board[columnIndex][lineIndex] == 'u' )
			{
				std::cout <<"  ";
			}
			else if( board[columnIndex][lineIndex] == 'e' )
			{
				std::cout <<" .";
			}
			else
			{
				std::cout <<" p";
			}


		}
	}

	std::cout << std::endl;

	std::cout << "Score is --> " << boardScore() << std::endl;

}









bool cse241hw5::PegSolitare::endGame() const
{

	for( int i=0 ; i<7 ; i++ )
	{
		for( int j=0 ; j<7 ; j++ )
		{
			if( (board[i][j]=='p') && (board[i][j+1]=='p') && (board[i][j+2]=='e') )
			{
				return false;
			}
			else if( (board[i][j]=='.') && (board[i][j+1]=='p') && (board[i][j+2]=='p') )
			{
				return false;
			}
			else if( (board[i][j]=='p') && (board[i+1][j]=='p') && (board[i+2][j]=='e') )
			{
				return false;
			}
			else if( (board[i][j]=='.') && (board[i+1][j]=='p') && (board[i+2][j]=='p') )
			{
				return false;
			}

		}
	}


	return true;


}
















std::string cse241hw5::PegSolitare::generateRandomValidCommand()
{

		srand( time(NULL) );


		char columnIndicator{' '}; //indicates horizental position of the corresponding cell
		char lineIndicator{' '}; //indicates vertical position of the corresponding cell
		const std::vector< std::string  > directions {   "U","D","L","R"  };  //directions vector,used to select a random move direction  
		int directionIndex{ 0 };  //index of the directions vector above



		std::string command = "";  //temporary command to play,created randomly

		while(!isCommandValid(command))  //creates a random command until it's valid
		{

			command.clear();  //command cleared to create a new command

			columnIndicator = 'A' + rand()%getBoardWidth();  //  Corresponding cell coordinates
			lineIndicator= '1' + rand()%getBoardHeigth();  //  selected randomly


			directionIndex = rand() % 4;
			


			command += columnIndicator;			      //
			command += lineIndicator;			     // A random command gets created and
			command +=  + '-';					    //	it will be checked if it's valid,
			command += directions[directionIndex]; //	if it's not a new random command gets created

		}

		return command;


}













const bool cse241hw5::PegSolitare::isCommandValid( const std::string& command ) const
{


		if( command.length()!=4 )//checks command length
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

		if( (direction=="U") )
		{
			nextColumnIndex -= 1;
			nextNextColumnIndex -= 2;
		}
		if( (direction=="D"))
		{
			nextColumnIndex += 1;
			nextNextColumnIndex += 2;
		}
		if( (direction=="L"))
		{
			nextLineIndex -= 1;
			nextNextLineIndex -= 2;
		}
		if( (direction=="R"))
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
		if(  (board[nextColumnIndex][nextLineIndex]!='p') || (board[nextNextColumnIndex][nextNextLineIndex]!='e') || (board[columnIndex][lineIndex]!='p')  ) 
		{
			return false;
		}


	return true;
}





















void cse241hw5::PegSolitare::playUser( std::string &command )
{



		if( isCommandValid(command) )
        {
			const int lineIndex{ command[0] - 65 };      //  Line and column indexes are converted to integer
			const int columnIndex{ command[1] - 49 };   // from characters of command string



			const std::string direction ={ command.substr(3) };  //direction string gets set from substring of command string 



			board[columnIndex][lineIndex] = 'e';  //Wherever corresponding cell moves,corresponding cell's coordinate will be empty after move



			//these if-else statements makes move to given direction

			if( direction == "U" )
			{
				board[columnIndex-1][lineIndex] = 'e' ;
				board[columnIndex-2][lineIndex] = 'p' ;
			}
			else if( direction == "D" )
			{
				board[columnIndex+1][lineIndex] = 'e' ;
				board[columnIndex+2][lineIndex] = 'p' ;
			}
			else if( direction == "L" )
			{
				board[columnIndex][lineIndex-1] = 'e' ;
				board[columnIndex][lineIndex-2] = 'p' ;
			}
			else if( direction == "R" )
			{
				board[columnIndex][lineIndex+1] = 'e' ;
				board[columnIndex][lineIndex+2] = 'p' ;
			}
		}

		else
		{
			std::cerr << std::endl << "Invalid command,please enter a valid command"<< std::endl << command <<std::endl;
			std::cout << "Your Command --> ";
			command.clear();
			std::cin >> command;
			playUser( command );
		}


}






















int cse241hw5::PegSolitare::boardScore()const
{


	int newScore = -1;


	for( int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		for( int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			if( board[lineIndicator][columnIndicator] == 'p' )
			{
				newScore++;
			}
		}
	}




	return newScore;




}


















