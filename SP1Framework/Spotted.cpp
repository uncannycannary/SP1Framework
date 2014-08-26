#include "Spotted.h"

gamestate Spotted::updateSpotted(Graphics* console)
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if(isKeyPressed(VK_RETURN))
	{
		GameStarts = true;
	}
	if(GameStarts == true)
	{
		playSpotted();
		drawSpotted(console);
		return SPOTTED;
	}
	else
	{
		drawSpotted(console);
		return SPOTTED;
	}
	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}
}

void Spotted::drawSpotted(Graphics* Spotted)
{
	{
		char buffer[10];
		sprintf(buffer,"%d",CurrentFramePerSec/30);
		Spotted->draw(32,0,"Timer:",0x3C);
		Spotted->draw(38,0,buffer,0x3C);
	}

	if(CurrentFramePerSec >= 135 && CurrentFramePerSec <= 150 || CurrentFramePerSec >= 195 && CurrentFramePerSec <= 210 || CurrentFramePerSec >= 285 && CurrentFramePerSec <= 315 ||CurrentFramePerSec >= 390 && CurrentFramePerSec <= 420 ||CurrentFramePerSec >= 470 && CurrentFramePerSec <= 500 || CurrentFramePerSec >= 565 && CurrentFramePerSec <= 580)
	{
		Guard = true;
	}
	else if (CurrentFramePerSec == 151 || CurrentFramePerSec == 211 || CurrentFramePerSec == 316 || CurrentFramePerSec == 421 || CurrentFramePerSec == 501 || CurrentFramePerSec == 581)
	{
		Guard = false;
	}
	if(moving == true && Guard == true)
	{
		Escapee = 0;
	}
	if(Escapee == 20)
	{
		Escapee = 0;
		score += 1;
	}
	if(CurrentFramePerSec <= 600)
	{
		Spotted->draw(24,20,"Cross, but don't get Spotted!",0x2A);
		Spotted->draw(23,21,"----------Instuctions----------" ,0x2A);
		Spotted->draw(5,22,"Spam the left, up and right buttons, but stop if the {!} sign comes out!",0x2A);
	}
	if(CurrentFramePerSec > 600)
	{
		Spotted->draw(12,21," criminals have crossed!",0x2A);
		{
			char buffer[10];
			sprintf(buffer,"%d",score);
			Spotted->draw(11,21,(buffer),0x2A);
		}
	}
	if(CurrentFramePerSec == 0 )
	{
		Spotted->draw(28,10,"Press Enter to Begin!" ,0x3E);
	}
	if(checkEscapee = 0)
	{
	}
	if(checkEscapee = 1)
	{
	}
}

void Spotted::playSpotted()
{
	CurrentFramePerSec++;
	if (CurrentFramePerSec <= 600)
	{
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_UP) || isKeyPressed(VK_RIGHT))
		{
			moving = true;
			Escapee += 1;
		}
	}
}

void Spotted::resetSpotted()
{
	Escapee = 0;
	CurrentFramePerSec = 0;
	GameStarts = false;
	gameends = false;
	Guard = false;
	score = 0;
}
