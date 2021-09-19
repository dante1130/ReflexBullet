#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H


#include "../include/glm/vec3.hpp"
#include "../include/GL/glut.h"

struct BoundingSphere
{
	/// The center of the sphere
	glm::vec3 center;
	/// The radius of the sphere
	GLfloat radius;
};

#endif