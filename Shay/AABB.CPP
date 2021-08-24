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

void AABB::SetMaxX(const int& tempIndex, const GLdouble& tempX)
{
	m_bBox[tempIndex].max.x = tempX;
}

void AABB::SetMinX(const int& tempIndex, const GLdouble& tempX)
{
	m_bBox[tempIndex].min.x = tempX;
}

void AABB::SetMaxY(const int& tempIndex, const GLdouble& tempY)
{
	m_bBox[tempIndex].max.y = tempY;
}

void AABB::SetMinY(const int& tempIndex, const GLdouble& tempY)
{
	m_bBox[tempIndex].min.y = tempY;
}

void AABB::SetMaxZ(const int& tempIndex, const GLdouble& tempZ) 
{ 
	m_bBox[tempIndex].max.z = tempZ; 
}

void AABB::SetMinZ(const int& tempIndex, const GLdouble& tempZ) 
{ 
	m_bBox[tempIndex].min.z = tempZ; 
}

void AABB::SetNoBoundingBoxes(const int& tempSize)
{
	m_bBox.resize(tempSize);
}

GLdouble AABB::GetMaxX(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].max.x; 
}

GLdouble AABB::GetMinX(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].min.x; 
}

GLdouble AABB::GetMaxY(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].max.y; 
}

GLdouble AABB::GetMinY(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].min.y; 
}

GLdouble AABB::GetMaxZ(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].max.z; 
}

GLdouble AABB::GetMinZ(const int& tempIndex) const
{ 
	return m_bBox[tempIndex].min.z; 
}

int AABB::GetNoBoundingBoxes() const
{ 
	return m_bBox.size(); 
}