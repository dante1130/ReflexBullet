#ifndef GUN_H
#define GUN_H


#include <vector>
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
	 * @param bulletVelocity GLfloat
	 * @param firingDelay GLfloat
	 */
	Gun(GLfloat bulletVelocity, GLfloat firingDelay);

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

	/**
	 * @brief Removes all the bullets in the gun.
	 * @return void
	 */
	void RemoveAllBullets();

	/**
	 * @brief Gets the bullet at an index.
	 * @param index int
	 * @return const Bullet&
	 */
	const Bullet& BulletAt(int index) const;

	/**
	 * @brief Returns the bullet count that is currently in the scene.
	 * @return int
	 */
	int BulletCount() const;

	// Getter

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
	/// Vector containing the bullets
	std::vector<Bullet> m_bullets;
	
	/// The bullet velocity.
	GLfloat m_bulletVelocity;

	/// The firing delay.
	GLfloat m_firingDelay;

	/// The firing buffer.
	GLfloat m_firingBuffer;

	/// Boolean for if the firing delay is occuring.
	bool m_isFiring;
	
	//Audio audio;
};

#endif GUN_H