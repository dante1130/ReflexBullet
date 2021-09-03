#include "DisplayEXTRAShaysWorld.h"

// The main environment object
Object3D EnvironmentOBJ[3];
// Small table object
Object3D SmallTableOBJ;
// Big table object
Object3D BigTableOBJ;
// Umbrella object
Object3D UmbrellaOBJ;

void DisplayExtraArea::DisplayExtension()
{
	// Environment
	glPushMatrix();
		glTranslatef(2613.56, 10000, 9250);
		glRotatef(180, 0, 1, 0);
		EnvironmentOBJ[0].DisplayObject(TEXT_ENVIRONMENT_GENERAL);
		EnvironmentOBJ[1].DisplayObject(TEXT_ENVIRONMENT_STAIRS);
		EnvironmentOBJ[2].DisplayObject(TEXT_ENVIRONMENT_RAILING);

	glPopMatrix();

	// Small tables
	glPushMatrix();
		glTranslatef(-12088, 9000, 3445.9);
		glRotatef(45, 0, 1, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-13467.5, 9000, 3110.74);
		glRotatef(45, 0, 1, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10847.4, 9000, 7313.37);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glPushMatrix();
		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
		glPopMatrix();

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-11750, 9000, 7313.37);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glPushMatrix();
		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9186.56, 9000, 5800);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9186.56, 9000, 6300);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9186.56, 9000, 6800);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9186.56, 9000, 7300);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9186.56, 9000, 7800);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10000, 9000, 7900);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10000, 9000, 6300);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE); 

		glTranslatef(0, 0, 255);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
		
		glTranslatef(0, 0, 255);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-15306, 9150, 4200);
		SmallTableOBJ.DisplayObject(SMALL_TABLE);
	glPopMatrix();

	// Big tables
	glPushMatrix();
		glTranslatef(-13742, 9000, 8645.51);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-12806.5, 9000, 8645.51);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-11871, 9000, 8645.51);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10935.5, 9000, 8645.51);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10000, 9000, 8645.51);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-8324.03, 9000, 5121.88);
		BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	// Umbrella
	glPushMatrix();
		glTranslatef(-9800, 9000, 8645.51);
		UmbrellaOBJ.DisplayObject(UMBRELLA);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-11671, 9000, 8645.51);
		UmbrellaOBJ.DisplayObject(UMBRELLA);
	glPopMatrix();

	DisplayNonBlendObjects();
}

void DisplayExtraArea::DisplayNonBlendObjects()
{
	DisplayFixedStartUpArea();
	DisplayEdgeWallEnvironmentPicutres();
	DisplayCanteen();
	DisplayCanteenRailing();
	DisplayOverhangUnder();
	DisplayCanteenPillars();
	DisplayPathways();
	DisplayWaltersResturant();
	DisplayLeftAreaOfStairs();
}

