#include "boardgame2d.h"









void cse241hw5::BoardGame2d::playUser()
{
	std::string playCommand{""};



	while( !endGame() )
	{
		print();
		std::cout << "Enter your command-->";
		std::cin >> playCommand;
		playUser( playCommand );
	}
	system("clear");
	std::cout << "Game over,score is --> " << "" << std::endl;
	std::cout << "Final state of the board is below "  << std::endl;
	print();

}









void cse241hw5::BoardGame2d::playAuto()
{
	std::string command = generateRandomValidCommand();
	playUser( command );
}









void cse241hw5::BoardGame2d::playAutoAll()
{

	print();
	while( !endGame() )
	{
		playAuto();
		sleep(2);
		print();
	}

}













void cse241hw5::BoardGame2d::playVector( std::vector<cse241hw5::BoardGame2d*> &vec )
{

	if( vec.size() < 6 )
	{
		system("clear");
		std::cerr << "Less than 6 games for playVector(),program terminated...";
		exit(1);
	}


	vec[0]->playUser();
	vec[1]->playUser();
	vec[2]->playUser();
	vec[3]->playAutoAll();
	vec[4]->playAutoAll();
	vec[5]->playAutoAll();
	

}
















