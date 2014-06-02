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
			int play();//Automatically play blackjack. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
	};
}

#endif /* AutoPlayer_h */
