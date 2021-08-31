//  PlainVector.h
//  Header file for the PlainVector class
//  Linked List used to store nodes (Plain) which contain the co-ordinates of the 
//  of each plain used in the program.
//
//	The program will split the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINVECTOR_H
#define PLAINVECTOR_H

//--------------------------------------------------------------------------------------

#include "Plain.h"
#include <vector>

//--------------------------------------------------------------------------------------

/**
 * @class PlainVector
 * @brief A vector to store nodes of PlainNodes
 * 
 */
class PlainVector
{
public:
	/**
	 * @brief Default constructor
	 */
	PlainVector();

	//----------------------------------------------------------------------------------

	/**
	 * @brief Pushes new plain into the vector
	 * 
	 * @param type GLint
	 * @param start const glm::vec3&
	 * @param end const glm::vec3&
	 * @return void
	 */
	void Push(GLint type, const glm::vec3& start, const glm::vec3& end);

	/**
	* @brief	Sets a special diagonal plain
	* 
	* @param	tempType	- The type of plain
	* @param	t1			- first coordinate
	* @param	t2			- second coordinate
	* @param	t3			- third coordinate
	* @param	t4			- fourth coordinate
	* 
	* @return	Void
	*/
	void PlainVector::Push(const GLint tempType, const glm::vec3& t1, const glm::vec3& t2, const glm::vec3& t3, const glm::vec3& t4);

	/**
	 * @brief Set the values of the data at an index
	 * 
	 * @param index int
	 * @param type GLint
	 * @param start const glm::vec3&
	 * @param end const glm::vec3&
	 * @return void
	 */
	void SetData(int index, GLint type, const glm::vec3& start, const glm::vec3& end);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief Get the Type
	 * 
	 * @param index int
	 * @return GLint 
	 */
	GLint GetType(int index) const;

	/**
	 * @brief Get the starting X coordinates.
	 * 
	 * @param index int
	 * @return GLdouble 
	 */
	const glm::vec3& GetStart(int index) const;

	/**
	 * @brief Get the ending X coordinates.
	 * 
	 * @param index int
	 * @return GLdouble 
	 */
	const glm::vec3& GetEnd(int index) const;

	/**
	* @brief	Returns the coordinate for coordiante 2 for the plain
	* @param	ptrCount	- The plain that is being selected
	* @return	glm gec3
	*/
	const glm::vec3& PlainVector::GetQ2(int ptrCount) const;

	/**
	* @brief	Returns the coordinate for coordiante 4 for the plain
	* @param	ptrCount	- The plain that is being selected
	* @return	glm gec3
	*/
	const glm::vec3& PlainVector::GetQ4(int ptrCount) const;


	/**
	 * @brief Return size of list
	 * 
	 * @return int 
	 */
	int Size() const;

//--------------------------------------------------------------------------------------

private:
	/// vector of Plain
	std::vector<Plain> m_plains;
};

#endif

//--------------------------------------------------------------------------------------