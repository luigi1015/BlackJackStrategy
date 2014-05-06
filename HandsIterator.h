#ifndef HandsItearator_h
#define HandsItearator_h

#include "Hand.h"
//#include "Player.h"
#include <vector>

namespace Blackjack
{
	class HandsIterator
	{//A iterator to iterate over the player's hands. If the hands change while the iterator is in the middle of iterating, unexpected results may occur, but care is taken to keep the iterator working if hands are added after the current hand. 
		friend class Player;

		private:
			Player& player;//The player with the hands to iterate over.
			size_t position;//The current position among the hands. Starts at 0 and goes to player.numHands() - 1.
			size_t getNumHands() const;//Get the current number of hands.

		public:
			//HandsIterator( std::vector<Hand>& hands );
			HandsIterator( Player* newPlayer );//Constructor with the player.
			//~HandsIterator();
			void first();//Move to the first hand.
			void next();//Move to the next hand.
			bool isDone() const;//Check if this is the last hand.
			Hand& currentHand();//Return the current hand.

		protected:
			HandsIterator();//Default constructor. It's protected so it won't be called by an unauthorized class.
	};
}

#endif /* HandsItearator_h */
