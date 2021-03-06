/*
namespace Blackjack
{
	class AutoPlayer: public Player
	{//A Blackjack player that automatically plays without user input.
		private:
			AutoStrategy *strategy;

		public:
			//AutoPlayer();//Default Constructor.
			//AutoPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name.
			AutoPlayer( unsigned int newID, std::string newName ) : Player( newID, newName );//Constructor with the player's name and ID.
			void play();//Automatically play blackjack.
			int askQuit();//Returns an int of value from playReturnValues based on whether the player thinks it should quit.
	};
}
*/

#include "AutoPlayer.h"
#include "InternetRecommendedStrategy.h"
#include <iostream>

namespace Blackjack
{
	AutoPlayer::AutoPlayer( unsigned int newID, std::string newName ) : Player( newID, newName )
	{//Constructor with the player's name and ID.
		strategy = new InternetRecommendedStrategy();
	}

	void AutoPlayer::play()
	{//Automatically play blackjack.
		//std::cerr << "AutoPlayer is still being written." << std::endl;
		
		if( getMoney() > 0 )
		{//If the user has money left, let the user play.

			if( collHands.numHands()  == 0 )
			{//If there aren't any hands yet, create the first one so that play can start.
				Hand newHand;//Create the hand object itself.
				newHand.addCard( getRandomCard() );//Get the first random card of the hand.
				newHand.addCard( getRandomCard() );//Get the second random card of the hand.
				collHands.addHand( newHand );//Add the new hand to the collection of hands.
			}

			//HandCollection::HandList::iterator itr = collHands.begin();
			//for( HandCollection::HandList::iterator itr = collHands.begin(); itr != collHands.end(); itr++ )
			//for( size_t i = 0; i < collHands.numHands(); i++ )
			size_t i = 0;
			do
			{//Play each hand by iteration through them.
				bool doneWithThisHand = false;//Used to keep track of wether the user has decided to stop playing this hand.

				//Print out the hand at the beginning of play
				printHand( i );
				/*
				std::cout << "This hand: " << std::endl;
				//std::cout << *itr << std::endl;//Print out the hand to the user.
				//std::cout << "Points: " << (*itr).getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
				std::cout << collHands.getHand(i) << std::endl;//Print out the hand to the user.
				std::cout << "Points: " << collHands.getHand(i).getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
				*/

				//For now, just set a standard bet.
				//(*itr).setBet( 5 );
				collHands.getHand(i).setBet( 5 );
				//std::cout << "Betting " << (*itr).getBet() << std::endl;
				std::cout << "Betting " << collHands.getHand(i).getBet() << std::endl;

				//while( (doneWithThisHand == false) && ((*itr).getMaxPointsAtOrBelow21() < 21) )
				while( (doneWithThisHand == false) && !(collHands.getHand(i).isBust()) )
				{//Continue on until the player decides to stop or 21+ has been reached.
					//Get the decision from the strategy.
					//int decision = strategy->decide( dealerCard, *itr );
					int decision = strategy->decide( dealerCard, collHands.getHand(i) );
					
					switch( decision )
					{//Run the decision decided by the strategy.
						case AutoStrategy::Hit://Hit
							std::cout << "Hit" << std::endl;
							//(*itr).addCard( getRandomCard() );//Put in a random card.
							collHands.getHand(i).addCard( getRandomCard() );//Put in a random card.
					
							//If this hand is a bust, go to the next hand.
							if( collHands.getHand(i).isBust() )
							{
								i++;
							}
							break;

						case AutoStrategy::Stand://Stand
							std::cout << "Stand" << std::endl;
							doneWithThisHand = true;
							//itr++;//Go to the next hand.
							i++;//Go to the next hand.
							break;

						case AutoStrategy::DoubleDown://Double Down
							//if( (*itr).getBet() * 2 <= getMoney() )
							if( collHands.getHand(i).getBet() * 2 <= getMoney() )
							{//If the player has enough money for a double down, double down.
								std::cout << "Double Down" << std::endl;
								//(*itr).doubleBet();
								//(*itr).addCard( getRandomCard() );//Put in a random card.
								collHands.getHand(i).doubleBet();
								collHands.getHand(i).addCard( getRandomCard() );//Put in a random card.
								doneWithThisHand = true;
								//itr++;//Go to the next hand.
								i++;//Go to the next hand.
							}
							else
							{//If the player doesn't have enough money for a double down, just do a hit.
								std::cout << "Tried to do a double down, but don't have anough money, hitting." << std::endl;
								collHands.getHand(i).addCard( getRandomCard() );//Put in a random card.
							}
							break;

						case AutoStrategy::Split://Split
							std::cout << "Split" << std::endl;
							//itr = split( itr );
							//split( itr );
							split( collHands.begin()+i );
							break;

					}

				}
			}while( i < collHands.numHands() );
		}
		else
		{//The user doesn't have any money left. Let the user know.
			std::cout << "You have " << getMoney() << " money left. You can't play with that amount." << std::endl;
		}
	}

	int AutoPlayer::askQuit()
	{//Returns an int of value from playReturnValues based on whether the player thinks it should quit.
		//std::cerr << "AutoPlayer is still being written." << std::endl;
		//return Player::quitPlaying;
		if( money > 0 )
		{//If you still have money, keep playing.
			std::cout << "Still have " << getMoney() << " money left. I'll keep playing." << std::endl;
			return Player::keepPlaying;
		}
		else
		{//If you've ran out of money, quit.
			std::cout << "Out of money, I quit." << std::endl;
			return Player::quitPlaying;
		}
	}
}
