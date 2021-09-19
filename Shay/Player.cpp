#include "Player.h"

Player::Player()
	: m_healthDecay(start_health_decay), m_firingSpeed(start_firing_speed), m_skillPoints(0), m_bulletOffsetScale(0.5f)
{
	m_gun = Gun(Faction::PLAYER, start_bullet_speed, m_firingSpeed);
	m_health = start_health;

	m_camera.SetMoveSpeed(start_move_speed);
}

void Player::Update(GLfloat delta)
{
	m_gun.Update(delta);

	m_health -= m_healthDecay;
	if (m_health <= 0) m_health = 0;
}

void Player::Shoot()
{	
	Bullet newBullet(m_gun.GetFaction(), 
					 m_camera.GetPosition() + glm::normalize(m_camera.GetLook()) * m_bulletOffsetScale,
				     m_camera.GetLook() * m_gun.GetBulletVelocity(),
					 10);

	m_gun.Shoot(newBullet);
}

Camera& Player::GetCamera()
{
	return m_camera;
}

Gun& Player::GetGun()
{
	return m_gun;
}
