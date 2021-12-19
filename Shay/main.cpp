#include <cstdlib>
#include <cmath>
#include <ctime>
#include <GL/glut.h>

#include "fileIO.h"
#include "ProcessShaysWorld.h"
#include "AStarInterface.h"

#include <vector>
//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
/**
* @brief	Main function
* @param	argc	- Int of how many arguments in char array
* @param	argv	- Char array
* @return	int
*/
int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;

	AStar level;
	std::vector<std::vector<DistanceNode>> result;
	level.setAllowDiagonalMovement(true);
	level.setHeuristicsCostScale(1.2);
	level.setNonDiagonalMovementCost(1);
	level.setDiagonalMovementCost(1.414);

	std::vector<std::vector<int>> grid;
	std::vector<int> row;
	int xSize = 10;
	int ySize = 10;
	for (int count = 0; count < xSize; count++)
	{
		row.push_back(0);
	}
	for (int count = 0; count < ySize; count++)
	{
		grid.push_back(row);
	}

	std::cout << grid.size() << std::endl;
	std::cout << grid[0].size() << std::endl;

	grid[0][2] = 1;
	grid[1][1] = 1;
	grid[1][3] = 1;
	grid[1][2] = 1;
	grid[2][2] = 1;


	level.setGrid(grid);

	node end, start;
	start.x = 0;
	start.y = 0;
	end.x = 3;
	end.y = 0;
	int temp;
	


	std::vector<node> path;
	node tempNode = end;

	result = level.findPath(start.x, start.y, end.x, end.y);


	for (int count = 0; count < ySize; count++)
	{
		for (int countTwo = 0; countTwo < xSize; countTwo++)
		{
			if (result[count][countTwo].parentNode.x != -1)
			{
				grid[count][countTwo] = 3;
			}
		}
	}


	std::cout << "\n\nResults::" << std::endl;
	bool running = true;
	while (running)
	{
		if (start.x == end.x && start.y == end.y) { running = false; }

		std::cout << "Node: y = " << end.y << " x = " << end.x << " cost = " << result[end.y][end.x].f
			<< " Parent: y: " << result[end.y][end.x].parentNode.y << " x: " << result[end.y][end.x].parentNode.x
			<< std::endl;

		grid[end.y][end.x] = 2;

		temp = end.x;
		end.x = result[end.y][end.x].parentNode.x;
		end.y = result[end.y][temp].parentNode.y;
	}

	std::cout << "Result: " << result[9][9].parentNode.x << std::endl;


	std::cout << std::endl;
	std::cout << "Result: 0 - free space, X - Blocked spaced, P - path, S - Start, E - end, 2 - checked node" << std::endl;

	for (int count = 0; count < ySize; count++)
	{
		for (int countTwo = 0; countTwo < xSize; countTwo++)
		{
			if (start.y == count && start.x == countTwo)
			{
				std::cout << "S ";
				continue;
			}

			if (tempNode.y == count && tempNode.x == countTwo)
			{
				std::cout << "E ";
				continue;
			}

			switch(grid[count][countTwo])
			{
			case 0:
				std::cout << "0 ";
				break;
			case 1:
				std::cout << "X ";
				break;
			case 2:
				std::cout << "P ";
				break;
			case 3:
				std::cout << "2 ";
				break;
			}
			
		}
		std::cout << std::endl;
	}



	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Duck and Cover 2: Duck Harder");

	PSW::myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(PSW::keys);
	glutKeyboardUpFunc(PSW::releaseKeys);
	
	glutDisplayFunc(PSW::Display);
	glutTimerFunc(FRAMETIME, PSW::RenderLoop, 0);

	glutMouseFunc(PSW::Mouse);

	glutSetCursor(GLUT_CURSOR_NONE);

	glutReshapeFunc(PSW::reshape);
	glutMainLoop();
	*/
	return 0;
}