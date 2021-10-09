#include "Boss.h"

glm::vec3 player_Pos, desiredRot;
GLfloat hyp, arccos, arctan, prevDesireY, prevDelta = 0;
GLfloat tempX, tempZ, maxX, maxZ, m_gradient;

Boss::Boss()
{
	m_gun = Gun(Faction::ENEMY, 5, 1);
	m_health = startHealth;
	radius = 10;
	SetPosition(0, 0, 0);
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
	Bullet newbullet(m_gun.GetFaction(), m_position + glm::normalize(sum), glm::normalize(sum) * m_gun.GetBulletVelocity(), 1);
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

const GLfloat Boss::GetStartHealth()
{
	return startHealth;
}
void Boss::SetBoundSphere(const BoundingSphere& bs)
{
	b_Sphere = bs;
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

const GLint& Boss::GetPhase()
{
	return phase;
}
const glm::vec3& Boss::GetRotation()
{
	return m_rotation;
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

	m_rotation = mix(m_rotation, desiredRot, 0.02);

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
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(HEALTH));
	glColor3f(1.0, 0.824, 0.0);
	glBegin(GL_QUADS);
		glVertex2f(m_lazerbeam[1].x, m_lazerbeam[1].y);
		glVertex2f(m_lazerbeam[0].x, m_lazerbeam[1].y);
		glVertex2f(m_lazerbeam[0].x, m_lazerbeam[0].y);
		glVertex2f(m_lazerbeam[1].x, m_lazerbeam[0].y);
	glEnd();

	prevDelta = delta;
}
bool Boss::LazerCollision(Player& player)
{
	player_Pos = player.GetCamera().GetPosition(); //stores the players position
	m_gradient = tan((m_rotation.y - 90) * (PI / 180)); //calculate the gradient of lazerbeam
	GLfloat player_grad = (player_Pos.x - m_position.x) / (player_Pos.z - m_position.z); //calculate players gradient

	//if gradients are super big or small, set them as fixed values
	/*
	if (m_gradient > 999)
		m_gradient = 999;
	if (m_gradient < 0.01)
		m_gradient = 0.01;
	if (player_grad > 999)
		player_grad = 999;
	if (player_grad < 0.01)
		player_grad = 0.01;
	*/

	//difference between gradients
	GLfloat sum = player_grad - m_gradient;

	//calculates the x and z cordinates which are the out of bounds for the gradient (end of lazerbeam)
	maxX = radius * sin(m_rotation.y * (PI / 180));
	if ((m_rotation.y > 90) && (m_rotation.y <= 270))
		maxX = maxX * -1;
	maxZ = radius * cos(m_rotation.y * (PI / 180));
	if (m_rotation.y > 180)
		maxZ = maxZ * -1;

	std::cout << "Player: " << player_grad << "   Bar: " << m_gradient;

	//if player goes past length of lazer, return false (out of range)
	/*
	if ((player_Pos.x > maxX) || (player_Pos.z > maxZ) || (player_Pos.x < -maxX) || (player_Pos.z < -maxZ))
		return false;
	*/

	//if the gradients are the same with 0.01+- (with relation to gradient size) then detect collision
	if ((sum > (-0.01 * m_gradient)) && (sum < (0.01 * m_gradient))) 
		return true;
	else
		return false;
	
}