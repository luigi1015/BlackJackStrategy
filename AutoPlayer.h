#ifndef AutoPlayer_h
#define AutoPlayer_h

//#include "Hand.h"
#include "Player.h"

namespace Blackjack
{
	class AutoPlayer: public Player
	{//A Blackjack player that automatically plays without user input.
		private:

		public:
			AutoPlayer();//Default Constructor.
			AutoPlayer( std::string newName );//Constructor with the player's name.
			void play();//Automatically play blackjack.
	};
}

#endif /* AutoPlayer_h */
