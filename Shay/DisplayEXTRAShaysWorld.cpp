#include "DisplayEXTRAShaysWorld.h"

// The main environment object
Object3D EnvironmentOBJ[3];
// Small table object
Object3D SmallTableOBJ;
// Big table object
Object3D BigTableOBJ;
// Umbrella object
Object3D UmbrellaOBJ;
// Chair object
Object3D ChairOBJ;
// Bench object
Object3D BenchOBJ;
// Bush object
Object3D BushOBJ;
// Bin object
Object3D BinOBJ;
// Tree object
Object3D TreeOBJ;


//Sliding door values
bool doorOpen = false; //if it is open or closed
float doorXPos = -8927.6275; //the xPosition of the door
int doorSpeed = 1000; //how fast it opens/closes // time it takes in milliseconds
float doorTime;

void DisplayExtraArea::DisplayExtension()
{
	// Environment
	{
		glPushMatrix();
		glTranslatef(2613.56, 10000, 9250);
		glRotatef(180, 0, 1, 0);
		EnvironmentOBJ[0].DisplayObject(TEXT_ENVIRONMENT_GENERAL);
		EnvironmentOBJ[1].DisplayObject(TEXT_ENVIRONMENT_STAIRS);
		EnvironmentOBJ[2].DisplayObject(TEXT_ENVIRONMENT_RAILING);
		glPopMatrix();
	}
	
	
	// Chair
	{
		// For diagonal chair 1
		glPushMatrix();
		glTranslatef(-11985, 9000, 3565);
		glRotatef(45, 0, 1, 0); 
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11977, 9000, 3335);
		glRotatef(135, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12216, 9000, 3330);
		glRotatef(-135, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12200, 9000, 3565);
		glRotatef(-45, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		// For diagonal chair 2
		glPushMatrix();
		glTranslatef(-13378, 9000, 3215);
		glRotatef(45, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-13352, 9000, 3007);
		glRotatef(135, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-13580, 9000, 3007);
		glRotatef(-135, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-13580, 9000, 3199);
		glRotatef(-45, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		// For normal tables
		glPushMatrix();
		glTranslatef(-9178.11, 9000, 7669.21);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9049.22, 9000, 7800);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9188.7, 9000, 7952.2);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9340.37, 9000, 7800);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-9049.22, 9000, 7300);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9340.37, 9000, 7300);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-9198, 9000, 6930);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8939, 9000, 6930);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8790, 9000, 6812);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8934, 9000, 6649.80);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9179, 9000, 6649.80);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9341, 9000, 6785);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-9048, 9000, 6300);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9344, 9000, 6300);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-9177.8, 9000, 5914);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9050, 9000, 5800);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-9187, 9000, 5628);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9340, 9000, 5800);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-10002, 9000, 8061);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9852, 9000, 7900);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10005, 9000, 7750);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10172, 9000, 7900);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-11097, 9000, 7441);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10843, 9000, 7441);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10582, 9000, 7441);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10448, 9000, 7308);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10602, 9000, 7159);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10856, 9000, 7159);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11112, 9000, 7159);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11250, 9000, 7317);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		//
		glPushMatrix();
		glTranslatef(-12011, 9000, 7440);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11752, 9000, 7440);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11598, 9000, 7315);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11755, 9000, 7157);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12011, 9000, 7157);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12152, 9000, 7307);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();
		
		//
		glPushMatrix();
		glTranslatef(-10245, 9000, 6950);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10007, 9000, 6950);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9848, 9000, 6806);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9848, 9000, 6559);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9848, 9000, 6307);
		glRotatef(90, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9997, 9000, 6144);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10257, 9000, 6144);
		glRotatef(180, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10405, 9000, 6287);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10405, 9000, 6553);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();
		glPushMatrix();

		glTranslatef(-10405, 9000, 6802);
		glRotatef(270, 0, 1, 0);
		ChairOBJ.DisplayObject(CHAIR);
		glPopMatrix();
	}

	// Small tables
	{
		// Diagonal chair 1
		glPushMatrix();
		glTranslatef(-12088, 9000, 3445.9);
		glRotatef(45, 0, 1, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Diagonal chair 2
		glPushMatrix();
		glTranslatef(-13467.5, 9000, 3110.74);
		glRotatef(45, 0, 1, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10847.4, 9000, 7313.37);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glPushMatrix();
		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11750, 9000, 7313.37);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glPushMatrix();
		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9186.56, 9000, 5800);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9186.56, 9000, 6300);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9186.56, 9000, 6800);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9186.56, 9000, 7300);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-9186.56, 9000, 7800);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10000, 9000, 7900);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10000, 9000, 6300);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(0, 0, 255);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(0, 0, 255);
		SmallTableOBJ.DisplayObject(BIG_TABLE);

		glTranslatef(-255, 0, 0);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-15306, 9150, 4200);
		SmallTableOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();
	}
	
	// Bench
	{
		// Bench 1 (Furthest)
		glPushMatrix();
		glTranslatef(-13950, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-13534, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Bench 2
		glPushMatrix();
		glTranslatef(-13014.5, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-12598.5, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Bench 3
		glPushMatrix();
		glTranslatef(-12079, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Bench 4
		glPushMatrix();
		glTranslatef(-11143.5, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-10727.5, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Bench 5 (Nearest bench)
		glPushMatrix();
		glTranslatef(-10208, 9000, 8645.51);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		// Bench 6 (Non-adjacent bench)
		glPushMatrix();
		glTranslatef(-8532.03, 9000, 5121.88);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-8116.03, 9000, 5121.88);
		BenchOBJ.DisplayObject(BIG_TABLE);
		glPopMatrix();
	}

	// Big tables
	{
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
	}
	
	// Umbrella
	{
		glPushMatrix();
		glTranslatef(-9800, 9000, 8645.51);
		UmbrellaOBJ.DisplayObject(UMBRELLA);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-11671, 9000, 8645.51);
		UmbrellaOBJ.DisplayObject(UMBRELLA);
		glPopMatrix();
	}
	
	DisplayResturantObjects();
	DisplayBushes();
	DisplayNonBlendObjects();
	FixingOverextendedCollisionBoxes();
	DisplayBins();
}

void DisplayExtraArea::DisplayResturantObjects()
{
	//Resturant area
	glPushMatrix();
	glTranslatef(-3600, 10000, 8350);
	SmallTableOBJ.DisplayObject(BIG_TABLE);

	glPushMatrix();
	glTranslatef(-250, 50, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-12, 1, 0, 0);
	BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	glTranslatef(-350, 0, -2000);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glPushMatrix();
	glTranslatef(0, 0, 150);
	ChairOBJ.DisplayObject(CHAIR);
	glTranslatef(0, 0, -300);
	glRotatef(180, 0, 1, 0);
	ChairOBJ.DisplayObject(CHAIR);
	glPopMatrix();

	glTranslatef(200, 0, -1000);
	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(0, 0, 150);
	ChairOBJ.DisplayObject(CHAIR);
	glTranslatef(0, 0, -300);
	glRotatef(180, 0, 1, 0);
	ChairOBJ.DisplayObject(CHAIR);
	glPopMatrix();

	glTranslatef(-200, 0, -500);
	glPushMatrix();
	glRotatef(78, 0, 1, 0);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(0, 0, 150);
	ChairOBJ.DisplayObject(CHAIR);
	glTranslatef(0, 0, -300);
	glRotatef(180, 0, 1, 0);
	ChairOBJ.DisplayObject(CHAIR);
	glPopMatrix();

	glTranslatef(200, 0, -1000);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glPushMatrix();
	glTranslatef(0, 0, 150);
	ChairOBJ.DisplayObject(CHAIR);
	glTranslatef(0, 0, -300);
	glRotatef(180, 0, 1, 0);
	ChairOBJ.DisplayObject(CHAIR);
	glPopMatrix();

	glTranslatef(-400, 0, -500);
	glRotatef(166, 0, 1, 0);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(0, 0, 150);
	ChairOBJ.DisplayObject(CHAIR);
	glTranslatef(0, 0, -300);
	glRotatef(180, 0, 1, 0);
	ChairOBJ.DisplayObject(CHAIR);

	glPopMatrix();

}

void DisplayExtraArea::FixingOverextendedCollisionBoxes()
{
	//Right area C
	glPushMatrix();
	glTranslatef(-9329, 8980, 4444);
	glRotatef(90, 0, 1, 0);
	BigTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	//Left area C
	glPushMatrix();
	glTranslatef(-10836, 8980, 4444);
	glRotatef(90, 0, 1, 0);
	BenchOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	//Right area B
	glPushMatrix();
	glTranslatef(-14816, 9130, 2900);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(-250, 0, 0);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(-250, 0, 0);
	SmallTableOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	//Back center area B
	glPushMatrix();
	glTranslatef(-16400, 9130, 4066);
	BenchOBJ.DisplayObject(BIG_TABLE);
	glTranslatef(0, 0, 900);
	BenchOBJ.DisplayObject(BIG_TABLE);
	glPopMatrix();

	//Left area B
	glPushMatrix();
	glTranslatef(-15942, 9130, 5880);
	ChairOBJ.DisplayObject(CHAIR);
	glPopMatrix();


}

void DisplayExtraArea::DisplayBins()
{
	glPushMatrix();
	glTranslatef(-15806, 8980, 7596);
	BinOBJ.DisplayObject(BIN_TEXTURE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-11950, 8980, 1932);
	//glRotatef(0, 0, 1, 0);
	BinOBJ.DisplayObject(BIN_TEXTURE);
	glPopMatrix();
}

void DisplayExtraArea::DisplayBushes()
{
	//Left side next to main stairs
	glPushMatrix(); //1st section
	glTranslatef(-4546, 10050, 10250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, 250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, -250);
	glRotatef(90, 0, 1, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //2nd section
	glTranslatef(-5374, 9800, 10250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, 250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, -250);
	glRotatef(90, 0, 1, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //3rd section
	glTranslatef(-6229, 9585, 10250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, 250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, -250);
	glRotatef(90, 0, 1, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //4th section
	glTranslatef(-7000, 9330, 10250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, 250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, -250);
	glRotatef(90, 0, 1, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();
	

	//In cylinder around big tree
	glPushMatrix();
	glTranslatef(-14971, 9250, 6673);
	glScalef(1.5, 1.5, 1.5);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 250);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, -100);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(50, 0, -300);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, 50);
	glScalef(1.1, 1.1, 1.1);
	glRotatef(35, 0, 1, 0);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(12, 6, 12);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	//In smaller cylinder
	glPushMatrix();	
	glTranslatef(-14055, 9130, 2480);
	glScalef(1.5, 1.5, 1.5);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-100, 0, -300);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, 50);
	glScalef(0.8, 0.8, 0.8);
	glRotatef(46, 0, 1, 0);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(12, 6, 12);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	//In metal pot thing by dirt area
	glPushMatrix();
	glTranslatef(-10267.8, 9090, 3512.5);
	glScalef(1.3, 1.3, 1.3);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	//Behind small wall - big bushes
	glPushMatrix();
	glTranslatef(-11345, 9160, 1684);
	glScalef(2, 2, 2);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(450, 0, 50);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(700, 0, 100);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(250, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	//Behind small wall - small bushes
	glPushMatrix();
	glTranslatef(-11345, 9160, 2084);
	glScalef(1.25, 1.25, 1.25);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(250, 0, 50);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(2500, 0, -100);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(250, 0, -300);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(250, 0, 50);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	//In left area of stairs
	glPushMatrix();
	glTranslatef(-5322.4, 9646, 5375);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(450, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(50, -120, -450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(0, 0, -450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-450, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(0, -120, -550);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(450, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(150, 0, 0);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-100, -140, -400);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 3 from top
	glTranslatef(-5672.44, 9616, 7220);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, -50);
	glScalef(0.5, 0.5, 0.5);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(12, 6, 12);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 4 from top -1
	glTranslatef(-6150, 9490, 5800);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-25, 0, -450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, -50);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(90, 0, 1, 0);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(12, 6, 12);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 5 from top -1
	glTranslatef(-6585, 9358, 8015);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, -50);
	glScalef(0.4, 0.4, 0.4);
	glRotatef(35, 0, 1, 0);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(8, 6, 8);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 5 from top -2
	glTranslatef(-6585, 9358, 5315);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-25, 0, -450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 5 from top -3
	glTranslatef(-6641, 9249, 4025);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(50, 0, -450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-400, 0, 450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, -50);
	glScalef(0.5, 0.6, 0.5);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(12, 6, 12);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 7 from top -1
	glTranslatef(-7438, 9106, 7565);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, -100, -50);
	glScalef(0.5, 0.3, 0.5);
	glRotatef(90, 0, 1, 0);
	TreeOBJ.DisplayObject(TREE_TEXTURE);
	glTranslatef(0, 2500, 0);
	glScalef(6, 6, 6);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();

	glPushMatrix(); //row 7 from top -2
	glTranslatef(-7438, 9106, 5765);
	BushOBJ.DisplayObject(BUSH_TEXTURE); 
	glPopMatrix();


	//in left area of stairs bottom
	glPushMatrix();
	glTranslatef(-4850, 9050, 2400);
	glScalef(2, 2, 2);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(0, 0, 450);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-600, 0, -100);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-50, 0, 100);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, -50);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-150, 0, -50);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-350, 0, 300);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glTranslatef(-250, 0, 300);
	BushOBJ.DisplayObject(BUSH_TEXTURE);
	glPopMatrix();


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
	DisplaySlidingDoor();
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

	//Hub area wall (door right)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STUDENTHUB_DOOR_LEFT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-8100.44, 10000, 10590);
	glTexCoord2f(1, 0);
	glVertex3f(-8927.6275, 10000, 10590);
	glTexCoord2f(1, 1);
	glVertex3f(-8927.6275, 8980, 10590);
	glTexCoord2f(0.0, 1);
	glVertex3f(-8100.44, 8980, 10590);
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

