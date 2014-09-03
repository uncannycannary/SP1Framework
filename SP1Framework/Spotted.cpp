#include "Spotted.h"

gamestate Spotted::updateSpotted(Graphics* console)
{
	checkEscapee = Escapee;
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if (CurrentFramePerSec > 1640)
	{
		if(isKeyPressed(VK_RETURN))
		{
			return MAIN_MENU;
		}
	}
	playSpotted();
	drawSpotted(console);
	return SPOTTED;

	if(gameends)
	{
		gamestate state = (gamestate)(rand() % numofminigames);
		return state;
	}
}

void Spotted::drawSpotted(Graphics* Spotted)
{
	if(CurrentFramePerSec >= 0 && CurrentFramePerSec <= 60)
	{
		Spotted->draw(44,20,"Don't get Spotted!", 0x0F);
	}
	if(CurrentFramePerSec >= 60 && CurrentFramePerSec <= 299)
	{
		Spotted->draw(42,20,"How to play", 0x0F);
		Spotted->draw(15,22,"Mash the arrow keys <, v and > to run across the border!\nBut watch out for the (ALERT!) icon!", 0x0F);
	}
	if(CurrentFramePerSec >= 300 && CurrentFramePerSec <= 330)
	{	
		Spotted->draw(47,20,"Ready?", 0x0F);
	}

	if(CurrentFramePerSec >= 330 && CurrentFramePerSec <= 360)
	{	
		Spotted->draw(50,20,"3", 0x0F);
	}

	if(CurrentFramePerSec >= 360 && CurrentFramePerSec <= 390)
	{	
		Spotted->draw(50,20,"2", 0x0F);
	}

	if(CurrentFramePerSec >= 390 && CurrentFramePerSec <= 420)
	{	
		Spotted->draw(50,20,"1", 0x0F);
	}

	if(CurrentFramePerSec >= 420 && CurrentFramePerSec <= 440)
	{	
		Spotted->draw(50,20,"GO!", 0x0F);
	}
	if(CurrentFramePerSec >= 440 && CurrentFramePerSec <= 1640)
	{
		Spotted->draw(46,2,"_________ ZZZ",0x3C);
		Spotted->draw(46,3,"/       \\",0x3C);
		Spotted->draw(46,4,"| -   - |",0x3C);
		Spotted->draw(46,5,"|   _   |",0x3C);
		for (int a = 0; a <= 15; a++)
		{
			Spotted->draw(20,12+a,"-",0x2A);
		}

		for (int a = 0; a <= 15; a++)
		{
			Spotted->draw(80,12+a,"-",0x2A);
		}
		if(checkalert >= 120 && checkalert <= 135 || checkalert >= 180 && checkalert <= 195 || checkalert >= 270 && checkalert <= 285 ||checkalert >= 375 && checkalert <= 390 ||checkalert >= 455 && checkalert <= 470 || checkalert >= 550 && checkalert <= 565 || checkalert >= 585 && checkalert <= 600 || checkalert >= 695 && checkalert <= 710 || checkalert >= 750 && checkalert <= 765 || checkalert >= 885 && checkalert <= 900 || checkalert >= 985 && checkalert <= 1000 || checkalert >= 1030 && checkalert <= 1045 || checkalert >= 1105 && checkalert <= 1120)
		{
			Spotted->draw(35,15,"ALERT!",0x3C);
		}
		if(checkalert >= 135 && checkalert <= 150 || checkalert >= 195 && checkalert <= 210 || checkalert >= 285 && checkalert <= 315 ||checkalert >= 390 && checkalert <= 420 ||checkalert >= 470 && checkalert <= 500 || checkalert >= 565 && checkalert <= 580 || checkalert >= 600 && checkalert <= 620 || checkalert >= 710 && checkalert <= 730 || checkalert >= 765 && checkalert <= 795 || checkalert >= 900 && checkalert <= 945 || checkalert >= 1000 && checkalert <= 1015 || checkalert >= 1045 && checkalert <= 1080 || checkalert >= 1120 && checkalert <= 1140)
		{
			Spotted->draw(46,2,"_________!!!!",0x3C);
			Spotted->draw(46,3,"/       \\",0x3C);
			Spotted->draw(46,4,"| 0   0 |",0x3C);
			Spotted->draw(46,5,"|   o   |",0x3C);
			Guard = true;
		}
		else if (checkalert == 151 || checkalert == 211 || checkalert == 316 || checkalert == 421 || checkalert == 501 || checkalert == 581 || checkalert == 621 || checkalert == 731 || checkalert == 796 || checkalert == 946 || checkalert == 1016 || checkalert == 1081 || checkalert == 1141)
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
		if(CurrentFramePerSec >= 440 && CurrentFramePerSec <= 1640)
		{
			if(Escapee%2 == 0)
			{ 
				Spotted->draw(21+checkEscapee*3,20,"  o  ",0x3C);
				Spotted->draw(21+checkEscapee*3,21,"/ 0 \\",0x3C);
				Spotted->draw(21+checkEscapee*3,22," / > ",0x3C);
			}
			else if(Escapee%2 == 1)
			{
				Spotted->draw(21+checkEscapee*3,20,"  o  ",0x3C);
				Spotted->draw(21+checkEscapee*3,21,"\\ 0 /",0x3C);
				Spotted->draw(21+checkEscapee*3,22," > / ",0x3C);
			}
		}
		{
			char buffer[10];
			sprintf(buffer,"%d",score);
			Spotted->draw(40,27,"Score:",0x3C);
			Spotted->draw(47,27,buffer,0x3C);
		}
		if(CurrentFramePerSec > 1640)
		{
			Spotted->draw(35,30,"  o  ",0x3C);
			Spotted->draw(35,31,"\\0 /",0x3C);
			Spotted->draw(35,32," / \\",0x3C);
			Spotted->draw(31,21,"  criminals have crossed!",0x2B);
			{
				char buffer[10];
				sprintf(buffer,"%d",score);
				Spotted->draw(30,21,(buffer),0x2B);
			}
		}
	}
}

void Spotted::playSpotted()
{
	CurrentFramePerSec++;
	if (CurrentFramePerSec >= 440 && CurrentFramePerSec <= 1640)
	{
		checkalert++;
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
