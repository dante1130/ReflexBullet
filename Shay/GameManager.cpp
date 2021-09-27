#include "GameManager.h"

bool ActiveGameWorld = false;
float gameWorldMovementSpeed = 0.06;
float playerHeight = 0.9;
float crouchDepth = -playerHeight * 3/5;
float camRotateSpeed = 1;
float zFar = 0.001;
bool Starting = true;
float width;
float height;
float delta = 0;
float elapsedTime = glutGet(GLUT_ELAPSED_TIME);

Collision collision;
Enemy enemy;

void GM::GameInit(int w, int h)
{
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
}

void GM::LoadGameObjectFiles()
{
	ReadOBJMTL("data/object/gameObjects/ToyStore.obj", ToyStore);
	ReadOBJMTL("data/object/gameObjects/Shelf_1.obj", Shelf_1);
	ReadOBJMTL("data/object/gameObjects/s_Box.obj", s_Box);
	ReadOBJMTL("data/object/gameObjects/s_Movies.obj", s_Movies);
	ReadOBJMTL("data/object/gameObjects/s_Books.obj", s_Books);
	ReadOBJMTL("data/object/gameObjects/Sky.obj", Sky);


	//
	//Objects used to populate the shelves
	//
	LoadGameShelfObject("data/object/gameObjects/s_WoodenBlocks.obj", S_WOODEN_BLOCKS);
	LoadGameShelfObject("data/object/gameObjects/s_ToyBuildings.obj", S_TOY_BUILDING);
	LoadGameShelfObject("data/object/gameObjects/s_StorageContainerBox.obj", S_STORAGE_CONTAINER_BOX);
	LoadGameShelfObject("data/object/gameObjects/s_plane.obj", WOOD);
	LoadGameShelfObject("data/object/gameObjects/s_car.obj", WOOD);
	LoadGameShelfObject("data/object/gameObjects/s_truck.obj", WOOD);

	//same object, dramaticall slows down frame rate using same object to load
	//must program so that one object can use from set of textures
	LoadGameShelfObject("data/object/gameObjects/s_boardgame.obj", M_POLY);
	LoadGameShelfObject("data/object/gameObjects/s_boardgame2.obj", B_GAMMON);
	LoadGameShelfObject("data/object/gameObjects/s_boardgame3.obj", P_NARY);

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

	if (Starting)
	{
		zFar = zFar * 1.1;
		if (zFar > 1000)
		{
			zFar = 1000;
			Starting = false;
			glClearColor(0.5, 0.5, 0.5, 1);
		}
		GameReshape(width, height);

	}

	player.GetCamera().KeyboardMovement();

	float newElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	delta = (newElapsedTime - elapsedTime) / 1000;
	elapsedTime = newElapsedTime;
	player.Update(delta);

	Enemy::SetLook(player.GetCamera().GetPosition());
	enemy.Shoot();

	GameCollisionResolution();
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
		player.GetCamera().SetCrouch(true);
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
	}

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

	case 'l':
	case 'L': 
		totalTime -= 5000;
		break;
	}

}

void GM::GameMouseMove(int x, int y)
{
	player.GetCamera().MouseMove(x, y);

	//glutPostRedisplay();
}

void GM::GameMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		player.Shoot();
	}
}

void GM::GameReshape(int w, int h)
{
	width = w;
	height = h;

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