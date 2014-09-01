#include "candy.h"

Candy::Candy(Graphics& console)
	:
console(console)
{
	CurrentFrame = 0;
	candy = 0;
	time = -1;
	score = 20;
	triger = false;
	twosec = 1040;
	read();
}

gamestate Candy::update()
{
	if(isKeyPressed(VK_ESCAPE))
	{
		return MAIN_MENU;
	}
	draw();
	play();

	return CANDY;
}

void Candy::play()
{
	if(CurrentFrame >= 440 && CurrentFrame <= twosec)
	{
		if(isKeyPressed(VK_LEFT) || isKeyPressed(VK_DOWN) || isKeyPressed(VK_RIGHT))
		{
			++candy;
		}
	}
	if(candy == 100 && triger == false)
	{
		score = time;
		triger = true;
		twosec = (CurrentFrame + 60);
	}
	if(candy > 100 && CurrentFrame == twosec)
	{
		score+=(candy - 100);
	}
	++CurrentFrame;
}

void Candy::read()
{
	reader.open("candy/jar0.txt");
	while(!reader.eof())
	{
		j0.push_back(reader.get());
	}
	reader.close();
	j0.pop_back();

	reader.open("candy/jar1.txt");
	while(!reader.eof())
	{
		j1.push_back(reader.get());
	}
	reader.close();
	j1.pop_back();

	reader.open("candy/jar2.txt");
	while(!reader.eof())
	{
		j2.push_back(reader.get());
	}
	reader.close();
	j2.pop_back();

	reader.open("candy/jar3.txt");
	while(!reader.eof())
	{
		j3.push_back(reader.get());
	}
	reader.close();
	j3.pop_back();

	reader.open("candy/jar4.txt");
	while(!reader.eof())
	{
		j4.push_back(reader.get());
	}
	reader.close();
	j4.pop_back();

	reader.open("candy/jar5.txt");
	while(!reader.eof())
	{
		j5.push_back(reader.get());
	}
	reader.close();
	j5.pop_back();

	reader.open("candy/jar6.txt");
	while(!reader.eof())
	{
		j6.push_back(reader.get());
	}
	reader.close();
	j6.pop_back();

	reader.open("candy/jar7.txt");
	while(!reader.eof())
	{
		j7.push_back(reader.get());
	}
	reader.close();
	j7.pop_back();
}

void Candy::draw()
{
	if(CurrentFrame >= 0 && CurrentFrame <= 60)
	{
		console.draw(44,20,"Candy the jar", 0x0F);
	}
	if(CurrentFrame >= 60 && CurrentFrame <= 299)
	{
		console.draw(45,20,"How to play", 0x0F);
		console.draw(30,22,"press <, V and > to add candy to the jar\n    the jar can only store 100 candy\n so add them asap and don't overflow it", 0x0F);
	}

	if(CurrentFrame >= 300 && CurrentFrame <= 330)
	{	
		console.draw(47,20,"Ready?", 0x0F);
		console.draw(38,25, j0.c_str(), 0x0F);
	}

	if(CurrentFrame >= 330 && CurrentFrame <= 360)
	{	
		console.draw(50,20,"3", 0x0F);
		console.draw(38,25, j0.c_str(), 0x0F);
	}

	if(CurrentFrame >= 360 && CurrentFrame <= 390)
	{	
		console.draw(50,20,"2", 0x0F);
		console.draw(38,25, j0.c_str(), 0x0F);
	}

	if(CurrentFrame >= 390 && CurrentFrame <= 420)
	{	
		console.draw(50,20,"1", 0x0F);
		console.draw(38,25, j0.c_str(), 0x0F);
	}

	if(CurrentFrame >= 420 && CurrentFrame <= 440)
	{	
		console.draw(49,20,"GO!", 0x0F);
		console.draw(38,25, j0.c_str(), 0x0F);
	}

	if(CurrentFrame >= 440 && CurrentFrame <= twosec)
	{	
		if(CurrentFrame%30 == 20)
		{
			++time;
		}

		char timebuffer[10];
		sprintf(timebuffer,"Time: %d",time);
		console.draw(47,17, timebuffer, 0x0F);

		char candybuffer[12];
		sprintf(candybuffer,"Candy: %d",candy);
		console.draw(46,45, candybuffer, 0x0F);

		if(candy <= 19)
		{
			console.draw(38,25, j0.c_str(), 0x0F);
		}
		if(candy >= 20 && candy <= 39)
		{
			console.draw(38,25, j1.c_str(), 0x0F);
		}
		if(candy >= 40 && candy <= 59)
		{
			console.draw(38,25, j2.c_str(), 0x0F);
		}
		if(candy >= 60 && candy <= 79)
		{
			console.draw(38,25, j3.c_str(), 0x0F);
		}
		if(candy >= 80 && candy <= 99)
		{
			console.draw(38,25, j4.c_str(), 0x0F);
		}
		if(candy == 100)
		{
			console.draw(38,25, j5.c_str(), 0x0F);
		}
		if(candy > 100)
		{
			console.draw(38,24, j6.c_str(), 0x0F);
		}
	}
	if(CurrentFrame > twosec)
	{
		if(candy <= 19)
		{
			console.draw(38,25, j0.c_str(), 0x0F);
		}
		if(candy >= 20 && candy <= 39)
		{
			console.draw(38,25, j1.c_str(), 0x0F);
		}
		if(candy >= 40 && candy <= 59)
		{
			console.draw(38,25, j2.c_str(), 0x0F);
		}
		if(candy >= 60 && candy <= 79)
		{
			console.draw(38,25, j3.c_str(), 0x0F);
		}
		if(candy >= 80 && candy <= 99)
		{
			console.draw(38,25, j4.c_str(), 0x0F);
		}
		if(candy >= 100)
		{
			console.draw(38,25, j7.c_str(), 0x0F);
		}

		char scorebuffer[26];
		sprintf(scorebuffer,"You took %ds to fill this",score);
		console.draw(38,23, scorebuffer, 0x0F);
		console.draw(37,45, "Press Enter to continune...", 0x0F);
	}
}