void DisplayExtraArea::DisplayEdgeWallEnvironmentPicutres()
{
	//far left wall (bathroom)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_TOILETS));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14535.84, 8980, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-15993.94, 8980, 10600);
	glTexCoord2f(1, -1);
	glVertex3f(-15993.94, 10210, 10600);
	glTexCoord2f(0, -1);
	glVertex3f(-14535.84, 10210, 10600);
	glEnd();

	//far back wall left of area B
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_FAR_BACK));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-15993.94, 8980, 6610.63);
	glTexCoord2f(-1, 0);
	glVertex3f(-15993.94, 8980, 10600);
	glTexCoord2f(-1, -1);
	glVertex3f(-15993.94, 10710, 10600);
	glTexCoord2f(0, -1);
	glVertex3f(-15993.94, 10710, 6610.63);
	glEnd();

	//far back left diagonal wall of area B
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_LEFT_DIAGONAL));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-15993.94, 8980, 6610.63);
	glTexCoord2f(1, 0);
	glVertex3f(-17196.639, 8980, 4036.9);
	glTexCoord2f(1, -1);
	glVertex3f(-17196.639, 11210, 4036.9);
	glTexCoord2f(0, -1);
	glVertex3f(-15993.94, 11210, 6610.63);
	glEnd();

	//far back right diagonal wall of area B
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_RIGHT_DIAGONAL));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-17196.639, 8980, 4036.9);
	glTexCoord2f(1, 0);
	glVertex3f(-14550.641, 8980, 1511.5);
	glTexCoord2f(1, -1);
	glVertex3f(-14550.641, 11210, 1511.5);
	glTexCoord2f(0, -1);
	glVertex3f(-17196.639, 11210, 4036.9);
	glEnd();

	//right wall close
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_RIGHT1));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7931.84, 8980, 1511.5);
	glTexCoord2f(1, 0);
	glVertex3f(-4622.44, 8980, 1511.5);
	glTexCoord2f(1, -1);
	glVertex3f(-4622.44, 11210, 1511.5);
	glTexCoord2f(0, -1);
	glVertex3f(-7931.84, 11210, 1511.5);
	glEnd();

	//right wall middle
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_RIGHT3));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-11241.24, 8980, 1511.5);
	glTexCoord2f(1, 0);
	glVertex3f(-7931.84, 8980, 1511.5);
	glTexCoord2f(1, -1);
	glVertex3f(-7931.84, 11210, 1511.5);
	glTexCoord2f(0, -1);
	glVertex3f(-11241.24, 11210, 1511.5);
	glEnd();

	//right wall end
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_RIGHT2));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14550.641, 8980, 1511.5);
	glTexCoord2f(1, 0);
	glVertex3f(-11241.24, 8980, 1511.5);
	glTexCoord2f(1, -1);
	glVertex3f(-11241.24, 11210, 1511.5);
	glTexCoord2f(0, -1);
	glVertex3f(-14550.641, 11210, 1511.5);
	glEnd();



	//close right wall facing backwards
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(EDGE_WALL_CLOSE_RIGHT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4622.44, 8980, 2875);
	glTexCoord2f(-1, 0);
	glVertex3f(-4622.44, 8980, 1511.5);
	glTexCoord2f(-1, -1);
	glVertex3f(-4622.44, 10000, 1511.5);
	glTexCoord2f(0, -1);
	glVertex3f(-4622.44, 10000, 2875);
	glEnd();


}

void DisplayExtraArea::DisplayFixedStartUpArea()
{
	//Lower wall closest to very begining
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_YZ));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(4850, 10000.0, 10128);
	glTexCoord2f(8, 0);
	glVertex3f(4850, 9000, 10128);
	glTexCoord2f(8, 50);
	glVertex3f(4850, 9000, 2875);
	glTexCoord2f(0, 50);
	glVertex3f(4850, 10000.0, 2875);
	glEnd();

	//Wooden beam texture
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(ROOF_PLANKS));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608.0, 12105.72, 6500.0);
	glTexCoord2f(0.0, 250);
	glVertex3f(2608.0, 12105.72, 8100.0 + (128.0 * 273.4));
	glTexCoord2f(15, 250);
	glVertex3f(4716.0, 11335.0, 8100.0 + (128.0 * 257.9));
	glTexCoord2f(15, 0.0);
	glVertex3f(4716.0, 11335.0, 6500.0);
	glEnd();

}

