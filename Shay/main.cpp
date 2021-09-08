#include <cstdlib>
#include <cmath>
#include <ctime>
#include "../include/GL/glut.h"

#include "camera.h"
#include "texturedPolygons.h"
#include "DisplayShaysWorld.h"
#include "defines.h"
#include "fileIO.h"
#include "Object.h"
#include "DisplayEXTRAShaysWorld.h"

//--------------------------------------------------------------------------------------

/// <summary>
/// Sets the movement speed of the player
/// </summary>
GLdouble movementSpeed = 50;
/// <summary>
/// Sets the rotation speed of the player
/// </summary>
GLdouble rotationSpeed = 1;

GLdouble stepIncrement;
GLdouble angleIncrement;

/// <summary>
/// The frame count of the program
/// </summary>
int frameCount = 0;

/// <summary>
/// The last clock to determine the change in frames
/// </summary>
clock_t lastClock = 0;

/// <summary>
/// The ratio of the screen
/// </summary>
float ratio;

/// <summary>
/// The screens width and height
/// </summary>
int width = 1280, height = 720;

/// <summary>
/// If the player has 'pauses' the program
/// </summary>
bool paused = true;

/// <summary>
/// Displays the campus map if true
/// </summary>
bool DisplayMap = false;

/// <summary>
/// Displays the welcome screen if true
/// </summary>
bool DisplayWelcome = true;

/// <summary>
/// Display the exit screen if true
/// </summary>
bool DisplayExit = false;

/// <summary>
/// Displays the light fittings if true
/// </summary>
bool lightsOn = true;

/// <summary>
/// Displays the ECL block if true
/// </summary>
bool displayECL = true;

/// <summary>
/// Camera object for main character
/// </summary>
Camera cam;

/**
* @brief	Initializes settings
* @prarm	No param
* @return	Void
*/
void myinit();

/**
* @brief	Handles all the display functions
* @param	No param
* @return	Void
*/
void Display();

/**
* @brief	Reshapes the window when the use tries to
* @param	w		- the width of the new window
* @param	h		- the heigh of the new window
* @return	Void
*/
void reshape(int w, int h);

/**
* @brief	Handles all the key inputs
* @param	key		- The key pressed as a char
* @param	x		- The location of the mouse when the key was pressed in the x direction
* @param	y		- The location of the mouse when the key was pressed in the y direction
* @return
*/
void keys(unsigned char key, int x, int y);

// keyboard and mouse functions

/**
* @brief	Handles all the key events when the key is released
* @param	key		- The key pressed as a char
* @param	x		- The location of the mouse when the key was pressed in the x direction
* @param	y		- The location of the mouse when the key was pressed in the y direction
* @return	Void
*/
void releaseKeys(unsigned char key, int x, int y);

/**
* @brief	Handles the mouse movement
* @param	button	- Which button was clicked
* @param	state	- If the button is up or down
* @param	x		- The location of the mouse when the mouse was moved/pressed in the x direction
* @param	y		- The location of the mouse when the mouse was moved/pressed in the y direction
* @return
*/
void Mouse(int button, int state, int x, int y);

/**
* @brief	Handles mouse movement
* @param	x		- The x location of the mouse on the screen
* @param	y		- The y location of the mouse on the screen
* @return	Void
*/
void mouseMove(int x, int y);

/**
* @brief	Increments the frame count
* @param	No param
* @return	Void
*/
void IncrementFrameCount();

/**
* @brief	Loads obj files from data/objects
* @param	No param
* @return	Void
*/
void loadObjFiles();

/**
* @brief	Creates bounding boxes for collision detection
* @param	No param
* @return	Void
*/
void CreateBoundingBoxes();

/**
* @brief	Creates bounding boxes for pillars
* @param	No param
* @return	Void
*/
void CreateBoundingBoxesPillar();

/**
* @brief	Creates different plains (used for setting the players y coordinate)
* @param	No param
* @return	Void
*/
void CreatePlains();

/**
* @brief	Determines if the sliding door should open or not
* @param	No param
* @return	Void
*/
void doorFunction();

/**
* @brief	Handles all the render steps for the program - still needs work, barebones right now
* @param	val - Currently unused, needed it for glutTimerFunc
* @return	Void
*/
void RenderLoop(int val);

/**
* @brief	Does all the bounding boxes for the extended area
* @param	No param
* @return	Void
*/
void CreateBoundingBoxesExtendedArea();

/**
* @brief	Does all the plains for the extended area
* @param	No param
* @return	Void
*/
void CreatePlainsExtendedArea();


