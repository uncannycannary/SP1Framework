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
	int currFrame;
	bool lockinput;
	Graphics& console;
	int powerbarcolor;
	int introcolor;

	//animation stuff
	Directory file;
	Animations anim;
	std::vector<std::string> intro;
	std::vector<std::string> countdown;
	int introindex;
	int countdownindex;

	//my const

	const int InstructionsFrame;
	const int CountdownFrame;
	const int GameStartFrame;
	const int GameEndFrame;
	const int EndscreenFrame;
	const int PowerToPixelRatio;
	const int PowerToResistanceRatio;
	const int PowerIncrement;
	const int PowerbarPositionX;
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
	char returnscore();
};

#endif