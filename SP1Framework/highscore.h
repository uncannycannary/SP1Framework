#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H
#include <string>
#include <iomanip>
#include "Graphics.h"
#include "Framework\console.h"

using std::string;

class highscore
{
public:

	highscore(Graphics* console)
	{
		corn = console;

	}
	~highscore()
	{
	}
private:
	Graphics* corn;
	char rank[10];
	char* name[10]; 
	char* position[10];
	void drawmainscore();
};

#endif