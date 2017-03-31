#pragma once
#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "MainClass.h"
#include <string>
using namespace std;
class Player
{
public:
	Player(Deck deck);
	~Player();
	void showHand();
	void placeCard(int card, Deck target);

	Hand hand = Hand();
};

