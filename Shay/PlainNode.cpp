//  PlainNode.cpp
//
//  Implementation file for PlainNode Class
//  Defines all the methods declared, but not defined, in PlainNode.h
//
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#include "PlainNode.h"

//----------------------------------------------------------------

PlainNode::PlainNode()
	: m_next(nullptr), m_type(0), m_plainStart(), m_plainEnd()
{}

PlainNode::PlainNode(const PlainNode& newNode)
{
	Copy(newNode);
}

PlainNode& PlainNode::operator=(const PlainNode& newNode)
{
	Copy(newNode);
	return *this;
}

PlainNode::~PlainNode()
{
	Clear();
}

void PlainNode::Copy(const PlainNode& newNode)
{
	m_type = newNode.m_type;
	m_plainStart = newNode.m_plainStart;
	m_plainEnd = newNode.m_plainEnd;

	if (newNode.m_next != nullptr)
	{
		m_next->Copy(*newNode.m_next);
	}
}

void PlainNode::Clear()
{
	if (m_next != nullptr)
	{
		m_next = nullptr;
	}
}

GLdouble PlainNode::GetType() const
{
	return m_type;
}

GLdouble PlainNode::GetXStart() const
{
	return m_plainStart.x;
}

GLdouble PlainNode::GetXEnd() const
{
	return m_plainEnd.x;
}

GLdouble PlainNode::GetYStart() const
{
	return m_plainStart.y;
}

GLdouble PlainNode::GetYEnd() const
{
	return m_plainEnd.y;
}

GLdouble PlainNode::GetZStart() const
{
	return m_plainStart.z;
}

GLdouble PlainNode::GetZEnd() const
{
	return m_plainEnd.z;
}

PlainNode* PlainNode::GetNext() const
{
	return m_next;
}

//----------------------------------------------------------------

void PlainNode::SetData(const int tempType,
						const GLdouble tempXs, const GLdouble tempXe,
						const GLdouble tempYs, const GLdouble tempYe,
						const GLdouble tempZs, const GLdouble tempZe)
{
	m_type = tempType;
	m_plainStart.x = tempXs;
	m_plainEnd.x = tempXe;
	m_plainStart.y = tempYs;
	m_plainEnd.y = tempYe;
	m_plainStart.z = tempZs;
	m_plainEnd.z = tempZe;
}

void PlainNode::SetNext(PlainNode* next)
{
	m_next = next;
}


//----------------------------------------------------------------