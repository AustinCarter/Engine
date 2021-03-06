#include "Core/Display.h"


//number of MSAA samples | not currently doing anti-aliasing
//#define SAMPLES 4;


/**
 * Display constructor class
 * @param width initial width of the display
 * @param height initial height of the display
 * @param title name of the display window
 */
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
	glfwSetFramebufferSizeCallback(m_window, &framebuffer_size_callback);
	glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

/**
 * Processes keyboard inputs into the Display
 */
void Display::processInput()
{
	//NOTE: currently polls all 1024 keys on each update cycle, might want to think about ways to reduce the number of polls
	for(int i = 0; i < 1024; i++)
	{
		if(glfwGetKey(m_window, i) == GLFW_PRESS)
		{
			setKey(i, true);\
		}

		else if(m_keys[i] && glfwGetKey(m_window, i) == GLFW_RELEASE)
		{
			setKey(i, false);
		}
	}		
}

/**
 * returns the value of the first mouse member variable for the Display
 * @return boolean: true if it is the first mouse movement on the Display
 */
bool Display::firstMouse()
{
	return m_firstMouse;
}

/**
 *Sets the coordinates of the last mouse positon for a Display
 * @param xpos the x position of the mouse
 * @param ypos the y position of the mouse
 */
void Display::setMouse(double xpos, double ypos)
{
	m_lastX = xpos;
	m_lastY = ypos;
}
/**
 * Sets the value of the first mouse member variable of a Display
 * @param target the target value for the fir1t mouse variable
 */
void Display::setFirstMouse(bool target)
{
	m_firstMouse = target;
}
/**
 * calculates the distance the mouse has moved in the x and y directions from the last update of the mouse's position
 * @param xpos the x position of the mouse
 * @param ypos the y position of the mouse
 */	
void Display::calcMouseOff(double xpos, double ypos)
{
	m_xoffset = xpos - m_lastX;
	m_yoffset = m_lastY - ypos; // reversed since y-coordinates go from bottom to top
}


/**
 * makes sure that the viewport matches the window dimensions after the display size is changed
 * @param window the window that is being targeted for the viewport size change
 * @param width  new width
 * @param height new height
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


//TODO: get this working. Documentation:  http://www.glfw.org/docs/latest/window_guide.html
/**
 * makes the display fullscreen
 */
void Display::makeFullscreen()
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
/**
 * makes the display borderless fullscreen
 */
void Display::makeBorderlessFullscreen()
{
	
}

//------------------------------------------------
//getters and setters + wrapper functions

void Display::setKey(int code, bool state)
{
	m_keys[code] = state;
}

bool Display::getKey(int code)
{
	return m_keys[code];
}

double Display::getXOffset()
{
	return m_xoffset;
}

double Display::getYOffset()
{
	return m_yoffset;
}

double Display::getYScrollOffset()
{
	return m_scrollYoff;
}

Display::~Display()
{
	glfwTerminate();
}

bool Display::shouldClose()
{
	return m_shouldClose;
}

void Display::closeDisplay()
{
	m_shouldClose = true;
	glfwSetWindowShouldClose(m_window, true);
}

void Display::setYOff(double yoffset)
{
	m_scrollYoff = yoffset;	
}

void Display::setCallbacks(void (*mouse_callback)(GLFWwindow *, double, double), void (*scroll_callback)(GLFWwindow *, double, double))
{
	glfwSetScrollCallback(m_window, scroll_callback);
	glfwSetCursorPosCallback(m_window, mouse_callback);
}