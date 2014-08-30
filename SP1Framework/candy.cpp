#include "candy.h"

gamestate Candy::update(Graphics* console)
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
		return CANDY;
	}
	else
	{
		draw(console);
		return CANDY;
	}
	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}

}
void Candy::draw(Graphics* candy)
{
	if(CurrentFramePerSec >= 0 && CurrentFramePerSec <= 60)
	{
		candy->draw(45,20,"Fill up the Candy jar!", 0x2B);
	}

	if(CurrentFramePerSec >= 61 && CurrentFramePerSec <= 299)
	{
		candy->draw(45,20,"How to play", 0x0F);
		candy->draw(38,22,"Press the left,up and right keys\n as much as you can.\n But do not overfill over 100 candies or something happens :3", 0x0F);
	}

	if(CurrentFramePerSec >= 300 && CurrentFramePerSec <= 660)
	{
		
	}
}

void Candy::play()
{
	CurrentFramePerSec++;
	checkframe++;
	if (CurrentFramePerSec >= 360 && CurrentFramePerSec <= 660 && gameends != true)
	{
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_DOWN) || isKeyPressed(VK_RIGHT))
		{
			candies += 1;
		}
	}
}
