#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <vector>
#include <array>
#include "../include/glm/vec2.hpp"
#include "../include/glm/vec3.hpp"
#include "../include/gl/glut.h"
#include "LoadTexturesShaysWorld.h"

/**
 * @struct FaceBase
 * @brief Vertices or texture coordinate positions of an .obj file.
 */
struct FaceBase
{
	/// stores vertices/texture coordinate position/vertex normal from .obj file
	int v, vt, vn; 
};

/**
 * @class Object3D
 * @author Spencer Shaw
 * @brief A 3D object.
 * 
 * @todo Describe Object3D in detail.
 * 
 */
class Object3D
{
public:

	/** @brief Constructor */
	Object3D(); 
	/** @brief Deconstructor */
	~Object3D();

	/**
	 * @brief Creates a vertex based of float parameters.
	 * @param vertex glm::vec3
	 * @return void
	 */
	void AddVertex(const glm::vec3& vertex);

	/**
	 * @brief Creates a texture coordinate based of float parameters.
	 * @param coord - the coordinate (x, y)
	 * @return void
	 */
	void AddCoord(const glm::vec2& coord); 

	/**
	* @brief	Stores the vertex normals
	* @param	vn	- Vertex normal
	* @return	Void
	*/
	void AddVertexNormal(const glm::vec3& vn);

	/**
	 * @brief Creates faces using FaceBase array.
	 * @param face_arr [4] const FaceBase
	 * @return void
	 */
	void AddFaces(const FaceBase face_arr[4]); 

	/**
	 * @brief Saves the texture name to program.
	 * @param fileName std::string
	 * @return void
	 */
	void SetTextureName(const std::string& fileName); 

	/**
	* @brief	Assigns an object an mtl file name
	* @param	mtlName	- The name of the mtl file
	* @return	Void
	*/
	void SetMTLName(const std::string& mtlName);
	
	/**
	* @brief	Returns the mrl file name associated with the object
	* @param	No param
	* @return	string&	- THe MTL file name
	*/
	const std::string& GetMTLName();

	/**
	* @brief	Assigns which material the object uses
	* @param	location	- The location in the material array that the object uses
	* @return	Void
	*/
	void SetMTLArrayLocation(int location);

	/**
	* @brief	Used to find the material properties for an object
	* @param	No param
	* @return	int		- returns an index for a material array which references the materials properties
	*/
	int GetMTLArrayLocation();

	/**
	 * @brief Returns a vertex of index i.
	 * @param i unsigned
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetVertex(unsigned i) const; 

	/**
	 * @brief Returns a texture coordinate of index i.
	 * @param i unsigned
	 * @return const glm::vec2&
	 */
	const glm::vec2& GetCoord(unsigned i) const; 

	/**
	* @brief	Returns the vertex normal of a vertex based on index i
	* @param	i	- The index of the vertex
	* @return	const glm::vec3&	- The normal of a vertex
	*/
	const glm::vec3& GetVertexNormal(unsigned i) const;



	/**
	 * @brief Returns a set of vertex and coordinate pairs of index i.
	 * @param i unsigned
	 * @return const std::array<Facebase, 4>&
	 */
	const std::array<FaceBase, 4>& GetFace(unsigned i) const;

	/**
	 * @brief Returns the name of the texture file.
	 * @return const std::string&
	 */
	const std::string& GetName() const;

	/**
	 * @brief Allows access to the contents of vertices vector.
	 * @return const std::vector<glm::vec3>&
	 */
	const std::vector<glm::vec3>& GetVertexVector() const; 

	/**
	 * @brief Allows access to the contents of texCoord vector.
	 * @return const std::vector<glm::vec2>&
	 */
	const std::vector<glm::vec2>& GetCoordVector() const;

	/**
	 * @brief Allows access to the contents of faces vector.
	 * @return const std::vector<std::array<Facebase,4>>&
	 */
	const std::vector<std::array<FaceBase, 4>>& GetFaceVector() const;

	/**
	* @brief	Displays the stored object based on the texture
	* @param	textureID	- The define value of the texture
	* @return	Void
	*/
	void DisplayObject(int textureID);

private:
	/// stores the vertices
	std::vector<glm::vec3> vertices; 
	/// stores the texture coordinates
	std::vector<glm::vec2> texCoord; 
	/// stores the vertex normals
	std::vector<glm::vec3> vertexNormals;
	/// saves the links to v and vt for faces
	std::vector<std::array<FaceBase, 4>> faces; 
	/// stores image name (and extension)
	std::string textureFile; 
	/// The name of the mtl file (for material properties for lighting)
	std::string mtlFile;
	/// Points to the index of the material properties of the object
	int mtlLoc;
};

#endif