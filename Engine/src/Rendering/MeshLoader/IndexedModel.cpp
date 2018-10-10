#include "IndexedModel.h"

IndexedModel::IndexedModel()
{}

//Getters and setters
std::vector<glm::vec3> IndexedModel::getPositions(){return m_positions;}
std::vector<glm::vec2> IndexedModel::getTexCoords(){return m_texCoords;}
std::vector<glm::vec3> IndexedModel::getNormals(){return m_normals;}
std::vector<int> IndexedModel::getIndicies(){return m_indicies;}

void IndexedModel::addPosition(glm::vec3 position){m_positions.push_back(position);}
void IndexedModel::addTexCoord(glm::vec2 coord){m_texCoords.push_back(coord);}
void IndexedModel::addNormal(glm::vec3 normal){m_normals.push_back(normal);}
void IndexedModel::addIndex(int i){m_indicies.push_back(i);}
