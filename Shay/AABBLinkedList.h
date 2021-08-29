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
	 * @param max const glm::dvec3&
	 * @param min const glm::dvec3&
	 * @return bool
	 */
	bool AddToStart(const glm::vec3& max, const glm::vec3& min);
	
	/**
	 * @brief Set the values of the node data.
	 * @param ptrCount const int&
	 * @param max const glm::dvec3&
	 * @param min const glm::dvec3&
	 * @return void
	 */
	void SetData(const int& ptrCount, const glm::vec3& max, const glm::vec3& min);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief	Gets the maximum extent.
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMax(int ptrCount) const;

	/**
	 * @brief	Gets the maximum extent.
	 * @return	const glm::vec3&
	 */
	const glm::vec3& GetMin(int ptrCount) const;
	
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