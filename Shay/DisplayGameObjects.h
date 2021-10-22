#ifndef DISPLAYGAMEOBJECTS_H
#define DISPLAYGAMEOBJECTS_H

#include "Gun.h"
#include "Enemy.h"
#include "Player.h"
#include "Object.h"
#include "definesGW.h"
#include "glm/vec3.hpp"
#include <algorithm>
#include <glm/common.hpp>
#include <vector>
#include <GL/glut.h>

struct RobotEnemies
{
	Object3D obj;
	std::vector<Enemy> enemies;

	void Spawn(int noOfEnemies, glm::vec3 playerPos)
	{
		BoundingBox tempBBox(obj.GetVertex(0), obj.GetVertex(0));

		for (int i = 0; i < obj.GetVertexCount(); ++i)
		{
			tempBBox.max = glm::max(obj.GetVertex(i), tempBBox.max);
			tempBBox.min = glm::min(obj.GetVertex(i), tempBBox.min);
		}

		for (int i = 0; i < noOfEnemies; ++i)
		{
			glm::ivec2 position;
			glm::ivec2 playerPos2D = glm::ivec2(playerPos.x, playerPos.z);

			do 
			{
				position = EnemyAI::GetRandFree();
			} while (position.x <= playerPos2D.x + 2 && position.y <= playerPos2D.y + 2);

			enemies.push_back(Enemy(glm::vec3(position.x + 0.5, 0.5, position.y + 0.5)));
			enemies[i].SetBBox(tempBBox);
		}
	}

	bool isAllDead()
	{
		int aliveCount = std::count_if(enemies.begin(), enemies.end(), [](Enemy enemy) {
			return enemy.GetIsAlive();
		});

		return aliveCount == 0;
	}
};

namespace DGO
{
	void DisplayEnemies(RobotEnemies& robots);

	void DisplayGunBullets(const Gun& gun);

	void DisplayBullets(const Bullet& bullet);

}

#endif
