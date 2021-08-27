#include "DisplayEXTRAShaysWorld.h"

//The main environment object
Object3D EnvironmentOBJ;


void DisplayExtraArea::DisplayExtension()
{
	//Object test
	glPushMatrix();

	glTranslatef(2613.56, 10000, 9250);
	glRotatef(180, 0, 1, 0);

	EnvironmentOBJ.DisplayObject(TEXT_ENVIRONMENT);


	glPopMatrix();

	DisplayNonBlendObjects();


	return;
}


void DisplayExtraArea::DisplayNonBlendObjects()
{

	DisplayFixedStartUpArea();
	DisplayCanteen();
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
	glTexCoord2f(20, 0);
	glVertex3f(4850, 9000, 10128);
	glTexCoord2f(10, 20);
	glVertex3f(4850, 9000, 6500);
	glTexCoord2f(0.0, 20);
	glVertex3f(4850, 10000.0, 6500);
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
	glVertex3f(2608, 12140.72, 10000 - 1);
	glTexCoord2f(17, 0);
	glVertex3f(28, 12140.72, 10000 - 1);
	glTexCoord2f(17, 15);
	glVertex3f(28, 10000.0, 10000 - 1);
	glTexCoord2f(0.0, 15);
	glVertex3f(2608, 10000.0, 10000 - 1);
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
	
	//Left side roof
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(ROOF_TOP));
	glBegin(GL_POLYGON);
	glTexCoord2f(30, 0.0);
	glVertex3f(28, 11070, 10600);
	glTexCoord2f(30, 30);
	glVertex3f(-14535.94, 11070, 10600);
	glTexCoord2f(0, 30);
	glVertex3f(-14535.94, 12140.72, 13000);
	glTexCoord2f(0.0, 0);
	glVertex3f(28, 12140.72, 13000);
	glEnd();

	//Lower wall directly right of stairs half covered by plants
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4346, 10000, 10600 - 1);
	glTexCoord2f(30, 0);
	glVertex3f(-8126.44, 10000, 10600 - 1);
	glTexCoord2f(30, 7.5);
	glVertex3f(-8126.44, 8980, 10600 - 1);
	glTexCoord2f(0.0, 7.5);
	glVertex3f(-4346, 8980, 10600 - 1);
	glEnd();
	
	//2613.56, 10000, 9250
}

void DisplayExtraArea::DisplayPathways()
{
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENTSIDE_RIGHT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2633, 10001.0 + 1, 8500);
	glTexCoord2f(2, 0);
	glVertex3f(2583, 10001.0 + 1, 8500);
	glTexCoord2f(2, 13);
	glVertex3f(2583, 10001.0 + 1, 10000);
	glTexCoord2f(0.0, 13);
	glVertex3f(2633, 10001.0 + 1, 10000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2613, 10000.0+1, 8500);
	glTexCoord2f(45, 0);
	glVertex3f(-4347, 10000.0+1, 8500);
	glTexCoord2f(45, 90);
	glVertex3f(-4347, 10000.0+1, 15000);
	glTexCoord2f(0.0, 90);
	glVertex3f(2613, 10000.0+1, 15000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(PAVEMENT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-7689, 8980 + 1, 10600);
	glTexCoord2f(45, 0);
	glVertex3f(-16029, 8980 + 1, 10600);
	glTexCoord2f(45, 90);
	glVertex3f(-16029, 8980 + 1, 925);
	glTexCoord2f(0.0, 90);
	glVertex3f(-7689, 8980 + 1, 925);
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
	glTexCoord2f(15, 15);
	glVertex3f(2608, 10000.0, 6500);
	glTexCoord2f(0.0, 15);
	glVertex3f(2608, 12140.72, 6500);
	glEnd();
	
	//Inner side
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WALL_BRICK_XY));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2608, 12140.72, 8500 + 1);
	glTexCoord2f(40, 0);
	glVertex3f(-3392, 12140.72, 8500 + 1);
	glTexCoord2f(40, 15);
	glVertex3f(-3392, 10000.0, 8500 + 1);
	glTexCoord2f(0.0, 15);
	glVertex3f(2608, 10000.0, 8500 + 1);
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

}

