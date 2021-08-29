//  AABBNODE.h
//  Header file for the AABBNODE class
//  Stores details for each bounding box used for collision detection.  Each node is stored
//  in each link of the AABB Linked List

//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBNODE_H
#define AABBNODE_H

#include "BoundingBox.h"
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

/** 
 * @class	AABBNode
 * @brief	Stores details for each bounding box used for collision detection.
 */
class AABBNode
{
public:
	/**
	 * @brief Default constructor.
	 */
	AABBNode();

	/**
	 * @brief Deconstructor.
	 */
    virtual ~AABBNode();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief	Gets the maximum extent.
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMax() const;

	/**
	 * @brief	Gets the maximum extent.
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMin() const;

	AABBNode* GetNext() const;

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief	Sets the extents of the BoundingBox.
	 * @param	maxX const GLdouble
	 * @param	minX const GLdouble
	 * @param	maxY const GLdouble
	 * @param	minY const GLdouble
	 * @param	maxZ const GLdouble
	 * @param	minZ const GLdouble
	 * @return	void
	 */
	void SetData(const glm::vec3& max, const glm::vec3& min);

    /**
     * @brief	Set the address of the link to the next node in the list.
     * @param	next AABBNode*
     * @return	void
     */
	void SetNext(AABBNode* next);

private:
    /// The address of the next node in the list
	AABBNode* m_next;

	/// stores above info
	BoundingBox m_bBox;

	//----------------------------------------------------------------------------------

	/**
	 * @brief	Helper function for copy constructor and assignment operator.
	 * @return	void
	 */
	void Copy(const AABBNode& newNode);

	/**
	 * @brief	Helper function for Deconstructor.
	 * @return	void
	 */
	void Clear();

    /**
     * @brief	Privatized copy constructor.
     * @param	newNode const AABBNode&
     */
	AABBNode(const AABBNode& newNode);

	/**
	 * @brief	Privatized assignment operator overload.
	 * @param	newNode const AABBNode&
	 */
	AABBNode& operator=(const AABBNode& newNode);
};

#endif
//--------------------------------------------------------------------------------------