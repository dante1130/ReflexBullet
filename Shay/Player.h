#ifndef PLAYER_H
#define PLAYER_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include "BoundingBox.h"
#include "BaseCharacter.h"
#include "camera.h"

/**
 * @class Player
 * @brief Represents the player, extended from the BaseCharacter
 */
class Player : public BaseCharacter
{
public:
	/**
	 * @brief Default constructor.
	 */
	Player();

	/**
	 * @brief Updates the player, to be called every game tick.
	 * @param delta GLfloat
	 * @return void
	 */
	void Update(GLfloat delta) override;

	/**
	 * @brief Shoots a bullet.
	 * @return void
	 */
	void Shoot() override;

	/**
	 * @brief Getter for health.
	 * @return const GLfloat
	 */
	const GLfloat GetHealth() override;
	
	/**
	 * @brief Setter for health.
	 * @param given_health const GLfloat&
	 * @return void
	 */
	void SetHealth(const GLfloat& given_health) override;

	// Getter

	/**
	 * @brief Getter for camera.
	 * @return Camera&
	 */
	Camera& GetCamera();

	/**
	 * @brief Getter for Gun.
	 * @return Gun&
	 */
	Gun& GetGun();

	/**
	 * @brief Getter for start health.
	 * @return const GLfloat
	 */
	const GLfloat GetStartHealth();

	/**
	 * @brief Getter for skill points.
	 * @return int
	 */
	int GetSkillPoints();
	
	/**
	 * @brief Getter for upgrade options.
	 * @param option
	 * @return int
	 */
	int GetUpgradeOption(int option);
	
	/**
	 * @brief Getter for health decay.
	 * @return GLfloat
	 */
	GLfloat GetHealthDecay();
	
	/**
	 * @brief Getter for if the player is hit by the boss laser.
	 * @return const bool
	 */
	const bool GetLazerHit() const;

	/**
	 * @brief Getter for accuracy.
	 * @return GLfloat
	 */
	GLfloat GetAccuracy() const;
	
	/**
	 * @brief Getter for bounding box.
	 * @return const BoundingBox&
	 */
	const BoundingBox& GetBoundingBox() const;

	// Setters (for upgrade system)

	/**
	 * @brief Decrease firing delay by a specified amount.
	 * @param added_firing_speed GLfloat
	 * @return void
	 */
	void DecreaseFiringDelay(GLfloat added_firing_speed);

	/**
	 * @brief Adds the bullet speed by a specified amount.
	 * @param added_bullet_speed GLfloat
	 * @return void
	 */
	void AddBulletSpeed(GLfloat added_bullet_speed);

	/**
	 * @brief Adds the movement speed by a specified amount.
	 * @param added_move_speed GLfloat
	 * @return void
	 */
	void AddMoveSpeed(GLfloat added_move_speed);

	/**
	 * @brief Decreases the health decay by a specified amount.
	 * @param added_health_decay GLfloat
	 * @return void
	 */
	void DecreaseHealthDecay(GLfloat added_health_decay);

	/**
	 * @brief Adds skill points by a certain amount.
	 * @param added_skill_point int
	 * @return void
	 */
	void AddSkillPoints(int added_skill_point);
	
	/**
	 * @brief Setter for if the player is hit by the laser.
	 * @param hit const bool&
	 * @return void
	 */
	void SetLazerHit(const bool& hit);
	
	/**
	 * @brief Increments the number of bullet hits.
	 * @return void
	 */
	void IncrementBulletHits();

	/**
	 * @brief Increments the number of bullet shot.
	 * @return void
	 */
	void IncrementBulletShots();
	
	/**
	 * @brief Resets the firing delay.
	 * @return void
	 */
	void ResetFiringDelay();

	/**
	 * @brief Resets the bullet speed
	 * @return void
	 */
	void ResetBulletSpeed();

	/**
	 * @brief Resets the movement speed.
	 * @return void
	 */
	void ResetMoveSpeed();

	/**
	 * @brief Resets the skill points.
	 * @return void
	 */
	void ResetSkillPoints();

	/**
	 * @brief Resets the health decay.
	 * @return void
	 */
	void ResetHealthDecay();

	/**
	 * @brief Resets the bullets.
	 * @return void
	 */
	void ResetBullets();

	/**
	 * @brief Resets the upgrade options.
	 * @return void
	 */
	void ResetUpgradeOptions();

	/**
	 * @brief Spend a skill point, decrements the skill point by 1
	 * @return void
	 */
	void SpendSkillPoint();

private:
	/// Constant for player starting health.
	const GLfloat start_health = 100;

	/// Constant for player movement speed.
	const GLfloat start_move_speed = 0.08;

	/// Constant for player health decay.
	const GLfloat start_health_decay = 0.1;

	/// Constant for player firing speed.
	const GLfloat start_firing_speed = 1;

	/// Constant for player bullet speed.
	const GLfloat start_bullet_speed = 5;

	/// Constant for player max firing speed.
	const GLfloat max_firing_speed = 0.5;

	/// Constant for player max bullet speed.
	const GLfloat max_bullet_speed = 10;

	/// Constant for player max movement speed.
	const GLfloat max_move_speed = 0.12;

	/// Constant for player max health decay.
	const GLfloat max_health_decay = 0.05;

	/// The camera class object.
	Camera m_camera;

	/// The bounding box of the player for collision detection.
	BoundingBox m_bBox;

	/// The previous position of the player
	glm::vec3 m_prevPos;
	
	/// Player health decay.
	GLfloat m_healthDecay;

	/// Player firing speed.
	GLfloat m_firingSpeed;

	/// Player movement speed.
	GLfloat m_move_speed;

	/// Player bullet speed.
	GLfloat m_bullet_speed;

	/// Boolean for if the player is hit by the boss laser.
	bool m_lazer_hit;

	/// Amount of player skill points.
	int m_skillPoints;

	/// Shows how many points are invested into each option
	int m_upgrade_options[4] = { 0, 0, 0, 0 }; 

	/// Bullet offset scale, used for offsetting the position of where the bullet is created.
	glm::vec3 m_bulletOffsetScale;

	/// Number of bullet shot, used for calculating accuracy
	GLint m_bulletShots;

	/// Number of bullet hits, used for calculating accuracy
	GLint m_bulletHits;
};

#endif