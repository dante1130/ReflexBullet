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
 * 
 * @todo Collision() and CheckCollision()
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
	 * @param tempX const double&
	 * @return void
	 */
	void SetWorldX(const double &tempX);

	/**
	 * @brief Sets the actual world co-ordinates Z
	 * @param tempZ const double&
	 * @return void
	 */
	void SetWorldZ(const double &tempZ);

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Returns TRUE if a collision occurred.
	 * @param endX double
	 * @param endY double
	 * @param endZ double
	 * @return bool
	 */
	bool Collide(const glm::dvec3& end);

	/**
	 * @brief Reads the BB info from AABB (dynamic array) and creates a Linked List containing BB data.
	 * @return void
	 */
	int GetQuadrant(const glm::vec3& max, const glm::vec3& min);

private:
	/// vectors to store bounding box info in each quadrant
	AABBVector m_list[4];

	/// stores world co-ordinates
	double m_worldSizeX, m_worldSizeZ;

	/**
	 * @brief Checks if collision occurred (called from Collide).
	 * @param index int
	 * @param endX double
	 * @param endY double
	 * @param endZ double
	 */
	bool CheckCollision(int index, const glm::dvec3& end);
};

#endif
//--------------------------------------------------------------------------------------