#include "DisplayGameWorld.h"

Player player;
Object3D ToyStore;
Object3D Shelf_1;
std::vector<ShelfObjectsOBJ> Shelf_Objects;
Object3D s_Box;
Object3D s_Movies;
Object3D s_Books;
Object3D s_Board;
Object3D Sky;
Leaderboard LB;

Object3D cashier[2];


AnimationOBJ Train;
AnimationOBJ DuckPerson;

float startFrameTime = -1;
int frameCountPos = 0;
int lastFrameTime;

bool wireFrame = false;
bool performanceMetric = true;

PauseMenuValues PMV;
GLfloat gameRunTime = 0;
GLfloat lastUnpausedFrame = 0;


void DGW::DisplayGameWorldMasterFunction()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glScalef(-1, 1, 1);
	Sky.DisplayObjectWithLighting(SKY);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glScalef(-1, 1, 1);
	ToyStore.DisplayObjectWithLighting(TOY_STORE);
	glPopMatrix();

	if (performanceMetric)
	{
		DisplayPerformanceMetrics();
	}
	
	DisplayShelves();
	DrawHUD(player);

	if (wireFrame)
	{
		EnemyAI::DisplayWireframe();
	}

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

	if (PMV.m_PausedMenuChoosen != 0 && !PMV.m_floatMoving)
	{
		DisplayPauseMenuOptions();
	}
	else
	{
		DGO::DisplayGunBullets(player.GetGun());
	}

	Lighting::UpdateLighting();

	DisplayAnimation();
	DisplayCashier();

	glutSwapBuffers();
}

void DGW::GetSize(int& width, int& height)
{
	GetScreenSize(width, height);
}

