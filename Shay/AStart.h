#ifndef ASTAR_H
#define ASTAR_H

#include <math.h>

struct node
{
	/// <summary>
	/// The x position
	/// </summary>
	int x;

	/// <summary>
	/// The y position
	/// </summary>
	int y;
};

/**
* @brief	Estimates distance between the current position and the goal using manhattan heuristic. I.e. cannot go diagonal
* 
* @param	movementCost	- The movementCost to move horizontally
* @param	pos				- The location of the position to start from
* @param	goal			- The location of the position of the goal
* 
* @return	The shortest estimated difference from the current position and goal
*/
float ManhattanHeuristic(float movementCost, node pos, node goal);

/**
* @brief	Estimates distance between the current position and the goal using diagonal heuristic. I.e. Can go diagonal
*
* @param	movementCostManhattan	- The movementCost to move horizontally
* @param	movementCostDiagonal	- The movementCost to move diagonally
* @param	pos						- The location of the position to start from
* @param	goal					- The location of the position of the goal
*
* @return	The shortest estimated difference from the current position and goal
*/
float DiagonalHeuristic(float movementCostManhattan, float movementCostDiagonal, node pos, node goal);

#endif