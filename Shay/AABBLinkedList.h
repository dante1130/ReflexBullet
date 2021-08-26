//  AABBLinkedList.h
//  Header file for the AABBLinkedList class
//  Linked List used to store nodes (AABBNode) which contain the co-ordinates of the 
//  boundings boxes which are used for the collsion detection.
//
//	The program splits the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "AABBNode.h"

//--------------------------------------------------------------------------------------

/** 
 * @class AABBLinkedList
 * @brief Linked list to store bounding box details
 */
class AABBLinkedList
{
public:
	/**
	 * @brief Constructor creates pointer to first node.
	 */
	AABBLinkedList();

	/**
	 * @brief Deconstructor.
	 */
	virtual ~AABBLinkedList();

	//----------------------------------------------------------------------------------



	/**
	 * @brief Add a node to the start of the linked list.
	 * @param maxX GLdouble
	 * @param minX GLdouble
	 * @param maxY GLdouble
	 * @param minY GLdouble
	 * @param maxZ GLdouble
	 * @param minZ GLdouble
	 * @return bool
	 */
	bool AddToStart(GLdouble maxX, GLdouble minX, GLdouble maxY,
				    GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
	/**
	 * @brief Set the values of the node data.
	 * @param maxX GLdouble
	 * @param minX GLdouble
	 * @param maxY GLdouble
	 * @param minY GLdouble
	 * @param maxZ GLdouble
	 * @param minZ GLdouble
	 * @return void
	 */
	void SetData(const int& ptrCount,
				 const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief Get the maximum X extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMaxX(int ptrCount) const;

	/**
	 * @brief Get the minimum X extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMinX(int ptrCount) const;

	/**
	 * @brief Get the maximum Y extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMaxY(int ptrCount) const;

	/**
	 * @brief Get the minimum Y extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMinY(int ptrCount) const;

	/**
	 * @brief Get the maximum Z extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMaxZ(int ptrCount) const;

	/**
	 * @brief Get the minimum Z extent
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetMinZ(int ptrCount) const;
	
	/**
	 * @brief Return size of list
	 * 
	 * @return int 
	 */
	int GetListSize() const;
	
	/**
	 * @brief Return the address of the link to the next node in the list
	 * 
	 * @return AABBNode* 
	 */
	AABBNode* GetNext() const;

	/**
	 * @brief Return the address of the link to the first node in the list
	 * 
	 * @return AABBNode* 
	 */
	AABBNode *GetFirst() const;

//--------------------------------------------------------------------------------------

private:
	/// pointer to first node in list
	AABBNode *m_first;

	/// number of nodes in the list
	int m_listSize;

	/**
	 * @brief Helper function to be used in the copy constructor and assignment operator.
	 * 
	 * @param ll AABBLinkedList&
	 * @return void
	 */
	void Copy(const AABBLinkedList& ll);

	/**
	 * @brief Clears linked list and frees memory, to be used in the deconstructor.
	 * @return void
	 */
	void Clear();

	/**
	 * @brief Helper function to be used in the deconstructor.
	 * 
	 * @param before AABBNode*
	 * @return void
	 */
	void Delete (AABBNode* before);

	/**
	 * @brief Privatized copy constructor
	 * 
	 * @param ll const AABBLinkedList&
	 */
	AABBLinkedList(const AABBLinkedList& ll);

	/**
	 * @brief Privatized assignment operator overload 
	 * 
	 * @param ll const AABBLinkedList&
	 * @return AABBLinkedList& 
	 */
	AABBLinkedList& operator=(const AABBLinkedList& ll);
};

#endif

//--------------------------------------------------------------------------------------