#include "DisplayEXTRAShaysWorld.h"

// The main environment object
Object3D EnvironmentOBJ;
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
		EnvironmentOBJ.DisplayObject(TEXT_ENVIRONMENT);
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
		glTranslatef(-11871, 9000, 8645.51);s
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

	DisplayNonBlendObjects();
}

void DisplayExtraArea::DisplayNonBlendObjects()
{
	DisplayFixedStartUpArea();
	DisplayCanteen();
	DisplayCanteenRailing();
	DisplayPathways();
	DisplayWaltersResturant();
	DisplayLeftAreaOfStairs();
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
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 10000);
	glTexCoord2f(17, 0);
	glVertex3f(28, 12140.72, 10000);
	glTexCoord2f(17, 15);
	glVertex3f(28, 10000.0, 10000);
	glTexCoord2f(0.0, 15);
	glVertex3f(2608, 10000.0, 10000);
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

	//Left side open area wall
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 11070, 10600);
	glTexCoord2f(30, 0);
	glVertex3f(-4346, 11070, 10600);
	glTexCoord2f(30, 7.5);
	glVertex3f(-4346, 10000, 10600);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(28, 10000, 10600);
	glEnd();
	
	//Direct canteen wall close
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(28, 11540.72, 11965);
	glTexCoord2f(30, 0);
	glVertex3f(-4346, 11540.72, 11965);
	glTexCoord2f(30, 7.5);
	glVertex3f(-4346, 10000, 11965);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(28, 10000, 11965);
	glEnd();

	//Direct canteen wall further
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4346, 11540.72, 11965);
	glTexCoord2f(60, 0);
	glVertex3f(-14536, 11540.72, 11965);
	glTexCoord2f(60, 7.5);
	glVertex3f(-14536, 10000, 11965);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(-4346, 10000, 11965);
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
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4346, 10000, 10600);
	glTexCoord2f(30, 0);
	glVertex3f(-8126.44, 10000, 10600);
	glTexCoord2f(30, 7.5);
	glVertex3f(-8126.44, 8980, 10600);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(-4346, 8980, 10600);
	glEnd();

	//Hub area wall (glass)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-8126.44, 10000, 10600);
	glTexCoord2f(60, 0);
	glVertex3f(-14535.94, 10000, 10600);
	glTexCoord2f(60, 7.5);
	glVertex3f(-14535.94, 8980, 10600);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(-8126.44, 8980, 10600);
	glEnd();
	
}

void DisplayExtraArea::DisplayCanteenRailing()
{
	//First section of wall outer
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
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
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
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
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_YZ));
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
	glVertex3f(-7610.63, 10001.0, 10000);
	glTexCoord2f(60, 0);
	glVertex3f(-14535.94, 10001.0, 10000);
	glTexCoord2f(60, 10);
	glVertex3f(-14535.94, 10001.0, 10600);
	glTexCoord2f(0.0, 10);
	glVertex3f(-7610.63, 10001.0, 10600);
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
	
	//Inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 8500 + 1);
	glTexCoord2f(40, 0);
	glVertex3f(-3392, 12140.72, 8500);
	glTexCoord2f(40, 15);
	glVertex3f(-3392, 10000.0, 8500);
	glTexCoord2f(0.0, 15);
	glVertex3f(2608, 10000.0, 8500);
	glEnd();

	//Back side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_YZ));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-3386.44, 12140.72, 8500);
	glTexCoord2f(-40, 0);
	glVertex3f(-3386.44, 12140.72, 2875);
	glTexCoord2f(-40, -15);
	glVertex3f(-3386.44, 10000.0, 2875);
	glTexCoord2f(0.0, -15);
	glVertex3f(-3386.44, 10000.0, 8500);
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
}
