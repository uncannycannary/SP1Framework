#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include <iostream>
#include "Graphics.h"

void ini();
gamestate Intro(Graphics&);
gamestate EnterName(Graphics& console, highscore* score);
gamestate MainMenu(Graphics&,highscore* score);
gamestate GameSelect(Graphics&);
gamestate Credits(Graphics&);
void randommode();


#endif