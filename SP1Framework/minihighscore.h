#ifndef _MINIHIGH_H
#define _MINIHIGH_H

#include "game.h"
#include "Framework\console.h"
#include "Graphics.h"
#include <fstream>
#include <string>
#include <time.h>

using std::string;

class minihigh
{
private:
	Directory judgement;
 	gamestate* state;
	Graphics& console;
	string score;
	string rank; 
	string comment;
public:
	gamestate update();
	minihigh(gamestate* state)
		:
	judgement(L"judgement\\",L"*.txt"),state(state), console(console)
	{
	  
	}
	~minihigh()
	{
	}
	gamestate read();
	void draw();
};

#endif