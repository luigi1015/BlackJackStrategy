#ifndef InternetRecommendedStrategy_h
#define InternetRecommendedStrategy_h

#include <vector>
#include <map>
#include <string>
#include <utility>
#include "AutoStrategy.h"
#include "Card.h"
#include "Hand.h"

namespace Blackjack
{
	class InternetRecommendedStrategy: public AutoStrategy
	{//A Blackjack strategy from the internet.
		private:
			std::map<std::pair<std::string, Rank>, AutoStrategy::Decision> recommendations;//A map of the different decisions based on the player's hand and the dealer's first card. The pair holds both the player's hand value, the string, and the dealer's first card, the Rank. The string can just be a number, indicating a hand of that value that's not soft, "Soft ##" which indicates a soft hand of that value, or "Pair X" which indicates a pair of that card rank (2-9 just use their number, 10 and face cards use "10", Ace use "A").
			std::vector<std::string> parseLine( std::string line, std::string delim );//Parse line into tokens separated by delim and return the tokens in a vector.

		public:
			int decide( Card dealerCard, Hand playerHand );//Takes the dealer's card, the player's cards, decide what to do, and return the appropriate Decision value.
			void readRecommendations( std::string recommendationsFilename = "InternetStrategyTable.csv" );//Reads the recommendations from the csv file and populates the recommendations map object accordingly.
			//std::vector<std::string> parseLine( std::string line, std::string delim );//Parse line into tokens separated by delim and return the tokens in a vector.
	};
}

#endif /* InternetRecommendedStrategy_h */
