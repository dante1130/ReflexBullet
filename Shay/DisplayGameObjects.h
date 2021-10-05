#ifndef DISPLAYGAMEOBJECTS_H
#define DISPLAYGAMEOBJECTS_H

#include "Gun.h"
#include "Enemy.h"
#include "Object.h"
#include "definesGW.h"
#include "glm/vec3.hpp"
#include <glm/common.hpp>
#include <vector>
#include <GL/glut.h>

struct RobotEnemies
{
	Object3D obj;
	std::vector<Enemy> enemies;

	void Spawn(int noOfEnemies)
	{
		BoundingBox tempBBox(obj.GetVertex(0), obj.GetVertex(0));

		for (int i = 0; i < obj.GetVertexCount(); ++i)
		{
			tempBBox.max = glm::max(obj.GetVertex(i), tempBBox.max);
			tempBBox.min = glm::min(obj.GetVertex(i), tempBBox.min);
		}

		for (int i = 0; i < noOfEnemies; ++i)
		{
			glm::ivec2 position = EnemyAI::GetRandFree();
			enemies.push_back(Enemy(glm::vec3(position.x + 0.5, 0.5, position.y + 0.5)));
			enemies[i].SetBBox(tempBBox);
		}
	}
};

namespace DGO
{
	void DisplayEnemies(RobotEnemies& robots);

	void DisplayGunBullets(const Gun& gun);

	void DisplayBullets(const Bullet& bullet);
}

#endif
