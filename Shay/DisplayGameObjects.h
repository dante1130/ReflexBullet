#ifndef DISPLAYGAMEOBJECTS_H
#define DISPLAYGAMEOBJECTS_H

#include "../include/GL/glut.h"
#include "Gun.h"

namespace DGO
{
	void DisplayGunBullets(const Gun& gun);

	void DisplayBullets(const Bullet& bullet);
}

#endif
