#include "PegSolitare.h"










int main()
{
	system( "CLEAR" );

	std::vector <PegSolitare> games(5);

	int whichGameIsActive = 1;

	int boardTypeSelection = 0;

	int gameModeSelection = 0;

	bool hasAllGamesEnded = false;

	std::string command{""};

	
	std::cout << "        Welcome to the Peg Solitare..." << std::endl;
	std::cout << "There are " << games.size() << " games active at the moment" << std::endl;





	for( int gameIndex=0 ; gameIndex<games.size() ; gameIndex++ )  //This loop sets gameModes for all active games
	{

			std::cout << std::endl << std::endl << "Make your gamemode selection for game " << gameIndex+1 << std::endl;
			std::cout << "To play player game,enter '1' " << std::endl;
			std::cout << "To semi-computer player game,enter '2' " << std::endl;
			std::cout << "To play computer game,enter '3' " << std::endl;


			while( true )  //This loop makes user select gamemode correctly
			{
				std::cout << "Your choice --> ";

				std::cin >> gameModeSelection;

				if( gameModeSelection<1 || gameModeSelection>3 )
				{
					std::cerr << "Invalid gamemode selection,please make a valid selection for game " << gameIndex+1 << std::endl;
				}
				else if( gameModeSelection == 1 )
				{
					games[gameIndex].setGameMode("Player");
					break;
				}
				else if( gameModeSelection == 2 )
				{
					games[gameIndex].setGameMode("Semi-Computer");
					break;
				}
				else if( gameModeSelection == 3 )
				{
					games[gameIndex].setGameMode("Computer");
					break;
				}
			}

			system("CLEAR");

	}

			



	for( int gameIndex=0 ; gameIndex<games.size() ; gameIndex++ )  //This loop sets board type for all active games
	{

			std::cout << std::endl << std::endl << "Make your board type selection between 1-6 , or enter 0 for default board for game " << gameIndex+1 << std::endl;



			while( true )    //This loop makes user select board type correctly
			{
				std::cout << "Your choice --> ";

				std::cin >> boardTypeSelection;

				if( boardTypeSelection<0 || boardTypeSelection>6 )
				{
					std::cerr << "Invalid board type selection,please make a valid selection for game " << gameIndex+1 << std::endl;
				}
				else if( boardTypeSelection>0 || boardTypeSelection<7 )
				{
					games[gameIndex].setBoardType( boardTypeSelection );
					break;
				}

			}

			system("CLEAR");

	}



	std::cin.ignore();
	
	

	while( !hasAllGamesEnded )  //This loop plays the game until all active games are finished
	{





		if( games[whichGameIsActive-1].hasGameEnded() )  //This loop makes user switch game if corresponding game is over
		{

				std::cout << std::endl <<  "Game '" << whichGameIsActive << "' is over , switch to another game..";

				while( true )  //This loop makes user switch to unfinished game correctly
				{
					std::cout << std::endl <<  "Switch to --> ";
					std::cin >> whichGameIsActive;

					if( whichGameIsActive<1 || whichGameIsActive>games.size() )
					{
						std::cerr << "Invalid selection,please select an existing game between 1-" << games.size();
					}
					else if( games[whichGameIsActive-1].hasGameEnded() )
					{
						std::cerr << "Game " << whichGameIsActive << "is over,please select an unfinished game...";
					}
					else
					{
						break;
					}

				}
		}



		//This statement makes computer play game until it's over
		else if( games[whichGameIsActive-1].getGameMode()=="Computer" )
		{
				games[whichGameIsActive-1].playGame();
		}


		//This statement makes computer play game too but it gets 'p' character to make computer a move
		//That's because in computer mode,game gets finished automaticcaly and user can't load a game
		else if( games[whichGameIsActive-1].getGameMode()=="Semi-Computer" )
		{
				games[ whichGameIsActive-1 ].printBoard();

				std::cout << std::endl  << "Enter 'p' to make computer a move" << std::endl;
				std::cout << "Enter \"SWITCH\" to switch game" << std::endl;
				std::cout << "Enter \"LOAD 'File Name'\" to load game" << std::endl;
				std::cout << "Enter \"SAVE 'File Name'\" to save game" << std::endl;
				std::cout << "Your selection --> ";


				getline(std::cin,command);  //Gets command to make computer a move or load/save/switch game

				if( command == "p" )
				{
					games[ whichGameIsActive-1 ].play();
				}
				else if( command == "SWITCH" )
				{

					while( true )  //This loop makes user switch game correctly
					{
						std::cout << std::endl << "Switch to game between 1-" << games.size() << "  --> ";

						std::cin >> whichGameIsActive;

						if( whichGameIsActive<1 || whichGameIsActive>games.size() )
						{
							std::cerr << "Invalid selection,please select an existing game between 1-" << games.size();
						}
						else
						{
							break;
						}
					}
				}
				else if( command.substr(0,4) == "LOAD" )
				{
					games[ whichGameIsActive-1 ].load(command);
				}
				else if( command.substr(0,4) == "SAVE" )
				{
					games[ whichGameIsActive-1 ].save(command);
				}


		}
		else if( games[whichGameIsActive-1].getGameMode()=="Player" )
		{
				games[ whichGameIsActive-1 ].printBoard();
				std::cout << std::endl << "Enter your command to make a move" << std::endl;
				std::cout << "enter \"SWITCH\" to switch game" << std::endl;
				std::cout << "Enter \"LOAD 'File Name'\" to load game" << std::endl;
				std::cout << "Enter \"SAVE 'File Name'\" to save game" << std::endl;
				std::cout << "Your selection --> ";


				getline(std::cin,command);

				if( command == "SWITCH" )
				{

					while( true )
					{
						std::cout << std::endl << "Switch to game between 1-" << games.size() << "  --> ";
						std::cin >> whichGameIsActive;
						if( whichGameIsActive<1 || whichGameIsActive>games.size() )
						{
							std::cerr << "Invalid selection,please select an existing game between 1-" << games.size();
						}
						else
						{
							break;
						}
					}
				}
				else if( command.substr(0,4) == "LOAD" )
				{
					games[ whichGameIsActive-1 ].load(command);
				}
				else if( command.substr(0,4) == "SAVE" )
				{
					games[ whichGameIsActive-1 ].save(command);
				}
				else
				{
					games[ whichGameIsActive-1 ].play( command );
				}



		}




		for( int gameIndex=0 ; gameIndex<games.size() ; gameIndex++)  //this loop checks all games and if all of them has finished
		{
			hasAllGamesEnded = true;
			if( !games[gameIndex].hasGameEnded() )
			{
				hasAllGamesEnded = false;
				break;
			}
		}

		
}



	system("CLEAR");

	std::cout << "All games are over..." << std::endl;
	std::cout << "Total number of pegs taken = " << games[0].returnNumOfTotalPegsOfAllBoards();



	return 0;
}
















