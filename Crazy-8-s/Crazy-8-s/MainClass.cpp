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
	bool valid = true;;

	Deck* stockPile = new Deck(false);
	Deck* discardPile = new Deck(true);
	stockPile->firstCard(discardPile);
	Draw::drawStart();

	cout << "Enter the number of players (between 2 and 4): ";
	cin >> numberPlayers;
	cin.clear();
	while (valid)
	{
		if (numberPlayers < 2 || numberPlayers > 4 || numberPlayers == NULL)
		{
			cout << " That is an invalid number of players. Enter the number of players (between 2 and 4): ";
			cin >> numberPlayers;
			cin.clear();
		}
		else
		{
			break;
		}
	}
	system("cls");

	Draw::drawRules();

	for (int i = 0; i < numberPlayers; i++)
	{
		players.push_back(new Player(stockPile));
	}

	int i = 0;

	while(i < numberPlayers)
	{
		system("cls");
		cout << "Player " << i + 1 << ", it is your turn!";
		cout << endl;
		system("pause");
		system("cls");
		Draw::drawMiddle(discardPile->topCard());
		players[i]->showHand();           // loop for each players turn

		cout << endl << "Pick a card, or enter 0 to show other commands.\nInput: ";
		cin >> playerInput;

	//change player input to type char
		//players[i]->testInput(playerInput, players[i]->hand->hand.size(), 1); // test
	
		if (playerInput == 0)
		{
			system("cls");
			cout << "Commands:" << endl;
			cout << "1: Draw a card." << endl;
			cout << "2: Pass turn." << endl;
			cout << "3: Show rules." << endl;
			cin >> playerInput;
			if (playerInput == 1)
			{
				if (stockPile->deck.size() == 0)
				{
					stockPile->swap(discardPile);
				}
				players[i]->drawCard(stockPile);
				system("cls");
				continue;
			}
			else if (playerInput == 2)
			{
				i++;
				system("cls");
				continue;
			}
			else if (playerInput == 3)
			{
				system("cls");
				Draw::drawRules();
				system("cls");
				continue;
			}	
		}
		else
		{
			if (!players[i]->placeCard(playerInput - 1, discardPile))
			{
				system("cls");
				cout << "The Card you tried to place is an invalid move. If you need help enter 0." << endl << endl;
				system("pause");
				system("cls");
				continue;
			}
			else
			{
				system("cls");
				Draw::drawMiddle(discardPile->topCard());
				cout << endl << endl << endl;
				cout << "                         ";
				cout << "Player " << i + 1 << " placed the " << discardPile->topCard()->getNum() << " of " << discardPile->topCard()->getSuit() << ".";
				cout << endl << "                         ";
				system("pause");
				system("cls");
			}
		}

		if (players[i]->testWin())
		{
			system("cls");
			cout << "Player " << i + 1 << " is the winner!!!!!!!!!";
			break;
		}
		if (i < numberPlayers - 1)
		{
			i++;
		}
		else
		{
			i = 0;
		}
	}

	system("pause");
	return 0;
}