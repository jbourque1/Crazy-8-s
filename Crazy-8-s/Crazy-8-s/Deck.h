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
	void shuffle();
	void swap(Deck* target);
	void delTop();
	void firstCard(Deck* target);
	bool isEmpty();
	Card* topCard();

	vector<Card*> deck;

private:

};
