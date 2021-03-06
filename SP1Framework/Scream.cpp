#include "Scream.h"


Scream::Scream(Graphics& console)
	:
console(console),
power(0),
file(L"scream\\",L"*.txt"),
currFrame(0),
rank('F'),
paused(false),
gameends(false),
lockinput(true),
InstructionsFrame(60),
CountdownFrame(200),
GameStartFrame(350),
GameEndFrame(550),
EndscreenFrame(600),
powerbarcolor(0x1A),
introcolor(0x0F),
PowerToPixelRatio(1550),
PowerToResistanceRatio(80),
PowerIncrement(1000),
PowerbarPositionX(90),
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

	countdown.push_back(file.getstring(L"ready.txt"));
	countdown.push_back(file.getstring(L"three.txt"));
	countdown.push_back(file.getstring(L"two.txt"));
	countdown.push_back(file.getstring(L"one.txt"));
	countdown.push_back(file.getstring(L"go.txt"));

	introindex = anim.Add(&intro, 1);
	countdownindex = anim.Add(&countdown, 30);
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
	if(currFrame >= EndscreenFrame)
	{
		char buffer[10];
		sprintf(buffer, "Rank: %c",rank);
		console.draw(47,20,buffer,0x0F);
	}
	anim.drawInstance(0, 0, introcolor, introindex);
	anim.drawInstance(0, 0, 0x0F, countdownindex);

	const int powerbarheight = power / PowerToPixelRatio;
	for(int index = 0; index < powerbarheight; index++)
	{
		console.draw(PowerbarPositionX, PowerbarPositionY - index, "****", powerbarcolor);
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
	else if(currFrame>=EndscreenFrame && isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	else if(isKeyPressed(VK_RETURN))
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
	if(currFrame >= CountdownFrame)
	{
		anim.playInstance(countdownindex,false);
	}

	if(currFrame == InstructionsFrame)
	{
		anim.playInstance(introindex);
	}
	else if(currFrame == CountdownFrame)
	{
		anim.playInstance(introindex);
	}
	else if(currFrame == GameStartFrame)
	{
		lockinput = false;
	}
	else if(currFrame == GameEndFrame)
	{
		lockinput = true;
		anim.playInstance(introindex);
	}
	else if(currFrame == EndscreenFrame)
	{
		//introcolor = 0x0C;
		anim.playInstance(introindex);
		if(power < 10000)
		{
			rank = 'F';
		}
		else if(power < 20000)
		{
			rank = 'E';
		}
		else if(power < 30000)
		{
			rank = 'D';
		}
		else if(power < 40000)
		{
			rank = 'C';
		}
		else if(power < 50000)
		{
			rank = 'B';
		}
		else if(power < 60000)
		{
			rank = 'A';
		}
		else
		{
			rank = 'S';
		}
	}
}


char Scream::returnscore()
{
	return rank;
}