//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
/**
* @brief	Main function
* @param	argc	- Int of how many arguments in char array
* @param	argv	- Char array
* @return	int
*/
int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, height);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keys);
	glutKeyboardUpFunc(releaseKeys);

	glutDisplayFunc(Display);
	glutTimerFunc(FRAMETIME, RenderLoop, 0);

	glutMouseFunc(Mouse);

	glutSetCursor(GLUT_CURSOR_NONE);

	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}

//--------------------------------------------------------------------------------------
//  Initialize Settings
//--------------------------------------------------------------------------------------
void myinit()
{
	glEnable(GL_TEXTURE_2D);
	// set background (sky colour)
	glClearColor(97.0 / 255.0, 140.0 / 255.0, 185.0 / 255.0, 1.0);

	// settings for glut cylinders
	glu_cylinder = gluNewQuadric();
	gluQuadricTexture(glu_cylinder, GL_TRUE);

	loadObjFiles();

	// set the world co-ordinates (used to set quadrants for bounding boxes)
	cam.SetWorldCoordinates(36000.0, 43200.0);
	// turn collision detection on
	cam.SetCollisionDetectionOn(true);
	// set starting position of user
	cam.Position(glm::vec3(32720.0, 9536.0, 4800.0), 180.0);

	CreatePlains();

	// creates bounding boxes and places in array
	CreateBoundingBoxes();

	// load texture images and create display lists
	CreateTextureList();
	CreateTextures();

	cam.SetMoveSpeed(movementSpeed);
	cam.SetRotateSpeed(angleIncrement * rotationSpeed);
}

void loadObjFiles()
{
	readObjFile("data/object/EnvironmentGeneral.obj", EnvironmentOBJ[0]);
	readObjFile("data/object/EnvironmentStairs.obj", EnvironmentOBJ[1]);
	readObjFile("data/object/EnvironmentRailing.obj", EnvironmentOBJ[2]);

	readObjFile("data/object/smallTable.obj", SmallTableOBJ);
	readObjFile("data/object/bigTable.obj", BigTableOBJ);
	readObjFile("data/object/umbrella.obj", UmbrellaOBJ);
	readObjFile("data/object/chair.obj", ChairOBJ);
	readObjFile("data/object/bench.obj", BenchOBJ);
	readObjFile("data/object/bush.obj", BushOBJ);
	readObjFile("data/object/bin.obj", BinOBJ);
	readObjFile("data/object/bark.obj", TreeOBJ);
}

void RenderLoop(int val)
{
	glutTimerFunc(FRAMETIME, RenderLoop, 0);

	if (!paused)
	{
		doorFunction();
		cam.KeyboardMovement();
	}

	glutPostRedisplay();
}


//--------------------------------------------------------------------------------------
//  Main Display Function
//--------------------------------------------------------------------------------------
void Display()
{

	// check for movement
	//cam.CheckCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	DisplayExtraArea::DisplayExtension();

	// DISPLAY TEXTURES
	glPushMatrix();
	// displays the welcome screen
	if (DisplayWelcome) cam.DisplayWelcomeScreen(width, height, 1, tp.GetTexture(WELCOME));
	// displays the exit screen
	if (DisplayExit) cam.DisplayWelcomeScreen(width, height, 0, tp.GetTexture(EXIT));
	// displays the map
	if (DisplayMap) cam.DisplayMap(width, height, tp.GetTexture(MAP));
	// display no exit sign (position check should really be in an object, but didn't have time)
	if ((cam.GetLR() > 35500.0) && (cam.GetFB() < 25344.0) ||
		(cam.GetLR() > 34100.0) && (cam.GetFB() > 41127.0))
	{
		cam.DisplayNoExit(width, height, tp.GetTexture(NO_EXIT));
	}
	// set the movement and rotation speed according to frame count
	IncrementFrameCount();
	
	// display images
	DrawBackdrop(lightsOn);
	glPopMatrix();

	// clear buffers
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------
void reshape(int w, int h)
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) h = 1;
	ratio = 1.0f * w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(60, ratio, 1, 250000);
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------------------------------
void keys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'U':
		cam.SetMoveSpeed(movementSpeed / 10);
		break;
	case 'I':
		cam.SetMoveSpeed(movementSpeed);
		break;
	case 'O':
		cam.SetMoveSpeed(movementSpeed * 10);
		break;
	case 'Y':
		cam.SetCameraLocation(2613.56, 10450, 9250);
		break;

	case 'x':
		cam.PrintPos();
		break;

		// move forwards
	case 'W':
	case 'w':
		cam.DirectionFB(1);
		break;

		// move backwards
	case 'S':
	case 's':
		cam.DirectionFB(-1);
		break;

		// step left
	case 'A':
	case 'a':
	case 1:
		cam.DirectionLR(-1);
		break;

		// step right
	case 'D':
	case 'd':
	case 4:
		cam.DirectionLR(1);
		break;

		// display campus map
	case 'm':
	case 'M':
		DisplayMap = !DisplayMap;
		break;

		// exit tour (escape key)
	case 27:
		glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
		DisplayExit = true;
		break;

	case 'c':
	case 'C':
	case ' ':
		cam.SetCrouch(true);
		break;

	case 'p':
	case 'P':
		paused = !paused;
		if (paused)
		{
			DisplayWelcome = true;
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			glutPassiveMotionFunc(NULL);
			glutMotionFunc(NULL);
		}
		else
		{
			DisplayWelcome = false;
			glutSetCursor(GLUT_CURSOR_NONE);
			glutPassiveMotionFunc(mouseMove);
			glutMotionFunc(mouseMove);
			glutWarpPointer(width / 2, height / 2);
		}
		break;
	}
	
}

