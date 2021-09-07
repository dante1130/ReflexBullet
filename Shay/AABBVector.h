//  AABBVector.h
//  Header file for the AABBVector class
//  Linked List used to store nodes (AABBNode) which contain the co-ordinates of the 
//  boundings boxes which are used for the collsion detection.
//
//	The program splits the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBVECTOR_H
#define AABBVECTOR_H

//--------------------------------------------------------------------------------------

#include "BoundingBox.h"
#include <vector>

//--------------------------------------------------------------------------------------

/** 
 * @class AABBVector
 * @brief Vector to store bounding box details
 */
class AABBVector
{
public:
	/**
	 * @brief Default constructor
	 */
	AABBVector();

	//----------------------------------------------------------------------------------

	/**
	 * @brief Add a bounding box
	 * @param max const glm::dvec3&
	 * @param min const glm::dvec3&
	 * @return void
	 */
	void Push(const glm::vec3& max, const glm::vec3& min);
	
	/**
	 * @brief Set the values of the data at an index
	 * @param index int
	 * @param max const glm::dvec3&
	 * @param min const glm::dvec3&
	 * @return void
	 */
	void SetData(int index, const glm::vec3& max, const glm::vec3& min);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief	Gets the maximum extent.
	 * @param	index int
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMax(int index) const;

	/**
	 * @brief	Gets the maximum extent.
	 * @param	index int
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMin(int index) const;
	
	/**
	 * @brief Return size of vector
	 * @return int 
	 */
	int Size() const;

//--------------------------------------------------------------------------------------

private:
	/// vector of BoundingBox
	std::vector<BoundingBox> m_AABB;
};

#endif

//--------------------------------------------------------------------------------------