#ifndef _PHOTOSPAM_H
#define _PHOTOSPAM_H

#include "game.h"
#include "Framework\console.h"
#include "Graphics.h"
#include <fstream>
#include <string>
#include <time.h>

class photospam
{
private:
	int CurrentFrame;
	int a;
	int b;
	int c;
	bool wrong;
	int score;
	int set;
	std::ifstream diamond, poop, snap, cross,box;
	std::string diamonds, poops, snaps, crosss,boxs;
	Graphics& console;

public:
	gamestate update(int& gamescore);
	void play();
	void read();
	void draw();
	photospam(Graphics&);
};
#endif