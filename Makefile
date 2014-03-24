.PHONY: all test clean

all: Card.o Hand.o test

test: CardTest HandTest

Card.o: Card.h Card.cpp
	g++ -g -Wall -c Card.cpp

CardTest: Card.h Card.cpp Card.o CardTest.cpp
	g++ -g -Wall -o CardTest CardTest.cpp Card.o -lcppunit

Hand.o: Hand.h Hand.cpp
	g++ -g -Wall -c Hand.cpp

HandTest: Hand.h Hand.cpp Hand.o HandTest.cpp
	g++ -g -Wall -o HandTest HandTest.cpp Hand.o Card.o -lcppunit

clean:
	rm *.o *~ *.gch CardTest HandTest
