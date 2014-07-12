.PHONY: all test clean

all: Card.o Hand.o HandCollection.o Player.o UserPlayer.o AutoPlayer.o BlackJack test

test: CardTest HandTest HandCollectionTest
#test: CardTest HandTest HandsIteratorTest HandCollectionTest

Card.o: Card.h Card.cpp
	g++ -g -Wall -c Card.cpp

CardTest: Card.h Card.cpp Card.o CardTest.cpp
	g++ -g -Wall -o CardTest CardTest.cpp Card.o -lcppunit

Hand.o: Hand.h Hand.cpp
	g++ -g -Wall -c Hand.cpp

HandCollection.o: HandCollection.h HandCollection.cpp
	g++ -g -Wall -c HandCollection.cpp

HandCollectionTest: HandCollection.h HandCollection.cpp HandCollection.o HandCollectionTest.cpp
	g++ -g -Wall -o HandCollectionTest HandCollection.o Hand.o Card.o HandCollectionTest.cpp -lcppunit

Player.o: Player.h Player.cpp
	g++ -g -Wall -c Player.cpp

UserPlayer.o: UserPlayer.h UserPlayer.cpp
	g++ -g -Wall -c UserPlayer.cpp

AutoPlayer.o: AutoPlayer.h AutoPlayer.cpp
	g++ -g -Wall -c AutoPlayer.cpp

HandsIterator.o: HandsIterator.h HandsIterator.cpp
	g++ -g -Wall -c HandsIterator.cpp

HandTest: Hand.h Hand.cpp Hand.o HandTest.cpp
	g++ -g -Wall -o HandTest HandTest.cpp Hand.o Card.o -lcppunit

BlackJack: Player.h Player.cpp Hand.h Hand.cpp AutoPlayer.h AutoPlayer.cpp UserPlayer.h UserPlayer.cpp HandCollection.h HandCollection.cpp Hand.h Hand.cpp Card.h Card.cpp
	g++ -g -Wall -std=c++11 Player.h Player.cpp Hand.h Hand.cpp AutoPlayer.h AutoPlayer.cpp UserPlayer.h UserPlayer.cpp HandCollection.h HandCollection.cpp Hand.h Hand.cpp Card.h Card.cpp main.cpp -o BlackJack

#HandsIteratorTest: Hand.h Hand.cpp Hand.o Card.h Card.cpp Card.o HandsIterator.h HandsIterator.cpp HandsIterator.o HandCollection.h HandCollection.cpp HandCollection.o Player.h Player.cpp Player.o HandsIteratorTest.cpp
#	g++ -g -Wall -o HandsIteratorTest HandsIteratorTest.cpp HandsIterator.o Hand.o Card.o Player.o HandCollection.o -lcppunit

clean:
	rm *.o *~ *.gch CardTest HandTest HandsIteratorTest HandCollectionTest BlackJack
