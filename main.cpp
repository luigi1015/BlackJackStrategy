#include <iostream>
#include <string>
#include <stdlib.h> 
#include "Dealer.h"

inline bool caseInsensitiveCharacterCompare( char first, char second )
{//Compare two characters, returns true if they're equal, false if they're not.
	return std::toupper(first) == std::toupper(second);
}

bool caseInsensitiveStringCompare( const std::string& first,  const std::string& second )
{
	return (first.size() == second.size()) && equal(first.begin(), first.end(), second.begin(), caseInsensitiveCharacterCompare);
}

int main()
{
	std::string input;//A temporary holder of user input.
	unsigned int maxUsedPlayerID = 0;//The highest player ID used so far.
	Blackjack::Dealer dealer;

	//Ask about the user player and create one if neccesary.
	do
	{//Keep asking for input until you get a valid answer.
		std::cout << "Do you want to play in the game (either way, you can have computer players)? (Y/N) ";
		std::cin >> input;
		if( caseInsensitiveStringCompare(input, "Y") )
		{//If the user entered Y for yes, get a name and add a UserPlayer to the dealer.
			std::string playerName;
			std::cout << "What name do you want to go by? ";
			std::cin >> playerName;
			dealer.addUserPlayer( ++maxUsedPlayerID, playerName );
		}
		else if( caseInsensitiveStringCompare(input, "N") )
		{//If the user entered N for no, don't add a UserPlayer.
			std::cout << "You will not play this game." << std::endl;
		}
		else
		{//Invalid response. Give an error.
			std::cerr << "Your answer on whether to play wasn't recognized, please try again." << std::endl;
		}
	}while( !caseInsensitiveStringCompare(input, "Y") && !caseInsensitiveStringCompare(input, "N") );

	//Ask about the computer players and add one or more if neccesary.
	int numComputerPlayers = 0;
	int maxComputerPlayers = 100;
	do
	{//Keep asking for input until you get a valid answer.
		std::cout << "How many computer players do you want? (Enter 0 for none) ";
		std::cin >> input;
		numComputerPlayers = atoi( input.c_str() );

		if( (numComputerPlayers > 0) && (numComputerPlayers <= maxComputerPlayers) )
		{//If the user entered a valid number, get names and aAutoPlayers to the dealer.
			for( int i = 1; i <= numComputerPlayers; i++ )
			{
				std::string playerName;
				std::cout << "What name do you want computer player " << i << " to go by? ";
				std::cin >> playerName;
				dealer.addAutoPlayer( ++maxUsedPlayerID, playerName );
			}
		}
		else if( numComputerPlayers == 0 )
		{//If the user entered 0, don't add any AutoPlayers.
			std::cout << "There will be no computer players this game." << std::endl;
		}
		else
		{//Invalid response. Give an error.
			std::cerr << "Your answer wasn't recognized or wasn't between 0 and " << maxComputerPlayers << ", please try again." << std::endl;
		}
	}while( (numComputerPlayers < 0) || (numComputerPlayers > maxComputerPlayers) );
	
	//Start the game!
	dealer.startGame();
}
