#include <stdexcept>
#include <sstream> 
#include <iostream>
#include "HandCollection.h"

/*
namespace Blackjack
{
	class HandCollection
	{//A collection of hands for a player of Blackjack.
		private:
			typedef std::vector<Hand> HandList;//A typedef to help the public side of the class, so don't have to keep using std::vector...
			HandList hands;//Put the hand in a vector since there could be more than one due to a split.

		public:
			HandCollection();//Default Cunstructor.
			size_t numHands() const;//Returns the number of hands in the collection.
			Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			//std::vector<Hand>& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandList::iterator HandCollection::addHand( Hand newHand, iterator position );//Add a hand at location position.
			void clearHands();//Remove all the hands.
			typedef HandList::iterator iterator;//An iterator for the hands.
			typedef HandList::const_iterator const_iterator;//A constant iterator for the hands.
			iterator begin();//An iterator for the beginning of the hands.
			iterator end();//An iterator for the end of the hands.
	};
}
*/


namespace Blackjack
{
	typedef std::vector<Hand> HandList;//A typedef to help the public side of the class, so don't have to keep using std::vector...

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

/*
	std::vector<Hand>& HandCollection::getHands()
	{//Returns the hands as a vector. This is mainly for use with HandsIterator.
		return hands;
	}
*/

	void HandCollection::addHand( Hand newHand )
	{//Add a hand to the end of the list;
		hands.push_back( newHand );
	}
/*
	void HandCollection::addHand( Hand newHand, size_t n )
	{//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
		std::stringstream errorStream;

		if( (n < 0) || (n >= numHands()) )
		{
			errorStream << "Trying to add a hand to location " << n << ", which is outside the list of hands. The location should be between 0 and " << (numHands() - 1) << ", inclusive.";
			std::cerr << errorStream.str() << std::endl;
			throw std::out_of_range( errorStream.str() );
		}
		else
		{
			hands.insert( (hands.begin() + n), newHand );
		}
	}
*/
	HandList::iterator HandCollection::addHand( Hand newHand, iterator position )
	{//Add a hand at location position.
		return hands.insert( position, newHand );
	}

	void HandCollection::clearHands()
	{//Remove all the hands.
		hands.clear();
	}

	HandCollection::HandList::iterator HandCollection::begin()
	{//An iterator for the beginning of the hands.
		return hands.begin();
	}

	HandCollection::HandList::iterator HandCollection::end()
	{//An iterator for the end of the hands.
		return hands.end();
	}
}
