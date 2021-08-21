#include "fileIO.h"

void readObjFile(std::string fileName, Object3D& obj)
{
	FaceBase temp_face[4];
	std::string temp_line, prefix, name;
	float temp_x, temp_y, temp_z;

	std::ifstream temp_file(fileName);
	if (!temp_file) return;

	while (getline(temp_file, temp_line))
	{
		std::stringstream ss(temp_line);

		getline(ss, prefix, ' ');
		if (prefix.compare("v") == 0) {
			ss >> temp_x >> temp_y >> temp_z;
			obj.AddVertex(temp_x, temp_y, temp_z);
		}
		if (prefix.compare("vt") == 0) {
			ss >> temp_x >> temp_y;
			obj.AddCoord(temp_x, temp_y);
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

FaceBase StringToFace(std::string str)
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
