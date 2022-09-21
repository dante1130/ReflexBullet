#ifndef BOSS_H
#define BOSS_H
#define _USE_MATH_DEFINES

#include <glm/glm.hpp>
#include <cmath>

#include "BaseCharacter.h"
#include "LoadTexturesGameWorld.h"


class Boss : public BaseCharacter
{
public:
	/**
	 * @brief Constructor, takes in a position
	 * @param x GLfloat
	 * @param y GLfloat
	 * @param z GLfloat
	 */
	Boss(GLfloat x, GLfloat y, GLfloat z);

	/**
	 * @brief Updates the bosses actions and phases.
	 * @param delta GLfloat
	 * @return void
	 */
	void Update(GLfloat delta) override;
	/**
	 * @brief Creates new bullet and calls m_gun.Shoot().
	 * @return void
	 */
	void Shoot() override;
	/**
	 * @brief Returns the bosses health value.
	 * @return const GLfloat
	 */
	const GLfloat GetHealth() override;
	/**
	 * @brief Sets the bosses health value equal to given_health.
	 * @param given_health const GLfloat&
	 * @return void
	 */
	void SetHealth(const GLfloat& given_health) override;



	/**
	 * @brief Returns gun object m_gun.
	 * @return Gun&
	 */
	Gun& GetGun();
	/**
	 * @brief Returns the phase number of boss.
	 * @return const GLint&
	 */
	const GLint& GetPhase() const; 
	/**
	 * @brief Returns the rotation vector of boss.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetRotation() const;
	/**
	 * @brief Returns the position vector of boss.
	 * @return const glm::vec3&
	 */
	const glm::vec3& GetPosition() const; 
	/**
	 * @brief Returns the starting health of boss.
	 * @return const GLfloat&
	 */
	const GLfloat& GetStartHealth() const; //chnaged
	/**
	 * @brief Returns boolean depending if boss is firing bullet.
	 * @return const bool
	 */
	const bool GetIsFiring() const;
	/**
	 * @brief Returns boolean depending if boss is firing laser.
	 * @return const bool
	 */
	const bool GetIsLaserFiring() const;



	/**
	 * @brief Sets position of boss given a vector.
	 * @param p const glm::vec3&
	 * @return void
	 */
	void SetPosition(const glm::vec3& p);
	/**
	 * @brief Sets rotation of boss given a vector.
	 * @param r const glm::vec3&
	 * @return void
	 */
	void SetRotation(const glm::vec3& r);
	/**
	 * @brief Sets phase of boss given a GLint.
	 * @param i const GLint&
	 * @return void
	 */
	void SetPhase(const GLint& i);

	void SetPlayerPosition(const glm::vec3& player);



	/**
	 * @brief Uses the players location to calculate 
	 * rotation to always be facing player.
	 * @param player Player&
	 * @return void
	 */
	void TrackPlayer();
	/**
	 * @brief Applies rotation and translation based 
	 * on m_rotation and m_position. Also draws 
	 * laser-beam during phase three.
	 * @return void
	 */
	void Animate();
	/**
	 * @brief Detects whether player has collided with
	 * laser beam and returns as a boolean
	 * @param player Player&
	 * @return bool
	 */
	bool LazerCollision();


private:

	/**
	 * @brief Sets players position based on three 
	 * GLfloat variables.
	 * @param x GLfloat
	 * @param y GLfloat
	 * @param z GLfloat
	 * @return void
	 */
	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	/**
	 * @brief Sets laser-beams size based on four
	 * GLfloat variables.
	 * @param x1 GLfloat
	 * @param y1 GLfloat
	 * @param x2 GLfloat
	 * @param y2 GLfloat
	 * @return void
	 */
	void SetLazerBeamSize(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	/**
	 * @brief Sets players rotation based on three
	 * GLfloat variables.
	 * @param x GLfloat
	 * @param y GLfloat
	 * @param z GLfloat
	 * @return void
	 */
	void SetRotation(GLfloat x, GLfloat y, GLfloat z);
	/**
	 * @brief Sets players y rotation based on
	 * GLfloat parameter variable.
	 * @param y GLfloat
	 * @return void
	 */
	void SetRotationY(GLfloat y);



	/**
	 * @brief Changes the phase of boss every
	 * 15 seconds
	 * @return void
	 */
	void PhaseChange();
	/**
	 * @brief Applies effects of phase onto
	 * boss
	 * @param delta GLfloat
	 * @return void
	 */
	void PhaseApply(GLfloat delta);
	/**
	 * @brief Calculates laser-beams length and 
	 * animates accordingly
	 * @param delta GLfloat
	 * @return void
	 */
	void AnimateSpecial(GLfloat delta);

	//main boss properties
	glm::vec3 m_rotation; //bosses rotation
	glm::vec3 m_position; //bosses position
	glm::vec3 player_Pos; //players position
	bool is_Firing = false;

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