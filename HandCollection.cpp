#include "HandCollection.h"
/*
namespace Blackjack
{
	class HandCollection
	{//A collection of hands for a player of Blackjack.
		private:
			std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.

		public:
			HandCollection();//Default Cunstructor.
			size_t numHands() const;//Returns the number of hands in the collection.
			Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			std::vector<Hand>& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			void addHand( Hand newHand );//Add a hand to the end of the list;
			void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			void clearHands();//Remove all the hands.
	};
}
*/


namespace Blackjack
{
	HandCollection::HandCollection()
	{//Default Cunstructor.
	}

	size_t HandCollection::numHands() const
	{//Returns the number of hands in the collection.
		return hands.size();
	}

	Hand& HandCollection::getHand( size_t n )
	{//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
		return hands.at(n);
	}

	std::vector<Hand>& HandCollection::getHands()
	{//Returns the hands as a vector. This is mainly for use with HandsIterator.
		return hands;
	}

	void HandCollection::addHand( Hand newHand )
	{//Add a hand to the end of the list;
	}

	void HandCollection::addHand( Hand newHand, size_t n )
	{//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
	}

	void HandCollection::clearHands()
	{//Remove all the hands.
		hands.clear();
	}
}
