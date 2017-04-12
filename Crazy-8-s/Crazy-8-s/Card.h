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
	int getFirst();
	string getNum();
	void changeSuit(int suit);

private:

	int cardNum, cardSuit, firstSuit;
	vector<string> num = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
	vector<string> suit = { "Hearts", "Diamonds", "Spades", "Clubs"};
	
};

