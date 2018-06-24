#ifndef INDEXED_H
#define INDEXED_H

#include <vector>
#include<glm.hpp>

class IndexedModel
{
	public:
		IndexedModel();
		vector<glm::vec3> getPositions();
		vector<glm::vec2> getTexCoords();
		vector<glm::vec3> getNormals();
		vector<int> getIndicies();

	private:
		std::vector<glm::vec3> m_positions;
		std::vector<glm::vec2> m_texCoords;
		std::vector<glm::vec3> m_normals;
		std::vector<int> m_indicies;
};

#endif