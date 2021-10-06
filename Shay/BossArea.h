#ifndef BOSSAREA_H
#define BOSSAREA_H

#include "Object.h"
#include "Boss.h"
#include "UI.h"
#include "definesGW.h"
#include "Player.h"

extern Object3D bossBody;
extern Boss boss;
extern UI BossUI;

void BossInit(Player &player);

void DrawBoss();

void PhaseChange();

void PhaseApply();

int PsudeoNumGen(int seed, int max, int rand);

float findDiff(float a, float b);
#endif