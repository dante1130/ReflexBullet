#ifndef ENEMYAI_H
#define ENEMYAI_H

#include <array>
#include <glm/vec2.hpp>
#include "Grid.h"
#include <GL/glut.h>

class EnemyAI
{
public:
	EnemyAI();

	void AIUpdate();

	static void DisplayWireframe()
	{
		for (GLfloat i = 0.5f; i < m_mainGrid.size(); ++i)
		{
			for (GLfloat j = 0.5f; j < m_mainGrid[i].size(); ++j)
			{
				glPushAttrib(GL_CURRENT_BIT);

				switch (m_mainGrid[i][j])
				{
				case Grid::FREE:
					glColor3f(0, 1, 0);
					break;

				case Grid::FULL:
					glColor3f(0, 0, 1);
					break;

				case Grid::HALF:
					glColor3f(1, 0, 1);
					break;

				case Grid::ENEMYTHERE:
					glColor3f(1, 0, 0);
					break;
				}

				glPushMatrix();
				glTranslatef(i, 0, j);
				glutWireCube(1);
				glPopMatrix();

				glPopAttrib();
			}
		}
	}

private:
	// As it is a 2d array, it does store what is happening in that grid position (based on it's x/z location in the grid)
	// If the position is empty, then both should be FREE
	static std::array<std::array<Grid, 26>, 20> m_mainGrid;

	glm::vec2 m_gridPos;

	bool m_isMoving;
};

#endif