#include "fileIO.h"

void readObjFile(const std::string& fileName, Object3D& obj)
{
	FaceBase temp_face[4];
	std::string temp_line, prefix, name;
	glm::vec3 tempVertex;
	glm::vec2 tempCoord;

	std::ifstream temp_file(fileName);
	if (!temp_file) return;

	while (getline(temp_file, temp_line))
	{
		std::stringstream ss(temp_line);

		getline(ss, prefix, ' ');
		if (prefix.compare("v") == 0) {
			ss >> tempVertex.x >> tempVertex.y >> tempVertex.z;
			obj.AddVertex(glm::vec3(tempVertex));
		}
		if (prefix.compare("vt") == 0) {
			ss >> tempCoord.x >> tempCoord.y;
			obj.AddCoord(tempCoord);
		}
		if (prefix.compare("usemtl") == 0) {
			getline(ss, name, ' ');
			obj.SetTextureName(name);
		}
		if (prefix.compare("f") == 0) {
			for (unsigned i = 0; i < 4; ++i)
			{
				getline(ss, name, ' ');
				temp_face[i] = StringToFace(name);
			}
			obj.AddFaces(temp_face);
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

	return temp;
}
