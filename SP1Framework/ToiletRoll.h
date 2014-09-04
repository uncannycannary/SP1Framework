#ifndef _TOILETROLL_H
#define _TOILETROLL_H

#include "Framework\console.h"
#include "Graphics.h"
#include <fstream>
#include <string>

class toiletroll
{
private:
	int CurrentFrame;
	bool rhold;
	int rholdcount;
	bool lhold;
	int lholdcount;
	int y;
	int rx;
	int lx;
	int score;
	char rank;
	std::ifstream tr, rh, lh;
	std::string trs, rhs, lhs;
	Graphics& console;

public:
	gamestate update();
	void play();
	void read();
	void draw();
	toiletroll(Graphics&);
	char returnscore();
};


#endif