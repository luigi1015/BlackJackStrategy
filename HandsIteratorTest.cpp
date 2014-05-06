#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
//#include "Hand.h"
#include "HandsIterator.h"

class HandsIteratorTest : public CppUnit::TestCase 
{
	private:

	public:
		void testIterateHand()
		{//Basic test of creating a hand.
			//Set up the player.
			Blackjack::Hand firstHand, secondHand;
			Blackjack::Player player;
			firstHand.addCard( Blackjack::Two, Blackjack::Clubs );
			firstHand.addCard( Blackjack::Three, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Five, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Jack, Blackjack::Diamonds );
			player.addHand( firstHand );
			player.addHand( secondHand );

			//Verify the values.
			CPPUNIT_ASSERT( h.getNumCards() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( h.getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( h.getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( h.getCard(0).isAce() == false );
			CPPUNIT_ASSERT( h.getCard(1).getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( h.getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( h.getCard(1).getPoints() == 3 );
			CPPUNIT_ASSERT( h.getCard(1).isAce() == false );

			//Iterate through the values.
			Blackjack::HandsIterator handsIt( player );

			//First value
			handsIt.first();
			CPPUNIT_ASSERT( handsIt.currentHand().getNumCards() == 2 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).isAce() == false );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getPoints() == 3 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).isAce() == false );
			CPPUNIT_ASSERT( handsIt.isDone() == false );

			//Second value
			handsIt.next();
			CPPUNIT_ASSERT( handsIt.currentHand().getNumCards() == 2 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(0).isAce() == false );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).getPoints() == 3 );
			CPPUNIT_ASSERT( handsIt.currentHand().getCard(1).isAce() == false );
			CPPUNIT_ASSERT( handsIt.isDone() == false );

			//Go past second/last value.
			handsIt.next();
			CPPUNIT_ASSERT( handsIt.isDone() == true );
		}

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( HandsIteratorTest );
		CPPUNIT_TEST( testIterateHand );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( HandsIteratorTest );
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
