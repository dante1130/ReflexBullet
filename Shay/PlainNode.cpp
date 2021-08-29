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

GLint PlainNode::GetType() const
{
	return m_type;
}

const glm::vec3& PlainNode::GetStart() const
{
	return m_plainStart;
}

const glm::vec3& PlainNode::GetEnd() const
{
	return m_plainEnd;
}

PlainNode* PlainNode::GetNext() const
{
	return m_next;
}

//----------------------------------------------------------------

void PlainNode::SetData(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
{
	m_type = tempType;
	m_plainStart = tempStart;
	m_plainEnd = tempEnd;
}

void PlainNode::SetNext(PlainNode* next)
{
	m_next = next;
}


//----------------------------------------------------------------