#include "EnemyAI.h"
#include <iostream>
#include <glm\geometric.hpp>

std::array<std::array<Grid, 26>, 20> EnemyAI::m_mainGrid;	
glm::ivec2 EnemyAI::m_playerPos;
glm::ivec2 EnemyAI::m_prevPlayerPos;

EnemyAI::EnemyAI()
	: m_gridPos(0), m_prevGridPos(0), m_gridDest(0), m_isMoving(false), m_isFirstMove(false)
{
	for (auto& gridRow : m_mainGrid)
		gridRow.fill(Grid::FREE);
}

void EnemyAI::AIUpdate(const glm::vec3& currentPos)
{
	if (m_isFirstMove)
	{
		m_prevGridPos = m_gridPos;
		m_isFirstMove = false;
	}

	m_gridPos.x = (GLint)currentPos.x;
	m_gridPos.y = (GLint)currentPos.z;

	m_mainGrid[m_prevPlayerPos.x][m_prevPlayerPos.y] = Grid::FREE;
	m_mainGrid[m_playerPos.x][m_playerPos.y] = Grid::PLAYERTHERE;

	if (m_isMoving)
	{
		// Destination reached
		if (floorf(currentPos.x * 10) / 10 == (GLfloat)m_gridDest.x + 0.5 &&
			floorf(currentPos.z * 10) / 10 == (GLfloat)m_gridDest.y + 0.5)
		{
			m_isMoving = false;
		}

		m_mainGrid[m_prevGridPos.x][m_prevGridPos.y] = Grid::FREE;
		m_mainGrid[m_gridPos.x][m_gridPos.y] = Grid::ENEMYTHERE;
	}
	else
	{
		FindNextDest();
		m_isMoving = true;
		m_isFirstMove = true;
	}
}

void EnemyAI::FindNextDest()
{
	std::vector<glm::ivec2> possibleDests;

	if (m_mainGrid[m_gridPos.x][m_gridPos.y + 1] == Grid::FREE)
	{
		possibleDests.push_back(glm::ivec2(m_gridPos.x, m_gridPos.y + 1));
	}
	if (m_mainGrid[m_gridPos.x + 1][m_gridPos.y] == Grid::FREE)
	{
		possibleDests.push_back(glm::ivec2(m_gridPos.x + 1, m_gridPos.y));
	}
	if (m_mainGrid[m_gridPos.x][m_gridPos.y - 1] == Grid::FREE)
	{
		possibleDests.push_back(glm::ivec2(m_gridPos.x, m_gridPos.y - 1));
	}
	if (m_mainGrid[m_gridPos.x - 1][m_gridPos.y] == Grid::FREE)
	{
		possibleDests.push_back(glm::ivec2(m_gridPos.x - 1, m_gridPos.y));
	}

	m_gridDest = possibleDests[rand() % possibleDests.size()];
}

void EnemyAI::DisplayWireframe()
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

			case Grid::PLAYERTHERE:
				glColor3f(1, 1, 0);
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

void EnemyAI::SetPlayerPos(const glm::vec3& position)
{
	m_prevPlayerPos = m_playerPos;
	m_playerPos = glm::ivec2(position.x, position.z);
}

void EnemyAI::SetGridPos(const glm::ivec2& position)
{
	m_gridPos = position;
}

const glm::ivec2& EnemyAI::GetGridDest() const
{
	return m_gridDest;
}

const glm::ivec2& EnemyAI::GetGridPos() const
{
	return m_gridPos;
}

const glm::ivec2& EnemyAI::GetPrevGridPos() const
{
	return m_prevGridPos;
}

bool EnemyAI::isPlayerInView(const glm::vec3& lookAt)
{
	glm::vec2 look2D = glm::vec2(lookAt.x, lookAt.z);

	for (glm::vec2 tempPos = m_gridPos; tempPos.x >= 0 && tempPos.y >= 0 && tempPos.x < 20 && tempPos.y < 26; tempPos += look2D)
	{
		switch (m_mainGrid[tempPos.x][tempPos.y])
		{
		case Grid::FULL:
			return false;

		case Grid::PLAYERTHERE:
			return true;
		}
	}
	return false;
}


