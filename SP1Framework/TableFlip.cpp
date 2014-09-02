#include "TableFlip.h"

gamestate TableFlip::updateTableFlip(Graphics* console)
{
	//does user input
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if (CurrentFramePerSec > 650)
	{
		if(isKeyPressed(VK_RETURN))
		{
			return MAIN_MENU;
		}
	}
	playTableFlip();
	drawTableFlip(console);
	return TABLE_FLIP;
	drawTableFlip(console);
	return TABLE_FLIP;

	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}
}

void TableFlip::playTableFlip()
{
	CurrentFramePerSec++;
	if(CurrentFramePerSec > 440 && CurrentFramePerSec <= 650)
	{
		if(isKeyPressed(VK_LEFT))
		{
			checkleft += 1;
			left = checkleft;
		}
		if(isKeyPressed(VK_RIGHT))
		{
			checkright += 1;
			right = checkright;
		}
	}
}

void TableFlip::drawTableFlip(Graphics* TableFlip)
{
	if(CurrentFramePerSec >= 0 && CurrentFramePerSec <= 60)
	{
		TableFlip->draw(44,20,"Table Flip", 0x0F);
	}
	if(CurrentFramePerSec >= 60 && CurrentFramePerSec <= 299)
	{
		TableFlip->draw(42,20,"How to play", 0x0F);
		TableFlip->draw(15,22,"Mash the arrow keys < and > to increase power to flip that table!", 0x0F);
	}
	if(CurrentFramePerSec >= 300 && CurrentFramePerSec <= 650)
	{
		TableFlip->draw(7,25,"-------",0x58);
		TableFlip->draw(7,26,"|     |",0x58);

		TableFlip->draw(2,24,"  o",0x48);  
		TableFlip->draw(2,25," / =",0x48);  
		TableFlip->draw(2,26,"|| ",0x48);

		if(CurrentFramePerSec >= 300 && CurrentFramePerSec <= 330)
		{	
			TableFlip->draw(47,20,"Ready?", 0x0F);
		}

		if(CurrentFramePerSec >= 330 && CurrentFramePerSec <= 360)
		{	
			TableFlip->draw(50,20,"1", 0x0F);
		}

		if(CurrentFramePerSec >= 360 && CurrentFramePerSec <= 390)
		{	
			TableFlip->draw(50,20,"2", 0x0F);
		}

		if(CurrentFramePerSec >= 390 && CurrentFramePerSec <= 420)
		{	
			TableFlip->draw(50,20,"3", 0x0F);
		}

		if(CurrentFramePerSec >= 420 && CurrentFramePerSec <= 440)
		{	
			TableFlip->draw(50,20,"GO!", 0x0F);
		}
	}
	if(CurrentFramePerSec >= 440 && CurrentFramePerSec < 650)
	{
		{
			char buffer[10];
			sprintf(buffer,"%d",right+left);
			TableFlip->draw(45,25,"Score:",0x3C);
			TableFlip->draw(51,25,buffer,0x3C);
		}
		if(isKeyHold(VK_LEFT))
		{
			TableFlip->draw(0,23,"  \\||/ ",0x48);  
			TableFlip->draw(0,24," -  o- ",0x48);  
			TableFlip->draw(0,25," - / = ",0x48);  
			TableFlip->draw(0,26," -||   ",0x48);
			TableFlip->draw(0,27,"  /||\\ ",0x48);
		}

		if(isKeyHold(VK_RIGHT))
		{
			TableFlip->draw(0,22,"\\ || / ",0x48); 
			TableFlip->draw(0,23,"       ",0x48); 
			TableFlip->draw(0,24,"-   o -",0x48);  
			TableFlip->draw(0,25,"-  / = ",0x48);  
			TableFlip->draw(0,26,"- ||   ",0x48);
			TableFlip->draw(0,27,"       ",0x48);
			TableFlip->draw(0,28,"/ || \\ ",0x48);
		}
	}

	if (CurrentFramePerSec > 650)
	{
		TableFlip->draw(80,25,"|     |",0x58);
		TableFlip->draw(80,26,"-------",0x58);

		TableFlip->draw(2,24,"  o// ",0x48);  
		TableFlip->draw(2,25,"  |   ",0x48);  
		TableFlip->draw(2,26,"  |\\  ",0x48); 
		{
			char scorebuffer[10];
			sprintf(scorebuffer,"%d",right+left);
			TableFlip->draw(35,25,"You table has flipped over    m!",0x2B);
			TableFlip->draw(62,25,scorebuffer,0x2B);
		}
		TableFlip->draw(37,45,"Press Enter to continue!" ,0x3E);
	}
}

