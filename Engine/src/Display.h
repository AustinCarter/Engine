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
	double getXOffset();
	double getYOffset();
	double getYScrollOffset();

	bool firstMouse();
	void setMouse(double xpos, double ypos);
	void setFirstMouse(bool target);
	void calcMouseOff(double xpos, double ypos);
	void setYOff(double yoffset);

	void setCallbacks(void (*mouse_callback)(GLFWwindow *, double, double), void (*scroll_callback)(GLFWwindow *, double, double));
	void closeDisplay();
	//NOTE: attempt to implement made it change the resolution of the OS and then the window became unresponsive
	//void makeFullscreen();
	//void makeBorderlessFullscreen();
	bool shouldClose();

	/*void processMouseScrolled(double xpos, double ypos);
	void processMouseMoved(double xoff, double yoff);*/

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
	double  m_xoffset;
	double  m_yoffset;
	double  m_lastX;
	double  m_lastY;
	double  m_scrollYoff;

	bool m_shouldClose;
	
	void processInput(); //NOTE: might want to abstract out the input handling eventually		

	
};

//callback function prototypes
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


#endif