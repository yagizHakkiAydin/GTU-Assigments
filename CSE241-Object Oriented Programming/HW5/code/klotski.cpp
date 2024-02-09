#include "klotski.h"





void cse241hw5::Klotski::print()
{

	for( int lineIndicator=0 ; lineIndicator<5 ; lineIndicator++ )
	{
		for( int columnIndicator=0 ; columnIndicator<4 ; columnIndicator++ )
		{

				std::cout << board[lineIndicator][columnIndicator] << "  ";
			
		}
		std::cout << std::endl << std::endl;
	
	}

	std::cout << "Score is --> " << boardScore() << std::endl;


}












void cse241hw5::Klotski::initialize()
{
	boardWidth = 4;
	boardHeigth = 5;

	board = std::vector< std::vector<char> >( 5 , std::vector<char>(4,'.') );


	board[0][0] = '1';
	board[0][1] = 'r';
	board[0][2] = 'r';
	board[0][3] = '2';
	board[1][0] = '1';
	board[1][1] = 'r';
	board[1][2] = 'r';
	board[1][3] = '2';
	board[2][0] = '3';
	board[2][1] = '5';
	board[2][2] = '5';
	board[2][3] = '4';
	board[3][0] = '3';
	board[3][1] = '6';
	board[3][2] = '7';
	board[3][3] = '4';
	board[4][0] = '8';
	board[4][1] = '.';
	board[4][2] = '.';
	board[4][3] = '9';

}











const bool cse241hw5::Klotski::isCommandValid( const std::string& command ) const
{



	if( command.length() != 3 )
	{
		return false;
	}
	else if( command[1] != '-' )
	{
		return false;
	}
	else if( ((command[0]>'9') || (command[0]<'1')) && (command[0]!='r') )
	{
		return false;
	}
	else if( (command[2]!='U') && (command[2]!='D') && (command[2]!='L') && (command[2]!='R') )
	{
		return false;
	}


	int lineIndicator = 0;
	int columnIndicator = 0;




	//This loop sets indexes of top-left corner of the asked piece
	for( lineIndicator=0 ; lineIndicator<5 ; lineIndicator++ )
	{
		bool breakLoop = false;
		for( columnIndicator=0 ; columnIndicator<4 ; columnIndicator++ )
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





	//these if-else checks if given command is valid
	if( command[0]>'5' && command[0]!='r')  
	{
		if( command[2] == 'U' )
		{
			if( lineIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator-1][columnIndicator] != '.' )
			{
				return false;
			}

		}
		else if( command[2] == 'D' )
		{
			if( lineIndicator == 4 )
			{
				return false;
			}
			else if( board[lineIndicator+1][columnIndicator] != '.' )
			{
				return false;
			}
			
		}
		else if( command[2] == 'L' )
		{
			if( columnIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator-1] != '.' )
			{
				return false;
			}
		}
		else
		{
			if( columnIndicator == 3 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator+1] != '.' )
			{
				return false;
			}			
		}

	}
	else if( command[0]<'5' )
	{
		if( command[2] == 'U' )
		{
			if( lineIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator-1][columnIndicator] != '.' )
			{
				return false;
			}

		}
		else if( command[2] == 'D' )
		{
			if( lineIndicator > 2 )
			{
				return false;
			}
			else if( board[lineIndicator+2][columnIndicator] != '.' )
			{
				return false;
			}
			
		}
		else if( command[2] == 'L' )
		{
			if( columnIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator-1] != '.'  || board[lineIndicator+1][columnIndicator-1] != '.' )
			{
				return false;
			}
		}
		else if( command[2] == 'R' )
		{
			if( columnIndicator == 3 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator+1] != '.'  || board[lineIndicator+1][columnIndicator+1] != '.' )
			{
				return false;
			}		
		}

	}
	else if( command[0]=='5' )
	{
		if( command[2] == 'U' )
		{
			if( lineIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator-1][columnIndicator] != '.'  ||  board[lineIndicator-1][columnIndicator+1] != '.')
			{
				return false;
			}		
		}
		else if( command[2] == 'D' )
		{
			if( lineIndicator == 4 )
			{
				return false;
			}
			else if( board[lineIndicator+1][columnIndicator] != '.'  ||  board[lineIndicator+1][columnIndicator+1] != '.')
			{
				return false;
			}			
		}
		else if( command[2] == 'L' )
		{
			if( columnIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator-1] != '.')
			{
				return false;
			}	
		}
		else
		{
			if( columnIndicator > 1 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator+2] != '.')
			{
				return false;
			}	
		}

	}
	else//command[0]=='r'
	{
		if( command[2] == 'U' )
		{
			if( lineIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator-1][columnIndicator] != '.'  ||  board[lineIndicator-1][columnIndicator+1] != '.')
			{
				return false;
			}		
		}
		else if( command[2] == 'D' )
		{
			if( lineIndicator > 2 )
			{
				return false;
			}
			else if( board[lineIndicator+2][columnIndicator] != '.'  ||  board[lineIndicator+2][columnIndicator+1] != '.')
			{
				return false;
			}		
		}
		else if( command[2] == 'L' )
		{
			if( columnIndicator == 0 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator-1] != '.'  || board[lineIndicator+1][columnIndicator-1] != '.' )
			{
				return false;
			}
		}
		else
		{
			
			if( columnIndicator > 1 )
			{
				return false;
			}
			else if( board[lineIndicator][columnIndicator+2] != '.'  || board[lineIndicator+1][columnIndicator+2] != '.' )
			{
				return false;
			}			
		}

	}




	



	

	return true;
}




























