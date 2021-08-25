//  collsion.h
//  Header file for the collision class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include "AABB.h"
#include "AABBLinkedList.h"

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

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	
	// (these set the co-ords is AABB, the array, the values for the list are copied from the array using CreateLinkedList).
	
	/**
	 * @brief Sets initial co-ordinates of bounding boxes of maximum X.
	 * @param tempIndex const int&
	 * @param tempX const double&
	 * @return void
	 */
	void SetAABBMaxX(const int& tempIndex, const double& tempX);

	/**
	 * @brief Sets initial co-ordinates of bounding boxes of minimum X.
	 * @param tempIndex const int&
	 * @param tempX const double&
	 * @return void
	 */
	void SetAABBMinX(const int& tempIndex, const double& tempX);

	/**
	 * @brief Sets initial co-ordinates of bounding boxes of maximum Y.
	 * @param tempIndex const int&
	 * @param tempY const double&
	 * @return void
	 */
	void SetAABBMaxY(const int& tempIndex, const double& tempY);

	/**
	 * @brief Sets initial co-ordinates of bounding boxes of minimum Y.
	 * @param tempIndex const int&
	 * @param tempY const double&
	 * @return void
	 */
	void SetAABBMinY(const int& tempIndex, const double& tempY);

	/**
	 * @brief Sets initial co-ordinates of bounding boxes of maximum Z.
	 * @param tempIndex const int&
	 * @param tempZ const double&
	 * @return void
	 */
	void SetAABBMaxZ(const int& tempIndex, const double& tempZ);

	/**
	 * @brief Sets initial co-ordinates of bounding boxes of minimum Z.
	 * @param tempIndex const int&
	 * @param tempZ const double&
	 * @return void
	 */
	void SetAABBMinZ(const int& tempIndex, const double& tempZ);

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

	/**
	 * @brief Set number of bounding boxes.
	 * @param tempSize const int&
	 * @return void
	 */
	void SetNoBoundingBoxes(const int & tempSize);

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------
	
	/**
	 * @brief Returns co-ordinates of bounding boxes of maximum X
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMaxX(const int& tempIndex) const;

	/**
	 * @brief Returns co-ordinates of bounding boxes of minimum X
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMinX(const int& tempIndex) const;

	/**
	 * @brief Returns co-ordinates of bounding boxes of maximum Y
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMaxY(const int& tempIndex) const;

	/**
	 * @brief Returns co-ordinates of bounding boxes of minimum Y
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMinY(const int& tempIndex) const;

	/**
	 * @brief Returns co-ordinates of bounding boxes of maximum Z
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMaxZ(const int& tempIndex) const;

	/**
	 * @brief Returns co-ordinates of bounding boxes of minimum Z
	 * @param tempIndex const int&
	 * @return double
	 */
	double GetAABBMinZ(const int& tempIndex) const;

	/**
	 * @brief Returns number of bounding boxes.
	 * @return int
	 */
	int GetNoBoundingBoxes() const;

	/**
	 * @brief Returns TRUE if a collision occurred.
	 * @param endX double
	 * @param endY double
	 * @param endZ double
	 * @return bool
	 */
	bool Collide(double endX, double endY, double endZ);

	/**
	 * @brief Reads the BB info from AABB (dynamic array) and creates a Linked List containing BB data.
	 * @return void
	 */
	void CreateLinkedList();

private:
	/// initially stores BB info in AABB (dynamic array) before copying to Linked List
	AABB m_AABB;

	/// lists to store bounding box info in each quadrant
	AABBLinkedList m_list[4];

	/// Stores the list size of each linked list, set to 4 has the world is split into 4 quadrants
	int m_listSize[4];

	/// stores world co-ordinates
	double m_worldSizeX, m_worldSizeZ;

	/**
	 * @brief Checks if collision occurred (called from Collide).
	 * @param index int
	 * @param endX double
	 * @param endY double
	 * @param endZ double
	 */
	bool CheckCollision(int index, double endX, double endY, double endZ);
};

#endif
//--------------------------------------------------------------------------------------