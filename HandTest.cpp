#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
#include "Hand.h"

class CardTest : public CppUnit::TestCase 
{
	private:

	public:
		void testCreateHand()
		{//Basic test of creating a hand.
			//Set up the hand without cards.
			Blackjack::Hand h;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );

			//Add a card.
			h.addCard( Blackjack::Two, Blackjack::Clubs );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );
		}

		void testChangeHand()
		{//Basic test of creating a hand.
			//Set up the hand without cards.
			Blackjack::Hand h;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );

			//Add a card.
			h.addCard( Blackjack::Two, Blackjack::Clubs );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );

			//Change a card.
			h.getCard(0).setRank( Blackjack::Three );
			h.getCard(0).setSuit( Blackjack::Diamonds );

			//Verify the new values.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Diamonds );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 3 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );
		}

		void testAddCardToHand()
		{//Basic test of creating a hand.
			//Set up the hand without cards.
			Blackjack::Hand h;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );

			//Add a card.
			h.addCard( Blackjack::Two, Blackjack::Clubs );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );

			//Add another card.
			h.addCard( Blackjack::Ace, Blackjack::Hearts );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 2 );
			CPPUNIT_ASSERT( h.getCard(1).getRank() == Blackjack::Ace );
			CPPUNIT_ASSERT( h.getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( h.getCard(1).getPoints() == 11 );
			CPPUNIT_ASSERT( h.getCard(1).isAce() == true );
		}

		void testRemoveCardFromHand()
		{//Basic test of creating a hand.
			//Set up the hand without cards.
			Blackjack::Hand h;
			Blackjack::Card removedCard;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );

			//Add the cards.
			h.addCard( Blackjack::Two, Blackjack::Clubs );
			h.addCard( Blackjack::Ace, Blackjack::Hearts );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );
			CPPUNIT_ASSERT( h.getCard(1).getRank() == Blackjack::Ace );
			CPPUNIT_ASSERT( h.getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( h.getCard(1).getPoints() == 11 );
			CPPUNIT_ASSERT( h.getCard(1).isAce() == true );

			//Add another card.
			removedCard = h.removeCard( 1 );

			//Verify the correct card was removed.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );
			CPPUNIT_ASSERT( removedCard.getRank() == Blackjack::Ace );
			CPPUNIT_ASSERT( removedCard.getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( removedCard.getPoints() == 11 );
			CPPUNIT_ASSERT( removedCard.isAce() == true );
		}

		void testClearHand()
		{//Basic test of creating a hand.
			//Set up the hand without cards.
			Blackjack::Hand h;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );

			//Add a card.
			h.addCard( Blackjack::Two, Blackjack::Clubs );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 1 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );

			//Clear the hand.
			h.clearCards();

			//Verify the hand's cleared.
			CPPUNIT_ASSERT( h.getNumCards() == 0 );
		}

		void testSplitHand()
		{//Basic test of the canSplit() method.
			//Set up the hand without cards.
			Blackjack::Hand h;

			//Verify the hand without cards.
			CPPUNIT_ASSERT( !(h.canSplit()) );

			//Add a card.
			h.addCard( Blackjack::Two, Blackjack::Clubs );
			h.addCard( Blackjack::Two, Blackjack::Hearts );

			//Verify the values.
			CPPUNIT_ASSERT( h.canSplit() );

			//Clear the hand.
			h.getCard(0).setRank( Blackjack::Three );;

			//Verify the hand's cleared.
			CPPUNIT_ASSERT( !(h.canSplit()) );
		}

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CardTest );
		CPPUNIT_TEST( testCreateHand );
		CPPUNIT_TEST( testAddCardToHand );
		CPPUNIT_TEST( testChangeHand );
		CPPUNIT_TEST( testClearHand );
		CPPUNIT_TEST( testRemoveCardFromHand );
		CPPUNIT_TEST( testSplitHand );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( CardTest );
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry( );
	runner.addTest( registry.makeTest( ) );
	if ( runner.run( ) )
	{//Runner had success.
		return 0;
	}
	else
	{//Runner failed.
		return 1;
	}
}
