#include "Scream.h"


Scream::Scream(Graphics& console)
	:
console(console),
power(0),
file(L"scream\\",L"*.txt"),
currFrame(0),
paused(false),
gameends(false),
lockinput(true),
GameStartFrame(100),
GameEndFrame(260),
EndscreenFrame(300),
PowerToPixelRatio(1550),
PowerToResistanceRatio(80),
PowerIncrement(1000),
PowerbarPositionXTop(80),
PowerbarPositionXBottom(40),
PowerbarPositionY(40),
drawPauseX(47),
drawPauseY(30),
anim(console)
{
	endscreen = "lol";
	Dovakin.push_back(file.getstring(L"dragon.txt"));
	Dovakin.push_back("lolzerssssssssss");
	anim.Add(&Intro, 0, 0, 1);
	anim.Add(&Dovakin, 0, 0, 1);
	anim.Add(&Dragon, 0, 0, 1);
	anim.Add(&Dovakin_kills_dragon, 0, 0, 1);
	anim.playInstance(INTRO);
}

Scream::~Scream()
{
}

void Scream::draw()
{
	anim.drawInstance(0, 0, 0x1A, INTRO);
	anim.drawInstance(0, 0, 0x1A, DOVAKIN);
	anim.drawInstance(0, 0, 0X1A, DRAGON);
	anim.drawInstance(0, 0, 0x1A, DOVAKIN_KILLS_DRAGON);

	const int powerbarheight = power / PowerToPixelRatio;
	for(int index = 0; index < powerbarheight; index++)
	{
		console.draw(PowerbarPositionXTop, PowerbarPositionY - 1, powerbar.c_str(), 0x1A);
		console.draw(PowerbarPositionXBottom, PowerbarPositionY - index, "****", 0x1A);
	}

	if(currFrame > EndscreenFrame)
	{
		console.draw(0, 0, endscreen.c_str(), 0x1A);
	}
	if(paused)
	{
		console.draw(drawPauseX, drawPauseY, "Paused", 0x1A);
	}
}

gamestate Scream::update()
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
		currFrame++;
		if(!lockinput)
		{
			DoUserInput();
		}
		UpdateAnim();
		changestate();
	}
	draw();

	return SCREAM;
}

void Scream::UpdateAnim()
{
	anim.update();
	const int delay = power;
	//anim.ChangeDelay(DOVAKIN_KILLS_DRAGON, delay);
}

void Scream::UpdatePowerbar()
{
	const int resistance = power / PowerToResistanceRatio;
	power -= resistance;
	if(power < 0)
	{
		power = 0;
	}
}

void Scream::DoUserInput()
{
	if(isKeyPressed(VK_LEFT))
	{
		power+=PowerIncrement;
	}
	if(isKeyPressed(VK_DOWN))
	{
		power+=PowerIncrement;
	}
	if(isKeyPressed(VK_RIGHT))
	{
		power+=PowerIncrement;
	}
}

void Scream::changestate()
{
	if(currFrame == GameStartFrame)
	{
		lockinput = false;
		anim.playInstance(DOVAKIN);
		anim.playInstance(DRAGON);
		UpdatePowerbar();
	}
	else if(currFrame > GameStartFrame && !(currFrame >= GameEndFrame))
	{
		anim.playInstance(DOVAKIN);
		anim.playInstance(DRAGON);
		UpdatePowerbar();
	}
	else if(currFrame == GameEndFrame)
	{
		lockinput = true;
		anim.stop(DOVAKIN);
		anim.stop(DRAGON);
		anim.playInstance(DOVAKIN_KILLS_DRAGON);
	}
	else if(currFrame > GameEndFrame && !(currFrame >= EndscreenFrame))
	{
		anim.playInstance(DOVAKIN_KILLS_DRAGON);
	}
	else if(currFrame == EndscreenFrame)
	{
		anim.stop(DOVAKIN_KILLS_DRAGON);
	}
}