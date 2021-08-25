//  AABH.h
//  Header file for the AABB class
//  Dynamic Array used to store the co-ordinates of the bounding boxes used for collsion 
//  detection.  The array is only used initially before being copied into AABB Linked Lists.
//  The array is then terminated.
//  
//  I created this class originally before using linked lists to store the BB info. But decided
//  to keep it has the stored data can be easily copied across into different linked lists
//  in any preferred order. (i.e. the data is copied into across into linked lists for different
//  quadrants)
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABB_H
#define AABB_H

//--------------------------------------------------------------------------------------

#include <vector>
#include <gl/glut.h>
#include "BoundingBox.h"

//--------------------------------------------------------------------------------------
/**
 * @class	AABB
 * @brief	Bounding boxes for collision detection.
 * 
 * Collision is set up in a way where there is a minimum extent and maximum extent,
 * and collision can be detected if they are within those extents.
 *
 */
class AABB
{
private:
	/// dynamic array to store info
	std::vector<BoundingBox> m_bBox;

public:
	/** @brief Default constructor */
	AABB();
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/** 
	 * @brief	Sets the maximum extent of X.
	 * @param	tempIndex const int&
	 * @param	tempX const GLdouble&
	 * @return	void
	 */
	void SetMaxX(const int& tempIndex, const GLdouble& tempX);

	/** 
	 * @brief	Sets the minimum extent of X.
	 * @param	tempIndex const int&
	 * @param	tempX const GLdouble&
	 * @return	void
	 */
	void SetMinX(const int& tempIndex, const GLdouble& tempX);

	/** 
	 * @brief	Sets the maximum extent of Y.
	 * @param	tempIndex const int&
	 * @param	tempY const GLdouble&
	 * @return	void
	 */
	void SetMaxY(const int& tempIndex, const GLdouble& tempY);

	/** 
	 * @brief	Sets the minimum extent of Y.
	 * @param	tempIndex const int&
	 * @param	tempY const GLdouble&
	 * @return	void
	 */
	void SetMinY(const int& tempIndex, const GLdouble& tempY);

	/** 
	 * @brief	Sets the maximum extent of Z.
	 * @param	tempIndex const int&
	 * @param	tempZ const GLdouble&
	 * @return	void
	 */
	void SetMaxZ(const int& tempIndex, const GLdouble& tempZ);

	/** 
	 * @brief	Sets the minimum extent of Z.
	 * @param	tempIndex const int&
	 * @param	tempZ const GLdouble&
	 * @return	void
	 */
	void SetMinZ(const int& tempIndex, const GLdouble& tempZ);

	/** 
	 * @brief	Sets the number of bounding boxes.
	 * @param	tempSize const int&
	 * @return	void
	 */
	void SetNoBoundingBoxes(const int& tempSize);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/** 
	 * @brief	Gets the minimum extent of X.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMaxX(const int& tempIndex) const;

	/*
	 * @brief	Gets the maximum extent of X.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMinX(const int& tempIndex) const;

	/** 
	 * @brief	Gets the maximum extent of Y.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMaxY(const int& tempIndex) const;

	/** 
	 * @brief	Gets the minimum extent of Y.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMinY(const int& tempIndex) const;

	/** 
	 * @brief	Gets the maximum extent of Z.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMaxZ(const int& tempIndex) const;

	/** 
	 * @brief	Gets the minimum extent of Z.
	 * @param	tempIndex const int&
	 * @return	GLdouble
	 */
	GLdouble GetMinZ(const int& tempIndex) const;

	/** 
	 * @brief	Gets the maximum extent of X.
	 * @return	int
	 */
	int GetNoBoundingBoxes() const;
};

#endif
//--------------------------------------------------------------------------------------