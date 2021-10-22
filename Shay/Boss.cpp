#include "Boss.h"

glm::vec3 player_Pos, desiredRot;
GLfloat hyp, arccos, arctan, prevDesireY, prevDelta, m_gradient = 0;

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
	m_gun.Update(delta);
}

void Boss::Shoot()
{
	glm::vec3 sum = player_Pos - m_position;
	Bullet newbullet(m_gun.GetFaction(), m_position + glm::normalize(sum), glm::normalize(sum) * m_gun.GetBulletVelocity(), 10);
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

const GLfloat Boss::GetStartHealth() const
{
	return startHealth;
}

void Boss::SetHealth(const GLfloat& given_health)
{
	m_health = given_health;
}

void Boss::SetPhase(GLint i)
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

void Boss::TrackPlayer(Player& player)
{
	player_Pos = player.GetCamera().GetPosition();
	hyp = sqrt(pow(player_Pos.x - m_position.x, 2) + pow(player_Pos.z - m_position.z, 2));
	arccos = (player_Pos.x - m_position.x) / hyp;

	desiredRot.y = (acos(arccos) * (180 / PI));

	arctan = hyp / (m_position.y - player_Pos.y);

	desiredRot.z = (atan(arctan) * (180 / PI));

	if (player_Pos.z - m_position.z > 0)
		desiredRot.y = -desiredRot.y;

	if (std::abs(desiredRot.y - prevDesireY) > 180)
		m_rotation.y = (m_rotation.y + desiredRot.y) + desiredRot.y;

	m_rotation = glm::mix(m_rotation, desiredRot, 0.02);

	prevDesireY = desiredRot.y;

}

void Boss::AnimateRotate()
{
	glRotatef(m_rotation.x, 1, 0, 0);
	glRotatef(m_rotation.y, 0, 1, 0);
	glRotatef(m_rotation.z, 0, 0, 1);
}

void Boss::AnimateSpecial(GLint delta)
{
	GLfloat time = (delta - prevDelta) / 1000;
	if ((delta > 13000) && (m_lazerbeam[0].x - m_lazerbeam[1].x < 0))
	{
		m_lazerbeam[0].x += 15 * time;
		m_lazerbeam[1].x -= 15 * time;
	}else if ((delta > 1100) && (m_lazerbeam[0].x - m_lazerbeam[1].x >= -(radius * 2)))
	{
		m_lazerbeam[0].x -= 15 * time;
		m_lazerbeam[1].x += 15 * time;
	}

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

	prevDelta = delta;
}
bool Boss::LazerCollision(Player& player)
{
	player_Pos = player.GetCamera().GetPosition(); //stores the players position
	GLfloat ac = sqrt(pow(player_Pos.x - m_position.x + radius, 2) + pow(player_Pos.z - m_position.z, 2)); // length of side ac (distance from top to player)
	GLfloat bc = sqrt(pow(player_Pos.x - m_position.x, 2) + pow(player_Pos.z - m_position.z, 2)); //length of side bc (distance from boss to player)
	GLfloat playerAngle = 180 - acos((radius * radius + bc * bc - ac * ac) / (2 * radius * bc)) * 180.0 / PI; //angle between abc
	if (player_Pos.z - m_position.z > 0)
		playerAngle = (180 - playerAngle) + 180;
	GLfloat sum = m_rotation.y - playerAngle; //difference between the angles
	GLfloat diff = 90 - atan(2 * bc / 0.5) * 180.0 / PI; //how much range between being hit by the laser
	
	if ((sum < diff && sum > -diff) || (sum + 180 < diff && sum + 180 > -diff))
		return true;
	else
		return false;
}