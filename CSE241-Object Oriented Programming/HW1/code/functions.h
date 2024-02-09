#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include"game.h"



bool isCommandValid( const std::vector< std::vector<Cell> >& board  ,  const std::string& command );  //Checks command validity



//play functions uses "UL","UR","DL","DR" arguments in commands for type 6 board

void play( std::vector< std::vector<Cell> >& board  ,  std::string& command );  //Makes asked move with given command


void computerPlay(  std::vector< std::vector<Cell> >& board  );//Randomly plays until game is ended,uses play() function to make moves

void playerPlay(  std::vector< std::vector<Cell> >& board  );//Makes player play until game is ended,uses play() function to make moves




#endif