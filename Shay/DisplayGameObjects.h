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

/**
 * @struct RobotEnemies
 * @brief Struct for enemies in the game world.
 */
struct RobotEnemies
{
	/// The obj to be used to display the enemies, also used to calculate the bounding boxes.
	Object3D obj;



	/// Vector of enemies. 
	std::vector<Enemy> enemies;

	/**
	 * @brief Spawns enemies by specified amount.
	 * @param noOfEnemies int
	 * @param playerPos glm::vec3
	 * @return void
	 */
	void Spawn(int noOfEnemies, glm::vec3 playerPos, int currentSize)
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
			} while ((position.x >= playerPos2D.x - 2 && position.x <= playerPos2D.x + 2) &&
					 (position.y >= playerPos2D.y - 2 && position.y <= playerPos2D.y + 2));

			enemies.push_back(Enemy(glm::vec3(position.x + 0.5, 0.75, position.y + 0.5)));
			enemies[currentSize + i].SetBBox(tempBBox);
		}
	}

	/**
	 * @brief Returns a boolean to check if all enemies are dead.
	 * @return bool
	 */
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
	/**
	 * @brief Displays the enemies from the RobotEnemies struct.
	 * @param robots RobotEnemies&
	 * @return void
	 */
	void DisplayEnemies(RobotEnemies& robots);

	/**
	 * @brief Displays all the bullets in the gun.
	 * @param gun const Gun&
	 * @return void
	 */
	void DisplayGunBullets(const Gun& gun);

	/**
	 * @brief Displays the bullet.
	 * @param bullet const Bullet&
	 * @return void
	 */
	void DisplayBullets(const Bullet& bullet);
}

#endif
