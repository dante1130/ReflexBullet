#ifndef DISPLAYGAMEOBJECTS_H
#define DISPLAYGAMEOBJECTS_H


#include "Gun.h"
#include "Enemy.h"
#include <GL/glut.h>

namespace DGO
{
	void DisplayEnemy(const Enemy& enemy);

	void DisplayGunBullets(const Gun& gun);

	void DisplayBullets(const Bullet& bullet);
}

#endif
