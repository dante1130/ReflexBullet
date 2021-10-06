#ifndef BOSS_H
#define BOSS_H

#include "BaseCharacter.h"
#include "definesGW.h"
#include "LoadTexturesGameWorld.h"
#include "Player.h"

#include <math.h>

class Boss : public BaseCharacter
{
public:
	Boss();

	void Update(GLfloat delta) override;
	void Shoot() override;
	const GLfloat GetHealth() override;
	void SetHealth(const GLfloat& given_health) override;


	Gun& GetGun();
	const GLint& GetPhase();
	const glm::vec3& GetRotation();
	const GLfloat GetStartHealth();

	void SetPosition(glm::vec3 p);
	void SetRotation(GLfloat x, GLfloat y, GLfloat z);
	void SetRotation(const glm::vec3& r);
	void SetRotationY(GLfloat y);
	void SetPhase(GLint i);

	void TrackPlayer(Player& player);

	void AnimateRotate();
	void AnimateSpecial(GLint delta);
	//void AnimateTarget();

	//void CollisionDetection();
	//void EnableCollision

private:

	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	void SetLazerBeamSize(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

	glm::vec3 m_rotation;
	glm::vec3 m_position;

	glm::vec2 m_lazerbeam[2];

	GLfloat startHealth = 50;
	GLint phase;
};


#endif