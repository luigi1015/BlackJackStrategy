#include "HandsIterator.h"
#include <vector>
#include <stdexcept>
#include <sstream> 
#include <iostream> 

/*
namespace Blackjack
{
	class HandsIterator
	{//A iterator to iterate over the player's hands. If the hands change while the iterator is in the middle of iterating, unexpected results may occur, but care is taken to keep the iterator working if hands are added after the current hand. 
		private:
			Player& player;//The player with the hands to iterate over.
			size_t position;//The current position among the hands. Starts at 0 and goes to player.numHands() - 1.
			size_t getNumHands() const;//Get the current number of hands.

		public:
			//HandsIterator( std::vector<Hand>& hands );
			HandsIterator( Player& newPlayer );//Constructor with the player.
			//~HandsIterator();
			void first();//Move to the first hand.
			void next();//Move to the next hand.
			bool isDone() const;//Check if this is the last hand.
			Hand& currentHand();//Return the current hand.

		protected:
			Iterator();//Default constructor. It's protected so it won't be called by an unauthorized class.
	};
}
*/


namespace Blackjack
{
	HandsIterator::HandsIterator( Player& newPlayer )
	{//Constructor with the player.
		player = newPlayer;
		first();
	}

	void HandsIterator::first()
	{//Move to the first hand.
		position = 0;
	}

	void HandsIterator::next()
	{//Move to the next hand.
		position++;
	}

	bool HandsIterator::isDone() const
	{//Check if this is the last hand.
		return ( position >= getNumHands() );
	}

	size_t HandsIterator::getNumHands() const
	{//Get the current number of hands.
		return player.numHands();
	}

	Hand& HandsIterator::currentHand()
	{//Return the current hand.
		std::stringstream errorString;

		if( isDone() )
		{//There is no current hand since the iterator has gone past the end.
			errorString << "This iterator is out of range. It's trying to access hand number " << position << " when there are " << getNumHands() << " hands (the last hand is number " << (getNumHands() - 1) << ").";
			std::cerr << errorString.str() << std::endl;
			throw std::out_of_range( errorString.str() );
		}
		else
		{
			return getHand( position );
		}
	}
}
