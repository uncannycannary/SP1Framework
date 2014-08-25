#ifndef _TABLEFLIP_H
#define _TABLEFLIP_H

#include <iostream>
#include <iomanip>
#include "Graphics.h"
#include "game.h"
#include "Framework\console.h"
#include "Framework\timer.h"
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

class TableFlip
{
public:
	gamestate updateTableFlip(Graphics* console);
	void resetTableFlip();
	TableFlip()
	{
		left = 0;
		right = 0;
		checkleft = 0;
		checkright = 0;
		CurrentFramePerSec = 0;
		GameStarts = false;
		gameends = false;
		countframe = 210;
	}
	~TableFlip()
	{
	}
private:
	void drawTableFlip(Graphics* TableFlip);
	void playTableFlip();
	int left;
	int right;
	int checkleft;
	int checkright;
	int CurrentFramePerSec;
	int countframe;
	bool GameStarts;
	bool gameends;
};

#endif