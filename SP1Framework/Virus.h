#ifndef _VIRUS_H
#define _VIRUS_H

#include <string>
#include "game.h"
#include "Framework\console.h"
#include "Animations.h"

class Virus
{
public:
	gamestate update(Graphics* console);
	Virus()
		:
	VirusFile(L"Virus\\",L"*.txt")
	{
		GameStarts = false;
		gameends = false;
		fileempty = false;
		firegun = false;
		checkfile = 0;
		penalty = 0;
		CurrentFramePerSec = 0;
	}
	~Virus()
	{
	}
private:
	void draw(Graphics* Virus);
	void play();
	bool fileempty;
	bool firegun;
	int files;
	int virus;
	int CurrentFramePerSec;
	Directory VirusFile;
	bool GameStarts;
	bool gameends;
	int checkfile;
	int penalty;
};

#endif