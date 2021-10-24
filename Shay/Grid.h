#ifndef GRID_H
#define GRID_H

/**
 * @class Grid.
 * @brief An enum class for all the possible grid states.
 */
enum class Grid
{
	FREE, 
	FULL, 
	HALF, 
	ENEMYTHERE,
	ENEMYGOING,
	PLAYERTHERE
};

#endif