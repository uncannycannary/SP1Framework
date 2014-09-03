#include "FindTwins.h"

FindTwins::FindTwins(Graphics& console)
	:
console(console),
anim(console),
paused(false),
userhasans(false),
wrong(false),
score(0),
currframe(0),
gameendframe(1100),
pics(L"twins\\", L"*.txt"),
namepattern(L"twins%d.txt"),
numofpictures(3),
picture1positionx(0),
picture2positionx(0),
picture3positionx(0),
picturepositiony(0),
pictureheight(0),
positionpictureduration(0),
positionpicture(0)
{
	for(int index = 0; index < numofpictures; index++)
	{
		pictures.push_back("");
		pictureans.push_back(false);
	}
	UpdatePictures();
}

FindTwins::~FindTwins()
{
}

gamestate FindTwins::update()
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if(isKeyPressed(VK_RETURN))
	{
		paused = !paused;
	}
	if(!paused)
	{
		currframe++;
		DoUserInput();
		UpdateState();
		if(userhasans)
		{
			UpdatePictures();
			userhasans = false;
		}
		//UpdateAnimations();
	}
	Draw();
	return FIND_TWINS;
}

void FindTwins::UpdateState()
{
	
}

void FindTwins::UpdatePictures()
{
	int twinsindex = rand() % pics.size();
	int herringindex = twinsindex;
	while(herringindex == twinsindex)
	{
		herringindex = rand() % pics.size();
	}

	wchar_t twinsname[15];
	wchar_t herringname[15];
	wsprintf(twinsname,namepattern.c_str(),twinsindex);
	wsprintf(herringname,namepattern.c_str(),herringindex);


	herringindex = rand() % numofpictures;
	for(int index = 0; index < numofpictures; index++)
	{
		if(index == herringindex)
		{
			pictures[index] = pics.getstring(herringname);
			pictureans[index] = false;
		}
		else
		{
			pictures[index] = pics.getstring(twinsname);
			pictureans[index] = true;
		}
	}
}

void FindTwins::UpdateAnimations()
{
}

void FindTwins::DoUserInput()
{
	if(isKeyPressed(VK_LEFT) && isKeyPressed(VK_DOWN))
	{
		ProcessAns(true, true, false);
	}
	else if(isKeyPressed(VK_LEFT) && isKeyPressed(VK_RIGHT))
	{
		ProcessAns(true, false, true);
	}
	else if(isKeyPressed(VK_DOWN) && isKeyPressed(VK_RIGHT))
	{
		ProcessAns(false, true, true);
	}
}

void FindTwins::Draw()
{
	int color;
	if(wrong)
	{
		color = 0x0C;
	}
	else
	{
		color = 0x0F;
	}
	console.draw(0,20,pictures[0].c_str(),color);
	console.draw(30,20,pictures[1].c_str(),color);
	console.draw(60,20,pictures[2].c_str(),color);
	
	{
		char buffer[15];
		sprintf(buffer,"Score %d",score);
		console.draw(46,10,buffer,0x0F);
	}
	if(currframe <= gameendframe)
	{
		char buffer[15];
		sprintf(buffer,"time %d",gameendframe - currframe);
		console.draw(46,11,buffer,0x0F);
	}
	if(state == INTRO)
	{
		anim.drawInstance(0,0,0x1A,INTRO);
	}
	else if(state == SETPICTURE)
	{
		//console.draw(0,0,pictures[picture1index].c_str(),0x1A);
	}
	else if(state == QUESTION)
	{
		//console.draw(0,0,background.c_str(),0x1A);
	}
	else if(state == SHOWANS)
	{
		
	}
	else if(state == ENDSCREEN)
	{
		
	}
}

void FindTwins::ProcessAns(bool userans1, bool userans2, bool userans3)
{
	if(userans1 == pictureans[0] && userans2 == pictureans[1] && userans3 == pictureans[2])
	{
		userhasans = true;
		score++;
		wrong = false;
	}
	else
	{
		userhasans = true;
		wrong = true;
	}
}
