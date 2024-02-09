#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "game.h"


void startGame( game& pegSolitareGame );  //used to start game

void makeMove( game& pegSolitareGame  ,  std::string& command );  //used to make move with given command,used by play functions,doesn't get used directly



void playerPlay( game &pegSolitareGame );  //allows player play until game ends


void computerPlay( game &pegSolitareGame );  //allows computer play until game ends,gets 'P' command from user to make computer a move


void load( game& pegSolitareGame , const std::string loadCommand);  //loads game from a file with given name,this function doesn't get filename directly as argument,it takes all command


void save( const game& pegSolitareGame , const std::string saveCommand );  //saves game to a file with given  name,this function doesn't get filename directly as argument,it takes all command





#endif