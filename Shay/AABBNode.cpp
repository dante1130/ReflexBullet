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
	SetData(newNode.GetMaxX(), newNode.GetMinX(),
			newNode.GetMaxY(), newNode.GetMinY(),
			newNode.GetMaxZ(), newNode.GetMinZ());

	m_next->SetData(newNode.GetNext()->GetMaxX(), newNode.GetNext()->GetMinX(),
					newNode.GetNext()->GetMaxY(), newNode.GetNext()->GetMinY(),
					newNode.GetNext()->GetMaxZ(), newNode.GetNext()->GetMinZ());
}	

void AABBNode::Clear()
{
	m_next = nullptr;
}

GLdouble AABBNode::GetMaxX() const
{
	return m_bBox.max.x;
}

GLdouble AABBNode::GetMinX() const
{
	return m_bBox.min.x;
}

GLdouble AABBNode::GetMaxY() const
{
	return m_bBox.max.y;
}

GLdouble AABBNode::GetMinY() const
{
	return m_bBox.min.y;
}

GLdouble AABBNode::GetMaxZ() const
{
	return m_bBox.max.z;
}

GLdouble AABBNode::GetMinZ() const
{
	return m_bBox.min.z;
}

AABBNode* AABBNode::GetNext() const
{
	return m_next;
}

//----------------------------------------------------------------

void AABBNode::SetData(const GLdouble maxX, const GLdouble minX,
					   const GLdouble maxY, const GLdouble minY,
				       const GLdouble maxZ, const GLdouble minZ)
{
	m_bBox.max.x = maxX;
	m_bBox.min.x = minX;
	m_bBox.max.y = maxY;
	m_bBox.min.y = minY;
	m_bBox.max.z = maxZ;
	m_bBox.min.z = minZ;
}

void AABBNode::SetNext(AABBNode* next)
{
	m_next = next;
}

//----------------------------------------------------------------
