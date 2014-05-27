#ifndef Dealer_h
#define Dealer_h

#include <vector>
#include <string>
#include "Hand.h"
#include "Random-Cpp/random.cpp"

namespace Blackjack
{
	class Dealer: public Player
	{//A Blackjack dealer.
		private:
			std::vector<Player*> players;

		public:
			//Dealer();//Default Constructor.
			~Dealer();//Default Destructor. Frees all the player pointers.
			//void deal();//Deal cards to players.
			void startGame();//Starts the players playing.
			void addUserPlayer( std::string newName );//Registers a new user's player for the game. newName is the name of the new player.
			void addAutoPlayer( std::string newName );//Registers a new automatic player for the game. newName is the name of the new player.
			Card getRandomCard();//Returns a randomly valued card.
	};
}

#endif /* Dealer_h */
