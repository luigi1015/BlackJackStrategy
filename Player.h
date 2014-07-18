#ifndef Player_h
#define Player_h

//#include "Hand.h"
//#include "HandsIterator.h"
#include "HandCollection.h"
//#include "Dealer.h"
//#include <vector>
#include <string>
//#include "Random-Cpp/random.cpp"

class Dealer;//To avoid having to include Dealer.h, possibly causing an include loop.

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
			void split( HandCollection::HandList::iterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual void play();//Virtual method for this player to play Blackjack.
			virtual int askQuit();//Rerturns an int of value from playReturnValues based on whether the user wants to quit or keep playing.
			void getRandomCard( HandCollection::HandList::iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName();//Returns the name of the player.
			//void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
			long setMoney( long newMoney );//Sets the amount of money the player has and returns that amount.
			long getMoney();//Returns the amount of money the player has.
			long addMoney( long newMoney );//Adds newMoney of money to the amount the player has and returns the updated amount.
			long subtractMoney( long newMoney );//Subtracts newMoney of money from the amount the player has and returns the updated amount.
			HandCollection::HandList::iterator handsBegin();//An iterator for the beginning of the player's hands.
			HandCollection::HandList::iterator handsEnd();//An iterator for the end of the player's hands.
			Card getRandomCard();//Returns a randomly valued card.
			void clearHands();//Clear the player's hands.
	};
}

#endif /* Player_h */
