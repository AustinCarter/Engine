#include "IndexedModel.h"

IndexedModel::IndexedModel()
{

}

//Getters and setters
vector<glm::vec3> IndexedModel::getPositions(){return m_positions;}
vector<glm::vec2> IndexedModel::getTexCoords(){return m_texCoords;}
vector<glm::vec3> IndexedModel::getNormals(){return m_normals;}
vector<int> IndexedModel::getIndicies(){return m_indicies;}
