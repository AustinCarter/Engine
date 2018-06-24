#ifndef SHADER_H
#define SHADER_H

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
	Shader(std::string vertex, std::string frag);
	~Shader();
	void use();
	void cleanUp();


	//Uniform helper functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec2(const std::string &name, float x, float y) const;
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec3(const std::string &name, float x, float y, float z) const;
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setVec4(const std::string &name, float x, float y, float z, float w);
	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

private:
	unsigned int m_programID;
	/*unsigned int m_vertexID;
	unsigned int m_fragID;*/

	void checkCompileErrors(unsigned int shader, std::string type);
};

#endif