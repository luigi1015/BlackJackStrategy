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
		{//Basic test of creating a card.
			//Set up the vertex.
			Blackjack::Card c(Blackjack::Two, Blackjack::Clubs);

			//Verify the values.
			CPPUNIT_ASSERT( c.getRank() == Blackjack::Two );
			CPPUNIT_ASSERT( c.getSuit() == Blackjack::Clubs );
			CPPUNIT_ASSERT( c.getPoints() == 2 );
			CPPUNIT_ASSERT( c.isAce() == false );
		}

		void testCreateAllCardCombinations()
		{//Test creating all combinations of cards.
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

				//std::cout << newCard << std::endl;
			}

			for( size_t i = 0; i < cards.size(); i++ )
			{//Verify the values.
				//Verify the suit.
				if( i < 13 )
				{
					CPPUNIT_ASSERT( cards.at(i).getSuit() == Blackjack::Clubs );
					//newCard.setSuit( Blackjack::Clubs );
				}
				else if( (i > 12) && (i < 26) )
				{
					CPPUNIT_ASSERT( cards.at(i).getSuit() == Blackjack::Diamonds );
					//newCard.setSuit( Blackjack::Diamonds );
				}
				else if( (i > 25) && (i < 39) )
				{
					CPPUNIT_ASSERT( cards.at(i).getSuit() == Blackjack::Hearts );
					//newCard.setSuit( Blackjack::Hearts );
				}
				else if( i > 38 )
				{
					CPPUNIT_ASSERT( cards.at(i).getSuit() == Blackjack::Spades );
					//newCard.setSuit( Blackjack::Spades );
				}

				//Verify the rank.
				if( i%13 == 0 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Two );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 2 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Two );
				}
				else if( i%13 == 1 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Three );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 3 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Three );
				}
				else if( i%13 == 2 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Four );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 4 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Four );
				}
				else if( i%13 == 3 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Five );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 5 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Five );
				}
				else if( i%13 == 4 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Six );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 6 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Six );
				}
				else if( i%13 == 5 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Seven );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 7 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Seven );
				}
				else if( i%13 == 6 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Eight );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 8 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Eight );
				}
				else if( i%13 == 7 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Nine );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 9 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Nine );
				}
				else if( i%13 == 8 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Ten );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 10 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Ten );
				}
				else if( i%13 == 9 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Jack );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 10 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Jack );
				}
				else if( i%13 == 10 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Queen );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 10 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::Queen );
				}
				else if( i%13 == 11 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::King );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 10 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == false );
					//newCard.setRank( Blackjack::King );
				}
				else if( i%13 == 12 )
				{
					CPPUNIT_ASSERT( cards.at(i).getRank() == Blackjack::Ace );
					CPPUNIT_ASSERT( cards.at(i).getPoints() == 11 );
					CPPUNIT_ASSERT( cards.at(i).isAce() == true );
					//newCard.setRank( Blackjack::Ace );
				}
			}
		}

		void testChangeCard()
		{//Test changing the card values.
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
