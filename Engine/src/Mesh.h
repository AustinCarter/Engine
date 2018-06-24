#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm.hpp>


struct Vertex
{
	glm::vec3 position;
	glm::vec3 texCoords;
	glm::vec3 normals;
	glm::vec3 tangent;
}

class Mesh
{
public:
	Mesh(const char *path);
	~Mesh();

private:

	meshResource m_resource;
	unsigned int m_VAO;

	Vector<Texture> m_textures;
	Vector<Vertex> m_verticies;

	void loadFromObj(const char *path);
};

#endif