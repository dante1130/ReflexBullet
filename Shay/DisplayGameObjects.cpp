#include "DisplayGameObjects.h"

void DGO::DisplayEnemies(RobotEnemies& robots)
{
	for (auto& enemy : robots.enemies)
	{
		glm::vec3 PlayerPos = enemy.GetPlayerPos() - enemy.GetPosition();
		glm::vec3 enemyLookAt = glm::vec3(1, 0, 0);
		float angle = acos((enemyLookAt.x * PlayerPos.x) /
			(sqrt(enemyLookAt.x * enemyLookAt.x)* sqrt(PlayerPos.x * PlayerPos.x + PlayerPos.z * PlayerPos.z)));

		if (enemy.GetPlayerPos().z > enemy.GetPosition().z) { angle *= -1; }

		angle = angle / PI * 180;

		//std::cout << angle << std::endl;

		if (enemy.GetIsAlive())
		{
			glPushMatrix();
			glTranslatef(enemy.GetPosition().x,
				enemy.GetPosition().y,
				enemy.GetPosition().z);
			glRotatef(angle, 0, 1, 0);
			robots.obj.DisplayObjectWithLighting(ROBOT);
			glPopMatrix();
		}

		DisplayGunBullets(enemy.GetGun());
	}
}

void DGO::DisplayGunBullets(const Gun& gun)
{
	for (int i = 0; i < gun.BulletCount(); ++i)
		DisplayBullets(gun.BulletAt(i));
}

void DGO::DisplayBullets(const Bullet& bullet)
{
	glPushMatrix();
	glTranslatef(bullet.GetPosition().x, 
				 bullet.GetPosition().y,
				 bullet.GetPosition().z);
	glutSolidSphere(0.25, 10, 10);
	glPopMatrix();
}
