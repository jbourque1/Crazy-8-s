#include "MainClass.h"

MainClass::MainClass()
{
}


MainClass::~MainClass()
{

}

int main()
{
	vector<Player*> players;
	int numberPlayers;
	Deck* stockPile = new Deck(false);
	Deck* discardPile = new Deck(true);
	Draw::drawStart();

	cout << "Enter the number of players (between 2 and 4): ";
	cin >> numberPlayers;
	system("cls");

	Draw::drawRules();

	for (int i = 0; i < numberPlayers; i++)
	{
		players.push_back(new Player(stockPile));
	}

	Draw::drawStart();
	Draw::drawMiddle(discardPile->topCard());

	for (int j = 0; j < numberPlayers; j++)
	{
		players[j]; // loop for each players turn
			// use goto or set j = 0 to return to player 1
	}

	system("pause");
	return 0;
}