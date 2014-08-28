#include "Rocket.h"

pumprocket::pumprocket(Graphics& console)
	:
console(console)
{
	CurrentFrame = 0;
	pushed = false;
	time = 11;
	score = 0;
	y = 40;
	read();
}

gamestate pumprocket::update()
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
		return ROCKET;
	}
}

void pumprocket::play()
{
	if(CurrentFrame >= 440 && CurrentFrame <= 740)
	{
		if(isKeyPressed(VK_LEFT) && pushed == false)
		{
			pushed = true;
			++score;
		}
		if(isKeyPressed(VK_RIGHT) && pushed == true)
		{
			pushed = false;
		}
	}
	++CurrentFrame;
}

void pumprocket::read()
{
	up.open("ascii/rocketup.txt");
	while(!up.eof())
	{
		ups.push_back(up.get());
	}
	up.close();
	ups.pop_back();

	down.open("ascii/rocketdown.txt");
	while(!down.eof())
	{
		downs.push_back(down.get());
	}
	down.close();
	downs.pop_back();

	spark.open("ascii/rocketsparks.txt");
	while(!spark.eof())
	{
		sparks.push_back(spark.get());
	}
	spark.close();
	sparks.pop_back();

	rocket.open("ascii/rocket.txt");
	while(!rocket.eof())
	{
		rockets.push_back(rocket.get());
	}
	rocket.close();
	rockets.pop_back();
}

void pumprocket::draw()
{
	if(CurrentFrame >= 0 && CurrentFrame <= 59)
	{
		console.draw(43,20,"PUMP THE ROCKET", 0x0F);
	}

	if(CurrentFrame >= 60 && CurrentFrame <= 300)
	{
		console.draw(45,20,"How to play", 0x0F);
		console.draw(28,22,"     You have 10 seconds before take off\n      press < to push the pump down and\n         press > to pull the pump up\nmash them faster to make the rocket go higher", 0x0F);
	}

	if(CurrentFrame >= 300 && CurrentFrame <= 330)
	{	
		console.draw(48,20,"Ready?", 0x0F);
		console.draw(30,24, ups.c_str(), 0x0F);
	}

	if(CurrentFrame >= 330 && CurrentFrame <= 360)
	{	
		console.draw(50,20,"3", 0x0F);
		console.draw(30,24, ups.c_str(), 0x0F);
	}

	if(CurrentFrame >= 360 && CurrentFrame <= 390)
	{	
		console.draw(50,20,"2", 0x0F);
		console.draw(30,24, ups.c_str(), 0x0F);
	}

	if(CurrentFrame >= 390 && CurrentFrame <= 420)
	{	
		console.draw(50,20,"1", 0x0F);
		console.draw(30,24, ups.c_str(), 0x0F);
	}

	if(CurrentFrame >= 420 && CurrentFrame <= 439)
	{	
		console.draw(49,20,"GO!", 0x0F);
		console.draw(30,24, ups.c_str(), 0x0F);
	}

	if(CurrentFrame >= 440 && CurrentFrame <= 740)
	{
		if(pushed == false)
		{
			console.draw(30,24, ups.c_str(), 0x0F);
		}
		if(pushed == true)
		{
			console.draw(30,24, downs.c_str(), 0x0F);
		}
		if(isKeyHold(VK_LEFT) && pushed == false)
		{
			console.draw(26,24, sparks.c_str(), 0x0F);
		}
		if(CurrentFrame%30 == 20)
		{
			--time;
		}
		char timebuffer[10];
		sprintf(timebuffer,"Time: %d",time);
		console.draw(47,17, timebuffer, 0x0F);

		char scorebuffer[10];
		sprintf(scorebuffer,"Score: %d",score);
		console.draw(47,53, scorebuffer, 0x0F);
	}
	if(CurrentFrame >= 740)
	{
		char buffer[24];
		sprintf(buffer,"Your rocket flew: %dm",score);
		console.draw(39,20, buffer, 0x0F);
		console.draw(37,22, "Press Enter to continune...", 0x0F);

		if(score!=0)
		{
			if(y!=0)
			{
				console.draw(43,y, rockets.c_str(), 0x0F);
				--y;
			}
		}
		else
			console.draw(43,y, rockets.c_str(), 0x0F);
	}
}