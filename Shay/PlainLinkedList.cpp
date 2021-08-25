//  PlainLinkedList.cpp
//
//  Implementation file for PlainLinkedList Class
//  Defines all the methods declared, but not defined, in PlainLinkedList.h
//
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#include "PlainLinkedList.h"

PlainLinkedList::PlainLinkedList() 
	: m_first(new PlainNode) {}

PlainLinkedList::PlainLinkedList(const PlainLinkedList& ll)
{
	Copy(ll);
}

PlainLinkedList& PlainLinkedList::operator=(const PlainLinkedList& ll)
{
	Copy(ll);
	return *this;
}

PlainLinkedList::~PlainLinkedList()
{
	Clear();
}

void PlainLinkedList::Copy(const PlainLinkedList& ll)
{
	m_first = ll.m_first;
}

//--------------------------------------------------------------------------------------

void PlainLinkedList::Clear()
{
	PlainNode *ptr = m_first;

	while (ptr->GetNext() != nullptr)
	
	// clear memory
	Delete(ptr);
}

//--------------------------------------------------------------------------------------

void PlainLinkedList::Delete(PlainNode *before)
{
	PlainNode *temp = before->GetNext();

	before->SetNext(temp->GetNext());

	delete temp;
	temp = nullptr;
}

//--------------------------------------------------------------------------------------


bool PlainLinkedList::AddToStart (const int tempType,
							      const GLdouble tempXs, const GLdouble tempXe,
								  const GLdouble tempYs, const GLdouble tempYe,
				                  const GLdouble tempZs, const GLdouble tempZe)
{
	PlainNode *newNode;

	try
	{
		newNode = new PlainNode;
	}
	catch(...)
	{
		return false;
	}
	
	// add the value to the node
	newNode->SetData(tempType, tempXs, tempXe, tempYs, tempYe, tempZs, tempZe);
	// set the address of the net node
	newNode->SetNext(m_first->GetNext());
	// reset the address of the first node
	m_first->SetNext(newNode);

	return true;
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetType(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetType();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetXStart(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetXStart();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetXEnd(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetXEnd();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetYStart(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetYStart();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetYEnd(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetYEnd();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetZStart(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetZStart();	
}

//--------------------------------------------------------------------------------------

GLdouble PlainLinkedList::GetZEnd(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetZEnd();	
}


//--------------------------------------------------------------------------------------

void PlainLinkedList::SetData (const int ptrCount, const int tempType,
							   const GLdouble tempXs, const GLdouble tempXe,
				               const GLdouble tempYs, const GLdouble tempYe,
				               const GLdouble tempZs, const GLdouble tempZe)
{
	PlainNode *ptr = (m_first);

	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}
	ptr->GetNext()->SetData(tempType, tempXs, tempXe, tempYs, tempYe, tempZs, tempZe);
}

//--------------------------------------------------------------------------------------

int PlainLinkedList::GetListSize() const
{
	int tmpSize = 0;
	// count size of list
	for (PlainNode *ptr = (m_first); ptr->GetNext() != nullptr; ptr = ptr->GetNext())
	{
		tmpSize++;
	}
	return tmpSize;
}

PlainNode* PlainLinkedList::GetNext() const
{
	return m_first->GetNext();
}

PlainNode* PlainLinkedList::GetFirst() const
{
	return m_first;
}

//--------------------------------------------------------------------------------------