
//		This header file includes functions which are for initializing game and
// includes functions which modifies game only when they are called from functions.h
// also includes game struct which keeps every information of the game and Cell type



#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>









enum struct Cell{ pegged,empty,undefined };  //Cell type,a cell can be at three states







struct game  //this struct includes all information of a game
{
	std::vector< std::vector< Cell > > board;
	int boardWidth = 0;
	int boardHeigth = 0;
	int totalScore = 0;
	std::string gameMode = "Player";
	std::string moveDirection = "Vertical/Horizental";
};








bool isGameCorrupted( const game& pegSolitareGame);  //this function checks if game is corrupted


bool isCommandValid(  const game& pegSolitareGame ,  const std::string& command );  //checks command validity


std::vector< std::vector<Cell> > returnUndefinedBoard(const int width=9,const int heigth=9);  //Creates an 9x9 board with undefined cells



std::vector<Cell> createAndReturnBoardLine( int decimalLineValue );  //returns an 2d cell vector which represents board line,cell states are decided with given argument



std::vector< std::vector<Cell> > returnTypeOneBoard();			//
std::vector< std::vector<Cell> > returnTypeTwoBoard();		   //
std::vector< std::vector<Cell> > returnTypeThreeBoard();	  //returns board with shaping
std::vector< std::vector<Cell> > returnTypeFourBoard();	     //	9x9 undefined board
std::vector< std::vector<Cell> > returnTypeFiveBoard();	 	//
std::vector< std::vector<Cell> > returnTypeSixBoard(); 	   //



void printBoard( const game& pegSolitareGame ); //prints recent state of the game board


void chooseBoardType( game& pegSolitareGame ); //allows user to select board type from 1-6,for these specific board types,move direction is selected automatically


bool hasGameEnded( const game& pegSolitareGame );  //checks if game has ended




std::string generateRandomValidCommand( const  game &pegSolitareGame );  //returns a valid command to make move,used in computer play mode




void selectGameMode( game& pegSolitareGame );  //allows user to select game mode






#endif
