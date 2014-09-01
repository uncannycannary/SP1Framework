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
	void addscore(int score);
	void scorestart(char* nowname);
	void scoreend();
	~highscore()
	{

	}
private:
	Graphics& corn;
	void drawhighscore();
	string score;
	string name;
	string position;
	char currentname[4];
	int totalscore;
	int numofmini;
	
	void drawmainscore();
};

#endif