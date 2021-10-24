#include "Player.h"

Player::Player()
	: m_prevPos(m_camera.GetPosition()), m_healthDecay(start_health_decay), 
	m_firingSpeed(start_firing_speed), m_skillPoints(0), 
	m_bulletOffsetScale(0.5f), m_bullet_speed(start_bullet_speed), 
	m_move_speed(start_move_speed), m_bulletShots(0), m_bulletHits(0)
{
	m_gun = Gun(Faction::PLAYER, start_bullet_speed, m_firingSpeed);
	m_health = start_health;
	m_lazer_hit = false;
	m_camera.SetMoveSpeed(start_move_speed);
	m_bBox = BoundingBox(glm::vec3(m_camera.GetPosition().x + 0.25, m_camera.GetPosition().y + 0.10, m_camera.GetPosition().z + 0.25),
						 glm::vec3(m_camera.GetPosition().x - 0.25, 0, m_camera.GetPosition().z - 0.25));
						 
}

void Player::Update(GLfloat delta)
{
	glm::vec3 change = m_camera.GetPosition() - m_prevPos;

	m_bBox.min += change;
	m_bBox.max += change;

	m_prevPos = m_camera.GetPosition();

	m_gun.Update(delta);

	m_health -= m_healthDecay;

	if (m_lazer_hit) m_health -= m_healthDecay * 5;

	if (m_health <= 0) 
		m_health = 0;
	else if (m_health > start_health)
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

void Player::SetLazerHit(const bool& hit)
{
	m_lazer_hit = hit;
}

Camera& Player::GetCamera()
{
	return m_camera;
}

GLfloat Player::GetHealthDecay()
{
	return m_healthDecay;
}

Gun& Player::GetGun()
{
	return m_gun;
}

int Player::GetSkillPoints()
{
	return m_skillPoints;
}

int Player::GetUpgradeOption(int option)
{
	if (option < 4) { return m_upgrade_options[option]; }
	else { return 0; }
	
}

const bool Player::GetLazerHit() const
{
	return m_lazer_hit;
}

GLfloat Player::GetAccuracy() const 
{
	GLfloat accuracy = (m_bulletShots == 0) ? 100.00f : ((GLfloat)m_bulletHits / m_bulletShots) * 100;

	return accuracy;
}

const BoundingBox& Player::GetBoundingBox() const
{
	return m_bBox;
}

void Player::DecreaseFiringDelay(GLfloat added_firing_speed)
{
	if (m_gun.GetFiringDelay() > max_firing_speed && m_gun.GetFiringDelay() <= start_firing_speed)
	{
		m_firingSpeed -= added_firing_speed;
		m_gun.SetFiringDelay(m_firingSpeed);
		m_upgrade_options[0]++;
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
		m_upgrade_options[1]++;
	}
}
void Player::DecreaseHealthDecay(GLfloat added_health_decay)
{
	if (m_healthDecay > max_health_decay && m_healthDecay <= start_health_decay)
	{
		m_healthDecay -= added_health_decay;
		m_upgrade_options[2]++;
	}
}

void Player::AddSkillPoints(int added_skill_point)
{
	m_skillPoints += added_skill_point;
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
		m_upgrade_options[3]++;
	}
}

void Player::IncrementBulletHits()
{
	++m_bulletHits;
}

void Player::IncrementBulletShots()
{
	++m_bulletShots;
}

void Player::ResetMoveSpeed()
{
	m_move_speed = start_move_speed;
	m_camera.SetMoveSpeed(m_move_speed);
}

void Player::ResetHealthDecay()
{
	m_healthDecay = start_health_decay;
}

void Player::ResetSkillPoints()
{
	m_skillPoints = 0;
}

void Player::ResetBullets()
{
	for (int i = 0; i < m_gun.BulletCount(); ++i)
		m_gun.RemoveBullet(i);

	m_bulletHits = 0;
	m_bulletShots = 0;
}

void Player::ResetUpgradeOptions()
{
	for (int i = 0; i < 4; ++i)
		m_upgrade_options[i] = 0;
}

void Player::SpendSkillPoint()
{
	m_skillPoints--;
}
