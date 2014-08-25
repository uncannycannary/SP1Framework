#ifndef _SCREAM_H
#define _SCREAM_H

#include "game.h"
#include "Framework\console.h"
#include "Graphics.h"
#include "Animations.h"

class Scream
{
private:
	//variables
	bool gameends;
	bool paused;
	int power;
	int resistance;
	int currFrame;
	Graphics& console;
	//functions
	bool play();

public:
	Scream(Graphics& console);
	~Scream();
	Animations anim;
	gamestate update();
	void draw();
	std::vector<std::string> someanim;
};

#endif