#ifndef _FINDTWINS_H
#define _FINDTWINS_H

#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include "game.h"
#include "Framework\console.h"
#include "Animations.h"

class FindTwins
{
public:
	FindTwins(Graphics& console);
	~FindTwins();
	gamestate update();
	char returnscore();
private:
	//game variables
	Directory mainfolder;
	Graphics& console;
	Animations anim;
	int currframe;
	int score;
	int paused;
	bool wrong;
	bool lockinput;
	char rank;

	//picture variables
	const int numofpictures;
	Directory pics;
	std::wstring namepattern;
	std::vector<std::string> pictures;
	std::vector<bool> pictureans;
	bool userhasans;

	//state enum
	enum STATE
	{
		INTRO,
		SETPICTURE,
		QUESTION,
		SHOWANS,
		ENDSCREEN,
		MAXSTATE
	};
	STATE state;
	
	//const variables
	const int instructionsframe;
	const int countdownframe;
	const int gamestartframe;
	const int gameendframe;
	const int endscreenframe;

	//draw info
	std::vector<std::string> intro;
	std::vector<std::string> countdown;
	int introindex;
	int countdownindex;

	//functions
	void Draw();
	void UpdateState();
	void UpdatePictures();
	void DoUserInput();
	void ProcessAns(bool userans1, bool userans2, bool userans3);
};

#endif