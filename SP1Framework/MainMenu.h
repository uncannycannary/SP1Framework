#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "highscore.h"
#include "Framework\console.h"
#include <iostream>
#include "Graphics.h"
#include "Directory.h"

class MainMenu
{
public:
	MainMenu(Graphics&, highscore*);
	~MainMenu();
	gamestate Update();
private:
	Graphics& console;
	highscore* score;

	enum STATE
	{
		TITLE,
		MENU,
		GAME_SELECT,
		RANDOM,
		ENTER_NAME,
		CREDITS,
		HIGHSCORE,
		MAX_STATE
	};

	STATE state;

	std::string Title;
	std::string Menu;
	std::string Select;
	Directory credits;
	int choice;
	int choice2;
	std::vector<gamestate> random;
	int currentframe;
	int currentstage;
	bool israndom;
	bool entername;
	bool displayscore;
	char finalrank;
	string name;

	void Intro();
	void EnterName();
	gamestate Main();
	gamestate GameSelect();
	gamestate Random();
	gamestate Credits();
	void randommode();
};


#endif