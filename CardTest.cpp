#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include "Card.h"

class CardTest : public CppUnit::TestCase 
{
	private:
		
	public:
		void testCreateCard()
		{//Basic test of creating a vertex.
			//Set up the vertex.
			Blackjack::Card c(Blackjack::Two, Blackjack::Clubs);
			
			//Verify the values.
			CPPUNIT_ASSERT( c.getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( c.getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( c.getPoints() == 2 );
			CPPUNIT_ASSERT( c.isAce() == false );
		}
		
		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CardTest );
		CPPUNIT_TEST( testCreateCard );
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
