#pragma once
#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include "MainClass.h"
#include <string>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	void start();

	Deck stockPile = Deck(false);
	Deck discardPile = Deck(true);
};