std::string cse241hw5::Klotski::generateRandomValidCommand()
{

		
		std::string command{""};

		char directionsArray[4] = { 'U' , 'D' , 'L' , 'R' };
		char blocksArray[10] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'r' };

		int directionsArrayIndex{0};
		int blocksArrayIndex{0};



		srand( time(NULL) );



		

		while(!isCommandValid(command))  //creates a random command until it's valid
		{

			command.clear();  //command cleared to create a new command

			directionsArrayIndex = rand()%4;
			blocksArrayIndex = rand()%10;

			command += blocksArray[ blocksArrayIndex ];
			command += '-';
			command += directionsArray[ directionsArrayIndex ];
		}

		return command;

}



































void cse241hw5::Klotski::playUser( std::string &command )
{


		int lineIndicator = 0;
		int columnIndicator = 0;



		while( true )  //This loop continues while user enters valid command
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






		for( lineIndicator=0 ; lineIndicator<5 ; lineIndicator++ )  //This loop sets line and column indexes of the asked piece's top-left corner
		{
			bool breakLoop = false;
			for( columnIndicator=0 ; columnIndicator<4 ; columnIndicator++ )
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

	


		//This if-else statements moves piece to given direction
		if( (command[0]<'5') )
		{
			if( command[2] == 'U' )
			{
				board[lineIndicator+1][columnIndicator] = '.';
				board[lineIndicator-1][columnIndicator] = command[0];

			}
			else if( command[2] == 'D' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator+2][columnIndicator] = command[0];

			}
			else if( command[2] == 'L' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator+1][columnIndicator] = '.';
				board[lineIndicator][columnIndicator-1] = command[0];
				board[lineIndicator+1][columnIndicator-1] = command[0];

			}
			else if( command[2] == 'R' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator+1][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+1] = command[0];
				board[lineIndicator+1][columnIndicator+1] = command[0];

			}
		}
		else if( command[0]>'5' && command[0]!='r')
		{
			if( command[2] == 'U' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator-1][columnIndicator] = command[0];
				
			}
			else if( command[2] == 'D' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator+1][columnIndicator] = command[0];
				
			}
			else if( command[2] == 'L' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator-1] = command[0];
				
			}
			else if( command[2] == 'R' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+1] = command[0];
				
			}
		}
		else if(command[0]=='5')
		{
			if( command[2] == 'U' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+1] = '.';
				board[lineIndicator-1][columnIndicator] = command[0];
				board[lineIndicator-1][columnIndicator+1] = command[0];
			}
			else if( command[2] == 'D' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+1] = '.';
				board[lineIndicator+1][columnIndicator] = command[0];
				board[lineIndicator+1][columnIndicator+1] = command[0];
			}
			else if( command[2] == 'L' )
			{
				board[lineIndicator][columnIndicator-1] = command[0];
				board[lineIndicator][columnIndicator+1] = '.';
			}
			else if( command[2] == 'R' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+2] = command[0];
			}
		}
		else
		{
			if( command[2] == 'U' )
			{
				board[lineIndicator+1][columnIndicator] = '.';
				board[lineIndicator+1][columnIndicator+1] = '.';
				board[lineIndicator-1][columnIndicator] = command[0];
				board[lineIndicator-1][columnIndicator+1] = command[0];
				
			}
			else if( command[2] == 'D' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+1] = '.';
				board[lineIndicator+2][columnIndicator] = command[0];
				board[lineIndicator+2][columnIndicator+1] = command[0];
				
			}
			else if( command[2] == 'L' )
			{
				board[lineIndicator][columnIndicator+1] = '.';
				board[lineIndicator+1][columnIndicator+1] = '.';
				board[lineIndicator][columnIndicator-1] = command[0];
				board[lineIndicator+1][columnIndicator-1] = command[0];
				
			}
			else if( command[2] == 'R' )
			{
				board[lineIndicator][columnIndicator] = '.';
				board[lineIndicator+1][columnIndicator] = '.';
				board[lineIndicator][columnIndicator+2] = command[0];
				board[lineIndicator+1][columnIndicator+2] = command[0];
				
			}
		}


}
















bool cse241hw5::Klotski::endGame() const
{
	if( board[4][1]=='r' && board[4][2]=='r')
	{
		return true;
	}
	else
	{
		return false;
	}

}














int cse241hw5::Klotski::boardScore()const
{
	int newScore = 0;

	for( int lineIndicator=0 ; lineIndicator<getBoardHeigth() ; lineIndicator++ )
	{
		bool endLoop = false;
		for( int columnIndicator=0 ; columnIndicator<getBoardWidth() ; columnIndicator++ )
		{
			if( board[lineIndicator][columnIndicator] == 'r' )
			{
				newScore = 3-lineIndicator;
				endLoop=true;
				break;
			}
		}

		if(endLoop)
		{
			break;
		}
	}


	return newScore;
} 



















