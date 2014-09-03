#ifndef _CANDY_H
#define _CANDY_H

#include "game.h"
#include "Framework\console.h"
#include "Graphics.h"
#include <fstream>
#include <string>

class Candy
{
private:
	int CurrentFrame;
	int candy;
	int time;
	int score;
	int twosec;
	bool triger;
	char rank;
	std::ifstream reader;
	std::string j0, j1, j2, j3, j4, j5, j6, j7;
	Graphics& console;

public:
	char returnscore();
	gamestate update();
	void read();
	void play();
	void draw();
	Candy(Graphics&);
};

#endif