#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>

#include <glm.hpp>

#include "MeshLoader/OBJModel.h"
#include "MeshLoader/IndexedModel.h"

#include "Rendering/shader.h"

/**
 * Struct to store vertex data
 */
struct Vertex
{
	glm::vec3 position;
	glm::vec2 texCoords;
	glm::vec3 normals;
	glm::vec3 tangent;
	Vertex(glm::vec3 positions, glm::vec2 texCoord, glm::vec3 normal):
	position(positions),
	texCoords(texCoord),
	normals(normal)
	{}
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

	void loadMesh(std::string filename);
};

#endif