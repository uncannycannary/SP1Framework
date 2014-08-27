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

	//animation stuff
	Animations anim;
	std::vector<std::string> Intro;
	std::vector<std::string> Dovakin;
	std::vector<std::string> Dragon;
	std::vector<std::string> Dovakin_kills_dragon;
	std::string endscreen;
	std::string powerbar;

	//my const
	const int EndscreenFrame;
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
	enum animnames
	{
		INTRO,
		DOVAKIN,
		DRAGON,
		DOVAKIN_KILLS_DRAGON,
		TOTALANIM
	};

	//functions
	void UpdatePowerbar();
	void draw();
	void DoUserInput();
	void UpdateAnim();
public:
	Scream(Graphics& console);
	~Scream();
	gamestate update();
};

#endif