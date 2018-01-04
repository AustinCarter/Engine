#ifndef DISPLAY_H
#define DISPLAY_H

#include <glew.h>
#include <glfw3.h>

class Display
{
public:
	Display(int width, int height, const char* title);
	~Display();
	void update();

	void  setKey(int code, bool state);
	bool  getKey(int code);
	float getXOffset();
	float getYOffset();
	float getYScrollOffset();

	void closeDisplay();
	//void makeFullscreen();
	//void makeBorderlessFullscreen();
	bool shouldClose();

private:
	//window properties
	int m_width;
	int m_height;
	const char *m_title;
	GLFWwindow* m_window;
	GLFWmonitor* m_monitor;


	//input data
	bool   m_keys[1024];
	bool   m_firstMouse;
	float  m_xoffset;
	float  m_yoffset;
	float  m_lastX;
	float  m_lastY;
	float  m_scrollYoff;

	bool m_shouldClose;
	
	void processInput(); //NOTE: might want to abstract out the input handling eventually
};

//callback function prototypes
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif