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
	int introindex;
	bool gameends;
	bool paused;
	int power;
	int currFrame;
	bool lockinput;
	Graphics& console;
	int powerbarcolor;

	//animation stuff
	Directory file;
	Animations anim;
	std::vector<std::string> intro;

	//my const
	const int EndscreenFrame;
	const int InstructionsFrame;
	const int GameStartFrame;
	const int GameEndFrame;
	const int PowerToPixelRatio;
	const int PowerToResistanceRatio;
	const int PowerIncrement;
	const int PowerbarPositionXTop;
	const int PowerbarPositionXBottom;
	const int PowerbarPositionY;
	const int drawPauseX;
	const int drawPauseY;

	//functions
	void UpdatePowerbar();
	void draw();
	void changestate();
	void DoUserInput();
public:
	Scream(Graphics& console);
	~Scream();
	gamestate update();
};

#endif