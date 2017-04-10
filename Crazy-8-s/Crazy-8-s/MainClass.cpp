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
	int playerInput;

	Deck* stockPile = new Deck(false);
	Deck* discardPile = new Deck(true);
	stockPile->firstCard(discardPile);
	Draw::drawStart();

	cout << "Enter the number of players (between 2 and 4): ";
	cin >> numberPlayers;
	system("cls");

	Draw::drawRules();

	for (int i = 0; i < numberPlayers; i++)
	{
		players.push_back(new Player(stockPile));
	}

loopStart:

	for (int j = 0; j < numberPlayers; j++)
	{
	loopTop:

		Draw::drawMiddle(discardPile->topCard());
		players[j]->showHand();           // loop for each players turn

		cout << endl << "Pick a card, or enter 0 for help.";
		cin >> playerInput;

		if (playerInput == 0)
		{
			system("cls");
			Draw::drawRules();
			goto loopTop;
		}
		else
		{
			if (!players[j]->placeCard(playerInput - 1, discardPile))
			{
				system("cls");
				cout << "The Card you tried to place is an invalid move. If you need help enter 0." << endl << endl;
				system("pause");
				system("cls");
				goto loopTop;
			}
			else
			{
				system("cls");
			}
		}
	}
	goto loopStart;

	system("pause");
	return 0;
}