//--------------------------------------------------------------------------------------
void releaseKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
		// step left or right
		case 'a' :
		case 'A' :
		case 1: //In case of ctrl + a
			cam.DirectionLR(-2);
			break;
		case 'd' :
		case 'D' :
		case 4: //In case of ctrl + d
			cam.DirectionLR(2);
			break;

		// look left up or down
		case 'w' :
		case 'W' :
		case 's' :
		case 'S' :
		case 23: //In case of ctrl + w
		case 19: //In case of ctrl + s
			cam.DirectionFB(0);
			break;

		case 'c':
		case 'C':
		case ' ':
			cam.SetCrouch(false);
			break;
	}
	
}

//--------------------------------------------------------------------------------------
//  Mouse Buttons
//--------------------------------------------------------------------------------------
void Mouse(int button, int state, int x, int y)
{
	// exit tour if clicked on exit splash screen
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if ((DisplayExit) && (x <= width / 2.0 + 256.0) && (x >= width / 2.0 - 256.0)
						  && (y <= height / 2.0 + 256.0) && (y >= height / 2.0 - 256.0))
		{
			exit(1);
		}
  	 }
}

//--------------------------------------------------------------------------------------
//  Mouse Movements (USED WITH BETTER IMPLEMENTATION)
//  Can be used to rotate around screen using mouse
//--------------------------------------------------------------------------------------
void mouseMove(int x, int y)
{
	cam.MouseMove(x, y);

	glutPostRedisplay();
}


void doorFunction()
{
	GLdouble x = cam.GetLR(), z = cam.GetFB();

	//std::cout << x << " - " << z << std::endl;

	if ((x < -8339.44 && x > -10386.44) && (z < 12000 && z > 9500)){ doorOpen = true; }
	else { doorOpen = false; }

}

//--------------------------------------------------------------------------------------
// Set up bounding boxes for collision detection
//--------------------------------------------------------------------------------------
void CreateBoundingBoxes()
{
	cam.AddAABB(glm::vec3(35879, 0, 22096), glm::vec3(33808, 0, 4688)); // chanc block
	cam.AddAABB(glm::vec3(35999, 0, 25344), glm::vec3(35730, 0, 22096)); // between chanc block and phys sci
	cam.AddAABB(glm::vec3(35879, 0, 26752), glm::vec3(33808, 0, 25344)); // phy sci block panel 1
	cam.AddAABB(glm::vec3(35879, 0, 27559), glm::vec3(34256, 0, 26752)); // phy sci block 1st doorway
	cam.AddAABB(glm::vec3(35879, 0, 36319), glm::vec3(33808, 0, 27559)); // phy sci block 2nd panel
	cam.AddAABB(glm::vec3(35879, 0, 37855), glm::vec3(34260, 0, 36319)); // phy sci block 2nd doorway
	cam.AddAABB(glm::vec3(35879, 0, 41127), glm::vec3(33808.0, 0, 37855)); // phy sci block 3rd panel
	cam.AddAABB(glm::vec3(35879, 0, 25344), glm::vec3(34704, 0, 24996)); // drinks machine
	cam.AddAABB(glm::vec3(33808, 0, 4688), glm::vec3(0, 0, 0)); // bottom of steps
	cam.AddAABB(glm::vec3(35879, 0, 43056), glm::vec3(41127, 0, 34320)); // end of phy sci block exit (top of steps)
	cam.AddAABB(glm::vec3(34320, 0, 50000), glm::vec3(6514, 0, 43036)); // library end panel
	cam.AddAABB(glm::vec3(28104, 0, 43046), glm::vec3(25608, 0, 42754)); // KBLT
	cam.AddAABB(glm::vec3(2608, 0, 49046), glm::vec3(-10, 0, 9990)); // Canteen block
	cam.AddAABB(glm::vec3(33892, 0, 25344), glm::vec3(33872, 0, 25173)); // Telephones
	cam.AddAABB(glm::vec3(34277, 0, 25344), glm::vec3(34157, 0, 25173)); // Telephones
	cam.AddAABB(glm::vec3(35462, 0, 25344), glm::vec3(34541, 0, 25173)); // Telephones
	cam.AddAABB(glm::vec3(31548, 0, 10395), glm::vec3(31444, 0, 4590)); // Wall by Steps
	cam.AddAABB(glm::vec3(2608, 0, 8540), glm::vec3(-4644, 0, 0)); //Walters restaurant
	cam.AddAABB(glm::vec3(34520, 0, 43193), glm::vec3(34130, 0, 41136)); //No modelling area sign
	cam.AddAABB(glm::vec3(6812, 0, 45400), glm::vec3(2417, 0, 44600)); //Other unfinished area

	// Pillars
	CreateBoundingBoxesPillar();
	
	// Extended area (Outdoor of student hub)
	CreateBoundingBoxesExtendedArea();
}

