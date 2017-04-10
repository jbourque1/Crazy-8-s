#pragma once
#include <iostream>
#include <string>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Draw.h"
using namespace std;
class Player
{
public:
	Player(Deck *);
	~Player();
	void showHand();
	bool placeCard(int card, Deck* target);
	Card* playedEight(Card* card, Deck* deck);
	bool testWin();


	Hand * hand;
};

