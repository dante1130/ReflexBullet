#include "Object.h"

Object3D::Object3D()
	: vertices(), texCoord(), faces(), textureFile("No name assigned!") {}

Object3D::~Object3D()
{
	vertices.clear();
	texCoord.clear();
	for (int i = 0; i < GetFaceVectorSize(); ++i)
	{
		faces[i].clear();
	}
	faces.clear();
}

void Object3D::AddVertexNormal(const glm::vec3& vn)
{
	vertexNormals.push_back(vn);
}

void Object3D::SetMTLName(const std::string& mtlName)
{
	mtlFile = mtlName;
}

void Object3D::SetMTLArrayLocation(int location)
{
	mtlLoc = location;
}

int Object3D::GetMTLArrayLocation()
{
	return mtlLoc;
}

const std::string& Object3D::GetMTLName()
{
	return mtlFile;
}

void Object3D::AddVertex(const glm::vec3& vertex)
{
	vertices.push_back(vertex);
}

void Object3D::AddCoord(const glm::vec2& coord)
{
	texCoord.push_back(coord);
}

void Object3D::AddFaces(const std::vector<FaceBase>& face_temp)
{
	faces.push_back(face_temp);
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

const glm::vec3& Object3D:: GetVertexNormal(unsigned i) const
{
	return vertexNormals[i];
}


const std::vector<FaceBase>& Object3D::GetFace(unsigned i) const
{
	return faces[i];
}

const std::string& Object3D::GetName() const
{
	return textureFile;
}

const unsigned Object3D::GetFaceVectorSize() const
{
	return faces.size();
}


void Object3D::DisplayObject(int textureID)
{
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(textureID));
	for (unsigned i = 0; i < GetFaceVectorSize(); ++i)
	{
		glBegin(GL_POLYGON);
		for (unsigned j = 0; j < GetFace(i).size(); ++j)
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

void Object3D::DisplayObjectWithLighting(int textureID)
{
	unsigned temp_v, temp_vt, temp_nv, faceVectorSize, j;

	SetMaterialProperties(mtlLoc);
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(textureID));
	faceVectorSize = GetFaceVectorSize();
	for (unsigned i = 0; i < faceVectorSize; ++i)
	{
		glBegin(GL_POLYGON);
		for (j = 0; j < GetFace(i).size(); ++j)
		{
			temp_v = GetFace(i)[j].v - 1;
			temp_vt = GetFace(i)[j].vt - 1;
			temp_nv = GetFace(i)[j].vn - 1;
			glTexCoord2f(GetCoord(temp_vt).x, 1 - GetCoord(temp_vt).y);
			glNormal3f(vertexNormals[temp_nv].x, vertexNormals[temp_nv].y, vertexNormals[temp_nv].z);
			glVertex3f(vertices[temp_v].x, vertices[temp_v].y, vertices[temp_v].z);
		}
		glEnd();
	}


	return;
}


void Object3D::SetMaterialProperties(int index)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Materials[index].Ka);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Materials[index].Kd);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Materials[index].Ks);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Materials[index].Ke);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Materials[index].Ns);
}