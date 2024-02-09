#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H



#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>	//for printing every move after some pause








namespace cse241hw5
{

	class BoardGame2d
	{
		public:
			BoardGame2d() : score(0){/*Intentionally Empty*/};
			BoardGame2d( const BoardGame2d &obj ){};
			virtual ~BoardGame2d(){};



			virtual void initialize() = 0;    //Initializes the game

			virtual void playUser() final;    //Plays the game until it ends,it gets user input for every
			virtual void playUser( std::string &command ) = 0;    //Gets input from the user ,plays the game for 1 moves
			virtual void playAuto() final;	//Plays game for one move automatically
			virtual void playAutoAll() final;    //Plays the game automatically until it ends

			virtual void print() = 0;    //Prints the game 

			virtual int boardScore() const =0;   //returns score at the step


			virtual bool endGame() const = 0;    //returns if game has ended


			int getBoardWidth() const{ return boardWidth; }
			int getBoardHeigth() const{ return boardHeigth; }






			static void playVector( std::vector<cse241hw5::BoardGame2d*> &vec );

		protected:
			std::vector< std::vector<char> > board;    //keeps game board

			int score;
			int boardWidth;
			int boardHeigth;

			virtual const bool isCommandValid( const std::string& command ) const = 0;    //checks if given command is valid

			virtual std::string generateRandomValidCommand() = 0;    //Generates command to make a move
	};


}


















#endif