#ifndef HandsItearator_h
#define HandsItearator_h

#include "Hand.h"
#include <vector>

namespace Blackjack
{
	class HandsIterator
	{//A Blackjack player.
		private:

		public:
			HandsIterator( std::vector<Hand>& hands );
			HandsIterator( Player& player );
			~HandsIterator();
			void first();
			void next();
			bool isDone() const;
			Hand currentItem() const;

		protected:
			Iterator();
	};
}

#endif /* HandsItearator_h */
