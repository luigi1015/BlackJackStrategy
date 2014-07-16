#ifndef AutoStrategy_h
#define AutoStrategy_h

#include <vector>

namespace Blackjack
{
	class AutoStrategy
	{//A Blackjack player that automatically plays without user input.
		protected:

		public:
			enum Decision { Bet, Stand, DoubleDown, Split };
			virtual int decide( Card dealerCard, HandCollection playerCards ) const;//Takes the dealer's card, the player's cards, decide what to do, and return the appropriate Decision value.
	};
}

#endif /* AutoStrategy_h */
