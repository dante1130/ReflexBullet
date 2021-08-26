#include <cstdlib>
#include <cmath>
#include <ctime>
#include <GL/glut.h>

#include "camera.h"
#include "texturedPolygons.h"
#include "DisplayShaysWorld.h"
#include "defines.h"
#include "fileIO.h"
#include "Object.h"

//--------------------------------------------------------------------------------------

// USE THESE SETTINGS TO CHANGE SPEED (on different spec computers)
// Set speed (steps)
GLdouble movementSpeed = 50;
GLdouble rotationSpeed = 1;

GLdouble stepIncrement;
GLdouble angleIncrement;
int frameCount = 0;
clock_t lastClock = 0;

// ratio of screen
float ratio;
// screen width and height
int width = 1280, height = 720;

bool paused = true;

// display campus map
bool DisplayMap = false;
// display welcome screen
bool DisplayWelcome = true;
// display exit screen
bool DisplayExit = false;
// display light fittings
bool lightsOn = true;
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
void releaseKeys(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void mouseMove(int x, int y);

void IncrementFrameCount();

// creates bounding boxes for collision detection
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
	glutInitWindowSize(width, height);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keys);
	glutKeyboardUpFunc(releaseKeys);

	glutDisplayFunc(Display);
	glutTimerFunc(FRAMETIME, RenderLoop, 0);

	glutMouseFunc(Mouse);

	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mouseMove);
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

	// set perspective
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
	cam.Position(32720.0, 9536.0, 4800.0, 180.0);

	CreatePlains();

	// creates bounding boxes and places in array
	CreateBoundingBoxes();
	// copies bounding boxes from array to linked lists (one for each quadrant)
	cam.InitiateBoundingBoxes();

	// load texture images and create display lists
	CreateTextureList();
	CreateTextures();

	cam.SetMoveSpeed(movementSpeed);
	cam.SetRotateSpeed(angleIncrement * rotationSpeed);
}

