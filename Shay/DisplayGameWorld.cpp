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

float startFrameTime = -1;
int frameCountPos = 0;
float frames = 0;
int lastFrameTime;

bool wireFrame = false;
bool performanceMetric = true;
bool m_PausedGame = false;
bool m_floatMoving = false;
bool m_LeaderboardShowsAccuracyOverTime = true;
GLfloat m_LeaderboardSwitchTime = 0;


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

	if (m_PausedGame && !m_floatMoving)
	{
		DisplayPauseMenuOptions();
	}
	else
	{
		DGO::DisplayGunBullets(player.GetGun());
	}

	Lighting::UpdateLighting();
	glutSwapBuffers();
}

void DGW::GetSize(int& width, int& height)
{
	GetScreenSize(width, height);
}

void DGW::DisplayShelves()
{
	glPushMatrix();
	//Shelves facing +y in blender at the back of the shop
	glTranslatef(10, 0, 0.5);
	DisplayShelfContents(1, 0);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 1);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 124);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 14);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 23);
	glTranslatef(-4, 0, 4);
	DisplayShelfContents(1, 0, 0, 5, 1, 8, 0);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(1, 0, 0, 5, 1, 9, 1);
	glTranslatef(0, 0, 4);
	DisplayShelfContents(0, 0, 0, 9, 1, 0, 0);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(0, 0, 0, 9, 1, 4, 1);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(0, 0, 0, 9, 1, 2, 0);
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	glScalef(0.5, 1, 1);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();
	//switch sides
	glTranslatef(0, 0, 10);
	DisplayShelfContents(0, 0, 0, 19, 1, 10, 1);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(0, 0, 0, 19, 1, 100, 0);
	glTranslatef(0, 0, 4);
	DisplayShelfContents(2, 0, 0, 23, 1, 14, 1);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(2, 0, 0, 23, 1, 6, 0);

	//Shelves facing -y in blender at the back of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	DisplayShelfContents(2, 2);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(2, 7);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(2, 26);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(2, 21);
	glTranslatef(4, 0, 4);
	DisplayShelfContents(0, 0, 0, 21, -1, 20, 1);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(0, 0, 0, 21, -1, 211, 0);
	glTranslatef(0, 0, 4);
	DisplayShelfContents(0, 0, 0, 17, -1, 35, 1);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(0, 0, 0, 17, -1, 57, 0);
	glTranslatef(-2, 0, 0);
	DisplayShelfContents(0, 0, 0, 17, -1, 59, 1);
	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	glScalef(0.5, 1, 1);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();
	//Switch sides
	glTranslatef(0, 0, 10);
	DisplayShelfContents(1, 0, 0, 7, -1, 27, 0);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 0, 0, 7, -1, 0, 1);
	glTranslatef(0, 0, 4);
	DisplayShelfContents(1, 0, 0, 3, -1, 2, 0);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 0, 0, 3, -1, 1, 1);

	//Back shop wall - left to right 
	glRotatef(90, 0, 1, 0);
	glTranslatef(-2.5, 0, -7.5);
	DisplayShelfContents(1, 90);
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();

	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 91);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 97);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 54);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(1, 12, 1, 0, 0, 24, 0);
	glTranslatef(8, 0, 0);
	DisplayShelfContents(2, 12, 1, 0, 0, 756, 1);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(2, 225);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(2, 25);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(2, 156);
	glTranslatef(2, 0, 0);
	DisplayShelfContents(2, 17);
	glPushMatrix();
	glTranslatef(1, 0, 0);
	Shelf_1.DisplayObjectWithLighting(SHELF_1); //Cover up corner shelf
	glPopMatrix();

	//Middle back
	glTranslatef(-15, 0, 3);
	DisplayShelfContents(0, 16, -1, 0, 0, 19, 0);
	glTranslatef(6, 0, 0);
	DisplayShelfContents(0, 16, -1, 0, 0, 12, 1);
	glPopMatrix();

	//Front of shop shelves
	glPushMatrix();
	//Shelves facing -y in blender at the front of the shop
	glTranslatef(4, 0, 6.5);
	DisplayShelfContents(0, 0, 0, 7, 1, 11, 1);
	glTranslatef(0, 0, 14);
	DisplayShelfContents(0, 0, 0, 21, 1, 10, 1);

	//Shelves facing +y in blender at the front of the shop
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, -3);
	DisplayShelfContents(0, 0, 0, 23, -1, 68, 0);
	glTranslatef(-4, 0, 0);
	DisplayShelfContents(0, 0, 0, 23, -1, 0, 0);
	glTranslatef(4, 0, 4);
	DisplayShelfContents(0, 0, 0, 19, -1, 56, 0);
	glTranslatef(0, 0, 14);
	DisplayShelfContents(0, 0, 0, 5, -1, 80, 0);

	//Shelves facing front of store
	glRotatef(90, 0, 1, 0);
	glTranslatef(0.5, 0, 1.5);
	DisplayShelfContents(0, 2, -1, 0, 0, 25, 1);
	glTranslatef(14, 0, 0);
	DisplayShelfContents(0, 2, -1, 0, 0, 66, 1);
	glTranslatef(5, 0, -1);
	DisplayShelfContents(0, 3, -1, 0, 0, 77, 0);
	glTranslatef(0, 0, -4);
	DisplayShelfContents(0, 7, -1, 0, 0, 88, 1);
	
	//Shelves facing back of store
	glRotatef(180, 0, 1, 0);
	glTranslatef(0, 0, 1);
	DisplayShelfContents(0, 9, 1, 0, 0, 99, 0);
	glTranslatef(0, 0, -4);
	DisplayShelfContents(0, 5, 1, 0, 0, 44, 1);

	glPopMatrix();


}

