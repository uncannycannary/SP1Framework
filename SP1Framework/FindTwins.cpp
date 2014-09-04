#include "FindTwins.h"

FindTwins::FindTwins(Graphics& console)
	:
console(console),
	anim(console),
	paused(false),
	rank('F'),
	lockinput(true),
	userhasans(false),
	wrong(false),
	score(0),
	currframe(0),
	keysreleased(true),
	instructionsframe(60),
	countdownframe(200),
	gamestartframe(350),
	gameendframe(900),
	endscreenframe(950),
	pics(L"twins\\pics\\", L"*.txt"),
	mainfolder(L"twins\\",L"*.txt"),
	namepattern(L"twins%d.txt"),
	numofpictures(3)
{
	for(int index = 0; index < numofpictures; index++)
	{
		pictures.push_back("");
		pictureans.push_back(false);
	}
	UpdatePictures();

	intro.push_back(mainfolder.getstring(L"title.txt"));
	intro.push_back(mainfolder.getstring(L"instructions.txt"));
	countdown.push_back(mainfolder.getstring(L"ready.txt"));
	countdown.push_back(mainfolder.getstring(L"three.txt"));
	countdown.push_back(mainfolder.getstring(L"two.txt"));
	countdown.push_back(mainfolder.getstring(L"one.txt"));
	countdown.push_back(mainfolder.getstring(L"go.txt"));
	introindex = anim.Add(&intro,1);
	countdownindex = anim.Add(&countdown,30);

	anim.playInstance(introindex);
}

FindTwins::~FindTwins()
{
}

gamestate FindTwins::update()
{
	if(isKeyReleased(VK_LEFT) && isKeyReleased(VK_UP) && isKeyReleased(VK_RIGHT))
	{
		keysreleased = true;
	}

	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if(currframe >= gameendframe &&isKeyPressed(VK_RETURN))
	{
		return  MAIN_MENU;
	}
	//else if(isKeyPressed(VK_RETURN))
	//{
		//paused = !paused;
	//}
	
	if(gameendframe == 0 && isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	if(!paused)
	{
		currframe++;
		if(!lockinput && keysreleased)
		{
			DoUserInput();
		}
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
	if(currframe >= countdownframe)
	{
		anim.playInstance(countdownindex,false);
	}

	if(currframe == instructionsframe)
	{
		anim.playInstance(introindex,false);
	}
	else if(currframe == countdownframe)
	{
		anim.playInstance(introindex,false);
	}
	else if(currframe == gamestartframe)
	{
		lockinput = false;
	}
	else if(currframe == gameendframe)
	{
		lockinput = true;
		if(score < 5)
		{
			rank = 'F';
		}
		else if(score < 10)
		{
			rank = 'E';
		}
		else if(score < 15)
		{
			rank = 'D';
		}
		else if(score < 20)
		{
			rank = 'C';
		}
		else if(score < 25)
		{
			rank = 'B';
		}
		else if(score < 30)
		{
			rank = 'A';
		}
		else
		{
			rank = 'S';
		}
	}
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
	keysreleased = false;
}

void FindTwins::DoUserInput()
{
	if(currframe <= gameendframe)
	{
		if(isKeyHold(VK_LEFT) && isKeyHold(VK_DOWN))
		{
			ProcessAns(true, true, false);
		}
		else if(isKeyHold(VK_LEFT) && isKeyHold(VK_RIGHT))
		{
			ProcessAns(true, false, true);
		}
		else if(isKeyHold(VK_DOWN) && isKeyHold(VK_RIGHT))
		{
			ProcessAns(false, true, true);
		}
	}
}

void FindTwins::Draw()
{
	anim.drawInstance(0,0,0x0F,introindex);
	anim.drawInstance(0, 0, 0x0F, countdownindex);
	if(currframe >= gamestartframe && currframe < gameendframe)
	{
		char timebuffer[15];
		sprintf(timebuffer,"time %d",(gameendframe - currframe)/30);
		console.draw(46,11,timebuffer,0x0F);

		char scorebuffer[15];
		sprintf(scorebuffer,"Score %d",score);
		console.draw(46,10,scorebuffer,0x0F);

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
	}
	else if(currframe >= gameendframe)
	{
		char scorebuffer[15];
		char rankbuffer[10];
		sprintf(scorebuffer,"Score %d",score);
		sprintf(rankbuffer,"Rank  %c",rank);
		console.draw(46,10,scorebuffer,0x0F);
		console.draw(46,9,rankbuffer,0x0F);
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
		score -= 3;
		userhasans = true;
		wrong = true;
	}
}

char FindTwins::returnscore()
{
	return rank;
}