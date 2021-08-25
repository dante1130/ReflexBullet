//  PlainLinkedList.h
//  Header file for the PlainLinkedList class
//  Linked List used to store nodes (PlainNode) which contain the co-ordinates of the 
//  of each plain used in the program.
//
//	The program will split the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINLINKED_LIST_H
#define PLAINLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "PlainNode.h"

//--------------------------------------------------------------------------------------

/**
 * @class PlainLinkedList
 * @brief A linkedlist to store nodes of PlainNodes
 * 
 */
class PlainLinkedList
{
public:
	/**
	 * @brief Constructor creates pointer to first node
	 */
	PlainLinkedList();

	/**
	 * @brief Destroy the Plain Linked List object
	 */
	virtual ~PlainLinkedList();

	//----------------------------------------------------------------------------------

	/**
	 * @brief Add a node to the start of the linked list
	 * 
	 * @param tempType const GLdouble
	 * @param tempXs const GLdouble
	 * @param tempXe const GLdouble
	 * @param tempYs const GLdouble
	 * @param tempYe const GLdouble
	 * @param tempZs const GLdouble
	 * @param tempZe const GLdouble
	 * @return bool
	 */
	bool AddToStart (const int tempType,
				     const GLdouble tempXs, const GLdouble tempXe,
				     const GLdouble tempYs, const GLdouble tempYe,
				     const GLdouble tempZs, const GLdouble tempZe);

	/**
	 * @brief Set the values of the node data
	 * 
	 * @param ptrCount const int
	 * @param tempType const int
	 * @param tempXs const GLdouble
	 * @param tempXe const GLdouble
	 * @param tempYs const GLdouble
	 * @param tempYe const GLdouble
	 * @param tempZs const GLdouble
	 * @param tempZe const GLdouble
	 * @return void
	 */
	void SetData(const int ptrCount, const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	/**
	 * @brief Get the Type
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetType(int ptrCount) const;

	/**
	 * @brief Get the starting X coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetXStart(int ptrCount) const;

	/**
	 * @brief Get the ending X coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetXEnd(int ptrCount) const;

	/**
	 * @brief Get the starting Y coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetYStart(int ptrCount) const;

	/**
	 * @brief Get the ending Y coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetYEnd(int ptrCount) const;

	/**
	 * @brief Get the starting Z coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetZStart(int ptrCount) const;

	/**
	 * @brief Get the ending Z coordinates.
	 * 
	 * @param ptrCount int
	 * @return GLdouble 
	 */
	GLdouble GetZEnd(int ptrCount) const;

	/**
	 * @brief Return size of list
	 * 
	 * @return int 
	 */
	int GetListSize() const;
	
	/**
	 * @brief Return the address of the link to the next node in the list
	 * 
	 * @return PlainNode* 
	 */
	PlainNode* GetNext() const;

	/**
	 * @brief Return the address of the link to the first node in the list
	 * 
	 * @return PlainNode* 
	 */
	PlainNode* GetFirst() const;


//--------------------------------------------------------------------------------------

private:
	/// pointer to first node in list
	PlainNode* m_first;

	/**
	 * @brief Helper function to be used in the copy constructor and assignment operator.
	 * 
	 * @param ll const PlainLinkedList&
	 * @return void
	 */
	void Copy(const PlainLinkedList& ll);

	/**
	 * @brief Clears linked list and frees memory, to be used in the deconstructor.
	 * @return void
	 */
	void Clear();

	/**
	 * @brief Helper function to be used in the deconstructor.
	 * 
	 * @param before PlainNode*
	 * @return void
	 */
	void Delete(PlainNode* before);

	/**
	 * @brief Privatized copy constructor
	 * 
	 * @param ll const PlainLinkedList&
	 */
	PlainLinkedList (const PlainLinkedList &ll);

	/**
	 * @brief Privatized assignment operator overload 
	 * 
	 * @param ll const PlainLinkedList&
	 * @return PlainLinkedList& 
	 */
	PlainLinkedList& operator=(const PlainLinkedList& ll);
};

#endif

//--------------------------------------------------------------------------------------