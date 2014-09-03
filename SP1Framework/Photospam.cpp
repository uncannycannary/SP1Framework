#include "Photospam.h"

photospam::photospam(Graphics& console)
	:
console(console)
{
	CurrentFrame = 0;
	srand(time(NULL));
	a = 0;
	b = 0;
	c = 0;
	wrong = false;
	score = 0;
	set = 500;
	read();
}

gamestate photospam::update()
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	draw();
	play();

	if(CurrentFrame >= 1310 && isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	else
	{
		return PHOTOSPAM;
	}
}

void photospam::play()
{

	if(CurrentFrame == 439 || CurrentFrame == 589 || CurrentFrame == 739)
	{
		a = rand() % 2;
		b = rand() % 2;
		if(a == 0)
		{
			b = 1;
			c = 1;
		}
		else if(b == 0)
		{
			c = 1;
		}
		else
		{
			c = 0;
		}
	}

	if(CurrentFrame == 889 || CurrentFrame == 1039)
	{
		a = rand() % 2;
		if(a == 0)
		{
			b = rand() % 2;
			if(b == 0)
			{
				c = 1;
			}
			else
			{
				c = 0;
			}
		}
		else
		{
			b = 0;
			c = 0;
		}
	}

	if(CurrentFrame == 1189)
	{
		a = 0;
		b = 0;
		c = 0;
	}

	if((CurrentFrame >= 440 && CurrentFrame <= 500) || (CurrentFrame >= 590 && CurrentFrame <= 650) || (CurrentFrame >= 740 && CurrentFrame <= 800) || (CurrentFrame >= 890 && CurrentFrame <= 950) || (CurrentFrame >= 1040 && CurrentFrame <= 1100) || (CurrentFrame >= 1190 && CurrentFrame <= 1250))
	{
		if(a == 0)
		{
			if(isKeyPressed(VK_LEFT))
				++score;
			if(isKeyHold(VK_LEFT))
				console.draw(11,30, snaps.c_str(), 0x0F);
		}
		else
		{
			if(isKeyPressed(VK_LEFT))
			{
				CurrentFrame+=(set - CurrentFrame);
				wrong = true;
			}
		}

		if(b == 0)
		{
			if(isKeyPressed(VK_DOWN))
				++score;
			if(isKeyHold(VK_DOWN))
				console.draw(36,15, snaps.c_str(), 0x0F);
		}
		else
		{
			if(isKeyPressed(VK_DOWN))
			{
				CurrentFrame+=(set - CurrentFrame);
				wrong = true;
			}
		}

		if(c == 0)
		{
			if(isKeyPressed(VK_RIGHT))
				++score;
			if(isKeyHold(VK_RIGHT))
				console.draw(61,30, snaps.c_str(), 0x0F);
		}
		else
		{
			if(isKeyPressed(VK_RIGHT))
			{
				CurrentFrame+=(set - CurrentFrame);
				wrong = true;
			}
		}
	}
	if(CurrentFrame == 530 || CurrentFrame == 680 || CurrentFrame == 830 || CurrentFrame == 980 || CurrentFrame == 1130)
	{
		wrong = false;
		set+=150;
	}
	CurrentFrame++;
}

void photospam::read()
{
	diamond.open("ascii/diamond.txt");
	while(!diamond.eof())
	{
		diamonds.push_back(diamond.get());
	}
	diamond.close();
	diamonds.pop_back();

	poop.open("ascii/shyt.txt");
	while(!poop.eof())
	{
		poops.push_back(poop.get());
	}
	poop.close();
	poops.pop_back();

	snap.open("ascii/snap.txt");
	while(!snap.eof())
	{
		snaps.push_back(snap.get());
	}
	snap.close();
	snaps.pop_back();

	cross.open("ascii/cross.txt");
	while(!cross.eof())
	{
		crosss.push_back(cross.get());
	}
	cross.close();
	crosss.pop_back();

	box.open("ascii/box.txt");
	while(!box.eof())
	{
		boxs.push_back(box.get());
	}
	box.close();
	boxs.pop_back();
}

