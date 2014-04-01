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
			~HandsIterator();
			void first();
			void next();
			bool isDone() const;
			Hand currentItem() const;
	};
}

#endif /* HandsItearator_h */
