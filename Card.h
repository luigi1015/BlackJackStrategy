#ifndef Card_h
#define Card_h

#include <ostream>

namespace Blackjack
{
	enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
	enum Suit { Clubs, Diamonds, Hearts, Spades };

	class Card
	{//A single playing card.
		private:
			Rank cardRank;
			Suit cardSuit;

		public:
			Card( Rank newCardRank, Suit newCardSuit );//Initializes the card's value.
			void setRank( Rank newCardRank );//Set the rank.
			int getRank() const;//Return the rank.
			void setSuit( Suit newCardSuit );//Set the suit.
			int getSuit() const;//Return the suit.
			size_t getPoints() const;//Return the numeric value of the rank according to the rules of Blackjack. Ace returns 11 instead of 1.
			bool isAce() const;//Returns if this card is an ace.
			friend std::ostream& operator<<(std::ostream &out, const Card &c);//For stream output.
	};
}

#endif /* Card_h */
