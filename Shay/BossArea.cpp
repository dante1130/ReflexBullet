#include "BossArea.h"



Object3D bossBody;
UI BossUI(300, 70, 70, true);
Boss boss(10, 3, 15);
BoundingSphere b_Sphere(glm::vec3(10, 3, 15), 2);


void BossInit(Player& player)
{
	if (boss.GetPhase() != 3)
		boss.TrackPlayer(player);
	else if(boss.GetRotation().z == 0){
		if (boss.LazerCollision(player) && !player.GetCamera().GetCrouch())
			player.SetLazerHit(true);
		else if(player.GetLazerHit())
			player.SetLazerHit(false);
	}
	DrawBoss();
	CollisionChecks(player);
}

void DrawBoss()
{
	glPushMatrix();
		boss.Animate();
		bossBody.DisplayObjectWithLighting(BOSS);
	glPopMatrix();
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
