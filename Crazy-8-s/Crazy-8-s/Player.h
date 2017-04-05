#pragma once
#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Draw.h"
//#include "MainClass.h"
#include <string>
using namespace std;
class Player
{
public:
	Player(Deck *);
	~Player();
	void showHand();
	void placeCard(int card, Deck* target);
	bool testWin();


	Hand * hand;
};

