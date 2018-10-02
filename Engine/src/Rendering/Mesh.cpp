#include "Mesh.h"

Mesh::Mesh(std::string path)
{
	loadMesh(path);
}

void Mesh::loadMesh(std::string filename)
{
	OBJModel objMod(filename);
	IndexedModel mod = objMod.toIndexedModel();

	std::vector<Vertex> verticies;

	for(unsigned int i = 0; i < mod.getPositions().size(); i++)
	{
		verticies.emplace_back(mod.getPositions()[i],
									mod.getTexCoords()[i],
									mod.getNormals()[i]);
	}

}

void Mesh::draw(Shader shader)
{

}