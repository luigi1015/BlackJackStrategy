/*
namespace Blackjack
{
	class AutoPlayer: public Player
	{//A Blackjack player that automatically plays without user input.
		private:
			AutoStrategy *strategy;

		public:
			//AutoPlayer();//Default Constructor.
			//AutoPlayer( unsigned int newID, std::string newName, Dealer* newDealer ) : Player( newID, newName, newDealer );//Constructor with the player's name.
			AutoPlayer( unsigned int newID, std::string newName ) : Player( newID, newName );//Constructor with the player's name and ID.
			void play();//Automatically play blackjack.
			int askQuit();//Returns an int of value from playReturnValues based on whether the player thinks it should quit.
	};
}
*/

#include "AutoPlayer.h"
#include "InternetRecommendedStrategy.h"
#include <iostream>

namespace Blackjack
{
	AutoPlayer::AutoPlayer( unsigned int newID, std::string newName ) : Player( newID, newName )
	{//Constructor with the player's name and ID.
		strategy = new InternetRecommendedStrategy();
	}

	void AutoPlayer::play()
	{//Automatically play blackjack.
		std::cerr << "AutoPlayer hasn't been written yet." << std::endl;
	}

	int AutoPlayer::askQuit()
	{//Returns an int of value from playReturnValues based on whether the player thinks it should quit.
		std::cerr << "AutoPlayer hasn't been written yet." << std::endl;
		return Player::quitPlaying;
	}
}
