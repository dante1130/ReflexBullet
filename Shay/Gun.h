#ifndef GUN_H
#define GUN_H


#include <vector>
#include "Faction.h"
#include "Bullet.h"
#include <gl/glut.h>

/**
 * @class Gun
 * @brief Represents a gun to fire bullets and stores the individual bullet information.
 */
class Gun
{
public:
	/**
	 * @brief Default constructor.
	 */
	Gun();

	/**
	 * @brief Parameterized constructor.
	 * @param faction Faction
	 * @param bulletVelocity GLfloat
	 * @param firingDelay GLfloat
	 */
	Gun(Faction faction, GLfloat bulletVelocity, GLfloat firingDelay);

	/**
	 * @brief Updates the bullets in the gun.
	 * @param delta GLfloat
	 * @return void
	 */
	void Update(GLfloat delta);

	/**
	 * @brief Adds a bullet into the bullets vector, used for when gun is shot.
	 * @param bullet const Bullet&
	 * @return void
	 */
	void Shoot(const Bullet& bullet);

	/**
	 * @brief Removes a bullet from the bullets vector, used for when the bullet has collided.
	 * @param index int
	 * @return void
	 */
	void RemoveBullet(int index);

	void RemoveAllBullets();

	/**
	 * @brief Gets the bullet at an index.
	 * @param index int
	 * @return const Bullet&
	 */
	const Bullet& BulletAt(int index) const;

	int BulletCount() const;

	// Getter

	/**
	 * @brief Getter for faction.
	 * @return Faction
	 */
	Faction GetFaction() const;

	/**
	 * @brief Getter for bullet velocity.
	 * @return GLfloat
	 */
	GLfloat GetBulletVelocity() const;

	/**
	 * @brief Getter for firing delay.
	 * @return GLfloat
	 */
	GLfloat GetFiringDelay() const;

	/**
	 * @brief Getter for is firing.
	 * @return bool
	 */
	bool GetIsFiring() const;

	// Setter

	/**
	 * @brief Setter for faction.
	 * @param faction Faction
	 * @return void
	 */
	void SetFaction(Faction faction);

	/**
	 * @brief Setter for bullet velocity.
	 * @param bulletVelocity GLfloat
	 * @return void
	 */
	void SetBulletVelocity(GLfloat bulletVelocity);

	/**
	 * @brief Setter for firing delay.
	 * @param firingDelay GLfloat
	 * @return void
	 */
	void SetFiringDelay(GLfloat firingDelay);

private:
	Faction m_faction;
	std::vector<Bullet> m_bullets;
	GLfloat m_bulletVelocity;
	GLfloat m_firingDelay;
	GLfloat m_firingBuffer;
	bool m_isFiring;
	
	//Audio audio;
};

#endif GUN_H