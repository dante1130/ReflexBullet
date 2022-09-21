#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <array>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "Grid.h"
#include "math.h"
#include <glm\geometric.hpp>
#include <GL/glut.h>

/**
 * @class EnemyAI.
 * @brief Behaviour for the enemy, uses a Grid system to specify which character is occupying that grid spot.
 */
class EnemyAI
{
public:
	/**
	 * @brief Default constructor.
	 */
	EnemyAI();

	/**
	 * @brief Changes the state of the EnemyAI to dead.
	 * @return void
	 */
	void Die();

	/**
	 * @brief Resets the Grid to the initial state.
	 * @return void
	 */
	static void ResetGrid();

	/**
	 * @brief Switches the grid to the boss grid.
	 * @return void
	 */
	static void SwitchBossGrid();

	/**
	 * @brief Updates the AI, to be called every game tick.
	 * @param currentPos const glm::vec3&
	 * @return void
	 */
	void AIUpdate(const glm::vec3& currentPos);

	/**
	 * @brief Displays the wireframe, used for debugging.
	 * @return void
	 */
	static void DisplayWireframe();

	/**
	 * @brief Displays the map for the AI.
	 * @return void
	 */
	static void DisplayMap();

	/**
	 * @brief Gets a random free spot from the grid.
	 * @return const glm::ivec2&
	 */
	static const glm::ivec2& GetRandFree();

	/**
	 * @brief Gets the boolean for if the enemy is moving.
	 * @return bool
	 */
	bool GetIsMoving() const;

	/**
	 * @brief Getter for the grid position of the destination.
	 * @return const glm::ivec2&
	 */
	const glm::ivec2& GetGridDest() const;

	/**
	 * @brief Getter for the grid position of the enemy.
	 * @return const glm::ivec2&
	 */
	const glm::ivec2& GetGridPos() const;

	/**
	 * @brief Getter for the previous grid position of the enemy.
	 * @return const glm::ivec2&
	 */
	const glm::ivec2& GetPrevGridPos() const;

	/**
	 * @brief Setter for the player position.
	 * @param position const glm::vec3&
	 * @return void
	 */
	static void SetPlayerPos(const glm::vec3& position);

	/**
	 * @brief Setter for the grid position of the enemy.
	 * @param position const glm::ivec2&
	 * @return void
	 */
	void SetGridPos(const glm::ivec2& position);

	/**
	 * @brief Returns a boolean if the player is in view of the enemy.
	 * @param lookAt const glm::vec3&
	 * @return bool
	 */
	bool isPlayerInView(const glm::vec3& lookAt);

private:
	// As it is a 2d array, it does store what is happening in that grid position (based on it's x/z location in the grid)
	// If the position is empty, then both should be FREE

	/// The grid.
	static std::array<std::array<Grid, 26>, 20> m_mainGrid;

	/// The player position.
	static glm::ivec2 m_playerPos;

	/// The previous player position.
	static glm::ivec2 m_prevPlayerPos;

	/// The enemy position in the grid.
	glm::ivec2 m_gridPos;

	/// The previous enemy position in the grid.
	glm::ivec2 m_prevGridPos;

	/// The position of the destination in the grid.
	glm::ivec2 m_gridDest;

	/// Boolean for if the enemy is moving.
	bool m_isMoving;

	/// Boolean for if it is the first move of the enemy.
	bool m_isFirstMove;

	/**
	 * @brief Returns a boolean if the enemy has reached the destination.
	 * @param currentPos const glm::vec3&
	 * @return bool
	 */
	bool isDestinationReached(const glm::vec3& currentPos);

	/**
	 * @brief Finds the next destination.
	 * @return void
	 */
	void FindNextDest();
};

#endif