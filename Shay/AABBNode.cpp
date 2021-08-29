//  AABBNode.cpp
//
//  Implementation file for AABBNode Class
//  Defines all the methods declared, but not defined, in AABBNode.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABBNode.h"

//----------------------------------------------------------------

AABBNode::AABBNode()
	: m_bBox(), m_next(nullptr) {}

AABBNode::~AABBNode()
{
	Clear();
}

AABBNode::AABBNode(const AABBNode& newNode)
{
	Copy(newNode);
}

AABBNode& AABBNode::operator=(const AABBNode& newNode)
{
	Copy(newNode);
	return *this;
}

void AABBNode::Copy(const AABBNode& newNode)
{
	m_bBox = newNode.m_bBox;

	if (newNode.m_next != nullptr)
	{
		m_next->Copy(*newNode.m_next);
	}
}	

void AABBNode::Clear()
{
	if (m_next != nullptr)
	{
		m_next = nullptr;
	}
}

const glm::vec3& AABBNode::GetMax() const
{
	return m_bBox.max;
}

const glm::vec3& AABBNode::GetMin() const
{
	return m_bBox.min;
}

AABBNode* AABBNode::GetNext() const
{
	return m_next;
}

//----------------------------------------------------------------

void AABBNode::SetData(const glm::vec3& max, const glm::vec3& min)
{
	m_bBox.max = max;
	m_bBox.min = min;
}

void AABBNode::SetNext(AABBNode* next)
{
	m_next = next;
}

//----------------------------------------------------------------
