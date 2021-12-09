#include "AStart.h"


float ManhattanHeuristic(float movementCost, node pos, node goal)
{
	return movementCost * (abs(pos.x - goal.x) + abs(pos.y - goal.y));
}

float DiagonalHeuristic(float movementCostManhattan, float movementCostDiagonal, node pos, node goal)
{
	float dx = abs(pos.x - goal.x);
	float dy = abs(pos.y - goal.y);

	float min;
	if (dx < dy) { min = dx; }
	else { min = dy; }

	return movementCostManhattan * (dx + dy) + (movementCostDiagonal - 2 * movementCostManhattan) * min;
}