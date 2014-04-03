#ifndef Player_h
#define Player_h

#include "Hand.h"
#include <vector>

namespace Blackjack
{
	class Player
	{//A Blackjack player.
		private:
			std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.

		public:
			Player();//Default Cunstructor.
			size_t numHands() const;//Returns the number of hands the player currently has.
			Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			void split( size_t n );//Splits the hand a location n if possible.
	};
}

#endif /* Player_h */
