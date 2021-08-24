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
	Vertex temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;

	vertices.push_back(temp);
}
void Object3D::AddCoord(float x, float y)
{
	Coord temp;
	temp.x = x;
	temp.y = y;

	texCoord.push_back(temp);
}

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

const Vertex& Object3D::GetVertex(unsigned i) const
{
	return vertices[i];
}

const Coord& Object3D::GetCoord(unsigned i) const
{
	return texCoord[i];
}

const std::array<FaceBase, 4>& Object3D::GetFace(unsigned i) const
{
	return faces[i];
}

const std::string& Object3D::GetName() const
{
	return textureFile;
}

const std::vector<Vertex>& Object3D::GetVertexVector() const
{
	return vertices;
}

const std::vector<Coord>& Object3D::GetCoordVector() const
{
	return texCoord;
}

const std::vector<std::array<FaceBase, 4>>& Object3D::GetFaceVector() const
{
	return faces;
}