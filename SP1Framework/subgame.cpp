//testtest
#include "subgame.h"
using std::ifstream;
using std::ofstream;
//Objective of this game is to shoot the monsters as much as you can as it appears
//int framecounter = 0;

//int higherscore = 0;
subgame::subgame(Graphics* console)
	:
higherscore(0),
	framecounter(-30),
	Subfold(L"Submarine\\",L"*.txt"),
	console(console)
{
}

void subgame::playsubcontrolsmechanics()//only starts after 3 sec
{
	framecounter++;
	if(framecounter <= 0)
	{
		console->draw(44,20, "Sub-Shootdown",0x1A);
	}
	if(framecounter >= 1 && framecounter<=90)
	{
		console->draw(42,10,Subfold.getstring(L"Intro.txt").c_str(),0x1A);
	}
	if(framecounter >= 90 && framecounter <= 119)
	{
		console->draw(42,10,Subfold.getstring(L"Subcounter3.txt").c_str(),0x1A);
	}
	if(framecounter >= 120 && framecounter <= 149)
	{
		console->draw(42,10,Subfold.getstring(L"Subcounter2.txt").c_str(),0x1A);
	}
	if(framecounter >= 150 && framecounter <= 179)
	{
		console->draw(42,10,Subfold.getstring(L"Subcounter1.txt").c_str(),0x1A);
	}
	if(framecounter >= 180 && framecounter <= 209)
	{
		console->draw(42,10,Subfold.getstring(L"SubcounterGO.txt").c_str(),0x1A);
	}

	if(framecounter > 210 && framecounter < 900)
	{
		if(isKeyPressed(VK_LEFT))
		{
			console->draw(4,24,Subfold.getstring(L"Sub-shoot.txt").c_str(),0x1A);
		}
		if(isKeyPressed(VK_DOWN))
		{
			console->draw(42,24,Subfold.getstring(L"Sub-shoot.txt").c_str(),0x1A);
		}

		if(isKeyPressed(VK_RIGHT))
		{
			console->draw(79,24,Subfold.getstring(L"Sub-shoot.txt").c_str(),0x1A);
		}
		console->draw(5,30,Subfold.getstring(L"Sub.txt").c_str(),0x1A);
		console->draw(43,30,Subfold.getstring(L"Sub.txt").c_str(),0x1A);
		console->draw(80,30,Subfold.getstring(L"Sub.txt").c_str(),0x1A);
		char buffer[256];
		sprintf(buffer,"Score: %d",higherscore);
		console->draw(24,10,buffer,0xB2);
	}
}

void subgame::playgamestate()
{
	if(framecounter >= 240 && framecounter <= 300)
	{
		console->draw(5,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_LEFT) &&(framecounter >= 240 && framecounter <= 300))
		{
			console->draw(5,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 300 && framecounter <=360)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 300 && framecounter <=360))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 370 && framecounter <= 420)
	{
		console->draw(43,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_DOWN) && (framecounter >= 370 && framecounter <=420))
		{
			console->draw(43,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 410 && framecounter <= 450)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 410 && framecounter <=450))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 460 && framecounter <= 478)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 460 && framecounter <=478))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 500 && framecounter <= 528)
	{
		console->draw(43,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_DOWN) && (framecounter >= 500 && framecounter <= 528))
		{
			console->draw(43,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 530 && framecounter <= 558)
	{
		console->draw(43,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_DOWN) && (framecounter >= 530 && framecounter <= 558))
		{
			console->draw(43,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 530 && framecounter <= 558)
	{
		console->draw(5,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_LEFT) && (framecounter >= 530 && framecounter <= 558))
		{
			console->draw(5,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 600 && framecounter <= 618)
	{
		console->draw(5,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_LEFT) &&(framecounter >= 600 && framecounter <= 618))
		{
			console->draw(5,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0xB2);
			higherscore++;
		}
	}
	if(framecounter >= 630 && framecounter <= 666)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 630 && framecounter <=666))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 680 && framecounter <= 710)
	{
		console->draw(43,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_DOWN) && (framecounter >= 680 && framecounter <= 710))
		{
			console->draw(43,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 714 && framecounter <= 742)
	{
		console->draw(43,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_DOWN) && (framecounter >= 714 && framecounter <= 742))
		{
			console->draw(43,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0x1A);
			higherscore++;
		}
	}
	if(framecounter >= 716 && framecounter <= 746)
	{
		console->draw(5,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_LEFT) &&(framecounter >= 716 && framecounter <= 746))
		{
			console->draw(5,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0xB2);
			higherscore++;
		}
	}
	if(framecounter >= 800 && framecounter <= 826)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 800 && framecounter <=826))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0xB2);
			higherscore++;
		}
	}
	if(framecounter >= 859 && framecounter <= 875)
	{
		console->draw(5,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_LEFT) &&(framecounter >= 859 && framecounter <= 875))
		{
			console->draw(5,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0xB2);
			higherscore++;
		}
	}
	if(framecounter >= 861 && framecounter <= 900)
	{
		console->draw(80,4,Subfold.getstring(L"Subenemies.txt").c_str(),0x1A);
		if(isKeyPressed(VK_RIGHT) && (framecounter >= 861 && framecounter <=900))
		{
			console->draw(80,4,Subfold.getstring(L"Subenemies-dead.txt").c_str(),0xB2);
			higherscore++;
		}
	}
	if(framecounter >= 900)
	{
		char score[25];
		sprintf(score,"You have scored: %d",higherscore);
		console->draw(41,20,score,0x1A);
		console->draw(38,22, "Press Enter to continue!", 0x1A);

		if(higherscore > 70 && higherscore < 80 )
		{
			rank = 'S';
		}
		if(higherscore > 60 && higherscore < 70)
		{
			rank = 'A';
		}
		if(higherscore > 50 && higherscore <= 60)
		{
			rank = 'B';
		}
		if(higherscore > 40 && higherscore <= 50)
		{
			rank = 'C';
		}
		if(higherscore > 30 && higherscore <= 40)
		{
			rank = 'D';
		}
		if(higherscore > 20 && higherscore <= 30)
		{
			rank = 'E';
		}
		if(higherscore <= 20)
		{
			rank = 'F';
		}
		char rankbuffer[10];
		sprintf(rankbuffer, "Rank: %c", rank);
		console->draw(47,19, rankbuffer, 0x0F);
	}
}

gamestate subgame::playsubgamemain() 
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if(framecounter >= 900)
	{
		if(isKeyPressed(VK_RETURN))
		{
			return MAIN_MENU;
		}
	}
	playsubcontrolsmechanics();
	playgamestate();
	if(isKeyPressed(VK_RETURN) && framecounter > 900)
	{
		return MAIN_MENU;
	}
	return SUBMARINE;
}