void DGW::DisplayShelves()
{
	glm::vec3 look = player.GetCamera().GetLook();
	glm::vec3 pos = player.GetCamera().GetPosition();
	float cullPoints[] = {9, 1, 11, 1 };


	glPushMatrix();
	//Shelves facing +y in blender at the back of the shop
	glTranslatef(10, 0, 0.5);
	DisplayShelfContentsCulling(1, 187090, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 11; cullPoints[2] = 13;
	DisplayShelfContentsCulling(1, 14658, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 13; cullPoints[1] = 1; cullPoints[2] = 15; cullPoints[3] = 1;
	DisplayShelfContentsCulling(1, 1547824, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 15; cullPoints[2] = 17;
	DisplayShelfContentsCulling(1, 13234, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 17; cullPoints[2] = 19;
	DisplayShelfContentsCulling(1, 283453, 1, look, pos, cullPoints);
	glTranslatef(-4, 0, 4);
	cullPoints[0] = 13; cullPoints[1] = 5; cullPoints[2] = 15; cullPoints[3] = 5;
	DisplayShelfContentsCulling(1, 0, 0, 5, 1, 7338, 0, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 11; cullPoints[2] = 13;
	DisplayShelfContentsCulling(1, 0, 0, 5, 1, 3639, 0, look, pos, cullPoints);
	glTranslatef(0, 0, 4);
	cullPoints[0] = 11; cullPoints[1] = 9; cullPoints[2] = 13; cullPoints[3] = 9;
	DisplayShelfContentsCulling(0, 0, 0, 9, 1, 1240, 0, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 13; cullPoints[2] = 15;
	DisplayShelfContentsCulling(0, 0, 0, 9, 1, 32144, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 15; cullPoints[2] = 17;
	DisplayShelfContentsCulling(0, 0, 0, 9, 1, 2122, 1, look, pos, cullPoints);
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	glScalef(0.5, 1, 1);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();
	//switch sides
	glTranslatef(0, 0, 10);
	cullPoints[1] = 19; cullPoints[3] = 19;
	DisplayShelfContentsCulling(0, 0, 0, 19, 1, 16340, 0, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 13;cullPoints[2] = 15;
	DisplayShelfContentsCulling(0, 0, 0, 19, 1, 1234600, 1, look, pos, cullPoints);
	glTranslatef(0, 0, 4);
	cullPoints[1] = 23; cullPoints[3] = 23;
	DisplayShelfContentsCulling(2, 0, 0, 23, 1, 12364, 0, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 11; cullPoints[2] = 13;
	DisplayShelfContentsCulling(2, 0, 0, 23, 1, 25626, 0, look, pos, cullPoints);

	//Shelves facing -y in blender at the back of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	cullPoints[1] = 25; cullPoints[3] = 25;
	DisplayShelfContentsCulling(2, 1463212, 0, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 13; cullPoints[2] = 15;
	DisplayShelfContentsCulling(2, 2477, 1, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 15; cullPoints[2] = 17;
	DisplayShelfContentsCulling(2, 227346, 1, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 17; cullPoints[2] = 19;
	DisplayShelfContentsCulling(2, 21783, 1, look, pos, cullPoints);
	glTranslatef(4, 0, 4);
	cullPoints[0] = 13; cullPoints[1] = 21; cullPoints[2] = 15; cullPoints[3] = 21;
	DisplayShelfContentsCulling(0, 0, 0, 21, -1, 234630, 0, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 11; cullPoints[2] = 13;
	DisplayShelfContentsCulling(0, 0, 0, 21, -1, 253211, 0, look, pos, cullPoints);
	glTranslatef(0, 0, 4);
	cullPoints[1] = 17; cullPoints[3] = 17;
	DisplayShelfContentsCulling(0, 0, 0, 17, -1, 365475, 0, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 13; cullPoints[2] = 15;
	DisplayShelfContentsCulling(0, 0, 0, 17, -1, 2352357, 1, look, pos, cullPoints);
	glTranslatef(-2, 0, 0);
	cullPoints[0] = 15; cullPoints[2] = 17;
	DisplayShelfContentsCulling(0, 0, 0, 17, -1, 53259, 1, look, pos, cullPoints);
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	glScalef(0.5, 1, 1);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();
	//Switch sides
	glTranslatef(0, 0, 10);
	cullPoints[0] = 15; cullPoints[1] = 7; cullPoints[2] = 17; cullPoints[3] = 7;
	DisplayShelfContentsCulling(1, 0, 0, 7, -1, 22457, 0, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 13; cullPoints[2] = 15;
	DisplayShelfContentsCulling(1, 0, 0, 7, -1, 34570, 1, look, pos, cullPoints);
	glTranslatef(0, 0, 4);
	cullPoints[1] = 3; cullPoints[3] = 3;
	DisplayShelfContentsCulling(1, 0, 0, 3, -1, 2352, 0, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[0] = 11; cullPoints[2] = 13;
	DisplayShelfContentsCulling(1, 0, 0, 3, -1, 231, 0, look, pos, cullPoints);

	//Back shop wall - left to right 
	glRotatef(90, 0, 1, 0);
	glTranslatef(-2.5, 0, -7.5);
	cullPoints[0] = 19; cullPoints[1] = 1; cullPoints[2] = 19; cullPoints[3] = 2;
	DisplayShelfContentsCulling(1, 905678, 1, look, pos, cullPoints);
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();

	glTranslatef(2, 0, 0);
	cullPoints[1] = 2; cullPoints[3] = 4;
	DisplayShelfContentsCulling(1, 963461, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 4; cullPoints[3] = 6;
	DisplayShelfContentsCulling(1, 92367, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 6; cullPoints[3] = 8;
	DisplayShelfContentsCulling(1, 52344, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 8; cullPoints[3] = 10;
	DisplayShelfContentsCulling(1, 12, 1, 0, 0, 23424, 0, look, pos, cullPoints);
	glTranslatef(8, 0, 0);
	cullPoints[1] = 16; cullPoints[3] = 18;
	DisplayShelfContentsCulling(2, 12, 1, 0, 0, 756, 0, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 18; cullPoints[3] = 20;
	DisplayShelfContentsCulling(2, 22789755, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 20; cullPoints[3] = 22;
	DisplayShelfContentsCulling(2, 25, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	cullPoints[1] = 22; cullPoints[3] = 24;
	DisplayShelfContentsCulling(2, 15789786, 1, look, pos, cullPoints);
	glTranslatef(2, 0, 0);
	//DisplayShelfContents(2, 17);
	cullPoints[1] = 24; cullPoints[3] = 25;
	DisplayShelfContentsCulling(2, 17897, 1, look, pos, cullPoints);
	glPushMatrix();
	glTranslatef(1, 0, 0);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();

	//Middle back
	glTranslatef(-15, 0, 3);
	cullPoints[0] = 16; cullPoints[1] = 9; cullPoints[2] = 16; cullPoints[3] = 11;
	DisplayShelfContentsCulling(0, 16, -1, 0, 0, 7819, 0, look, pos, cullPoints);
	glTranslatef(6, 0, 0);
	cullPoints[1] = 15; cullPoints[3] = 17;
	DisplayShelfContentsCulling(0, 16, -1, 0, 0, 11992, 0, look, pos, cullPoints);
	glPopMatrix();

	//Front of shop shelves
	glPushMatrix();
	//Shelves facing -y in blender at the front of the shop
	glTranslatef(4, 0, 6.5);
	cullPoints[0] = 3; cullPoints[1] = 7; cullPoints[2] = 5; cullPoints[3] = 7;
	DisplayShelfContentsCulling(0, 0, 0, 7, 1, 3118, 0, look, pos, cullPoints);
	glTranslatef(0, 0, 14);
	cullPoints[1] = 21; cullPoints[3] = 21;
	DisplayShelfContentsCulling(0, 0, 0, 21, 1, 10, 0, look, pos, cullPoints);

	//Shelves facing +y in blender at the front of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	cullPoints[1] = 23; cullPoints[3] = 23;
	DisplayShelfContentsCulling(0, 0, 0, 23, -1, 68, 0, look, pos, cullPoints);
	glTranslatef(-4, 0, 0);
	cullPoints[0] = 7; cullPoints[2] = 9;
	DisplayShelfContentsCulling(0, 0, 0, 23, -1, 0, 0, look, pos, cullPoints);
	glTranslatef(4, 0, 4);
	cullPoints[0] = 3; cullPoints[1] = 19; cullPoints[2] = 5; cullPoints[3] = 19;
	DisplayShelfContentsCulling(0, 0, 0, 19, -1, 56, 0, look, pos, cullPoints);
	glTranslatef(0, 0, 14);
	cullPoints[1] = 5; cullPoints[3] = 5;
	DisplayShelfContentsCulling(0, 0, 0, 5, -1, 80, 0, look, pos, cullPoints);

	//Shelves facing front of store
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.5, 0, 1.5);
	cullPoints[0] = 2; cullPoints[2] = 2; cullPoints[3] = 7;
	DisplayShelfContentsCulling(0, 2, -1, 0, 0, 25, 0, look, pos, cullPoints);
	glTranslatef(14, 0, 0);
	cullPoints[1] = 19; cullPoints[3] = 21;
	DisplayShelfContentsCulling(0, 2, -1, 0, 0, 66, 0, look, pos, cullPoints);
	glTranslatef(5, 0, -1);
	cullPoints[0] = 3; cullPoints[1] = 24; cullPoints[2] = 3; cullPoints[3] = 26;
	DisplayShelfContentsCulling(0, 3, -1, 0, 0, 77, 1, look, pos, cullPoints);
	glTranslatef(0, 0, -4);
	cullPoints[0] = 7; cullPoints[2] = 7;
	DisplayShelfContentsCulling(0, 7, -1, 0, 0, 88, 1, look, pos, cullPoints);
	
	//Shelves facing back of store
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, 1);
	cullPoints[0] = 9; cullPoints[2] = 9;
	DisplayShelfContentsCulling(0, 9, 1, 0, 0, 99, 1, look, pos, cullPoints);
	glTranslatef(0, 0, -4);
	cullPoints[0] = 5; cullPoints[2] = 5;
	DisplayShelfContentsCulling(0, 5, 1, 0, 0, 44, 1, look, pos, cullPoints);

	glPopMatrix();

}


void DGW::DisplayShelfContentsCulling(unsigned int objectList, int seed,
									  bool ShelfCulling, glm::vec3& look, glm::vec3& pos, float *cullPoints)
{
	DisplayShelfContentsCulling(objectList, 0, 0, 0, 0, seed, ShelfCulling, look, pos, cullPoints);
}

void DGW::DisplayShelfContentsCulling(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed,
									  bool ShelfCulling, glm::vec3& look, glm::vec3& pos, float *cullPoints)
{
	if (!ShelfCulling){	Shelf_1.DisplayObjectWithLighting(SHELF_1);	}
	
	glm::vec3 direction = -pos;
	direction.x += cullPoints[0];
	direction.z += cullPoints[1];
	float angleOne = acos((direction.x * look.x + direction.z * look.z)/(sqrt(direction.x * direction.x + direction.z * direction.z) * sqrt(look.x * look.x + look.z * look.z)));
	
	direction = -pos;
	direction.x += cullPoints[2];
	direction.z += cullPoints[3];
	float angleTwo = acos((direction.x * look.x + direction.z * look.z) / (sqrt(direction.x * direction.x + direction.z * direction.z) * sqrt(look.x * look.x + look.z * look.z)));
	
	//if (angleOne > 1.578 && angleTwo > 1.578) { return; }

	
	float xRatio = glutGet(GLUT_WINDOW_WIDTH) / 1280.0;
	if (xRatio < 0.5) { xRatio = 0.5; }

	

	float distanceOne = sqrt(pow((cullPoints[0] - pos.x), 2) + pow((cullPoints[1] - pos.z), 2));
	float distanceTwo = sqrt(pow((cullPoints[2] - pos.x), 2) + pow((cullPoints[3] - pos.z), 2));

	if (angleOne > 1.1* xRatio && angleTwo > 1.1* xRatio)
	{
		if(!(distanceOne <= 1.2 || distanceTwo <= 1.2)) { return; }
	}
	
	if (distanceOne > distanceTwo) { distanceOne = distanceTwo; }

	int LOD = 0;
	if (distanceOne > 16) { LOD = 3; }
	else if (distanceOne > 8) { LOD = 2; }
	else if (distanceOne > 4) { LOD = 1; }


	DisplayShelfContents(objectList, xPos, xDirection, zPos, zDirection, seed, PsudeoNumGen(seed, 2, xPos + zPos), pos, LOD);

	if (ShelfCulling) { Shelf_1.DisplayObjectWithLighting(SHELF_1); }

}

void DGW::DisplayShelfContents(unsigned int objectList, int seed, glm::vec3 pos)
{
	DisplayShelfContents(objectList, 0, 0, 0, 0, seed, 0, pos, 0);
}

void DGW::DisplayShelfContents(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed, int obj, glm::vec3 pos, int LOD)
{
	//Don't draw contents if shelf not facing player
	if (xDirection != 0)
	{
		if ((xDirection == 1 && xPos > pos[0]) || (xDirection == -1 && xPos < pos[0])) { return; }
	}
	if (zDirection != 0)
	{
		if ((zDirection == 1 && zPos > pos[2]) || (zDirection == -1 && zPos < pos[2])) { return; }
	}

	//If selecting at random from the object list or choosing perticular object
	if (objectList == 0)
	{
		int arraySize = Shelf_Objects.size();
		int i = PsudeoNumGen(seed, arraySize, 0), rot;

		glPushMatrix();
		glTranslatef(-0.725, 0.1, 0.15);
		//s_Box.DisplayObjectWithLighting(S_BOX_1 + (seed + 25) % 3);


		rot = (seed * 7) % 2;
		if (rot == 0) { rot = -1; }
		else { rot = 1; }


		if (obj == 0)
			DisplayBoxes(seed, rot);
		else
			DisplayBoards(seed, rot);

		i = PsudeoNumGen(i+1, arraySize, sqrt(seed));

		int useLOD = LOD;
		int size = Shelf_Objects[i].obj.size();
		if (LOD > size - 1) { useLOD = size-1; }


		glTranslatef(-1.75, 0.5, 0);
		glPushMatrix();
		glRotatef(((seed * 2) % 20) * rot, 0, 1, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glPopMatrix();
		for (int count = 0; count < 3; count++)
		{
			rot = (seed * 7 + count) % 2;
			if (rot == 0) { rot = -1; }
			else { rot = 1; }

			glTranslatef(0.45, 0, 0);
			glPushMatrix();
			glRotatef(((seed * count) % 20) * rot, 0, 1, 0);
			Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
			glPopMatrix();
		}
		glTranslatef(-1.35, 0, -0.4);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		
		
		i = PsudeoNumGen(seed, arraySize, seed);
		useLOD = LOD;
		size = Shelf_Objects[i].obj.size();
		if (LOD > size - 1) { useLOD = size - 1; }

		glTranslatef(-1.35, 0.5, 0.5);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj[useLOD].DisplayObjectWithLighting(Shelf_Objects[i].texture);
		
		glPopMatrix();
		

	}
	else if (objectList == 1)
	{
		s_Movies.DisplayObjectWithLighting(S_MOVIES);
	}
	else if (objectList == 2)
	{
		s_Books.DisplayObjectWithLighting(S_BOOKS);
	}
}

void DGW::DisplayBoxes(int seed, int rot)
{
	for (int count = 0; count < 4; count++)
	{
		rot = (seed * 7 + count) % 2;
		if (rot == 0) { rot = -1; }
		else { rot = 1; }
		glPushMatrix();
		glRotatef(((seed * count) % 30) * rot, 0, 1, 0);
		s_Box.DisplayObjectWithLighting(S_BOX_1 + (seed * count) % 3);
		glPopMatrix();
		glTranslatef(0.45, 0, 0);
	}
}

void DGW::DisplayBoards(int seed, int rot)
{
	for (int count = 0; count < 4; count++)
	{
		rot = (seed * 7 + count) % 2;
		if (rot == 0) { rot = -1; }
		else { rot = 1; }
		glPushMatrix();
		glRotatef(((seed * count) % 10) * rot, 0, 1, 0);
		s_Board.DisplayObjectWithLighting(S_BOARD_1 + (seed * count) % 3);
		glPopMatrix();
		glTranslatef(0.45, 0, 0);
	}
}


int DGW::PsudeoNumGen(int seed, int max, int rand)
{
	seed = (seed + rand) % max;
	return seed;
}

void DGW::DisplayPauseMenuOptions()
{
	glDisable(GL_LIGHTING);

	glm::vec3 pos = { 0.14, 6.5, 15.95 };
	

	if (PMV.m_OptionHighlighted != 0 && PMV.m_PausedMenuChoosen != 2)
	{
		glm::vec3 posTwo = { 0.13, 6.5, 16 };
		posTwo.y = posTwo.y - 1.05 - 0.6 * (PMV.m_OptionHighlighted - 1);
		DisplayIndividualOption(T_MENU_OUTLINE_COLOUR, posTwo, 0.6, 4.1);
	}
	else if (PMV.m_OptionHighlighted != 0 && PMV.m_PausedMenuChoosen == 2)
	{
		glm::vec3 posTwo = { 0.132, 6.5, 16 };
		posTwo.y = posTwo.y - 1.05 - 0.6 * ((PMV.m_OptionHighlighted - 1)/2);
		if (PMV.m_OptionHighlighted == 9)
		{
			posTwo.x = 0.125;
			DisplayIndividualOption(T_MENU_OUTLINE_COLOUR, posTwo, 0.6, 4.1);
		}
		else if (PMV.m_OptionHighlighted % 2 == 1)
		{
			posTwo.z = posTwo.z - 3;
			DisplayIndividualOption(T_MENU_OUTLINE_COLOUR, posTwo, 0.6, 1.1);
		}
		else
		{
			DisplayIndividualOption(T_MENU_OUTLINE_COLOUR, posTwo, 0.6, 1.1);
		}
		
	}

	if (PMV.m_PausedMenuChoosen == 2)
	{
		DisplayOptionsMenu();
	}
	else if (PMV.m_PausedMenuChoosen == 3)
	{
		DisplayUpgradeMenu();
	}
	else if (PMV.m_PausedMenuChoosen == 4)
	{
		DisplayStartScreen();
	}
	else if (PMV.m_PausedMenuChoosen == 5)
	{
		DisplayCredits();
	}
	else if (PMV.m_PausedMenuChoosen == 1)
	{
		//Title
		DisplayIndividualOption(T_PAUSED, pos, 1, 4);

		pos.y = pos.y - 1.1;
		DisplayIndividualOption(T_RESUME, pos, 0.5, 4);

		pos.y = pos.y - 0.6;
		DisplayIndividualOption(T_RESTART_GAME, pos, 0.5, 4);

		pos.y = pos.y - 0.6;
		DisplayIndividualOption(T_OPTIONS, pos, 0.5, 4);

		pos.y = pos.y - 0.6;
		DisplayIndividualOption(T_EXIT, pos, 0.5, 4);

		pos.y = pos.y - 0.6;
		DisplayIndividualOption(T_ACCURACY_TIME, pos, 0.5, 4);
	}
	
	//Background
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0.125, 2.5, 10);
	glVertex3f(0.125, 2.5, 16);
	glVertex3f(0.125, 6.5, 16);
	glVertex3f(0.125, 6.5, 10);
	glEnd();
	glColor3f(1, 1, 1);
	
	DisplayPauseMenuLeaderboard();

	glEnable(GL_LIGHTING);

}

void DGW::DisplayIndividualOption(int texture, glm::vec3 startPos, float yDrop, float width)
{

	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(texture));

	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(startPos.x, startPos.y, startPos.z);
	glTexCoord2f(1, 0);
	glVertex3f(startPos.x, startPos.y, startPos.z - width);
	glTexCoord2f(1, 1);
	glVertex3f(startPos.x, startPos.y - yDrop, startPos.z - width);
	glTexCoord2f(0, 1);
	glVertex3f(startPos.x, startPos.y - yDrop, startPos.z);
	glEnd();


}

void DGW::DisplayUpgradeMenu()
{
	glm::vec3 pos = { 0.135, 6.5, 15.95 };
	
	//Title
	DisplayIndividualOption(T_UPGRADE_MENU, pos, 1, 4);

	pos.y = pos.y - 1.1;
	DisplayIndividualOption(T_ATTACK_SPEED, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_BULLET_SPEED, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_HEALTH, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_MOVEMENT_SPEED, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_BOSS_FIGHT, pos, 0.5, 4);

	float yCoord = 5.7;
	std::string temp;
	temp = "[" + std::to_string(99) + "]";
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(T_MENU_OUTLINE_COLOUR));
	glRasterPos3f(0.2, yCoord, 13.4);
	RenderBitMapString(GLUT_BITMAP_TIMES_ROMAN_24, temp);

	yCoord -= 0.75;
	for (int count = 0; count < 4; count++)
	{
		if		(count == 0) { temp = "[" + std::to_string(1) + "]"; }
		else if (count == 1) { temp = '[' + std::to_string(1) + ']'; }
		else if (count == 2) { temp = '[' + std::to_string(1) + ']'; }
		else if (count == 3) { temp = '[' + std::to_string(1) + ']'; }

		glRasterPos3f(0.2, yCoord, 14.9);
		RenderBitMapString(GLUT_BITMAP_TIMES_ROMAN_24, temp);
		yCoord -= 0.59;
	}
	
}

void DGW::DisplayOptionsMenu()
{
	glm::vec3 pos = { 0.13, 6.5, 15.95 };

	//Title
	DisplayIndividualOption(T_OPTIONS_MENU, pos, 1, 4);

	pos.y = pos.y - 1.1;
	pos.z = 14.95;
	DisplayIndividualOption(T_CAMERA_SENSITIVITY, pos, 0.5, 2);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_MUSIC_VOLUME, pos, 0.5, 2);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_SFX_VOLUME, pos, 0.5, 2);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_DIFFICULTY, pos, 0.5, 2);

	pos.y = pos.y - 0.6;
	pos.z = 15.95;
	DisplayIndividualOption(T_RETURN, pos, 0.5, 4);


	pos.y = 5.4;
	pos.x = 0.134;
	pos.z = 15.94;
	for (int count = 0; count < 4; count++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				DisplayIndividualOption(T_PLUS, pos, 0.5, 1);
			}
			else
			{
				DisplayIndividualOption(T_MINUS, pos, 0.5, 1);
			}

			pos.z = pos.z - 2.97;
		}

		pos.y = pos.y - 0.6;
		pos.z = 15.94;
	}

	float yCoord = 4.98;
	std::string temp;
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(T_MENU_OUTLINE_COLOUR));

	for (int count = 0; count < 4; count++)
	{
		if (count == 0)
		{
			temp = std::to_string(player.GetCamera().GetCameraRotateSpeed());
			temp = '[' + temp.substr(0, 4) + ']';
		}
		else if (count == 1) { temp = '[' + std::to_string(100) + ']'; }
		else if (count == 2) { temp = '[' + std::to_string(100) + ']'; }
		else if (count == 3) { temp = '[' + std::to_string(2) + ']'; }

		glRasterPos3f(0.2, yCoord, 13.35);
		RenderBitMapString(GLUT_BITMAP_TIMES_ROMAN_24, temp);
		yCoord -= 0.58;
	}


}

void DGW::DisplayStartScreen()
{
	glm::vec3 pos = { 0.14, 6.5, 15.95 };

	//Title
	DisplayIndividualOption(T_STARTSCREEN, pos, 1, 4);

	pos.y = pos.y - 1.1;
	DisplayIndividualOption(T_START_GAME, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_OPTIONS, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_CREDITS, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_EXIT, pos, 0.5, 4);
}

void DGW::DisplayCredits()
{
	glm::vec3 pos = { 0.14, 6.5, 15.95 };
	//Title
	DisplayIndividualOption(T_STARTSCREEN, pos, 1, 4);
	pos.y = pos.y - 1.1;

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(219));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0.5);
	glVertex3f(pos.x, pos.y, pos.z);
	glTexCoord2f(1, 0.5);
	glVertex3f(pos.x, pos.y, pos.z - 4);
	glTexCoord2f(1, 0.9);
	glVertex3f(pos.x, pos.y - 1.7, pos.z - 4);
	glTexCoord2f(0, 0.9);
	glVertex3f(pos.x, pos.y - 1.7, pos.z);
	glEnd();


	pos.y = pos.y - 1.8;
	DisplayIndividualOption(T_RETURN, pos, 0.5, 4);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(T_EXIT, pos, 0.5, 4);

}

void DGW::DisplayPauseMenuLeaderboard()
{
	float y = 6.3;
	Record r;
	int max;

	glRasterPos3f(0.2, y, 11.8);
	y -= 0.15;

	if (glutGet(GLUT_ELAPSED_TIME) - PMV.m_LeaderboardSwitchTime > 4000)
	{
		PMV.m_LeaderboardSwitchTime = glutGet(GLUT_ELAPSED_TIME);
		PMV.m_LeaderboardShowsAccuracyOverTime = !PMV.m_LeaderboardShowsAccuracyOverTime;
	}

	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(T_MENU_OUTLINE_COLOUR));
	if (PMV.m_LeaderboardShowsAccuracyOverTime)
	{
		RenderBitMapString(GLUT_BITMAP_HELVETICA_18, "Leaderboards: Accuracy");

		max = LB.GetTopRecordAccuracy(0);
		for (int count = 1; count <= max; count++)
		{
			DisplayIndividualLeaderboardRecord(y, LB.GetTopRecordAccuracy(count), count);
			y -= 0.75;
		}
	}
	else
	{
		RenderBitMapString(GLUT_BITMAP_HELVETICA_18, "Leaderboards: Time");

		max = LB.GetTopRecordTimes(0);
		for (int count = 1; count <= max; count++)
		{
			DisplayIndividualLeaderboardRecord(y, LB.GetTopRecordTimes(count), count);
			y -= 0.75;
		}
	}
	
}

void DGW::DisplayIndividualLeaderboardRecord(float yCoord, int recordIndex, int num)
{
	Record r = LB.GetRecord(recordIndex);
	std::string temp = "[" + std::to_string(num) + "]";

	glRasterPos3f(0.2, yCoord, 11.9);
	yCoord -= 0.15;
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, r.name);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	temp = std::to_string(r.accuracy);
	temp = "Accuracy = " + temp.substr(0, 7) + '%';
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	temp = std::to_string(r.time);
	temp = "Time = " + temp.substr(0, 7) + " seconds";
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, "-------------------");
	glRasterPos3f(0.2, yCoord, 11.7);
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, "-------------------");
}

void DGW::DisplayAnimation()
{
	glPushMatrix();
	glScalef(-1, 1, 1);

	Train.frame = (int)gameRunTime % 6000 / (1000 / 24);
	if (Train.frame > Train.obj.size()-1) { Train.frame = Train.obj.size()-1; }
	Train.obj[Train.frame].DisplayObjectWithLighting(Train.texture);


	
	float result = (int)gameRunTime % 9000 / 1000.0;
	float movement = 5;
	float zPos = -14 + result * movement;

	glPushMatrix();
	glTranslatef(1, 0, zPos);
	DuckPerson.frame = (int)gameRunTime % 1000 / (1000 / 24);
	if (DuckPerson.frame > DuckPerson.obj.size() - 1) { DuckPerson.frame = DuckPerson.obj.size() - 1; }
	DuckPerson.obj[DuckPerson.frame].DisplayObjectWithLighting(DuckPerson.texture);
	glPopMatrix();

	glPushMatrix();
	result = (int)(gameRunTime + 4500) % 9000 / 1000.0;
	zPos = -14 + result * movement;
	glTranslatef(1, 0, zPos);
	DuckPerson.frame = (int)gameRunTime % 1000 / (1000 / 24);
	if (DuckPerson.frame > DuckPerson.obj.size() - 1) { DuckPerson.frame = DuckPerson.obj.size() - 1; }
	DuckPerson.obj[DuckPerson.frame].DisplayObjectWithLighting(DuckPerson.texture);
	glPopMatrix();

	glPushMatrix();
	result = (int)gameRunTime % 12000 / 1000.0;
	zPos = 44 - result * movement;
	glTranslatef(2.2, 0, zPos);
	glRotatef(180, 0, 1, 0);
	DuckPerson.frame = (int)(gameRunTime+5555) % 1000 / (1000 / 24);
	if (DuckPerson.frame > DuckPerson.obj.size() - 1) { DuckPerson.frame = DuckPerson.obj.size() - 1; }
	DuckPerson.obj[DuckPerson.frame].DisplayObjectWithLighting(DuckPerson.texture);
	glPopMatrix();

	glPopMatrix();
}

void DGW::DisplayCashier()
{
	glm::vec3 pos = player.GetCamera().GetPosition();
	glm::vec3 duckLook = {0, 0, 1};
	glm::vec3 duckHeadPos = {5.6, 1.83, 2.1};
	glm::vec3 posVec = pos - duckHeadPos;

	//Body
	glPushMatrix();
	glScalef(-1, 1, 1);
	cashier[0].DisplayObjectWithLighting(T_DUCK_PERSON);
	glPopMatrix();

	//Head
	glPushMatrix();
	float angle = acos((duckLook.x * posVec.x + duckLook.z * posVec.z) / (sqrt(duckLook.x * duckLook.x + duckLook.z * duckLook.z) * sqrt(posVec.x * posVec.x + posVec.z * posVec.z)));
	angle = angle / PI * 180;
	if (angle > 90) { angle = 90; }
	if (duckHeadPos.x > pos.x) { angle = angle * -1; }

	glTranslatef(duckHeadPos.x, duckHeadPos.y, duckHeadPos.z);
	glRotatef(angle, 0, 1, 0);
	glRotatef(30, 1, 0, 0);
	cashier[1].DisplayObjectWithLighting(T_DUCK_PERSON);

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


void DGW::RenderBitMapString(void* font, std::string string)
{
	int size = string.size();

	for (int count = 0; count < size; count++)
	{
		glutBitmapCharacter(font, string[count]);
	}

	return;
}

