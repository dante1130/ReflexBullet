//  AABBLinkedList.cpp
//
//  Implementation file for AABBLinkedList Class
//  Defines all the methods declared, but not defined, in AABBLinkedList.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABBLinkedList.h"

//--------------------------------------------------------------------------------------

void AABBLinkedList::Clear()
{
	AABBNode *ptr = m_first;

	while (ptr->GetNext() != nullptr)
	
	// clear memory
	Delete(ptr);
}

//--------------------------------------------------------------------------------------

void AABBLinkedList::Delete(AABBNode *before)
{
	AABBNode *temp = before->GetNext();

	before->SetNext(temp->GetNext());

	delete temp;
}

AABBLinkedList::AABBLinkedList(const AABBLinkedList& ll)
{

}

AABBLinkedList::AABBLinkedList() : m_first(new AABBNode)
{

}

AABBLinkedList::~AABBLinkedList()
{
	Clear();
}

AABBLinkedList& AABBLinkedList::operator=(const AABBLinkedList& ll)
{
	return *this;
}

//--------------------------------------------------------------------------------------

bool AABBLinkedList::AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY,
				             GLdouble minY, GLdouble maxZ, GLdouble minZ)
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
	newNode->SetData(maxX, minX, maxY, minY, maxZ, minZ);
	// set the address of the net node
	newNode->SetNext(m_first->GetNext());
	// reset the address of the first node
	m_first->SetNext(newNode);

	return true;
}

//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMaxX (int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMaxX();
}
//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMinX (int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMinX();	
}

//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMaxY (int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMaxY();	
}

//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMinY(int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMinY();	
}

//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMaxZ (int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMaxZ();
}

//--------------------------------------------------------------------------------------

GLdouble AABBLinkedList::GetMinZ (int ptrCount)
{
	AABBNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetMinZ();	
}

//--------------------------------------------------------------------------------------

void AABBLinkedList::SetData (const int &ptrCount,
							  const GLdouble maxX, const GLdouble minX,
				              const GLdouble maxY, const GLdouble minY,
				              const GLdouble maxZ, const GLdouble minZ)
{
	AABBNode *ptr = (m_first);

	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}
	ptr->GetNext()->SetData(maxX, minX, maxY, minY, maxZ, minZ);	
}

//--------------------------------------------------------------------------------------

int AABBLinkedList::GetListSize()
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