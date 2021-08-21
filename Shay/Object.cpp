#include "Object.h"


Object3D::Object3D()
{
	textureFile = "No name assigned!";
}

Object3D::~Object3D()
{
	vertices.clear();
	texCoord.clear();
	faces.clear();
}

void Object3D::AddVertex(float x, float y, float z)
{
	vertex temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;

	vertices.push_back(temp);
}
void Object3D::AddCoord(float x, float y)
{
	coord temp;
	temp.x = x;
	temp.y = y;

	texCoord.push_back(temp);
}
//void AddNormal(float x, float y, float z);
void Object3D::AddFaces(const FaceBase face_arr[4])
{
	std::array<FaceBase, 4> too;

	for (unsigned i = 0; i < 4; ++i) {
		too[i] = face_arr[i];
	}
	faces.push_back(too);
}
void Object3D::SetTextureName(std::string fileName)
{
	textureFile = fileName;
}

const vertex& Object3D::GetVertex(const unsigned i)
{
	return vertices[i];
}
const coord& Object3D::GetCoord(const unsigned i)
{
	return texCoord[i];
}
const std::array<FaceBase, 4>& Object3D::GetFace(const unsigned i)
{
	return faces[i];
}

const std::string &Object3D::GetName()
{
	return textureFile;
}

const std::vector<vertex>& Object3D::GetVertexVector()
{
	return vertices;
}

const std::vector<coord>& Object3D::GetCoordVector()
{
	return texCoord;
}
const std::vector<std::array<FaceBase, 4>>& Object3D::GetFaceVector()
{
	return faces;
}