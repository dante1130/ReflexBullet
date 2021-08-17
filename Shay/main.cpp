#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>

//#include <windows.h> // only used if mouse is required (not portable)
#include "camera.h"
#include "texturedPolygons.h"
#include "DisplayShaysWorld.h"
#include "defines.h"


//--------------------------------------------------------------------------------------

// USE THESE STTEINGS TO CHANGE SPEED (on different spec computers)
// Set speed (steps)
GLdouble movementSpeed = 2.0;
GLdouble rotationSpeed = 1;

GLdouble stepIncrement;
GLdouble angleIncrement;
int frameCount = 0;
clock_t lastClock = 0;

// ratio of screen
float ratio;
// screen width and height
int width, height;

// display campus map
bool DisplayMap = false;
// display welcome screen
bool DisplayWelcome = true;
// display exit screen
bool DisplayExit = false;
// display light fittings
bool lightsOn;
// display ECL block
bool displayECL = true;

// objects
Camera cam;


// initializes setting
void myinit();

// display functions
void Display();
void reshape(int w, int h);
void keys(unsigned char key, int x, int y);

// keyboard and mouse functions
void movementKeys(int key, int x, int y);
void releaseKey(int key, int x, int y);
void releaseKeys(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void mouseMove(int x, int y);

void BindBridgeWall(GLint LR);
void BindBuildingWall();
void BindWallPosts(GLint LR);

void IncrementFrameCount();


// creates bounding boxes for collsion detection
void CreateBoundingBoxes();
// creates different plains
void CreatePlains();


void RenderLoop(int val);

//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 500);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keys);
	glutKeyboardUpFunc(releaseKeys);
	

	glutDisplayFunc(Display);
	//glutIdleFunc(Display);
	glutTimerFunc(FRAMETIME, RenderLoop, 0);

	glutMouseFunc(Mouse);


	glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);
	glutSetCursor(GLUT_CURSOR_NONE);

	glutReshapeFunc(reshape);
	glutMainLoop();

	return(0);
}

//--------------------------------------------------------------------------------------
//  Initialize Settings
//--------------------------------------------------------------------------------------
void myinit()
{
	// set background (sky colour)
	glClearColor(97.0 / 255.0, 140.0 / 255.0, 185.0 / 255.0, 1.0);

	// set perpsective
	gluLookAt(0.0, 1.75, 0.0,
		0.0, 1.75, -1,
		0.0f, 1.0f, 0.0f);

	// settings for glut cylinders
	glu_cylinder = gluNewQuadric();
	gluQuadricTexture(glu_cylinder, GL_TRUE);

	// set the world co-ordinates (used to set quadrants for bounding boxes)
	cam.SetWorldCoordinates(36000.0, 43200.0);
	// turn collision detection on
cam.SetCollisionDetectionOn(true);
// set number of bounding boxes required
cam.SetNoBoundingBoxes(19);
// set starting position of user
cam.Position(32720.0, 9536.0,
	4800.0, 180.0);

CreatePlains();

// creates bounding boxes and places in array
CreateBoundingBoxes();
// copies bounding boxes from array to linked lists (one fopr each quadrant)
cam.InitiateBoundingBoxes();

// load texture images and create display lists
CreateTextureList();
CreateTextures();
}

/**
* @breif	Handles all the render steps for the program - still needs work, barebones right now
*
* @param	val - Currently unused, needed it for glutTimerFunc
*
* @return	Void
*/
void RenderLoop(int val)
{
	glutTimerFunc(FRAMETIME, RenderLoop, 0);



	cam.KeyboardMovement();

	glutPostRedisplay();
	return;
}


