#include "Boss.h"


Boss::Boss(GLfloat x, GLfloat y, GLfloat z)
{
	m_gun = Gun(Faction::ENEMY, 5, 1);
	m_health = startHealth;
	radius = 20;
	SetPosition(x, y, z);
	SetRotation(0, 0, 0);
	SetLazerBeamSize(0, -1.5, 0, -2.5);
	SetPhase(1);
}

void Boss::Update(GLfloat delta)
{
	totalTime += delta;
	is_Firing = false;
	m_gun.Update(delta);
	if(m_gun.GetIsFiring())
		is_Firing = true;
	PhaseChange();
	PhaseApply(delta);

	if (m_health <= 0)
		m_gun.RemoveAllBullets();
}

void Boss::Shoot()
{
	glm::vec3 sum = player_Pos - m_position;
	Bullet newbullet(m_gun.GetFaction(), 
					 m_position + (glm::normalize(sum) * glm::vec3(2.5)), 
					 glm::normalize(sum) * m_gun.GetBulletVelocity(), 
					 15);

	m_gun.Shoot(newbullet);
}

const GLfloat Boss::GetHealth()
{
	return m_health;
}

Gun& Boss::GetGun()
{
	return m_gun;
}

const GLfloat& Boss::GetStartHealth() const
{
	return startHealth;
}

const bool Boss::GetIsFiring() const
{
	return is_Firing;
}

const bool Boss::GetIsLaserFiring() const
{
	if ((GetPhase() == 3) && (m_rotation.z == 0))
		return true;
	else
		return false;
}

void Boss::SetHealth(const GLfloat& given_health)
{
	m_health = given_health;
}

void Boss::SetPhase(const GLint& i)
{
	phase = i;
}

void Boss::SetRotation(GLfloat x, GLfloat y, GLfloat z)
{
	m_rotation.x = x;
	m_rotation.y = y;
	m_rotation.z = z;
}

void Boss::SetRotation(const glm::vec3& r)
{
	m_rotation = r;
}

void Boss::SetRotationY(GLfloat y)
{
	m_rotation.y = y;
}

void Boss::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void Boss::SetLazerBeamSize(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	m_lazerbeam[0].x = x1;
	m_lazerbeam[0].y = y1;
	m_lazerbeam[1].x = x2;
	m_lazerbeam[1].y = y2;
}

void Boss::SetPosition(const glm::vec3& p)
{
	m_position = p;
}

void Boss::SetPlayerPosition(const glm::vec3& player)
{
	player_Pos = player;
}

const GLint& Boss::GetPhase() const
{
	return phase;
}
const glm::vec3& Boss::GetRotation() const
{
	return m_rotation;
}
const glm::vec3& Boss::GetPosition() const
{
	return m_position;
}

void Boss::TrackPlayer()
{

	GLfloat hyp = std::sqrt(std::pow(player_Pos.x - m_position.x, 2) + std::pow(player_Pos.z - m_position.z, 2));
	GLfloat arccos = (player_Pos.x - m_position.x) / hyp;

	desiredRotation.y = (std::acos(arccos) * (180 / M_PI));

	GLfloat arctan = hyp / (m_position.y - player_Pos.y);

	desiredRotation.z = (std::atan(arctan) * (180 / M_PI));

	if (player_Pos.z - m_position.z > 0)
		desiredRotation.y = -desiredRotation.y;

	if (std::abs(desiredRotation.y - previousDesiredYRotation) > 180)
		m_rotation.y = (m_rotation.y + desiredRotation.y) + desiredRotation.y;

	m_rotation = glm::mix(m_rotation, desiredRotation, 0.02);

	previousDesiredYRotation = desiredRotation.y;

}

void Boss::PhaseChange()
{
	if (totalTime - startPhaseTime >= 15)
	{
		int temp = (GLint)totalTime % 3 + 1;
		if (temp != GetPhase()) {
			SetPhase(temp);
			if (GetPhase() == 1)
				GetGun().SetFiringDelay(1);
			else if (GetPhase() == 2)
				GetGun().SetFiringDelay(0.3);
			else if (GetPhase() == 3) {

			}
			std::cout << "Phase changed to: " << GetPhase() << std::endl;
			startPhaseTime = totalTime;
		}
	}

}

void Boss::PhaseApply(GLfloat delta)
{
	if (totalTime - startPhaseTime > 1)
	{
		if (GetPhase() == 1)
			Shoot();
		else if ((GetPhase() == 2) && (((GLint)totalTime % 2) >= 1))
			Shoot();
	}

	if (GetPhase() == 3)
	{

		if (GetRotation().z != 0)
		{
			SetRotation(glm::mix(GetRotation(), glm::vec3(0.0, 0.0, 0.0), 0.04));
			if ((GetRotation().z > -0.05) && (GetRotation().z < 0.05))
				SetRotation(glm::vec3(0.0, 0.0, 0.0));
			return;
		}
		SetRotationY(GetRotation().y + 15 * delta);
		AnimateSpecial(delta);
	}
}

void Boss::Animate()
{
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_rotation.x, 1, 0, 0);
	glRotatef(m_rotation.y, 0, 1, 0);
	glRotatef(m_rotation.z, 0, 0, 1);

	if (GetPhase() == 3) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(B_LAZER));
		glBegin(GL_QUADS);
		glTexCoord2f(0, 1);
		glVertex2f(m_lazerbeam[1].x, m_lazerbeam[1].y);
		glTexCoord2f(1, 1);
		glVertex2f(m_lazerbeam[0].x, m_lazerbeam[1].y);
		glTexCoord2f(1, 0);
		glVertex2f(m_lazerbeam[0].x, m_lazerbeam[0].y);
		glTexCoord2f(0, 0);
		glVertex2f(m_lazerbeam[1].x, m_lazerbeam[0].y);
		glEnd();
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
}

void Boss::AnimateSpecial(GLfloat delta)
{

	if ((totalTime - startPhaseTime > 13) && (m_lazerbeam[1].x - m_lazerbeam[0].x > 0))
	{
		m_lazerbeam[0].x += 15.0 * delta;
		m_lazerbeam[1].x -= 15.0 * delta;
	}else if ((m_rotation.z == 0) && (m_lazerbeam[1].x - m_lazerbeam[0].x < radius * 2))
	{
		m_lazerbeam[0].x -= 15.0 * delta;
		m_lazerbeam[1].x += 15.0 * delta;
	}
	
}
bool Boss::LazerCollision()
{
	GLfloat ac = sqrt(pow(player_Pos.x - m_position.x + radius, 2) + pow(player_Pos.z - m_position.z, 2)); // length of side ac (distance from top to player)
	GLfloat bc = sqrt(pow(player_Pos.x - m_position.x, 2) + pow(player_Pos.z - m_position.z, 2)); //length of side bc (distance from boss to player)
	GLfloat playerAngle = 180 - acos((radius * radius + bc * bc - ac * ac) / (2 * radius * bc)) * 180.0 / M_PI; //angle between abc
	if (player_Pos.z - m_position.z > 0)
		playerAngle = (180 - playerAngle) + 180;
	GLfloat sum = m_rotation.y - playerAngle; //difference between the angles
	GLfloat diff = 90 - atan(2 * bc / 0.5) * 180.0 / M_PI; //how much range between being hit by the laser
	
	if ((sum < diff && sum > -diff) || (sum + 180 < diff && sum + 180 > -diff))
		return true;
	else
		return false;
}