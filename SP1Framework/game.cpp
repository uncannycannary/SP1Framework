// This is the main file for the game logic and function
//
//
#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
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

Graphics console;

//Create a pointer to store the location of the scream object
Spotted* spot;
TableFlip* flip;
Scream* scream;
toiletroll* toilet;
photospam* spam;
FindTwins* twins;
highscore* score;
gamestate state = INTRO;
void init()
{
	updateinput();
	ini();
	initialisesubdrawings();

	score = NULL;
	scream = NULL;
	toilet = NULL;
	spam = NULL;
	flip = NULL;
	spot = NULL;
	twins = NULL;
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
		state = playsubgamemain(&console);
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
