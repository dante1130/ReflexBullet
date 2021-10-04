#include "BossArea.h"

Object3D bossBody;
Boss boss;

int timer, timePhaseStart = 0;
float xRotate, yRotate;

glm::vec3 pos(10, 3, 15);
glm::vec3 zero(0, 0, 0);

void BossInit(Player& player)
{
	timer = glutGet(GLUT_ELAPSED_TIME);
	if(boss.GetPhase() != 3)
		boss.TrackPlayer(player);
	DrawBoss();
	PhaseChange();
}

void DrawBoss()
{
	glPushMatrix();
		boss.SetPosition(pos);
		glTranslatef(pos.x, pos.y, pos.z);
		PhaseApply();
		boss.AnimateRotate();
		bossBody.DisplayObjectWithLighting(BOSS);
		if (boss.GetPhase() == 3)
			boss.AnimateSpecial(timer - timePhaseStart);
	glPopMatrix();
}

void PhaseChange()
{
	if (timer - timePhaseStart >= 15000)
	{
		boss.SetPhase(PsudeoNumGen(timer, 4, timer / 2));
		if (boss.GetPhase() == 0)
			boss.SetPhase(1);
		if (boss.GetPhase() == 1)  
			boss.GetGun().SetFiringDelay(1);
		else if (boss.GetPhase() == 2)
			boss.GetGun().SetFiringDelay(0.3);
		else if (boss.GetPhase() == 3) {
			yRotate = 0;
		}
		std::cout << "Phase changed to: " << boss.GetPhase() << std::endl;
		timePhaseStart = timer;
	}

}


void PhaseApply()
{
	if (boss.GetPhase() == 1)
		boss.Shoot();
	else if ((boss.GetPhase() == 2) && ((timer % 2000) > 1000))
		boss.Shoot();
	else if(boss.GetPhase() == 3)
	{
		if ((timer - timePhaseStart) < 1000)
		{
			boss.SetRotation(mix(boss.GetRotation(), zero, 0.02));
			return;
		}
		boss.SetRotationY(yRotate);
		yRotate += 0.1;
		if (yRotate >= 360.0)
			yRotate = yRotate - 360;
	}
}


int PsudeoNumGen(int seed, int max, int rand)
{
	seed = (seed + rand) % max;
	return seed;
}