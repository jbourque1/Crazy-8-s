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

	Draw::drawStart();

	system("pause");
	return 0;
}

