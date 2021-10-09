#include "BossArea.h"

Object3D bossBody;
UI BossUI(300, 70, 70, true);
Boss boss;

int timer, timePhaseStart, lastTime = 0;
float xRotate, yRotate, temp_healthDecay;

glm::vec3 pos(10, 3, 15);
glm::vec3 zero(0, 0, 0);
glm::vec3 saveRotate;

void BossInit(Player& player)
{
	timer = glutGet(GLUT_ELAPSED_TIME);
	BossUI.DrawHUD(boss.GetHealth(), boss.GetStartHealth());
	if (boss.GetPhase() != 3)
		boss.TrackPlayer(player);
	else {
		if (boss.LazerCollision(player))
		{
			player.SetLazerHit(true);
			std::cout << "HIT HIT HIT" << std::endl;
		}
		else if(player.GetLazerHit())
			player.SetLazerHit(false);
	}
	DrawBoss();
	PhaseChange();
	lastTime = timer;
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
		{
			glPushMatrix();
			tp.GetTexture(HEALTH);
			boss.AnimateSpecial(timer - timePhaseStart);
			glPopMatrix();
		}
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
			saveRotate = boss.GetRotation();
		}
		std::cout << "Phase changed to: " << boss.GetPhase() << std::endl;
		timePhaseStart = timer;
	}

}


void PhaseApply()
{
	if (timer - timePhaseStart > 1000)
	{
		if (boss.GetPhase() == 1)
			boss.Shoot();
		else if ((boss.GetPhase() == 2) && ((timer % 2000) > 1000))
			boss.Shoot();
	}

	if (boss.GetPhase() == 3)
	{
		if (boss.GetRotation().z != 0)
		{
			boss.SetRotation(mix(boss.GetRotation(), zero, 0.02));
			if ((boss.GetRotation().z > -0.05) && (boss.GetRotation().z < 0.05))
				boss.SetRotation(zero);
			return;
		}
		if (lastTime == 0)
			lastTime = glutGet(GLUT_ELAPSED_TIME);
		boss.SetRotationY(yRotate);
		yRotate += 15 * (findDiff((float)timer, (float)lastTime) / 1000);
		if (yRotate >= 360.0)
			yRotate = yRotate - 360;
	}
}


int PsudeoNumGen(int seed, int max, int rand)
{
	seed = (seed + rand) % max;
	return seed;
}

float findDiff(float a, float b)
{
	return sqrt(pow(a - b, 2));
}