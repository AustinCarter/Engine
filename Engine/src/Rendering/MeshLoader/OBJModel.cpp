#include "OBJModel.h"
#include "utility/StringUtil.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
/**
 * [description of method]
 * @param filename [description]
 */
OBJModel::OBJModel(std::String filename)
{
	//check that the file being loaded in is an obj file
	std::vector<std::string> splitFile = split(filename, '.');
	if(splitFile.back().compare(".obj"))
	{
		printf("ERROR:	at %s line %d; expected obj recieved %s",__FILE__, __LINE__, splitFile.back());

	}
	else
	{			
		m_hasNorm = false;
		m_hasText = false;
		std::ifstream objStream(filename); 
		std::string line;
		std::vector<std::string> tokens;
		while(std::getline(objStream, line))
		{
			std::cout << line << std::endl;
			tokens = split(line, ' ')
			if(!tokens.front().compare("v"))
			{
				m_positions.push_back(glm::vec3(atof(tokens[1]),atof(tokens[2]),atof(tokens[3])));
			}
			else if(!tokens.front().compare("vt"))
			{
				m_texCoords.push_back(glm::vec2(atof(tokens[1]),atof(tokens[2])));

			}
			else if(!tokens.front().compare("vn"))
			{
				m_normals.push_back(glm::vec3(atof(tokens[1]),atof(tokens[2]),atof(tokens[3])));
			}
			else if(!tokens.front().compare("f"))
			{
				for(int i = 0; i < tokens.size() - 3; i++)
				{
					m_indicies.push_back(parseIndex(tokens[1]));
					m_indicies.push_back(parseIndex(tokens[2 + i]));
					m_indicies.push_back(parseIndex(tokens[3 + i]));
				}
			}

		}

		objStream.close();
	}

}

OBJIndex OBJModel::parseIndex(std::string index)
{
	std::vector<std::string> tokens = split(index, "/");

	OBJIndex result;
	result.vertexIndex = atoi(tokens[0]);

	if(tokens.size() > 1)
	{
		m_hasText = true;
		result.texCoordIndex = atoi(tokens[1]);
		if(tokens.size() > 2)
		{
			m_hasNorm = true;
			result.normalIndex = atoi(tokens[2]);
		}
	}

	return result;
}

//Getters and setters
vector<glm::vec3> OBJModel::getPositions(){return m_positions;}
vector<glm::vec2> OBJModel::getTexCoords(){return m_texCoords;}
vector<glm::vec3> OBJModel::getNormals(){return m_normals;}
vector<OBJIndex> OBJModel::getIndicies(){return m_indicies;}
