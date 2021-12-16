#include "AStart.h"

#define baseParent -1
#define baseCost 9999999999

//////////////////////////////////
//OPERATION FUNCTIONS/////////////
//////////////////////////////////
std::vector<std::vector<DistanceNode>> aStar::aStarSearch(std::vector<std::vector<int>> grid, const float movementCost[3], const float heuristicsCostScale, const int gridSize[2], const node start, const node goal) throw (AStarExceptions)
{
	//Init grid used to store path
	std::vector<std::vector<DistanceNode>> distanceGrid;

	//Init grid default values
	InitDefaultGrid(distanceGrid, gridSize);

	//Make sure nodes are available
	if (IsDestination(start, goal) == true) throw (ALREADY_AT_DESTINATION);

	if (ValidPosition(start, gridSize[0], gridSize[1]) == false) throw (START_OUT_OF_BOUNDS);
	if (ValidPosition(goal, gridSize[0], gridSize[1]) == false) throw (GOAL_OUT_OF_BOUNDS);
	
	if (CellNotBlocked(start, grid) == false) throw (START_BLOCKED);
	if (CellNotBlocked(goal, grid) == false) throw (GOAL_BLOCKED);





	return distanceGrid;
}

void aStar::InitDefaultGrid(std::vector<std::vector<DistanceNode>>& distanceGrid, const int gridSize[2])
{
	DistanceNode defaultDistanceNode;
	defaultDistanceNode.parentNode.x = baseParent;
	defaultDistanceNode.parentNode.y = baseParent;
	defaultDistanceNode.f = baseCost;
	defaultDistanceNode.g = baseCost;
	defaultDistanceNode.h = baseCost;

	for (int count = 0; count < gridSize[0]; count++)
	{
		for (int countTwo = 0; countTwo < gridSize[1]; countTwo++)
		{
			distanceGrid[count].push_back(defaultDistanceNode);
		}
	}

	return;
}


//////////////////////////////////
//HEURISTIC FUNCTIONS/////////////
//////////////////////////////////
float aStar::ManhattanHeuristic(const float movementCost, node pos, const node goal)
{
	return movementCost * (abs(pos.x - goal.x) + abs(pos.y - goal.y));
}


float aStar::DiagonalHeuristic(const float movementCostManhattan, const float movementCostDiagonal, node pos, const node goal)
{
	float dx = abs(pos.x - goal.x);
	float dy = abs(pos.y - goal.y);

	float min;
	if (dx < dy) { min = dx; }
	else { min = dy; }

	return movementCostManhattan * (dx + dy) + (movementCostDiagonal - 2 * movementCostManhattan) * min;
}


//////////////////////////////////
//UTILITY FUNCTIONS///////////////
//////////////////////////////////
bool aStar::IsDestination(const node pos, node goal)
{
	if (pos.x == goal.x && pos.y == goal.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool aStar::ValidPosition(node pos, int xSize, int ySize)
{
	if (pos.x > xSize || pos.x < 0) return false;
	if (pos.y > ySize || pos.y < 0) return false;

	return true;
}

bool aStar::CellNotBlocked(node pos, const std::vector<std::vector<int>> &grid)
{
	if (grid[pos.x][pos.y] == 0) return true;
	
	return false;
}