#ifdef _SPOTTED_H
#define _SPOTTED_H

#include <iostream>
#include <iomanip>
#include "Graphics.h"
#include "game.h"
#include "Framework\console.h"

class Spotted
{
public:
	gamestate updateSpotted(Graphics* console);
	void resetSpotted();
	TableFlip()
	{
	}
	~TableFlip()
	{
	}
private:
	void drawSpotted(Graphics* TableFlip);
	void playSpotted();
};

#endif 