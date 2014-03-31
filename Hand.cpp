#include <iostream>
#include <ostream>
#include <vector>
#include "Hand.h"

/*
namespace Blackjack
{
	class Hand
	{//A hand of playing cards.
		private:
			std::vector<Card> cards;

		public:
			Hand();//Default Cunstructor.
			void addCard( Rank newCardRank, Suit newCardSuit );//Add a card
			void addCard( Card newCard );//Add a card
			size_t getNumCards() const;//Get the number of cards in the hand.
			Card& getCard( size_t n );//Get card a location n. n should be between 0 and getNumCards()-1, inclusive.
			const Card& getCard( size_t n ) const;//Get card a location n. n should be between 0 and getNumCards()-1, inclusive.
			void clearCards();//Clear all the cards from the hand.
			int getMaxPointsAtOrBelow21() const;//Get the max number of points below 21 taking into account that an Ace can be 1 or 11. This is using BlackJack rules. If there isn't any hand below 21, the method will return the lowest of points number above 21.
			bool isSoft() const;//Returns true if this is a soft hand according to the rules of BlackJack.
			bool isPair() const;//Returns true if this hand is a pair of equal rank cards.
			bool isBust() const;//Returns if this is a bust according to the rules of BlackJack. Basically it's a bust if the minimum number of points is above 21.
			bool isBlackJack() const;//Returns true if the points add up to 21 according to the rules of BlackJack.
			friend std::ostream& operator<<(std::ostream &out, const Hand &h);//For stream output.
	};
}
*/
namespace Blackjack
{
	Hand::Hand()
	{//Default Cunstructor.
	}

	void Hand::addCard( Rank newCardRank, Suit newCardSuit )
	{//Add a card
		Card newCard( newCardRank, newCardSuit );
		cards.push_back( newCard );
	}

	void Hand::addCard( Card newCard )
	{//Add a card
		cards.push_back( newCard );
	}

	size_t Hand::getNumCards() const
	{//Get the number of cards in the hand.
		return cards.size();
	}

	Card& Hand::getCard( size_t n )
	{//Get card a location n. n should be between 0 and getNumCards()-1, inclusive.
		return cards.at( n );
	}

	const Card& Hand::getCard( size_t n ) const
	{//Get card a location n. n should be between 0 and getNumCards()-1, inclusive.
		return cards.at( n );
	}

	void Hand::clearCards()
	{//Clear all the cards from the hand.
		cards.clear();
	}

	Card Hand::removeCard( size_t n )
	{//Removes a card from the hand. n should be between 0 and getNumCards()-1, inclusive. Returns a copy of the card that was removed.
		Card removedCard = cards.at( n );
		cards.erase( cards.begin() + n );
		return removedCard;
	}

	size_t Hand::getMaxPointsAtOrBelow21() const
	{//Get the max number of points below 21 taking into account that an Ace can be 1 or 11. This is using BlackJack rules. If there isn't any hand below 21, the method will return the lowest of points number above 21.
		size_t sum = 0;//The sum of the points.
		bool encounteredAce = false;//True if the method finds an ace to help figure out if one of the aces will be value 1 or 11. Doesn't bother about the other aces, see comments below for why.

		for( size_t i = 0; i < cards.size(); i++ )
		{//Go through the cards and add up their values.
			if( cards.at(i).isAce() )
			{//If it's an ace, record that and add 1 to the sum.
				encounteredAce = true;
				sum += 1;
			}
			else
			{//It's not an ace, so just add up the value for the card.
				sum += cards.at(i).getPoints();
			}
		}

		if( encounteredAce )
		{//If it encountered an ace, check to see if it should make one of the ace(s) an 11 instead of a 1. The other aces don't matter since more than one 11-point ace will the total at least 22 all by themselves. Since 22 is greater than 21, all aces except for one will be counted as 1 point cards.
			if( sum <= 11 )
			{//If the sum is at least 10 below 21 (21-10=11), count the ace as 11 by adding 10. Only 10 needs to be added since 1 point has already been counted per ace.
				sum += 10;
			}
		}

		return sum;
	}

	bool Hand::isSoft() const
	{//Returns true if this is a soft hand according to the rules of BlackJack.
		//Use the same algorithm as getMaxPointsAtOrBelow21(), but instead on looking for the sum, keep an eye out for if the ace was 11 or 1 point(s).
		size_t sum = 0;//The sum of the points.
		bool encounteredAce = false;//True if the method finds an ace to help figure out if one of the aces will be value 1 or 11. Doesn't bother about the other aces, see comments below for why.
		bool soft = false;//True if an ace is set to value 11 rather than 1.

		for( size_t i = 0; i < cards.size(); i++ )
		{//Go through the cards and add up their values.
			if( cards.at(i).isAce() )
			{//If it's an ace, record that and add 1 to the sum.
				encounteredAce = true;
				sum += 1;
			}
			else
			{//It's not an ace, so just add up the value for the card.
				sum += cards.at(i).getPoints();
			}
		}

		if( encounteredAce )
		{//If it encountered an ace, check to see if it should make one of the ace(s) an 11 instead of a 1. The other aces don't matter since more than one 11-point ace will the total at least 22 all by themselves. Since 22 is greater than 21, all aces except for one will be counted as 1 point cards.
			if( sum <= 11 )
			{//If the sum is at least 10 below 21 (21-10=11), count the ace as 11. If the ace is counted as 11, the hand is soft.
				soft = true;
			}
		}

		return soft;
	}

	bool Hand::isPair() const
	{//Returns true if this hand is a pair of equal rank cards.
		if( cards.size() == 2 )
		{//Check to see if there are two and only two cards. A pair is composed of two and only two cards.
			if( cards.at(0).getRank() == cards.at(1).getRank() )
			{//Check to see if the cards are of the same rank.
				return true;
			}
			else
			{//The cards are not of the same rank.
				return false;
			}
		}
		else
		{//There are more or less than two cards.
			return false;
		}
	}

	bool Hand::isBust() const
	{//Returns if this is a bust according to the rules of BlackJack. Basically it's a bust if the minimum number of points is above 21.
		return (getMaxPointsAtOrBelow21() > 21);
	}

	bool Hand::isBlackJack() const
	{//Returns true if the points add up to 21 according to the rules of BlackJack.
		return (getMaxPointsAtOrBelow21() == 21);
	}

	bool Hand::canSplit() const
	{//Returns true if the hand meets the requirements of a split according to the rules of BlackJack.
		return ( (getNumCards() == 2) && (cards.at(0).getRank() == cards.at(1).getRank()) );
	}

	std::ostream& operator<<(std::ostream &out, const Hand &h)
	{//For stream output.
		out << "There are " << h.getNumCards() << " cards." << std::endl << "Cards: " << std::endl;

		for( size_t i = 0; i < h.getNumCards(); i++ )
		{//Go through each of the cards and output them.
			out << h.getCard( i ) << std::endl;
		}

		out << "Points: " << h.getMaxPointsAtOrBelow21();
		if( h.isBlackJack() )
		{
			out << " Blackjack!";
		}
		else if( h.isBust() )
		{
			out << " Bust.";
		}
		out << std::endl;

		return out;
	}
}
