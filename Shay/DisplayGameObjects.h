#ifndef DISPLAYGAMEOBJECTS_H
#define DISPLAYGAMEOBJECTS_H


#include "Gun.h"
#include <GL/glut.h>

namespace DGO
{
	void DisplayGunBullets(const Gun& gun);

	void DisplayBullets(const Bullet& bullet);
}

#endif
