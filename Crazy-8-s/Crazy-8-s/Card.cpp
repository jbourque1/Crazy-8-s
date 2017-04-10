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
	return suit[cardSuit - 1];
}

string Card::getNum()
{
	return num[cardNum - 1];
}

void Card::changeSuit(int suit)
{
	cardSuit = suit;
}
