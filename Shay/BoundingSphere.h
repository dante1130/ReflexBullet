#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include <glm/vec3.hpp>
#include <GL/glut.h>

/**
 * @struct  BoundingSphere
 * @brief	BoundingSphere collision type, represented by a center and a radius.
 */
struct BoundingSphere
{
	/// The center of the sphere
	glm::vec3 center;
	/// The radius of the sphere
	GLfloat radius;

	/**
	 * @brief	Default constructor.
	 */
	BoundingSphere() : center(0), radius(0) {}

	/**
	 * @brief	Parameterized constructor.
	 * @param	center const glm::vec3&
	 * @param	radius const glm::vec3&
	 */
	BoundingSphere(const glm::vec3& center, GLfloat radius) : center(center), radius(radius) {}
};

#endif