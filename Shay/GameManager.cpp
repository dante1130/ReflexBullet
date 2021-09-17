#include "GameManager.h"



bool ActiveGameWorld = false;
float gameWorldMovementSpeed = 0.03;
float playerHeight = 0.9;
float crouchDepth = -playerHeight * 3/5;
float camRotateSpeed = 1;
float zFar = 0.001;
bool Starting = true;
float width;
float height;
float delta = 0;
float elapsedTime = glutGet(GLUT_ELAPSED_TIME);

void temp(int button, int state, int x, int y)
{
	glutPostRedisplay();
}

void GM::GameInit(int w, int h)
{
	player.GetCamera().SetRotateSpeed(camRotateSpeed);
	player.GetCamera().SetMoveSpeed(gameWorldMovementSpeed);
	player.GetCamera().Position(glm::vec3(0, playerHeight, 0), 180.0);
	player.GetCamera().SetMaximumCrouchDepth(crouchDepth);

	GameReshape(w, h); // Called once to init the reshape

	glutDisplayFunc(DGW::DisplayGameWorldMasterFunction);
	glutKeyboardFunc(GameKeys);
	glutKeyboardUpFunc(GameReleaseKeys);
	glutPassiveMotionFunc(GameMouseMove);
	glutMotionFunc(GameMouseMove);
	glutMouseFunc(GameMouseClick);
	GameReshape(w, h);
	glutReshapeFunc(GameReshape);

	glutTimerFunc(FRAMETIME, GameFixedUpdateLoop, 0);
	glutIdleFunc(GameUpdateLoop);

	glEnable(GL_CULL_FACE);
	
	glCullFace(GL_BACK);

	LoadGameObjectFiles();
}


void GM::LoadGameObjectFiles()
{
	readObjFile("data/object/ToyStore.obj", ToyStore);
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
		}
		GameReshape(width, height);

	}


	player.GetCamera().KeyboardMovement();
	float newElapsedTime = glutGet(GLUT_ELAPSED_TIME);
	delta = (newElapsedTime - elapsedTime) / 1000;
	elapsedTime = newElapsedTime;

	player.GetCamera().KeyboardMovement();
	player.Update(delta);
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
		if (camRotateSpeed > 5) { camRotateSpeed = 5; }
		player.GetCamera().SetRotateSpeed(camRotateSpeed);
		break;
	case '+':
	case '=':
		camRotateSpeed += 0.1;
		if (camRotateSpeed < 0.05) { camRotateSpeed = 0.05; }
		player.GetCamera().SetRotateSpeed(camRotateSpeed);
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
	}

}

void GM::GameMouseMove(int x, int y)
{
	player.GetCamera().MouseMove(x, y);

	glutPostRedisplay();
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