void DisplayExtraArea::DisplayCanteen()
{
	//Entrance inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_COLOUR_1));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 10000);
	glTexCoord2f(1, 0);
	glVertex3f(1318, 12140.72, 10000);
	glTexCoord2f(1, 1);
	glVertex3f(1318, 10000.0, 10000);
	glTexCoord2f(0.0, 1);
	glVertex3f(2608, 10000.0, 10000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_COLOUR_2));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1318, 12140.72, 10000);
	glTexCoord2f(1, 0);
	glVertex3f(28, 12140.72, 10000);
	glTexCoord2f(1, 1);
	glVertex3f(28, 10000.0, 10000);
	glTexCoord2f(0.0, 1);
	glVertex3f(1318, 10000.0, 10000);
	glEnd();



	//Entrance Roof
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(ROOF_TOP));
	glBegin(GL_POLYGON);
	glTexCoord2f(30, 0.0);
	glVertex3f(2613.56, 12140.72, 10000);
	glTexCoord2f(30, 30);
	glVertex3f(28, 12140.72, 10000);
	glTexCoord2f(0, 30);
	glVertex3f(28, 12140.72, 8500);
	glTexCoord2f(0.0, 0);
	glVertex3f(2613.56, 12140.72, 8500);
	glEnd();

	//Entrance roof corner
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(ROOF_TOP));
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0, 20);
	glVertex3f(28, 12140.72, 10000);
	glTexCoord2f(20, 20);
	glVertex3f(28, 12140.72, 8500);
	glTexCoord2f(20, 0);
	glVertex3f(-1500, 12140.72, 8500);
	glEnd();

	//Entrance inner side corner
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_YZ));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 12140.72, 20000);
	glTexCoord2f(15, 0);
	glVertex3f(28, 10000.0, 20000);
	glTexCoord2f(15, 70);
	glVertex3f(28, 10000.0, 10000);
	glTexCoord2f(0.0, 70);
	glVertex3f(28, 12140.72, 10000);
	glEnd();

	
	//Left side open area wall 1
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_WALL1));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 11070, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-1065.5, 11070, 10600);
	glTexCoord2f(1, 1);
	glVertex3f(-1065.5, 10000, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(28, 10000, 10600);
	glEnd();

	//Left side open area wall 2
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_WALL2));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1065.5, 11070, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-2159, 11070, 10600);
	glTexCoord2f(1, 1);
	glVertex3f(-2159, 10000, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-1065.5, 10000, 10600);
	glEnd();

	//Left side open area wall 3
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_WALL3));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2159, 11070, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-3252.5, 11070, 10600);
	glTexCoord2f(1, 1);
	glVertex3f(-3252.5, 10000, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-2159, 10000, 10600);
	glEnd();

	//Left side open area wall 4
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CANTEEN_WALL4));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3252.5, 11070, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-4346, 11070, 10600);
	glTexCoord2f(1, 1);
	glVertex3f(-4346, 10000, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-3252.5, 10000, 10600);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 11070, 10595);
	glTexCoord2f(10, 0);
	glVertex3f(-4346, 11070, 10595);
	glTexCoord2f(10, 1);
	glVertex3f(-4346, 10900, 10595);
	glTexCoord2f(0.0, 1);
	glVertex3f(28, 10900, 10595);
	glEnd();


	//Direct canteen wall further
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WINDOW_LIB_US_A));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 11540.72, 11965);
	glTexCoord2f(5, 0);
	glVertex3f(-14536, 11540.72, 11965);
	glTexCoord2f(5, -1);
	glVertex3f(-14536, 10000, 11965);
	glTexCoord2f(0.0, -1);
	glVertex3f(28, 10000, 11965);
	glEnd();


	//Left side roof
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(ROOF_TOP));
	glBegin(GL_POLYGON);
	glTexCoord2f(30, 0.0);
	glVertex3f(28, 11070, 10600);
	glTexCoord2f(30, 30);
	glVertex3f(-14536, 11070, 10600);
	glTexCoord2f(0, 30);
	glVertex3f(-14536, 11540.72, 11965);
	glTexCoord2f(0.0, 0);
	glVertex3f(28, 11540.72, 11965);
	glEnd();

	//Lower wall directly right of stairs half covered by plants
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALL));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4346, 10000, 10600);
	glTexCoord2f(2.5, 0);
	glVertex3f(-8126.44, 10000, 10600);
	glTexCoord2f(2.5, 1);
	glVertex3f(-8126.44, 8980, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-4346, 8980, 10600);
	glEnd();

	//Hub area wall (door)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STUDENTHUB_DOOR));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-8126.44, 10000, 10600);
	glTexCoord2f(1, 0);
	glVertex3f(-9728.815, 10000, 10600);
	glTexCoord2f(1, 1);
	glVertex3f(-9728.815, 8980, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-8126.44, 8980, 10600);
	glEnd();

	//Hub area wall (wall)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STUDENTHUB_WALL));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-9728.815, 10000, 10600);
	glTexCoord2f(3, 0);
	glVertex3f(-14535.94, 10000, 10600);
	glTexCoord2f(3, 1);
	glVertex3f(-14535.94, 8980, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-9728.815, 8980, 10600);
	glEnd();
	
}

