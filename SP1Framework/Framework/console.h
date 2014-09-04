#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <windows.h>
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
	ENTER_NAME,
	CREDITS,
	RANDOM,
	RESULTS,
	MAXSTATES,
};

enum submarfull//submarine game.
{
	ANIMATIONS,
	GAMESTATE,
	MECHANICS
};

const int numofminigames = MAXSTATES - 9;

bool isKeyPressed(unsigned short key);
bool isKeyReleased(unsigned short key);
void updateinput();
bool isKeyHold(unsigned short key);
char getkeyboardbuffer();

#endif // _CONSOLE_H