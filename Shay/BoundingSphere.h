#ifndef BOUNDINGSPHERE_H
#define BOUNDINGSPHERE_H

#include "../include/GL/glut.h"
#include "../include/glm/vec3.hpp"


struct BoundingSphere
{
	/// The center of the sphere
	glm::vec3 center;
	/// The radius of the sphere
	GLfloat radius;
};

#endif