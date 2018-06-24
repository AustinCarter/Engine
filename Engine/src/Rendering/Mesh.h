#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm.hpp>
#include "Rendering/shader.h"

using namespace std;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 texCoords;
	glm::vec3 normals;
	glm::vec3 tangent;
};

struct Texture {
	unsigned int id;
	const char *type;
	//aiString path;
};

class Mesh
{
public:
	Mesh(const char *path);
	~Mesh();
	void draw(Shader shader);
private:

	//meshResource m_resource;
	unsigned int m_VAO;

	vector<Texture> m_textures;
	vector<Vertex> m_vertices;

	void loadFromObj(const char *path);

	void init();
};

#endif