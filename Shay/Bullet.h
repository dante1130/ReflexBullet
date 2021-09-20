#ifndef BULLET_H
#define BULLET_H

#include <glm/vec3.hpp>
#include "Faction.h"
#include "BoundingSphere.h"
#include <GL/glut.h>

/**
 * @class Bullet
 * @brief Represents a bullet.
 * @todo Give a better brief description.
 */
class Bullet
{
public:
	/**
	 * @brief Default constructor.
	 */
	Bullet();

	/**
	 * @brief Parameterized constructor.
	 */
	Bullet(Faction faction, const glm::vec3& position, const glm::vec3& velocity, GLint damage);

	/**
	 * @brief Updates the bullet with delta time.
	 * @param delta GLfloat
	 * @return void
	 */
	void Update(GLfloat delta);

	// Getters

	/**
	 * @brief Getter for faction.
	 * @return Faction
	 */
	Faction GetFaction() const;

	/**
	 * @brief Getter for position.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetPosition() const;

	/**
	 * @brief Getter for velocity.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetVelocity() const;

	/**
	 * @brief Getter for damage.
	 * @return GLfloat
	 */
	GLfloat GetDamage() const;

	const BoundingSphere& GetBoundingSphere() const;

	// Setters

	/**
	 * @brief Setter for faction.
	 * @param faction Faction
	 * @return void
	 */
	void SetFaction(Faction faction);

	/**
	 * @brief Setter for position.
	 * @param position const glm::vec3& 
	 * @return void
	 */
	void SetPosition(const glm::vec3& position);

	/**
	 * @brief Setter for velocity.
	 * @param velocity const glm::vec3&
	 * @return void
	 */
	void SetVelocity(const glm::vec3& velocity);

	/**
	 * @brief Setter for damage.
	 * @param damage GLfloat
	 * @return void
	 */
	void SetDamage(GLfloat damage);

private:
	/// The faction (PLAYER / ENEMY)
	Faction m_faction;
	/// The position of the bullet
	glm::vec3 m_position;
	/// The velocity of which the bullet is moving to
	glm::vec3 m_velocity;
	/// The damage the bullet can deal to health
	GLint m_damage;
	/// Bounding sphere for collision detection
	BoundingSphere m_bSphere;
	//Audio* m_audio;
};

#endif