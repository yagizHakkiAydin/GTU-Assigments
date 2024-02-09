#include "eightpuzzle.h"





void cse241hw5::EightPuzzle::initialize()
{
	boardWidth = 3;
	boardHeigth = 3;


	srand( time(NULL) );


	board = std::vector< std::vector<char> >( 3 , std::vector<char>(3,'.') );



	board[0][0] = '8';		   //
	board[0][1] = '1';		  //
	board[0][2] = '2';		 //
	board[1][0] = '4';	    //  Initialized board is not solvable because,the loop below generates random board while board isn't solvable
	board[1][1] = '3';	   //
	board[1][2] = '7';	  //
	board[2][0] = '6';	 //
	board[2][1] = '5';	//



	//This loop shuffles the board to get solvable 8-puzzle board
	while( !isSolvable() )
	{
		int howManyTimesSwap = rand()%50+20;

		char tempChar;

		int firstElementLineIndex = 0;
		int firstElementColumnIndex = 0;
		int secElementLineIndex = 0;
		int secElementColumnIndex = 0; 




		for( int i=0 ; i< howManyTimesSwap ; i++)
		{
			firstElementLineIndex = rand()%3;
			firstElementColumnIndex = rand()%3;
			secElementLineIndex = rand()%3;
		    secElementColumnIndex = rand()%3;

		    tempChar = board[firstElementLineIndex][firstElementColumnIndex];
		    board[firstElementLineIndex][firstElementColumnIndex] = board[secElementLineIndex][secElementColumnIndex];
		    board[secElementLineIndex][secElementColumnIndex] = tempChar;

		}


	}



}











bool cse241hw5::EightPuzzle::isSolvable() const
{

	int countInversions=0;

	std::vector <char> elementsLine;



	//this loop converts 2d char vector board to 1d char vector line
	for(int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		for(int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			elementsLine.push_back(board[lineIndicator][columnIndicator]);
		}
	}




	for(int i=0 ; i<elementsLine.size() ; i++ )  //This loop counts inversions
	{
		for(int j=i ; j<elementsLine.size() ; j++ )
		{
			if( (elementsLine[i]>elementsLine[j]) && (elementsLine[i]!='.') && (elementsLine[j]!='.') )
			{
				countInversions++;
			}
		}
	}




	if( countInversions%2 == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}





















void cse241hw5::EightPuzzle::print()
{
	for( int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		for( int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{

				std::cout << board[lineIndicator][columnIndicator] << "  ";
			
		}
		std::cout << std::endl << std::endl;
	
	}
	std::cout << std::endl << std::endl;

	std::cout << "Score is --> " << boardScore() << std::endl;

}

















const bool cse241hw5::EightPuzzle::isCommandValid( const std::string& command ) const
{
	int lineIndex=0;
	int columnIndex=0;


	if( command.length() != 3 )
	{
		return false;
	}
	else if( command[1] != '-' )
	{
		return false;
	}
	else if( (command[0]>'8') || (command[0]<'1') )
	{
		return false;
	}
	else if( (command[2]!='U') && (command[2]!='D') && (command[2]!='L') && (command[2]!='R') )
	{
		return false;
	}




	//This loop finds indexes of asked number
	for( int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{	bool endLoop = false;

		for( int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			if( board[lineIndicator][columnIndicator] == command[0] )
			{
				endLoop=true;
				lineIndex = lineIndicator;
				columnIndex = columnIndicator;
				break;
			}
			
		}
		if(endLoop)
		{
			break;
		}
	
	}





	//These if-else statements checks if asked number can move to asked direction
	if(command[2]=='U')
	{
		if(lineIndex==0)
		{
			return false;			
		}
		else if( board[lineIndex-1][columnIndex] != '.' )
		{
			return false;
		}
	}
	else if(command[2]=='D')
	{
		if(lineIndex==2)
		{
			return false;			
		}
		else if( board[lineIndex+1][columnIndex] != '.' )
		{
			return false;
		}
	}
	else if(command[2]=='L')
	{
		if(columnIndex==0)
		{
			return false;			
		}
		else if( board[lineIndex][columnIndex-1] != '.' )
		{
			return false;
		}
	}
	else if(command[2]=='R')
	{
		if(columnIndex==2)
		{
			return false;			
		}
		else if( board[lineIndex][columnIndex+1] != '.' )
		{
			return false;
		}
	}


	return true;
}





















void cse241hw5::EightPuzzle::playUser( std::string &command )
{

	//This loop gets command until it's valid
	while( true )
	{

		if(!isCommandValid(command))
		{
			std::cerr << std::endl << "Invalid command,please enter a valid command"<< std::endl << command <<std::endl;
			std::cout << "Your Command --> ";
			command.clear();
			std::cin >> command;
		}
		else
		{
			break;
		}
	}


	int lineIndicator = 0;
	int columnIndicator = 0;



	//These loops sets indexes of asked number
	for( lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		bool breakLoop = false;
		for( columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			if( board[lineIndicator][columnIndicator] == command[0] )
			{
				breakLoop = true;
				break;
			}
		}
		if(breakLoop)
		{
			break;
		}
	}

	
	 const char correspondingCell =  board[lineIndicator][columnIndicator];


	 board[lineIndicator][columnIndicator] = '.';  //Sets previous position of selected number empty


	 if( command[2] == 'U' )
	 {
	 	board[lineIndicator-1][columnIndicator] = correspondingCell;
	 }
	 else if(command[2] == 'D' )
	 {
	 	board[lineIndicator+1][columnIndicator] = correspondingCell;
	 }
	 else if(command[2] == 'L' )
	 {
	 	board[lineIndicator][columnIndicator-1] = correspondingCell;
	 }
	 else
	 {
	 	board[lineIndicator][columnIndicator+1] = correspondingCell;
	 }


		

}










































std::string cse241hw5::EightPuzzle::generateRandomValidCommand()
{
		std::string command{""};

		char directionsArray[4] = { 'U' , 'D' , 'L' , 'R' };
		char blocksArray[8] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8'  };

		int directionsArrayIndex{0};
		int blocksArrayIndex{0};



		srand( time(NULL) );



		

		while(!isCommandValid(command))  //creates a random command until it's valid
		{

			command.clear();  //command cleared to create a new command

			directionsArrayIndex = rand()%4;
			blocksArrayIndex = rand()%8;

			command += blocksArray[ blocksArrayIndex ];
			command += '-';
			command += directionsArray[ directionsArrayIndex ];
		}

		return command;

}















bool cse241hw5::EightPuzzle::endGame() const
{
	const std::vector <std::vector<char>> finalBoard = { {'1','2','3'} , {'4','5','6'} , {'7','8','.'} };


	if( finalBoard == board )
	{
		return true;
	}
	else
	{
		return false;
	}


}











int cse241hw5::EightPuzzle::boardScore()const
{

	std::vector<std::vector<char>> finalBoard = { {'1','2','3'} , {'4','5','6'} , {'7','8','.'} };

	int newScore = 0;


	//This loop counts how many elements are at different position where they must be
	for( int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		for( int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			if( board[lineIndicator][columnIndicator] != finalBoard[lineIndicator][columnIndicator] )
			{
				newScore++;
			}
		}
	}


	return newScore;
} 














