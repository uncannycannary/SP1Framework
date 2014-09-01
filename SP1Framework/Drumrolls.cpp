#include "Drumrolls.h"

Drumrolls::Drumrolls(Graphics*console)
	:
higherscore(0),
framecounter(0),
DrumAnim(L"Drumrolls\\",L"*.txt"),
console(console)
{
}

void Drumrolls::playsDRcontrolsmechanics()
{
	
}

void Drumrolls::playDRstate()
{
	if(isKeyPressed(VK_LEFT))
	{
		++higherscore;
	}
	if(isKeyPressed(VK_RIGHT))
	{
		++higherscore;
	}
}

gamestate Drumrolls::playsDRmain()
{
}