void DisplayExtraArea::DisplayCanteenRailing()
{
	//First section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4343.14, 10375, 10600);
	glTexCoord2f(5, 0);
	glVertex3f(-7610.14, 10375, 10600);
	glTexCoord2f(5, 1);
	glVertex3f(-7610.14, 10075, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-4343.14, 10075, 10600);
	glEnd();

	//First section of wall top
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4343.14, 10375, 10750);
	glTexCoord2f(5, 0);
	glVertex3f(-7610.14, 10375, 10750);
	glTexCoord2f(5, 1);
	glVertex3f(-7610.14, 10375, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-4343.14, 10375, 10600);
	glEnd();

	//First section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4343.14, 10075, 10750);
	glTexCoord2f(5, 0);
	glVertex3f(-7610.14, 10075, 10750);
	glTexCoord2f(5, 1);
	glVertex3f(-7610.14, 10075, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-4343.14, 10075, 10600);
	glEnd();

	//Second section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10375, 10075);
	glTexCoord2f(2, 0);
	glVertex3f(-7610.14, 10375, 10750);
	glTexCoord2f(2, 1);
	glVertex3f(-7610.14, 10075, 10750);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10075, 10075);
	glEnd();

	//Second section of wall top
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10375, 10750);
	glTexCoord2f(2, 0);
	glVertex3f(-7760.14, 10375, 10750);
	glTexCoord2f(2, 1);
	glVertex3f(-7760.14, 10375, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10375, 10075);
	glEnd();

	//Second section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10075, 10750);
	glTexCoord2f(1, 0);
	glVertex3f(-7760.14, 10075, 10750);
	glTexCoord2f(1, 1);
	glVertex3f(-7760.14, 10075, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10075, 10075);
	glEnd();

	//Third section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10375, 10075);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10375, 10075);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 10075, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10075, 10075);
	glEnd();

	//Third section of wall inside
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10375, 10225);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10375, 10225);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 10075, 10225);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10075, 10225);
	glEnd();

	//Third section of wall top
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7760.14, 10375, 10225);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10375, 10225);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 10375, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7760.14, 10375, 10075);
	glEnd();

	//Third section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10075, 10225);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10075, 10225);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 10075, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 10075, 10075);
	glEnd();

	//Fourth section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14385.94, 10375, 10225);
	glTexCoord2f(5, 0);
	glVertex3f(-14385.94, 10375, 12234.4);
	glTexCoord2f(5, 1);
	glVertex3f(-14385.94, 10075, 12234.4);
	glTexCoord2f(0.0, 1);
	glVertex3f(-14385.94, 10075, 10225);
	glEnd();

	//Fourth section of wall inside
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14535.94, 10375, 10075);
	glTexCoord2f(5, 0);
	glVertex3f(-14535.94, 10375, 12234.4);
	glTexCoord2f(5, 1);
	glVertex3f(-14535.94, 10075, 12234.4);
	glTexCoord2f(0.0, 1);
	glVertex3f(-14535.94, 10075, 10075);
	glEnd();

	//Fourth section of wall top
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14385.94, 10375, 12234.4);
	glTexCoord2f(5, 0);
	glVertex3f(-14535.94, 10375, 12234.4);
	glTexCoord2f(5, 5);
	glVertex3f(-14535.94, 10375, 10225);
	glTexCoord2f(0.0, 5);
	glVertex3f(-14385.94, 10375, 10225);
	glEnd();

	//Fourth section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14385.94, 10075, 12234.4);
	glTexCoord2f(1, 0);
	glVertex3f(-14535.94, 10075, 12234.4);
	glTexCoord2f(1, 5);
	glVertex3f(-14535.94, 10075, 10225);
	glTexCoord2f(0.0, 5);
	glVertex3f(-14385.94, 10075, 10225);
	glEnd();

}

