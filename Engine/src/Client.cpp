#include "Display.h"

/**
 * This is an example of a client program that is used to test the 
 * usability of the engine for an actual user of the engine
 */

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Display display(800, 600, "Example Client App");

int main(int argc, char** argv)
{
	display.setCallbacks(&mouse_callback, &scroll_callback);
	while(!display.shouldClose())
	{
		display.update();
		if(display.getKey(GLFW_KEY_ESCAPE))
		{
			display.closeDisplay();		
		}
	}

	return 0;
}

//NOTE: can change this later so that display won't need to be declared globaly 
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if(display.firstMouse())
	{
		display.setMouse(xpos, ypos);
		display.setFirstMouse(false);
	}

	display.calcMouseOff(xpos, ypos);
	display.setMouse(xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	display.setYOff(yoffset);	
}