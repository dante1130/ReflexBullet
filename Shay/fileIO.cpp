#include "fileIO.h"

void readObjFile(const std::string& fileName, Object3D& obj)
{
	std::vector<FaceBase> temp_face;
	std::string temp_line, prefix, name;
	glm::vec3 tempVertex, tempNormalVertex;
	glm::vec2 tempCoord;

	std::ifstream temp_file(fileName);
	if (!temp_file)
	{
		std::cout << fileName << " file not found" << std::endl;
		return;
	}

	while (getline(temp_file, temp_line))
	{
		std::stringstream ss(temp_line);

		getline(ss, prefix, ' ');
		if (prefix.compare("v") == 0) {
			ss >> tempVertex.x >> tempVertex.y >> tempVertex.z;
			obj.AddVertex(glm::vec3(tempVertex));
		}
		else if (prefix.compare("vt") == 0) {
			ss >> tempCoord.x >> tempCoord.y;
			obj.AddCoord(tempCoord);
		}
		else if (prefix.compare("usemtl") == 0) {
			getline(ss, name, ' ');
			obj.SetTextureName(name);
		}
		else if (prefix.compare("vn") == 0){
			ss >> tempNormalVertex.x >> tempNormalVertex.y >> tempNormalVertex.z;
			obj.AddVertexNormal(tempNormalVertex);

		}
		else if (prefix.compare("f") == 0) {
			for (unsigned i = 0; getline(ss, name, ' '); ++i)
			{
				temp_face.push_back(StringToFace(name));
			}
			obj.AddFaces(temp_face);
			temp_face.clear();
		}
		else if (prefix.compare("mtllib") == 0)
		{
			getline(ss, name);
			obj.SetMTLName(name);
		}
	}
	
	temp_file.close();
}

FaceBase StringToFace(const std::string& str)
{
	std::stringstream temp_line(str);
	std::string temp_A, temp_B, temp_C;
	FaceBase temp;

	getline(temp_line, temp_A, '/');
	getline(temp_line, temp_B, '/');
	getline(temp_line, temp_C, ' ');

	temp.v = std::stoul(temp_A);
	temp.vt = std::stoul(temp_B);
	temp.vn = std::stoul(temp_C);

	return temp;
}

void ReadOBJMTL(const std::string& fileName, Object3D& obj)
{
	readObjFile(fileName, obj);
	ReadMTLFile(obj);
}

void ReadMTLFile(Object3D& obj)
{
	int mat1 = 0;
	std::string temp_line, prefix;
	Material mat;

	std::string name = "data/object/" + obj.GetMTLName();

	std::ifstream temp_file(name);
	if (!temp_file)
	{
		std::cout << name << "File not found" << std::endl;
		return;
	}

	while (getline(temp_file, temp_line) && mat1 != 2)
	{
		std::stringstream ss(temp_line);

		getline(ss, prefix, ' ');

		if (prefix.compare("newmtl") == 0) {
			mat1++;
		}
		else if (prefix.compare("Ns") == 0) {
			ss >> mat.Ns;
		}
		else if (prefix.compare("Kd") == 0) {
			ss >> mat.Kd[0] >> mat.Kd[1] >> mat.Kd[2];
		}
		else if (prefix.compare("Ks") == 0) {
			ss >> mat.Ks[0] >> mat.Ks[1] >> mat.Ks[2];
		}
		else if (prefix.compare("Ka") == 0) {
			ss >> mat.Ka[0] >> mat.Ka[1] >> mat.Ka[2];
		}
		else if (prefix.compare("Ke") == 0) {
			ss >> mat.Ke[0] >> mat.Ke[1] >> mat.Ke[2];
		}
		else if (prefix.compare("Ni") == 0) {
			ss >> mat.Ni;
		}
		else if (prefix.compare("d") == 0) {
			ss >> mat.d;
		}
	}

	Materials.push_back(mat);
	obj.SetMTLArrayLocation(Materials.size() - 1);

	temp_file.close();
	
}