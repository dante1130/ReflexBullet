#ifndef BOSSAREA_H
#define BOSSAREA_H

#include "Object.h"
#include "Boss.h"
#include "UI.h"
#include "LoadTexturesGameWorld.h"
#include "Player.h"
#include "collision.h"

extern Object3D bossBody;
extern Boss boss;
extern UI BossUI;
extern BoundingSphere b_Sphere;

void BossInit(Player &player);

void DrawBoss();

void PhaseChange();

void PhaseApply();

void CollisionChecks(Player& player);

int PsudeoNumGen(int seed, int max, int rand);

float findDiff(float a, float b);
#endif