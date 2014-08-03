#include <iostream>
#include <fstream>
#include <sstream>
//#include <vector>
#include "InternetRecommendedStrategy.h"

/*
namespace Blackjack
{
	class InternetRecommendedStrategy
	{//A Blackjack strategy from the internet.
		private:
			std::map<std::pair<std::string, Card::Rank>, Autoplayer::Decision> recommendations;//A map of the different decisions based on the player's hand and the dealer's first card. The pair holds both the player's hand value, the string, and the dealer's first card, the Rank. The string can just be a number, indicating a hand of that value that's not soft, "Soft ##" which indicates a soft hand of that value, or "Pair X" which indicates a pair of that card rank (2-9 just use their number, 10 and face cards use "10", Ace use "A").
			std::vector<std::string> parseLine( std::string line, std::string delim );//Parse line into tokens separated by delim and return the tokens in a vector.

		public:
			int decide( Card dealerCard, Hand playerHand );//Takes the dealer's card, the player's cards, decide what to do, and return the appropriate Decision value.
			void readRecommendations( std::string = "InternetStrategyTable.csv" );//Reads the recommendations from the csv file and populates the recommendations map object accordingly.
	};
}
*/

namespace Blackjack
{
	int InternetRecommendedStrategy::decide( Card dealerCard, Hand playerHand )
	{//Takes the dealer's card, the player's cards, decide what to do from the recommendations file, and return the appropriate Decision value.
		std::string handString;//The player's hand as a string, used for looking up the recommendation in the map.
		//Rank dealerRank;//The rank of the dealer's card, used for looking up the recommendation in the map.
		std::pair<std::string, Rank> mapKey;//The pair to use as a key for the map.

		readRecommendations();//Read the recommendations from the file.
		
		//Get the rank to look up.
		if( (dealerCard.getRank() == Jack) || (dealerCard.getRank() == Queen) || (dealerCard.getRank() == King) )
		{//If the card is a face card, use rank 10.
			mapKey.second = Ten;
		}
		else
		{//If the card isn't a facecard, jst use the card's rank.
			mapKey.second = dealerCard.getRank();
		}
		
		//Get the hand string
		if( playerHand.isPair() )
		{//Put the hand string as "Pair x" where x is the rank of one of the cards.
			if( (playerHand.getCard(0).getRank() == Jack) || (playerHand.getCard(0).getRank() == Queen) || (playerHand.getCard(0).getRank() == King) )
			{//If the card is a face card, use rank 10.
				handString = "Pair 10";
			}
			else if( playerHand.getCard(0).getRank() == Ace )
			{//If the card is an ace, use rank A.
				handString = "Pair A";
			}
			else
			{
				handString = "Pair " + playerHand.getCard(0).getRank();
			}
		}
		else if( playerHand.isSoft() )
		{//Put the hand string as "Soft x" where x is the number of points.
			handString = "Soft " + playerHand.getMaxPointsAtOrBelow21();
		}
		else
		{//The hand is neither a pair or soft, so the string needs to be the total.
			handString = "" + playerHand.getMaxPointsAtOrBelow21();
		}
		//Set the hand
		mapKey.first = handString;
		
		//Use the pair to get the recommendation from the map and return it.
		try
		{
			return recommendations.at( mapKey );
		}
		catch(...)
		{
			//Threw exception, probably because the key wasn't there. This would be expected, so probably nothing needed here.
		}
		
		return AutoStrategy::Stand;//Default recommendation to return.
	}

	void InternetRecommendedStrategy::readRecommendations( std::string recommendationsFilename )
	{//Reads the recommendations from the csv file and populates the recommendations map object accordingly.
		std::ifstream recommendationsFile( recommendationsFilename.c_str() );
		std::string recString;
		std::string delim = ",";//The delimiter of the file.
		
		if( recommendationsFile.is_open() )
		{//If the file opened, read from it.
			std::cout << "Opening file " << recommendationsFilename << std::endl;

			while( std::getline( recommendationsFile, recString ) )
			{
				//std::stringstream lineStream( recString );//A stream of the line to put into getline for splitting the line token by token.
				//std::string tok;//A holder for the token.
				std::string handValue;//The user's hand's value.
				std::vector<std::string> tokens;//To hold all the tokens once the line has been split.
				//Rank rank;
				std::pair<std::string, Rank> recPair;//The pair to put in the map.

				std::cout << recString << std::endl;

				tokens = parseLine( recString, delim );//Go ahead and split the line.

				handValue = tokens.at(0);

				//Get and save the recommendation for the dealer's rank two card.
				recPair.first = handValue;
				recPair.second = Two;
				if( tokens.at(1).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(1).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(1).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(1).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank three card.
				recPair.second = Three;
				if( tokens.at(2).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(2).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(2).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(2).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank four card.
				recPair.second = Four;
				if( tokens.at(3).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(3).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(3).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(3).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank five card.
				recPair.second = Five;
				if( tokens.at(4).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(4).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(4).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(4).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank six card.
				recPair.second = Six;
				if( tokens.at(5).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(5).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(5).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(5).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank seven card.
				recPair.second = Seven;
				if( tokens.at(6).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(6).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(6).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(6).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank eight card.
				recPair.second = Eight;
				if( tokens.at(7).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(7).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(7).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(7).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank nine card.
				recPair.second = Nine;
				if( tokens.at(8).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(8).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(8).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(8).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's rank ten card.
				recPair.second = Ten;
				if( tokens.at(9).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(9).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(9).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(9).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}

				//Get and save the recommendation for the dealer's ace card.
				recPair.second = Ace;
				if( tokens.at(10).compare("Stand") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Stand;
				}
				else if( tokens.at(10).compare("Hit") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Hit;
				}
				else if( tokens.at(10).compare("Double") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::DoubleDown;
				}
				else if( tokens.at(10).compare("Split") == 0 )
				{//If the recommendation is stand, store that in the rank.
					recommendations[recPair] = AutoStrategy::Split;
				}
			}
		}
		else
		{//There was a problem opening the file.
			std::cerr << "There was a problem opening the recommendations file " << recommendationsFilename << std::endl;
		}
	}

	std::vector<std::string> InternetRecommendedStrategy::parseLine( std::string line, std::string delim )
	{//Parse line into tokens separated by delim and return the tokens in a vector.
		//char delim = ",";//The delimiter to look for.
		std::vector<std::string> tokens;//The tokens to return.
		size_t first = 0;//The position of the first character of the token.
		size_t last = 0;//The position of the last character of the token.

		do
		{
			last = line.find( delim, first );//Find the first occurence of the delimiter after position first.
			tokens.push_back( line.substr(first, last-first) );//Put the token into the vector.
			first = last + 1;//Go to the next token
		}
		while( last != std::string::npos );//Go until there aren't any more delimiters (in which case the find method returns npos).

		return tokens;
/*
		std::string token;//A holder for the token.
		std::stringstream lineStream( line );//A stream of the line to put into getline for splitting the line token by token.

		while( std::getline(lineStream, token, delim) )
		{
			tokens.push_back( token );
		}

		return tokens;
*/
	}
}
