#include "IndexedModel.h"

IndexedModel::IndexedModel()
{

}

//Getters and setters
vector<glm::vec3> getPositions(){return m_positions;}
vector<glm::vec2> getTexCoords(){return m_texCoords;}
vector<glm::vec3> getNormals(){return m_normals;}
vector<int> getIndicies(){return m_indicies;}
