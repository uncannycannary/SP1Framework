#include "Spotted.h"

gamestate Spotted::updateSpotted(Graphics* console)
{
	checkEscapee = Escapee;
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
	Spotted->draw(35,2,"_________ ZZZ",0x3C);
	Spotted->draw(35,3,"/       \\",0x3C);
	Spotted->draw(35,4,"| -   - |",0x3C);
	Spotted->draw(35,5,"|   _   |",0x3C);
	for (int a = 0; a <= 15; a++)
	{
		Spotted->draw(10,2+a,"-",0x2A);
	}

	for (int a = 0; a <= 15; a++)
	{
		Spotted->draw(70,2+a,"-",0x2A);
	}
	{
		char buffer[10];
		sprintf(buffer,"%d",CurrentFramePerSec/30);
		Spotted->draw(32,0,"Timer:",0x3C);
		Spotted->draw(38,0,buffer,0x3C);
	}
	if(CurrentFramePerSec >= 120 && CurrentFramePerSec <= 135 || CurrentFramePerSec >= 180 && CurrentFramePerSec <= 195 || CurrentFramePerSec >= 270 && CurrentFramePerSec <= 285 ||CurrentFramePerSec >= 375 && CurrentFramePerSec <= 390 ||CurrentFramePerSec >= 455 && CurrentFramePerSec <= 470 || CurrentFramePerSec >= 550 && CurrentFramePerSec <= 565 || CurrentFramePerSec >= 585 && CurrentFramePerSec <= 600 || CurrentFramePerSec >= 695 && CurrentFramePerSec <= 710 || CurrentFramePerSec >= 750 && CurrentFramePerSec <= 765 || CurrentFramePerSec >= 885 && CurrentFramePerSec <= 900 || CurrentFramePerSec >= 985 && CurrentFramePerSec <= 1000 || CurrentFramePerSec >= 1030 && CurrentFramePerSec <= 1045 || CurrentFramePerSec >= 1105 && CurrentFramePerSec <= 1120)
	{
		Spotted->draw(35,15,"ALERT!",0x3C);
	}
	if(CurrentFramePerSec >= 135 && CurrentFramePerSec <= 150 || CurrentFramePerSec >= 195 && CurrentFramePerSec <= 210 || CurrentFramePerSec >= 285 && CurrentFramePerSec <= 315 ||CurrentFramePerSec >= 390 && CurrentFramePerSec <= 420 ||CurrentFramePerSec >= 470 && CurrentFramePerSec <= 500 || CurrentFramePerSec >= 565 && CurrentFramePerSec <= 580 || CurrentFramePerSec >= 600 && CurrentFramePerSec <= 620 || CurrentFramePerSec >= 710 && CurrentFramePerSec <= 730 || CurrentFramePerSec >= 765 && CurrentFramePerSec <= 795 || CurrentFramePerSec >= 900 && CurrentFramePerSec <= 945 || CurrentFramePerSec >= 1000 && CurrentFramePerSec <= 1015 || CurrentFramePerSec >= 1045 && CurrentFramePerSec <= 1080 || CurrentFramePerSec >= 1120 && CurrentFramePerSec <= 1140)
	{
		Spotted->draw(35,2,"_________!!!!",0x3C);
		Spotted->draw(35,3,"/       \\",0x3C);
		Spotted->draw(35,4,"| 0   0 |",0x3C);
		Spotted->draw(35,5,"|   o   |",0x3C);
		Guard = true;
	}
	else if (CurrentFramePerSec == 151 || CurrentFramePerSec == 211 || CurrentFramePerSec == 316 || CurrentFramePerSec == 421 || CurrentFramePerSec == 501 || CurrentFramePerSec == 581 || CurrentFramePerSec == 621 || CurrentFramePerSec == 731 || CurrentFramePerSec == 796 || CurrentFramePerSec == 946 || CurrentFramePerSec == 1016 || CurrentFramePerSec == 1081 || CurrentFramePerSec == 1141)
	{
		Guard = false;
	}
	if(moving == true && Guard == true)
	{
		CurrentFramePerSec - 10;
		Escapee = 0;
	}
	if(Escapee == 20)
	{
		Escapee = 0;
		score += 1;
	}
	if(CurrentFramePerSec <= 1200)
	{
		if(Escapee%2 == 0)
		{ 
			Spotted->draw(10+checkEscapee*3,10,"  o  ",0x3C);
			Spotted->draw(10+checkEscapee*3,11,"/ 0 \\",0x3C);
			Spotted->draw(10+checkEscapee*3,12," / > ",0x3C);
		}
		else if(Escapee%2 == 1)
		{
			Spotted->draw(10+checkEscapee*3,10,"  o  ",0x3C);
			Spotted->draw(10+checkEscapee*3,11,"\\ 0 /",0x3C);
			Spotted->draw(10+checkEscapee*3,12," > / ",0x3C);
		}
		Spotted->draw(24,20,"Cross, but don't get Spotted!",0x2B);
		Spotted->draw(23,21,"----------Instuctions----------" ,0x2B);
		Spotted->draw(5,22,"Spam the left, down and right buttons, but stop if the Guard wakes up!",0x2B);
	}
	if(CurrentFramePerSec > 1200)
	{
		Spotted->draw(19,21,"  criminals have crossed!",0x2B);
		{
			char buffer[10];
			sprintf(buffer,"%d",score);
			Spotted->draw(18,21,(buffer),0x2B);
		}
	}
	if(CurrentFramePerSec == 0 )
	{
		Spotted->draw(28,10,"Press Enter to Begin!" ,0x3E);
	}
}

void Spotted::playSpotted()
{
	CurrentFramePerSec++;
	if (CurrentFramePerSec <= 1200)
	{
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_DOWN) || isKeyPressed(VK_RIGHT))
		{
			moving = true;
			Escapee += 1;
			step += 1;
		}
		else 
		{
			moving = false;
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
