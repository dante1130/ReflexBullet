#include "EnemyAI.h"

std::array<std::array<Grid, 26>, 20> EnemyAI::m_mainGrid;	

EnemyAI::EnemyAI()
	: m_gridPos(0.0f), m_isMoving(false)
{
	for (auto& gridRow : m_mainGrid)
		gridRow.fill(Grid::FREE);
}

void EnemyAI::AIUpdate()
{

}