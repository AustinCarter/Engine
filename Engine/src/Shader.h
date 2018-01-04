#ifndef SHADER_H
#define SHADER_H

#include <iostream>

#include <glew.h>
#include <glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	//NOTE: will need to add new constructors for shaders using things like geometry shaders
	Shader(const char* vertex, const char* frag);
	~Shader();
	void use();
	void cleanUp();
private:
	unsigned int m_programID;
	/*unsigned int m_vertexID;
	unsigned int m_fragID;*/

	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif