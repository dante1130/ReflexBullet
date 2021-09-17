#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <vector>
#include "../include/GL/glut.h"
#include "Grid.h"

namespace EnemyAI
{
	// As it is a 2d array, it does store what is happening in that grid position (based on it's x/z location in the grid)
	// If the position is empty, then both should be FREE
	static Grid[][] mainGrid;

	vec2 gridPos;

	bool isMoving;

	void AIUpdate();
}



#endif