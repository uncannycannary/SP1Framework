#include "Graphics.h"
#include "game.h"
#include <iostream>
#include "Directory.h"
#include <fstream>
#include "Framework\timer.h"
#include "Framework\console.h"

class IKR
{
private:
	int Icekachanimcounter;
	int higherscore;
	int framecounter;
	Directory IceKach;
	Graphics* console;
	char rank;
public:
	char returnscore();
	void playIKRgameinstances();
	gamestate playIKRgame();//main function
	IKR(Graphics* console);
	void IKRcontrols();
};