void DisplayExtraArea::DisplayOverhangUnder()
{
	//Second section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10000, 10075);
	glTexCoord2f(2, 0);
	glVertex3f(-7610.14, 10000, 10750);
	glTexCoord2f(2, 1);
	glVertex3f(-7610.14, 9750, 10750);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 9750, 10075);
	glEnd();

	//Second section of wall inner
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7760.14, 10000, 10075);
	glTexCoord2f(2, 0);
	glVertex3f(-7760.14, 10000, 10750);
	glTexCoord2f(2, 1);
	glVertex3f(-7760.14, 9750, 10750);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7760.14, 9750, 10075);
	glEnd();

	//Second section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 9750, 10750);
	glTexCoord2f(1, 0);
	glVertex3f(-7760.14, 9750, 10750);
	glTexCoord2f(1, 1);
	glVertex3f(-7760.14, 9750, 10225);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 9750, 10225);
	glEnd();

	//Third section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10000, 10075);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10000, 10075);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 9750, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 9750, 10075);
	glEnd();

	//Third section of wall inside
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 10000, 10225);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 10000, 10225);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 9750, 10225);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 9750, 10225);
	glEnd();

	//Third section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.14, 9750, 10225);
	glTexCoord2f(15, 0);
	glVertex3f(-14535.94, 9750, 10225);
	glTexCoord2f(15, 1);
	glVertex3f(-14535.94, 9750, 10075);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.14, 9750, 10075);
	glEnd();

	//Fourth section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14385.94, 10000, 10225);
	glTexCoord2f(5, 0);
	glVertex3f(-14385.94, 10000, 12234.4);
	glTexCoord2f(5, 1);
	glVertex3f(-14385.94, 9750, 12234.4);
	glTexCoord2f(0.0, 1);
	glVertex3f(-14385.94, 9750, 10225);
	glEnd();

	//Fourth section of wall inside
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14535.94, 10000, 10075);
	glTexCoord2f(5, 0);
	glVertex3f(-14535.94, 10000, 12234.4);
	glTexCoord2f(5, 1);
	glVertex3f(-14535.94, 9750, 12234.4);
	glTexCoord2f(0.0, 1);
	glVertex3f(-14535.94, 9750, 10075);
	glEnd();

	//Fourth section of wall bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-14385.94, 9750, 12234.4);
	glTexCoord2f(1, 0);
	glVertex3f(-14535.94, 9750, 12234.4);
	glTexCoord2f(1, 5);
	glVertex3f(-14535.94, 9750, 10225);
	glTexCoord2f(0.0, 5);
	glVertex3f(-14385.94, 9750, 10225);
	glEnd();



}

void DisplayExtraArea::DisplayCanteenPillars()
{
	float xStart = -4203.14, xEnd, xChange = -1110, xLast = -15990;
	int xWidth = 150;
	xEnd = xStart - xWidth;
		
	while(xStart+xChange > xLast)
	{
		

		//Front face of pillar
		glBindTexture(GL_TEXTURE_2D, tp.GetTexture(MAIN_POST));
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(xStart, 11070, 10597);
		glTexCoord2f(1, 0);
		glVertex3f(xEnd, 11070, 10597);
		glTexCoord2f(1, 5);
		glVertex3f(xEnd, 10000, 10597);
		glTexCoord2f(0.0, 5);
		glVertex3f(xStart, 10000, 10597);
		glEnd();

		//Left face of pillar
		glBindTexture(GL_TEXTURE_2D, tp.GetTexture(MAIN_POST));
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(xStart, 11070, 10597);
		glTexCoord2f(1, 0);
		glVertex3f(xStart, 11070, 10675);
		glTexCoord2f(1, 5);
		glVertex3f(xStart, 10000, 10675);
		glTexCoord2f(0.0, 5);
		glVertex3f(xStart, 10000, 10597);
		glEnd();

		//Right face of pillar
		glBindTexture(GL_TEXTURE_2D, tp.GetTexture(MAIN_POST));
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(xEnd, 11070, 10597);
		glTexCoord2f(1, 0);
		glVertex3f(xEnd, 11070, 10675);
		glTexCoord2f(1, 5);
		glVertex3f(xEnd, 10000, 10675);
		glTexCoord2f(0.0, 5);
		glVertex3f(xEnd, 10000, 10597);
		glEnd();



		xStart = xStart + xChange - xWidth;
		xEnd = xStart - xWidth;
	}


}

