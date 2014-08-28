#include "Animations.h"

Animations::Animations(Graphics& console)
	:
console(console)
{
}

Animations::~Animations()
{
}

void Animations::update()
{
	for(int index = 0; index < aniVector.size(); index++)
	{
		advance(index);
	}
}

int Animations::Add(const std::vector<std::string>* frames,const int sizeX,const int sizeY, const int frameDelay)
{
	const int currDelay = 0;
	const int currframe = 0;
	const bool isplaying = false;
	Animation newAnimation = {frames, sizeX, sizeY, frameDelay, currDelay, isplaying, currframe};
	aniVector.push_back(newAnimation);

	const int index = aniVector.size() - 1;
	stop(index);
	return index;
}

void Animations::playInstance(const int index)
{
	aniVector[index].isplaying = true;
	if(aniVector[index].currframe == aniVector[index].frames->size())
	{
		stop(index);
	}
}

bool Animations::InstanceIsPlaying(const int index)
{
	return aniVector[index].isplaying;
}

void Animations::drawInstance(const int x, const int y,const int color, const int index)
{
	if(aniVector[index].isplaying)
	{
		std::string buffer = (*(aniVector[index].frames))[aniVector[index].currframe];
		console.draw(x, y, buffer.c_str(), color);
	}
}

void Animations::advance(const int index)
{
	if(aniVector[index].isplaying)
	{
		aniVector[index].currDelay++;
		if(aniVector[index].currDelay == aniVector[index].frameDelay)
		{
			aniVector[index].currframe++;
			aniVector[index].currDelay = 0;
		}
		if(aniVector[index].currframe == aniVector[index].frames->size())
		{
			stop(index);
		}
	}
}

void Animations::stop(const int index)
{
	aniVector[index].currframe = 0;
	aniVector[index].currDelay = 0;
	aniVector[index].isplaying = false;
}

void Animations::ChangeDelay(const int index, const int delay)
{
	aniVector[index].frameDelay = delay;
}