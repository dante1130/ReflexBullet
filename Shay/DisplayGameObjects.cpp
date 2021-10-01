#include "DisplayGameObjects.h"
#include <iostream>

void DGO::DisplayEnemy(const Enemy& enemy)
{
	glPushMatrix();
	glTranslatef(enemy.GetPosition().x,
				 enemy.GetPosition().y,
				 enemy.GetPosition().z);
	glutSolidTeapot(0.5);
	glPopMatrix();
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
