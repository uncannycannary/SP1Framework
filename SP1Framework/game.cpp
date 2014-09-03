// This is the main file for the game logic and function
//
//
#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MainMenu.h"
#include"ToiletRoll.h"
#include "Graphics.h"
#include "TableFlip.h"
#include "Scream.h"
#include "subgame.h"
#include "Spotted.h"
#include "Rocket.h"
#include "IKR.h"
#include "Photospam.h"
#include "FindTwins.h"
#include "candy.h"
#include "Credits.h"

Graphics console;
highscore score(console);

//Create a pointer to store the location of the scream object
IKR* icekan;
Spotted* spot;
TableFlip* flip;
Scream* scream;
toiletroll* toilet;
photospam* spam;
FindTwins* twins;
subgame* submarine;
Candy* candy;
Credits credit(&console);
pumprocket* rocket;
gamestate state = INTRO;
void init()
{
	srand(time(NULL));
	updateinput();
	ini();

	//credit = NULL:
	scream = NULL;
	toilet = NULL;
	spam = NULL;
	flip = NULL;
	spot = NULL;
	twins = NULL;
	submarine = NULL;
	candy = NULL;
	rocket = NULL;
	icekan = NULL;
}

void shutdown()
{
}

void update(double dt)
{
	updateinput();
	switch(state)
	{
	case INTRO:
		state = Intro(console);
		break;
	case MAIN_MENU:
		state = MainMenu(console,&score);
		break;
	case GAME_SELECT:
		state = GameSelect(console);
		break;
	case TABLE_FLIP:
		if(flip == NULL)
		{
			flip = new TableFlip;
		}

		state = flip->updateTableFlip(&console);

		if(state != TABLE_FLIP)
		{
			score.addscore(flip->returnscore());
			delete flip;
			flip = NULL;
		}
		break;
	case SUBMARINE:
		if(submarine == NULL)
		{
			submarine = new subgame(&console);
		}
		state = submarine->playsubgamemain();
		if(state != SUBMARINE)
		{
			score.addscore(submarine->returnscore());
			delete submarine;
			submarine = NULL;
		}
		break;
	case TOILET_ROLL:
		if(toilet == NULL)
		{
			
			toilet = new toiletroll(console);
		}

		state = toilet->update();

		if(state != TOILET_ROLL)
		{
			score.addscore(toilet->returnscore());
			delete toilet;
			toilet = NULL;
		}
		break;
	case ICECHAN:
		if(icekan == NULL)
		{
			icekan = new IKR(&console);
		}
		state = icekan->playIKRgame();

		if(state != ICECHAN)
		{
			score.addscore(icekan->returnscore());
			delete icekan;
			icekan = NULL;
		}
		break;
	case SCREAM:
		if(scream == NULL)
		{
			scream = new Scream(console);
		}

		state = scream->update();

		if(state != SCREAM)
		{
			score.addscore(scream->returnscore());
			delete scream;
			scream = NULL;
		}
		break;
	case SPOTTED:
		if(spot == NULL)
		{
			spot = new Spotted;
		}

		state = spot->updateSpotted(&console);

		if(state != SPOTTED)
		{
			score.addscore(spot->returnscore());
			delete spot;
			spot = NULL;
		}
		break;
	case FIND_TWINS:
		if(twins == NULL)
		{
			twins = new FindTwins(console);
		}

		state = twins->update();

		if(state != FIND_TWINS)
		{
			score.addscore(twins->returnscore());
			delete twins;
			twins = NULL;
		}
		break;
	case PHOTOSPAM:
		if(spam == NULL)
		{
			spam = new photospam(console);
		}
		
		state = spam->update();

		if(state != PHOTOSPAM)
		{
			score.addscore(spam->returnscore());
			delete spam;
			spam = NULL;
		}
		break;
	case ROCKET:
		if(rocket == NULL)
		{
			rocket = new pumprocket(console);
		}

		state = rocket->update();

		if(state != ROCKET)
		{
			score.addscore(rocket->returnscore());
			delete rocket;
			rocket = NULL;
		}
		break;
	case CANDY:
		if(candy == NULL)
		{
			candy = new Candy(console);
		}

		state = candy->update();

		if(state != CANDY)
		{
			score.addscore(candy->returnscore());
			delete candy;
			candy = NULL;
		}
		break;
	case HIGH_SCORE:
		state = score.updatehighscore();
		break;
	case CREDITS:
		state = credit.playCredits();
		break;
	case ENTER_NAME:
		state = EnterName(console, &score);
		break;
	case QUIT_GAME:
		g_quitGame = true;
		break;
	}
}

void render()
{
	console.updateconsole();
}
