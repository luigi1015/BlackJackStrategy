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
			void play();//Play a hand as the dealer.
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
		while( players.size() > 0 )
		{
			std::vector<Player*>::iterator pit

			for( pit = players.begin(); pit != players.end(); pit++ )
			{//Go through the players and have each them play a hand.
				(*pit)->play();
			}

			//Play a hand as the dealer.
			play();

			pit = players.begin();
			while( pit != players.end() )
			{//Go through the players and count up the winnings/losses and ask each if they want to quit.
				
				std::cout << "Winnings and losses to be programmed later..." << std::endl;
				//TODO: finish the calculations of winnings and losses.
				
				if( (*pit)->askQuit() == playReturnValues.quitPlaying )
				{//Ask if the player wants to quit.
					pit = players.erase( pit );//Erase the plaer and get the new iterator.
				}
				else
				{//The player didn't want to quit, so just move on.
					pit++;
				}
			}
		}
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

	void Dealer::play()
	{//Play a hand as the dealer.
		if( collHands.numHands()  == 0 )
		{//If there aren't any hands yet, create the first one so that play can start.
			Hand newHand;//Create the hand object itself.
			newHand.addCard( myDealer->getRandomCard() );//Get the first random card of the hand.
			newHand.addCard( myDealer->getRandomCard() );//Get the second random card of the hand.
			collHands.addHand( newHand );//Add the new hand to the collection of hands.
		}
			
		for( HandList::iterator itr = collHands.begin(); itr != collHands.end(); itr++ )
		{//Play each hand by iteration through them.
			bool doneWithThisHand = false;//Used to keep track of wether the dealer has decided to stop playing this hand.
				
			while( (doneWithThisHand != true) && (*itr.getMaxPointsAtOrBelow21() < 21) )
			{//While the dealer hasn't decided to stop playing this hand and the hand is below 21 points, keep playing this hand.
				std::cout << "Dealer's hand: " << *itr << std::endl;//Print out the hand.
				std::cout << "Dealer's points: " << *itr.getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points.

				if( *itr.getMaxPointsAtOrBelow21() < 17 )
				{//If the points for this hand are below 17, hit.
					(*itr).addCard( myDealer->getRandomCard() );//Put in a random card.
				}
				else
				{//The dealer wants to stand, so done with this hand.
					doneWithThisHand = true;
				}
			}
				
			//Print out the hand at the end of the play
			std::cout << "Dealer's hand: " << std::endl;
			std::cout << *itr << std::endl;//Print out the hand.
			std::cout << "Dealer's points: " << (*itr).getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points.
		}
	}

	int Dealer::askQuit()
	{//Just returns keep playing every time.
		return playReturnValues.keepPlaying;
	}
}
