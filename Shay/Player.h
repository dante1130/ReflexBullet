#ifndef PLAYER_H
#define PLAYER_H

#include <glm/vec3.hpp>
#include "BaseCharacter.h"
#include "Camera.h"

class Player : public BaseCharacter
{
public:
	Player();

	void Update(GLfloat delta) override;
	void Shoot() override;

	// Getter
	Camera& GetCamera();
	Gun& GetGun();

private:
	const GLfloat start_health = 100;
	const GLfloat start_move_speed = 0.08;
	const GLfloat start_health_decay = 0.01;
	const GLfloat start_firing_speed = 1;
	const GLfloat start_bullet_speed = 5;

	Camera m_camera;
	
	GLfloat m_healthDecay;
	GLfloat m_firingSpeed;
	glm::vec3 bulletOffset = glm::vec3(-0.15, -0.2, 0.0);
	int m_skillPoints;

	// Audio audio
};

#endif