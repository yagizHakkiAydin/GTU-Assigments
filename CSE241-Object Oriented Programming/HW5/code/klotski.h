#ifndef KLOTSKI_H
#define KLOTSKI_H


#include "boardgame2d.h"



namespace cse241hw5{


	class Klotski : public cse241hw5::BoardGame2d
	{
		public:
			Klotski(){ initialize(); score=3;}
			Klotski( const Klotski& obj ){}
			~Klotski(){}

			void print() override;
			void initialize() override;


			void playUser( std::string &command ) override;
			bool endGame() const override;


			int boardScore()const override;







		private:
			const bool isCommandValid( const std::string& command ) const override;
			std::string generateRandomValidCommand() override;





	};


}





#endif