void DisplayExtraArea::LeftOfStairs1ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_1_START, LEVEL_1_HEIGHT + 1, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT + 1, 8275);
	glTexCoord2f(1, 6);
	glVertex3f(ROW_2_START, LEVEL_1_HEIGHT + 1, 5575);
	glTexCoord2f(0, 6);
	glVertex3f(ROW_1_START, LEVEL_1_HEIGHT + 1, 5575);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs2ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_2_HEIGHT + 1, 10000);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT + 1, 10000);
	glTexCoord2f(1, 8);
	glVertex3f(ROW_3_START, LEVEL_2_HEIGHT + 1, 5575);
	glTexCoord2f(0, 8);
	glVertex3f(ROW_2_START, LEVEL_2_HEIGHT + 1, 5575);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT + 1, 4675);
	glTexCoord2f(0.0, 1);
	glVertex3f(ROW_2_START, LEVEL_4_HEIGHT + 1, 4675);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT + 1, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT + 1, 3775);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT + 1, 2875);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_2_START, LEVEL_6_HEIGHT + 1, 2875);
	glEnd();
}

void DisplayExtraArea::LeftOfStairs3ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT + 1, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT + 1, 8275);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT + 1, 7375);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT + 1, 7375);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT + 1, 6925);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT + 1, 6925);
	glTexCoord2f(1, 4);
	glVertex3f(ROW_4_START, LEVEL_3_HEIGHT + 1, 5125);
	glTexCoord2f(0, 4);
	glVertex3f(ROW_3_START, LEVEL_3_HEIGHT + 1, 5125);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_4_HEIGHT + 1, 4675);
	glEnd();

	//Fourth top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT + 1, 3775);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_3_START, LEVEL_5_HEIGHT + 1, 3775);
	glEnd();
	
	//Fith top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT + 1, 3775);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT + 1, 3775);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT + 1, 3325);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_3_START, LEVEL_6_HEIGHT + 1, 3325);
	glEnd();
}

void DisplayExtraArea::LeftOfStairs4ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 10000);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT + 1, 10000);
	glTexCoord2f(1, 7);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT + 1, 6025);
	glTexCoord2f(0, 7);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 6025);
	glEnd();
	
	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT + 1, 5125);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_4_HEIGHT + 1, 4675);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_4_HEIGHT + 1, 4675);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_4_START, LEVEL_5_HEIGHT + 1, 4225);
	glEnd();

	//Fourth top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT + 1, 4225);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT + 1, 4225);
	glTexCoord2f(1, 2);
	glVertex3f(ROW_5_START, LEVEL_6_HEIGHT + 1, 3325);
	glTexCoord2f(0, 2);
	glVertex3f(ROW_4_START, LEVEL_6_HEIGHT + 1, 3325);
	glEnd();
}

void DisplayExtraArea::LeftOfStairs5ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 7825);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT + 1, 7825);
	glTexCoord2f(1, 4);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT + 1, 5575);
	glTexCoord2f(0, 4);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 5575);
	glEnd();
	
	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT + 1, 4675);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_6_START, LEVEL_5_HEIGHT + 1, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_5_START, LEVEL_5_HEIGHT + 1, 4225);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs6ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(CONCRETE_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT + 1, 10000);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT + 1, 10000);
	glTexCoord2f(1, 11);
	glVertex3f(ROW_7_START, LEVEL_6_HEIGHT + 1, 4225);
	glTexCoord2f(0, 11);
	glVertex3f(ROW_6_START, LEVEL_6_HEIGHT + 1, 4225);
	glEnd();

}

void DisplayExtraArea::LeftOfStairs7ROW()
{
	//First top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 8275);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 8275);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 7825);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 7825);
	glEnd();

	//Second top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 7375);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 7375);
	glTexCoord2f(1, 3);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 6025);
	glTexCoord2f(0, 3);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 6025);
	glEnd();

	//Third top section
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(WOOD_WALKWAY_TEXTURE));
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 5575);
	glTexCoord2f(1, 0);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 5575);
	glTexCoord2f(1, 1);
	glVertex3f(ROW_7_END, LEVEL_7_HEIGHT + 1, 4225);
	glTexCoord2f(0, 1);
	glVertex3f(ROW_7_START, LEVEL_7_HEIGHT + 1, 4225);
	glEnd();
}
