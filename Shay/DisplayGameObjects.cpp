#include "DisplayGameObjects.h"

void DGO::DisplayEnemies(RobotEnemies& robots)
{
	for (auto& enemy : robots.enemies)
	{
		glPushMatrix();
		glTranslatef(enemy.GetPosition().x,
					 enemy.GetPosition().y,
					 enemy.GetPosition().z);
		robots.obj.DisplayObjectWithLighting(ROBOT);
		glPopMatrix();

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
