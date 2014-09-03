#include "MainMenu.h"
std::string Title;
std::string Main;
std::string Select;
int choice = 0;
int choice2 = 0;
std::vector<gamestate> random;
int currentframe = 0;
int currentstage = 0;
bool israndom = false;
bool displayscore = false;
char finalrank = 'F';
string name;

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
	console.draw(27,3,Title.c_str(),0x9D);
	console.draw(42,21,"Press Enter to Begin!" ,0x9D);
	if(isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	return INTRO;
}

gamestate MainMenu(Graphics& console,highscore* score)
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
	else if(israndom)
	{
		finalrank = score->scoreend();
		israndom = false;
		displayscore = true;
		return MAIN_MENU;
	}
	else if(displayscore)
	{
		char buffer[256];
		sprintf(buffer,"Final Rank: %c",finalrank);
		console.draw(44,20,buffer,0x0F);
		if(isKeyPressed(VK_RETURN) || isKeyPressed(VK_ESCAPE))
		{
			displayscore = false;
		}
		return MAIN_MENU;
	}
	else
	{
		console.draw(37,12+choice,"-->",0x9D);
		console.draw(25,3,Main.c_str(),0x9D);
		console.draw(40,12," Normal Mode",0x9D);
		console.draw(40,13," Random Mode",0x9D);
		console.draw(40,14," High Score ",0x9D);
		console.draw(40,15," Credits    ",0x9D);
		console.draw(40,16," Exit game  ",0x9D);

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
				return ENTER_NAME;
			case 2:
				return HIGH_SCORE;
			case 3:
				return CREDITS;
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
	israndom = true;
}

gamestate Credits(Graphics& console)
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	else
	{
		return CREDITS;
	}
}

gamestate GameSelect(Graphics& console)
{
	console.draw(34,12+choice2,"-->",0x9D);
	console.draw(20,2,Select.c_str(),0x9D);
	console.draw(37,12," Scream it out!               ",0x9D);
	console.draw(37,13," Flip that table over!        ",0x9D);
	console.draw(37,14," Submarine shoot-down!        ",0x9D);
	console.draw(37,15," Toilet Roll Catch!           ",0x9D);
	console.draw(37,16," Cross, but don't get Spotted!",0x9D);
	console.draw(37,17," Snapshot that blink!         ",0x9D);
	console.draw(37,18," Fill that candy jar up!      ",0x9D);
	console.draw(37,19," Pump that Rocket Sky-high!   ",0x9D);
	console.draw(37,20," Get the twins!               ",0x9D);
	console.draw(37,21," Ice Kachang eat-out!         ", 0x9D);

	if(isKeyPressed(VK_DOWN))
	{
		choice2++;
		if(choice2 > numofminigames - 1)
		{
			choice2 = numofminigames - 1;
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
				return CANDY;
			}
		case 7:
			{
				return ROCKET;
			}
		case 8:
			{
				return FIND_TWINS;
			}
		case 9:
			{
				return ICECHAN;
			}
		}
	}
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	return GAME_SELECT;
}

gamestate EnterName(Graphics& console, highscore* score)
{
	if(name.empty())
	{
		name += "AAA";
	}
	while(char letter = getkeyboardbuffer())
	{
		string l;
		l += letter;
		name.insert(0,l);
		name.pop_back();
	}
	char buffer[256] = "Please enter your name: ";
	strcat(buffer,name.c_str());
	console.draw(37,10,buffer,0x0f);
	if(isKeyPressed(VK_RETURN))
	{
		score->scorestart(name.c_str());
		return MAIN_MENU;
	}
	else
	{
		return ENTER_NAME;
	}
}