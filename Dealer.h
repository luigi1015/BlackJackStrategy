#ifndef Dealer_h
#define Dealer_h

#include <vector>
#include <string>
//#include "Hand.h"
//#include "Player.h"
#include "UserPlayer.h"
#include "AutoPlayer.h"
//#include "Random-Cpp/random.cpp"

namespace Blackjack
{
	class Dealer: public Player
	{//A Blackjack dealer.
		private:
			std::vector<Player*> players;//A vector of the players. I have them stored as pointers so that it can store subclasses of Player.

		public:
			Dealer();//Default Constructor.
			~Dealer();//Default Destructor. Frees all the player pointers.
			//void deal();//Deal cards to players.
			void startGame();//Starts the players playing.
			void addUserPlayer( unsigned int newID, std::string newName );//Registers a new user's player for the game. newName and newID are the name and ID of the new player.
			void addAutoPlayer( unsigned int newID, std::string newName );//Registers a new automatic player for the game. newName and newID are the name and ID of the new player.
			//Card getRandomCard();//Returns a randomly valued card.
			Card getDealerCard();//Returns one of the dealer's card for the player to see.
			void play();//Play a hand as the dealer.
			int askQuit();//Just returns keep playing every time.
	};
}

#endif /* Dealer_h */
