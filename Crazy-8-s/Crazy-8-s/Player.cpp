#include "Player.h"



Player::Player(Deck* deck)
{
	hand = new Hand();
	for (int i = 0; i < 25; i++)
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
		if (extra != 0)
		{
			Draw::drawRow(extra, temp, rows);
		}
	}
	else
	{
		Draw::drawRow(hand->hand.size(), hand->hand, 0);
	}
}

bool Player::placeCard(int card, Deck* target)
{


	if (hand->hand[card]->getNum() == "8")
	{
		target->topCard()->changeSuit(target->topCard()->getFirst());
		target->deck.push_back(playedEight(hand->hand[card], target));
		hand->hand.erase(hand->hand.begin() + card);
		return true;
	}
	else if (hand->hand[card]->getNum() == target->deck[target->deck.size() - 1]->getNum() ||
		hand->hand[card]->getSuit() == target->deck[target->deck.size() - 1]->getSuit())
	{
		target->topCard()->changeSuit(target->topCard()->getFirst());
		target->deck.push_back(hand->hand[card]);
		hand->hand.erase(hand->hand.begin() + card);
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::posibilities(Deck * target)
{
	for (int i = 0; i < hand->hand.size(); i++)
	{
		if (hand->hand[i]->getNum() == target->topCard()->getNum() || hand->hand[i]->getSuit() == target->topCard()->getSuit() || hand->hand[i]->getNum() == "8")
		{
			return true;
		}
	}
	return false;
}

void Player::drawCard(Deck* target)
{
	hand->hand.push_back(target->topCard());
	target->delTop();
}

Card* Player::playedEight(Card* card, Deck* deck)
{
	int change;
	system("cls");
	Draw::drawMiddle(deck->topCard());
	cout << endl << endl;
	Draw::drawChange();
	cout << endl;
	cout << "Choose a suit. (Input the number above the suit you want) Suit: ";
	cin >> change;
	card->changeSuit(change);
	return card;

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

/*int Player::testInput(char input, int max, int min) // test
{
	bool valid = false;

	const char* temp = &input;

	if (isdigit(input) == true)
	{
		atoi(temp);
		if (input < max || input >= min)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
	}
	else if (isalpha(input) == true)
	{
		valid = false;
	}

	if (valid == true)
	{
		return input; // change ascii to int and return int value
	}
	else
	{
		system("cls");
		cout << "Enter a valid input" << endl;
		system("pause");
	}
}*/

