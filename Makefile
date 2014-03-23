.PHONY: all test clean

all: Card.o test

test: CardTest

Card.o: Card.h Card.cpp
	g++ -g -Wall -c Card.cpp

CardTest: Card.h Card.cpp Card.o CardTest.cpp
	g++ -g -Wall -o CardTest CardTest.cpp Card.o -lcppunit

clean:
	rm *.o *~ *.gch CardTest
