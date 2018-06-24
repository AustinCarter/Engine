#include "OBJModel.h"

/**
 * [description of method]
 * @param filename [description]
 */
IndexedModel::IndexedModel(std::String filename)
{
	
}

//Getters and setters
vector<glm::vec3> getPositions(){return m_positions;}
vector<glm::vec2> getTexCoords(){return m_texCoords;}
vector<glm::vec3> getNormals(){return m_normals;}
vector<OBJIndex> getIndicies(){return m_indicies;}
