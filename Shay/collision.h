//  collision.h
//  Header file for the collision class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include "AABBVector.h"

//--------------------------------------------------------------------------------------

/**
 * @class Collision
 * @brief Collision class using AABB Bounding boxes.
 */
class Collision
{
public:
	/**
	 * @brief Default constructor.
	 */
	Collision();

	/**
	* @brief	Sets the bounding box to the vector
	* @param	max	- The maximum coordinate of the bounding box
	* @param	min	- The minimum coordinate of the bounding box
	* @return	Void
	*/
	void Push(const glm::vec3& max, const glm::vec3& min);

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Sets the actual world co-ordinates X.
	 * @param tempX double
	 * @return void
	 */
	void SetWorldX(const double& tempX);

	/**
	 * @brief Sets the actual world co-ordinates Z
	 * @param tempZ double
	 * @return void
	 */
	void SetWorldZ(const double& tempZ);

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Returns TRUE if a collision occurred.
	 * @param end const glm::dvec3&
	 * @return bool
	 */
	bool Collide(const glm::dvec3& end);


private:
	/// vectors to store bounding box data in each quadrant
	AABBVector m_list[4];

	/// stores world co-ordinates
	double m_worldSizeX, m_worldSizeZ;

	/**
	 * @brief Checks if collision occurred (called from Collide).
	 * @param index int
	 * @param end const glm::dvec3&
	 * @return bool
	 */
	bool CheckCollision(int index, const glm::dvec3& end);

	/**
	 * @brief	Gets the quadrant - used for efficiency of bounding boxes
	 * @param	max	- The max coordiante of the bounding box
	 * @param	min - The min coordinate of the bounding box
	 * @return	Void
	 */
	void GetQuadrant(const glm::vec3& max, const glm::vec3& min);
};

#endif
//--------------------------------------------------------------------------------------