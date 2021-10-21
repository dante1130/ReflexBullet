#include "BossArea.h"



Object3D bossBody;
UI BossUI(300, 70, 70, true);
Boss boss(10, 3, 15);
BoundingSphere b_Sphere(glm::vec3(10, 3, 15), 2);

int timer, timePhaseStart, lastTime = 0;
float xRotate, yRotate, temp_healthDecay;

glm::vec3 zero(0, 0, 0);
glm::vec3 saveRotate;

void BossInit(Player& player)
{
	timer = glutGet(GLUT_ELAPSED_TIME);
	BossUI.DrawHUD(boss.GetHealth(), boss.GetStartHealth());
	if (boss.GetPhase() != 3)
		boss.TrackPlayer(player);
	else {
		if (boss.LazerCollision(player) && !player.GetCamera().GetCrouch())
		{
			player.SetLazerHit(true);
			std::cout << "HIT HIT HIT" << std::endl;
		}
		else if(player.GetLazerHit())
			player.SetLazerHit(false);
	}
	DrawBoss();
	CollisionChecks(player);
	PhaseChange();
	lastTime = timer;
}

void DrawBoss()
{
	glPushMatrix();
		glTranslatef(boss.GetPosition().x, boss.GetPosition().y, boss.GetPosition().z);
		PhaseApply();
		boss.AnimateRotate();
		bossBody.DisplayObjectWithLighting(BOSS);
		if (boss.GetPhase() == 3) 
		{
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(B_LAZER));
			boss.AnimateSpecial(timer - timePhaseStart);
			glPopMatrix();
		}
	glPopMatrix();
}

void PhaseChange()
{
	if (timer - timePhaseStart >= 15000)
	{
		int temp = PsudeoNumGen(timer, 3, timePhaseStart) + 1;
		if (temp != boss.GetPhase()) {
			boss.SetPhase(temp);
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

void CollisionChecks(Player& player)
{
	for (int i = 0; i < player.GetGun().BulletCount(); ++i)
	{
		BoundingSphere bulletBSphere(player.GetGun().BulletAt(i).GetBoundingSphere().center,
			player.GetGun().BulletAt(i).GetBoundingSphere().radius - 0.20);

		if (Collision::Collide(bulletBSphere, b_Sphere))
		{
			player.IncrementBulletHits();
			player.IncrementBulletShots();
			player.GetGun().RemoveBullet(i);
			boss.SetHealth(boss.GetHealth() - 1);
			player.SetHealth(player.GetHealth() + 5);
		}
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