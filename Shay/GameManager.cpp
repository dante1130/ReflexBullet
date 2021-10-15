#include "GameManager.h"
#include <thread>

int noOfSpawn = 100;
bool ActiveGameWorld = false;
float gameWorldMovementSpeed = 0.06;
float camRotateSpeed = 1;
float zFar = 0.001;
bool Starting = true;
float delta = 0;
float elapsedTime = glutGet(GLUT_ELAPSED_TIME);

glm::vec3 m_playerPos, m_floatPos, m_playerLook, m_floatLook, m_bossArea;

Collision collision;


void GM::GameInit(int w, int h)
{
	std::thread loadGameObjectFiles(LoadGameObjectFiles);
	std::thread loadAnimation(LoadAnimation);

	srand(time(0));

	Audio::AddMusic("music/gamefast.wav", "gameplay");
	Audio::AddSound("music/shooting.wav", "playerShoot");
	Audio::PlayMusicFadeIn("gameplay");

	LTGW::CreateTextures();

	ReadLeaderboardFile("data/leaderboards.txt", LB);

	glClearColor(1, 1, 1, 1);
	player.GetCamera().SetWorldCoordinates(0, 26);
	player.GetCamera().ClearAABB();

	player.GetCamera().SetRotateSpeed(camRotateSpeed);
	player.GetCamera().SetMoveSpeed(gameWorldMovementSpeed);
	player.GetCamera().Position(glm::vec3(0.5, playerHeight, 0.5), 180.0);
	player.GetCamera().SetMaximumCrouchDepth(crouchDepth);

	CreateGameBoundingBoxes();

	loadGameObjectFiles.join();
	loadAnimation.join();

	GameReshape(w, h); // Called once to reinit the reshape
	DGW::GetSize(w, h);
	Lighting::LightingInit();
	glutDisplayFunc(DGW::DisplayGameWorldMasterFunction);
	glutKeyboardFunc(GameKeys);
	glutKeyboardUpFunc(GameReleaseKeys);
	glutPassiveMotionFunc(GameMouseMove);
	glutMotionFunc(GameMouseMove);
	glutMouseFunc(GameMouseClick);
	glutReshapeFunc(GameReshape);

	glutTimerFunc(FRAMETIME, GameFixedUpdateLoop, 0);
	glutIdleFunc(GameUpdateLoop);

	PauseGame();
}

void GM::LoadGameObjectFiles()
{
	ReadOBJMTL("data/object/gameObjects/ToyStore.obj", GWO.ToyStore[0]);
	ReadOBJMTL("data/object/gameObjects/ToyShopPillars.obj", GWO.ToyStore[1]);
	ReadOBJMTL("data/object/gameObjects/Shelf_1.obj", GWO.Shelf_1);
	ReadOBJMTL("data/object/gameObjects/s_Box.obj", GWO.s_Box);
	ReadOBJMTL("data/object/gameObjects/s_Movies.obj", GWO.s_Movies);
	ReadOBJMTL("data/object/gameObjects/s_Books.obj", GWO.s_Books);
	ReadOBJMTL("data/object/gameObjects/Sky.obj", GWO.Sky);
	ReadOBJMTL("data/object/gameObjects/s_boardgame.obj", GWO.s_Board);
	ReadOBJMTL("data/object/gameObjects/Cachier.obj", GWO.cashier[0]);
	ReadOBJMTL("data/object/gameObjects/Cachier1.obj", GWO.cashier[1]);
	ReadOBJMTL("data/object/gameObjects/boss.obj", bossBody);
	ReadOBJMTL("data/object/gameObjects/TrainArea.obj", GWO.TrainArea);
	ReadOBJMTL("data/object/gameObjects/LightHead.obj", GWO.LightOBJ[0]);
	ReadOBJMTL("data/object/gameObjects/LightTop.obj", GWO.LightOBJ[1]);
	ReadOBJMTL("data/object/gameObjects/Table.obj", GWO.Table[0]);
	ReadOBJMTL("data/object/gameObjects/Box.obj", GWO.Table[1]);
	ReadOBJMTL("data/object/gameObjects/Chair.obj", GWO.Table[2]);
	ReadOBJMTL("data/object/gameObjects/Chair1.obj", GWO.Table[3]);
	ReadOBJMTL("data/object/gameObjects/Chair2.obj", GWO.Table[4]);
	ReadOBJMTL("data/object/gameObjects/robotDummy.obj", robots.obj);
	ReadOBJMTL("data/object/gameObjects/DisplayShelfMovies.obj", GWO.DisplayShelf[0]);
	ReadOBJMTL("data/object/gameObjects/DisplayShelfBooks.obj", GWO.DisplayShelf[1]);
	ReadOBJMTL("data/object/gameObjects/Bench.obj", GWO.Bench);
	ReadOBJMTL("data/object/gameObjects/LightPlane.obj", GWO.LightPlane);
	ReadOBJMTL("data/object/gameObjects/ClawMachine.obj", GWO.ClawMachine);
	ReadOBJMTL("data/object/gameObjects/Speaker.obj", GWO.Speaker);
	ReadOBJMTL("data/object/gameObjects/ShelfEnd.obj", GWO.ShelfEnd);
	ReadOBJMTL("data/object/gameObjects/Counter.obj", GWO.Counter);




	//
	//Objects used to populate the shelves
	//
	LoadGameShelfObject("data/object/gameObjects/s_WoodenBlocks", S_WOODEN_BLOCKS, 1);
	LoadGameShelfObject("data/object/gameObjects/s_ToyBuildings", S_TOY_BUILDING, 1);
	LoadGameShelfObject("data/object/gameObjects/s_StorageContainerBox", S_STORAGE_CONTAINER_BOX, 1);
	LoadGameShelfObject("data/object/gameObjects/s_plane", WOOD, 4);
	LoadGameShelfObject("data/object/gameObjects/s_car", WOOD, 3);
	LoadGameShelfObject("data/object/gameObjects/s_truck", WOOD, 4);





	//
	//End of objects used to populate the shelves
	//
}

