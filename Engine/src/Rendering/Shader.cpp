#include "Rendering/Shader.h"

/**
 * Shader constructor
 * @param vertex The path to the vertex shader file
 * @param fragment The path to the vertex shader file
 */
Shader::Shader(std::string vertex, std::string frag)
{
	unsigned int vertexShader;
	unsigned int fragmentShader;

	// 1. retrieve the vertex/fragment source code from filePath
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try
	{
		// open files
		vShaderFile.open(vertex);
		fShaderFile.open(frag);

		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR: 	Failed to open shader files" << std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);
	checkCompileErrors(vertexShader, "VERTEX");


	fragmentShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);
	checkCompileErrors(fragmentShader, "VERTEX");

	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader);
	glLinkProgram(m_programID);
	checkCompileErrors(m_programID,"PROGRAM");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

/**
 * Sets the shader to be used by openGL for rendering
 */
void Shader::use()
{
	glUseProgram(m_programID);
}

/**
 * delete the shader program, free resources
 */
void Shader::cleanUp()
{
	glDeleteProgram(m_programID);
}

Shader::~Shader()
{
	glDeleteProgram(m_programID);
}

/**
 * Check the compilation of the shader program
 * @param shader Shader program to be checked
 * @param type   Type of shader that is being checked (E.g VERTEX)
 */
void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "PROGRAM COMPILATION ERROR:		" << infoLog << "\n ------------------------------------------------------- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHDAER COMPILATION ERROR:		" <<  type << "\n" << infoLog << "\n ------------------------------------------------------- " << std::endl;
		}
	}
}


// utility uniform functions
void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_programID, name.c_str()), (int)value);
} 

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(m_programID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(m_programID, name.c_str()), value);
}

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(m_programID, name.c_str()), 1, &value[0]);
}

void Shader::setVec2(const std::string &name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(m_programID, name.c_str()), x, y);
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(m_programID, name.c_str()), 1, &value[0]);
}

void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(m_programID, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(m_programID, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string &name, float x, float y, float z, float w)
{
	glUniform4f(glGetUniformLocation(m_programID, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_programID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}