//--------------------------------------------------------------------------------------
//  Main Display Function
//--------------------------------------------------------------------------------------
void Display()
{
	// check for movement
	//cam.CheckCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// DISPLAY TEXTURES
	//enable texture mapping
	glEnable(GL_TEXTURE_2D);
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
	cam.SetMoveSpeed(stepIncrement * movementSpeed);
	cam.SetRotateSpeed(angleIncrement * rotationSpeed);
	// display images
	DrawBackdrop(lightsOn);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

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
	gluPerspective(45, ratio, 1, 250000);
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------------------------------
void keys(unsigned char key, int x, int y)
{
	int i = 0;


	int vaal = glutGetModifiers();
	std::cout << vaal << std::endl;

	
	switch (key)
	{
	// move forwards
	case 'W':
	case 'w':
		cam.DirectionFB(1);
		break;

	case 'S':
	case 's':
		cam.DirectionFB(-1);
		break;
		
	// step left
	case 'A':
	case 'a':
		cam.DirectionLR(-1);
		break;
	// step right
	case 'D':
	case 'd':
		cam.DirectionLR(1);
		break;
	

	// display campus map
	case 'm':
	case 'M':
		if (DisplayMap)
		{
			DisplayMap = false;
		}
		else
		{
			DisplayMap = true;
		}
		break;

	// exit tour (escape key)
	case 27:
		cam.SetRotateSpeed (0.0f);
		cam.SetMoveSpeed (0.0f);
		glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
		DisplayExit = true;
		break;

	// display welcome page (space key)
	case ' ':
		if (DisplayWelcome)
		{
			cam.SetRotateSpeed (rotationSpeed);
			cam.SetMoveSpeed (movementSpeed);
			DisplayWelcome = false;
		}
		else
		{
			cam.SetRotateSpeed (0.0f);
			cam.SetMoveSpeed (0.0f);
			DisplayWelcome = true;
		}
		break;

	// display light fittings
	case 'l':
	case 'L':
		if (lightsOn)
		{
			lightsOn = false;
		}
		else
		{
			lightsOn = true;
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
			cam.DirectionLR(-2);
			break;
		case 'd' :
		case 'D' :
			cam.DirectionLR(2);
			break;

		// look left up or down
		case 'w' :
		case 'W' :
		case 's' :
		case 'S' :
			cam.DirectionFB(0);
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
		if ((DisplayExit) && (x <= width/2.0 + 256.0) && (x >= width/2.0 - 256.0)
			&& (y <= height/2.0 + 256.0) && (y >= height/2.0 - 256.0))
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

//--------------------------------------------------------------------------------------
// Set up bounding boxes for collsion detection
//--------------------------------------------------------------------------------------
void CreateBoundingBoxes()
{
	// chanc block
	cam.SetAABBMaxX(0, 35879.0);
	cam.SetAABBMinX(0, 33808.0);
	cam.SetAABBMaxZ(0, 22096.0);
	cam.SetAABBMinZ(0, 4688.0);

	// between chanc block and phys sci
	cam.SetAABBMaxX(1, 35999.0);
	cam.SetAABBMinX(1, 35730.0);
	cam.SetAABBMaxZ(1, 25344.0);
	cam.SetAABBMinZ(1, 22096.0);

	// phy sci block panel 1
	cam.SetAABBMaxX(2, 35879.0);
	cam.SetAABBMinX(2, 33808.0);
	cam.SetAABBMaxZ(2, 26752.0);
	cam.SetAABBMinZ(2, 25344.0);

	// phy sci block 1st doorway
	cam.SetAABBMaxX(3, 35879.0);
	cam.SetAABBMinX(3, 34256.0);
	cam.SetAABBMaxZ(3, 27559.0);
	cam.SetAABBMinZ(3, 26752.0);

	// phy sci block 2nd panel
	cam.SetAABBMaxX(4, 35879.0);
	cam.SetAABBMinX(4, 33808.0);
	cam.SetAABBMaxZ(4, 36319.0);
	cam.SetAABBMinZ(4, 27559.0);

	// phy sci block 2nd doorway
	cam.SetAABBMaxX(5, 35879.0);
	cam.SetAABBMinX(5, 34260.0);
	cam.SetAABBMaxZ(5, 37855.0);
	cam.SetAABBMinZ(5, 36319.0);

	// phy sci block 3rd panel
	cam.SetAABBMaxX(6, 35879.0);
	cam.SetAABBMinX(6, 33808.0);
	cam.SetAABBMaxZ(6, 41127.0);
	cam.SetAABBMinZ(6, 37855.0);

	// drinks machine
	cam.SetAABBMaxX(7, 35879.0);
	cam.SetAABBMinX(7, 34704.0);
	cam.SetAABBMaxZ(7, 25344.0);
	cam.SetAABBMinZ(7, 24996.0);
		
	// bottom of steps
	cam.SetAABBMaxX(8, 33808.0);
	cam.SetAABBMinX(8, 0.0);
	cam.SetAABBMaxZ(8, 4688.0);
	cam.SetAABBMinZ(8, 0.0);

	// end of phy sci block exit (top of steps)
	cam.SetAABBMaxX(9, 35879.0);
	cam.SetAABBMinX(9, 34320.0);
	cam.SetAABBMaxZ(9, 43056.0);
	cam.SetAABBMinZ(9, 41127.0);

	// library end panel
	cam.SetAABBMaxX(10, 34320.0);
	cam.SetAABBMinX(10, 6514.0);
	cam.SetAABBMaxZ(10, 50000.0);
	cam.SetAABBMinZ(10, 43036.0);

	// KBLT
	cam.SetAABBMaxX(11, 28104.0);
	cam.SetAABBMinX(11, 25608.0);
	cam.SetAABBMaxZ(11, 43046.0);
	cam.SetAABBMinZ(11, 42754.0);

	// Canteen block
	cam.SetAABBMaxX(12, 2608.0);
	cam.SetAABBMinX(12, 0.0);
	cam.SetAABBMaxZ(12, 49046.0);
	cam.SetAABBMinZ(12, 0.0);

	// Telephones
	cam.SetAABBMaxX(13, 33892.0);
	cam.SetAABBMinX(13, 33872.0);
	cam.SetAABBMaxZ(13, 25344.0);
	cam.SetAABBMinZ(13, 25173.0);

	// Telephones
	cam.SetAABBMaxX(14, 34277.0);
	cam.SetAABBMinX(14, 34157.0);
	cam.SetAABBMaxZ(14, 25344.0);
	cam.SetAABBMinZ(14, 25173.0);

	// Telephones
	cam.SetAABBMaxX(15, 35462.0);
	cam.SetAABBMinX(15, 34541.0);
	cam.SetAABBMaxZ(15, 25344.0);
	cam.SetAABBMinZ(15, 25173.0);

	// Wall by Steps
	cam.SetAABBMaxX(16, 31548.0);
	cam.SetAABBMinX(16, 31444.0);
	cam.SetAABBMaxZ(16, 10395.0);
	cam.SetAABBMinZ(16, 4590.0);
}

//--------------------------------------------------------------------------------------
// Set up co-ordinates of different plains
//--------------------------------------------------------------------------------------
/**
* @breif	Set up co-ordinates of different plains. What this actually means is this is where you assign invisible floors for the player to walk on
* @param	No param
* @return	Void
*/
void CreatePlains()
{	
	//						x1, x2				, y1, y2			, z1, z2
	// grass slope ZY_PLAIN
	cam.SetPlains(ZY_PLAIN, 4848.0, 31568.0		, 9536.0, 10450.0	, 6200.0, 10000.0);

	// flat land (pavement and grass)
	cam.SetPlains (FLAT_PLAIN, 0.0, 36000.0		, 10450.0, 10450.0	, 10000.0, 17000.0);
	cam.SetPlains (FLAT_PLAIN, 0.0, 6500.0		, 10450.0, 10450.0	, 17000.0, 40000.0);
	cam.SetPlains (FLAT_PLAIN, 27000.0, 36000.0 , 10450.0, 10450.0	, 17000.0, 40000.0);
	cam.SetPlains (FLAT_PLAIN, 0.0, 36000.0		, 10450.0, 10450.0	, 40000.0, 50000.0);
	
	// top of lower hill
	cam.SetPlains (FLAT_PLAIN, 9000.0, 22000.0	, 10650.0, 10650.0	, 19000.0, 23000.0);
	cam.SetPlains (FLAT_PLAIN, 9000.0, 10000.0	, 10650.0, 10650.0	, 28000.0, 33000.0);
	cam.SetPlains (FLAT_PLAIN, 9000.0, 22000.0	, 10650.0, 10650.0	, 36000.0, 37000.0);
	// sides of lower hill
	cam.SetPlains (ZY_PLAIN, 6500.0, 27000.0	, 10450.0, 10650.0	, 17000.0, 19000.0);
	cam.SetPlains (ZY_PLAIN, 6500.0, 27000.0	, 10650.0, 10450.0	, 37000.0, 40000.0);
	cam.SetPlains (XY_PLAIN, 6500.0, 9000.0		, 10450.0, 10650.0	, 17000.0, 40000.0);
	cam.SetPlains (XY_PLAIN, 22000.0, 27000.0	, 10650.0, 10450.0	, 17000.0, 40000.0);

	// top of higher hill
	cam.SetPlains (FLAT_PLAIN, 14000.0, 18000.0 , 10875.0, 108075.0	, 28000.0, 33000.0);
	// sides of higher hill
	cam.SetPlains (ZY_PLAIN, 10000.0, 22000.0	, 10650.0, 10875.0	, 23000.0, 28000.0);
	cam.SetPlains (ZY_PLAIN, 10000.0, 22000.0	, 10875.0, 10650.0	, 33000.0, 36000.0);
	cam.SetPlains (XY_PLAIN, 10000.0, 14000.0	, 10650.0, 10875.0	, 23000.0, 36000.0);
	cam.SetPlains (XY_PLAIN, 18000.0, 22000.0	, 10875.0, 10650.0	, 23000.0, 36000.0);

	//entance steps
	step = 10450.0;
	stepLength = 9808.0;
	for (int i = 0; i < 18 ; i ++)
	{
		cam.SetPlains (FLAT_PLAIN, 31582.0, 33835, step, step		, stepLength, stepLength + 42.0);		
		step -= 48.0;
		stepLength -= 142.0;
		if ((i+3) % 5 == 0) 
		{
			stepLength -= 500.0;
			step -= 48.0;
		}
	}

	// temp plain to take down to ECL1
	cam.SetPlains (ZY_PLAIN, 3200.0, 4800.0		, 10450.0, 9370.0	, 53400.0, 57900.0);
}

//--------------------------------------------------------------------------------------
//  Increments frame count used for setting movement speed
//--------------------------------------------------------------------------------------
void IncrementFrameCount()
{
	double t = ((GLdouble)(clock()-lastClock))/(GLdouble)CLOCKS_PER_SEC;  
	frameCount ++;

	// reset after t
	if (t > 0.1)
	{
		stepIncrement = t/frameCount * 1400;
		angleIncrement = t/frameCount;
		frameCount = 0;
		lastClock = clock();
	}
}