void CreateBoundingBoxesPillar()
{
	glm::vec3 pillarMax(31900, 0, 8300);
	glm::vec3 pillarMin(31700, 0, 8100);

	// Left
	for (int i = 0; i < 17; ++i, pillarMax.z += 1930, pillarMin.z += 1930)
		cam.AddAABB(glm::vec3(pillarMax), glm::vec3(pillarMin));

	// Middle
	for (int i = 0; i < 14; ++i, pillarMax.x -= 1940, pillarMin.x -= 1940)
		cam.AddAABB(glm::vec3(pillarMax), glm::vec3(pillarMin));

	// Right
	for (int i = 0; i < 19; ++i, pillarMax.z -= 1930, pillarMin.z -= 1930) // 19 pillars on this side
	{
		if (i == 18) // for the last pillar, fix the collision according to location (1930 * 0.87)
		{
			pillarMax.z += 250.9;
			pillarMin.z += 250.9;
		}
		cam.AddAABB(glm::vec3(pillarMax), glm::vec3(pillarMin));
	}
}

void CreateBoundingBoxesExtendedArea()
{
	//Gaming hub
	cam.AddAABB(glm::vec3(0, 0, 13500), glm::vec3(-17200, 0, 10540));

	//Left side of main stair plant area
	cam.AddAABB(glm::vec3(-4350, 0, 9940), glm::vec3(-7580, 0, 9840));
	cam.AddAABB(glm::vec3(-4347, 0, 10600), glm::vec3(-7980, 0, 9840));

	//Center railing on main stairs
	cam.AddAABB(glm::vec3(-4350, 0, 9300), glm::vec3(-7980, 0, 9200));

	//Side area of main stairs
	cam.AddAABB(glm::vec3(-2346, 0, 8500), glm::vec3(-5174, 0, 8275)); //First barrier off to right of stairs
	cam.AddAABB(glm::vec3(-5420, 0, 8500), glm::vec3(-6032, 0, 8275)); //Second barrier off to right of stairs
	cam.AddAABB(glm::vec3(-6278, 0, 8500), glm::vec3(-6890, 0, 8275)); //Third barrier off to right of stairs
	cam.AddAABB(glm::vec3(-7136, 0, 8500), glm::vec3(-7748, 0, 8275)); //Fourth barrier off to right of stairs

	cam.AddAABB(glm::vec3(-4622, 0, 5705), glm::vec3(-5072, 0, 2875)); //First tree/bush section on row 1
	cam.AddAABB(glm::vec3(-5072, 0, 5705), glm::vec3(-5522, 0, 5125)); //First tree/bush section on row 2
	cam.AddAABB(glm::vec3(-5072, 0, 4675), glm::vec3(-5522, 0, 3775)); //Second tree/bush section on row 2
	cam.AddAABB(glm::vec3(-5522, 0, 7375), glm::vec3(-5972, 0, 6925)); //First tree/bush section on row 3
	cam.AddAABB(glm::vec3(-5972, 0, 6025), glm::vec3(-6381, 0, 5125)); //First tree/bush section on row 4
	cam.AddAABB(glm::vec3(-6381, 0, 8275), glm::vec3(-6788, 0, 7825)); //First tree/bush section on row 5
	cam.AddAABB(glm::vec3(-6381, 0, 5575), glm::vec3(-6788, 0, 4675)); //Second tree/bush section on row 5
	cam.AddAABB(glm::vec3(-6381, 0, 4225), glm::vec3(-6788, 0, 3325)); //Third tree/bush section on row 5
	cam.AddAABB(glm::vec3(-6788, 0, 4225), glm::vec3(-7238, 0, 3775)); //First tree/bush section on row 6
	cam.AddAABB(glm::vec3(-7238, 0, 7825), glm::vec3(-7688, 0, 7375)); //First tree/bush section on row 7
	cam.AddAABB(glm::vec3(-7238, 0, 6025), glm::vec3(-7688, 0, 5575)); //Second tree/bush section on row 7


	//boundary walls
	cam.AddAABB(glm::vec3(-15993, 0, 10600), glm::vec3(-16993, 0, 6613)); //far back
	cam.AddAABB(glm::vec3(-16300.840, 0, 6826.400), glm::vec3(-17300.840, 0, 2493.300)); //far back behind Area B
	//cam.AddAABB(glm::vec3(-7238, 0, 6025), glm::vec3(-7688, 0, 5575)); //far back diagonal 2.1
	cam.AddAABB(glm::vec3(-4500, 0, 1551.5), glm::vec3(-17000, 0, 0)); //right

	//cylinders on Area B
	cam.AddAABB(glm::vec3(-14620.84, 0, 7343.56), glm::vec3(-17000, 0, 6030.1)); //cylinder
	cam.AddAABB(glm::vec3(-14912.330, 0, 6030.1), glm::vec3(-17000, 0, 5809.100));//next to cylinder (also left railing of left stairs)
	cam.AddAABB(glm::vec3(-14912.330, 0, 4945), glm::vec3(-15550, 0, 4895));//Right railing of left stairs

	cam.AddAABB(glm::vec3(-13478.14, 0, 3100), glm::vec3(-16550.64, 0, 1511.5)); //cylinder
	cam.AddAABB(glm::vec3(-16101, 0, 3674), glm::vec3(-16550.64, 0, 3400)); //cylinder
	cam.AddAABB(glm::vec3(-15961, 0, 3400), glm::vec3(-16550.64, 0, 3200)); //cylinder
	cam.AddAABB(glm::vec3(-15831, 0, 3200), glm::vec3(-16550.64, 0, 3000)); //cylinder
	cam.AddAABB(glm::vec3(-15701, 0, 3000), glm::vec3(-16550.64, 0, 2700)); //cylinder
	
	
	//Diagonal Railing
	cam.AddAABB(glm::vec3(-14620, 0, 3960), glm::vec3(-14740, 0, 3885)); //cylinder
	cam.AddAABB(glm::vec3(-14740, 0, 3885), glm::vec3(-14860, 0, 3815)); //cylinder
	cam.AddAABB(glm::vec3(-14860, 0, 3815), glm::vec3(-15000, 0, 3700)); //cylinder
	cam.AddAABB(glm::vec3(-15000, 0, 3700), glm::vec3(-15158, 0, 3596)); //cylinder

	//Area C
	cam.AddAABB(glm::vec3(-8844.34, 0, 4586), glm::vec3(-11207.44, 0, 2050));

	//Wall next to Area C 
	cam.AddAABB(glm::vec3(-8225.74, 0, 2763.7), glm::vec3(-11816.44, 0, 1551.5));
	cam.AddAABB(glm::vec3(-7688, 0, 2508), glm::vec3(-8225.74, 0, 1000));

	cam.AddAABB(glm::vec3(-7286, 0, 2050), glm::vec3(-7688, 0, 1000));
	cam.AddAABB(glm::vec3(-6386, 0, 1750), glm::vec3(-7286, 0, 1000));

	// Diagonal small table
	cam.AddAABB(glm::vec3(-11855, 0, 3636), glm::vec3(-12274, 0, 3243));
	cam.AddAABB(glm::vec3(-13278, 0, 3263), glm::vec3(-13648, 0, 2920));

	// Chairs
	cam.AddAABB(glm::vec3(-8832, 0, 7011), glm::vec3(-9283, 0, 6575));
	cam.AddAABB(glm::vec3(-8693, 0, 6883), glm::vec3(-9438, 0, 6730));

	cam.AddAABB(glm::vec3(-8935, 0, 7885), glm::vec3(-9437, 0, 7715));
	cam.AddAABB(glm::vec3(-9079, 0, 8061), glm::vec3(-9272, 0, 7568));

	cam.AddAABB(glm::vec3(-8945, 0, 7413), glm::vec3(-9449, 0, 7214));
	
	cam.AddAABB(glm::vec3(-9726, 0, 6906), glm::vec3(-10491, 0, 6229));
	cam.AddAABB(glm::vec3(-9892, 0, 7047), glm::vec3(-10342, 0, 6057));

	cam.AddAABB(glm::vec3(-9718, 0, 7990), glm::vec3(-10270, 0, 7808));
	cam.AddAABB(glm::vec3(-9896, 0, 8183), glm::vec3(-10084, 0, 7660));

	cam.AddAABB(glm::vec3(-10497, 0, 7547), glm::vec3(-11181, 0, 7069));
	cam.AddAABB(glm::vec3(-10325, 0, 7409), glm::vec3(-11332, 0, 7229));

	cam.AddAABB(glm::vec3(-11485, 0, 7400), glm::vec3(-12241, 0, 7227));
	cam.AddAABB(glm::vec3(-11666, 0, 7532), glm::vec3(-12089, 0, 7053));

	cam.AddAABB(glm::vec3(-8935, 0, 6379), glm::vec3(-9438, 0, 6213));

	cam.AddAABB(glm::vec3(-8926, 0, 5879), glm::vec3(-9424, 0, 5714));
	cam.AddAABB(glm::vec3(-9103, 0, 5999), glm::vec3(-9255, 0, 5531));

	// Small table
	cam.AddAABB(glm::vec3(-9852, 0, 8061), glm::vec3(-10171, 0, 7750));
	cam.AddAABB(glm::vec3(-9050, 0, 7950), glm::vec3(-9340, 0, 7670));
	cam.AddAABB(glm::vec3(-9050, 0, 7440), glm::vec3(-9340, 0, 7160));
	cam.AddAABB(glm::vec3(-8795, 0, 6930), glm::vec3(-9340, 0, 6650));
	cam.AddAABB(glm::vec3(-9050, 0, 6420), glm::vec3(-9340, 0, 6140));
	cam.AddAABB(glm::vec3(-9050, 0, 5910), glm::vec3(-9340, 0, 5630));

	cam.AddAABB(glm::vec3(-10450, 0, 7440), glm::vec3(-11250, 0, 7160));
	
	cam.AddAABB(glm::vec3(-11600, 0, 7440), glm::vec3(-12150, 0, 7160));

	cam.AddAABB(glm::vec3(-9850, 0, 6950), glm::vec3(-10403, 0, 6145));

	cam.AddAABB(glm::vec3(-15155, 0, 4350), glm::vec3(-15456, 0, 4050));

	// Big table
	cam.AddAABB(glm::vec3(-7990, 0, 5400), glm::vec3(-8640, 0, 4840));

	cam.AddAABB(glm::vec3(-9830, 0, 8940), glm::vec3(-10300, 0, 8360));
	cam.AddAABB(glm::vec3(-10600, 0, 8940), glm::vec3(-11240, 0, 8360));
	cam.AddAABB(glm::vec3(-11710, 0, 8940), glm::vec3(-12180, 0, 8360));
	cam.AddAABB(glm::vec3(-12480, 0, 8940), glm::vec3(-13120, 0, 8360));
	cam.AddAABB(glm::vec3(-13420, 0, 8940), glm::vec3(-14060, 0, 8360));

	// Umbrella
	cam.AddAABB(glm::vec3(-9755, 0, 8680), glm::vec3(-9830, 0, 8610));
	cam.AddAABB(glm::vec3(-11635, 0, 8680), glm::vec3(-11708, 0, 8610));

	//bins
	cam.AddAABB(glm::vec3(-11523, 0, 2124), glm::vec3(-12100, 0, 1740));
	cam.AddAABB(glm::vec3(-15700, 0, 7779), glm::vec3(-17000, 0, 7000));
}

