#include "Dealer.h"

/*
namespace Blackjack
{
	class Dealer: public Player
	{//A Blackjack dealer.
		private:
			std::vector<Player*> players;//A vector of the players. I have them stored as pointers so that it can store subclasses of Player.

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
*/
namespace Blackjack
{
	Dealer::Dealer()
	{//Default Constructor.
		//Create a new hand.
		Hand newHand;//Create the hand object itself.
		newHand.addCard( myDealer->getRandomCard() );//Get the first random card of the hand.
		newHand.addCard( myDealer->getRandomCard() );//Get the second random card of the hand.
		collHands.addHand( newHand );//Add the new hand to the collection of hands.
	}

	Dealer::~Dealer()
	{//Default Destructor. Frees all the player pointers.
		for( std::vector<Player*>::iterator i = players.begin(); i != players.end(); i++ )
		{//Iterate through each element in the players vector and delete each one.
			delete *i;
		}

		players.clear();//Remove all the deleted pointers from the players vector.
	}

	void Dealer::startGame()
	{//Starts the players playing.
	}

	void Dealer::addUserPlayer( std::string newName )
	{//Registers a new user's player for the game. newName is the name of the new player.
		players.push_back( new UserPlayer(newName) );
	}

	void Dealer::addAutoPlayer( std::string newName )
	{//Registers a new automatic player for the game. newName is the name of the new player.
		players.push_back( new AutoPlayer(newName) );
	}

	Card Dealer::getRandomCard()
	{//Returns a randomly valued card.
		Card randomCard( static_cast<Rank>(0,12), static_cast<Suit>(0,3) );
		return randomCard;
	}

	Card Dealer::getDealerCard()
	{//Returns one of the dealer's card for the player to see.
		return (*collHands.begin()).getCard(1);//Return the first card of the first hand.
	}
}
