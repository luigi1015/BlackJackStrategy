#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
#include "Hand.h"
//#include "Card.cpp"

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

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CardTest );
		CPPUNIT_TEST( testCreateHand );
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
