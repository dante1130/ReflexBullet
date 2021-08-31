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
	 * @param tempType const GLint
	 * @param tempStart const glm::vec3&
	 * @param tempEnd const glm::vec3&
	 * @return void
	 */
	void Push(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

	/**
	 * @brief Set the values of the data at an index
	 * 
	 * @param ptrCount const int
	 * @param tempType const GLint
	 * @param tempStart const glm::vec3&
	 * @param tempEnd const glm::vec3&
	 * @return void
	 */
	void SetData(const int ptrCount, const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief Get the Type
	 * 
	 * @param ptrCount int
	 * @return GLint 
	 */
	GLint GetType(int ptrCount) const;

	/**
	 * @brief Get the starting X coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	const glm::vec3& GetStart(int ptrCount) const;

	/**
	 * @brief Get the ending X coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	const glm::vec3& GetEnd(int ptrCount) const;

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