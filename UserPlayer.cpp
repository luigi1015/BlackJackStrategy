#include UserPlayer.h

/*
namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer() : Player();//Default Constructor.
			UserPlayer( std::string newName ) : Player();//Constructor with the player's name.
			void play();//Play blackjack with user input.
	};
}
*/

namespace Blackjack
{
	UserPlayer::UserPlayer() : Player()
	{//Default Constructor.
	}

	UserPlayer::UserPlayer( std::string newName ) : Player()
	{//Constructor with the player's name.
		name = newName;
	}

	void UserPlayer::play()
	{//Play blackjack with user input.
	}
}
