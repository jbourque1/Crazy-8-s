#include "Deck.h"



Deck::Deck(bool empty)
{

	if (!empty)
	{
		for (int i = 0; i < 13; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				deck.push_back(new Card(i, j));
			}

		}
		shuffle();
	}

}


Deck::~Deck()
{
}

void Deck::shuffle()
{

	vector<Card*> temp;
	srand(time_t(NULL));
	int random;
	for (size_t i = 0; i < deck.size(); i++)
	{
		random = rand() * deck.size();
		temp.push_back(deck[random]);
		deck.erase(deck.begin()+random);
	}

	deck = temp;


}

void Deck::swap(Deck target)
{
	vector<Card*> temp;
	temp = deck;
	deck = target.deck;
	target.deck = temp;
}

void Deck::firstCard(Deck target)
{
	target.deck.push_back(deck[deck.size() - 1]);
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

Card * Deck::topCard()
{
	return deck[deck.size()-1];
}
