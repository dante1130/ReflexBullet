#ifndef ENEMY_H
#define ENEMY_H

#include <glm/vec3.hpp>
#include "BaseCharacter.h"
#include "EnemyAI.h"

class Enemy : public BaseCharacter
{
public:
	Enemy();

	void Update(GLfloat delta) override;
	void Shoot() override;
	void SetHealth(const GLfloat& given_health) override;

	// Getter
	Gun& GetGun();
	const glm::vec3& GetPosition() const;

	void SetPosition(const glm::vec3& position);

	static void SetPlayerPos(const glm::vec3& position);

private:
	/// Where the enemy is facing, static as all enemies will look at the player
	static glm::vec3 m_playerPos;

	glm::vec3 m_position;
	GLfloat m_moveSpeed;
	EnemyAI m_ai;
};

#endif