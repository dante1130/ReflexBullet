#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Gun.h"
#include "../include/GL/glut.h"

class BaseCharacter
{
public:
	virtual void Update(GLfloat delta) = 0;
	virtual void Shoot() = 0;

protected:
	Gun m_gun;
	GLint m_health;
};

#endif