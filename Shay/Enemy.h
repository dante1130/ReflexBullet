#ifndef ENEMY_H
#define ENEMY_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "BaseCharacter.h"
#include "BoundingBox.h"
#include "EnemyAI.h"

class Enemy : public BaseCharacter
{
public:
	Enemy();

	Enemy(glm::vec3 position);

	void Die();

	void Update(GLfloat delta) override;
	void Shoot() override;
	void SetHealth(const GLfloat& given_health) override;

	// Getter
	bool GetIsAlive() const;

	Gun& GetGun();

	const BoundingBox& GetBBox() const;

	const glm::vec3& GetPosition() const;
	
	const glm::vec3& GetPlayerPos() const;

	void SetBBox(const BoundingBox& bBox);

	void SetPosition(const glm::vec3& position);

	static void SetPlayerPos(const glm::vec3& position);

private:
	/// Where the enemies is facing, static as all enemies will look at the player
	static glm::vec3 m_playerPos;

	bool m_isAlive;

	BoundingBox m_bBox;
	glm::vec3 m_position;
	GLfloat m_moveSpeed;
	EnemyAI m_ai;
};

#endif