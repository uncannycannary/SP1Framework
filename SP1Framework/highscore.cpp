#include "highscore.h"
std::string scoretitle;

void highscore::addscore(int gamescore)
{

	totalscore += gamescore;
}

highscore::highscore(Graphics& console)
	:
corn(console)
{
	std::ifstream readscoretitle;
	readscoretitle.open ("highscore.txt"); // associate & open files
	while (!readscoretitle.eof()) 
	{
		scoretitle += readscoretitle.get();
	}
	scoretitle.pop_back();
	readscoretitle.close ();

	std::ifstream readposition;
	readposition.open ("Position.txt"); // associate & open files
	char lol = 'z';
	while(!readposition.eof())
	{
		lol = readposition.get();
		position += lol;
	}
	position.pop_back();
	readposition.close ();

	std::ifstream readname;
	readname.open ("name.txt"); // associate & open files
	char pol = 'z';
	while(!readname.eof())
	{
		pol = readname.get();
		name += pol;
	}
	name.pop_back();
	readname.close ();

	std::ifstream readscore;
	readscore.open ("score.txt"); // associate & open files
	char lop = 'z';
	while(!readscore.eof())
	{
		lop = readscore.get();
		score += lop;
	}
	score.pop_back();
	readscore.close ();

	totalscore = 0;
	numofmini = 0;
	strcpy(currentname,"END");
}
gamestate highscore::updatehighscore()
{
	corn.draw(15,1,scoretitle.c_str(),0x2A);
	corn.draw(2,10,position.c_str(),0x2A);
	corn.draw(7,10,name.c_str(),0x2A);
	corn.draw(45,10,score.c_str(),0x2A);
	

	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	return HIGH_SCORE;
}

void highscore::scorestart(char* nowname)
{
	totalscore = 0;
	numofmini = 0;
	strcpy(currentname,nowname);
}

void highscore::scoreend()
{
	int currscore;
	currscore = totalscore/numofmini;
	std::vector<int> scores;
	std::string buffer;
	for(int i = 0; i < score.size(); i++)
	{
		if(score[i] != '\n')
		{	int num = 0;
			for(int i = 0; i < buffer.size(); i++)
			{
				num = i - 48;
			}
			scores.push_back(num);
			buffer.empty();
		}
		else
		{
			buffer += score[i];
		}
	}
}