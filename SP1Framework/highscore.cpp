#include "highscore.h"
#include <math.h>
std::string scoretitle;

void highscore::addscore(char gamescore)
{
	if(gamescore >= 'A' && gamescore <= 'F')
	{
		numofmini++;
		totalscore += gamescore;
	}
	else if(gamescore == 'S')
	{
		numofmini++;
		totalscore += 'A' - 1;
	}
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
	corn.draw(15,1,scoretitle.c_str(),0x9D);
	corn.draw(2,10,position.c_str(),0x9D);
	corn.draw(7,10,name.c_str(),0x9D);
	corn.draw(45,10,score.c_str(),0x9D);


	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	return HIGH_SCORE;
}

void highscore::scorestart(const char* nowname)
{
	totalscore = 0;
	numofmini = 0;
	strcpy(currentname,nowname);
}

char highscore::scoreend()
{
	char currscore = 'F';
	if(numofmini)
	{
		currscore = ceil(totalscore/(float)numofmini);
		int index = 0;
		bool scoreadded = false;
		for(int i = 0; i < score.size(); i++)
		{
			
			if( score[i] == '\n')
			{
				continue;
			}
			else
			{
				char letter = score[i];
				if(letter == 'S')
				{
					letter = 'A' - 1;
				}
				if(currscore <= letter)
				{
					if(currscore == 'A' - 1)
					{
						currscore = 'S';
					}
					string buffer;

					buffer += currscore;
					buffer += "\n\n";		

					score.insert(i,buffer);
					for(int index = 0; index < 3; index++)
					{
						score.pop_back();
					}
					scoreadded = true;
					break;
				}
				else
				{
					index++;
				}
			}
		}
		if(scoreadded)
		{
			std::vector<string> namebuffer;
			int namepass = 0;
			for(int nameindex = 0; nameindex < name.size(); nameindex += 5)
			{
				namebuffer.push_back(name.substr(nameindex,5));
				namepass ++;
			}
			{
				string buffer = currentname;
				buffer += "\n\n";
				namebuffer.insert(namebuffer.begin() + index,buffer);
				namebuffer.pop_back();
				name.clear();
				for(int namedelete = 0; namedelete < namebuffer.size(); namedelete++)
				{
					name += namebuffer[namedelete];
				}
			}
		}
	}
	if(currscore == 'A' - 1)
	{
		currscore = 'S';
	}
	return currscore;
}