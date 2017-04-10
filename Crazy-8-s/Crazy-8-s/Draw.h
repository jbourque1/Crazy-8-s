#pragma once
#include <iostream>
#include <string>
#include "Card.h"
using namespace std;
class Draw
{
public:
	Draw();
	~Draw();
		
	static void drawTop(int length);
	static void drawEmpty(int length, bool extra);
	static void drawNum(int length, int start);
	static void drawString(int length, string print);
	static void drawSingle(int spaces, bool odd, string print);
	static void drawRow(int length, vector<Card*> vec, int times);
	static void drawStart();
	static void drawMiddle(Card* card);
	static void drawCard(Card* card);
	static void drawCardE();
	static void drawChange();
	static void drawRules();
	static void drawHelp();

};

