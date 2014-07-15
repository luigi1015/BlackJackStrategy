#ifndef UserPlayer_h
#define UserPlayer_h

//#include "Hand.h"
#include "Player.h"

namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer( unsigned int newID );//Constructor with only the ID.
			UserPlayer( unsigned int newID, std::string newName );//Constructor with the player's name and the ID.
			//UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer );//Constructor with the player's name, the ID and the Dealer.
			void play();//Play one round of blackjack with user input. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
			int askQuit();//Asks the user whether to quit and returns an int of value from playReturnValues based on the answer.
	};
}

#endif /* UserPlayer_h */
