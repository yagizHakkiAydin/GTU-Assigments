//Yağız Hakkı Aydın
//1901042612






#include"functions.h"
#include"game.h"








int main( int argc , char** argv )
{
	std::vector< std::vector<Cell> > gameBoard;  //board is represented by 2d cell vector,not initialized yet,will be initialized by setBoardType()

	std::string gameType = "";


	system("clear");//clears terminal before starting game

	std::cout << "Welcome to peg solitare" << std::endl;



	setBoardType( gameBoard );
	std::cout << "Here is initial board" << std::endl;
	printBoard(gameBoard);



	while( true )  //used to make correct game mode selection,if correct game mode command is entered,loop ends
	{



		std::cout << std::endl << "For player game please enter 'P'" << std::endl;
		std::cout << "For computer game please enter 'C'" << std::endl;
		std::cout << "Your choice --> ";


		std::cin >> gameType;

		if( (gameType!="P") && (gameType!="C"))
		{
			std::cout << std::endl << "Please make a valid choice" << std::endl;
		}
		else if( gameType == "P" )
		{
			playerPlay(gameBoard);
			break;
		}
		else if( gameType == "C" )
		{
			computerPlay(gameBoard);
			break;
		}


	}





	std::cout << std::endl << std::endl << "Game over,final score is--> " << getFinalScore(gameBoard) << std::endl;
	std::cout << std::endl << "here is final board..." << std::endl;
	printBoard(gameBoard);
	std::cout << std::endl;



	return 0;
}



















