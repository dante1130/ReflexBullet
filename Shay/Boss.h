#ifndef BOSS_H
#define BOSS_H

#include <math.h>
#include <glm/glm.hpp>

#include "BaseCharacter.h"
#include "LoadTexturesGameWorld.h"
#include "Player.h"
#include "BoundingSphere.h"


class Boss : public BaseCharacter
{
public:
	Boss(GLfloat x, GLfloat y, GLfloat z);

	void Update(GLfloat delta) override;
	void Shoot() override;
	const GLfloat GetHealth() override;
	void SetHealth(const GLfloat& given_health) override;


	Gun& GetGun();
	const GLint& GetPhase() const;
	const glm::vec3& GetRotation() const;
	const glm::vec3& GetPosition() const;
	const GLfloat GetStartHealth() const;

	void SetPosition(const glm::vec3& p);
	void SetRotation(const glm::vec3& r);
	void SetRotationY(GLfloat y);
	void SetPhase(GLint i);

	void TrackPlayer(Player& player);

	void AnimateRotate();
	void AnimateSpecial(GLint delta);
	bool LazerCollision(Player&  player);

	//void CollisionDetection();
	//void EnableCollision

private:

	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	void SetLazerBeamSize(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	void SetRotation(GLfloat x, GLfloat y, GLfloat z);

	glm::vec3 m_rotation;
	glm::vec3 m_position;

	//special
	glm::vec2 m_lazerbeam[2];
	float radius;


	GLfloat startHealth = 50;
	GLint phase;
};


#endif