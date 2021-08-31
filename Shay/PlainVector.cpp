//  PlainVector.cpp
//
//  Implementation file for PlainVector Class
//  Defines all the methods declared, but not defined, in PlainVector.h
//
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#include "PlainVector.h"

PlainVector::PlainVector() 
	: m_plains() {}

void PlainVector::Push (const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
{
	Plain newPlain;
	
	newPlain.m_type = tempType;
	newPlain.m_plainStart = tempStart;
	newPlain.m_plainEnd = tempEnd;

	m_plains.push_back(newPlain);
}

//--------------------------------------------------------------------------------------

GLint PlainVector::GetType(int index) const
{
	return m_plains[index].m_type;
}

//--------------------------------------------------------------------------------------

const glm::vec3& PlainVector::GetStart(int index) const
{
	return m_plains[index].m_plainStart;
}

//--------------------------------------------------------------------------------------

const glm::vec3& PlainVector::GetEnd(int index) const
{
	return m_plains[index].m_plainEnd;
}

//--------------------------------------------------------------------------------------

void PlainVector::SetData(int index, const GLint type, const glm::vec3& start, const glm::vec3& end)
{
	m_plains[index].m_type = type;
	m_plains[index].m_plainStart = start;
	m_plains[index].m_plainEnd = end;
}

//--------------------------------------------------------------------------------------

int PlainVector::Size() const
{
	return m_plains.size();
}

//--------------------------------------------------------------------------------------