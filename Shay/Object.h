#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <array>



typedef struct vertex {
	float x, y, z; //storing 3d points
}vertex;

typedef struct coord {
	float x, y; //stroing 2d points
}coord;

typedef struct FaceBase {
	int v, vt; //stores vertice/texture coordinate posiiton from .obj file
}FaceBase;

class Object3D
{
public:

	Object3D(); //constructor
	~Object3D(); //deconstructor

	void AddVertex(float x, float y, float z); //creates a vertice based of flaot parameters
	void AddCoord(float x, float y); //creates a texture coordinate based of flaot parameters
	void AddFaces(const FaceBase face_arr[4]); //creates faces using FaceBase array
	void SetTextureName(std::string fileName); //saves the texture name to program

	const vertex& GetVertex(const unsigned i); //returns a vertex of index i
	const coord& GetCoord(const unsigned i); //returns a texture coordinate of indec i
	const std::array<FaceBase, 4> & GetFace(const unsigned i); //returns a set of vertex and coord pairs of index i
	const std::string& GetName(); //returns the name of the texture file
	const std::vector<vertex>& GetVertexVector(); //allows access to the contents of vertices vector
	const std::vector<coord>& GetCoordVector(); //allows access to the contents of texCoord vector
	const std::vector<std::array<FaceBase, 4>>& GetFaceVector(); //allows access to the contents of faces vector


private:
	std::vector<vertex> vertices; // stores the vertices
	std::vector<coord> texCoord; // stores the texture coordinates
	std::vector<std::array<FaceBase, 4>> faces; // saves the links to v and vt for faces
	std::string textureFile; // stores image name (and extention)
};

#endif