void GM::LoadAnimation()
{
	Object3D temp, temp2;
	std::string tempName, nameStart = "data/object/gameObjects/TrainAnimation/TrainAnimation_000", nameEnd = ".obj";

	GWO.Train.texture = T_TRAIN;

	tempName = nameStart + "001" + nameEnd;
	ReadOBJMTL(tempName, temp);
	GWO.Train.obj.push_back(temp);
	for (int count = 2; count <= 144; count++)
	{
		tempName = nameStart;
		if (count < 10) { tempName = tempName + "00"; }
		else if (count < 100) { tempName = tempName + '0'; }
		tempName = tempName + std::to_string(count) + nameEnd;

		LoadAnimationFrame(tempName, GWO.Train);
		
	}
	std::cout << "Frames of animation loaded: " << GWO.Train.obj.size() << std::endl;


	std::string nameStartTwo = "data/object/gameObjects/DuckPersonAnimation/DuckPerson_0000";
	GWO.DuckPerson.texture = T_DUCK_PERSON;

	tempName = nameStartTwo + "01" + nameEnd;
	ReadOBJMTL(tempName, temp2);
	GWO.DuckPerson.obj.push_back(temp2);
	for (int count = 2; count <= 24; count++)
	{
		tempName = nameStartTwo;
		if (count < 10) { tempName = tempName + "0"; }
		tempName = tempName + std::to_string(count) + nameEnd;

		LoadAnimationFrame(tempName, GWO.DuckPerson);

	}
	std::cout << "Frames of animation loaded: " << GWO.DuckPerson.obj.size() << std::endl;

}

void GM::LoadAnimationFrame(std::string tempName, AnimationOBJ &AOBJ)
{
	Object3D temp;

	readObjFile(tempName, temp);
	temp.SetMTLArrayLocation(AOBJ.obj[0].GetMTLArrayLocation());
	AOBJ.obj.push_back(temp);
}

void GM::LoadGameShelfObject(const std::string& fileName, int textureID, int LODNumber)
{
	ShelfObjectsOBJ temp;
	Object3D tempOBJ;
	std::string fileNameStorage = fileName + ".obj";

	ReadOBJMTL(fileNameStorage, tempOBJ);

	temp.obj.push_back(tempOBJ);
	temp.texture = textureID;
	
	
	for (int count = 1; count < LODNumber; count++)
	{
		fileNameStorage = fileName + std::to_string(count) + ".obj";
		StoreLODObj(fileNameStorage, temp);
	}
	
	GWO.Shelf_Objects.push_back(temp);
}

void GM::StoreLODObj(std::string &fileName, ShelfObjectsOBJ &soOBJ)
{
	Object3D tempOBJ;

	ReadOBJMTL(fileName, tempOBJ);

	soOBJ.obj.push_back(tempOBJ);

}

