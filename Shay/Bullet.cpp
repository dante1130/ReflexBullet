#include "Bullet.h"

Bullet::Bullet()
	: m_faction(), m_position(glm::vec3(0.0f)), m_velocity(glm::vec3(0.0f)), m_damage(0)
{
	m_bSphere.center = m_position;
	m_bSphere.radius = 0.25;
}

Bullet::Bullet(Faction faction, const glm::vec3& position, const glm::vec3& velocity, GLint damage)
	: m_faction(faction), m_position(position), m_velocity(velocity), m_damage(damage)
{
	m_bSphere.center = m_position;
	m_bSphere.radius = 0.25;
}

void Bullet::Update(GLfloat delta)
{
	m_position += m_velocity * delta;
	m_bSphere.center = m_position;
}

Faction Bullet::GetFaction() const
{
	return Faction();
}

const glm::vec3& Bullet::GetPosition() const
{
	return m_position;
}

const glm::vec3& Bullet::GetVelocity() const
{
	return m_velocity;
}

GLfloat Bullet::GetDamage() const
{
	return m_damage;
}

const BoundingSphere& Bullet::GetBoundingSphere() const
{
	return m_bSphere;
}

void Bullet::SetFaction(Faction faction)
{
	m_faction = faction;
}

void Bullet::SetPosition(const glm::vec3& position)
{
	m_position = position;
}

void Bullet::SetVelocity(const glm::vec3& velocity)
{
	m_velocity = velocity;
}

void Bullet::SetDamage(GLfloat damage)
{
	m_damage = damage;
}