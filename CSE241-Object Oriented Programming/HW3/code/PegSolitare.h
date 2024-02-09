#ifndef PEGSOLITARE_H
#define PEGSOLITARE_H


#include <cmath>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


enum struct CellState{ empty , pegged , undefined };



class PegSolitare
{


	public:

		PegSolitare();

		PegSolitare( int type );

		PegSolitare( std::string loadFileName );

		const bool hasGameEnded() const;



		const inline int getBoardWidth() const {  return boardWidth;  }

		const inline int getBoardHeigth() const {  return boardHeigth;  }

		const inline int getTotalScore() const {  return totalScore;  }

		const inline std::string getGameMode() const {  return gameMode;  }

		const inline std::string getMoveDirection() const {  return moveDirection;  }




		inline void setBoardWidth( int newWidth ) {  boardWidth = newWidth;  }

		inline void setBoardHeigth( int newHeigth ) {  boardHeigth = newHeigth; }

		inline void setTotalScore( int newScore ) {  totalScore = newScore;  }

		inline void setGameMode( std::string newMode ) {  gameMode = newMode; }

		void setBoardType( const int type );

		inline void setMoveDirection( std::string newDirection ) {  moveDirection = newDirection;  }


		void printBoard();


		inline bool hasThisGameMorePegs( PegSolitare &obj ){ return (  returnNumOfPegs()>obj.returnNumOfPegs()  ); }


		const int returnNumOfPegs() const;

		const int returnNumOfEmpty() const;

		static int returnNumOfTotalPegsOfAllBoards() { return totalNumberOfPegsOfAllBoards; }


		void play();

		void play( std::string command );

		void playGame();

		void load( const std::string loadCommand );

		void save( const std::string saveCommand ) const;




		void testBoard();









		class Cell
		{
			public:



				Cell() : Cell( "-1" , "-1" , CellState::undefined ){ /*Intentionally Empty*/ }
				Cell( const std::string xPosition , const std::string yPosition , const CellState stateOfCell);


				void testCell();

				const inline std::string getLinePosition() const{ return linePosition; }
				const inline std::string getColumnPosition() const{ return columnPosition; }
				const inline CellState getState() const{ return state; }

				inline void setLinePosition( std::string newPosition ){ linePosition = newPosition; }
				inline void setColumnPosition( std::string newPosition ){ columnPosition = newPosition; }
				inline void setState( CellState newState ){ state = newState; }



			private:
				std::string linePosition;
				std::string columnPosition;
				CellState state;

		};








	private:

		std::vector< std::vector< Cell > > board;
		int boardWidth;
		int boardHeigth;
		int totalScore;
		std::string gameMode;
		std::string moveDirection;

		static int totalNumberOfPegsOfAllBoards;

		const bool isGameCorrupted() const;



		std::vector< std::vector<Cell> > returnUndefinedBoard(const int width,const int heigth);

		std::vector<Cell> createAndReturnBoardLine( int width , int columnPositionOfLine, int decimalLineValue );

		std::vector< std::vector<Cell> > returnTypeOneBoard();			//
		std::vector< std::vector<Cell> > returnTypeTwoBoard();		   //
		std::vector< std::vector<Cell> > returnTypeThreeBoard();	  //
		std::vector< std::vector<Cell> > returnTypeFourBoard();	     //	
		std::vector< std::vector<Cell> > returnTypeFiveBoard();	 	//
		std::vector< std::vector<Cell> > returnTypeSixBoard(); 	   //

		std::string generateRandomValidCommand();


		const bool isCommandValid( const std::string& command ) const;



};





#endif