void GM::CreateGameBoundingBoxes()
{
	// Walls
	collision.Push(glm::vec3(20, 7, 0.05), glm::vec3(0, 0, -2));
	collision.Push(glm::vec3(20, 5, 28), glm::vec3(0, 0, 25.95));
	collision.Push(glm::vec3(0.05, 7, 26), glm::vec3(-2, 0, 0));
	collision.Push(glm::vec3(22, 7, 26), glm::vec3(19.95, 0, 0));

	// Counter
	collision.Push(glm::vec3(9.05, 1, 3.05), glm::vec3(2.95, 0, 0));

	// Shelves by the wall
	collision.Push(glm::vec3(20.05, 1.5, 1.05), glm::vec3(8.95, 0, 0));

	collision.Push(glm::vec3(20.05, 1.5, 10.05), glm::vec3(18.95, 0, 1));
	collision.Push(glm::vec3(20.05, 0.5, 12.05), glm::vec3(18.95, 0, 9.95));

	collision.Push(glm::vec3(20.05, 0.5, 16.05), glm::vec3(18.95, 0, 13.95));
	collision.Push(glm::vec3(20.05, 1.5, 26), glm::vec3(18.95, 0, 15.95));

	// Shelves
	collision.Push(glm::vec3(19.05, 1.5, 26), glm::vec3(10.95, 0, 24.95));

	collision.Push(glm::vec3(9.05, 1.5, 26), glm::vec3(6.95, 0, 22.95));

	collision.Push(glm::vec3(5.05, 1.5, 26), glm::vec3(2.95, 0, 22.95));

	collision.Push(glm::vec3(5.05, 1.5, 7.05), glm::vec3(1.95, 0, 4.95));
	collision.Push(glm::vec3(7.05, 0.5, 7.05), glm::vec3(4.95, 0, 5.95));
	collision.Push(glm::vec3(8.05, 1.5, 9.05), glm::vec3(6.95, 0, 4.95));
	collision.Push(glm::vec3(10.05, 0.5, 7.05), glm::vec3(7.95, 0, 5.95));

	collision.Push(glm::vec3(15.05, 1.5, 5.05), glm::vec3(10.95, 0, 2.95));
	collision.Push(glm::vec3(17.05, 0.5, 5.05), glm::vec3(14.95, 0, 2.95));

	collision.Push(glm::vec3(17.05, 1.5, 12.05), glm::vec3(15.95, 0, 6.95));
	collision.Push(glm::vec3(17.05, 1.5, 8.05), glm::vec3(11.95, 0, 6.95));
	collision.Push(glm::vec3(17.05, 1.5, 9.05), glm::vec3(10.95, 0, 7.95));

	collision.Push(glm::vec3(17.05, 1.5, 19.05), glm::vec3(15.95, 0, 13.95));
	collision.Push(glm::vec3(16.05, 1.5, 18.05), glm::vec3(10.95, 0, 16.95));
	collision.Push(glm::vec3(17.05, 1.5, 19.05), glm::vec3(11.95, 0, 17.95));

	collision.Push(glm::vec3(15.05, 1.5, 23.05), glm::vec3(10.95, 0, 20.95));
	collision.Push(glm::vec3(17.05, 0.5, 23.05), glm::vec3(14.95, 0, 20.95));

	// Train
	collision.Push(glm::vec3(3.05, 1.5, 17.05), glm::vec3(1.95, 0, 14.95));
	collision.Push(glm::vec3(3.05, 1.5, 11.05), glm::vec3(1.95, 0, 8.95));
	collision.Push(glm::vec3(4.05, 0.5, 15.05), glm::vec3(1.95, 0, 10.95));
	

	//
	collision.Push(glm::vec3(13.05, 0.5, 15.05), glm::vec3(11.95, 0, 10.95));
	collision.Push(glm::vec3(14.05, 1.5, 15.05), glm::vec3(12.95, 0, 10.95));
	collision.Push(glm::vec3(15.05, 0.5, 14.05), glm::vec3(13.95, 0, 11.95));

	//
	collision.Push(glm::vec3(5.05, 1.5, 21.05), glm::vec3(1.95, 0, 18.95));
	collision.Push(glm::vec3(7.05, 0.5, 20.05), glm::vec3(4.95, 0, 18.95));
	collision.Push(glm::vec3(8.05, 1.5, 21.05), glm::vec3(6.95, 0, 16.95));
	collision.Push(glm::vec3(10.05, 0.5, 20.05), glm::vec3(7.95, 0, 18.95));

	//
	collision.Push(glm::vec3(7.05, 0.5, 15.05), glm::vec3(5.95, 0, 10.95));
	collision.Push(glm::vec3(10.05, 1.5, 14.05), glm::vec3(5.95, 0, 11.95));
	collision.Push(glm::vec3(10.05, 0.5, 16.05), glm::vec3(8.95, 0, 9.95));
	
	player.GetCamera().SetCollision(collision);

	// Floor
	collision.Push(glm::vec3(20, 0, 26), glm::vec3(0, -0.05, 0));

	// Ceiling
	collision.Push(glm::vec3(20, 5.05, 26), glm::vec3(0, 4.95, 0));
}

void GM::GameCollisionResolution()
{
	GM::PlayerBulletCollisionResolution();
	GM::EnemyBulletCollisionResolution();

	if (bossOn)
	{
		GM::BossBulletCollisionResolution();
	}
}

