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
	void SetPhase(GLint i);

	void TrackPlayer(Player& player);
	void Animate();
	bool LazerCollision(Player&  player);


private:

	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	void SetLazerBeamSize(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	void SetRotation(GLfloat x, GLfloat y, GLfloat z);
	void SetRotationY(GLfloat y);

	void PhaseChange();
	void PhaseApply(GLfloat delta);
	void AnimateSpecial(GLfloat delta);

	//main boss properties
	glm::vec3 m_rotation; //bosses rotation
	glm::vec3 m_position; //bosses position
	glm::vec3 player_Pos; //players position

	//special attack variables
	glm::vec2 m_lazerbeam[2]; //lazerbeams min and max for size
	glm::vec3 desiredRotation; //desired rotation for tracking player
	GLfloat previousDesiredYRotation = 0; //stores desired rotation for y direction a previous runthough
	GLfloat radius; //radius of lazer beam

	//boss specific properties
	GLfloat startHealth = 50; //starting health of boss
	GLint phase; //phase number of boss

	//time based variables
	GLfloat totalTime, startPhaseTime = 0; 
};


#endif