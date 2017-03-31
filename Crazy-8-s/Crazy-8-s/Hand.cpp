#include "Hand.h"



Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::draw(Deck target)
{
	hand.push_back(target.deck[target.deck.size() - 1]);
	target.deck.pop_back();
}

bool Hand::testWin(Hand target)
{
	if (target.hand.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
