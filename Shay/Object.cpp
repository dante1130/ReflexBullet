#include "Object.h"

Object3D::Object3D()
	: vertices(), texCoord(), faces(), textureFile("No name assigned!") {}

Object3D::~Object3D()
{
	vertices.clear();
	texCoord.clear();
	faces.clear();
}

void Object3D::AddVertex(const glm::vec3& vertex)
{
	vertices.push_back(vertex);
}

void Object3D::AddCoord(const glm::vec2& coord)
{
	texCoord.push_back(coord);
}

void Object3D::AddFaces(const FaceBase face_arr[4])
{
	std::array<FaceBase, 4> too;

	for (unsigned i = 0; i < 4; ++i) {
		too[i] = face_arr[i];
	}
	faces.push_back(too);
}

void Object3D::SetTextureName(const std::string& fileName)
{
	textureFile = fileName;
}

const glm::vec3& Object3D::GetVertex(unsigned i) const
{
	return vertices[i];
}

const glm::vec2& Object3D::GetCoord(unsigned i) const
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

const std::vector<glm::vec3>& Object3D::GetVertexVector() const
{
	return vertices;
}

const std::vector<glm::vec2>& Object3D::GetCoordVector() const
{
	return texCoord;
}

const std::vector<std::array<FaceBase, 4>>& Object3D::GetFaceVector() const
{
	return faces;
}


void Object3D::DisplayObject(int textureID)
{
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(textureID));
	for (unsigned i = 0; i < GetFaceVector().size(); ++i)
	{
		glBegin(GL_POLYGON);
		for (unsigned j = 0; j < 4; ++j)
		{
			unsigned temp_v = GetFace(i)[j].v - 1;
			unsigned temp_vt = GetFace(i)[j].vt - 1;
			glTexCoord2f(GetCoord(temp_vt).x, 1 - GetCoord(temp_vt).y);
			glVertex3f((GetVertex(temp_v).x * 300), (GetVertex(temp_v).y * 300), (GetVertex(temp_v).z * 300));
		}
		glEnd();
	}

	return;
}