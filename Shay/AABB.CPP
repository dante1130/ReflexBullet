//  AABB.cpp
//
//  Implementation file for AABB Class
//  Defines all the methods declared, but not defined, in AABB.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABB.h"

AABB::AABB() 
	: m_bBox()
{}

void AABB::SetMax(const int& tempIndex, const glm::vec3& tempMax)
{
	m_bBox[tempIndex].max = tempMax;
}

void AABB::SetMin(const int& tempIndex, const glm::vec3& tempMin)
{
	m_bBox[tempIndex].min = tempMin;
}

void AABB::SetNoBoundingBoxes(const int& tempSize)
{
	m_bBox.resize(tempSize);
}

const glm::vec3& AABB::GetMax(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].max; 
}

const glm::vec3& AABB::GetMin(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].min; 
}

int AABB::GetNoBoundingBoxes() const
{ 
	return m_bBox.size(); 
}