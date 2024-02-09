#ifndef PEGSOLITARE_H
#define PEGSOLITARE_H


#include "boardgame2d.h"


namespace cse241hw5{

	class PegSolitare : public cse241hw5::BoardGame2d
	{

		public:

			PegSolitare(){ initialize(); score=43;}
			PegSolitare( const PegSolitare &obj );
			~PegSolitare(){};


			
			
			void playUser( std::string &command ) override;
			bool endGame() const override;



			void initialize() override;

			void print() override;


			int boardScore() const override;







		private:

			std::string generateRandomValidCommand() override;
			const bool isCommandValid( const std::string& command ) const override;
			

	};


}





#endif