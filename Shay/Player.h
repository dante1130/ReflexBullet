#ifndef PLAYER_H
#define PLAYER_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "BoundingBox.h"
#include "BaseCharacter.h"
#include "camera.h"

class Player : public BaseCharacter
{
public:
	Player();

	void Update(GLfloat delta) override;
	void Shoot() override;
	const GLfloat GetHealth() override;
	void SetHealth(const GLfloat& given_health) override;

	// Getter
	Camera& GetCamera();
	Gun& GetGun();
	const GLfloat GetStartHealth();
	int GetSkillPoints();
	int GetUpgradeOption(int option);
	GLfloat GetHealthDecay();
	const bool GetLazerHit() const;
	GLfloat GetAccuracy() const;
	const BoundingBox& GetBoundingBox() const;

	// Setters (for upgrade system)
	void DecreaseFiringDelay(GLfloat added_firing_speed);
	void AddBulletSpeed(GLfloat added_bullet_speed);
	void AddMoveSpeed(GLfloat added_move_speed);
	void DecreaseHealthDecay(GLfloat added_health_decay);
	void AddSkillPoints(int added_skill_point);
	void SetLazerHit(const bool& hit);
	
	void IncrementBulletHits();
	void IncrementBulletShots();
	
	void ResetFiringDelay();
	void ResetBulletSpeed();
	void ResetMoveSpeed();
	void ResetSkillPoints();
	void ResetHealthDecay();
	void ResetBullets();
	void ResetUpgradeOptions();

	void SpendSkillPoint();

private:
	const GLfloat start_health = 100;
	const GLfloat start_move_speed = 0.08;
	const GLfloat start_health_decay = 0.1;
	const GLfloat start_firing_speed = 1;
	const GLfloat start_bullet_speed = 5;

	const GLfloat max_firing_speed = 0.5;
	const GLfloat max_bullet_speed = 10;
	const GLfloat max_move_speed = 0.12;
	const GLfloat max_health_decay = 0.05;

	Camera m_camera;

	BoundingBox m_bBox;

	glm::vec3 m_prevPos;
	
	GLfloat m_healthDecay;
	GLfloat m_firingSpeed;
	GLfloat m_move_speed;
	GLfloat m_bullet_speed;
	bool m_lazer_hit;
	int m_skillPoints;

	int m_upgrade_options[4] = { 0, 0, 0, 0 }; //Shows how many points are invested into each option

	glm::vec3 m_bulletOffsetScale;

	GLint m_bulletShots;
	GLint m_bulletHits;
};

#endif