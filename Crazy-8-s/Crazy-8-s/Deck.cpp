#include "Deck.h"



Deck::Deck(bool empty)
{

	if (!empty)
	{
		for (int i = 1; i <= 13; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				deck.push_back(new Card(i, j));
			}

		}
		shuffleInc(10);
	}

}


Deck::~Deck()
{
}

void Deck::shuffle()
{

	vector<Card*> temp;
	int random, start;
	start = deck.size();
	for (size_t i = 0; i < start; i++)
	{
		srand(time(NULL));
		random = rand() % deck.size();
		temp.push_back(deck[random]);
		deck.erase(deck.begin()+random);
	}

	deck = temp;

}

void Deck::swap(Deck* target)
{
	vector<Card*> temp;
	Card* top = target->topCard();
	target->delTop();
	temp = deck;
	deck = target->deck;
	target->deck = temp;
	target->deck.push_back(top);
}

void Deck::shuffleInc(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		shuffle();
	}
}

void Deck::delTop()
{
	deck.pop_back();
}

void Deck::firstCard(Deck* target)
{
	target->deck.push_back(topCard());
	deck.pop_back();

}

bool Deck::isEmpty()
{
	if(deck.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Card* Deck::topCard()
{
	return deck[deck.size()-1];
}