void photospam::draw()
{
	if(CurrentFrame >= 0 && CurrentFrame <= 59)
	{
		console.draw(45,20,"PHOTO SPAM", 0x0F);
	}
	if(CurrentFrame >= 60 && CurrentFrame <= 300)
	{
		console.draw(45,20,"How to play", 0x0F);
		console.draw(29,22,"   Press <, V and > keys to take photos\ntake as many photos of diamonds as you can\n       but dont take photo of poop!", 0x0F);
	}

	if(CurrentFrame >= 300 && CurrentFrame <= 330)
	{	
		console.draw(48,20,"Ready?", 0x0F);
	}

	if(CurrentFrame >= 330 && CurrentFrame <= 360)
	{	
		console.draw(50,20,"3", 0x0F);
	}

	if(CurrentFrame >= 360 && CurrentFrame <= 390)
	{	
		console.draw(50,20,"2", 0x0F);
	}

	if(CurrentFrame >= 390 && CurrentFrame <= 420)
	{	
		console.draw(50,20,"1", 0x0F);
	}

	if(CurrentFrame >= 420 && CurrentFrame <= 439)
	{	
		console.draw(49,20,"GO!", 0x0F);
	}

	if(CurrentFrame >= 440 && CurrentFrame <= 1310)
	{
		char buffer[11];
		sprintf(buffer,"Score: %d",score);
		console.draw(46,40, buffer, 0x0F);
	}

	if((CurrentFrame >= 440 && CurrentFrame <= 500) || (CurrentFrame >= 590 && CurrentFrame <= 650) || (CurrentFrame >= 740 && CurrentFrame <= 800) || (CurrentFrame >= 890 && CurrentFrame <= 950) || (CurrentFrame >= 1040 && CurrentFrame <= 1100) || (CurrentFrame >= 1190 && CurrentFrame <= 1250))
	{
		if(a == 0)
		{
			console.draw(18,20, diamonds.c_str(), 0x0F);
		}
		else if(a == 1)
		{
			console.draw(18,20, poops.c_str(), 0x0F);
		}

		if(b == 0)
		{
			console.draw(43,20, diamonds.c_str(), 0x0F);
		}
		else if(b == 1)
		{
			console.draw(43,20, poops.c_str(), 0x0F);
		}

		if(c == 0)
		{
			console.draw(68,20, diamonds.c_str(), 0x0F);
		}
		else if(c == 1)
		{
			console.draw(68,20, poops.c_str(), 0x0F);
		}
	}

	if((CurrentFrame >= 500 && CurrentFrame <= 530) || (CurrentFrame >= 650 && CurrentFrame <= 680) || (CurrentFrame >= 800 && CurrentFrame <= 830) || (CurrentFrame >= 950 && CurrentFrame <= 980) || (CurrentFrame >= 1100 && CurrentFrame <= 1130))
	{
		if(wrong == true)
		{
			console.draw(40,22, crosss.c_str(), 0x0F);
		}
		else
		{
			CurrentFrame+=30;
		}
	}

	if(CurrentFrame >= 530 && CurrentFrame <= 590 || CurrentFrame >= 680 && CurrentFrame <= 740 || CurrentFrame >= 830 && CurrentFrame <= 890 || CurrentFrame >= 980 && CurrentFrame <= 1040 || CurrentFrame >= 1130 && CurrentFrame <= 1190 || CurrentFrame >= 1250 && CurrentFrame <= 1310)
	{
		console.draw(18,20, boxs.c_str(), 0x0F);
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_DOWN) || isKeyPressed(VK_RIGHT))
		{
			wrong = false;
		}
	}

	if(CurrentFrame >= 1310)
	{
		if(score > 110 )
		{
			rank = 'S';
		}
		if(score > 100 && score <= 110)
		{
			rank = 'A';
		}
		if(score > 85 && score <= 100)
		{
			rank = 'B';
		}
		if(score > 70 && score <= 85)
		{
			rank = 'C';
		}
		if(score > 55 && score <= 70)
		{
			rank = 'D';
		}
		if(score > 40 && score <= 55)
		{
			rank = 'E';
		}
		if(score <= 40)
		{
			rank = 'F';
		}
		char rankbuffer[10];
		sprintf(rankbuffer, "Rank: %c", rank);
		console.draw(47,19, rankbuffer, 0x0F);

		char buffer[256];
		console.draw(36,19, "Just kidding, the game ended", 0x0F);
		sprintf(buffer,"You have scored: %d",score);
		console.draw(41,20, buffer, 0x0F);
		console.draw(37,22, "Press Enter to continune...", 0x0F);
	}
}

char photospam::returnscore()
{
	return score;
}