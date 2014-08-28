#include "TableFlip.h"

//int left = 0;
//int right = 0;
//int checkleft = 0;
//int checkright = 0;
//int CurrentFramePerSec = 0;
//bool GameStarts = false;
//bool gameends = false;

gamestate TableFlip::updateTableFlip(Graphics* console)
{
	//does user input
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
		playTableFlip();
		drawTableFlip(console);
		return TABLE_FLIP;
	}
	else
	{
		drawTableFlip(console);
		return TABLE_FLIP;
	}

	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}
}

void TableFlip::playTableFlip()
{
	CurrentFramePerSec++;
	if(CurrentFramePerSec <=210)
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
	{
		char buffer[10];
		sprintf(buffer,"%d",CurrentFramePerSec/30);
		TableFlip->draw(32,0,"Timer:",0x3C);
		TableFlip->draw(38,0,buffer,0x3C);
	}
	if(CurrentFramePerSec == 0)
	{
		TableFlip->draw(33,20,"Table Flip",0x2B);
		TableFlip->draw(23,21,"----------Instuctions----------" ,0x2B);
		TableFlip->draw(13,22,"Press the left and right button as much as you can!",0x2B);
		TableFlip->draw(28,10,"Press Enter to Begin!" ,0x3E);
	}
	if(CurrentFramePerSec <= 210)
	{
		TableFlip->draw(33,20,"Table Flip",0x2B);
		TableFlip->draw(23,21,"----------Instuctions----------" ,0x2B);
		TableFlip->draw(13,22,"Press the left and right button as much as you can!",0x2B);

		TableFlip->draw(7,12,"-------",0x58);
		TableFlip->draw(7,13,"|     |",0x58);

		TableFlip->draw(2,11,"  o",0x48);  
		TableFlip->draw(2,12," / =",0x48);  
		TableFlip->draw(2,13,"|| ",0x48);

		if(isKeyHold(VK_LEFT))
		{
			TableFlip->draw(0,10,"  \\||/ ",0x48);  
			TableFlip->draw(0,11," -  o- ",0x48);  
			TableFlip->draw(0,12," - / = ",0x48);  
			TableFlip->draw(0,13," -||   ",0x48);
			TableFlip->draw(0,14,"  /||\\ ",0x48);

		}

		if(isKeyHold(VK_RIGHT))
		{
			TableFlip->draw(0,9,"\\ || / ",0x48); 
			TableFlip->draw(0,10,"       ",0x48); 
			TableFlip->draw(0,11,"-   o -",0x48);  
			TableFlip->draw(0,12,"-  / = ",0x48);  
			TableFlip->draw(0,13,"- ||   ",0x48);
			TableFlip->draw(0,14,"       ",0x48);
			TableFlip->draw(0,15,"/ || \\ ",0x48);
		}
	}

	if (CurrentFramePerSec > 210)
	{
		TableFlip->draw(71,12,"|     |",0x58);
		TableFlip->draw(71,13,"-------",0x58);

		TableFlip->draw(3,11,"  o// ",0x48);  
		TableFlip->draw(3,12,"  |   ",0x48);  
		TableFlip->draw(3,13,"  |\\  ",0x48); 

		TableFlip->draw(13,21,"Congratulations! Your table has flipped over ",0x2B);
		{
			char buffer[10];
			sprintf(buffer,"%d",right+left);
			TableFlip->draw(58,21,(buffer),0x2B);
		}
		TableFlip->draw(61,21,"m!",0x2AB);

		TableFlip->draw(20,10,"Press Enter to return to the Main Menu!" ,0x3E);
	}
}

