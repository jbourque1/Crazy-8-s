#include "MainClass.h"

MainClass::MainClass()
{
}


MainClass::~MainClass()
{

}

int main()
{
	Deck * stockPile = new Deck(false);
	Player * player1 = new Player(stockPile);
	Player *player2 = new Player(stockPile);
	Deck * discardPile = new Deck(true);

	player1->showHand();


	system("pause");
	return 0;
}

