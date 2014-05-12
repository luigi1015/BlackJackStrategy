#ifndef HandCollection_h
#define HandCollection_h

#include "Hand.h"
#include <vector>

namespace Blackjack
{
	class HandCollection
	{//A collection of hands for a player of Blackjack.
		public:
			typedef std::vector<Hand> HandList;//A typedef to help the public side of the class, so don't have to keep using std::vector...
			HandCollection();//Default Cunstructor.
			size_t numHands() const;//Returns the number of hands in the collection.
			Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			//std::vector<Hand>& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			void addHand( Hand newHand );//Add a hand to the end of the list;
			void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			void addHand( Hand newHand, HandList::iterator position );//Add a hand at location position.
			void clearHands();//Remove all the hands.
			typedef HandList::iterator iterator;//An iterator for the hands.
			typedef HandList::const_iterator const_iterator;//A constant iterator for the hands.
			HandList::iterator begin();//An iterator for the beginning of the hands.
			HandList::iterator end();//An iterator for the end of the hands.

		private:
			//typedef std::vector<Hand> HandList;//A typedef to help the public side of the class, so don't have to keep using std::vector...
			HandList hands;//Put the hand in a vector since there could be more than one due to a split.
	};
}

#endif /* HandCollection_h */