void GM::PlayerBulletCollisionResolution()
{
	// Player's bullets
	for (int i = 0; i < player.GetGun().BulletCount(); ++i)
	{
		const Bullet& playerBullet = player.GetGun().BulletAt(i);

		BoundingSphere bulletBSphere(playerBullet.GetBoundingSphere().center,
			playerBullet.GetBoundingSphere().radius - 0.20);

		// Collision with world objects
		if (collision.Collide(bulletBSphere))
		{
			player.GetGun().RemoveBullet(i);
			continue;
		}

		for (int j = 0; j < robots.enemies.size(); ++j)
		{
			// Collision with robots
			if (Collision::Collide(robots.enemies[j].GetBBox(),
				playerBullet.GetBoundingSphere()))
			{
				player.SetHealth(player.GetHealth() + playerBullet.GetDamage());
				player.GetGun().RemoveBullet(i);
				robots.enemies[j].SetHealth(robots.enemies[j].GetHealth() - playerBullet.GetDamage());
				break;
			}
		}
	}
}

void GM::EnemyBulletCollisionResolution()
{
	// Enemies' bullets
	for (auto& enemy : robots.enemies)
	{
		for (int i = 0; i < enemy.GetGun().BulletCount(); ++i)
		{
			const Bullet& enemyBullet = enemy.GetGun().BulletAt(i);

			BoundingSphere bulletBSphere(enemyBullet.GetBoundingSphere().center,
										enemyBullet.GetBoundingSphere().radius - 0.20);

			// Collision with world objects
			if (collision.Collide(bulletBSphere))
			{
				enemy.GetGun().RemoveBullet(i);
			}
			// Collision with player
			else if (Collision::Collide(player.GetCamera().GetPosition(),
				enemyBullet.GetBoundingSphere()))
			{
				player.SetHealth(player.GetHealth() - enemyBullet.GetDamage());
				enemy.GetGun().RemoveBullet(i);
			}
			else
			{
				bool isPlayerBulletCollide = false;

				// Collision with player's bullets
				for (int j = 0; j < player.GetGun().BulletCount(); ++j)
				{
					const Bullet& playerBullet = player.GetGun().BulletAt(j);

					if (Collision::Collide(enemyBullet.GetBoundingSphere(),
						playerBullet.GetBoundingSphere()))
					{
						enemy.GetGun().RemoveBullet(i);
						player.GetGun().RemoveBullet(j);
						isPlayerBulletCollide = true;
						break;
					}
				}

				// BUG FOR NOW
				/*
				if (!isPlayerBulletCollide)
				{
					// Collision with robots' bullets
					for (int j = 1; j < enemy.GetGun().BulletCount(); ++j)
					{
						const Bullet& otherEnemyBullet = enemy.GetGun().BulletAt(j);

						if (Collision::Collide(enemyBullet.GetBoundingSphere(),
											   otherEnemyBullet.GetBoundingSphere()))
						{
							enemy.GetGun().RemoveBullet(i);
							enemy.GetGun().RemoveBullet(j);
							break;
						}
					}
				}
				*/
			}
		}
	}
}

void GM::BossBulletCollisionResolution()
{
	for (int i = 0; i < boss.GetGun().BulletCount(); ++i)
	{
		BoundingSphere bulletBSphere(boss.GetGun().BulletAt(i).GetBoundingSphere().center,
			boss.GetGun().BulletAt(i).GetBoundingSphere().radius - 0.20);
		if (collision.Collide(bulletBSphere))
			boss.GetGun().RemoveBullet(i);
		if (Collision::Collide(player.GetCamera().GetPosition(), boss.GetGun().BulletAt(i).GetBoundingSphere()))
		{
			player.SetHealth(player.GetHealth() - boss.GetGun().BulletAt(i).GetDamage());
			boss.GetGun().RemoveBullet(i);
		}
	}
}

void GM::GameFixedUpdateLoop(int val)
{
	glutTimerFunc(FRAMETIME, GameFixedUpdateLoop, 0);

	float newElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	delta = (newElapsedTime - elapsedTime) / 1000;
	elapsedTime = newElapsedTime;

	if (Starting) 
		GameStartUp();
	else if (PMV.m_PausedMenuChoosen != 0) 
		PausedFloatingPosition();
	else
	{
		gameRunTime = gameRunTime + newElapsedTime - lastUnpausedFrame;
		lastUnpausedFrame = newElapsedTime;
		player.Update(delta);

		player.GetCamera().KeyboardMovement();

		Enemy::SetPlayerPos(player.GetCamera().GetPosition());
		for (int i = 0; i < robots.enemies.size(); ++i)
		{
			robots.enemies[i].Update(delta);

			if (robots.enemies[i].GetIsAlive())
			{
				robots.enemies[i].Shoot();
			}
			else if (robots.enemies[i].GetGun().BulletCount() == 0)
			{
				robots.enemies.erase(robots.enemies.begin() + i);
			}
		}

		if (bossOn)
			boss.Update(delta);
	}

	GameCollisionResolution();
}

