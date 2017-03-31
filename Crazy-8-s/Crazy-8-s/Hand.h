#pragma once
#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "MainClass.h"
#include <string>
#include <vector>
using namespace std;

class Hand
{
public:
	Hand();
	~Hand();
	void draw(Deck target);
	bool testWin(Hand target);

	vector<Card*> hand;
};

