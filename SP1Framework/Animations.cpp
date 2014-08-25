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
		if(hasEnded(index))
		{
			reset(index);
		}
	}
}

int Animations::Add(const std::vector<std::string>* frames,const int sizeX,const int sizeY, const int frameDelay)
{
	Animation newAnimation = {frames, sizeX, sizeY, frameDelay};
	aniVector.push_back(newAnimation);
	const int index = aniVector.size() - 1;
	return index;
}

void Animations::playInstance(const int index)
{
	if(!aniVector[index].isplaying)
	{
		aniVector[index].isplaying = true;
	}
	else
	{
		reset(index);
		aniVector[index].isplaying = true;
	};
}

bool Animations::InstanceIsPlaying(const int index)
{
	return aniVector[index].isplaying;
}

void Animations::drawInstance(const int x, const int y,const int color, const int index)
{
	std::string buffer = (*(aniVector[index].frames))[aniVector[index].currframe];
	console.draw(x, y, buffer.c_str(), color);
}

void Animations::advance(const int index)
{
	if(aniVector[index].isplaying)
	{
		if(aniVector[index].currframe < aniVector[index].frames->size())
		{
			if(aniVector[index].currDelay == aniVector[index].frameDelay)
			{
				aniVector[index].currframe++;
				aniVector[index].currDelay = 0;
			}
			else
			{
				aniVector[index].currDelay++;
			}
		}
		else
		{
			aniVector[index].isplaying = false;
		}
	}
}

bool Animations::hasEnded(const int index)
{
	if(aniVector[index].currframe == aniVector[index].frames->size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Animations::reset(const int index)
{
	aniVector[index].currframe = 0;
	aniVector[index].currDelay = 0;
	aniVector[index].isplaying = false;
}