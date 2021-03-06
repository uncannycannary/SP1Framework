#ifndef _ANIMATIONS_H
#define _ANIMATIONS_H

#include <vector>
#include <string>
#include "Graphics.h"

class Animations
{
public:
	Animations(Graphics& console);
	~Animations();
	int Add(const std::vector<std::string>* frames, const int frameDelay);
	void playInstance(const int index, bool loop = true, bool reset = false);
	bool InstanceIsPlaying(const int index);
	void drawInstance(const int x, const int y, const int color, const int index);
	void stop(const int index);
	void ChangeDelay(const int index, const int delay);
private:
	struct Animation
	{
		const std::vector<std::string>* frames;
		int frameDelay;
		int currDelay;
		bool hasbeenplayed;
		bool isplaying;
		int currframe;
	};
	std::vector<Animation> aniVector;
	Graphics& console;
};

#endif