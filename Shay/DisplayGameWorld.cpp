#include "DisplayGameWorld.h"

Player player;
Object3D ToyStore;

float startFrameTime = -1;
int frameCountPos = 0;
float frames = 0;
int lastFrameTime;

void DGW::DisplayGameWorldMasterFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1, 1, 1, 1);

	glPushMatrix();
	glScalef(0.00333333, 0.00333333, 0.00333333);
	ToyStore.DisplayObject(TEXT_ENVIRONMENT_STAIRS);
	glPopMatrix();

	DisplayPerformanceMetrics();

	DGO::DisplayGunBullets(player.GetGun());

	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, 1280/720, 0.001, 1000);

	glMatrixMode(GL_MODELVIEW);
	*/

	glutSwapBuffers();
}


void DGW::DisplayPerformanceMetrics()
{
	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 1280, 0, 720);

	glMatrixMode(GL_MODELVIEW);
	*/

	if (startFrameTime == -1)
	{
		startFrameTime = glutGet(GLUT_ELAPSED_TIME);
		lastFrameTime = startFrameTime;
	}
	frameCountPos++;
	float elapsedTime = glutGet(GLUT_ELAPSED_TIME);

	if (elapsedTime - lastFrameTime > 33)
	{
		std::cout << "WARNING: Frame time detected that is above 33 miliseconds :WARNING" << std::endl;
	}
	lastFrameTime = elapsedTime;

	if ((elapsedTime - startFrameTime) < 1000) { return; }

	std::cout << "Frames per second: " << frameCountPos << std::endl;

	frameCountPos = 0;
	startFrameTime = glutGet(GLUT_ELAPSED_TIME);

	/*
	char temp[30], text[10];
	gcvt(fps, 10, text);
	strcpy(temp, "Frames per second: ");
	sprintf(text, "%d", (int)fps);
	strcat(temp, text);
	glRasterPos2i(0, 700);
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);
	*/
}


void DGW::RenderBitMapString(void* font, char* string)
{
	char* c;

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}

	return;
}

