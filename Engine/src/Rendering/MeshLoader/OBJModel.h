#ifndef OBJMODEL_H
#define OBJMODEL_H

#include <vector>
#include<glm.hpp>

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
		vector<glm::vec3> getPositions();
		vector<glm::vec2> getTexCoords();
		vector<glm::vec3> getNormals();
		vector<OBJIndex> getIndicies();

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