// This is the main file to hold everthing together

#include "Framework\timer.h"
#include "game.h"


StopWatch g_timer;							  // Timer function to keep track of time and the frame rate
bool quitgame = false;						 // Set to true if you want to quit the game
const unsigned char FPS = 30;				// FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame

Game game;

 // TODO:
// Bug in waitUnitil. it waits for the time from getElapsedTime to waitUntil, but should be insignificant.

int main()
{
    g_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
    while (!quitgame)      // run this loop until user wants to quit 
	{
        quitgame = game.Update(g_timer.getElapsedTime());							 // update the game
        game.Render();													// render the graphics output to screen
		g_timer.waitUntil(frameTime - g_timer.getElapsedTime());       // Frame rate limiter. Limits each frame to a specified time in ms.      
	}  
	
	return 0;
}
