#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "game.h"
#include "highscore.h"
#include "Framework\console.h"
#include <iostream>
#include "Graphics.h"

void ini();
gamestate Intro(Graphics&);
gamestate MainMenu(Graphics&,highscore* score);
gamestate GameSelect(Graphics&);
gamestate Options(Graphics&);
void randommode();


#endif