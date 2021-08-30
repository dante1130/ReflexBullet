//  Plain.h
//  Header file for the Plain struct
//  Stores details for each plain. To be used in a Plain vector.

//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAIN_H
#define PLAIN_H

//--------------------------------------------------------------------------------------

#include <glm/vec3.hpp>
#include <gl/glut.h>

/**
 * @struct Plain
 * @brief A struct that stores information about a plain.
 */
struct Plain
{
	/// Stores type of plain: (0: flat plane) (1: incline from z to y) (2: incline from x to y)
	GLint m_type;
	/// stores start co-ordinates of plane on x, y and z axis
	glm::vec3 m_plainStart;
	/// stores end co-ordinates of plane on x, y and z axis
	glm::vec3 m_plainEnd;
};

#endif

//--------------------------------------------------------------------------------------