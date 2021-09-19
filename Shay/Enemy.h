#ifndef ENEMY_H
#define ENEMY_H

#include <glm/vec3.hpp>
#include "BaseCharacter.h"
#include "EnemyAI.h"

class Enemy : public BaseCharacter
{
public:
	Enemy();

	void Update(GLfloat delta) override;
	void Shoot() override;

	// Getter
	Gun& GetGun();
	const glm::vec3& GetPosition() const;
	const glm::vec3& GetLook() const;

private:
	glm::vec3 m_position;
	glm::vec3 m_look;
	EnemyAI m_ai;
};

#endif