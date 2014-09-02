#include "Credits.h"

Credits::Credits(Graphics* console)
	:
framecounter(0),
CreditsText(L"Credits//",L"*.txt"),
console(console)
{
}

gamestate Credits::playCredits()
{
	++framecounter;
	if(framecounter >= 0  && framecounter <= 150)
	{
		console->draw(0,0,CreditsText.getstring(L"Credits1.txt").c_str(),0xB2);
	}
	if(framecounter >= 150 && framecounter <= 300)
	{
		console->draw(0,0,CreditsText.getstring(L"Credits2.txt").c_str(),0xB2);
	}
	if(framecounter >= 300 && framecounter <= 450)
	{
		console->draw(0,0,CreditsText.getstring(L"Credits3.txt").c_str(),0xB2);
	}
	if(framecounter >= 450 && framecounter <= 600)
	{
		console->draw(0,0,CreditsText.getstring(L"Credits4.txt").c_str(),0xB2);
	}
	return CREDITS;
}