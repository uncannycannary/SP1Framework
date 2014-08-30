#include "minihighscore.h"
std::string results;

gamestate minihigh::update()
{
	console.draw(15,1,judgement.getstring(L"results.txt").c_str(),0x2A);
	console.draw(7,10,judgement.getstring(L"rank.txt").c_str(),0x2A);

	if(*state == TABLE_FLIP)
	{
		console.draw(2,10,judgement.getstring(L"tablescore.txt").c_str(),0x2B);
	}

	if(*state == TOILET_ROLL)
	{
		console.draw(2,10,judgement.getstring(L"toiletscore.txt").c_str(),0x2B);
	}

	if(*state == SPOTTED)
	{
		console.draw(2,10,judgement.getstring(L"spottedscore.txt").c_str(),0x2B);
	}

	if(*state == PHOTOSPAM)
	{
		console.draw(2,10,judgement.getstring(L"photoscore.txt").c_str(),0x2B);
	}

	if(*state == ROCKET)
	{
		console.draw(2,10,judgement.getstring(L"rocketscore.txt").c_str(),0x2B);
	}

	if(isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	return HIGH_SCORE;
}

void draw()
{

}