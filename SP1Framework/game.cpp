#include "game.h"

Game::Game()
	:
score(console),
state(MAIN_MENU),
mainmenu(console,&score)
{
	srand(time(NULL));
	updateinput();

	//credit = NULL:
	scream = NULL;
	toilet = NULL;
	spam = NULL;
	flip = NULL;
	spot = NULL;
	twins = NULL;
	submarine = NULL;
	candy = NULL;
	rocket = NULL;
	icekan = NULL;
}

Game::~Game()
{
}

bool Game::Update(double dt)
{
	updateinput();
	switch(state)
	{
	case MAIN_MENU:
		state = mainmenu.Update();
		break;
	case TABLE_FLIP:
		if(flip == NULL)
		{
			flip = new TableFlip;
		}

		state = flip->updateTableFlip(&console);

		if(state != TABLE_FLIP)
		{
			score.addscore(flip->returnscore());
			delete flip;
			flip = NULL;
		}
		break;
	case SUBMARINE:
		if(submarine == NULL)
		{
			submarine = new subgame(&console);
		}
		state = submarine->playsubgamemain();
		if(state != SUBMARINE)
		{
			score.addscore(submarine->returnscore());
			delete submarine;
			submarine = NULL;
		}
		break;
	case TOILET_ROLL:
		if(toilet == NULL)
		{
			
			toilet = new toiletroll(console);
		}

		state = toilet->update();

		if(state != TOILET_ROLL)
		{
			score.addscore(toilet->returnscore());
			delete toilet;
			toilet = NULL;
		}
		break;
	case ICECHAN:
		if(icekan == NULL)
		{
			icekan = new IKR(&console);
		}
		state = icekan->playIKRgame();

		if(state != ICECHAN)
		{
			score.addscore(icekan->returnscore());
			delete icekan;
			icekan = NULL;
		}
		break;
	case SCREAM:
		if(scream == NULL)
		{
			scream = new Scream(console);
		}

		state = scream->update();

		if(state != SCREAM)
		{
			score.addscore(scream->returnscore());
			delete scream;
			scream = NULL;
		}
		break;
	case SPOTTED:
		if(spot == NULL)
		{
			spot = new Spotted;
		}

		state = spot->updateSpotted(&console);

		if(state != SPOTTED)
		{
			score.addscore(spot->returnscore());
			delete spot;
			spot = NULL;
		}
		break;
	case FIND_TWINS:
		if(twins == NULL)
		{
			twins = new FindTwins(console);
		}

		state = twins->update();

		if(state != FIND_TWINS)
		{
			score.addscore(twins->returnscore());
			delete twins;
			twins = NULL;
		}
		break;
	case PHOTOSPAM:
		if(spam == NULL)
		{
			spam = new photospam(console);
		}
		
		state = spam->update();

		if(state != PHOTOSPAM)
		{
			score.addscore(spam->returnscore());
			delete spam;
			spam = NULL;
		}
		break;
	case ROCKET:
		if(rocket == NULL)
		{
			rocket = new pumprocket(console);
		}

		state = rocket->update();

		if(state != ROCKET)
		{
			score.addscore(rocket->returnscore());
			delete rocket;
			rocket = NULL;
		}
		break;
	case CANDY:
		if(candy == NULL)
		{
			candy = new Candy(console);
		}

		state = candy->update();

		if(state != CANDY)
		{
			score.addscore(candy->returnscore());
			delete candy;
			candy = NULL;
		}
		break;
	case HIGH_SCORE:
		state = score.updatehighscore();
		break;
	case QUIT_GAME:
		return true;
		break;
	}
	return false;
}

void Game::Render()
{
	console.updateconsole();
}
