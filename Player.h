#ifndef Player_h
#define Player_h

//#include "Hand.h"
//#include "HandsIterator.h"
#include "HandCollection.h"
//#include <vector>
#include <string>

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
			long money;//How much money the player has.

		public:
			struct playReturnValues { quitPlaying, keepPlaying };//Return values for the play method. quitPlaying will tell the dealer that the player wants to stop while keepPlaying will tell the dealer that the player wants to continue.
			Player( unsigned int newID );//Constructor with the ID.
			Player( unsigned int newID, std::string newName );//Constructor with the ID and the name.
			Player( unsigned int newID, std::string newName, Dealer* newDealer );//Constructor with the ID, the name and the dealer.
			//size_t numHands() const;//Returns the number of hands the player currently has.
			//Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandCollection& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			//void split( size_t n );//Splits the hand at location n. Throws an exception if the hand can't be split according to the rules of blackjack. n should be between 0 and numHands()-1, inclusive.
			//void split( HandsIterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			void split( HandList::iterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual void play();//Virtual method for this player to play Blackjack.
			virtual int askQuit();//Rerturns an int of value from playReturnValues based on whether the user wants to quit or keep playing.
			void getRandomCard( iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName();//Returns the name of the player.
			void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
			long setMoney( long newMoney );//Sets the amount of money the player has and returns that amount.
			long getMoney();//Returns the amount of money the player has.
			long addMoney( long newMoney );//Adds newMoney of money to the amount the player has and returns the updated amount.
			long subtractMoney( long newMoney );//Subtracts newMoney of money from the amount the player has and returns the updated amount.
			HandList::iterator Player::handsBegin();//An iterator for the beginning of the player's hands.
			HandList::iterator Player::handsEnd();//An iterator for the end of the player's hands.
	};
}

#endif /* Player_h */
