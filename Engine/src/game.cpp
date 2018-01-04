#include "Display.h"

/**
 * This is an example of an end user program that is used to test the 
 * usability of the engine for an actual user of the engine
 */


int main(int argc, char** argv)
{
	Display display(800, 600, "Client App");
	while(!display.shouldClose())
	{
		display.update();
		if(display.getKey(GLFW_KEY_ESCAPE))
			display.closeDisplay();
	}

	return 0;
}