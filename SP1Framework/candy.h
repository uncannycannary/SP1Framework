#ifndef _CANDY_H
#define _CANDY_H

#include <string>
#include "game.h"
#include "Framework\console.h"
#include "Animations.h"
#include <time.h>

class Candy
{
public:
	gamestate update(Graphics* console);
	Candy()
		:
	CandyFile(L"candy\\",L"*.txt")
	{
		GameStarts = false;
		gameends = false;
		jarfull = false;
		overflow = false;
		checkjar = 0;
		penalty = 0;
		CurrentFramePerSec = 0;
		candies = 0;
	}
	~Candy()
	{
	}
private:
	void draw(Graphics* candy);
	void play();
	bool jarfull;
	bool overflow;
	int candies;
	int CurrentFramePerSec;
	int checkframe;
	Directory CandyFile;
	bool GameStarts;
	bool gameends;
	int checkjar;
	int penalty;
};

#endif