#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <vector>
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

		void testCreateAllCardCombinations()
		{//Basic test of creating a vertex.
			//Set up the vertex.
			Blackjack::Card c01(Blackjack::Two, Blackjack::Clubs);
			Blackjack::Card c02(Blackjack::Three, Blackjack::Clubs);
			Blackjack::Card c03(Blackjack::Four, Blackjack::Clubs);
			Blackjack::Card c04(Blackjack::Five, Blackjack::Clubs);
			Blackjack::Card c05(Blackjack::Six, Blackjack::Clubs);
			Blackjack::Card c06(Blackjack::Seven, Blackjack::Clubs);
			Blackjack::Card c07(Blackjack::Eight, Blackjack::Clubs);
			Blackjack::Card c08(Blackjack::Nine, Blackjack::Clubs);
			Blackjack::Card c09(Blackjack::Ten, Blackjack::Clubs);
			Blackjack::Card c10(Blackjack::Jack, Blackjack::Clubs);
			Blackjack::Card c11(Blackjack::Queen, Blackjack::Clubs);
			Blackjack::Card c12(Blackjack::King, Blackjack::Clubs);
			Blackjack::Card c13(Blackjack::Ace, Blackjack::Clubs);
			Blackjack::Card c14(Blackjack::Two, Blackjack::Diamonds);
			Blackjack::Card c15(Blackjack::Three, Blackjack::Diamonds);
			Blackjack::Card c16(Blackjack::Four, Blackjack::Diamonds);
			Blackjack::Card c17(Blackjack::Five, Blackjack::Diamonds);
			Blackjack::Card c18(Blackjack::Six, Blackjack::Diamonds);
			Blackjack::Card c19(Blackjack::Seven, Blackjack::Diamonds);
			Blackjack::Card c20(Blackjack::Eight, Blackjack::Diamonds);
			Blackjack::Card c21(Blackjack::Nine, Blackjack::Diamonds);
			Blackjack::Card c22(Blackjack::Ten, Blackjack::Diamonds);
			Blackjack::Card c23(Blackjack::Jack, Blackjack::Diamonds);
			Blackjack::Card c24(Blackjack::Queen, Blackjack::Diamonds);
			Blackjack::Card c25(Blackjack::King, Blackjack::Diamonds);
			Blackjack::Card c26(Blackjack::Ace, Blackjack::Diamonds);
			Blackjack::Card c27(Blackjack::Two, Blackjack::Hearts);
			Blackjack::Card c28(Blackjack::Three, Blackjack::Hearts);
			Blackjack::Card c29(Blackjack::Four, Blackjack::Hearts);
			Blackjack::Card c30(Blackjack::Five, Blackjack::Hearts);
			Blackjack::Card c31(Blackjack::Six, Blackjack::Hearts);
			Blackjack::Card c32(Blackjack::Seven, Blackjack::Hearts);
			Blackjack::Card c33(Blackjack::Eight, Blackjack::Hearts);
			Blackjack::Card c34(Blackjack::Nine, Blackjack::Hearts);
			Blackjack::Card c35(Blackjack::Ten, Blackjack::Hearts);
			Blackjack::Card c36(Blackjack::Jack, Blackjack::Hearts);
			Blackjack::Card c37(Blackjack::Queen, Blackjack::Hearts);
			Blackjack::Card c38(Blackjack::King, Blackjack::Hearts);
			Blackjack::Card c39(Blackjack::Ace, Blackjack::Hearts);
			Blackjack::Card c40(Blackjack::Two, Blackjack::Spades);
			Blackjack::Card c41(Blackjack::Three, Blackjack::Spades);
			Blackjack::Card c42(Blackjack::Four, Blackjack::Spades);
			Blackjack::Card c43(Blackjack::Five, Blackjack::Spades);
			Blackjack::Card c44(Blackjack::Six, Blackjack::Spades);
			Blackjack::Card c45(Blackjack::Seven, Blackjack::Spades);
			Blackjack::Card c46(Blackjack::Eight, Blackjack::Spades);
			Blackjack::Card c47(Blackjack::Nine, Blackjack::Spades);
			Blackjack::Card c48(Blackjack::Ten, Blackjack::Spades);
			Blackjack::Card c49(Blackjack::Jack, Blackjack::Spades);
			Blackjack::Card c50(Blackjack::Queen, Blackjack::Spades);
			Blackjack::Card c51(Blackjack::King, Blackjack::Spades);
			Blackjack::Card c52(Blackjack::Ace, Blackjack::Spades);
			
			std::vector<Blackjack::Card> cards;
			
			for( int i = 0; i < 52; i++ )
			{//Create the cards.
				Blackjack::Card newCard;

				//Set the suit.
				if( i < 13 )
				{
					newCard.setSuit( Blackjack::Clubs );
				}
				else if( (i > 12) && (i < 26) )
				{
					newCard.setSuit( Blackjack::Diamonds );
				}
				else if( (i > 25) && (i < 39) )
				{
					newCard.setSuit( Blackjack::Hearts );
				}
				else if( i > 38 )
				{
					newCard.setSuit( Blackjack::Spades );
				}

				//Set the rank.
				if( i%13 == 0 )
				{
					newCard.setRank( Blackjack::Two );
				}
				else if( i%13 == 1 )
				{
					newCard.setRank( Blackjack::Three );
				}
				else if( i%13 == 2 )
				{
					newCard.setRank( Blackjack::Four );
				}
				else if( i%13 == 3 )
				{
					newCard.setRank( Blackjack::Five );
				}
				else if( i%13 == 4 )
				{
					newCard.setRank( Blackjack::Six );
				}
				else if( i%13 == 5 )
				{
					newCard.setRank( Blackjack::Seven );
				}
				else if( i%13 == 6 )
				{
					newCard.setRank( Blackjack::Eight );
				}
				else if( i%13 == 7 )
				{
					newCard.setRank( Blackjack::Nine );
				}
				else if( i%13 == 8 )
				{
					newCard.setRank( Blackjack::Ten );
				}
				else if( i%13 == 9 )
				{
					newCard.setRank( Blackjack::Jack );
				}
				else if( i%13 == 10 )
				{
					newCard.setRank( Blackjack::Queen );
				}
				else if( i%13 == 11 )
				{
					newCard.setRank( Blackjack::King );
				}
				else if( i%13 == 12 )
				{
					newCard.setRank( Blackjack::Ace );
				}

				cards.push_back( newCard );

				std::cout << newCard << std::endl;
			}

			//Verify the values.
			CPPUNIT_ASSERT( c01.getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( c01.getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( c01.getPoints() == 2 );
			CPPUNIT_ASSERT( c01.isAce() == false );
		}

		void testChangeCard()
		{//Basic test of creating a vertex.
			//Set up the vertex.
			Blackjack::Card c(Blackjack::Two, Blackjack::Clubs);

			//Verify the initial values.
			CPPUNIT_ASSERT( c.getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( c.getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( c.getPoints() == 2 );
			CPPUNIT_ASSERT( c.isAce() == false );

			c.setRank( Blackjack::Three );
			c.setSuit( Blackjack::Diamonds );

			//Verify the new values.
			CPPUNIT_ASSERT( c.getRank() == Blackjack::Three );
			CPPUNIT_ASSERT( c.getSuit() == Blackjack::Diamonds );
			CPPUNIT_ASSERT( c.getPoints() == 3 );
			CPPUNIT_ASSERT( c.isAce() == false );

			c.setRank( Blackjack::Ace );
			c.setSuit( Blackjack::Hearts );

			//Verify the new values.
			CPPUNIT_ASSERT( c.getRank() == Blackjack::Ace );
			CPPUNIT_ASSERT( c.getSuit() == Blackjack::Hearts );
			CPPUNIT_ASSERT( c.getPoints() == 11 );
			CPPUNIT_ASSERT( c.isAce() == true );
		}

		//Create the test suite using CPPUnit macros.
		CPPUNIT_TEST_SUITE( CardTest );
		CPPUNIT_TEST( testCreateCard );
		CPPUNIT_TEST( testCreateAllCardCombinations );
		CPPUNIT_TEST( testChangeCard );
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
