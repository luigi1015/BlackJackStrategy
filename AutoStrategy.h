#ifndef AutoStrategy_h
#define AutoStrategy_h

#include "Card.h"
#include "Hand.h"

namespace Blackjack
{
	class AutoStrategy
	{//A Blackjack player that automatically plays without user input.
		protected:

		public:
			enum Decision { Hit, Stand, DoubleDown, Split };
			virtual ~AutoStrategy() {};//Default destructor
			virtual int decide( Card dealerCard, Hand playerHand ) { return 0; };//Takes the dealer's card, the player's cards, decide what to do, and return the appropriate Decision value.
	};
}

#endif /* AutoStrategy_h */
