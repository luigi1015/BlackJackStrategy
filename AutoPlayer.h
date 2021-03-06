#ifndef AutoPlayer_h
#define AutoPlayer_h

#include "Player.h"
#include "AutoStrategy.h"

namespace Blackjack
{
	class AutoPlayer: public Player
	{//A Blackjack player that automatically plays without user input.
		private:
			AutoStrategy *strategy;

		public:
			//AutoPlayer();//Default Constructor.
			//AutoPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name.
			AutoPlayer( unsigned int newID, std::string newName );//Constructor with the player's name and ID.
			void play();//Automatically play blackjack. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
			int askQuit();//Returns an int of value from playReturnValues based on whether the player thinks it should quit.
	};
}

#endif /* AutoPlayer_h */
