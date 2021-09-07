//  collision.cpp
//
//  Implementation file for Collsion Class
//  Defines all the methods declared, but not defined, in collsion.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "collision.h"

Collision::Collision()
	: m_list(), m_worldSizeX(0), m_worldSizeZ(0) {}

void Collision::Push(const glm::vec3& max, const glm::vec3& min)
{
	GetQuadrant(max, min);
	//m_list[GetQuadrant(max, min)].Push(max, min);
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

//--------------------------------------------------------------------------------------
//  Returns TRUE if a collsion occurs.
//  The parameters passed to this function are the co-ordinates of the camera.
//  At present this function uses if statements to split the world into quadrants
//  this is to be improved (for the project) so that the quadrants (or levels) are
//  stored in a list or tree data structure.
//--------------------------------------------------------------------------------------

bool Collision::Collide(const glm::dvec3& end)
{
	bool Collision = false;
	// check 1st quadrant (1st linked list)
	if (end.x <= m_worldSizeX / 2.0 && end.z <= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(0, end);
	}
	// check 2nd quadrant (2nd linked list)
	if (end.x <= m_worldSizeX / 2.0 && end.z >= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(1, end);
	}
	// check 3rd quadrant (3rd linked list)
	if (end.x >= m_worldSizeX / 2.0 && end.z <= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(2, end);
	}
	// check 4th quadrant (4th linked list)
	if (end.x >= m_worldSizeX / 2.0 && end.z >= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(3, end);
	}
	return Collision;
}

//--------------------------------------------------------------------------------------
// Called from above function to check if collsion occurred.
//--------------------------------------------------------------------------------------
bool Collision::CheckCollision(int index, const glm::dvec3& end)
{
	bool CollisionFound = false;

	for (int count = 0; count < m_list[index].Size(); count++)
	{
		glm::vec3 max = m_list[index].GetMax(count);
		glm::vec3 min = m_list[index].GetMin(count);

		if ((end.x < max.x && end.x > min.x) && (end.z < max.z && end.z > min.z))
		{
			CollisionFound = true;
		}
	}
	return CollisionFound;
}



//--------------------------------------------------------------------------------------