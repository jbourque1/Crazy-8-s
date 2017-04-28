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
	string in;
	int numberPlayers;
	int playerInput;
	bool valid = true;;

	Deck* stockPile = new Deck(false);
	Deck* discardPile = new Deck(true);
	stockPile->firstCard(discardPile);
	Draw::drawStart();

	cout << "Enter the number of players (between 2 and 4): ";
	while (getline(cin, in)) 
	{
		if (isdigit(in[0]))
		{
			numberPlayers = stoi(in);
			if (numberPlayers >= 2 && numberPlayers <= 4)
			{
				break;
			}
		}
		system("cls");
		cout << "Invalid input. Enter the number of players (between 2 and 4): ";
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
		cout << endl << endl << endl << "                          ";
		cout << "Player " << i + 1 << ", it is your turn!";
		cout << endl << "                          ";
		system("pause");
		while (true)
		{
			system("cls");
			cout << endl << endl << "                                   ";
			cout << "Player " << i + 1 << endl << endl;
			Draw::drawMiddle(discardPile->topCard());
			players[i]->showHand();           // loop for each players turn

			cout << endl << "Pick a card, or enter 0 to show other commands.\nInput: ";

			while(getline(cin, in))
			{
				if (isdigit(in[0]))
				{
					playerInput = stoi(in);
					if (playerInput == 0 || playerInput <= players[i]->hand->hand.size())
					{
						break;
					}
				}
				system("cls");
				cout << endl << endl << "                                   ";
				cout << "Player " << i + 1 << endl << endl;
				Draw::drawMiddle(discardPile->topCard());
				players[i]->showHand();
				cout << endl << "Invalid input. Pick a card, or enter 0 to show other commands.\nInput: ";
			}

			if (playerInput == 0)
			{
				system("cls");
				cout << "Commands:" << endl;
				cout << "1: Draw a card." << endl;
				cout << "2: Show rules." << endl << endl;
				while (getline(cin, in))
				{
					if (isdigit(in[0]))
					{
						playerInput = stoi(in);
						if (playerInput == 1 || playerInput == 2)
						{
							break;
						}
					}
					system("cls");
					cout << "Commands:" << endl;
					cout << "1: Draw a card." << endl;
					cout << "2: Show rules." << endl << endl;
					cout << endl << "Invalid input.\nInput: ";
				}
				if (playerInput == 1)
				{
					if (stockPile->deck.size() == 0)
					{
						stockPile->swap(discardPile);

						if (stockPile->deck.size() == 0)
						{
							if (players[i]->posibilities(discardPile))
							{
								system("cls");
								cout << "The deck is empty, but you still have a card you can play in your hand." << endl;
								system("pause");
								continue;
							}
							else
							{
								system("cls");
								cout << "The deck is empty, and you have no cards you can play.\nYour turn has been skipped." << endl;
								system("pause");
								break;
							}
						}
					}
					players[i]->drawCard(stockPile);
					system("cls");
					continue;
				}
				else if (playerInput == 2)
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
			break;
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