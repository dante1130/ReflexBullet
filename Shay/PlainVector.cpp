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

void PlainVector::Push(const GLint tempType, const glm::vec3& t1, const glm::vec3& t2, const glm::vec3& t3, const glm::vec3& t4)
{
	Plain newPlain;

	newPlain.m_type = tempType;
	newPlain.m_plainStart = t1;
	newPlain.m_plainEnd = t3;
	newPlain.q2 = t2;
	newPlain.q4 = t4;

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

const glm::vec3& PlainVector::GetQ2(int ptrCount) const
{
	return m_plains[ptrCount].q2;
}

const glm::vec3& PlainVector::GetQ4(int ptrCount) const
{
	return m_plains[ptrCount].q4;
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