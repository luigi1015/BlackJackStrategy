#ifndef UserPlayer_h
#define UserPlayer_h

//#include "Hand.h"
#include "Player.h"

namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer();//Default Constructor.
			UserPlayer( std::string newName );//Constructor with the player's name.
			void play();//Play blackjack with user input.
	};
}

#endif /* UserPlayer_h */
