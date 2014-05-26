#include "Dealer.h"

/*
namespace Blackjack
{
	class Dealer: public Player
	{//A Blackjack dealer.
		private:
			std::vector<Player*> players;

		public:
			Dealer();//Default Constructor.
			~Dealer();//Default Destructor. Frees all the player pointers.
			//void deal();//Deal cards to players.
			void startGame();//Starts the players playing.
			void addUserPlayer( std::string newName );//Registers a new user's player for the game. newName is the name of the new player.
			void addAutoPlayer( std::string newName );//Registers a new automatic player for the game. newName is the name of the new player.
			Card getRandomCard();//Returns a randomly valued card.
	};
}
*/
namespace Blackjack
{
	Dealer::Dealer()
	{//Default Constructor.
	}

	Dealer::~Dealer()
	{//Default Destructor. Frees all the player pointers.
	}

	void Dealer::startGame()
	{//Starts the players playing.
	}

	void Dealer::addUserPlayer( std::string newName )
	{//Registers a new user's player for the game. newName is the name of the new player.
	}

	void Dealer::addAutoPlayer( std::string newName )
	{//Registers a new automatic player for the game. newName is the name of the new player.
	}

	Card Dealer::getRandomCard()
	{//Returns a randomly valued card.
		Card randomCard( static_cast<Rank>(0,12), static_cast<Suit>(0,3) );
		return randomCard;
	}
}
