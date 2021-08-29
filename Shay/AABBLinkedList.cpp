//  AABBLinkedList.cpp
//
//  Implementation file for AABBLinkedList Class
//  Defines all the methods declared, but not defined, in AABBLinkedList.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABBLinkedList.h"

//--------------------------------------------------------------------------------------

AABBLinkedList::AABBLinkedList()
	: m_first(new AABBNode), m_listSize(1) {}

AABBLinkedList::AABBLinkedList(const AABBLinkedList& ll)
{
	Copy(ll);
}

AABBLinkedList& AABBLinkedList::operator=(const AABBLinkedList& ll)
{
	Copy(ll);
	return *this;
}

AABBLinkedList::~AABBLinkedList()
{
	Clear();
}

void AABBLinkedList::Copy(const AABBLinkedList& ll)
{
	m_first = ll.m_first;
	m_listSize = ll.m_listSize;
}

void AABBLinkedList::Clear()
{
	AABBNode* ptr = m_first;

	while (ptr->GetNext() != nullptr)
		Delete(ptr); // clear memory
}

//--------------------------------------------------------------------------------------

void AABBLinkedList::Delete(AABBNode *before)
{
	AABBNode* temp = before->GetNext();

	before->SetNext(temp->GetNext());

	delete temp;
	temp = nullptr;
}

//--------------------------------------------------------------------------------------

bool AABBLinkedList::AddToStart(const glm::vec3& max, const glm::vec3& min)
{
	AABBNode *newNode;
	try
	{
		newNode = new AABBNode;
	}
	catch(...)
	{
		return false;
	}
	
	// add the value to the node
	newNode->SetData(max, min);
	// set the address of the net node
	newNode->SetNext(m_first->GetNext());
	// reset the address of the first node
	m_first->SetNext(newNode);

	return true;
}

//--------------------------------------------------------------------------------------

const glm::vec3& AABBLinkedList::GetMax(int ptrCount) const
{
	AABBNode* ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMax();
}

/**
 * @brief	Gets the maximum extent.
 * @return	const glm::vec3&
 */
const glm::vec3& AABBLinkedList::GetMin(int ptrCount) const
{
	AABBNode* ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMin();
}

//--------------------------------------------------------------------------------------

void AABBLinkedList::SetData(const int &ptrCount, const glm::vec3& max, const glm::vec3& min)
{
	AABBNode *ptr = (m_first);

	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}
	ptr->GetNext()->SetData(max, min);	
}

//--------------------------------------------------------------------------------------

int AABBLinkedList::GetListSize() const
{
	int tmpSize = 0;
	// count size of list
	for (AABBNode *ptr = (m_first); ptr->GetNext() != nullptr; ptr = ptr->GetNext())
	{
		tmpSize++;
	}
	return tmpSize;
}

AABBNode* AABBLinkedList::GetNext() const
{
	return m_first->GetNext();
}

AABBNode* AABBLinkedList::GetFirst() const
{
	return m_first;
}

//--------------------------------------------------------------------------------------