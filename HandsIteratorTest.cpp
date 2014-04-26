#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
#include "Hand.h"
#include "HandsIterator.h"

class HandsIteratorTest : public CppUnit::TestCase 
{
	private:

	public:
		void testIterateHand()
		{//Basic test of creating a hand.
			//Set up the hand.
			Blackjack::Hand h;
			h.addCard( Blackjack::Two, Blackjack::Clubs );
			h.addCard( Blackjack::Three, Blackjack::Hearts );

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
			//TODO: Finish this
			CPPUNIT_ASSERT( 1 == 0 );
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
