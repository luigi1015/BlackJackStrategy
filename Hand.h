#ifndef Hand_h
#define Hand_h

#include <ostream>
#include <vector>
#include "Card.h"

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
			size_t getMaxPointsAtOrBelow21() const;//Get the max number of points below 21 taking into account that an Ace can be 1 or 11. This is using BlackJack rules. If there isn't any hand below 21, the method will return the lowest of points number above 21.
			bool isSoft() const;//Returns true if this is a soft hand according to the rules of BlackJack.
			bool isPair() const;//Returns true if this hand is a pair of equal rank cards.
			bool isBust() const;//Returns if this is a bust according to the rules of BlackJack. Basically it's a bust if the minimum number of points is above 21.
			bool isBlackJack() const;//Returns true if the points add up to 21 according to the rules of BlackJack.
			friend std::ostream& operator<<(std::ostream &out, const Hand &h);//For stream output.
	};
}

#endif /* Hand_h */
