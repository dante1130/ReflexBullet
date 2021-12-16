#ifndef ASTARINTERFACE_H
#define ASTARINTERFACE_H

#include "AStart.h"

#include <vector>

class AStar
{
	public:


	private:

		/// <summary>
		/// A 2D vector which is used to store the grid as 0 - free and 1's - not free
		/// </summary>
		std::vector<std::vector<int>> grid;

		/// <summary>
		/// [0] - horizontal movement cost
		/// [1] - diagonal movement cost
		/// [3] - 0 if don't use diagonal, 1 if use diagonal
		/// </summary>
		float movementCosts[3];

		/// <summary>
		/// 1 is average
		/// smaller values puts less importance on estimate distance making it more like Dijkstra's algorithm .e. slower but more accurate
		/// larger values puts more importance on estimate distance making it more greedy i.e. faster but less accurate
		/// </summary>
		float heuristicsCostScale;

		/// <summary>
		/// gridSize[0] - X size
		/// gridSize[1] - Y size
		/// 		/// </summary>
		int gridSize[2];
};

#endif