void DisplayExtraArea::DisplayPathways()
{
	//Starting pavement
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENTSIDE_RIGHT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2633, 10001.0, 8500);
	glTexCoord2f(2, 0);
	glVertex3f(2583, 10001.0, 8500);
	glTexCoord2f(2, 13);
	glVertex3f(2583, 10001.0, 10000);
	glTexCoord2f(0.0, 13);
	glVertex3f(2633, 10001.0, 10000);
	glEnd();

	//Pavement in out of bounds area next to canteen
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4347, 10001.0, 10600);
	glTexCoord2f(100, 0);
	glVertex3f(-14535.94, 10001.0, 10600);
	glTexCoord2f(100, 20);
	glVertex3f(-14535.94, 10001.0, 11965);
	glTexCoord2f(0.0, 20);
	glVertex3f(-4347, 10001.0, 11965);
	glEnd();

	//Pavement in out of bounds area next to canteen at overhang
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.63, 10001.0, 10075);
	glTexCoord2f(60, 0);
	glVertex3f(-14535.94, 10001.0, 10075);
	glTexCoord2f(60, 10);
	glVertex3f(-14535.94, 10001.0, 10600);
	glTexCoord2f(0.0, 10);
	glVertex3f(-7610.63, 10001.0, 10600);
	glEnd();

	//Pavement in out of bounds area next to canteen at overhang
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALL));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7610.63, 9970, 10075);
	glTexCoord2f(10, 0);
	glVertex3f(-14535.94, 9970, 10075);
	glTexCoord2f(10, 1);
	glVertex3f(-14535.94, 9970, 10600);
	glTexCoord2f(0.0, 1);
	glVertex3f(-7610.63, 9970, 10600);
	glEnd();

	//Upper pavement section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2613, 10000.0, 8500);
	glTexCoord2f(45, 0);
	glVertex3f(-4347, 10000.0, 8500);
	glTexCoord2f(45, 90);
	glVertex3f(-4347, 10000.0, 15000);
	glTexCoord2f(0.0, 90);
	glVertex3f(2613, 10000.0, 15000);
	glEnd();

	//Courtyard
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4389, 8980, 10600);
	glTexCoord2f(45, 0);
	glVertex3f(-16029, 8980, 10600);
	glTexCoord2f(45, 90);
	glVertex3f(-16029, 8980, 925);
	glTexCoord2f(0.0, 90);
	glVertex3f(-4389, 8980, 925);
	glEnd();

	//Grate
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(DRAIN));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-12595.24, 8985, 4932.7);
	glTexCoord2f(1, 0);
	glVertex3f(-12685.24, 8985, 4932.7);
	glTexCoord2f(1, 1);
	glVertex3f(-12685.24, 8985, 4842.7);
	glTexCoord2f(0, 1);
	glVertex3f(-12595.24, 8985, 4842.7);
	glEnd();


}

void DisplayExtraArea::DisplayWaltersResturant()
{
	
	//2608.0, 11088.0, 10000.0

	//Front
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_YZ));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 8500);
	glTexCoord2f(15, 0);
	glVertex3f(2608, 10000.0, 8500);
	glTexCoord2f(15, 30);
	glVertex3f(2608, 10000.0, 2875);
	glTexCoord2f(0.0, 30);
	glVertex3f(2608, 12140.72, 2875);
	glEnd();
	
	//First Inner side lower
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(RESTURANT_STAIRS));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 11070.36, 8500);
	glTexCoord2f(-1, 0);
	glVertex3f(608, 11070.36, 8500);
	glTexCoord2f(-1, 1);
	glVertex3f(608, 10000.0, 8500);
	glTexCoord2f(0.0, 1);
	glVertex3f(2608, 10000.0, 8500);
	glEnd();
	
	//End Inner side upper
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STEP_WINDOW));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 8500);
	glTexCoord2f(4, 0);
	glVertex3f(608, 12140.72, 8500);
	glTexCoord2f(4, 1);
	glVertex3f(608, 11070.36, 8500);
	glTexCoord2f(0.0, 1);
	glVertex3f(2608, 11070.36, 8500);
	glEnd();
	
	//Middle Inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(RESTURANT_COLOUR_SIDE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(608, 12140.72, 8500);
	glTexCoord2f(-1, 0);
	glVertex3f(-1392, 12140.72, 8500);
	glTexCoord2f(-1, 1);
	glVertex3f(-1392, 10000.0, 8500);
	glTexCoord2f(0.0, 1);
	glVertex3f(608, 10000.0, 8500);
	glEnd();

	//End Inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STEP_WINDOW));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1392, 12140.72, 8500);
	glTexCoord2f(4, 0);
	glVertex3f(-3392, 12140.72, 8500);
	glTexCoord2f(4, 1);
	glVertex3f(-3392, 11070.36, 8500);
	glTexCoord2f(0.0, 1);
	glVertex3f(-1392, 11070.36, 8500);
	glEnd();

	//End Inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(RESTURANT_DINNING));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1392, 11070.36, 8500);
	glTexCoord2f(1, 0);
	glVertex3f(-3392, 11070.36, 8500);
	glTexCoord2f(1, 1);
	glVertex3f(-3392, 10000.0, 8500);
	glTexCoord2f(0.0, 1);
	glVertex3f(-1392, 10000.0, 8500);
	glEnd();


	//Back side top
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STEP_WINDOW));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 12140.72, 8500);
	glTexCoord2f(-10, 0);
	glVertex3f(-3386.44, 12140.72, 2875);
	glTexCoord2f(-10, -1);
	glVertex3f(-3386.44, 11070.36, 2875);
	glTexCoord2f(0.0, -1);
	glVertex3f(-3386.44, 11070.36, 8500);
	glEnd();


	//Back side bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 11070.36, 8500);
	glTexCoord2f(7.5, 0);
	glVertex3f(-3386.44, 11070.36, 6500);
	glTexCoord2f(7.5, 7.5);
	glVertex3f(-3386.44, 10000.0, 6500);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(-3386.44, 10000.0, 8500);
	glEnd();

	//Back side bottom
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(RESTURANT_DINNING));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 11070.36, 6500);
	glTexCoord2f(3, 0);
	glVertex3f(-3386.44, 11070.36, 2875);
	glTexCoord2f(3, 1);
	glVertex3f(-3386.44, 10000.0, 2875);
	glTexCoord2f(0.0, 1);
	glVertex3f(-3386.44, 10000.0, 6500);
	glEnd();
	
	//Wood walkway
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 10000.0, 2875);
	glTexCoord2f(1, 0);
	glVertex3f(-4346.44, 10000.0, 2875);
	glTexCoord2f(1, 10);
	glVertex3f(-4346.44, 10000.0, 8500);
	glTexCoord2f(0.0, 10);
	glVertex3f(-3386.44, 10000.0, 8500);
	glEnd();

	//Back end
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 10750, 2875);
	glTexCoord2f(5, 0);
	glVertex3f(-4622.44, 10750, 2875);
	glTexCoord2f(5, 5);
	glVertex3f(-4622.44, 10000, 2875);
	glTexCoord2f(0.0, 5);
	glVertex3f(-3386.44, 10000, 2875);
	glEnd();

}