void GM::GameStartUp()
{
	zFar = zFar * 1.1;
	if (zFar > 1000)
	{
		zFar = 1000;
		Starting = false;
		glClearColor(0.5, 0.5, 0.5, 1);
	}
	GameReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

void GM::GameUpdateLoop()
{
	glutPostRedisplay();
}

void GM::GameKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'x':
		player.GetCamera().PrintPos();
		break;

		// move forwards
	case 'W':
	case 'w':
		player.GetCamera().DirectionFB(1);
		break;

		// move backwards
	case 'S':
	case 's':
		player.GetCamera().DirectionFB(-1);
		break;

		// step left
	case 'A':
	case 'a':
	case 1:
		player.GetCamera().DirectionLR(-1);
		break;

		// step right
	case 'D':
	case 'd':
	case 4:
		player.GetCamera().DirectionLR(1);
		break;
	case 27:
		exit(1);
		break;
	case 'C':
	case 'c':
	case ' ':
		if (!PMV.m_floatMoving) { player.GetCamera().SetCrouch(true); }
		break;
	case 'p':
	case 'P':
		if (!(PMV.m_PausedMenuChoosen == 0 || PMV.m_PausedMenuChoosen == 1)) { return; }

		if (PMV.m_PausedMenuChoosen == 0) { PMV.m_PausedMenuChoosen = 1; }
		else { PMV.m_PausedMenuChoosen = 0; }


		if (PMV.m_PausedMenuChoosen == 1)
		{
			PauseGame();
		}
		else if(PMV.m_PausedMenuChoosen == 0)
		{
			UnpauseGame();
		}

		break;
	case '_':
	case '-':
		camRotateSpeed -= 0.1;
		if (camRotateSpeed < 0.05) { camRotateSpeed = 0.05; }
		player.GetCamera().SetRotateSpeed(camRotateSpeed);
		break;
	case '+':
	case '=':
		camRotateSpeed += 0.1;
		if (camRotateSpeed > 5) { camRotateSpeed = 5; }
		player.GetCamera().SetRotateSpeed(camRotateSpeed);
		break;
	case 'o':
	case 'O':
		wireFrame = !wireFrame;
		break;
	case 'i':
	case 'I':
		performanceMetric = !performanceMetric;
		break;
	case 49: // 1
		player.AddBulletSpeed(1);
		break;
	case 50: // 2
		player.AddMoveSpeed(0.01);
		break;
	case 51: // 3
		player.DecreaseFiringDelay(0.1);
		break;
	case 55: // 7
		player.ResetFiringDelay();
		break;
	case 56: // 8
		player.ResetBulletSpeed();
		break;
	case 57: // 9
		player.ResetMoveSpeed();
		break;
	case 'g':
		PMV.m_PausedMenuChoosen = (PMV.m_PausedMenuChoosen + 1) % 8;
		if (PMV.m_PausedMenuChoosen == 0) { PMV.m_PausedMenuChoosen = 1; }
		break;
	case 'b':
	case 'B':
		//GWO.ToyStore[0].Clear();
		//ReadOBJMTL("data/object/gameObjects/bossAreaV2.obj", GWO.ToyStore[0]);
		bossOn = true;
		break;
	case 'h':
	case 'H':
		player.SetHealth(player.GetHealth() + 10);
		break;
	case 'm':
	case 'M':
		Audio::SetMusicVolume(0);
		break;
	}
}

void GM::PauseGame()
{
	//glutPassiveMotionFunc(NULL);
	glutMotionFunc(NULL);
	PMV.m_playerPos = player.GetCamera().GetPosition();
	PMV.m_floatPos = PMV.m_playerPos;
	PMV.m_playerLook = player.GetCamera().GetLook();
	PMV.m_floatLook = PMV.m_playerLook;
	PMV.m_floatMoving = true;
	hudOn = false;
}

void GM::UnpauseGame()
{
	PMV.m_PausedMenuChoosen = 0;
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT) / 2);
	//glutPassiveMotionFunc(GameMouseMove);
	glutMotionFunc(GameMouseMove);
	PMV.m_floatMoving = false;
	player.GetCamera().SetCameraLocation(PMV.m_playerPos.x, PMV.m_playerPos.y, PMV.m_playerPos.z);
	player.GetCamera().SetCameraLookAt(PMV.m_playerLook);
	lastUnpausedFrame = glutGet(GLUT_ELAPSED_TIME);
	hudOn = true;
}

