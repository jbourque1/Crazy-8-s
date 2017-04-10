#include "Draw.h"



Draw::Draw()
{
}


Draw::~Draw()
{
}

void Draw::drawTop(int length)
{
	cout << " ";
	for (int i = 0; i < length; i++)
	{
		cout << "-----------";
	}
	cout << "-" << endl << " ";
}

void Draw::drawEmpty(int length, bool extra)
{
	for (int i = 0; i < length; i++)
	{
		cout << "|          ";
	}
	if (extra)
	{
		cout << "|" << endl << " ";
	}
	else
	{
		cout << "|" << endl;
	}
}

void Draw::drawNum(int length, int start)
{
	int tempSpaces;
	bool odd;


	for (int i = 0; i < length; i++)
	{
		if (start < 10)
		{
			tempSpaces = 3;
			odd = true;
		}
		else
		{
			tempSpaces = 3;
			odd = false;
		}

		cout << "|";

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		cout << "(" << start + i + 1 << ")";

		if (start + i + 1 >= 10)
			odd = false;

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		if (odd)
		{
			cout << " ";
		}
	}
	cout << "|" << endl << " ";
}

void Draw::drawString(int length, string print)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "|";
		cout << "    ";
		cout << print;
		cout << "    ";
	}
	cout << "|" << endl << " ";
}

void Draw::drawSingle(int spaces, bool odd, string print)
{
	cout << "|";

	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}

	cout << print;

	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}

	if (odd)
	{
		cout << " ";
	}
}

void Draw::drawRow(int length, vector<Card*> vec, int times)
{
	int tempSpaces;
	bool odd;

	drawTop(length);
	drawEmpty(length, true);
	drawNum(length, times * 7);
	drawEmpty(length, true);
	for (int i = 0; i < length; i++)
	{
		tempSpaces = 10 - vec[i]->getNum().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		drawSingle(tempSpaces, odd, vec[i]->getNum());
	}
	cout << "|" << endl << " ";
	drawString(length, "of");
	for (int i = 0; i < length; i++)
	{
		tempSpaces = 10 - vec[i]->getSuit().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		drawSingle(tempSpaces, odd, vec[i]->getSuit());
	}
	cout << "|" << endl << " ";
	drawEmpty(length, true);
	drawEmpty(length, false);
	drawTop(length);
}

void Draw::drawStart()
{
	drawTop(7);
	 cout << "|                                                                            |" << endl;
	cout << " |                                                                            |" << endl;
	cout << " |        0 0 0      0 0 0           0          0 0 0 0 0      0     0        |" << endl;
	cout << " |       0           0     0        0 0               0         0   0         |" << endl;
	cout << " |      0            0  0 0        0   0            0            0 0          |" << endl;
	cout << " |       0           0    0       0 0 0 0         0               0           |" << endl;
	cout << " |        0 0 0      0     0     0       0      0 0 0 0 0         0           |" << endl;
	cout << " |                                                                            |" << endl;
	cout << " |                                                                            |" << endl;
	cout << " |                           0 0 0   0     0 0 0                              |" << endl;
	cout << " |                          0     0   0   0                                   |" << endl;
	cout << " |                           0 0 0          0 0                               |" << endl;
	cout << " |                          0     0             0                             |" << endl;
	cout << " |                           0 0 0         0 0 0                              |" << endl;
	cout << " |                                                                            |" << endl;
	cout << " |                                                                            |" << endl;
	cout << " |         By: James Bourque, Brian Dansereau, and Noah LeVangie              |" << endl;
	drawTop(7);

	cout << endl << endl;
	cout << "                        Press ENTER to start..." << std::flush;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Draw::drawMiddle(Card * card)
{
	int tempSpaces;
	bool odd;
		cout << "                         ";
		cout << "------------" << "   " << "------------" << endl << "                         ";
		cout << "|          |" << "   " << "|          |" << endl << "                         ";
		cout << "|          |" << "   " << "|          |" << endl << "                         ";
		cout << "|   D      |" << "   " << "|          |" << endl << "                         ";
		cout << "|    E     |" << "   ";

		tempSpaces = 10 - card->getNum().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		cout << "|";

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		cout << card->getNum();

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		if (odd)
		{
			cout << " ";
		}
		cout << "|" << endl << " ";

		cout << "                        |     C    |" << "   ";
		cout << "|";
		cout << "    ";
		cout << "of";
		cout << "    ";

		cout << "|" << endl << " ";

		cout << "                        |      K   |" << "   ";

		tempSpaces = 10 - card->getSuit().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		cout << "|";

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		cout << card->getSuit();

		for (int i = 0; i < tempSpaces; i++)
		{
			cout << " ";
		}

		if (odd)
		{
			cout << " ";
		}
		cout << "|" << endl << " ";
		
		cout << "                        |          |" << "   " << "|          |" << endl << " ";
		cout << "                        |          |" << "   " << "|          |" << endl << " ";
		cout << "                        ------------" << "   " << "------------" << endl << " ";

		cout << endl << endl;
}

void Draw::drawCard(Card * card)
{
	int tempSpaces, odd;
	drawTop(1);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	tempSpaces = 10 - card->getNum().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		drawSingle(tempSpaces, odd, card->getNum());
		cout << "|" << endl << " ";
		drawString(1, "of");
		tempSpaces = 10 - card->getSuit().size();
		if (tempSpaces % 2 == 0)
		{
			tempSpaces /= 2;
			odd = false;
		}
		else
		{
			tempSpaces -= 1;
			tempSpaces /= 2;
			odd = true;
		}
		drawSingle(tempSpaces, odd, card->getSuit());
		cout << "|" << endl << " ";
		drawEmpty(1, true);
		drawEmpty(1, false);
		drawTop(1);

}

void Draw::drawCardE()
{
	drawTop(1);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, true);
	drawEmpty(1, false);
	drawTop(1);
}
