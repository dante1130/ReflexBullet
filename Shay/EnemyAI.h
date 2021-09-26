#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <array>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "Grid.h"
#include <GL/glut.h>

class EnemyAI
{
public:
	EnemyAI();

	void AIUpdate(const glm::vec3& currentPos);

	static void DisplayWireframe();

	void SetGridPos(const glm::ivec2& position);

	const glm::ivec2& GetGridDest() const;

	bool isPlayerInView(const glm::vec3& lookAt);

private:
	// As it is a 2d array, it does store what is happening in that grid position (based on it's x/z location in the grid)
	// If the position is empty, then both should be FREE
	static std::array<std::array<Grid, 26>, 20> m_mainGrid;

	glm::ivec2 m_gridPos;
	glm::ivec2 m_gridDest;

	bool m_isMoving;

	void FindNextDest();
};

#endif