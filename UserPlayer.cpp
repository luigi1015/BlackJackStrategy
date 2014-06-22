#include UserPlayer.h
#include <stdexcept>
#include <iostream>
#include <string>

/*
namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer( unsigned int newID ) : Player( newID );//Constructor with only the ID.
			UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName );//Constructor with the player's name and the ID.
			UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name, the ID and the Dealer.
			int play();//Play blackjack with user input. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
	};
}
*/

namespace Blackjack
{
	UserPlayer::UserPlayer( unsigned int newID ) : Player( newID )
	{//Constructor with only the ID.
	}

	UserPlayer::UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName )
	{//Constructor with the player's name and the ID.
	}

	UserPlayer::UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer )
	{//Constructor with the player's name, the ID and the Dealer.
	}

	int UserPlayer::play()
	{//Play blackjack with user input.
		if( myDealer == NULL )
		{//Check to make sure the dealer is set. If not, error out.
			std::cerr << "Started the play method of UserPlayer without a set dealer." << std::endl;
			throw std::runtime_error( "Started the play method of UserPlayer without a set dealer." );
		}
		
		if( collHands.numHands()  == 0 )
		{//If there aren't any hands yet, create the first one so that play can start.
			Hand newHand;//Create the hand object itself.
			newHand.addCard( myDealer->getRandomCard() );//Get the first random card of the hand.
			newHand.addCard( myDealer->getRandomCard() );//Get the second random card of the hand.
			collHands.addHand( newHand );//Add the new hand to the collection of hands.
		}
		
		for( HandList::iterator itr = collHands.begin(); itr != collHands.end(); itr++ )
		{//Play each hand by iteration through them.
			bool doneWithThisHand = false;//USed to keep track of wether the user has decided to stop playing this hand.

			while( (doneWithThisHand != true) && (*itr.getMaxPointsAtOrBelow21() < 21) )
			{//While  the user hasn't decided to stop playing this hand and the hand is below 21 points, keep playing this hand.
				std::cout << *itr << std::endl;//Print out the hand to the user.
				std::cout << *itr.getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
				
				if( *itr.canSplit() )
				{//If the hand can be split, ask the user wether to do that.
					std::string splitInput;
					while( (splitInput.compare("Y") != 0) && (splitInput.compare("y") != 0) && (splitInput.compare("N") != 0) && (splitInput.compare("n") != 0) )
					{//Keep looping until get a y or a n from the user.
						std::cout << "This hand can be split. Do you want to split the hand? (y/n) ";
						std::cin >> splitInput;
						
						if( (splitInput.compare("Y") == 0) || (splitInput.compare("y") == 0) )
						{//If the user said yes, split the hand.
							//Finish this code later
							std::cout << "This feature is still under construction." << std::endl;
						}
						else if( (splitInput.compare("N") != 0) && (splitInput.compare("n") != 0) )
						{//If the user didn't specify yes (previous if statement) or no (this if statement), give the user an error.
							std::cerr << "Please input the character y or the character n." << std::endl;
						}
					}
				}
				else
				{//If the hand can't be split, ask the user wether to deal a new card.
					std::string dealInput;
					while( (dealInput.compare("Y") != 0) && (dealInput.compare("y") != 0) && (dealInput.compare("N") != 0) && (dealInput.compare("n") != 0) )
					{//Keep looping until get a y or a n from the user.
						std::cout << "This hand can be split. Do you want to split the hand? (y/n) ";
						std::cin >> dealInput;
							
						if( (dealInput.compare("Y") == 0) || (dealInput.compare("y") == 0) )
						{//If the user said yes, deal a card.
							//Finish this code later
							std::cout << "This feature is still under construction." << std::endl;
						}
						else if( (dealInput.compare("N") != 0) && (dealInput.compare("n") != 0) )
						{//If the user didn't specify yes (previous if statement) or no (this if statement), give the user an error.
							std::cerr << "Please input the character y or the character n." << std::endl;
						}
					}
				}
			}
		}
	}
}
