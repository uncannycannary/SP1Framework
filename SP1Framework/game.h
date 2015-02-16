#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Directory.h"
#include "Sound.h"
#include "TableFlip.h"
#include "Scream.h"
#include "subgame.h"
#include "Spotted.h"
#include "Rocket.h"
#include "IKR.h"
#include "Photospam.h"
#include "FindTwins.h"
#include "candy.h"
#include "highscore.h"
#include "Framework\console.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MainMenu.h"
#include"ToiletRoll.h"
#include "Graphics.h"

class Game
{
public:
	Game::Game();
	Game::~Game();
	bool Update(double dt);
	void Render();
private:
	Graphics console;
	highscore score;
	MainMenu mainmenu;

	gamestate state;

	IKR* icekan;
	Spotted* spot;
	TableFlip* flip;
	Scream* scream;
	toiletroll* toilet;
	photospam* spam;
	FindTwins* twins;
	subgame* submarine;
	Candy* candy;
	pumprocket* rocket;
};

#endif // _GAME_H