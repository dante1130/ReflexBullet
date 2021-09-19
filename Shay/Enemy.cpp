#include "Enemy.h"

Enemy::Enemy()
	: m_position(0.0f), m_look(0.0f)
{
	m_gun = Gun(Faction::ENEMY, 5, 1);
	m_health = 10;
}

void Enemy::Update(GLfloat delta)
{
	m_gun.Update(delta);
}

void Enemy::Shoot()
{
	Bullet newBullet(m_gun.GetFaction(),
					 m_position,
					 m_look * m_gun.GetBulletVelocity(),
					 10);

	m_gun.Shoot(newBullet);
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

const glm::vec3& Enemy::GetLook() const
{
	return m_look;
}