.PHONY: all test clean

all: Card.o Hand.o test

test: CardTest HandTest HandsIteratorTest

Card.o: Card.h Card.cpp
	g++ -g -Wall -c Card.cpp

CardTest: Card.h Card.cpp Card.o CardTest.cpp
	g++ -g -Wall -o CardTest CardTest.cpp Card.o -lcppunit

Hand.o: Hand.h Hand.cpp
	g++ -g -Wall -c Hand.cpp

HandsIterator.o: HandsIterator.h HandsIterator.cpp
	g++ -g -Wall -c HandsIterator.cpp

HandTest: Hand.h Hand.cpp Hand.o HandTest.cpp
	g++ -g -Wall -o HandTest HandTest.cpp Hand.o Card.o -lcppunit

HandsIteratorTest: HandsIterator.h HandsIterator.cpp HandsIterator.o HandsIteratorTest.cpp
	g++ -g -Wall -o HandsIteratorTest HandsIteratorTest.cpp HandsIterator.o Hand.o Card.o -lcppunit

clean:
	rm *.o *~ *.gch CardTest HandTest HandsIteratorTest
