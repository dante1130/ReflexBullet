#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Gun.h"
#include <GL/glut.h>

/**
 * @class	BaseCharacter
 * @brief	An interface for the characters of the game.
 */
class BaseCharacter
{
public:
	/**
	 * @brief	Updates the character, to be called every game tick.
	 * @param	delta GLfloat
	 * @return	void
	 */
	virtual void Update(GLfloat delta) = 0;

	/**
	 * @brief	Shoots a bullet.
	 * @return	void
	 */
	virtual void Shoot() = 0;

	/**
	 * @brief	Getter for health.
	 * @return	const GLfloat
	 */
	virtual const GLfloat GetHealth() { return m_health; }

	/**
	 * @brief	Setter for health.
	 * @param	given_health const GLfloat&
	 * @return	void
	 */
	virtual void SetHealth(const GLfloat& given_health) { m_health = given_health; }

protected:
	/// Gun object.
	Gun m_gun;

	/// Health.
	GLfloat m_health;
};

#endif