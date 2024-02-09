#include "boardgame2d.h"
#include "pegsolitare.h"
#include "klotski.h"
#include "eightpuzzle.h"
#include <iostream>




int main()
{

	cse241hw5::PegSolitare *obj = new cse241hw5::PegSolitare;
	cse241hw5::EightPuzzle *obj2 = new cse241hw5::EightPuzzle;
	cse241hw5::Klotski *obj3 = new cse241hw5::Klotski;
	cse241hw5::PegSolitare *obj4 = new cse241hw5::PegSolitare;
	cse241hw5::EightPuzzle *obj5 = new cse241hw5::EightPuzzle;
	cse241hw5::Klotski *obj6 = new cse241hw5::Klotski;







	std::vector<cse241hw5::BoardGame2d*> games;

	games.push_back( obj );
	games.push_back( obj2 );
	games.push_back( obj3 );
	games.push_back( obj4 );
	games.push_back( obj5 );
	games.push_back( obj6 );



	(*obj).playVector( games );





	return 0;
}