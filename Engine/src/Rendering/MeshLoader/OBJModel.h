#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <vector>
#include <glm.hpp>

#include "IndexedModel.h"

struct OBJIndex
{
	int vertexIndex;
	int texCoordIndex;
	int normalIndex;

};

class OBJModel
{
	public:
		OBJModel(std::string filename);
		std::vector<glm::vec3> getPositions();
		std::vector<glm::vec2> getTexCoords();
		std::vector<glm::vec3> getNormals();
		std::vector<OBJIndex> getIndicies();
		IndexedModel toIndexedModel();

	private:
		std::vector<glm::vec3> m_positions;
		std::vector<glm::vec2> m_texCoords;
		std::vector<glm::vec3> m_normals;
		std::vector<OBJIndex> m_indicies;

		bool m_hasNorm;
		bool m_hasText;

		OBJIndex parseIndex(std::string index);
};

#endif