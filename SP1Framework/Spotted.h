#ifndef _SPOTTED_H
#define _SPOTTED_H

#include <iostream>
#include <iomanip>
#include "Graphics.h"
#include "Framework\console.h"
#include "highscore.h"

class Spotted
{
public:
	gamestate updateSpotted(Graphics* console);
	void resetSpotted();
	Spotted()
	{
		CurrentFramePerSec = 0;
		GameStarts = false;
		gameends = false;
		Guard = false;
		moving = false;
		score = 0;
		step = 0;
		Escapee = 0;
		checkalert = 0;
		checkEscapee = Escapee%2;
		rank = 'F';
	}
	~Spotted()
	{
	}
	char returnscore();
private:
	void drawSpotted(Graphics* Spotted);
	void playSpotted();
	int CurrentFramePerSec;
	bool Guard;
	bool GameStarts;
	bool gameends;
	bool moving;
	int Escapee;
	int score;
	int checkEscapee;
	int step;
	int checkalert;
	char rank;
};

#endif 