#ifndef BOSSAREA_H
#define BOSSAREA_H

#include "Object.h"
#include "Boss.h"
#include "definesGW.h"
#include "Player.h"

extern Object3D bossBody;
extern Boss boss;

void BossInit(Player &player);

void DrawBoss();

void PhaseChange();

void PhaseApply();

void PhaseThreeRotate(glm::vec3 rot, int timeDone, int currentTime, int inv);

int PsudeoNumGen(int seed, int max, int rand);


#endif