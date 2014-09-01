#include <iostream>
#include "Graphics.h"
#include "Framework\timer.h"
#include "Directory.h"
#include <fstream>
#include "Framework\console.h"
#include "game.h"

class Drumrolls
{
public:
	void playDRstate();
	gamestate playsDRmain();
	void playsDRcontrolsmechanics();
	Drumrolls(Graphics* console);
private:
	Directory DrumAnim;
	Graphics* console;
	int higherscore;
	int framecounter;
};