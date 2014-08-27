#include "FindTwins.h"

FindTwins::FindTwins(Graphics& console)
	:
console(console),
anim(console),
showansduration(0),
picture1positionx(0),
picture2positionx(0),
picture3positionx(0),
picturepositiony(0),
pictureheight(0),
positionpictureduration(0),
positionpicture(0)
{
	srand(time(NULL));
	picture1state = (PICTURES)(rand() % TOTAL_PICTURES);
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
		UpdateState();
		UpdatePictures();
		UpdateAnimations();
	}
	Draw();
}

void FindTwins::UpdateState()
{
	
}

void FindTwins::UpdatePictures()
{
	
}

void FindTwins::UpdateAnimations()
{
}

void FindTwins::DoUserInput()
{
	if(isKeyPressed(VK_LEFT) && isKeyPressed(VK_UP))
	{
		picture1ans = true;
		picture2ans = true;
		userhasans = true;
	}
	else if(isKeyPressed(VK_LEFT) && isKeyPressed(VK_RIGHT))
	{
		picture1ans = true;
		picture3ans = true;
		userhasans = true;
	}
	else if(isKeyPressed(VK_UP) && isKeyPressed(VK_RIGHT))
	{
		picture2ans = true;
		picture3ans = true;
		userhasans = true;
	}
}

void FindTwins::Draw()
{
	if(state == INTRO)
	{
		anim.drawInstance(0,0,0x1A,INTRO);
	}
	else if(state == SETPICTURE)
	{
		console.draw(0,0,pictures[picture1index].c_str(),0x1A);
	}
	else if(state == QUESTION)
	{
		console.draw(0,0,background.c_str(),0x1A);
	}
	else if(state == SHOWANS)
	{
		
	}
	else if(state == ENDSCREEN)
	{
		
	}
}