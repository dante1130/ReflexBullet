#include "Player.h"

Player::Player()
	: m_healthDecay(start_health_decay), m_firingSpeed(start_firing_speed), m_skillPoints(0), m_bulletOffsetScale(0.5f),
		m_bullet_speed(start_bullet_speed), m_move_speed(start_move_speed)
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
	if (m_health > start_health)
		m_health = start_health;
}

void Player::Shoot()
{	
	Bullet newBullet(m_gun.GetFaction(),
					 m_camera.GetPosition() + glm::normalize(m_camera.GetLook()) * m_bulletOffsetScale,
				     m_camera.GetLook() * m_gun.GetBulletVelocity(), 
					 10);

	m_gun.Shoot(newBullet);
}

const GLfloat Player::GetHealth()
{
	return m_health;
}

const GLfloat Player::GetStartHealth()
{
	return start_health;
}

void Player::SetHealth(const GLfloat& given_health)
{
	m_health = given_health;
}

Camera& Player::GetCamera()
{
	return m_camera;
}

Gun& Player::GetGun()
{
	return m_gun;
}

void Player::DecreaseFiringDelay(GLfloat added_firing_speed)
{
	if (m_gun.GetFiringDelay() > max_firing_speed && m_gun.GetFiringDelay() <= start_firing_speed)
	{
		m_firingSpeed -= added_firing_speed;
		m_gun.SetFiringDelay(m_firingSpeed);
	}
}

void Player::ResetFiringDelay()
{
	m_firingSpeed = start_firing_speed;
	m_gun.SetFiringDelay(m_firingSpeed);
}

void Player::AddBulletSpeed(GLfloat added_bullet_speed)
{
	if (m_gun.GetBulletVelocity() < max_bullet_speed && m_gun.GetBulletVelocity() >= start_bullet_speed)
	{
		m_bullet_speed += added_bullet_speed;
		m_gun.SetBulletVelocity(m_bullet_speed);
	}
}

void Player::ResetBulletSpeed()
{
	m_bullet_speed = start_bullet_speed;
	m_gun.SetBulletVelocity(m_bullet_speed);
}

void Player::AddMoveSpeed(GLfloat added_move_speed)
{
	if (m_camera.GetMoveSpeed() < max_move_speed && m_camera.GetMoveSpeed() >= start_move_speed)
	{
		m_move_speed += added_move_speed;
		m_camera.SetMoveSpeed(m_move_speed);
	}
}

void Player::ResetMoveSpeed()
{
	m_move_speed = start_move_speed;
	m_camera.SetMoveSpeed(m_move_speed);
}