void GM::GameReleaseKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		// step left or right
	case 'a':
	case 'A':
	case 1: //In case of ctrl + a
		player.GetCamera().DirectionLR(-2);
		break;
	case 'd':
	case 'D':
	case 4: //In case of ctrl + d
		player.GetCamera().DirectionLR(2);
		break;

		// look left up or down
	case 'w':
	case 'W':
	case 's':
	case 'S':
	case 23: //In case of ctrl + w
	case 19: //In case of ctrl + s
		player.GetCamera().DirectionFB(0);
		break;

	case 'c':
	case 'C':
	case ' ':
		player.GetCamera().SetCrouch(false);
		break;
	}

}

void GM::GameMouseMove(int x, int y)
{
	if (PMV.m_PausedMenuChoosen == 0)
	{
		player.GetCamera().MouseMove(x, y);
	}
	else
	{
		MouseOverOption(x, y);
	}
	
}

void GM::MouseOverOption(int x, int y)
{
	float width = glutGet(GLUT_WINDOW_WIDTH);
	float height = glutGet(GLUT_WINDOW_HEIGHT);

	float xRatio = width / 1280.0;
	float yRatio = height / 720.0;

	float xMax = width / 2 + 157 * (xRatio * (yRatio - xRatio + 1));
	float xMin = width / 2 - 466 * (xRatio * (yRatio - xRatio + 1));
	float yMax = height / 2 + 302 * yRatio;
	float yMin = height / 2 - 139 * yRatio;
	
	if (x > xMax || x < xMin || y > yMax || y < yMin)
	{
		PMV.m_OptionHighlighted = 0;
		return;
	}

	float yChange = 76 * yRatio;

	float yTop = yMin;
	float yBottom = yMin + yChange;

	yChange = yChange + 15.2 * yRatio;

	if (PMV.m_PausedMenuChoosen == 2)
	{
		float xChange = 152 * (xRatio * (yRatio - xRatio + 1));
		GameMouseOverOptionOptions(x, y, xMax, xMin, yMax, yMin, yChange, xChange);
		return;
	}

	int max = 5;
	if (PMV.m_PausedMenuChoosen == 4 || PMV.m_PausedMenuChoosen == 1) { max = 4; }
	PMV.m_OptionHighlighted = 0;
	for (int count = 0; count < max; count++)
	{
		if (y > yTop && y < yBottom)
		{
			if (PMV.m_PausedMenuChoosen == 5)
			{
				if (count + 1 > 3)
				{
					PMV.m_OptionHighlighted = count + 1;
					count = max;
				}
			}
			else
			{
				PMV.m_OptionHighlighted = count + 1;
				count = max;
			}

		}

		yTop = yTop + yChange;
		yBottom = yBottom + yChange;

	}
}

void GM::GameMouseOverOptionOptions(int x, int y, float xMax, float xMin, float yMax, float yMin, float yChange, float xChange)
{
	float yTop = yMin;
	float yBottom = yMin + yChange;
	float xLeft = xMax;
	float xRight = xMax + xChange;

	PMV.m_OptionHighlighted = 0;
	for (int count = 0; count < 5; count++)
	{
		if (y > yTop && y < yBottom)
		{
			if (count == 4)
			{
				PMV.m_OptionHighlighted = count * 2 + 1;
				count = 5;
			}
			else
			{
				xLeft = xMax - xChange;
				xRight = xMax;

				for (int i = 0; i < 2; i++)
				{
					if (x > xLeft && x < xRight)
					{
						PMV.m_OptionHighlighted = count * 2 + i + 1;
						count = 5;
						i = 2;
					}

					xLeft = xMin;
					xRight = xMin + xChange;
				}
			}
		}

		yTop = yTop + yChange;
		yBottom = yBottom + yChange;
	}
}

void GM::GameMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && PMV.m_PausedMenuChoosen == 0)
	{
		player.Shoot();
	}
	else if (PMV.m_PausedMenuChoosen != 0)
	{
		GameMouseClickOption(button, state, x, y);
	}
}

