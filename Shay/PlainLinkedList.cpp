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


bool PlainLinkedList::AddToStart (const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
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
	newNode->SetData(tempType, tempStart, tempEnd);
	// set the address of the net node
	newNode->SetNext(m_first->GetNext());
	// reset the address of the first node
	m_first->SetNext(newNode);

	return true;
}

//--------------------------------------------------------------------------------------

GLint PlainLinkedList::GetType(int ptrCount) const
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

const glm::vec3& PlainLinkedList::GetStart(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetStart();	
}

//--------------------------------------------------------------------------------------

const glm::vec3& PlainLinkedList::GetEnd(int ptrCount) const
{
	PlainNode *ptr = (m_first);
	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}

	if (ptr->GetNext() != nullptr)
		return ptr->GetNext()->GetEnd();	
}


//--------------------------------------------------------------------------------------

void PlainLinkedList::SetData (const int ptrCount, const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
{
	PlainNode *ptr = (m_first);

	for (int count = 0; count < ptrCount; count++)
	{
		ptr = ptr->GetNext();
	}
	ptr->GetNext()->SetData(tempType, tempStart, tempEnd);
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