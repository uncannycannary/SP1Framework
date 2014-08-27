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
	gamestate Update();
private:
	//game variables
	Graphics& console;
	Animations anim;
	int currframe;
	int score;
	int paused;
	//picture variables and enums
	enum PICTURES
	{
		HAND,
		FOOT,
		TOTAL_PICTURES
	};
	PICTURES picture1state;
	PICTURES picture2state;
	PICTURES picture3state;
	bool picture1ans;
	bool picture2ans;
	bool picture3ans;
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
	const int showansduration;
	const int picture1positionx;
	const int picture2positionx;
	const int picture3positionx;
	const int picturepositiony;
	const int pictureheight;
	const int positionpictureduration;
	const int positionpicture;


	//draw info
	std::vector<std::string> intro;
	std::string background;
	std::vector<std::string> pictures;
	int picture1index;
	int picture2index;
	int picture3index;

	//functions
	void Draw();
	void UpdateState();
	void UpdatePictures();
	void DoUserInput();
	void UpdateAnimations();
};

#endif