#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm.hpp>
#include "Rendering/shader.h"

/**
 * Struct to store vertex data
 */
struct Vertex
{
	glm::vec3 position;
	glm::vec3 texCoords;
	glm::vec3 normals;
	glm::vec3 tangent;
};

/**
 * Struct to store texture data
 */
struct Texture
 {
	unsigned int textID;
	const char *type;
	//aiString path;
};

class Mesh
{
public:
	Mesh(std::string path);
	~Mesh();
	void draw(Shader shader);
	
private:

	//meshResource m_resource;
	unsigned int m_VAO;

	std::vector<Texture> m_textures;
	std::vector<Vertex> m_vertices;

	void init();
};

#endif