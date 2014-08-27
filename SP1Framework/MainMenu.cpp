#include "MainMenu.h"
std::string Title;
std::string Main;
std::string Select;
int choice = 0;
int check = 0;
int choice2 = 0;
int check2 = 0;

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
	console.draw(15,3,Main.c_str(),0x25);
	console.draw(30,12,"Start game",0x25);
	console.draw(30,13,"Options",0x25);
	console.draw(30,14,"High Score",0x25);
	console.draw(30,15,"Exit game",0x25);
	if(choice == 0 && isKeyPressed(VK_DOWN))
	{
		check += 1;
		choice = check;
	}
	if(choice == 1 && isKeyPressed(VK_DOWN))
	{
		check += 1;
		choice = check;
	}
	if(choice == 2 && isKeyPressed(VK_DOWN))
	{
		check += 1;
		choice = check;
	}
	if( choice == 1 && isKeyPressed(VK_UP))
	{
		check -= 1;
		choice = check;
	}
	if( choice == 2 && isKeyPressed(VK_UP))
	{
		check -= 1;
		choice = check;
	}
	if( choice == 3 && isKeyPressed(VK_UP))
	{
		check -= 1;
		choice = check;
	}
	if(choice == 0)
	{
		console.draw(27,12,"-->",0x25);
	}
	if(choice == 1)
	{
		console.draw(27,13,"-->",0x25);
	}
	if(choice == 2)
	{
		console.draw(27,14,"-->",0x25);
	}
	if(choice == 3)
	{
		console.draw(27,15,"-->",0x25);
	}
	if(isKeyPressed(VK_RETURN))
	{
		if (choice == 0)
		{
			return GAME_SELECT;
		}
		if (choice == 1)
		{
			return OPTIONS;
		}
		if (choice == 2)
		{
			return HIGH_SCORE;
		}
		if (choice == 3)
		{
			return QUIT_GAME;
		}
	}
	return MAIN_MENU;
}

gamestate GameSelect(Graphics& console)
{
	console.draw(11,3,Select.c_str(),0x69);
	console.draw(30,12,"Scream it out!",0x69);
	console.draw(30,13,"Flip that table over!",0x69);
	console.draw(30,14,"Submarine shoot-down!",0x69);
	console.draw(30,15,"Toilet Roll Catch!",0x69);
	console.draw(30,16,"Cross, but don't get Spotted!",0x69);
	if(choice2 == 0 && isKeyPressed(VK_DOWN))
	{
		check2 += 1;
		choice2 = check2;
	}
	if(choice2 == 1 && isKeyPressed(VK_DOWN))
	{
		check2 += 1;
		choice2 = check2;
	}
	if(choice2 == 2 && isKeyPressed(VK_DOWN))
	{
		check2 += 1;
		choice2 = check2;
	}
	if(choice2 == 3 && isKeyPressed(VK_DOWN))
	{
		check2 += 1;
		choice2 = check2;
	}
	if(choice2 == 1 && isKeyPressed(VK_UP))
	{
		check2 -= 1;
		choice2 = check2;
	}
	if( choice2 == 2 && isKeyPressed(VK_UP))
	{
		check2 -= 1;
		choice2 = check2;
	}
	if( choice2 == 3 && isKeyPressed(VK_UP))
	{
		check2 -= 1;
		choice2 = check2;
	}
	if( choice2 == 4 && isKeyPressed(VK_UP))
	{
		check2 -= 1;
		choice2 = check2;
	}
	if(choice2 == 0)
	{
		console.draw(27,12,"-->",0x69);
	}
	if(choice2 == 1)
	{
		console.draw(27,13,"-->",0x69);
	}
	if(choice2 == 2)
	{
		console.draw(27,14,"-->",0x69);
	}
	if(choice2 == 3)
	{
		console.draw(27,15,"-->",0x69);
	}
	if(choice2 == 4)
	{
		console.draw(27,16,"-->",0x69);
	}
	if(isKeyPressed(VK_RETURN))
	{
		if (choice2 == 0)
		{
			return SCREAM;
		}
		if (choice2 == 1)
		{
			return TABLE_FLIP;
		}
		if (choice2 == 2)
		{
			return SUBMARINE;
		}
		if (choice2 == 3)
		{
			return TOILET_ROLL;
		}
		if (choice2 == 4)
		{
			return SPOTTED;
		}
	}
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	return GAME_SELECT;
}