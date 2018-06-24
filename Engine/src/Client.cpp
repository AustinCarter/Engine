#include "Core/Display.h"
#include "Rendering/Shader.h"
/**
 * This is an example of a client program that is used to test the 
 * usability of the engine for an actual user of the engine
 */

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Display display(800, 600, "Client App");

int main(int argc, char** argv)
{
	//NOTE: will want to rewrite shaders once more of the engine is developed
	//NOTE: probably want to have game objects have a default shader that the user can manually change if they want to
	Shader shader("./Rendering/Shader/shader.vert","./Rendering/Shader/shader.frag");
	
	display.setCallbacks(&mouse_callback, &scroll_callback);
	while(!display.shouldClose())
	{
		display.update();
		if(display.getKey(GLFW_KEY_ESCAPE))
		{
			display.closeDisplay();
		}
	}
	shader.cleanUp();

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