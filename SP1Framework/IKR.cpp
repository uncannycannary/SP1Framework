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
		if(Icekachanimcounter == 2)// 1/5 of the dessert
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang5.txt").c_str(),0x1A);
			higherscore++;
		}
		if(Icekachanimcounter == 1)//the bowl
		{
			console->draw(42,10,IceKach.getstring(L"Icekachang2.txt").c_str(),0x1A);
		}
		if(Icekachanimcounter == 0)
		{
			Icekachanimcounter = 6;
		}
	}
}

void IKR::IKRcontrols()
{
	if(framecounter >= 291 && framecounter <= 1191)
	{
		if(isKeyPressed(VK_LEFT))// Eat Ice Kachang Button
		{
		Icekachanimcounter -= 1;
		}
		if(isKeyPressed(VK_RIGHT))//Eat Ice Kachang Button
		{
		Icekachanimcounter -= 1;
		}
	}
}

gamestate IKR::playIKRgame()
{
	framecounter++;
	IKR::IKRcontrols();//the controls
	IKR::playIKRgameinstances();//game instances
	return ICECHAN;
}