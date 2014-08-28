#include "Virus.h"

gamestate Virus::update(Graphics* console)
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
		play();
		draw(console);
		return VIRUS;
	}
	else
	{
		draw(console);
		return VIRUS;
	}
	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}

}
void Virus::draw(Graphics* Virus)
{
	if(virus <= 0)
	{
		fileempty = true;
	}
	if(fileempty == true)
	{
		checkfile++;
	}
	if(checkfile < 15 && firegun == true)
	{
		penalty++;
		if(penalty == 15)
		{
			fileempty = false;
			files -= 1;
		}
	}

	if (CurrentFramePerSec >= 0 && CurrentFramePerSec <= 900 || gameends != true)
	{

	}

	if (files == 0 || CurrentFramePerSec >= 900)
	{
		gameends = true;
	}
}

void Virus::play()
{
	CurrentFramePerSec++;
	if (CurrentFramePerSec <= 900 && gameends != true)
	{
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_DOWN) || isKeyPressed(VK_RIGHT))
		{
			firegun = true;
			virus -= 1;
		}
		else 
		{
			firegun = false;
		}
	}
}
