#include "IKR.h"
// no animations
//test
IKR::IKR(Graphics* console)
	:
Icekachanimcounter(6),//for the animations the game instances
higherscore(0),
IceKach(L"Ice Kachang Eatout\\",L"*.txt"),
framecounter(0),
console(console)
{
}
void IKR::playIKRgameinstances()
{
	//initialise a drawing here.
	if(framecounter >= 0 && framecounter <= 150)//add Intro here
	{
	}
	if(framecounter >= 170 && framecounter <= 200)//3
	{
	}
	if(framecounter >= 200 && framecounter <= 230)//2
	{
	}
	if(framecounter >= 260 && framecounter <= 290)//1
	{
	}
	if(framecounter >= 320 && framecounter <= 350)//GO!
	{
	}
	if(framecounter >= 351 && framecounter <= 381)//add animations here.
	{
		if(Icekachanimcounter == 6)// 5/5 of the dessert
		{
		}
		if(Icekachanimcounter == 5)// 4/5 of the dessert
		{
		}
		if(Icekachanimcounter == 4)// 3/5 of the dessert
		{
		}
		if(Icekachanimcounter == 3)// 2/5 of the dessert
		{
		}
		if(Icekachanimcounter == 2)// 1/5 of the dessert
		{

			higherscore++;
		}
		if(Icekachanimcounter == 1)//the bowl
		{

		}
		if(Icekachanimcounter == 0)
		{
			Icekachanimcounter = 6;
		}
	}
}

void IKR::IKRcontrols()
{
	if(framecounter >= 381 && framecounter <= 1281)
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

//gamestate IKR::playIKRgame()
//{
	//framecounter++;//Increases as each frames go.
	//IKR::IKRcontrols();//the controls
	//IKR::playIKRgameinstances();//game instances
	//return ICE_KACHANG_RACE;
//}