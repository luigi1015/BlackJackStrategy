#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
#include "HandCollection.h"

class HandCollectionTest : public CppUnit::TestCase 
{
	private:

	public:
		void testCreateCollection()
		{//Basic test of creating a hand.
			//Set up the player.
			Blackjack::Hand firstHand, secondHand;
			Blackjack::HandCollection collection;
			firstHand.addCard( Blackjack::Two, Blackjack::Clubs );
			firstHand.addCard( Blackjack::Three, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Five, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Jack, Blackjack::Diamonds );
			secondHand.addCard( Blackjack::Ace, Blackjack::Spades );
			collection.addHand( firstHand );
			collection.addHand( secondHand );

			//Check first hand.
			CPPUNIT_ASSERT( collection.getHand(0).getNumCards() == 2 );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getPoints() == 2 );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(0).isAce() == false );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getPoints() == 3 );
			CPPUNIT_ASSERT( collection.getHand(0).getCard(1).isAce() == false );

			//Check second hand.
			CPPUNIT_ASSERT( collection.getHand(1).getNumCards() == 3 );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getRank() == Blackjack::Five );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getPoints() == 5 );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(0).isAce() == false );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getRank() == Blackjack::Jack );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getSuit() == Blackjack::Diamonds );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getPoints() == 10 );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(1).isAce() == false );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getRank() == Blackjack::Ace );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getSuit() == Blackjack::Spades );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getPoints() == 11 );
			CPPUNIT_ASSERT( collection.getHand(1).getCard(2).isAce() == true );
		}
		
		void testIterateCollection()
		{//Basic test of iterating through a hand.
			size+t i = 0;
			//Set up the player.
			Blackjack::Hand firstHand, secondHand;
			Blackjack::HandCollection collection;
			firstHand.addCard( Blackjack::Two, Blackjack::Clubs );
			firstHand.addCard( Blackjack::Three, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Five, Blackjack::Hearts );
			secondHand.addCard( Blackjack::Jack, Blackjack::Diamonds );
			secondHand.addCard( Blackjack::Ace, Blackjack::Spades );
			collection.addHand( firstHand );
			collection.addHand( secondHand );

			for( Blackjack::HandCollection::HandList it = collection.begin(); it != collection.end(); it++ )
			{
				if( i == 0 )
				{
					//Check first hand.
					CPPUNIT_ASSERT( collection.getHand(0).getNumCards() == 2 );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getRank() == Blackjack::Two );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getSuit() == Blackjack::Clubs );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(0).getPoints() == 2 );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(0).isAce() == false );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getRank() == Blackjack::Three );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getSuit() == Blackjack::Hearts );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(1).getPoints() == 3 );
					CPPUNIT_ASSERT( collection.getHand(0).getCard(1).isAce() == false );

					i++;
				}
				else if( i == 1 )
				{
					//Check second hand.
					CPPUNIT_ASSERT( collection.getHand(1).getNumCards() == 3 );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getRank() == Blackjack::Five );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getSuit() == Blackjack::Hearts );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(0).getPoints() == 5 );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(0).isAce() == false );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getRank() == Blackjack::Jack );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getSuit() == Blackjack::Diamonds );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(1).getPoints() == 10 );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(1).isAce() == false );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getRank() == Blackjack::Ace );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getSuit() == Blackjack::Spades );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(2).getPoints() == 11 );
					CPPUNIT_ASSERT( collection.getHand(1).getCard(2).isAce() == true );

					i++;
				}
				else
				{
					CPPUNIT_ASSERT( false == true );//Should not get here since the above should cover all the hands.
				}
		}

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( HandCollectionTest );
		CPPUNIT_TEST( testCreateCollection );
		CPPUNIT_TEST( testIterateCollection );
		CPPUNIT_TEST_SUITE_END( );
};

int main()
{
	CPPUNIT_TEST_SUITE_REGISTRATION( HandCollectionTest );
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
