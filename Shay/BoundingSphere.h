#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include <glm/vec3.hpp>
#include <GL/glut.h>

struct BoundingSphere
{
	/// The center of the sphere
	glm::vec3 center;
	/// The radius of the sphere
	GLfloat radius;

	BoundingSphere() : center(0), radius(0) {}

	BoundingSphere(const glm::vec3& center, GLfloat radius) : center(center), radius(radius) {}
};

#endif