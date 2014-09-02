#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Directory.h"

extern StopWatch g_timer;
extern bool g_quitGame;
enum gamestate
{
	TABLE_FLIP,
	TOILET_ROLL,
	SCREAM,
	SUBMARINE,
	SPOTTED,
	FIND_TWINS,
	ROCKET,
	PHOTOSPAM,
	CANDY,
	ICECHAN,
	QUIT_GAME,
	GAME_SELECT,
	INTRO,
	MAIN_MENU,
	HIGH_SCORE,
	CREDITS,
	RANDOM,
	RESULTS,
	MAXSTATES
};

enum submarfull//submarine game.
{
	ANIMATIONS,
	GAMESTATE,
	MECHANICS
};


const int numofminigames = 7;
//const int numofminigames = MAXSTATES - 8;


void init();                // initialize your variables, allocate memory, etc
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory

#endif // _GAME_H