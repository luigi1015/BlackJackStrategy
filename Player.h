#ifndef Player_h
#define Player_h

//#include "Hand.h"
#include "HandsIterator.h"
//#include "HandCollection.h"
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

		public:
			struct playReturnValues { quitPlaying, keepPlaying };//Return values for the play method. quitPlaying will tell the dealer that the player wants to stop while keepPlaying will tell the dealer that the player wants to continue.
			Player( unsigned int newID );//Constructor with the ID.
			//size_t numHands() const;//Returns the number of hands the player currently has.
			//Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			HandCollection& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			//void split( size_t n );//Splits the hand at location n. Throws an exception if the hand can't be split according to the rules of blackjack. n should be between 0 and numHands()-1, inclusive.
			void split( HandsIterator iteratorPosition );//Splits the hand at the location pointed to by iteratorPosition. Throws an exception if the hand can't be split according to the rules of blackjack.
			//void addHand( Hand newHand );//Add a hand to the end of the list;
			//void addHand( Hand newHand, size_t n );//Add a hand at location n. n should be between 0 and numHands()-1, inclusive.
			//void clearHands();//Remove all the hands.
			virtual int play();//Virtual method for this player to play Blackjack. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
			void getRandomCard( iterator iteratorPosition );//Gets a random card for the hand pointed to by iteratorPosition.
			void setName( std::string newName );//Sets the name of the player.
			std::string getName();//Returns the name of the player.
			void setDealer( Dealer* newDealer );//Set the dealer.
			void setID( unsigned int newID );//Set the ID to newID.
			unsigned int getID();//Returns the ID.
	};
}

#endif /* Player_h */
