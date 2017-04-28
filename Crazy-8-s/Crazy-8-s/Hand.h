#pragma once
#include <iostream>
#include "Card.h"
#include <vector>
using namespace std;

class Hand
{
public:
	Hand();
	~Hand();

	vector<Card*> hand;
};

