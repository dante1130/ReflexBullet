#include "GameManager.h"

Camera m_gameCam;
bool ActiveGameWorld = false;
float gameWorldMovementSpeed = 0.08;
float playerHeight = 0.9;
float crouchDepth = -playerHeight*3/5;
float camRotateSpeed = 1;



void GM::GameInit(int w, int h)
{
	m_gameCam.SetMoveSpeed(gameWorldMovementSpeed);
	m_gameCam.SetRotateSpeed(camRotateSpeed);
	m_gameCam.Position(glm::vec3(0, playerHeight, 0), 180.0);
	m_gameCam.SetMaximumCrouchDepth(crouchDepth);

	glutDisplayFunc(DGW::DisplayGameWorldMasterFunction);
	glutKeyboardFunc(GameKeys);
	glutKeyboardUpFunc(GameReleaseKeys);
	glutPassiveMotionFunc(GameMouseMove);
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

	m_gameCam.KeyboardMovement();
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
		m_gameCam.PrintPos();
		break;

		// move forwards
	case 'W':
	case 'w':
		m_gameCam.DirectionFB(1);
		break;

		// move backwards
	case 'S':
	case 's':
		m_gameCam.DirectionFB(-1);
		break;

		// step left
	case 'A':
	case 'a':
	case 1:
		m_gameCam.DirectionLR(-1);
		break;

		// step right
	case 'D':
	case 'd':
	case 4:
		m_gameCam.DirectionLR(1);
		break;
	case 27:
		exit(1);
		break;
	case 'C':
	case 'c':
	case ' ':
		m_gameCam.SetCrouch(true);
		break;
	case '_':
	case '-':
		camRotateSpeed -= 0.1;
		if (camRotateSpeed > 5) { camRotateSpeed = 5; }
		m_gameCam.SetRotateSpeed(camRotateSpeed);
		break;
	case '+':
	case '=':
		camRotateSpeed += 0.1;
		if (camRotateSpeed < 0.05) { camRotateSpeed = 0.05; }
		m_gameCam.SetRotateSpeed(camRotateSpeed);
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
		m_gameCam.DirectionLR(-2);
		break;
	case 'd':
	case 'D':
	case 4: //In case of ctrl + d
		m_gameCam.DirectionLR(2);
		break;

		// look left up or down
	case 'w':
	case 'W':
	case 's':
	case 'S':
	case 23: //In case of ctrl + w
	case 19: //In case of ctrl + s
		m_gameCam.DirectionFB(0);
		break;

	case 'c':
	case 'C':
	case ' ':
		m_gameCam.SetCrouch(false);
		break;
	}

}

void GM::GameMouseMove(int x, int y)
{
	m_gameCam.MouseMove(x, y);

	glutPostRedisplay();
}

void GM::GameReshape(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	int ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(90, ratio, 0.001, 1000);
	glMatrixMode(GL_MODELVIEW);
}