void GM::GameMouseClickOption(int button, int state, int x, int y)
{
	//std::cout << "Mouse clicked: Button - " << button << " state - " << state << " POS x/y - " << x << " : " << y << std::endl;

	if (button != 0 || state != 0) { return; }

	float width = glutGet(GLUT_WINDOW_WIDTH);
	float height = glutGet(GLUT_WINDOW_HEIGHT);

	float xRatio = width / 1280.0;
	float yRatio = height / 720.0;

	float xMax = width / 2 + 157 * (xRatio * (yRatio - xRatio + 1));
	float xMin = width / 2 - 466 * (xRatio * (yRatio - xRatio + 1));
	float yMax = height / 2 + 302 * yRatio;
	float yMin = height / 2 - 139 * yRatio;

	if (x > xMax || x < xMin || y > yMax || y < yMin) { return; }

	float yChange = 76 * yRatio;

	float yTop = yMin;
	float yBottom = yMin + yChange;

	yChange = yChange + 15.2 * yRatio;

	if (PMV.m_PausedMenuChoosen == 2)
	{
		float xChange = 152 * (xRatio * (yRatio - xRatio + 1));
		GameMouseOptionMenuClickOption(x, y, xMax, xMin, yMax, yMin, yChange, xChange);
		return;
	}

	int max = 5;
	if (PMV.m_PausedMenuChoosen == 4) { max = 4; }
	PMV.m_OptionHighlighted = 0;
	for (int count = 0; count < max; count++)
	{
		if (y > yTop && y < yBottom)
		{
			MenuOptionChoosen(count + 1);
			count = max;
		}

		yTop = yTop + yChange;
		yBottom = yBottom + yChange;

	}

}

void GM::GameMouseOptionMenuClickOption(int x, int y, float xMax, float xMin, float yMax, float yMin, float yChange, float xChange)
{
	float yTop = yMin;
	float yBottom = yMin + yChange;
	float xLeft = xMax;
	float xRight = xMax + xChange;

	for (int count = 0; count < 5; count++)
	{
		if (y > yTop && y < yBottom)
		{
			if (count == 4)
			{
				MenuOptionChoosen(count * 2 + 1);
				count = 5;
			}
			else
			{
				xLeft = xMax - xChange;
				xRight = xMax;

				for (int i = 0; i < 2; i++)
				{
					if (x > xLeft && x < xRight)
					{
						MenuOptionChoosen(count * 2 + i + 1);
						count = 5;
						i = 2;
					}

					xLeft = xMin;
					xRight = xMin + xChange;
				}
			}
		}

		yTop = yTop + yChange;
		yBottom = yBottom + yChange;
	}
}

void GM::MenuOptionChoosen(int option)
{
	if (PMV.m_PausedMenuChoosen == 1) //General pause menu
	{
		if (option == 1) { UnpauseGame(); }
		else if (option == 2) { RestartGame(); }
		else if (option == 3) { PMV.m_PausedMenuChoosen = 2; PMV.m_PausedOverStart = true; }
		else if (option == 4) { PMV.m_PausedMenuChoosen = 4; }
	}
	else if (PMV.m_PausedMenuChoosen == 2) //Options menu
	{
		if (option == 1)
		{
			std::cout << "speed -" << std::endl;
			
			camRotateSpeed -= 0.05;
			if (camRotateSpeed < 0.05) { camRotateSpeed = 0.05; }
			player.GetCamera().SetRotateSpeed(camRotateSpeed);
		}
		else if (option == 2)
		{
			std::cout << "speed +" << std::endl;
			camRotateSpeed += 0.05;
			if (camRotateSpeed > 5) { camRotateSpeed = 5; }
			player.GetCamera().SetRotateSpeed(camRotateSpeed);
		}
		else if (option == 3)
		{
			std::cout << "mV -" << std::endl;
			Audio::SetMusicVolume(Audio::GetMusicVolume() - 5);
		}
		else if (option == 4)
		{
			std::cout << "mV +" << std::endl;
			Audio::SetMusicVolume(Audio::GetMusicVolume() + 5);
		}
		else if (option == 5)
		{
			std::cout << "SFXV -" << std::endl;
			Audio::SetSfxVolume(Audio::GetSfxVolume() - 5);
		}
		else if (option == 6)
		{
			std::cout << "SFXV +" << std::endl;
			Audio::SetSfxVolume(Audio::GetSfxVolume() + 5);
		}
		else if (option == 7)
		{
			std::cout << "D -" << std::endl;
			//RestartGame();
		}
		else if (option == 8)
		{
			std::cout << "D +" << std::endl;
			//RestartGame();
		}
		else if (option == 9)
		{
			if (PMV.m_PausedOverStart) { PMV.m_PausedMenuChoosen = 1; }
			else { PMV.m_PausedMenuChoosen = 4; }
		}

	}
	else if (PMV.m_PausedMenuChoosen == 3) //Upgrade menu
	{
		if (player.GetSkillPoints() > 0)
		{
			if (option == 1 && player.GetUpgradeOption(0) < 5)
			{
				player.DecreaseFiringDelay(0.1);
				player.SpendSkillPoint();
			}
			else if (option == 2 && player.GetUpgradeOption(1) < 5)
			{
				player.AddBulletSpeed(1);
				player.SpendSkillPoint();
			}
			else if (option == 3 && player.GetUpgradeOption(2) < 5)
			{
				player.DecreaseHealthDecay(0.01);
				player.SpendSkillPoint();
			}
			else if (option == 4 && player.GetUpgradeOption(3) < 4)
			{
				player.AddMoveSpeed(0.01);
				player.SpendSkillPoint();
			}
			else if (option == 5)
			{
				if (player.GetSkillPoints() >= 10)
				{
					//go to boss level
					GWO.ToyStore[0].Clear();
					ReadOBJMTL("data/object/gameObjects/bossAreaV2.obj", GWO.ToyStore[0]);
					bossOn = true;
				}
				else
				{
					UnpauseGame();
				}
			}
		}
	}
	else if (PMV.m_PausedMenuChoosen == 4) //Start screen
	{
		if (option == 1) { RestartGame(); }
		else if (option == 2) { PMV.m_PausedMenuChoosen = 2; PMV.m_PausedOverStart = false; }
		else if (option == 3) { PMV.m_PausedMenuChoosen = 5; }
		else if (option == 4) { exit(0); }
	}
	else if (PMV.m_PausedMenuChoosen == 5) //Credits
	{
		if (option == 4){ PMV.m_PausedMenuChoosen = 4; } //Return to start screen
		else if (option == 5) { exit(0); }
	}
	else if (PMV.m_PausedMenuChoosen == 6) //Defeat
	{
		if (option == 4) { RestartGame(); } //Restart game
		else if (option == 5) { PMV.m_PausedMenuChoosen = 4; } //Return to start screen
	}
	else if (PMV.m_PausedMenuChoosen == 7) //Victory
	{
		if (option == 5) { PMV.m_PausedMenuChoosen = 4; } //Return to start screen
	}

}

