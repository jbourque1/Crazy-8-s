#include "Player.h"



Player::Player(Deck deck)
{
	hand.draw(deck);
}


Player::~Player()
{
}

void Player::showHand()
{
	int tempSpaces;
	Card* tempCard;
	for (size_t i = 0; i < hand.hand.size(); i++)
	{
		tempCard = hand.hand[i];
		cout << "___________" << endl;
		cout << "|          " << endl;
		tempSpaces = (10 - (int)size(tempCard->getNum())) / 2;
		cout << "|";
		for (int j = 0; j < tempSpaces; j++)
		{
			cout << " ";
		}
		if (tempSpaces % 2 != 0)
		{
			cout << " ";
		}
		cout << tempCard->getNum();
		for (int j = 0; j < tempSpaces; j++)
		{
			cout << " ";
		}
		cout << endl;
		cout << "|    of    " << endl;
		tempSpaces = (10 - (int)size(tempCard->getSuit())) / 2;
		cout << "|";
		for(int j = 0; j < tempSpaces; j++)
		{
			cout << " ";
		}
		cout << tempCard->getSuit();
		for (int j = 0; j < tempSpaces; j++)
		{
			cout << " ";
		}
		if (tempSpaces % 2 != 0)
		{
			cout << " ";
		}
		cout << endl;
		cout << "|          " << endl;
		cout << "___________";
	}
	for (int i = 0; i < 7; i++)
		cout << "|" << endl;
}

void Player::placeCard(int card, Deck target)
{
	target.deck.push_back(hand.hand[card]);
	hand.hand.erase(hand.hand.begin() + card);
}
