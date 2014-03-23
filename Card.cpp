#include <ostream>
#include <stdexcept>
#include <sstream>
#include "Card.h"

/*
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
			Card();//Default Cunstructor.
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
*/

namespace Blackjack
{
	Card::Card()
	{//Default Cunstructor.
	}

	Card::Card( Rank newCardRank, Suit newCardSuit )
	{//Initializes the card's value.
		cardRank = newCardRank;
		cardSuit = newCardSuit;
	}

	void Card::setRank( Rank newCardRank )
	{//Set the rank.
		cardRank = newCardRank;
	}

	int Card::getRank() const
	{//Return the rank.
		return cardRank;
	}

	void Card::setSuit( Suit newCardSuit )
	{//Set the suit.
		cardSuit = newCardSuit;
	}

	int Card::getSuit() const
	{//Return the suit.
		return cardSuit;
	}

	size_t Card::getPoints() const
	{//Return the numeric value of the rank according to the rules of Blackjack. Ace returns 11 instead of 1.
		switch( cardRank )
		{
			case Two:
				return 2;

			case Three:
				return 3;

			case Four:
				return 4;

			case Five:
				return 5;

			case Six:
				return 6;

			case Seven:
				return 7;

			case Eight:
				return 8;

			case Nine:
				return 9;

			case Ten:
				return 10;

			case Jack:
				return 10;

			case Queen:
				return 10;

			case King:
				return 10;

			case Ace:
				return 11;

			default:
				std::ostringstream buffer;
				buffer << "Rank " << cardRank << " is invalid in getPoints().";
				throw std::out_of_range( buffer.str() );
		}
	}

	bool Card::isAce() const
	{//Returns if this card is an ace.
		return (cardRank == Ace);
	}

	std::ostream& operator<<(std::ostream &out, const Card &c)
	{//For stream output.
		switch( c.getRank() )
		{
			case Two:
				out << "Two ";

			case Three:
				out << "Three ";

			case Four:
				out << "Four ";

			case Five:
				out << "Five ";

			case Six:
				out << "Six ";

			case Seven:
				out << "Seven ";

			case Eight:
				out << "Eight ";

			case Nine:
				out << "Nine ";

			case Ten:
				out << "Ten ";

			case Jack:
				out << "Jack ";

			case Queen:
				out << "Queen ";

			case King:
				out << "King ";

			case Ace:
				out << "Ace ";

			default:
				std::ostringstream buffer;
				buffer << "Rank " << c.getRank() << " is invalid in << operator.";
				throw std::out_of_range( buffer.str() );
		}

		out << "of ";

		switch( c.getSuit() )
		{
			case Clubs:
				out << "Clubs";

			case Diamonds:
				out << "Diamonds";

			case Hearts:
				out << "Hearts";

			case Spades:
				out << "Spades";

			default:
				std::ostringstream buffer;
				buffer << "Suit " << c.getSuit() << " is invalid in << operator.";
				throw std::out_of_range( buffer.str() );
		}
	}
}
