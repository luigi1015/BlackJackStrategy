#include "Player.h"
/*
namespace Blackjack
{
	class Player
	{//A Blackjack player.
		private:
			std::vector<Hand> hands;//Put the hand in a vector since there could be more than one due to a split.

		public:
			Player();//Default Cunstructor.
			size_t numHands() const;//Returns the number of hands the player currently has.
			Hand& getHand( size_t n );//Returns the hand at location n. n should be between 0 and numHands()-1, inclusive.
			std::vector<Hand>& getHands();//Returns the hands as a vector. This is mainly for use with HandsIterator.
			void split( size_t n );//Splits the hand at index n. Throws an exception if the hand can't be split according to the rules of blackjack.
	};
}
*/


namespace Blackjack
{
	Player::Player()
	{//Default Cunstructor.
	}

	size_t Player::numHands() const
	{//Returns the number of hands the player currently has.
		return hands.size();
	}
}
