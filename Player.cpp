#include "Player.h"
#include <stdexcept>
#include <iostream>
#include "Random-Cpp/random.cpp"

/*
namespace Blackjack
{
	class Player
	{//A Blackjack player.
		private:
			//std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.
			HandCollection collHands;
			std::string name;
			//Dealer* myDealer;//The dealer for this game.
			unsigned int ID;//The programatically generated ID of the payer.
			long money;//How much money the player has.

		public:
			enum playReturnValues { quitPlaying, keepPlaying };//Return values for the play method. quitPlaying will tell the dealer that the player wants to stop while keepPlaying will tell the dealer that the player wants to continue.
			Player( unsigned int newID );//Constructor with the ID.
			Player( unsigned int newID, std::string newName );//Constructor with the ID and the name.
			//Player( unsigned int newID, std::string newName, Dealer* newDealer );//Constructor with the ID, the name and the dealer.
			//size_t numHands() const;//Returns the number of hands the player currently has.
			//Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandCollection& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			//void split( size_t n );//Splits the hand at location n. Throws an exception if the hand can't be split according to the rules of blackjack. n should be between 0 and numHands()-1, inclusive.
			//void split( HandsIterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			void split( HandCollection::HandList::iterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual void play();//Virtual method for this player to play Blackjack.
			virtual int askQuit();//Rerturns an int of value from playReturnValues based on whether the user wants to quit or keep playing.
			void getRandomCard( HandCollection::HandList::iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName();//Returns the name of the player.
			void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
			long setMoney( long newMoney );//Sets the amount of money the player has and returns that amount.
			long getMoney();//Returns the amount of money the player has.
			long addMoney( long newMoney );//Adds newMoney of money to the amount the player has and returns the updated amount.
			long subtractMoney( long newMoney );//Subtracts newMoney of money from the amount the player has and returns the updated amount.
			HandCollection::HandList::iterator handsBegin();//An iterator for the beginning of the player's hands.
			HandCollection::HandList::iterator handsEnd();//An iterator for the end of the player's hands.
	};
}
*/


namespace Blackjack
{
	Player::Player( unsigned int newID )
	{//Constructor with the ID.
		//myDealer = 0;
		setID( newID );
	}

	Player::Player( unsigned int newID, std::string newName )
	{//Constructor with the ID and the name.
		//myDealer = 0;
		setID( newID );
		setName( newName );
	}
/*
	Player::Player( unsigned int newID, std::string newName, Dealer* newDealer )
	{//Constructor with the ID, the name and the dealer.
		setID( newID );
		setName( newName );
		setDealer( newDealer );
	}
*/
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

	void Player::split( HandCollection::HandList::iterator iteratorPosition )
	{//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
		if( (*iteratorPosition).canSplit() )
		{//If the hand can be split, go ahead and split it.
			Card splitCard = (*iteratorPosition).getCard(0);//Get the first card
			//Card randomCard1( static_cast<Rank>(0,12), static_cast<Suit>(0,3) );//Get a random card
			//Card randomCard2( static_cast<Rank>(0,12), static_cast<Suit>(0,3) );//Get another random card
			(*iteratorPosition).removeCard( (*iteratorPosition).getNumCards()-1 );//Remove the last card.
			//(*iteratorPosition).addCard( myDealer->getRandomCard() );//Replace the last card.
			(*iteratorPosition).addCard( getRandomCard() );//Replace the last card.

			//Create the new hand with the split card.
			Hand newHand;
			newHand.addCard( splitCard );//Put in the split card.
			//newHand.addCard( myDealer->getRandomCard() );//Put in a random card to round out the hand.
			newHand.addCard( getRandomCard() );//Put in a random card to round out the hand.
			collHands.addHand( newHand );//Add the hand to the collection.
		}
		else
		{//If the hand can't be split, give an error.
			std::cerr << "The hand can't be split." << std::endl;
		}
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
	void Player::getRandomCard( HandCollection::HandList::iterator iteratorPosition )
	{//Gets a random card for the hand pointed to by iteratorPosition.
		//Card randomCard( static_cast<Rank>(0,12), static_cast<Suit>(0,3) );//Get a random card
		(*iteratorPosition).addCard( getRandomCard() );//assign the random card.
		/*
		if( myDealer != 0 )
		{//The dealer object is not a null pointer, so it's ok to use that to get a random card.
			*iteratorPosition.addCard( myDealer->getRandomCard() );
		}
		else
		{//The dealer object is a null pointer, throw an error.
			throw std::runtime_error( "In Player::getRandomCard( iterator iteratorPosition ), the dealer isn't registered to the player. The function needs the dealer to ger a random card."
		}
		*/
	}

	void Player::setName( std::string newName )
	{//Sets the name of the player.
		name = newName;
	}

	std::string Player::getName()
	{//Returns the name of the player.
		return name;
	}
/*
	void Player::setDealer( Dealer* newDealer )
	{//Sets the name of the player.
		myDealer = newDealer;
	}
*/
	void Player::setID( unsigned int newID )
	{//Set the ID to newID.
		ID = newID;
	}

	unsigned int Player::getID()
	{//Returns the ID.
		return ID;
	}

	long Player::setMoney( long newMoney )
	{//Sets the amount of money the player has and returns that amount.
		money = newMoney;
		return money;
	}

	long Player::getMoney()
	{//Returns the amount of money the player has.
		return money;
	}

	long Player::addMoney( long newMoney )
	{//Adds newMoney of money to the amount the player has and returns the updated amount.
		money += newMoney;
		return money;
	}

	long Player::subtractMoney( long newMoney )
	{//Subtracts newMoney of money from the amount the player has and returns the updated amount.
		money -= newMoney;
		return money;
	}

	HandCollection::HandList::iterator Player::handsBegin()
	{//An iterator for the beginning of the player's hands.
		return collHands.begin();
	}

	HandCollection::HandList::iterator Player::handsEnd()
	{//An iterator for the end of the player's hands.
		return collHands.end();
	}

	Card Player::getRandomCard()
	{//Gets a random card for the hand pointed to by iteratorPosition.
		Card randomCard( static_cast<Rank>(RNG::generateNumber<int>(0,12)), static_cast<Suit>(RNG::generateNumber<int>(0,3)) );//Get a random card
		return randomCard;
	}
}
