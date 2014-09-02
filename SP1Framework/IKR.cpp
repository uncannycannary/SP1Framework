#include "IKR.h"
// no animations
//test
IKR::IKR(Graphics* console)
	:
Icekachanimcounter(6),//for the animations the game instances
higherscore(0),
IceKach(L"IceKachangEatout\\",L"*.txt"),
framecounter(0),
console(console)
{
}
void IKR::playIKRgameinstances()
{
	//initialise a drawing here.
	if(framecounter >= 0 && framecounter <= 150)//add Intro here
	{
		console->draw(22,10,IceKach.getstring(L"Intro.txt").c_str(),0x1A);
	}
	if(framecounter >= 170 && framecounter <= 200)//3
	{
		console->draw(42,10,IceKach.getstring(L"Subcounter3.txt").c_str(),0x1A);
	}
	if(framecounter >= 200 && framecounter <= 230)//2
	{
		console->draw(42,10,IceKach.getstring(L"Subcounter2.txt").c_str(),0x1A);
	}
	if(framecounter >= 230 && framecounter <= 260)//1
	{
		console->draw(42,10,IceKach.getstring(L"Subcounter1.txt").c_str(),0x1A);
	}
	if(framecounter >= 260 && framecounter <= 290)//GO!
	{
		console->draw(42,10,IceKach.getstring(L"SubcounterGO.txt").c_str(),0x1A);
	}
	if(framecounter >= 291 && framecounter <= 1191)//add animations here.
	{
		if(Icekachanimcounter == 6)// 5/5 of the dessert
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang1.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 5)// 4/5 of the dessert
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang2.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 4)// 3/5 of the dessert
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang3.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 3)// 2/5 of the dessert
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang4.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 2)//bowl
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang5.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 1)//finish((bowl thrown away))
		{
		}
		if(Icekachanimcounter <= 0)
		{
			Icekachanimcounter = 6;
		}
		char score[12];
		sprintf(score,"Score: %d",higherscore);
		console->draw(10,0,score,0x1A);
	}
}

void IKR::IKRcontrols()
{
	if(framecounter >= 291 && framecounter <= 1191)
	{
		if(isKeyPressed(VK_LEFT))// Eat Ice Kachang Button
		{
		Icekachanimcounter -= 1;
		if(Icekachanimcounter == 2)
		{
			higherscore++;
		}
		}
		if(isKeyPressed(VK_RIGHT))//Eat Ice Kachang Button
		{
		Icekachanimcounter -= 1;
		if(Icekachanimcounter == 2)
		{
			higherscore++;
		}
		}
	}

}

gamestate IKR::playIKRgame()
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	framecounter++;
	IKRcontrols();//the controls
	playIKRgameinstances();//game instances
	return ICECHAN;
}