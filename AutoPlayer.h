#ifndef AutoPlayer_h
#define AutoPlayer_h

#include "Hand.h"
#include “Player.h”

namespace Blackjack
{
	class AutoPlayer: public Player
	{//A Blackjack player that automatically plays without user input.
		private:

		public:
			AutoPlayer();//Default Cunstructor.
	};
}

#endif /* AutoPlayer_h */
