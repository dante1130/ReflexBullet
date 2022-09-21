//  collision.h
//  Header file for the collision class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include <glm/common.hpp>
#include "AABBVector.h"
#include "BoundingSphere.h"

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
	 * @brief Clears the vector.
	 * @return void
	 */
	void Clear();

	/**
	* @brief	Sets the bounding box to the vector
	* @param	max	- The maximum coordinate of the bounding box
	* @param	min	- The minimum coordinate of the bounding box
	* @return	Void
	*/
	void Push(const glm::vec3& max, const glm::vec3& min);

	/**
	 * @brief	Gets the reference to the AABBvector of a quadrant.
	 * @param	index int
	 * @return	AABBVector&
	 */
	AABBVector& GetQuadrant(int index);

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
	 * @brief Collision check between a point and a bounding sphere.
	 * @param point const glm::vec3&
	 * @param bSphere const BoundingSphere&
	 * @return bool
	 */
	static bool Collide(const glm::vec3& point, const BoundingSphere& bSphere);
	
	/**
	 * @brief Collision check between a bounding box and a bounding sphere.
	 * @param bBox const BoundingBox&
	 * @param bSphere const BoundingSphere&
	 * @return bool
	 */
	static bool Collide(const BoundingBox& bBox, const BoundingSphere& bSphere);

	/**
	 * @brief Collision check between a bounding boxes.
	 * @param bBox1 const BoundingBox&
	 * @param bBox2 const BoundingBox&
	 * @return bool
	 */
	static bool Collide(const BoundingBox& bBox1, const BoundingBox& bBox2);

	/**
	 * @brief Collision check between a bounding spheres.
	 * @param bSphere1 const BoundingSphere&
	 * @param bSphere2 const BoundingSphere&
	 * @return bool
	 */
	static bool Collide(const BoundingSphere& bSphere1, const BoundingSphere& bSphere2);

	/**
	 * @brief Collision checks for the AABB quadrants with the bounding sphere.
	 * @param bSphere const BoundingSphere&
	 * @return bool
	 */
	bool Collide(const BoundingSphere& bSphere);

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
	 * @brief Checks if collision occured with a boundingSphere.
	 * @param index int
	 * @param bSphere const BoundingSphere&
	 * @return bool
	 */
	bool CheckCollision(int index, const BoundingSphere& bSphere);

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