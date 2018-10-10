#include "OBJModel.h"
#include "utility/StringUtil.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

/**
 * Construct a model based off of data from an OBJ file at path filename
 * @param filename path of the obj file to be read from
 */
OBJModel::OBJModel(std::string filename)
{
	//check that the file being loaded in is an obj file
	std::vector<std::string> splitFile = split(filename, '.');
	if(splitFile.back().compare(".obj"))
	{
		printf("ERROR:	at %s line %d; expected .obj recieved %s",__FILE__, __LINE__, splitFile.back());

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
			tokens = split(line, ' ');
			if(!tokens.front().compare("v"))
			{
				m_positions.push_back(glm::vec3(stof(tokens[1]),stof(tokens[2]),stof(tokens[3])));
			}
			else if(!tokens.front().compare("vt"))
			{
				m_texCoords.push_back(glm::vec2(stof(tokens[1]),stof(tokens[2])));

			}
			else if(!tokens.front().compare("vn"))
			{
				m_normals.push_back(glm::vec3(stof(tokens[1]),stof(tokens[2]),stof(tokens[3])));
			}
			else if(!tokens.front().compare("f"))
			{
				//triangulation of faces
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

/**
 * Converts from raw OBJ model data into the internal indexed model
 * @return an indexed model representation of the data stored in the OBJ model
 */
IndexedModel* OBJModel::toIndexedModel()
{
	IndexedModel *result = new IndexedModel();

	for(int i = 0; i < m_indicies.size(); i++)
	{
		OBJIndex currentIndex = m_indicies[i];
		glm::vec3 currentPosition = m_positions[currentIndex.vertexIndex];
		glm::vec2 currentTexCoord;
		glm::vec3 currentNormal;

		if(m_hasText)
			 currentTexCoord = m_texCoords[currentIndex.texCoordIndex];
		else
			currentTexCoord = glm::vec2(0,0);
		if(m_hasNorm)
			 currentNormal = m_normals[currentIndex.normalIndex];
		else
			currentTexCoord = glm::vec3(0,0,0);		

		result -> addPosition(currentPosition);
		result -> addNormal(currentNormal);
		result -> addTexCoord(currentTexCoord);
		result -> addIndex(i);
	}

	return result;
}

OBJIndex OBJModel::parseIndex(std::string index)
{
	std::vector<std::string> tokens = split(index, '/');

	OBJIndex result;
	result.vertexIndex = stoi(tokens[0]);

	if(tokens.size() > 1)
	{
		m_hasText = true;
		result.texCoordIndex = stoi(tokens[1]);
		if(tokens.size() > 2)
		{
			m_hasNorm = true;
			result.normalIndex = stoi(tokens[2]);
		}
	}

	return result;
}

//------ Getters and setters ------
std::vector<glm::vec3> OBJModel::getPositions(){return m_positions;}
std::vector<glm::vec2> OBJModel::getTexCoords(){return m_texCoords;}
std::vector<glm::vec3> OBJModel::getNormals(){return m_normals;}
std::vector<OBJIndex> OBJModel::getIndicies(){return m_indicies;}