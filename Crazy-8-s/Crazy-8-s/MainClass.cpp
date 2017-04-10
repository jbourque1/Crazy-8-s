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
	Draw::drawMiddle(discardPile->topCard());
	cout << endl << endl;
	player1->showHand();

	system("pause");
	return 0;
}

