#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H
#include <string>
#include <iomanip>
#include "game.h"
#include "Graphics.h"
#include "Framework\console.h"

using std::string;

class highscore
{
public:
	gamestate updatehighscore();
	highscore(Graphics&);
	void addscore(char score);
	void scorestart(char* nowname);
	void scoreend();
	~highscore()
	{
		std::ofstream savescore;
		savescore.open("score.txt");
		savescore << score;
		savescore.close();

		savescore.open("name.txt");
		savescore << name;
		savescore.close();
	}
private:
	Graphics& corn;
	void drawhighscore();
	string scoretitle;
	string score;
	string name;
	string position;
	char currentname[4];
	int totalscore;
	int numofmini;
	
	void drawmainscore();
};

#endif