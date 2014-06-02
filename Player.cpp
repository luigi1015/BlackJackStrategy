#include "Player.h"
#include <stdexcept>

/*
namespace Blackjack
{
	class Player
	{//A Blackjack player.
		private:
			//std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.
			HandCollection collHands;
			std::string name;
			Dealer* myDealer;//The dealer for this game.
			unsigned int ID;//The programatically generated ID of the payer.

		public:
			Player( unsigned int newID );//Constructor with the ID.
			//size_t numHands() const;//Returns the number of hands the player currently has.
			//Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandCollection& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			//void split( size_t n );//Splits the hand at location n. Throws an exception if the hand can't be split according to the rules of blackjack. n should be between 0 and numHands()-1, inclusive.
			void split( HandsIterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual void play();//Virtual method for this player to play Blackjack.
			void getRandomCard( iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName();//Returns the name of the player.
			void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
	};
}
*/


namespace Blackjack
{
	Player::Player( unsigned int newID )
	{//Default Cunstructor.
		myDealer = 0;
		setID( newID );
	}

/*
	size_t Player::numHands() const
	{//Returns the number of hands the player currently has.
		return hands.size();
	}

	Hand& Player::getHand( size_t n )
	{//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
		return hands.at(n);
	}
*/

	HandCollection& Player::getHands()
	{//Returns the hands as a vector. This is mainly for use with HandsIterator.
		return collHands;
	}

	void Player::split( HandsIterator iteratorPosition )
	{//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
		
	}

/*
	void Player::addHand( Hand newHand )
	{//Add a hand to the end of the list;
	}

	void Player::addHand( Hand newHand, size_t n )
	{//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
	}

	void clearHands()
	{//Remove all the hands.
		hands.clear();
	}
*/
	void Player::getRandomCard( iterator iteratorPosition )
	{//Gets a random card for the hand pointed to by iteratorPosition.
		if( myDealer != 0 )
		{//The dealer object is not a null pointer, so it's ok to use that to get a random card.
			*iteratorPosition.addCard( myDealer->getRandomCard() );
		}
		else
		{//The dealer object is a null pointer, throw an error.
			throw std::runtime_error( "In Player::getRandomCard( iterator iteratorPosition ), the dealer isn't registered to the player. The function needs the dealer to ger a random card."
		}
	}

	void Player::setName( std::string newName )
	{//Sets the name of the player.
		name = newName;
	}

	std::string Player::getName()
	{//Returns the name of the player.
		return name;
	}

	void Player::setDealer( Dealer* newDealer )
	{//Sets the name of the player.
		myDealer = newDealer;
	}
	void setID( unsigned int newID )
	{//Set the ID to newID.
		ID = newID;
	}

	unsigned int getID()
	{//Returns the ID.
		return ID;
	}
}
