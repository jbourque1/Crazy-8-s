#include "Player.h"



Player::Player(Deck* deck)
{
	hand = new Hand();
	for (int i = 0; i < 7; i++)
	{
		hand->hand.push_back(deck->topCard());
		deck->delTop();
	}
}


Player::~Player()
{
}

void Player::showHand()
{
	vector<Card*> temp;
	int size, extra, rows;
	if (hand->hand.size() > 7)
	{
		size = hand->hand.size();
		extra = size % 7;
		size -= extra;
		rows = size / 7;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0 + (i * 7); j < ((i * 7) + 7); j++)
			{
				temp.push_back(hand->hand[j]);
			}
			Draw::drawRow(7, temp, i);
			cout << endl << endl << endl;
			for (int j = 0 ; j < 7; j++)
			{
				temp.pop_back();
			}
		}
		for (int i = size; i < size + extra; i++)
		{
			temp.push_back(hand->hand[i]);
		}
		Draw::drawRow(extra, temp, rows);
	}
	else
	{
		Draw::drawRow(hand->hand.size(), hand->hand, 0);
	}
}

bool Player::placeCard(int card, Deck* target)
{
	if (hand->hand[card]->getNum() == target->deck[target->deck.size() - 1]->getNum() ||
		hand->hand[card]->getSuit() == target->deck[target->deck.size() - 1]->getSuit())
	{
		target->deck.push_back(hand->hand[card]);
		hand->hand.erase(hand->hand.begin() + card);
		return true;
	}
	else if (hand->hand[card]->getNum() == "8")
	{
		playedEight(target);
		return true;
	}
}

void Player::playedEight(Deck* deck)
{
	system("cls");
	Draw::drawMiddle(deck->topCard());
	cout << endl << endl;
	Draw::drawChange();
}

bool Player::testWin()
{
	if (hand->hand.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