void DisplayExtraArea::DisplaySlidingDoor()
{

	if (doorOpen)
	{
		doorXPos = doorXPos + 801.1875 * (glutGet(GLUT_ELAPSED_TIME) - doorTime)  / doorSpeed;
		if (doorXPos > -8240.44) { doorXPos = -8240.44; }
	}
	else
	{
		doorXPos = doorXPos - 801.1875 * (glutGet(GLUT_ELAPSED_TIME) - doorTime) / doorSpeed;
		if (doorXPos < -8927.6275) { doorXPos = -8927.6275; }
	}
	doorTime = glutGet(GLUT_ELAPSED_TIME);
	
	//Hub area wall (door right)
	glBindTexture(GL_TEXTURE_2D, tp.GetTexture(STUDENTHUB_DOOR_RIGHT));
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(doorXPos, 9750, 10595);
	glTexCoord2f(1, 0);
	glVertex3f((doorXPos - 801.1875), 9750, 10595);
	glTexCoord2f(1, 1);
	glVertex3f((doorXPos - 801.1875), 8980, 10595);
	glTexCoord2f(0.0, 1);
	glVertex3f(doorXPos, 8980, 10595);
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
	glTexCoord2f(60, 0);
	glVertex3f(-18029, 8980, 10600);
	glTexCoord2f(60, 90);
	glVertex3f(-18029, 8980, 925);
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
