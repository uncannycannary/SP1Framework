#include "highscore.h"
std::string scoretitle;

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
