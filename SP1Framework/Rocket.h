#ifndef _ROCKET_H
#define _ROCKET_H

#include "game.h"
#include "Framework\console.h"
#include "Graphics.h"
#include <fstream>
#include <string>

class pumprocket
{
private:
	int CurrentFrame;
	bool pushed;
	int time;
	int score;
	int y;
	int move;
	char rank;
	std::ifstream up, down, spark, rocket;
	std::string ups, downs, sparks, rockets;
	Graphics& console;
	
public:
	gamestate update();
	void play();
	void read();
	void draw();
	pumprocket(Graphics&);
	char returnscore();
};
#endif