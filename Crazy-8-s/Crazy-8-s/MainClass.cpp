#include "MainClass.h"

MainClass::MainClass()
{
}


MainClass::~MainClass()
{

}

int main()
{
	Game game = Game();
	Player player1 = Player(game.stockPile);
	Player player2 = Player(game.stockPile);
	system("pause");
	return 0;
}

