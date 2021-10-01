#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Gun.h"
#include "../include/GL/glut.h"

class BaseCharacter
{
public:
	virtual void Update(GLfloat delta) = 0;
	virtual void Shoot() = 0;
	virtual const GLint GetHealth() { return m_health; }
	virtual void SetHealth(const GLfloat& given_health) { m_health = given_health; }

protected:
	Gun m_gun;
	GLfloat m_health;
};

#endif