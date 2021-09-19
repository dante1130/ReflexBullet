//  AABBVector.cpp
//
//  Implementation file for AABBVector Class
//  Defines all the methods declared, but not defined, in AABBVector.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "AABBVector.h"

//--------------------------------------------------------------------------------------

AABBVector::AABBVector()
	: m_AABB() {}

//--------------------------------------------------------------------------------------

void AABBVector::Clear()
{
	m_AABB.clear();
}

void AABBVector::Push(const glm::vec3& max, const glm::vec3& min)
{
	BoundingBox newBBox;

	newBBox.max = max;
	newBBox.min = min;

	m_AABB.push_back(newBBox);
}

//--------------------------------------------------------------------------------------

const glm::vec3& AABBVector::GetMax(int index) const
{
	return m_AABB[index].max;
}

const glm::vec3& AABBVector::GetMin(int index) const
{
	return m_AABB[index].min;
}

//--------------------------------------------------------------------------------------

void AABBVector::SetData(int index, const glm::vec3& max, const glm::vec3& min)
{
	m_AABB[index].max = max;
	m_AABB[index].min = min;
}

//--------------------------------------------------------------------------------------

int AABBVector::Size() const
{
	return m_AABB.size();
}

//--------------------------------------------------------------------------------------