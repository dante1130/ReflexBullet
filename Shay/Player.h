#ifndef PLAYER_H
#define PLAYER_H

#include <glm/vec3.hpp>
#include <glm\geometric.hpp>
#include "BaseCharacter.h"
#include "camera.h"

class Player : public BaseCharacter
{
public:
	Player();

	void Update(GLfloat delta) override;
	void Shoot() override;
	const GLint GetHealth() override;
	void SetHealth(const GLfloat& given_health) override;

	// Getter
	Camera& GetCamera();
	Gun& GetGun();
	const GLfloat GetStartHealth();

	// Setters (for upgrade system)
	void DecreaseFiringDelay(GLfloat added_firing_speed);
	void AddBulletSpeed(GLfloat added_bullet_speed);
	void AddMoveSpeed(GLfloat added_move_speed);
	

	void ResetFiringDelay();
	void ResetBulletSpeed();
	void ResetMoveSpeed();

private:
	const GLfloat start_health = 100;
	const GLfloat start_move_speed = 0.08;
	const GLfloat start_health_decay = 0.1;
	const GLfloat start_firing_speed = 1;
	const GLfloat start_bullet_speed = 5;

	const GLfloat max_firing_speed = 0.5;
	const GLfloat max_bullet_speed = 10;
	const GLfloat max_move_speed = 0.12;
	const GLfloat max_health_decay = 0.005;

	Camera m_camera;
	
	GLfloat m_healthDecay;
	GLfloat m_firingSpeed;
	GLfloat m_move_speed;
	GLfloat m_bullet_speed;
	int m_skillPoints;

	glm::vec3 m_bulletOffsetScale;

	// Audio audio
};

#endif