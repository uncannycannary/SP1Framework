#include "ToiletRoll.h"

toiletroll::toiletroll(Graphics& console)
	:
console(console)
{
	CurrentFrame = 0;
	rhold = false;
	lhold = false;
	rholdcount = 0;
	lholdcount = 0;
	y = 0;
	rx = 60;
	lx = 25;
	score = 0;
	rank = 'F';
	read();
}

gamestate toiletroll::update()
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	draw();
	play();
	
	if(CurrentFrame >= 728 && isKeyPressed(VK_RETURN))
	{
		return MAIN_MENU;
	}
	else
	{
		return TOILET_ROLL;
	}
}

void toiletroll::play()
{
	if (CurrentFrame >= 370)
	{
		if(!isKeyHold(VK_RIGHT))
		{
			rhold = false;
		}
		if(isKeyHold(VK_RIGHT) && rhold == false)
		{
			if(rholdcount < 4)
			{
				++rholdcount;
				rx = 55;
			}
			else
			{
				rhold = true;
				rholdcount = 0;
			}
		}

		if(!isKeyHold(VK_LEFT))
		{
			lhold = false;
		}
		if(isKeyHold(VK_LEFT) && lhold == false)
		{
			if(lholdcount < 4)
			{
				++lholdcount;
				lx = 30;
			}
			else
			{
				lhold = true;
				lholdcount = 0;
			}
		}
	}

	if(CurrentFrame >= 370 && CurrentFrame <= 619)
	{
		if(rx == 55 && (y == 38) && lx == 30)
		{
			y = 0;
			CurrentFrame+=12;
			++score;
		}
	}

	if(CurrentFrame >= 620 && CurrentFrame <= 694)
	{
		if(rx == 55 && (y == 38) && lx == 30)
		{
			y = 0;
			CurrentFrame+=6;
			++score;
		}
	}

	if(CurrentFrame >= 695 && CurrentFrame <= 727)
	{
		if(rx == 55 && (y >= 38 && y <= 40) && lx == 30)
		{
			y = 0;
			CurrentFrame+=3;
			++score;
		}
	}
	CurrentFrame ++;
}

void toiletroll::read()
{
	tr.open("ascii/toiletroll.txt");
	while(!tr.eof())
	{
		trs.push_back(tr.get());
	}
	tr.close();
	trs.pop_back();

	rh.open("ascii/righthand.txt");
	while(!rh.eof())
	{
		rhs.push_back(rh.get());
	}
	rh.close();
	rhs.pop_back();

	lh.open("ascii/lefthand.txt");
	while(!lh.eof())
	{
		lhs.push_back(lh.get());
	}
	lh.close();
	lhs.pop_back();
}

void toiletroll::draw()
{
	if(CurrentFrame >= 0 && CurrentFrame <= 60)
	{
		console.draw(45,20,"TOILET ROLL", 0x0F);
	}
	if(CurrentFrame >= 60 && CurrentFrame <= 229)
	{
		console.draw(45,20,"How to play", 0x0F);
		console.draw(38,22,"When the toiletroll falls\n  press the < and > keys\n     at the same time\n       to catch it", 0x0F);
	}

	if(CurrentFrame >= 230 && CurrentFrame <= 260)
	{	
		console.draw(47,20,"Ready?", 0x0F);
		console.draw(43,0, trs.c_str(), 0x0F);
		console.draw(60,40, rhs.c_str(), 0x0F);
		console.draw(25,40, lhs.c_str(), 0x0F);
	}

	if(CurrentFrame >= 260 && CurrentFrame <= 290)
	{	
		console.draw(50,20,"3", 0x0F);
		console.draw(43,0, trs.c_str(), 0x0F);
		console.draw(60,40, rhs.c_str(), 0x0F);
		console.draw(25,40, lhs.c_str(), 0x0F);
	}

	if(CurrentFrame >= 290 && CurrentFrame <= 320)
	{	
		console.draw(50,20,"2", 0x0F);
		console.draw(43,0, trs.c_str(), 0x0F);
		console.draw(60,40, rhs.c_str(), 0x0F);
		console.draw(25,40, lhs.c_str(), 0x0F);
	}

	if(CurrentFrame >= 320 && CurrentFrame <= 350)
	{	
		console.draw(50,20,"1", 0x0F);
		console.draw(43,0, trs.c_str(), 0x0F);
		console.draw(60,40, rhs.c_str(), 0x0F);
		console.draw(25,40, lhs.c_str(), 0x0F);
	}

	if(CurrentFrame >= 350 && CurrentFrame <= 370)
	{	
		console.draw(49,20,"GO!", 0x0F);
		console.draw(43,0, trs.c_str(), 0x0F);
		console.draw(60,40, rhs.c_str(), 0x0F);
		console.draw(25,40, lhs.c_str(), 0x0F);
	}

	if(CurrentFrame >= 370 && CurrentFrame <= 728)
	{
		char buffer[10];
		sprintf(buffer,"Score: %d",score);
		console.draw(46,20, buffer, 0x0F);
	}

	if(CurrentFrame >= 370 && CurrentFrame <= 619)
	{	
		console.draw(43,y, trs.c_str(), 0x0F);
		console.draw(rx,40, rhs.c_str(), 0x0F);
		console.draw(lx,40, lhs.c_str(), 0x0F);
		y+=1;
		if(y == 50)
		{
			y = 0;
		}
	}

	if(CurrentFrame >= 620 && CurrentFrame <= 694)
	{	
		console.draw(43,y, trs.c_str(), 0x0F);
		console.draw(rx,40, rhs.c_str(), 0x0F);
		console.draw(lx,40, lhs.c_str(), 0x0F);
		y+=2;
		if(y == 50)
		{
			y = 0;
		}
	}

	if(CurrentFrame >= 695 && CurrentFrame <= 727)
	{	
		console.draw(43,y, trs.c_str(), 0x0F);
		console.draw(rx,40, rhs.c_str(), 0x0F);
		console.draw(lx,40, lhs.c_str(), 0x0F);
		y+=3;
		if(y == 51)
		{
			y = 0;
		}
	}

	if(CurrentFrame >= 728)
	{
		if(score > 8)
		{
			rank = 'S';
		}
		if(score > 6 && score <= 8)
		{
			rank = 'A';
		}
		if(score > 5 && score <= 6)
		{
			rank = 'B';
		}
		if(score > 4 && score <= 5)
		{
			rank = 'C';
		}
		if(score > 3 && score <= 4)
		{
			rank = 'D';
		}
		if(score > 2 && score <= 3)
		{
			rank = 'E';
		}
		if(score <= 2)
		{
			rank = 'F';
		}
		char rankbuffer[10];
		sprintf(rankbuffer, "Rank: %c", rank);
		console.draw(47,19, rankbuffer, 0x0F);

		char buffer[256];
		sprintf(buffer,"You have scored: %d",score);
		console.draw(41,20, buffer, 0x0F);
		console.draw(37,22, "Press Enter to continune...", 0x0F);
	}
	rx = 60;
	lx = 25;
}

char toiletroll::returnscore()
{
	return rank;
}