//--------------------------------------------------------------------------------------
// Set up co-ordinates of different plains
//--------------------------------------------------------------------------------------
/**
* @brief	Set up co-ordinates of different plains. What this actually means is this is where you assign invisible floors for the player to walk on
* @param	No param
* @return	Void
*/
void CreatePlains()
{	
	//						x1, x2				, y1, y2		, z1, z2
	// grass slope ZY_PLAIN
	cam.AddPlain(ZY_PLAIN, glm::vec3(4848, 9536, 6200), glm::vec3(31568, 10450, 10000));

	// flat land (pavement and grass)
	cam.AddPlain(FLAT_PLAIN, glm::vec3(0, 10450, 10000), glm::vec3(36000, 10450, 17000));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(0, 10450, 17000), glm::vec3(6500, 10450, 40000));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(27000, 10450, 17000), glm::vec3(36000, 10450, 40000));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(0, 10450, 40000), glm::vec3(36000, 10450, 50000));
	
	// top of lower hill
	cam.AddPlain(FLAT_PLAIN, glm::vec3(9000, 10650, 19000), glm::vec3(22000, 10650, 23000));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(9000, 10650, 28000), glm::vec3(10000, 10650, 33000));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(9000, 10650, 36000), glm::vec3(22000, 10650, 37000));
	// sides of lower hill
	cam.AddPlain(ZY_PLAIN, glm::vec3(6500, 10450, 17000), glm::vec3(27000, 10650, 19000));
	cam.AddPlain(ZY_PLAIN, glm::vec3(6500, 10650, 37000), glm::vec3(27000, 10450, 40000));
	cam.AddPlain(XY_PLAIN, glm::vec3(6500, 10450, 17000), glm::vec3(9000, 10650, 40000));
	cam.AddPlain(XY_PLAIN, glm::vec3(22000, 10650, 17000), glm::vec3(27000, 10450, 40000));

	// top of higher hill
	cam.AddPlain(FLAT_PLAIN, glm::vec3(14000, 10875, 28000), glm::vec3(18000, 10875, 33000));
	// sides of higher hill
	cam.AddPlain(ZY_PLAIN, glm::vec3(10000, 10650, 23000), glm::vec3(22000, 10875, 28000));
	cam.AddPlain(ZY_PLAIN, glm::vec3(10000, 10875, 33000), glm::vec3(22000, 10650, 36000));
	cam.AddPlain(XY_PLAIN, glm::vec3(10000, 10650, 23000), glm::vec3(14000, 10875, 36000));
	cam.AddPlain(XY_PLAIN, glm::vec3(18000, 10875, 23000), glm::vec3(22000, 10650, 36000));

	// Missing big step
	cam.AddPlain(FLAT_PLAIN, glm::vec3(31582, 10258, 9000), glm::vec3(33835, 10258, 9300));

	// Missing step 4th step from the top
	cam.AddPlain(FLAT_PLAIN, glm::vec3(31582, 10300, 9400), glm::vec3(33835, 10300, 9490));

	//entrance steps
	step = 10450.0;
	stepLength = 9808.0;
	for (int i = 0; i < 18; i++)
	{
		cam.AddPlain(FLAT_PLAIN, glm::vec3(31582, step, stepLength), glm::vec3(33835, step, stepLength + 42));
		step -= 48.0;
		stepLength -= 142.0;
		if ((i + 3) % 5 == 0)
		{
			stepLength -= 500.0;
			step -= 48.0;
		}
	}

	// temp plain to take down to ECL1
	cam.AddPlain(ZY_PLAIN, glm::vec3(3200, 10450, 53400), glm::vec3(4800, 9370, 57900));

	CreatePlainsExtendedArea();
}

