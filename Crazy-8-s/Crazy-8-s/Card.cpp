#include "Card.h"



Card::Card(int num, int suit)
{
	cardNum = num;
	cardSuit = suit;
}


Card::~Card()
{
}

string Card::getSuit()
{
	return suit[cardSuit];
}

string Card::getNum()
{
	return num[cardNum];
}
