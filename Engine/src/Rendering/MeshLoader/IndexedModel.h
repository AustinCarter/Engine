#ifndef INDEXED_H
#define INDEXED_H

#include <vector>
#include <glm.hpp>

class IndexedModel
{
	public:
		IndexedModel();
		std::vector<glm::vec3> getPositions();
		std::vector<glm::vec2> getTexCoords();
		std::vector<glm::vec3> getNormals();
		std::vector<int> getIndicies();

	private:
		std::vector<glm::vec3> m_positions;
		std::vector<glm::vec2> m_texCoords;
		std::vector<glm::vec3> m_normals;
		std::vector<int> m_indicies;
};

#endif