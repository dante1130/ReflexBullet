#include "EnemyAI.h"
#include <iostream>

std::array<std::array<Grid, 26>, 20> EnemyAI::m_mainGrid;	
glm::ivec2 EnemyAI::m_playerPos;
glm::ivec2 EnemyAI::m_prevPlayerPos;

EnemyAI::EnemyAI()
	: m_gridPos(0), m_prevGridPos(0), m_gridDest(0), m_isMoving(false), m_isFirstMove(false)
{}

void EnemyAI::Die()
{
	m_mainGrid[m_gridPos.x][m_gridPos.y] = Grid::FREE;
	m_mainGrid[m_gridDest.x][m_gridDest.y] = Grid::FREE;
	m_isMoving = false;
}

void EnemyAI::ResetGrid()
{
	// I'm sorry.
	const int initialGrid[20][26] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 1, 1, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 2, 2, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	}; 

	for (int i = 0; i < m_mainGrid.size(); ++i)
		for (int j = 0; j < m_mainGrid[i].size(); ++j)
			m_mainGrid[i][j] = (Grid)initialGrid[i][j];
}

void EnemyAI::SwitchBossGrid()
{
	// I'm sorry too.
	const int bossGrid[20][26] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 2, 2, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 1, 2, 2, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 2, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 2, 2, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 2, 2, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	for (int i = 0; i < m_mainGrid.size(); ++i)
		for (int j = 0; j < m_mainGrid[i].size(); ++j)
			m_mainGrid[i][j] = (Grid)bossGrid[i][j];	
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
		if (isDestinationReached(currentPos))
		{
			m_isMoving = false;
		}

		m_mainGrid[m_prevGridPos.x][m_prevGridPos.y] = Grid::FREE;
		m_mainGrid[m_gridPos.x][m_gridPos.y] = Grid::ENEMYTHERE;
	}
	else
	{
		FindNextDest();
	}
}

bool EnemyAI::isDestinationReached(const glm::vec3& currentPos)
{
	glm::vec2 currentPos2D= glm::vec2(currentPos.x, currentPos.z);

	glm::vec2 prevGridPosf = glm::vec2((GLfloat)m_prevGridPos.x + 0.5f, (GLfloat)m_prevGridPos.y + 0.5f);

	return glm::distance(prevGridPosf, currentPos2D) >= 1;
}

void EnemyAI::FindNextDest()
{
	std::vector<glm::ivec2> possibleDests;

	if (m_gridPos.y + 1 < 26 && m_mainGrid[m_gridPos.x][m_gridPos.y + 1] == Grid::FREE)
		possibleDests.push_back(glm::ivec2(m_gridPos.x, m_gridPos.y + 1));

	if (m_gridPos.x + 1 < 20 && m_mainGrid[m_gridPos.x + 1][m_gridPos.y] == Grid::FREE)
		possibleDests.push_back(glm::ivec2(m_gridPos.x + 1, m_gridPos.y));

	if (m_gridPos.y - 1 >= 0 && m_mainGrid[m_gridPos.x][m_gridPos.y - 1] == Grid::FREE)
		possibleDests.push_back(glm::ivec2(m_gridPos.x, m_gridPos.y - 1));

	if (m_gridPos.x - 1 >= 0 && m_mainGrid[m_gridPos.x - 1][m_gridPos.y] == Grid::FREE)
		possibleDests.push_back(glm::ivec2(m_gridPos.x - 1, m_gridPos.y));

	if (possibleDests.size() != 0)
	{
		m_gridDest = possibleDests[rand() % possibleDests.size()];
		m_isMoving = true;
		m_isFirstMove = true;
		m_mainGrid[m_gridDest.x][m_gridDest.y] = Grid::ENEMYGOING;
	}
}

void EnemyAI::DisplayWireframe()
{
	glDisable(GL_LIGHTING);
	glPushAttrib(GL_CURRENT_BIT);

	for (GLfloat i = 0.5f; i < m_mainGrid.size(); ++i)
	{
		for (GLfloat j = 0.5f; j < m_mainGrid[i].size(); ++j)
		{
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

			case Grid::ENEMYGOING:
				glColor3f(0, 1, 1);
				break;

			case Grid::PLAYERTHERE:
				glColor3f(1, 1, 1);
				break;
			}

			glPushMatrix();
			glTranslatef(i, 0, j);
			glutWireCube(1);
			glPopMatrix();
		}
	}

	glPopAttrib();
	glEnable(GL_LIGHTING);
}

void EnemyAI::DisplayMap()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0, 720);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);

	glPushAttrib(GL_CURRENT_BIT);

	for (int i = 0; i < m_mainGrid.size(); ++i)
	{
		for (int j = 0; j < m_mainGrid[i].size(); ++j)
		{
			switch (m_mainGrid[i][j])
			{
			case Grid::FREE:
			case Grid::ENEMYGOING:
				glColor3f(0, 1, 0);
				break;

			case Grid::FULL:
			case Grid::HALF:
				glColor3f(0, 0, 1);
				break;

			case Grid::ENEMYTHERE:
				glColor3f(1, 0, 0);
				break;

			case Grid::PLAYERTHERE:
				glColor3f(1, 1, 1);
				break;
			}

			glPushMatrix();
			glTranslatef(1250, 500, 0);
			glRotatef(90, 0, 0, 1);
			glRotatef(180, 1, 1, 0);
			glScalef(8, 8, 0);
			glBegin(GL_POLYGON);
			glVertex2f(i, j);
			glVertex2f(i + 1, j);
			glVertex2f(i + 1, j + 1);
			glVertex2f(i, j + 1);
			glEnd();
			glPopMatrix();
		}
	}

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

bool EnemyAI::GetIsMoving() const
{
	return m_isMoving;
}

const glm::ivec2& EnemyAI::GetRandFree()
{
	std::vector<glm::ivec2> freePositions;

	for (int i = 0; i < m_mainGrid.size(); ++i)
		for (int j = 0; j < m_mainGrid[i].size(); ++j)
			if (m_mainGrid[i][j] == Grid::FREE) 
				freePositions.push_back(glm::ivec2(i, j));

	int index = 1 + rand() % (freePositions.size() - 1);

	return freePositions[index];
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

void EnemyAI::SetPlayerPos(const glm::vec3& position)
{
	m_prevPlayerPos = m_playerPos;
	m_playerPos = glm::ivec2(position.x, position.z);
}

void EnemyAI::SetGridPos(const glm::ivec2& position)
{
	m_gridPos = position;
}

bool EnemyAI::isPlayerInView(const glm::vec3& lookAt)
{
	glm::vec2 look2D = glm::normalize(glm::vec2(lookAt.x, lookAt.z));

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