/**
* @brief	Handles all the render steps for the program - still needs work, barebones right now
* @param	val - Currently unused, needed it for glutTimerFunc
* @return	Void
*/
void RenderLoop(int val)
{
	glutTimerFunc(FRAMETIME, RenderLoop, 0);

	if (!paused)
	{
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
	case 'I':
		cam.SetMoveSpeed(movementSpeed);
		break;
	case 'O':
		cam.SetMoveSpeed(movementSpeed * 10);
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
			glutWarpPointer(width / 2, height / 2);
			glutPassiveMotionFunc(mouseMove);
			glutMotionFunc(mouseMove);
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

//--------------------------------------------------------------------------------------
// Set up bounding boxes for collision detection
//--------------------------------------------------------------------------------------
void CreateBoundingBoxes()
{
	cam.SetNoBoundingBoxes(50);

	// chanc block
	cam.SetAABBXZ(0, 35879.0, 22096.0, 33808.0, 4688.0);

	// between chanc block and phys sci
	cam.SetAABBXZ(1, 35999.0, 25344.0, 35730.0, 22096.0);

	// phy sci block panel 1
	cam.SetAABBXZ(2, 35879.0, 26752.0, 33808.0, 25344.0);

	// phy sci block 1st doorway
	cam.SetAABBXZ(3, 35879.0, 27559.0, 34256.0, 26752.0);

	// phy sci block 2nd panel
	cam.SetAABBXZ(4, 35879.0, 36319.0, 33808.0, 27559.0);

	// phy sci block 2nd doorway
	cam.SetAABBXZ(5, 35879.0, 37855.0, 34260.0, 36319.0);

	// phy sci block 3rd panel
	cam.SetAABBXZ(6, 35879.0, 41127.0, 33808.0, 37855.0);

	// drinks machine
	cam.SetAABBXZ(7, 35879.0, 25344.0, 34704.0, 24996.0);

	// bottom of steps
	cam.SetAABBXZ(8, 33808.0, 4688.0, 0.0, 0.0);

	// end of phy sci block exit (top of steps)
	cam.SetAABBXZ(9, 35879.0, 43056.0, 41127.0, 34320.0);

	// library end panel
	cam.SetAABBXZ(10, 34320.0, 50000.0, 6514.0, 43036.0);

	// KBLT
	cam.SetAABBXZ(11, 28104.0, 43046.0, 25608.0, 42754.0);

	// Canteen block
	cam.SetAABBXZ(12, 2608.0, 49046.0, -2580, 9990); //////////////////

	// Telephones
	cam.SetAABBXZ(13, 33892.0, 25344.0, 33872.0, 25173.0);

	// Telephones
	cam.SetAABBXZ(14, 34277.0, 25344.0, 34157.0, 25173.0);

	// Telephones
	cam.SetAABBXZ(15, 35462.0, 25344.0, 34541.0, 25173.0);

	// Wall by Steps
	cam.SetAABBXZ(16, 31548.0, 10395.0, 31444.0, 4590.0);

	//Walters restaurant
	cam.SetAABBXZ(17, 2608.0, 8490, -2580, 0);

	//No modelling area sign
	cam.SetAABBXZ(18, 34520, 43193, 34130, 41136);

	//Other unfinished area
	cam.SetAABBXZ(19, 6812, 45400, 2417, 44600);

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
	cam.SetPlains(ZY_PLAIN, 4848.0, 31568.0, 9536.0, 10450.0, 6200.0, 10000.0);

	// flat land (pavement and grass)
	cam.SetPlains(FLAT_PLAIN, 0.0, 36000.0, 10450.0, 10450.0, 10000.0, 17000.0);
	cam.SetPlains(FLAT_PLAIN, 0.0, 6500.0, 10450.0, 10450.0, 17000.0, 40000.0);
	cam.SetPlains(FLAT_PLAIN, 27000.0, 36000.0, 10450.0, 10450.0, 17000.0, 40000.0);
	cam.SetPlains(FLAT_PLAIN, 0.0, 36000.0, 10450.0, 10450.0, 40000.0, 50000.0);
	
	// top of lower hill
	cam.SetPlains(FLAT_PLAIN, 9000.0, 22000.0, 10650.0, 10650.0, 19000.0, 23000.0);
	cam.SetPlains(FLAT_PLAIN, 9000.0, 10000.0, 10650.0, 10650.0, 28000.0, 33000.0);
	cam.SetPlains(FLAT_PLAIN, 9000.0, 22000.0, 10650.0, 10650.0, 36000.0, 37000.0);
	// sides of lower hill
	cam.SetPlains(ZY_PLAIN, 6500.0, 27000.0, 10450.0, 10650.0, 17000.0, 19000.0);
	cam.SetPlains(ZY_PLAIN, 6500.0, 27000.0, 10650.0, 10450.0, 37000.0, 40000.0);
	cam.SetPlains(XY_PLAIN, 6500.0, 9000.0, 10450.0, 10650.0, 17000.0, 40000.0);
	cam.SetPlains(XY_PLAIN, 22000.0, 27000.0, 10650.0, 10450.0, 17000.0, 40000.0);

	// top of higher hill
	cam.SetPlains(FLAT_PLAIN, 14000.0, 18000.0, 10875.0, 108075.0, 28000.0, 33000.0);
	// sides of higher hill
	cam.SetPlains(ZY_PLAIN, 10000.0, 22000.0, 10650.0, 10875.0, 23000.0, 28000.0);
	cam.SetPlains(ZY_PLAIN, 10000.0, 22000.0, 10875.0, 10650.0, 33000.0, 36000.0);
	cam.SetPlains(XY_PLAIN, 10000.0, 14000.0, 10650.0, 10875.0, 23000.0, 36000.0);
	cam.SetPlains(XY_PLAIN, 18000.0, 22000.0, 10875.0, 10650.0, 23000.0, 36000.0);

	// Missing big step
	cam.SetPlains(FLAT_PLAIN, 31582, 33835, 10258, 10258, 9000, 9300);

	// Missing step 4th step from the top
	cam.SetPlains(FLAT_PLAIN, 31582, 33835, 10300, 10300, 9400, 9490);

	//entrance steps
	step = 10450.0;
	stepLength = 9808.0;
	for (int i = 0; i < 18; i++)
	{
		cam.SetPlains(FLAT_PLAIN, 31582.0, 33835, step, step, stepLength, stepLength + 42.0);
		step -= 48.0;
		stepLength -= 142.0;
		if ((i + 3) % 5 == 0)
		{
			stepLength -= 500.0;
			step -= 48.0;
		}
	}

	// temp plain to take down to ECL1
	cam.SetPlains(ZY_PLAIN, 3200.0, 4800.0, 10450.0, 9370.0, 53400.0, 57900.0);
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
