#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>



enum struct Cell{ pegged , empty , undefined };  //Cells can be in 3 different states and undefined cells shapes 9x9 board to wanted type




std::vector< std::vector<Cell> > createUndefinedBoard();  //Creates an 9x9 board with undefined cells

std::vector<Cell> createLine( int decimalLineValue );  //creates 1D cell vectors to shape board to wanted type,used in initializing board types



void setBoardType( std::vector< std::vector<Cell> >& board ); //Prints board type choice menu for user , gets user's board type choice



std::vector< std::vector<Cell> > initializeTypeOneBoard();			//
std::vector< std::vector<Cell> > initializeTypeTwoBoard();		   //
std::vector< std::vector<Cell> > initializeTypeThreeBoard();	  //Initializes board with shaping
std::vector< std::vector<Cell> > initializeTypeFourBoard();	     //	9x9 undefined board
std::vector< std::vector<Cell> > initializeTypeFiveBoard();	 	//
std::vector< std::vector<Cell> > initializeTypeSixBoard(); 	   //




bool isGameEnded(  const std::vector< std::vector<Cell> >& board   );  //Checks if game is ended or not




int getBoardType( const std::vector< std::vector<Cell> >& board );  //returns board type

int getBoardWidth( const std::vector< std::vector<Cell> >& board );  //returns board width

int getBoardHeigth( const std::vector< std::vector<Cell> >& board );  //returns board heigth



void printBoard( const std::vector< std::vector<Cell> >& board );  //Prints the board's current situation


int getFinalScore( const std::vector< std::vector<Cell> >& board );  //Returns final score







#endif