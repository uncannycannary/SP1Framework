#include "MainMenu.h"
std::string Title;
std::string Main;
std::string Select;
int choice = 0;
int choice2 = 0;
std::vector<gamestate> random;
int currentframe = 0;
int currentstage = 0;

void ini()
{
	std::ifstream readTitle;
	readTitle.open ("ButtonMashMaster.txt"); // associate & open files
	while (!readTitle.eof()) 
	{
		Title += readTitle.get();
	}
	Title.pop_back();
	readTitle.close ();

	std::ifstream readMain;
	readMain.open ("MainMenu.txt"); // associate & open files
	while (!readMain.eof()) 
	{
		Main += readMain.get();
	}
	Main.pop_back();
	readMain.close();

	std::ifstream readSelect;
	readSelect.open ("SelectGame.txt"); // associate & open files
	while (!readSelect.eof()) 
	{
		Select += readSelect.get();
	}
	Select.pop_back();
	readSelect.close();
}

gamestate Intro(Graphics& console)
{
	console.draw(16,3,Title.c_str(),0x3E);
	console.draw(28,20,"Press Enter to Begin!" ,0x3E);
	if(isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	return INTRO;
}

gamestate MainMenu(Graphics& console)
{
	if(random.size() > 0)
	{
		if(currentframe <= 60)
		{
			char buffer[8];
			sprintf(buffer, "Stage %d", currentstage);
			console.draw(47,20,buffer,0x0F);
			++currentframe;
			return MAIN_MENU;
		}
		else
		{
			++currentstage;
			currentframe = 0;
			gamestate stage = random.back();
			random.pop_back();
			return stage;
		}
	}
	else
	{
		console.draw(27,12+choice,"-->",0x25);
		console.draw(15,3,Main.c_str(),0x25);
		console.draw(30,12,"Normal Mode",0x25);
		console.draw(30,13,"Random Mode",0x25);
		console.draw(30,14,"Options",0x25);
		console.draw(30,15,"High Score",0x25);
		console.draw(30,16,"Exit game",0x25);

		if(isKeyPressed(VK_DOWN))
		{
			choice++;
			if(choice > 4)
			{
				choice = 4;
			}
		}
		if(isKeyPressed(VK_UP))
		{
			choice--;
			if(choice < 0)
			{
				choice = 0;
			}
		}
		if(isKeyPressed(VK_RETURN))
		{
			switch(choice)
			{
			case 0:
				return GAME_SELECT;
			case 1:
				randommode();
				return MAIN_MENU;
			case 2:
				return OPTIONS;
			case 3:
				return HIGH_SCORE;
			case 4:
				return QUIT_GAME;
			}
		}
		return MAIN_MENU;
	}
}

void randommode()
{
	std::vector<int> games;
	for(int i=0; i < numofminigames; ++i)
	{
		games.push_back(i);
	}
	for(int i=0; i < 7; ++i)
	{
		int index = rand()%games.size();
		gamestate stage = (gamestate)games[index];
		random.push_back(stage);
		games[index] = games.back();
		games.pop_back();
	}
	currentstage = 1;
}

gamestate Options(Graphics& console)
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	else
	{
		return OPTIONS;
	}
}

gamestate GameSelect(Graphics& console)
{
	console.draw(27,12+choice2,"-->",0x69);
	console.draw(11,3,Select.c_str(),0x69);
	console.draw(30,12,"Scream it out!",0x69);
	console.draw(30,13,"Flip that table over!",0x69);
	console.draw(30,14,"Submarine shoot-down!",0x69);
	console.draw(30,15,"Toilet Roll Catch!",0x69);
	console.draw(30,16,"Cross, but don't get Spotted!",0x69);
	console.draw(30,17,"Snapshot that blink!",0x69);
	console.draw(30,18,"Be the Virus Buster!",0x69);
	console.draw(30,19,"Pump that Rocket Sky-high!",0x69);

	if(isKeyPressed(VK_DOWN))
	{
		choice2++;
		if(choice2 > numofminigames)
		{
			choice2 = numofminigames;
		}
	}
	if(isKeyPressed(VK_UP))
	{
		choice2--;
		if(choice2 < 0)
		{
			choice2 = 0;
		}
	}
	if(isKeyPressed(VK_RETURN))
	{
		switch(choice2)
		{
			case 0:
			{
				return SCREAM;
			}
			case 1:
			{
				return TABLE_FLIP;
			}
			case 2:
			{
				return SUBMARINE;
			}
			case 3:
			{
				return TOILET_ROLL;
			}
			case 4:
			{
				return SPOTTED;
			}
			case 5:
			{
				return PHOTOSPAM;
			}
			case 6:
			{
				return VIRUS;
			}
			case 7:
			{
				return ROCKET;
			}
		}
	}
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	return GAME_SELECT;
}