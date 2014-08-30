// This is the main file for the game logic and function
//
//
#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "MainMenu.h"
#include"ToiletRoll.h"
#include "Graphics.h"
#include "TableFlip.h"
#include "Scream.h"
#include "subgame.h"
#include "Spotted.h"
#include "Rocket.h"
#include "Photospam.h"
#include "FindTwins.h"
#include "candy.h"

Graphics console;

//Create a pointer to store the location of the scream object
Spotted* spot;
TableFlip* flip;
Scream* scream;
toiletroll* toilet;
photospam* spam;
FindTwins* twins;
highscore* score;
subgame* submarine;
Candy* candy;
pumprocket* rocket;
gamestate state = INTRO;
void init()
{
	srand(time(NULL));
	updateinput();
	ini();

	score = NULL;
	scream = NULL;
	toilet = NULL;
	spam = NULL;
	flip = NULL;
	spot = NULL;
	twins = NULL;
	submarine = NULL;
	candy = NULL;
	rocket = NULL;
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
		state = MainMenu(console);
		break;
	case GAME_SELECT:
		state = GameSelect(console);
		break;
	case OPTIONS:
		state = Options(console);
		break;
	case TABLE_FLIP:
		if(flip == NULL)
		{
			flip = new TableFlip;
		}

		state = flip->updateTableFlip(&console);

		if(state != TABLE_FLIP)
		{
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
			delete toilet;
			toilet = NULL;
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
			delete rocket;
			rocket = NULL;
		}
		break;
	case CANDY:
		if(CANDY == NULL)
		{
			candy = new Candy;
		}

		state = candy->update(&console);

		if(state != CANDY)
		{
			delete candy;
			candy = NULL;
		}
		break;
	case HIGH_SCORE:
	{
		if(score == NULL)
		{
			 score = new highscore(console);
		}

		state = score->updatehighscore();
		break;
	}
	case QUIT_GAME:
		g_quitGame = true;
		break;
	}
}

void render()
{
	console.updateconsole();
}
