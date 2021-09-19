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
};

#endif