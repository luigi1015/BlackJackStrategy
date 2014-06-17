#include UserPlayer.h

/*
namespace Blackjack
{
	class UserPlayer: public Player
	{//A Blackjack player that plays with user input.
		private:

		public:
			UserPlayer( unsigned int newID ) : Player( newID );//Constructor with only the ID.
			UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName );//Constructor with the player's name and the ID.
			UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name, the ID and the Dealer.
			int play();//Play blackjack with user input. Returns an int of value from playReturnValues to tell the dealer if it wants to continue or stop.
	};
}
*/

namespace Blackjack
{
	UserPlayer::UserPlayer( unsigned int newID ) : Player( newID )
	{//Constructor with only the ID.
	}

	UserPlayer::UserPlayer( unsigned int newID, std::string newName ) : Player( newID, newName )
	{//Constructor with the player's name and the ID.
	}

	UserPlayer::UserPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer )
	{//Constructor with the player's name, the ID and the Dealer.
	}

	void UserPlayer::play()
	{//Play blackjack with user input.
	}
}
