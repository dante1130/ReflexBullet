#include "Gun.h"

Gun::Gun()
	: m_faction(), m_bullets(), m_bulletVelocity(0.0f), m_firingDelay(0.0f), m_firingBuffer(0.0f), m_isFiring(false)
{}

Gun::Gun(Faction faction, GLfloat bulletVelocity, GLfloat firingDelay)
	: m_faction(faction), m_bullets(), m_bulletVelocity(bulletVelocity), m_firingDelay(firingDelay), m_firingBuffer(0.0f), m_isFiring(false)
{}

void Gun::Update(GLfloat delta)
{
	for (Bullet& bullet : m_bullets)
		bullet.Update(delta);

	if (m_isFiring)
	{
		m_firingBuffer += 0.025f;

		if (m_firingBuffer >= m_firingDelay) 
		{
			m_isFiring = false;
			m_firingBuffer = 0.0f;
		}
	}
}

void Gun::Shoot(const Bullet& bullet)
{
	//if (!m_isFiring)
	{
		m_isFiring = true;
		m_bullets.push_back(bullet);
	}
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
