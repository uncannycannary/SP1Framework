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
InstructionsFrame(50),
GameStartFrame(100),
GameEndFrame(260),
powerbarcolor(0x1A),
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
	intro.push_back(file.getstring(L"title.txt"));
	intro.push_back(file.getstring(L"instructions.txt"));
	intro.push_back(file.getstring(L"dragon.txt"));
	intro.push_back(file.getstring(L"dovakin.txt"));
	intro.push_back(file.getstring(L"dovakinkillsdragon.txt"));
	introindex = anim.Add(&intro, 0, 0, 1);
	anim.playInstance(introindex);
}

Scream::~Scream()
{
}

void Scream::draw()
{
	if(currFrame == GameEndFrame)
	{
		powerbarcolor = 0x25;
	}
	anim.drawInstance(0, 0, 0x1A, introindex);

	const int powerbarheight = power / PowerToPixelRatio;
	for(int index = 0; index < powerbarheight; index++)
	{
		console.draw(PowerbarPositionXTop, PowerbarPositionY - 1, "___", 0x1A);
		console.draw(PowerbarPositionXBottom, PowerbarPositionY - index, "****", powerbarcolor);
	}
	if(currFrame >= GameStartFrame && currFrame <= 130)
	{
		console.draw(40,30,"Go",0x0F);
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
		changestate();
		if(currFrame < GameEndFrame)
		{
			UpdatePowerbar();
		}
	}
	draw();

	return SCREAM;
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
	if(currFrame == InstructionsFrame)
	{
		anim.playInstance(introindex);
	}
	else if(currFrame == GameStartFrame)
	{
		lockinput = false;
		anim.playInstance(introindex);
	}
	else if(currFrame == GameEndFrame)
	{
		lockinput = true;
		anim.playInstance(introindex);
	}
	else if(currFrame == EndscreenFrame)
	{
		anim.playInstance(introindex);
	}
}