void CreatePlainsExtendedArea()
{
	//						x1, x2				, y1, y2		, z1, z2
	//Missing part infront of entrance
	cam.AddPlain(FLAT_PLAIN, glm::vec3(2636, 10450, 6360), glm::vec3(4841, 10450, 10019));

	//Entrance
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-4613, 10450, 6360), glm::vec3(2636, 10450, 10019));

	//Bottom of stairs/Side area of stairs
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-14226.04, 9430, 1421), glm::vec3(-7874, 9430, 10540));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-9296, 9430, 3325), glm::vec3(-6974, 9430, 4225));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-9296, 9430, 2875), glm::vec3(-5674, 9430, 3325));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-9296, 9430, 1421), glm::vec3(-4774, 9430, 2875));

	//Stairs Main
	//glTranslatef(2613.56, 10000, 9250);
	float stepDepth = 51, stepLength = 102, largeStepLength = 450;
	float zStart = 10000, zEnd = 8500;	//9250 +- 750
	float xPos = -4664.44; //2613.56 - 7278
	float height = 10399;

	for (int count = 1; count <= 20; count++)
	{
		cam.AddPlain(FLAT_PLAIN, glm::vec3(xPos - stepLength, height, zEnd), glm::vec3(xPos, height, zStart));
		xPos -= stepLength;
		height -= stepDepth;
		
		if (count % 5 == 0){ xPos -= largeStepLength - stepLength; }
	}

	//Left stairs by small area
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-16300.84, 9580, 4914.7), glm::vec3(-15398.44, 9580, 5854)); //upper section
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15398.44, 9529, 4914.7), glm::vec3(-15316.539, 9529, 5854)); //bottom section
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15316.539, 9478, 4914.7), glm::vec3(-15188.44, 9478, 5854)); //first step
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15188.44, 9430, 4914.7), glm::vec3(-14088.44, 9430, 5854)); //second step

	//sections close (bit to the right) to left stairs by small area
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15706.24, 9580, 4654), glm::vec3(-15076.24, 9580, 4921.6));
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15076.24, 9430, 4654), glm::vec3(-14076.24, 9430, 4921.6));


	//Right stairs by small area
	
	cam.AddPlain(DIAGONAL_FLAT_PLAIN,	glm::vec3(-14490.640, 9580, 2910.100),	glm::vec3(-15211.840, 9580, 4021.600),
										glm::vec3(-16890.641, 9580, 3972.100),	glm::vec3(-14972.739, 9580, 2093.800)); //upper section
	cam.AddPlain(DIAGONAL_FLAT_PLAIN,	glm::vec3(-14727.341, 9430, 3865.3),	glm::vec3(-14226.04, 9430, 3073.9),
										glm::vec3(-14312.74, 9430, 3022),		glm::vec3(-14811.64, 9430, 3813.4)); //bottem section


	cam.AddPlain(DIAGONAL_FLAT_PLAIN,	glm::vec3(-14312.74, 9478, 3022),		glm::vec3(-14811.64, 9478, 3813.4),
										glm::vec3(-14900.44, 9478, 3757.6),	glm::vec3(-14401.84, 9580, 2966.2));//first step


	cam.AddPlain(DIAGONAL_FLAT_PLAIN, glm::vec3(-14900.44, 9529, 3757.6), glm::vec3(-14401.84, 9529, 2966.2),
										glm::vec3(-14490.64, 9529, 2910.1),	glm::vec3(-14989.239, 9529, 3701.5));//second step
	

	//Area B
	
	cam.AddPlain(DIAGONAL_FLAT_PLAIN,	glm::vec3(-14727.341, 9580, 3865.3),	glm::vec3(-14989.239, 9580, 3701.5),
										glm::vec3(-15486, 9580, 4364.5),		glm::vec3(-14993.14, 9580, 4397.8)); //upper middle section
	cam.AddPlain(DIAGONAL_FLAT_PLAIN,	glm::vec3(-14993.14, 9430, 4397.8),		glm::vec3(-14226.04, 9430, 3073.9),
										glm::vec3(-13982.14, 9430, 3251.2),		glm::vec3(-14593.84, 9430, 4526.5)); //lower middle section
	
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-15883.14, 9580, 4397.8), glm::vec3(-14883.14, 9580, 4770.7)); //upper left middle section
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-14883.14, 9430, 4397.8), glm::vec3(-14483.14, 9430, 4770.7)); //bottom left middle section

	//Side area of main stairs
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5072, 10324, 5575), glm::vec3(-4622, 10324, 8275)); //First wood section - main //Level 2
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5522, 10195, 5575), glm::vec3(-5072, 10195, 8275)); //First concrete section - main //Level 3
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5972, 10066, 5125), glm::vec3(-5522, 10066, 8275)); //Second wood section - main //Level 4
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-6381, 9937, 5125), glm::vec3(-5972, 9937, 8275)); //Second concrete section - main //Level 5
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-6788, 9808, 4675), glm::vec3(-6381, 9808, 8275)); //Third wood section - main //Level 6
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-7238, 9679, 4225), glm::vec3(-6788, 9679, 8275)); //Third concrete section - main //Level 7
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-7688, 9556, 4225), glm::vec3(-7238, 9556, 8275)); //Fourth wood section - main //Level 8

	//The messy part of the area - ask Dan if you need to know. level 2 is top wood, level 8 is lowest wood block
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-6381, 9937, 4675), glm::vec3(-5072, 9937, 5125)); //Block over second, third and fourth at level 5
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-6788, 9808, 4225), glm::vec3(-5522, 9808, 4675)); //Block over third, fourth and fifth at level 6\

	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5522, 9679, 2875), glm::vec3(-5072, 9679, 3775)); //Block over Second at level 7
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5972, 9679, 3325), glm::vec3(-5522, 9679, 3775)); //Block over third at level 7
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-5972, 9808, 3775), glm::vec3(-5522, 9808, 4225)); //Block over third at level 6
	cam.AddPlain(FLAT_PLAIN, glm::vec3(-6381, 9679, 3325), glm::vec3(-5972, 9679, 4225)); //Block over fourth at level 7
}

//--------------------------------------------------------------------------------------
//  Increments frame count used for setting movement speed
//--------------------------------------------------------------------------------------
void IncrementFrameCount()
{
	double t = ((GLdouble)(clock() - lastClock)) / (GLdouble)CLOCKS_PER_SEC;
	++frameCount;

	// reset after t
	if (t > 0.1)
	{
		stepIncrement = t / frameCount * 1400;
		angleIncrement = t / frameCount;
		frameCount = 0;
		lastClock = clock();
	}
}
