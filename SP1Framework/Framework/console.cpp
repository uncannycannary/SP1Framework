#include "console.h"
#include <cstdio>
#include <vector>

std::vector<char> keyboardbuffer;
/* Standard error macro for reporting API errors */ 
inline void PERR(bool bSuccess, char* api)
{
	if(!(bSuccess))
	{
		printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);
	}
}

bool keyAlreadyPressed[256];
bool keyispressed[256];
bool keyishold[256];

bool isKeyHold(unsigned short key)
{
	return keyishold[key];
}

bool getkey(unsigned short key)
{
	return ((GetAsyncKeyState(key) & 0x8001) != 0);
}

void updateinput()
{
	keyboardbuffer.clear();
	for(int index = 0; index < 256; index++)
	{
		if(keyAlreadyPressed[index] && !getkey(index))
		{
			keyAlreadyPressed[index] = false;
			keyispressed[index] = false;
			keyishold[index] = false;
		}
		else if(!keyAlreadyPressed[index] && getkey(index))
		{
			keyAlreadyPressed[index] = true;
			keyispressed[index] = true;
			keyishold[index] = true;
		}
		else if(keyAlreadyPressed[index] && getkey(index))
		{
			keyispressed[index] = false;
			keyishold[index] = true;
		}
		else
		{
			keyispressed[index] = false;
			keyishold[index] = false;
		}
	}
	for(int index = ' '; index < '~'; index++)
	{
		if(isKeyPressed(index))
		{
			keyboardbuffer.push_back((char)index);
		}
	}
}

bool isKeyPressed(unsigned short key)
{
	return keyispressed[key];
}

char getkeyboardbuffer()
{
	if(keyboardbuffer.empty())
	{
		return 0;
	}
	else
	{
		char letter = keyboardbuffer.back();
		keyboardbuffer.pop_back();
		return letter;
	}
}

bool isKeyReleased(unsigned short key)
{
	return !(isKeyHold(key));
}