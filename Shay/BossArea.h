#ifndef BOSSAREA_H
#define BOSSAREA_H

#include "Object.h"
#include "Boss.h"
#include "definesGW.h"

extern Object3D bossBody;
extern Boss boss;

void BossInit();

void DrawBoss();

void PhaseChange();

void PhaseApply();

int PsudeoNumGen(int seed, int max, int rand);


#endif