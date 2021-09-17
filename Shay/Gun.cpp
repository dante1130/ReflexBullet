#include "Gun.h"

Gun::Gun()
	: m_faction(), m_bullets(), m_bulletVelocity(0), m_firingDelay(0)
{}

Gun::Gun(Faction faction, GLfloat bulletVelocity, GLfloat firingDelay)
	: m_faction(faction), m_bullets(), m_bulletVelocity(bulletVelocity), m_firingDelay(firingDelay)
{}

void Gun::Update(GLfloat delta)
{
	for (Bullet& bullet : m_bullets)
		bullet.Update(delta);
}

void Gun::AddBullet(const Bullet& bullet)
{
	m_bullets.push_back(bullet);
}

void Gun::RemoveBullet(int index)
{
	m_bullets.erase(m_bullets.begin() + index);
}

const Bullet& Gun::BulletAt(int index) const
{
	return m_bullets[index];
}

int Gun::BulletCount() const
{
	return m_bullets.size();
}

Faction Gun::GetFaction() const
{
	return m_faction;
}

GLfloat Gun::GetBulletVelocity() const
{
	return m_bulletVelocity;
}

GLfloat Gun::GetFiringDelay() const
{
	return m_firingDelay;
}

void Gun::SetFaction(Faction faction)
{
	m_faction = faction;
}

void Gun::SetBulletVelocity(GLfloat bulletVelocity)
{
	m_bulletVelocity = bulletVelocity;
}

void Gun::SetFiringDelay(GLfloat firingDelay)
{
	m_firingDelay = firingDelay;
}
