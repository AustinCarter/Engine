#include <iostream>

#include "Display.h"

//#define SAMPLES 4;


Display::Display(int width, int height, const char* title):
	m_width(width),
	m_height(height),
	m_title(title),
	m_firstMouse(true),
	m_shouldClose(false),
	m_monitor(NULL)
{
	if(!glfwInit()) 
	{
		std::cout << "ERROR:	Failed to initialize GLFW" << std::endl;
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//NOTE: Anti-Aliasing not enabaled currently
	//glfwWindowHint(GLFW_SAMPLES, SAMPLES); //number of samples for MSAA

	// Create a windowed mode window and its OpenGL context 
	m_window = glfwCreateWindow(m_width, m_height, m_title , m_monitor, NULL);

	if (!m_window)
	{
		std::cout << "ERROR:	Failed to create window" << std::endl;
		glfwTerminate();
		return;
	}

	//Set the window to the current context and add set appropriate callbacks
	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
	glfwSetCursorPosCallback(m_window, mouse_callback);
//	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetScrollCallback(m_window, scroll_callback);

	if(glewInit() != GLEW_OK)
		std::cout << "ERROR: 	Failed to initialize GLEW" << std::endl;

	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_MULTISAMPLE);
	
}

void Display::update()
{
	processInput();
	//NOTE: the member variable is probably redundant, look into removing it
	if(glfwWindowShouldClose(m_window))
	{
		m_shouldClose = true;
		glfwTerminate();
	}

	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void Display::processInput()
{
	for(int i = 0; i < 1024; i++)
	{
		if(glfwGetKey(m_window, i) == GLFW_PRESS)
			setKey(i, true);

		else if(glfwGetKey(m_window, i) == GLFW_PRESS)
			setKey(i, false);
	}
	
		
}


//TODO: make this work
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	/*if(m_firstMouse)
	{
		m_lastX = xpos;
		m_lastY = ypos;
		m_firstMouse = false;
	}

	m_xoffset = xpos - m_lastX;
	m_yoffset = m_lastY - ypos; // reversed since y-coordinates go from bottom to top

	m_lastX = xpos;
	m_lastY = ypos;*/
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	glViewport(0, 0, width, height);
}

//TODO: make this work
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	//m_scrollYoff = yoffset;	
	
}

//TODO: get this working. Documentation:  http://www.glfw.org/docs/latest/window_guide.html
/*void Display::makeFullscreen()
{
	if(!m_monitor)
	{
		m_monitor = glfwGetPrimaryMonitor();
	}
	else
	{
		m_monitor = NULL;
	}
	
	glfwSetWindowMonitor(m_window, m_monitor, 0, 0, 1920, 1080, GLFW_DONT_CARE);
}

void Display::makeBorderlessFullscreen()
{
	
}
*/

void Display::setKey(int code, bool state)
{
	m_keys[code] = state;
}

bool Display::getKey(int code)
{
	return m_keys[code];
}

float Display::getXOffset()
{
	return m_xoffset;
}

float Display::getYOffset()
{
	return m_yoffset;
}

float Display::getYScrollOffset()
{
	return m_scrollYoff;
}

Display::~Display()
{
	glfwTerminate();
}

bool Display::shouldClose()
{
	return m_shouldClose; //should we just make this a call to the GL function?
}

void Display::closeDisplay()
{
	m_shouldClose = true;
	glfwSetWindowShouldClose(m_window, true);
}