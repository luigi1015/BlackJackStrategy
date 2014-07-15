#include "UserPlayer.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>//For equal method to compare characters/strings.
#include <cctype>//For toupper method.
#include <stdlib.h>//For strtol

/*
namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer( unsigned int newID ) : Player( newID );//Constructor with only the ID.
			UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName );//Constructor with the player's name and the ID.
			//UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name, the ID and the Dealer.
			void play();//Play one round of blackjack with user input.
			int askQuit();//Asks the user whether to quit and returns an int of value from playReturnValues based on the answer.
	};
}
*/

namespace Blackjack
{
	inline bool caseInsensitiveCharacterCompare( char first, char second )
	{//Compare two characters, returns true if they're equal, false if they're not.
		return std::toupper(first) == std::toupper(second);
	}

	bool caseInsensitiveStringCompare( const std::string& first,  const std::string& second )
	{
		return (first.size() == second.size()) && equal(first.begin(), first.end(), second.begin(), caseInsensitiveCharacterCompare);
	}

	UserPlayer::UserPlayer( unsigned int newID ) : Player( newID )
	{//Constructor with only the ID.
	}

	UserPlayer::UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName )
	{//Constructor with the player's name and the ID.
	}
/*
	UserPlayer::UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer )
	{//Constructor with the player's name, the ID and the Dealer.
	}
*/
	void UserPlayer::play()
	{//Play one round of blackjack with user input.
		if( myDealer == NULL )
		{//Check to make sure the dealer is set. If not, error out.
			std::cerr << "Started the play method of UserPlayer without a set dealer." << std::endl;
			throw std::runtime_error( "Started the play method of UserPlayer without a set dealer." );
		}

		if( getMoney() > 0 )
		{//If the user has money left, let the user play.
			//long bet = 0;//The amount of money the user wants to bet.

			if( collHands.numHands()  == 0 )
			{//If there aren't any hands yet, create the first one so that play can start.
				Hand newHand;//Create the hand object itself.
				newHand.addCard( myDealer->getRandomCard() );//Get the first random card of the hand.
				newHand.addCard( myDealer->getRandomCard() );//Get the second random card of the hand.
				collHands.addHand( newHand );//Add the new hand to the collection of hands.
			}
			
			for( HandList::iterator itr = collHands.begin(); itr != collHands.end(); itr++ )
			{//Play each hand by iteration through them.
				bool doneWithThisHand = false;//Used to keep track of wether the user has decided to stop playing this hand.
				//bet = 0;//Reset the bet.

				while( ((*itr).getBet() <= 0) || ((*itr).getBet() > getMoney()) )
				{//Keep asking for a bet until you get a valid one (bet needs to be a positive number less than or equal to the amount of money the player has.
					long tempBet;//Temporary variable to hold the value of the bet temporarily.
					std::cout << "You have " << getMoney() << " money left. How much do you want to bet? ";
					std::cin >> input;
					tempBet = strtol( input.c_str(), NULL, 0 );

					if( (tempBet <= 0) || (tempBet > getMoney()) )
					{//The bet was invalid, give an error.
						std::cerr << "The bet you entered, " << tempBet << ", was invalid, please try again with a number between 1 and " << getMoney() << "." << std::endl;
					}
					else
					{//The bet is valid, set the bet and take the bet out of the player's money..
						(*itr).setBet( tempBet );
						money -= tempBet;
					}
				}

				//Double Down
				if( (*itr).getBet() * 2 <= getMoney() )
				{//If the player has enough money, let the player double down.
					std::string doubleDownInput;
					do
					{//Keep looping until get a y or a n from the user.
						std::cout << *itr << std::endl;//Print out the hand to the user.
						std::cout << "Points: " << *itr.getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
						std::cout << "Money: " << getMoney() << std::endl;//Print out the amount of money the user has.
						std::cout << "Do you want to double down? (y/n) ";
						std::cin >> doubleDownInput;

						if( caseInsensitiveStringCompare(doubleDownInput, "Y") )
						{//If the user said yes, double down and take the additional bet amount out of the player's money.
							//bet *= 2;
							money -= (*itr).getBet();
							(*itr).doubleBet();
							doneWithThisHand = true;
						}
						else if( !caseInsensitiveStringCompare(doubleDownInput, "N") )
						{//If the user didn't specify yes (previous if statement) or no (this if statement), give the user an error.
							std::cerr << "Please input the character y or the character n." << std::endl;
						}
					}while( !caseInsensitiveStringCompare(splitInput, "Y") && !caseInsensitiveStringCompare(splitInput, "N") );
				}
				else
				{//Let the user know the user can't souble down.
					std::cout << "You don't have enough money to double down." << std::endl;
				}

				//Split
				if( (*itr).canSplit() )
				{//If the hand can be split, ask the user wether to do that.
					std::string splitInput;
					do
					{//Keep looping until get a y or a n from the user.
						std::cout << *itr << std::endl;//Print out the hand to the user.
						std::cout << "Points: " << *itr.getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
						std::cout << "This hand can be split. Do you want to split the hand? (y/n) ";
						std::cin >> splitInput;

						if( caseInsensitiveStringCompare(splitInput, "Y") )
						{//If the user said yes, split the hand.
							//Finish this code later
							//std::cout << "This feature is still under construction." << std::endl;
							split( itr );
						}
						else if( !caseInsensitiveStringCompare(splitInput, "N") )
						{//If the user didn't specify yes (previous if statement) or no (this if statement), give the user an error.
							std::cerr << "Please input the character y or the character n." << std::endl;
						}
					}while( !caseInsensitiveStringCompare(splitInput, "Y") && !caseInsensitiveStringCompare(splitInput, "N") );
				}
					
				while( (doneWithThisHand != true) && (*itr.getMaxPointsAtOrBelow21() < 21) )
				{//While  the user hasn't decided to stop playing this hand and the hand is below 21 points, keep playing this hand.
					std::cout << *itr << std::endl;//Print out the hand to the user.
					std::cout << "Points: " << *itr.getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.

					//if( *itr.getMaxPointsAtOrBelow21() < 21 )
					//{//If the points for this hand are below 21, see if the user wants to keep going.

					//Ask if the user wants to deal another card.
					std::string dealInput;
					do
					{//Keep looping until get a y or a n from the user.
						std::cout << *itr << std::endl;
						std::cout << "Do you want to hit or stand? (h/s) ";
						std::cin >> dealInput;

						if( caseInsensitiveStringCompare(dealInput, "h") )
						{//If the user said yes, deal a card.
							//Finish this code later
							//std::cout << "This feature is still under construction." << std::endl;
							(*itr).addCard( myDealer->getRandomCard() );//Put in a random card.
						}
						else if( caseInsensitiveStringCompare(dealInput, "s") )
						{//User selected stand, so done with this hand.
							doneWithThisHand = true;
						}
						else
						{//If the user didn't specify hit or stand, give the user an error.
							std::cerr << "Please input the character y or the character n." << std::endl;
						}
					}while( !caseInsensitiveStringCompare(dealInput, "h") && !caseInsensitiveStringCompare(dealInput, "s") );
					//}
				}
				
				//Print out the hand at the end of the play
				std::cout << "This hand: " << std::endl;
				std::cout << *itr << std::endl;//Print out the hand to the user.
				std::cout << "Points: " << (*itr).getMaxPointsAtOrBelow21() << std::endl;//Print out the number of points for the user.
			}
		}
		else
		{//The user doesn't have any money left. Let the user know.
			std::cout << "You have " << getMoney() << " money left. You can't play with that amount." << std::endl;
		}
	}

	int UserPlayer::askQuit()
	{//Asks the user whether to quit and returns an int of value from playReturnValues based on the answer.
		std::string input;
		do
		{//Keep asking for input until you get a valid answer.
			std::cout << "You have " << getMoney() << " money left. Do you want to quit? (Y/N) ";
			std::cin >> input;
			if( caseInsensitiveStringCompare(input, "Y") )
			{//If the user entered Y for yes, return quitPlaying
				return playReturnValues.quitPlaying;
			}
			else if( caseInsensitiveStringCompare(input, "N") )
			{//If the user entered N for no, return keepPlaying
				return playReturnValues.keepPlaying;
			}
			else
			{//Invalid response. Give an error.
				std::cerr << "Your answer on whether to quit wasn't recognized, please try again." << std::endl;
			}
		}while( caseInsensitiveStringCompare(input, "Y") || caseInsensitiveStringCompare(input, "N") );
		
		//Execution shouldn't get here, but in case the compiler will complian about the possibility of ending the method without a return value I'll put a default.
		std::cerr << "Something unexpected happened in UserPlayer::askQuit(), quitting." << std::endl;
		return playReturnValues.quitPlaying;
	}
}