void DisplayExtraArea::DisplayLeftAreaOfStairs()
{
	LeftOfStairs1ROW();
	LeftOfStairs2ROW();
	LeftOfStairs3ROW();
	LeftOfStairs4ROW();
	LeftOfStairs5ROW();
	LeftOfStairs6ROW();
	LeftOfStairs7ROW();

	//Flat wall at back side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4622.44, 10051, 2875);
	glTexCoord2f(4, 0);
	glVertex3f(-4622.44, 10051, 8275);
	glTexCoord2f(4, 2);
	glVertex3f(-4622.44, 8980, 8275);
	glTexCoord2f(0.0, 2);
	glVertex3f(-4622.44, 8980, 2875);
	glEnd();

	//Flat wall at back side (side facing resturant)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4346.44, 10051, 2875);
	glTexCoord2f(4, 0);
	glVertex3f(-4346.44, 10051, 8275);
	glTexCoord2f(4, 0.05);
	glVertex3f(-4346.44, 10000, 8275);
	glTexCoord2f(0.0, 0.05);
	glVertex3f(-4346.44, 10000, 2875);
	glEnd();

	//Flat wall at back side (side facing up)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4622.44, 10051, 2875);
	glTexCoord2f(4, 0);
	glVertex3f(-4622.44, 10051, 8275);
	glTexCoord2f(4, 0.5);
	glVertex3f(-4346.44, 10051, 8275);
	glTexCoord2f(0.0, 0.5);
	glVertex3f(-4346.44, 10051, 2875);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs1ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_1_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT, 8275);
	glTexCoord2f(1, 6);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT, 5575);
	glTexCoord2f(0, 6);
	glVertex3f(ROW_1_START, LEVEL_1_HEIGHT, 5575);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_3_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT, 8275);
	glTexCoord2f(1, 6);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT, 5575);
	glTexCoord2f(0, 6);
	glVertex3f(ROW_2_START, LEVEL_3_HEIGHT, 5575);
	glEnd();

	//Second top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_4_HEIGHT, 5575);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_1_START, LEVEL_1_HEIGHT, 5575);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT, 5575);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 5575);
	glEnd();

	//Third top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_5_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_1_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, LEVEL_5_HEIGHT, 5125);
	glEnd();

	//Fourth top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_1_START, LEVEL_4_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 4225);
	glEnd();

	//Fifth top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_7_HEIGHT, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_1_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, LEVEL_7_HEIGHT, 3775);
	glEnd();

	//Sixth top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_1_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, 8980, 3325);
	glEnd();


}

