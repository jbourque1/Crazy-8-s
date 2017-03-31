#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Card
{
public:
	Card(int num, int suit);
	~Card();
	string getSuit();
	string getNum();

private:

	int cardNum, cardSuit;
	vector<string> num = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
	vector<string> suit = { "Diamonds", "Hearts", "Spades", "Clubs"};
};

