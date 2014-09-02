#include "Animations.h"

Animations::Animations(Graphics& console)
	:
console(console)
{
}

Animations::~Animations()
{
}

int Animations::Add(const std::vector<std::string>* frames, const int frameDelay)
{
	const int currDelay = 0;
	const int currframe = 0;
	const bool hasbeenplayed = false;
	const bool isplaying = false;
	Animation newAnimation = {frames, frameDelay, currDelay, hasbeenplayed, isplaying, currframe};
	aniVector.push_back(newAnimation);

	const int index = aniVector.size() - 1;
	return index;
}

void Animations::playInstance(const int index, bool loop, bool reset)
{
	if(reset)
	{
		stop(index);
		aniVector[index].hasbeenplayed = false;
	}
	if(loop || !(aniVector[index].hasbeenplayed))
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
		else
		{
			aniVector[index].isplaying = true;
			if(aniVector[index].currframe == aniVector[index].frames->size())
			{
				stop(index);
			}
		}
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

void Animations::stop(const int index)
{
	aniVector[index].currframe = 0;
	aniVector[index].currDelay = 0;
	aniVector[index].isplaying = false;
	aniVector[index].hasbeenplayed = true;
}

void Animations::ChangeDelay(const int index, const int delay)
{
	aniVector[index].frameDelay = delay;
}