void DisplayExtraArea::LeftOfStairs2ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_2_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT, 8275);
	glTexCoord2f(1, 6);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT, 5575);
	glTexCoord2f(0, 6);
	glVertex3f(ROW_2_START, LEVEL_2_HEIGHT, 5575);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT, 8275);
	glTexCoord2f(1, 6);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT, 5575);
	glTexCoord2f(0, 6);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 5575);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0.0, 1);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 4675);
	glEnd();

	//Second top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 4225);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 2875);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 2875);
	glEnd();

	//Third top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 2875);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, 8980, 2875);
	glEnd();

	//Fourth top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 2875);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_2_START, 8980, 2875);
	glEnd();

	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 5575);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_2_HEIGHT, 5575);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT, 5575);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 5575);
	glEnd();

	//Second end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_5_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 5125);
	glEnd();

	//Third end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 4225);
	glEnd();

	//Fourth end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_7_HEIGHT, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_7_HEIGHT, 3775);
	glEnd();

	//Fifth end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, 8980, 2875);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT, 2875);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 2875);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, 8980, 2875);
	glEnd();
	


}

void DisplayExtraArea::LeftOfStairs3ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 8275);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 7375);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 7375);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 8275);
	glTexCoord2f(1, 7);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(0, 7);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 5125);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 6925);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 6925);
	glTexCoord2f(1, 4);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(0, 4);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 5125);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4675);
	glEnd();

	//Second top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_7_HEIGHT, 3775);
	glEnd();

	//Fourth top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 3775);
	glEnd();
	
	//Fith top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 3325);
	glEnd();


	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT, 5125);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 5125);
	glEnd();

	//Second end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 4675);
	glEnd();

	//Third end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_7_HEIGHT, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_7_HEIGHT, 3775);
	glEnd();

	//Fourth end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, 8980, 3325);
	glEnd();



}

void DisplayExtraArea::LeftOfStairs4ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 8275);
	glTexCoord2f(1, 5);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 6025);
	glTexCoord2f(0, 5);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 6025);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 8275);
	glTexCoord2f(1, 8);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0, 8);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 4675);
	glEnd();
	
	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 4675);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 4225);
	glEnd();

	//Fourth top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 3325);
	glEnd();


	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 4675);
	glEnd();

	//Second end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_5_START, LEVEL_7_HEIGHT, 4225);
	glEnd();

	//Third end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_5_START, 8980, 3325);
	glEnd();


}

void DisplayExtraArea::LeftOfStairs5ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 7825);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 7825);
	glTexCoord2f(1, 4);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 5575);
	glTexCoord2f(0, 4);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 5575);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_6_START, LEVEL_7_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 8275);
	glTexCoord2f(1, 9);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(0, 9);
	glVertex3f(ROW_6_START, LEVEL_7_HEIGHT, 4225);
	glEnd();
	
	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4225);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_6_START, 8980, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_6_START, 8980, 3325);
	glEnd();

	
	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_6_START, LEVEL_7_HEIGHT, 4225);
	glEnd();

	//Second end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, 8980, 3325);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_6_START, 8980, 3325);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs6ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 8275);
	glTexCoord2f(1, 9);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(0, 9);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 4225);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, 8710, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 8275);
	glTexCoord2f(1, 9);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(0, 9);
	glVertex3f(ROW_7_START, 8710, 4225);
	glEnd();

	//Second top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, 8710, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_START, 8710, 3775);
	glEnd();

	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, 8980, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_6_START, 8980, 4225);
	glEnd();

	//Second end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, 8980, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT, 3775);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_6_START, 8980, 3775);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs7ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 8275);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 7825);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 7825);
	glEnd();

	//First top depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_END, 8710, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 8275);
	glTexCoord2f(1, 9);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(0, 9);
	glVertex3f(ROW_7_END, 8710, 4225);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 7375);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 7375);
	glTexCoord2f(1, 3);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 6025);
	glTexCoord2f(0, 3);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 6025);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 5575);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 5575);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 4225);
	glEnd();

	//First end depth section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, 8830, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_END, 8830, 4225);
	glEnd();
}
