#include "Enemy.h"
#include <iostream>
#include <glm\geometric.hpp>

glm::vec3 Enemy::m_playerPos;

Enemy::Enemy()
	: m_position(0.0f), m_moveSpeed(0.10f)
{
	m_gun = Gun(Faction::ENEMY, 5, 1);
	m_health = 10;
}

void Enemy::Update(GLfloat delta)
{
	m_ai.AIUpdate(m_position);

	glm::vec2 direction = m_ai.GetGridDest() - m_ai.GetPrevGridPos();

	m_position.x += (direction.x) * delta;
	m_position.z += (direction.y) * delta;

	m_gun.Update(delta);
}

void Enemy::Shoot()
{
	glm::vec3 lookAt = m_playerPos - m_position;

	if (m_ai.isPlayerInView(lookAt))
	{
		Bullet newBullet(m_gun.GetFaction(),
						 m_position,
						 glm::normalize(lookAt) * m_gun.GetBulletVelocity(),
						 10);

		m_gun.Shoot(newBullet);
	}
}

// Getter
Gun& Enemy::GetGun()
{
	return m_gun;
}

const glm::vec3& Enemy::GetPosition() const
{
	return m_position;
}

void Enemy::SetPosition(const glm::vec3& position)
{
	m_position = position;
}

void Enemy::SetPlayerPos(const glm::vec3& position)
{
	m_playerPos = position;
	EnemyAI::SetPlayerPos(position);
}

void Enemy::SetHealth(const GLfloat& given_health)
{
	m_health = given_health;
}