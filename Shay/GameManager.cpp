#include "GameManager.h"

bool ActiveGameWorld = false;
float gameWorldMovementSpeed = 0.06;
float camRotateSpeed = 1;
float zFar = 0.001;
bool Starting = true;
float delta = 0;
float elapsedTime = glutGet(GLUT_ELAPSED_TIME);

glm::vec3 m_playerPos, m_floatPos, m_playerLook, m_floatLook, m_bossArea;


Audio audio;
Collision collision;
Enemy enemy;

void GM::GameInit(int w, int h)
{
	audio.AddMusic("music/gamefast.wav", "gameplay");
	audio.PlayMusic("gameplay");

	LTGW::CreateTextures();

	glClearColor(1, 1, 1, 1);
	player.GetCamera().SetWorldCoordinates(0, 26);
	player.GetCamera().ClearAABB();


	player.GetCamera().SetRotateSpeed(camRotateSpeed);
	player.GetCamera().SetMoveSpeed(gameWorldMovementSpeed);
	player.GetCamera().Position(glm::vec3(0.5, playerHeight, 0.5), 180.0);
	player.GetCamera().SetMaximumCrouchDepth(crouchDepth);

	enemy.SetLook(player.GetCamera().GetPosition());

	CreateGameBoundingBoxes();
	
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

	//glEnable(GL_CULL_FACE);
	
	//glCullFace(GL_FRONT);

	LoadGameObjectFiles();
	ReadLeaderboardFile("data/leaderboards.txt", LB);
	
	PauseGame();
}

void GM::LoadGameObjectFiles()
{
	ReadOBJMTL("data/object/gameObjects/ToyStore.obj", ToyStore);
	ReadOBJMTL("data/object/gameObjects/Shelf_1.obj", Shelf_1);
	ReadOBJMTL("data/object/gameObjects/s_Box.obj", s_Box);
	ReadOBJMTL("data/object/gameObjects/s_Movies.obj", s_Movies);
	ReadOBJMTL("data/object/gameObjects/s_Books.obj", s_Books);
	ReadOBJMTL("data/object/gameObjects/Sky.obj", Sky);
	ReadOBJMTL("data/object/gameObjects/s_boardgame.obj", s_Board);
	ReadOBJMTL("data/object/gameObjects/boss.obj", bossBody);



	//
	//Objects used to populate the shelves
	//
	LoadGameShelfObject("data/object/gameObjects/s_WoodenBlocks.obj", S_WOODEN_BLOCKS);
	LoadGameShelfObject("data/object/gameObjects/s_ToyBuildings.obj", S_TOY_BUILDING);
	LoadGameShelfObject("data/object/gameObjects/s_StorageContainerBox.obj", S_STORAGE_CONTAINER_BOX);
	LoadGameShelfObject("data/object/gameObjects/s_plane.obj", WOOD);
	LoadGameShelfObject("data/object/gameObjects/s_car.obj", WOOD);
	LoadGameShelfObject("data/object/gameObjects/s_truck.obj", WOOD);

	//
	//End of objects used to populate the shelves
	//
}

void GM::LoadGameShelfObject(const std::string& fileName, int textureID)
{
	ShelfObjectsOBJ temp;
	ReadOBJMTL(fileName, temp.obj);
	temp.texture = textureID;
	Shelf_Objects.push_back(temp);
}

void GM::CreateGameBoundingBoxes()
{
	// Walls
	collision.Push(glm::vec3(20, 5, 0.05), glm::vec3(0, 0, -2));
	collision.Push(glm::vec3(20, 5, 28), glm::vec3(0, 0, 25.95));
	collision.Push(glm::vec3(0.05, 5, 26), glm::vec3(-2, 0, 0));
	collision.Push(glm::vec3(22, 5, 26), glm::vec3(19.95, 0, 0));

	player.GetCamera().SetCollision(collision);
}

void GM::GameCollisionResolution()
{
	for (int i = 0; i < player.GetGun().BulletCount(); ++i)
	{
		if (collision.Collide(player.GetGun().BulletAt(i).GetBoundingSphere()))
		{
			player.GetGun().RemoveBullet(i);
		}
	}
}

void GM::GameFixedUpdateLoop(int val)
{
	glutTimerFunc(FRAMETIME, GameFixedUpdateLoop, 0);

	if (Starting) { GameStartUp(); }

	float newElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	delta = (newElapsedTime - elapsedTime) / 1000;
	elapsedTime = newElapsedTime;

	if (PMV.m_PausedMenuChoosen != 0)
	{
		PausedFloatingPosition();
	}
	else
	{
		player.Update(delta);
		player.GetCamera().KeyboardMovement();
		if (bossOn)
			boss.Update(delta);
	}

	Enemy::SetLook(player.GetCamera().GetPosition());
	enemy.Shoot();

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
		PMV.m_PausedMenuChoosen = (PMV.m_PausedMenuChoosen + 1) % 5;
		if (PMV.m_PausedMenuChoosen == 0) { PMV.m_PausedMenuChoosen = 1; }
	case 'b':
	case 'B':
		visibleShelves = false;
		ToyStore.Clear();
		ReadOBJMTL("data/object/gameObjects/bossAreaV2.obj", ToyStore);
		bossOn = true;
		break;
	case 'h':
	case 'H':
		player.SetHealth(player.GetHealth() + 10);
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
			std::cout << "speed +" << std::endl;
			
			camRotateSpeed -= 0.05;
			if (camRotateSpeed < 0.05) { camRotateSpeed = 0.05; }
			player.GetCamera().SetRotateSpeed(camRotateSpeed);
		}
		else if (option == 2)
		{
			std::cout << "speed -" << std::endl;
			camRotateSpeed += 0.05;
			if (camRotateSpeed > 5) { camRotateSpeed = 5; }
			player.GetCamera().SetRotateSpeed(camRotateSpeed);
		}
		else if (option == 3)
		{
			std::cout << "mV +" << std::endl;
		}
		else if (option == 4)
		{
			std::cout << "mV -" << std::endl;
		}
		else if (option == 5)
		{
			std::cout << "SFXV +" << std::endl;
		}
		else if (option == 6)
		{
			std::cout << "SFXV -" << std::endl;
		}
		else if (option == 7)
		{
			std::cout << "D +" << std::endl;
			//RestartGame();
		}
		else if (option == 8)
		{
			std::cout << "D -" << std::endl;
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
		if (option == 1) {  }
		else if (option == 2) {  }
		else if (option == 3) {  }
		else if (option == 4) {  }
		else if (option == 5) {  }
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
	GLfloat health = 100;;
	player.ResetFiringDelay();
	player.ResetBulletSpeed();
	player.ResetMoveSpeed();
	player.SetHealth(health);
	UnpauseGame();

	zFar = 0.001;
	Starting = true;

	glClearColor(1, 1, 1, 1);

	player.GetCamera().SetCameraLocation(0.5, playerHeight, 0.5);
	player.GetCamera().SetCameraLookAt(glm::vec3(-1, 0, 0));

}