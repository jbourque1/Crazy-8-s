#include "MainClass.h"

MainClass::MainClass()
{
}


MainClass::~MainClass()
{

}

int main()
{
	Deck* stockPile = new Deck(false);
	Player* player1 = new Player(stockPile);
	Deck* discardPile = new Deck(true);

	stockPile->firstCard(discardPile);

	Draw::drawStart();
	Draw::drawMiddle(discardPile->topCard());
	player1->showHand();

	system("pause");
	return 0;
}

int main()
{
	vector<Player*> players;
	int numberPlayers;
	int playerInput;

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
		players[j]->showHand();           // loop for each players turn
		system("cls");		// use goto or set j = 0 to return to player 1

		cout << "Pick a card, or enter 0 for help.";
		cin >> playerInput;

		if (playerInput == 0)
		{
			Draw::drawRules();
		}
		else
		{
			players[j]->placeCard(playerInput - 1, discardPile);
		}
	}

	system("pause");
	return 0;
}