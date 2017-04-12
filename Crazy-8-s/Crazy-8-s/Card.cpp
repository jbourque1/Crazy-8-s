#include "Card.h"



Card::Card(int num, int suit)
{
	cardNum = num;
	cardSuit = suit;
	firstSuit = suit;
}


Card::~Card()
{
}

string Card::getSuit()
{
	return suit[cardSuit - 1];
}

int Card::getFirst()
{
	return firstSuit;
}

string Card::getNum()
{
	return num[cardNum - 1];
}

void Card::changeSuit(int suit)
{
	cardSuit = suit;
}
