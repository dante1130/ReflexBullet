#include "DisplayGameWorld.h"

Player player;
Object3D ToyStore;
Object3D Shelf_1;

float startFrameTime = -1;
int frameCountPos = 0;
float frames = 0;
int lastFrameTime;


void DGW::DisplayGameWorldMasterFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glScalef(-1, 1, 1);
	ToyStore.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glPopMatrix();

	DisplayShelves();

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

void DGW::DisplayShelves()
{
	glPushMatrix();
	//Shelves facing +y in blender at the back of the shop
	glTranslatef(10, 0, 0.5);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-4, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	//switch sides
	glTranslatef(0, 0, 10);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	//Shelves facing -y in blender at the back of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(4, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	//Switch sides
	glTranslatef(0, 0, 10);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	//Back shop wall
	glRotatef(90, 0, 1, 0);
	glTranslatef(-2.5, 0, -7.5);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(8, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(2, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	//Middle back
	glTranslatef(-15, 0, 3);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(6, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glPopMatrix();

	//Front of shop shelves
	glPushMatrix();
	//Shelves facing -y in blender at the front of the shop
	glTranslatef(4, 0, 6.5);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 14);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	//Shelves facing +y in blender at the front of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(-4, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(4, 0, 4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, 14);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	//Shelves facing front of store
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.5, 0, 1.5);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(14, 0, 0);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(5, 0, -1);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, -4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	
	//Shelves facing back of store
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, 1);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);
	glTranslatef(0, 0, -4);
	Shelf_1.DisplayObjectWithLighting(TEXT_ENVIRONMENT_STAIRS);

	glPopMatrix();





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

