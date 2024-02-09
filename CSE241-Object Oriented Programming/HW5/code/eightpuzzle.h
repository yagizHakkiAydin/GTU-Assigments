#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H


#include "boardgame2d.h"








namespace cse241hw5{



class EightPuzzle : public cse241hw5::BoardGame2d
{
	public:
		EightPuzzle(){ initialize(); score=boardScore();}
		EightPuzzle( const EightPuzzle &obj );
		~EightPuzzle(){};


		
		
		void playUser( std::string &command ) override;
		bool endGame() const override;



		void initialize() override;
		void print() override;



		int boardScore() const override;






	private:




		bool isSolvable() const;   //checks if the board created randomly by initialize() is solvable


		const bool isCommandValid( const std::string& command ) const override;
		std::string generateRandomValidCommand() override;



};




}



#endif