void GM::GameReshape(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	GLdouble ratio = (GLdouble)w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(90, ratio, 0.001, zFar);
	glMatrixMode(GL_MODELVIEW);
	elapsedTime = glutGet(GLUT_ELAPSED_TIME);
}

void GM::PausedFloatingPosition()
{
	if (PMV.m_floatMoving)
	{
		float timeToComplete = 120;

		//Smooth movement motion
		glm::vec3 change = { 2.5, 4.5, 13 };
		change = (change - PMV.m_playerPos);
		change.x = change.x / timeToComplete;
		change.y = change.y / timeToComplete;
		change.z = change.z / timeToComplete;

		PMV.m_floatPos = PMV.m_floatPos + change;

		//Smooth look motion
		glm::vec3 look = { -1, 0, 0 };
		float angle = acos((-1 * PMV.m_playerLook.x)/sqrt(PMV.m_playerLook.x * PMV.m_playerLook.x + PMV.m_playerLook.z * PMV.m_playerLook.z));
		
		if (PMV.m_playerLook.z >= 0)
		{
			PMV.m_floatLook.x = PMV.m_floatLook.x * cos(angle / timeToComplete) - PMV.m_floatLook.z * sin(angle / timeToComplete);
			PMV.m_floatLook.z = PMV.m_floatLook.x * sin(angle / timeToComplete) + PMV.m_floatLook.z * cos(angle / timeToComplete);
		}
		else
		{
			angle *= -1;
			PMV.m_floatLook.x = PMV.m_floatLook.x * cos(angle / timeToComplete) - PMV.m_floatLook.z * sin(angle / timeToComplete);
			PMV.m_floatLook.z = PMV.m_floatLook.x * sin(angle / timeToComplete) + PMV.m_floatLook.z * cos(angle / timeToComplete);
		}

		PMV.m_floatLook.y = PMV.m_floatLook.y - PMV.m_playerLook.y / timeToComplete;

		//if you reach the destination
		if (PMV.m_floatPos.y >= 4.5)
		{
			PMV.m_floatPos.x = 2.5;
			PMV.m_floatPos.y = 4.5;
			PMV.m_floatPos.z = 13;
			PMV.m_floatMoving = false;
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
		}

		player.GetCamera().SetCameraLocation(PMV.m_floatPos.x, PMV.m_floatPos.y, PMV.m_floatPos.z);
		player.GetCamera().SetCameraLookAt(PMV.m_floatLook);
	}
}

void GM::RestartGame()
{
	robots.enemies.clear();
	robots.Spawn(noOfSpawn);

	GLfloat health = 100;
	player.ResetFiringDelay();
	player.ResetBulletSpeed();
	player.ResetMoveSpeed();
	player.SetHealth(health);

	UnpauseGame();

	zFar = 0.001;
	Starting = true;
	gameRunTime = 0;

	glClearColor(1, 1, 1, 1);


	player.GetCamera().SetCameraLocation(0.5, playerHeight, 0.5);
	glm::vec3 cannotBindToTemporaryofTypeVec = { -1, 0, 0 };
	player.GetCamera().SetCameraLookAt(cannotBindToTemporaryofTypeVec); //Florian: My laptop does not like this line "non-const lvalue reference to type
															 // 'vec<...>' cannot bind to temporary of type 'vec<...>'"

}