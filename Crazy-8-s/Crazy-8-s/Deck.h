#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include <math.h>
#include <time.h>
#include <string>
using namespace std;

class Deck
{
public:
	Deck(bool empty);
	~Deck();
	void swap(Deck* target);
	void shuffleInc(int amount);
	void delTop();
	void firstCard(Deck* target);
	bool isEmpty();
	Card* topCard();

	vector<Card*> deck;

private:

	void shuffle();

};
