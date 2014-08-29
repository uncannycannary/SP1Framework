#include "minihighscore.h"
std::string results;

gamestate minihigh::update()
{
	console.draw(15,1,judgement.getstring(L"results.txt").c_str(),0x2A);
	console.draw(2,10,judgement.getstring(L"comment.txt").c_str(),0x2A);
	console.draw(7,10,judgement.getstring(L"rank.txt").c_str(),0x2A);

	if(*state == ROCKET)
	{
		console.draw(45,10,judgement.getstring(L"rocketscore.txt").c_str(),0x2A);
	}

	if(isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	return HIGH_SCORE;
}