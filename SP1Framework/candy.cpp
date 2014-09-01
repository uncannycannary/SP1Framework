#include "candy.h"

Candy::Candy(Graphics& console)
	:
console(console)
{
	CurrentFrame = 0;
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
}