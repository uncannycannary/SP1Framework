#include <iostream>
#include "Graphics.h"
#include "Directory.h"
#include <fstream>
#include "Framework\console.h"
#include "game.h"

class Credits
{
public:
	Credits(Graphics* console);
	gamestate playCredits();
private:
	Graphics* console;
	Directory CreditsText;
	int framecounter;
};