//  collision.cpp
//
//  Implementation file for Collsion Class
//  Defines all the methods declared, but not defined, in collsion.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "collision.h"
#include "../include/glm/geometric.hpp"


Collision::Collision()
	: m_list(), m_worldSizeX(0), m_worldSizeZ(0) {}

void Collision::Clear()
{
	for (int i = 0; i < 4; ++i)
		m_list[i].Clear();
}

void Collision::Push(const glm::vec3& max, const glm::vec3& min)
{
	GetQuadrant(max, min);
}

AABBVector& Collision::GetQuadrant(int index)
{
	return m_list[index];
}

void Collision::SetWorldX(const double& tempX)
{
	m_worldSizeX = tempX;
}

void Collision::SetWorldZ(const double& tempZ)
{
	m_worldSizeZ = tempZ;
}

//--------------------------------------------------------------------------------------
//  Creates a linked list for each quadrant and then copies the bounding box data from
//  AABB (array) to the required linked list.
//  I initially just created AABB, then decided to place the bounding box info into a list.
//  I kept the array has it allows for the data to be copied into the list in any reuired 
//  order.
//--------------------------------------------------------------------------------------
void Collision::GetQuadrant(const glm::vec3& max, const glm::vec3& min)
{
	// 1st quadrant
	if (((min.x <= m_worldSizeX / 2.0) || (max.x <= m_worldSizeX / 2.0)) &&
		((min.z <= m_worldSizeZ / 2.0) || (max.z <= m_worldSizeZ / 2.0)))
	{
		m_list[0].Push(max, min);
	}
	// 2nd quadrant
	if (((min.x <= m_worldSizeX / 2.0) || (max.x <= m_worldSizeX / 2.0)) &&
		((min.z >= m_worldSizeZ / 2.0) || (max.z >= m_worldSizeZ / 2.0)))
	{
		m_list[1].Push(max, min);
	}
	// 3rd quadrant
	if (((min.x >= m_worldSizeX / 2.0) || (max.x >= m_worldSizeX / 2.0)) &&
		((min.z <= m_worldSizeZ / 2.0) || (max.z <= m_worldSizeZ / 2.0)))
	{
		m_list[2].Push(max, min);
	}
	// 4th quadrant
	if (((min.x >= m_worldSizeX / 2.0) || (max.x >= m_worldSizeX / 2.0)) &&
		((min.z >= m_worldSizeZ / 2.0) || (max.z >= m_worldSizeZ / 2.0)))
	{
		m_list[3].Push(max, min);
	}
}

bool Collision::Collide(const glm::vec3& point, const BoundingSphere& bSphere)
{
	return glm::length(bSphere.center - point) < bSphere.radius;
}

bool Collision::Collide(const BoundingBox& bBox, const BoundingSphere& bSphere)
{
	GLfloat distance;
	glm::vec3 point;

	point = glm::max(glm::min(bSphere.center, bBox.max), bBox.min);

	distance = glm::length(point - bSphere.center);

	return distance < bSphere.radius;
}

bool Collision::Collide(const BoundingBox& bBox1, const BoundingBox& bBox2)
{
	return (bBox1.min.x <= bBox2.max.x && bBox1.max.x >= bBox2.min.x) &&
		   (bBox1.min.y <= bBox2.max.y && bBox1.max.y >= bBox2.min.y) &&
		   (bBox1.min.z <= bBox2.max.z && bBox1.max.z >= bBox2.min.z);
}

bool Collision::Collide(const BoundingSphere& bSphere1, const BoundingSphere& bSphere2)
{
	GLfloat radiusDistance = bSphere1.radius + bSphere2.radius;
	GLfloat centerDistance = glm::length(bSphere2.center - bSphere1.center);

	return centerDistance < radiusDistance;
}

bool Collision::Collide(const BoundingSphere& bSphere)
{
	bool isColliding = false;
	// check 1st quadrant (1st linked list)
	if (bSphere.center.x <= m_worldSizeX / 2.0 && bSphere.center.z <= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(0, bSphere);
	}
	// check 2nd quadrant (2nd linked list)
	if (bSphere.center.x <= m_worldSizeX / 2.0 && bSphere.center.z >= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(1, bSphere);
	}
	// check 3rd quadrant (3rd linked list)
	if (bSphere.center.x >= m_worldSizeX / 2.0 && bSphere.center.z <= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(2, bSphere);
	}
	// check 4th quadrant (4th linked list)
	if (bSphere.center.x >= m_worldSizeX / 2.0 && bSphere.center.z >= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(3, bSphere);
	}
	return isColliding;
}

//--------------------------------------------------------------------------------------
//  Returns TRUE if a collsion occurs.
//  The parameters passed to this function are the co-ordinates of the camera.
//  At present this function uses if statements to split the world into quadrants
//  this is to be improved (for the project) so that the quadrants (or levels) are
//  stored in a list or tree data structure.
//--------------------------------------------------------------------------------------

bool Collision::Collide(const glm::dvec3& end)
{
	bool isColliding = false;
	// check 1st quadrant (1st linked list)
	if (end.x <= m_worldSizeX / 2.0 && end.z <= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(0, end);
	}
	// check 2nd quadrant (2nd linked list)
	if (end.x <= m_worldSizeX / 2.0 && end.z >= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(1, end);
	}
	// check 3rd quadrant (3rd linked list)
	if (end.x >= m_worldSizeX / 2.0 && end.z <= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(2, end);
	}
	// check 4th quadrant (4th linked list)
	if (end.x >= m_worldSizeX / 2.0 && end.z >= m_worldSizeZ / 2.0)
	{
		isColliding = CheckCollision(3, end);
	}
	return isColliding;
}

bool Collision::CheckCollision(int index, const BoundingSphere& bSphere)
{
	bool isColliding = false;

	float distance;
	glm::vec3 point;

	for (int count = 0; count < m_list[index].Size(); count++)
	{
		glm::vec3 max = m_list[index].GetMax(count);
		glm::vec3 min = m_list[index].GetMin(count);

		point = glm::max(glm::min(bSphere.center, max), min);

		distance = glm::length(point - bSphere.center);

		if (distance < bSphere.radius)
		{
			isColliding = true;
			break;
		}
	}
	return isColliding;
}

//--------------------------------------------------------------------------------------
// Called from above function to check if collsion occurred.
//--------------------------------------------------------------------------------------
bool Collision::CheckCollision(int index, const glm::dvec3& end)
{
	bool isColliding = false;

	for (int count = 0; count < m_list[index].Size(); count++)
	{
		glm::vec3 max = m_list[index].GetMax(count);
		glm::vec3 min = m_list[index].GetMin(count);

		if ((end.x < max.x && end.x > min.x) && 
			(end.z < max.z && end.z > min.z))
		{
			isColliding = true;
			break;
		}
	}
	return isColliding;
}



//--------------------------------------------------------------------------------------