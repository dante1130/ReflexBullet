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

GLint PlainVector::GetType(int ptrCount) const
{
	return m_plains[ptrCount].m_type;
}

//--------------------------------------------------------------------------------------

const glm::vec3& PlainVector::GetStart(int ptrCount) const
{
	return m_plains[ptrCount].m_plainStart;
}

//--------------------------------------------------------------------------------------

const glm::vec3& PlainVector::GetEnd(int ptrCount) const
{
	return m_plains[ptrCount].m_plainEnd;
}

//--------------------------------------------------------------------------------------

void PlainVector::SetData(const int ptrCount, const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
{
	m_plains[ptrCount].m_type = tempType;
	m_plains[ptrCount].m_plainStart = tempStart;
	m_plains[ptrCount].m_plainEnd = tempEnd;
}

//--------------------------------------------------------------------------------------

int PlainVector::Size() const
{
	return m_plains.size();
}

//--------------------------------------------------------------------------------------