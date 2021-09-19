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
	

	glPushMatrix();
	glScalef(-1, 1, 1);
	GLfloat mat_a[] = { 0.1, 0.1, 0.1, 1 };
	GLfloat mat_d[] = { 0.9, 0.9, 0.9, 1 };
	GLfloat mat_s[] = { 1, 1, 1, 1 };
	GLfloat low_sh[] = { 5.0 };
	GLfloat mat_e[] = { 0, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_a);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_d);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_s);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_e);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_sh);
	ToyStore.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glPopMatrix();

	DisplayPerformanceMetrics();

	GLfloat mat_a2[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat mat_d2[] = { 0, 0, 1, 1.0 };
	GLfloat mat_s2[] = { 1, 1, 1, 1.0 };
	GLfloat low_sh2[] = { 5.0 };
	GLfloat mat_e2[] = { 0, 0, 1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_a2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_d2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_s2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_e2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_sh2);

	DGO::DisplayGunBullets(player.GetGun());

	
	Lighting::UpdateLighting();

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

