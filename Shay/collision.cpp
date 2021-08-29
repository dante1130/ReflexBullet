//  collision.cpp
//
//  Implementation file for Collsion Class
//  Defines all the methods declared, but not defined, in collsion.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "collision.h"

Collision::Collision()
	: m_AABB(), m_list(), m_listSize(), m_worldSizeX(0.0), m_worldSizeZ(0.0)
{
	for (int& i : m_listSize)
	{
		i = 0;
	}
}

void Collision::SetAABBMax(const int& tempIndex, const glm::vec3 &tempMax)
{
	m_AABB.SetMax(tempIndex, tempMax);
}

void Collision::SetAABBMin(const int& tempIndex, const glm::vec3 &tempMin)
{
	m_AABB.SetMin(tempIndex, tempMin);
}

void Collision::SetWorldX(const double& tempX)
{
	m_worldSizeX = tempX;
}

void Collision::SetWorldZ(const double& tempZ)
{
	m_worldSizeZ = tempZ;
}

void Collision::SetNoBoundingBoxes(const int& tempSize)
{
	m_AABB.SetNoBoundingBoxes(tempSize);
}

const glm::vec3& Collision::GetAABBMax(const int& tempIndex) const
{
	return m_AABB.GetMax(tempIndex);
}

const glm::vec3& Collision::GetAABBMin(const int& tempIndex) const
{
	return m_AABB.GetMin(tempIndex);
}


int Collision::GetNoBoundingBoxes() const
{
	return m_AABB.GetNoBoundingBoxes();
}

//--------------------------------------------------------------------------------------
//  Creates a linked list for each quadrant and then copies the bounding box data from
//  AABB (array) to the required linked list.
//  I initially just created AABB, then decided to place the bounding box info into a list.
//  I kept the array has it allows for the data to be copied into the list in any reuired 
//  order.
//--------------------------------------------------------------------------------------
void Collision::CreateLinkedList()

{
	int tempNoBoxes = GetNoBoundingBoxes();
	// initilize list size for each quadrant
	m_listSize[0] = 0;
	m_listSize[1] = 0;
	m_listSize[2] = 0;
	m_listSize[3] = 0;

	for (int count = 0; count < tempNoBoxes; count++)
	{
		glm::vec3 max = GetAABBMax(count);
		glm::vec3 min = GetAABBMin(count);

		// 1st quadrant
		if (((min.x <= m_worldSizeX / 2.0) || (max.x <= m_worldSizeX / 2.0)) && 
			((min.z <= m_worldSizeZ / 2.0) || (max.z <= m_worldSizeZ / 2.0)))
		{
			// increment list size
			m_listSize[0]++;
			// add bb data to list
			m_list[0].AddToStart(max, min);
		}
		// 2nd quadrant
		if (((min.x <= m_worldSizeX / 2.0) || (max.x <= m_worldSizeX / 2.0)) &&
			((min.z >= m_worldSizeZ / 2.0) || (max.z >= m_worldSizeZ / 2.0)))
		{
			// increment list size
			m_listSize[1]++;
			// add bb data to list
			m_list[1].AddToStart(max, min);
		}
		// 3rd quadrant
		if (((min.x >= m_worldSizeX / 2.0) || (max.x >= m_worldSizeX / 2.0)) && 
			((min.z <= m_worldSizeZ / 2.0) || (max.z <= m_worldSizeZ / 2.0)))
		{
			// increment list size
			m_listSize[2]++;
			// add bb data to list
			m_list[2].AddToStart(max, min);
		}
		// 4th quadrant
		if (((min.x >= m_worldSizeX / 2.0) || (max.x >= m_worldSizeX / 2.0)) && 
			((min.z >= m_worldSizeZ / 2.0) || (max.z >= m_worldSizeZ / 2.0)))
		{
			// increment list size
			m_listSize[3]++;
			// add bb data to list
			m_list[3].AddToStart(max, min);
		}
	}
	// Call AABB constructor the delete array and clear memory
	// (the array AABB is not required once the lists have been created)
	m_AABB.~AABB();
}

//--------------------------------------------------------------------------------------
//  Returns TRUE if a collsion occurs.
//  The parameters passed to this function are the co-ordinates of the camera.
//  At present this function uses if statements to split the world into quadrants
//  this is to be improved (for the project) so that the quadrants (or levels) are
//  stored in a list or tree data structure.
//--------------------------------------------------------------------------------------

bool Collision::Collide(GLdouble endX, GLdouble endY, GLdouble endZ)
{
	bool Collision = false;
	// check 1st quadrant (1st linked list)
	if (endX <= m_worldSizeX / 2.0 && endZ <= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(0, endX, endY, endZ);
	}
	// check 2nd quadrant (2nd linked list)
	if (endX <= m_worldSizeX / 2.0 && endZ >= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(1, endX, endY, endZ);
	}
	// check 3rd quadrant (3rd linked list)
	if (endX >= m_worldSizeX / 2.0 && endZ <= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(2, endX, endY, endZ);
	}
	// check 4th quadrant (4th linked list)
	if (endX >= m_worldSizeX / 2.0 && endZ >= m_worldSizeZ / 2.0)
	{
		Collision = CheckCollision(3, endX, endY, endZ);
	}
	return Collision;
}

//--------------------------------------------------------------------------------------
// Called from above function to check if collsion occurred.
//--------------------------------------------------------------------------------------
bool Collision::CheckCollision(int index, GLdouble endX, GLdouble endY, GLdouble endZ)
{
	bool CollisionFound = false;

	for (int count = 0; count < m_listSize[index]; count++)
	{
		glm::vec3 max = m_list[index].GetMax(count);
		glm::vec3 min = m_list[index].GetMin(count);

		if ((endX < max.x && endX > min.x) && (endZ < max.z && endZ > min.z))
		{
			CollisionFound = true;
		}
	}
	return CollisionFound;
}



//--------------------------------------------------------------------------------------