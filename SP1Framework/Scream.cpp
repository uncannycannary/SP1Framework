#include "Scream.h"


Scream::Scream(Graphics& console)
	:
console(console),
power(0),
resistance(0),
currFrame(0),
paused(true),
gameends(false),
anim(console)
{
	someanim.push_back("lololol\nlololol");
	someanim.push_back("ROROROROR");
	int anim1Index = anim.Add(&someanim,1,1,15);
}

Scream::~Scream()
{
}

void Scream::draw()
{
}

gamestate Scream::update()
{
	anim.update();
	if(!anim.InstanceIsPlaying(0))
	{
		anim.playInstance(0);
	}
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	if(isKeyPressed(VK_RETURN))
	{
		paused = !paused;
	}
	if(paused)
	{
		console.draw(10,10,"Paused",0x1A);
		return SCREAM;
	}
	else
	{
		anim.drawInstance(0, 0, 0x1A, 0);
		currFrame++;
		gameends = play();
		draw();
		if(gameends)
		{
			gamestate state = (gamestate)(rand() % numofminigames);
			return state;
		}
		return SCREAM;
	}
}

bool Scream::play()
{
	return false;
}