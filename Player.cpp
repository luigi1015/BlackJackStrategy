#include "Player.h"
#include <stdexcept>
#include <iostream>
#include "Random-Cpp/random.cpp"

/*
namespace Blackjack
{
	class Player
	{//A Blackjack player.
		protected:
			//std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.
			HandCollection collHands;
			std::string name;
			//Dealer* myDealer;//The dealer for this game.
			unsigned int ID;//The programatically generated ID of the payer.
			long money;//How much money the player has.
			Card dealerCard;//The dealer's card.

		public:
			enum playReturnValues { quitPlaying, keepPlaying };//Return values for the play method. quitPlaying will tell the dealer that the player wants to stop while keepPlaying will tell the dealer that the player wants to continue.
			Player();//Default Constructor.
			Player( unsigned int newID );//Constructor with the ID.
			Player( unsigned int newID, std::string newName );//Constructor with the ID and the name.
			virtual ~Player();//Default destructor
			//Player( unsigned int newID, std::string newName, Dealer* newDealer );//Constructor with the ID, the name and the dealer.
			//size_t numHands() const;//Returns the number of hands the player currently has.
			//Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandCollection& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			//void split( size_t n );//Splits the hand at location n. Throws an exception if the hand can't be split according to the rules of blackjack. n should be between 0 and numHands()-1, inclusive.
			//void split( HandsIterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			HandCollection::HandList::iterator split( HandCollection::HandList::iterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual void play();//Virtual method for this player to play Blackjack.
			virtual int askQuit();//Rerturns an int of value from playReturnValues based on whether the user wants to quit or keep playing.
			void getRandomCard( HandCollection::HandList::iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName() const;//Returns the name of the player.
			//void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
			long setMoney( long newMoney );//Sets the amount of money the player has and returns that amount.
			long getMoney() const;//Returns the amount of money the player has.
			long addMoney( long newMoney );//Adds newMoney of money to the amount the player has and returns the updated amount.
			long subtractMoney( long newMoney );//Subtracts newMoney of money from the amount the player has and returns the updated amount.
			HandCollection::HandList::iterator handsBegin();//An iterator for the beginning of the player's hands.
			HandCollection::HandList::iterator handsEnd();//An iterator for the end of the player's hands.
			Card getRandomCard() const;//Returns a randomly valued card.
			void clearHands();//Clear the player's hands.
			void setDealerCard( Card dealerCard );//Set the dealer's card to show to the player.
			Card Player::getDealerCard() const;//Return's the dealer's card that the player has on record.
			void printHand( size_t i ) const;//Print hand at location i.
	};
}
*/


namespace Blackjack
{
	Player::Player()
	{//Default Constructor.
		setID( 0 );
	}

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

	Player::~Player()
	{//Default destructor
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

	HandCollection::HandList::iterator Player::split( HandCollection::HandList::iterator iteratorPosition )
	{//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
		if( (*iteratorPosition).canSplit() )
		{//If the hand can be split, go ahead and split it.
			Card splitCard = (*iteratorPosition).getCard(1);//Get the second/last card
			(*iteratorPosition).removeCard( (*iteratorPosition).getNumCards()-1 );//Remove the last card.
			(*iteratorPosition).addCard( getRandomCard() );//Replace the last card.

			//Create the new hand with the split card.
			Hand newHand;
			newHand.addCard( splitCard );//Put in the split card.
			newHand.addCard( getRandomCard() );//Put in a random card to round out the hand.
			collHands.addHand( newHand );//Add the hand to the collection.

			//Return an iterator to the beginning of the hand so that it'll have a valid iterator.
			return collHands.begin();
		}
		else
		{//If the hand can't be split, give an error.
			std::cerr << "The hand can't be split." << std::endl;
			//Return the parameter iterator since the hand collection and therefore the iterator haven't changed.
			return iteratorPosition;
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

	std::string Player::getName()  const
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

	unsigned int Player::getID() const
	{//Returns the ID.
		return ID;
	}

	long Player::setMoney( long newMoney )
	{//Sets the amount of money the player has and returns that amount.
		money = newMoney;
		return money;
	}

	long Player::getMoney() const
	{//Returns the amount of money the player has.
		return money;
	}

	long Player::addMoney( long newMoney )
	{//Adds newMoney of money to the amount the player has and returns the updated amount.
		std::cout << "Adding " << newMoney << " to player's money." << std::endl;
		money += newMoney;
		std::cout << "Player now has " << money << " money." << std::endl;
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

	Card Player::getRandomCard() const
	{//Gets a random card for the hand pointed to by iteratorPosition.
		//std::cout << "Generating random card: " << std::endl;
		int randomRank = RNG::generateNumber<int>(0,12);
		//std::cout << "Rank(# between 0 and 12): " << randomRank << std::endl;
		int randomSuit = RNG::generateNumber<int>(0,3);
		//std::cout << "Suit(# between 0 and 3): " << randomSuit << std::endl;
		Card randomCard( static_cast<Rank>(randomRank), static_cast<Suit>(randomSuit) );//Get a random card
		return randomCard;
	}

	void Player::play()
	{//Virtual method for this player to play Blackjack.
	}

	int Player::askQuit()
	{//Rerturns an int of value from playReturnValues based on whether the user wants to quit or keep playing.
		return quitPlaying;
	}

	void Player::clearHands()
	{//Clear the player's hands.
		collHands.clearHands();
	}

	void Player::setDealerCard( Card newDealerCard )
	{//Set the dealer's card to show to the player.
		dealerCard = newDealerCard;
	}

	Card Player::getDealerCard() const
	{//Return's the dealer's card that the player has on record.
		return dealerCard;
	}

	void Player::printHand( size_t i ) const
	{//Print hand at location i.
		std::cout << "This hand: " << std::endl;
		std::cout << collHands.getHand(i) << std::endl;//Print out the hand to the user.
		std::cout << "Points: " << collHands.getHand(i).getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
	}
}