void DGW::DisplayShelfContents(unsigned int objectList, int seed)
{
	DisplayShelfContents(objectList, 0, 0, 0, 0, seed, 0);
}

void DGW::DisplayShelfContents(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed, int obj)
{
	Shelf_1.DisplayObjectWithLighting(SHELF_1);

	glm::vec3 pos = player.GetCamera().GetPosition();

	//Don't drow contents if shelf not facing player
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

		if (obj == 0)
			DisplayBoxes(seed, rot);
		else
			DisplayBoards(seed, rot);

		i = PsudeoNumGen(i+1, arraySize, seed);
		glTranslatef(-1.75, 0.5, 0);
		glPushMatrix();
		glRotatef(((seed * 2) % 20) * rot, 0, 1, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glPopMatrix();
		for (int count = 0; count < 3; count++)
		{
			rot = (seed * 7 + count) % 2;
			if (rot == 0) { rot = -1; }
			else { rot = 1; }

			glTranslatef(0.45, 0, 0);
			glPushMatrix();
			glRotatef(((seed * count) % 20) * rot, 0, 1, 0);
			Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
			glPopMatrix();
		}
		glTranslatef(-1.35, 0, -0.4);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		
		
		i = PsudeoNumGen(i+5, arraySize, 0);
		glTranslatef(-1.35, 0.5, 0.5);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		glTranslatef(0.45, 0, 0);
		Shelf_Objects[i].obj.DisplayObjectWithLighting(Shelf_Objects[i].texture);
		
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
	seed = (seed + (seed * 3) + rand) % max;
	return seed;
}

void DGW::DisplayPauseMenuOptions()
{
	glDisable(GL_LIGHTING);

	glm::vec3 pos = { 0.13, 6.5, 16 };

	glBegin(GL_POLYGON);
	glVertex3f(pos.x, pos.y - 1, pos.z - 4);
	glVertex3f(pos.x, pos.y - 1, pos.z);
	glVertex3f(pos.x, pos.y, pos.z);
	glVertex3f(pos.x, pos.y, pos.z - 4);
	glEnd();

	pos.y = pos.y - 1.1;
	DisplayIndividualOption(1, pos);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(1, pos);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(1, pos);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(1, pos);

	pos.y = pos.y - 0.6;
	DisplayIndividualOption(1, pos);


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

void DGW::DisplayIndividualOption(int texture, glm::vec3 startPos)
{
	glBegin(GL_POLYGON);
	glVertex3f(startPos.x, startPos.y - 0.5, startPos.z - 4);
	glVertex3f(startPos.x, startPos.y - 0.5, startPos.z);
	glVertex3f(startPos.x, startPos.y, startPos.z);
	glVertex3f(startPos.x, startPos.y, startPos.z - 4);
	glEnd();


}

void DGW::DisplayPauseMenuLeaderboard()
{
	float y = 6.3;
	Record r;
	int max;

	glRasterPos3f(0.2, y, 11.9);
	y -= 0.15;

	if (glutGet(GLUT_ELAPSED_TIME) - m_LeaderboardSwitchTime > 4000)
	{
		m_LeaderboardSwitchTime = glutGet(GLUT_ELAPSED_TIME);
		m_LeaderboardShowsAccuracyOverTime = !m_LeaderboardShowsAccuracyOverTime;
	}


	if (m_LeaderboardShowsAccuracyOverTime)
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

	glRasterPos3f(0.2, yCoord, 11.95);
	yCoord -= 0.15;
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, r.name);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	temp = "Accuracy = " + std::to_string(r.accuracy) + "%";
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	temp = "Time = " + std::to_string(r.time) + " seconds";
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, temp);

	glRasterPos3f(0.2, yCoord, 11.8);
	yCoord -= 0.15;
	RenderBitMapString(GLUT_BITMAP_HELVETICA_18, "-------------------");
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

