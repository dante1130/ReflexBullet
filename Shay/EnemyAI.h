#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <array>
#include "../include/glm/vec2.hpp"
#include "Grid.h"
#include "../include/GL/glut.h"

class EnemyAI
{
public:
	EnemyAI();

	void AIUpdate();

private:
	// As it is a 2d array, it does store what is happening in that grid position (based on it's x/z location in the grid)
	// If the position is empty, then both should be FREE
	static std::array<std::array<Grid, 5>, 5> m_mainGrid;

	glm::vec2 m_gridPos;

	bool m_isMoving;
};

#endif