#include "functions.h"













void makeMove( game& pegSolitareGame  ,  std::string& command )
{


		if( !isCommandValid(pegSolitareGame,command) )  //if this function gets an invalid command,that means play functions are corrupted
		{
			std::cerr << std::endl << "Invalid command for makeMove() function , program terminated..." << std::endl;
			exit(1);
		}



		const int lineIndex{ command[0] - 65 };      //  Line and column indexes are converted to integer
		const int columnIndex{ command[1] - 49 };   // from characters of command string



		const std::string direction ={ command.substr(3) };  //direction string gets set from substring of command string 



		pegSolitareGame.board[columnIndex][lineIndex] = Cell::empty;  //Wherever corresponding cell moves,corresponding cell's coordinate will be empty after move



		//these if-else statements makes move to given direction

		if( direction == "U" )
		{
			pegSolitareGame.board[columnIndex-1][lineIndex] = Cell::empty;
			pegSolitareGame.board[columnIndex-2][lineIndex] = Cell::pegged;
		}
		else if( direction == "D" )
		{
			pegSolitareGame.board[columnIndex+1][lineIndex] = Cell::empty;
			pegSolitareGame.board[columnIndex+2][lineIndex] = Cell::pegged;
		}
		else if( direction == "L" )
		{
			pegSolitareGame.board[columnIndex][lineIndex-1] = Cell::empty;
			pegSolitareGame.board[columnIndex][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "R" )
		{
			pegSolitareGame.board[columnIndex][lineIndex+1] = Cell::empty;
			pegSolitareGame.board[columnIndex][lineIndex+2] = Cell::pegged;
		}
		else if( direction == "UL" )
		{
			pegSolitareGame.board[columnIndex-1][lineIndex-1] = Cell::empty;
			pegSolitareGame.board[columnIndex-2][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "DL" )
		{
			pegSolitareGame.board[columnIndex+1][lineIndex-1] = Cell::empty;
			pegSolitareGame.board[columnIndex+2][lineIndex-2] = Cell::pegged;
		}
		else if( direction == "UR" )
		{
			pegSolitareGame.board[columnIndex-1][lineIndex+1] = Cell::empty;
			pegSolitareGame.board[columnIndex-2][lineIndex+2] = Cell::pegged;
		}
		else if( direction == "DR" )	
		{
			pegSolitareGame.board[columnIndex+1][lineIndex+1] = Cell::empty;
			pegSolitareGame.board[columnIndex+2][lineIndex+2] = Cell::pegged;
		}

}

















void playerPlay( game &pegSolitareGame )
{

	std::string command{ "" };

	printBoard(pegSolitareGame);

	while( !hasGameEnded(pegSolitareGame) )
	{
		std::cout << std::endl << "Enter command-->";

		getline(std::cin,command);


		if(command.substr(0,4) == "LOAD")
		{
			load( pegSolitareGame , command);
			printBoard( pegSolitareGame );
			if( pegSolitareGame.gameMode == "Computer" )
			{
				computerPlay(pegSolitareGame);
				break;
			}
		}
		else if(command.substr(0,4) == "SAVE")
		{
			save( pegSolitareGame , command );
			printBoard( pegSolitareGame );
		}
		else if( isCommandValid(pegSolitareGame,command) )
		{   
			system("clear");  //clears terminal after every move

			makeMove(pegSolitareGame,command);  //play function called with given command

			std::cout << "You played-->" << command << std::endl << std::endl;
			std::cout << "Here is the board" << std::endl;

			pegSolitareGame.totalScore++;
			printBoard(pegSolitareGame);
		}
		else
		{
			std::cout <<" Invalid command " << std::endl;
		}

	}

	std::cout << std::endl << "Game Over,total score --> " << pegSolitareGame.totalScore << std::endl;


}














void computerPlay( game &pegSolitareGame )
{

	srand( time(NULL) );


	const int boardWidth { pegSolitareGame.boardWidth };
	const int boardHeigth { pegSolitareGame.boardHeigth };



	const std::vector< std::string  > directions {   {"U","D","L","R","UL","DL","UR","DR"}   };         //   Vectors of every direction,column and line


	int columnIndex = 0;        //
	int lineIndex = 0;	       // Indexes of vectors above
	int directionIndex = 0;   //




	while( !hasGameEnded(pegSolitareGame) )  //Makes computer play until game has ended
	{

		std::string action{ "" };
		std::string command{ "" };

		std::cout << std::endl << std::endl <<  "To let computer make a move,enter 'P' ";
		std::cout << std::endl <<  "To load a game from a file , enter \" LOAD 'File Name' \" ";
		std::cout << std::endl <<  "To save game to a file , enter \" SAVE 'File Name' \" ";
		std::cout << std::endl << std::endl <<  "Your Selection --> ";


		getline( std::cin , action );


		if(action.substr(0,4) == "LOAD")
		{
			load(pegSolitareGame,action);
			printBoard( pegSolitareGame );
			if( pegSolitareGame.gameMode == "Player" )
			{
				playerPlay(pegSolitareGame);
				break;
			}
		}
		else if(action.substr(0,4) == "SAVE")
		{
			save(pegSolitareGame,action);
			printBoard( pegSolitareGame );
		}

		else if( action != "P" )
		{
			std::cerr << "Invalid selection,please make a valid selection";
		}


		else
		{
			command = generateRandomValidCommand( pegSolitareGame );
			makeMove( pegSolitareGame , command   );
			pegSolitareGame.totalScore++;
			printBoard( pegSolitareGame );
		}


	}


	std::cout << std::endl << "Game Over,total score --> " << pegSolitareGame.totalScore << std::endl;


}



























void load( game& pegSolitareGame , const std::string loadCommand )
{





	int lineIndex=0,columnIndex=0;  //


	std::ifstream file( loadCommand.substr(5) );  //this line gets loadCommand's substring which is file name

	std::string tempLine{ "" };  //used at reading load file with getline()



	pegSolitareGame.boardHeigth = 0;  //These lines sets board width and board heigth 0
	pegSolitareGame.boardWidth = 0;  //because game width and heigth will be set from load file




	while( getline(file,tempLine) )  //this loop reads file line by line until game properties line,sets board width and heigth
	{
		if( tempLine.substr(0,4) == "Game" )  //This line ends loop if corresponding line doesn't keep a board line,but it keeps game property
		{
			break;
		}

		pegSolitareGame.boardHeigth++;  //increaases board heigth for every board line read from load file

		if( tempLine.length() > pegSolitareGame.boardWidth )  //sets board width to widthest board line of load file
		{
			pegSolitareGame.boardWidth = tempLine.length();
		}
	}



	tempLine.clear();  //clears tempLine because it will be used again to read file again 
	file.close();  //closes load file,because it will be read again



	pegSolitareGame.board = returnUndefinedBoard(pegSolitareGame.boardWidth,pegSolitareGame.boardHeigth);  //creates a undefined board with width and heigth read from load file




	file.open( loadCommand.substr(5) );  //opens loadFile to set created undefined board to the shape which is given in loadFile



	while( getline(file,tempLine) )  //reads load file to set board,move direction , total score and game mode.
	{
		lineIndex=0;  //line index of the board vector,used to fill board from loadFile

		if( tempLine.substr(0,4) == "Game" )  //Sets game mode from needed line
		{
			pegSolitareGame.gameMode = tempLine.substr(11);
		}
		else if( tempLine.substr(0,4) == "Move" )  //Sets move direction from needed line
		{
			pegSolitareGame.moveDirection = tempLine.substr(17);
		}
		else if( tempLine.substr(0,5) == "Total" )  //Sets total score from needed line
		{
			pegSolitareGame.totalScore = stoi( tempLine.substr(14) );
		}
		else //sets board from needed lines
		{
			for( auto cellChar : tempLine )  //reads every character of given line and sets every cell of the board
			{	

				if( cellChar == 'P' )
				{
					pegSolitareGame.board[columnIndex][lineIndex] = Cell::pegged;
				}
				else if( cellChar == '.' )
				{
					pegSolitareGame.board[columnIndex][lineIndex] = Cell::empty;
				}
				else
				{
					pegSolitareGame.board[columnIndex][lineIndex] = Cell::undefined;
				}
				lineIndex++;
			}
			columnIndex++;
		}
		
	}


}














void save( const game& pegSolitareGame , const std::string saveCommand )
{

	std::ofstream saveFile( saveCommand.substr(5) );  //opens a file with given name by command

	int columnIndex{ 0 };  //column index of board vector of the game

	for( auto line : pegSolitareGame.board )  //counts every line of the board
	{
		for( auto boardCell : pegSolitareGame.board[columnIndex] )  //writes necessary character to the saveFile for every cell of the board
		{
			if( boardCell == Cell::pegged )
			{
				saveFile << "P";
			}
			else if( boardCell == Cell::empty )
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



	saveFile << "Gamemode = " << pegSolitareGame.gameMode << std::endl;				  //
	saveFile << "Move Direction = " << pegSolitareGame.moveDirection << std::endl;   //Writes game mode,move direction and total score to the saveFile
	saveFile << "Total Score = " << pegSolitareGame.totalScore;					    //


	saveFile.close();



}



























void startGame( game& pegSolitareGame )
{

	std::string command{ "" };
	std::cout << std::endl << "To play with available board types , enter 'START'";
	std::cout << std::endl << "To load game,enter \" LOAD 'File Name' \" -->";
	std::cout << std::endl << "Your selection -->";
	getline( std::cin,command );



	if( command.substr(0,4) == "LOAD" )  //loads the game with load()
	{
		load(pegSolitareGame,command);
	}
	else if( command.substr(0,5) == "START")  //starts a game with a specific board type
	{
		chooseBoardType( pegSolitareGame );
		selectGameMode( pegSolitareGame );
	}
	else
	{
		std::cerr << std::endl << "Invalid choice,please make a valid choice" << std::endl;
		startGame(pegSolitareGame);
	}




	if( pegSolitareGame.gameMode == "Computer" )
	{
		system("CLEAR");
		printBoard( pegSolitareGame );
		computerPlay(pegSolitareGame);
	}
	else
	{
		system("CLEAR");
		playerPlay(pegSolitareGame);
	}

	
}


