#include <iostream>
#include "Graphics.h"
#include "Framework\timer.h"
#include "Directory.h"
#include <fstream>
#include "Framework\console.h"

class subgame
{
private:
//Objective of this game is to shoot the monsters as much as you can as it appears
	int framecounter;
	int higherscore;
	Graphics* console;
	Directory Subfold;
	char rank;
public:
	void playgamestate();
	gamestate playsubgamemain();
	void playsubcontrolsmechanics();
	subgame(Graphics* console);
	char returnscore();
};