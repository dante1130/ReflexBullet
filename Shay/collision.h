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

	void Push(const glm::vec3& max, const glm::vec3& min);

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Sets the actual world co-ordinates X.
	 * @param tempX double
	 * @return void
	 */
	void SetWorldX(double tempX);

	/**
	 * @brief Sets the actual world co-ordinates Z
	 * @param tempZ double
	 * @return void
	 */
	void SetWorldZ(double tempZ);

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
};

#endif
//--------------------------------------------------------------------------------------