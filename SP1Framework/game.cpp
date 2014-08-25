// This is the main file for the game logic and function
//
//
#include "game.h"
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
TableFlip FlippingTables;

//Create a pointer to store the location of the scream object
Scream* scream;
toiletroll* toilet;
gamestate state = INTRO;
void init()
{
	updateinput();
	ini();
	initialisesubdrawings();

	scream = NULL;
	toilet = NULL;
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
		state = FlippingTables.updateTableFlip(&console);
		if(state != TABLE_FLIP)
		{
			FlippingTables.resetTableFlip();
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
		break;
	case FIND_TWINS:
		break;
	case PHOTOSPAM:
		break;
	case ROCKET:
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
