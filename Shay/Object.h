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
	/// stores vertices/texture coordinate position from .obj file
	int v, vt; 
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
	 * @brief Creates faces using FaceBase array.
	 * @param face_arr [4] const FaceBase
	 * @return void
	 */
	void AddFaces(const std::vector<FaceBase>& face_temp);

	/**
	 * @brief Saves the texture name to program.
	 * @param fileName std::string
	 * @return void
	 */
	void SetTextureName(const std::string& fileName); 

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
	 * @brief Returns a set of vertex and coordinate pairs of index i.
	 * @param i unsigned
	 * @return const std::array<Facebase, 4>&
	 */
	const std::vector<FaceBase>& GetFace(unsigned i) const;

	/**
	 * @brief Returns the name of the texture file.
	 * @return const std::string&
	 */
	const std::string& GetName() const;

	/**
	* @brief	Displays the stored object based on the texture
	* @param	textureID	- The define value of the texture
	* @return	Void
	*/
	void DisplayObject(int textureID);

private:
	/**
	 * @brief Allows access to the contents of faces vector.
	 * @return const std::vector<std::array<Facebase,4>>&
	 */
	const unsigned GetFaceVectorSize() const;


	/// stores the vertices
	std::vector<glm::vec3> vertices; 
	/// stores the texture coordinates
	std::vector<glm::vec2> texCoord; 
	/// saves the links to v and vt for faces
	std::vector<std::vector<FaceBase>> faces; 
	/// stores image name (and extension)
	std::string textureFile; 
};

#endif