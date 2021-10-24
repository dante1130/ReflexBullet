#ifndef ENEMY_H
#define ENEMY_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "BaseCharacter.h"
#include "BoundingBox.h"
#include "EnemyAI.h"

/**
 * @class Enemy
 * @brief Represents an enemy in the game world, extends from the BaseCharacter interface
 */
class Enemy : public BaseCharacter
{
public:
	/**
	 * @brief Default constructor.
	 */
	Enemy();

	/**
	 * @brief Parameterized constructor.
	 * @param position glm::vec3
	 */
	Enemy(glm::vec3 position);

	/**
	 * @brief Have the enemy enter into the dead state.
	 * @return void
	 */
	void Die();

	/**
	 * @brief Updates by delta, to be called every frame.
	 * @param delta GLfloat
	 * @return void
	 */
	void Update(GLfloat delta) override;

	/**
	 * @brief Shoots a bullet.
	 * @return void
	 */
	void Shoot() override;

	/**
	 * @brief Setter for health.
	 * @param given_health const GLfloat&
	 * @return void
	 */
	void SetHealth(const GLfloat& given_health) override;

	/**
	 * @brief Getter for if the enemy is alive.
	 * @return bool
	 */
	bool GetIsAlive() const;

	/**
	 * @brief Getter for gun.
	 * @return Gun&
	 */
	Gun& GetGun();

	/**
	 * @brief Getter for bounding box.
	 * @return const BoundingBox&
	 */
	const BoundingBox& GetBBox() const;

	/**
	 * @brief Getter for position.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetPosition() const;
	
	/**
	 * @brief Getter for player position.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetPlayerPos() const;

	/**
	 * @brief Setter for bounding box.
	 * @param bBox const BoundingBox&
	 * @return void
	 */
	void SetBBox(const BoundingBox& bBox);

	/**
	 * @brief Setter for position.
	 * @param position const glm::vec3&
	 * @return void
	 */
	void SetPosition(const glm::vec3& position);

	/**
	 * @brief Setter for player position.
	 * @param position const glm::vec3&
	 * @return void
	 */
	static void SetPlayerPos(const glm::vec3& position);

private:
	/// Player position, static as all enemies will look at the player.
	static glm::vec3 m_playerPos;

	/// Boolean for if the enemy is alive.
	bool m_isAlive;

	/// Bounding box for the enemy for collision detection.
	BoundingBox m_bBox;

	/// Position of the enemy.
	glm::vec3 m_position;

	/// Movement speed of the enemy.
	GLfloat m_moveSpeed;

	/// The enemy AI.
	EnemyAI m_ai;
};

#endif