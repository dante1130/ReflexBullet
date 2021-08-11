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
GLdouble movementSpeed = 4.0;
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

// varibles used for tarnslating graphics etc
//GLdouble step, step2, stepLength;

// Glut Cylinder
//GLUquadricObj *glu_cylinder;

// Stores raw image file
unsigned char* image = NULL;

// objects
Camera cam;
//TexturedPolygons tp;

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

// loads images and creates texture
void CreateTextures();
// creates bounding boxes for collsion detection
void CreateBoundingBoxes();
// creates different plains
void CreatePlains();

// deletes image and clears memory
void DeleteImageFromMemory(unsigned char* tempImage);

//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	std::cout << "Hello World!" << std::endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardUpFunc (releaseKeys);
	glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);
	

	glutPassiveMotionFunc(mouseMove);
	//ShowCursor(FALSE);

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
	glClearColor(97.0/255.0, 140.0/255.0, 185.0/255.0, 1.0);
	
	// set perpsective
	gluLookAt(0.0, 1.75, 0.0, 
		      0.0, 1.75, -1,
			  0.0f,1.0f,0.0f);
	
	// settings for glut cylinders
	glu_cylinder = gluNewQuadric();
    gluQuadricTexture(glu_cylinder, GL_TRUE );

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

//--------------------------------------------------------------------------------------
//  Main Display Function
//--------------------------------------------------------------------------------------
void Display()
{
	// check for movement
	cam.CheckCamera();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// DISPLAY TEXTURES
	//enable texture mapping
	glEnable (GL_TEXTURE_2D);
	glPushMatrix();	
		// displays the welcome screen
		if (DisplayWelcome) cam.DisplayWelcomeScreen (width, height, 1, tp.GetTexture(WELCOME));	
		// displays the exit screen
		if (DisplayExit) cam.DisplayWelcomeScreen (width, height, 0, tp.GetTexture(EXIT) );
		// displays the map
		if (DisplayMap) cam.DisplayMap(width, height, tp.GetTexture(MAP));
		// display no exit sign (position check should really be in an object, but didn't have time)
		if ((cam.GetLR() > 35500.0) && (cam.GetFB() < 25344.0) ||
			(cam.GetLR() > 34100.0) && (cam.GetFB() > 41127.0))
		{
			cam.DisplayNoExit(width, height,tp.GetTexture(NO_EXIT));
		}
				// set the movement and rotation speed according to frame count
		IncrementFrameCount();
		cam.SetMoveSpeed (stepIncrement * movementSpeed);
		cam.SetRotateSpeed (angleIncrement * rotationSpeed);
		// display images
		DrawBackdrop(lightsOn);
	glPopMatrix();
	glDisable (GL_TEXTURE_2D); 

	// clear buffers
	glFlush();
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
	gluPerspective(45,ratio,1,250000);	
	glMatrixMode(GL_MODELVIEW);
}

//--------------------------------------------------------------------------------------
void keys(unsigned char key, int x, int y)
{
	int i = 0;
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
		
	// Display ECL Block
	case 'P':
	case 'p':	
		if (displayECL)
		{
			displayECL = false;
		}
		else
		{
			displayECL = true;
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
		case 'd' :
		case 'D' :
			cam.DirectionLR(0);
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
			DeleteImageFromMemory(image);
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
void CreatePlains()
{	
	// grass slope
	cam.SetPlains (ZY_PLAIN, 4848.0 ,31568.0 ,9536.0, 10450.0 ,6200.0, 10000.0);

	// flat land (pavement and grass)
	cam.SetPlains (FLAT_PLAIN, 0.0, 36000.0 , 10450.0, 10450.0, 10000.0, 17000.0);
	cam.SetPlains (FLAT_PLAIN, 0.0, 6500.0 , 10450.0, 10450.0, 17000.0, 40000.0);
	cam.SetPlains (FLAT_PLAIN, 27000.0, 36000.0 , 10450.0, 10450.0, 17000.0, 40000.0);
	cam.SetPlains (FLAT_PLAIN, 0.0, 36000.0 , 10450.0, 10450.0, 40000.0, 50000.0);
	
	// top of lower hill
	cam.SetPlains (FLAT_PLAIN, 9000.0, 22000.0 , 10650.0, 10650.0, 19000.0, 23000.0);
	cam.SetPlains (FLAT_PLAIN, 9000.0, 10000.0 , 10650.0, 10650.0, 28000.0, 33000.0);
	cam.SetPlains (FLAT_PLAIN, 9000.0, 22000.0 , 10650.0, 10650.0, 36000.0, 37000.0);
	// sides of lower hill
	cam.SetPlains (ZY_PLAIN, 6500.0, 27000.0 , 10450.0, 10650.0, 17000.0, 19000.0);
	cam.SetPlains (ZY_PLAIN, 6500.0, 27000.0 , 10650.0, 10450.0, 37000.0, 40000.0);
	cam.SetPlains (XY_PLAIN, 6500.0, 9000.0 , 10450.0, 10650.0, 17000.0, 40000.0);
	cam.SetPlains (XY_PLAIN, 22000.0, 27000.0 , 10650.0, 10450.0, 17000.0, 40000.0);

	// top of higher hill
	cam.SetPlains (FLAT_PLAIN, 14000.0, 18000.0 , 10875.0, 108075.0, 28000.0, 33000.0);
	// sides of higher hill
	cam.SetPlains (ZY_PLAIN, 10000.0, 22000.0 , 10650.0, 10875.0, 23000.0, 28000.0);
	cam.SetPlains (ZY_PLAIN, 10000.0, 22000.0 , 10875.0, 10650.0, 33000.0, 36000.0);
	cam.SetPlains (XY_PLAIN, 10000.0, 14000.0 , 10650.0, 10875.0, 23000.0, 36000.0);
	cam.SetPlains (XY_PLAIN, 18000.0, 22000.0 , 10875.0, 10650.0, 23000.0, 36000.0);

	//entance steps
	step = 10450.0;
	stepLength = 9808.0;
	for (int i = 0; i < 18 ; i ++)
	{
		cam.SetPlains (FLAT_PLAIN, 31582.0, 33835, step, step, stepLength, stepLength + 42.0);		
		step -= 48.0;
		stepLength -= 142.0;
		if ((i+3) % 5 == 0) 
		{
			stepLength -= 500.0;
			step -= 48.0;
		}
	}

	// temp plain to take down to ECL1
	cam.SetPlains (ZY_PLAIN, 3200.0, 4800.0 , 10450.0, 9370.0, 53400.0, 57900.0);
}

//--------------------------------------------------------------------------------------
//  Delete raw image and clear memory
//--------------------------------------------------------------------------------------
void DeleteImageFromMemory(unsigned char* tempImage)
{
	tempImage = NULL;
		if (tempImage == NULL)
	{
		delete [] tempImage;
	}
}

//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// Load and Create Textures
//--------------------------------------------------------------------------------------
void CreateTextures()
{
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	// set texture count
	tp.SetTextureCount(250);

	// load and create textures
	image = tp.LoadTexture("data/abovechanctext.raw", 128, 1024);
	tp.CreateTexture(ABOVE_CHANC_TEXT, image, 128, 1024);

	image = tp.LoadTexture("data/abovechanctext2.raw", 128, 1024);
	tp.CreateTexture(ABOVE_CHANC_TEXT_2, image, 128, 1024);

	image = tp.LoadTexture("data/abovechanctext3.raw", 128, 1024);
	tp.CreateTexture(ABOVE_CHANC_TEXT_3, image, 128, 1024);

	image = tp.LoadTexture("data/aboveLibText.raw", 1024, 256);
	tp.CreateTexture(ABOVE_LIB_TEXT, image, 1024, 256);

	image = tp.LoadTexture("data/aboveLibraryText2.raw", 1024, 256);
	tp.CreateTexture(ABOVE_LIB_TEXT_2, image, 1024, 256);

	image = tp.LoadTexture("data/aboveUnder4B.raw",256, 128);
	tp.CreateTexture(ABOVE_UNDER_4B, image, 256, 128);

	image = tp.LoadTexture("data/aboveWindows.raw", 128, 256);
	tp.CreateTexture(ABOVE_WINDOW_BLOCK, image, 128, 256);

	image = tp.LoadTexture("data/aboveWindows2.raw", 128, 256);
	tp.CreateTexture(ABOVE_WINDOW_BLOCK_2, image, 128, 256);

	image = tp.LoadTexture("data/aboveWindowsChanc.raw", 128, 256);
	tp.CreateTexture(ABOVE_WINDOW_BLOCK_CHANC, image, 128, 256);

	image = tp.LoadTexture("data/aboveWindows2posts.raw", 128, 256);
	tp.CreateTexture(ABOVE_UNDER_POSTS, image, 128, 256);
	
	image = tp.LoadTexture("data/aboveWindows2posts2.raw", 128, 256);
	tp.CreateTexture(ABOVE_UNDER_POSTS_2, image, 256, 128);

	image = tp.LoadTexture("data/aboveWindowsLib.raw", 256, 256);
	tp.CreateTexture(ABOVE_LIB, image, 256, 256);

	image = tp.LoadTexture("data/aboveWindows2lib.raw", 256, 128);
	tp.CreateTexture(ABOVE_WINDOW_UNDER_LIB, image, 256, 128);

	image = tp.LoadTexture("data/aboveWindows3bricks.raw", 256, 256);
	tp.CreateTexture(ABOVE_WINDOW_BLOCK_3, image, 256, 256);

	image = tp.LoadTexture("data/abovephysscitext.raw", 256, 1024);
	tp.CreateTexture(ABOVE_PHYS_SCI_TEXT, image, 256, 1024);

	image = tp.LoadTexture("data/aboveWindows3bricksXY.raw", 256, 256);
	tp.CreateTexture(ABOVE_WINDOW_BLOCK_XY_3, image, 256, 256);

	image = tp.LoadTexture("data/aboveWindowEdge.raw", 128, 256);
	tp.CreateTexture(ABOVE_WINDOW_EDGE_3B, image, 128, 256);

	image = tp.LoadTexture("data/aboveWindowEdgeLib.raw", 256, 64);
	tp.CreateTexture(ABOVE_WINDOW_EDGE_3B_LIB, image, 256, 64);

	image = tp.LoadTexture("data/aboveWindowsLibEdge.raw", 256, 64);
	tp.CreateTexture(ABOVE_WINDOW_EDGE_4B_LIB, image, 256, 64);

	image = tp.LoadTexture("data/aboveTicketsText.raw", 256, 256);
	tp.CreateTexture(ABOVE_TICKETS_TEXT, image, 256, 256);

	image = tp.LoadTexture("data/aboveWindowsEdge.raw", 128, 128);
	tp.CreateTexture(ABOVE_CHANC_EDGE, image, 128, 128);

	image = tp.LoadTexture("data/belowrooffill.raw", 128, 256);
	tp.CreateTexture(BELOW_ROOF_FILL, image, 128, 256);

	image = tp.LoadTexture("data/bench.raw", 64, 64);
	tp.CreateTexture(BENCH_TOP, image, 64, 64);

	image = tp.LoadTexture("data/benchedgeside.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE_SIDE, image, 64, 64);

	image = tp.LoadTexture("data/benchedge.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE, image, 64, 64);

	image = tp.LoadTexture("data/benchedgetop.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE_TOP, image, 64, 64);

	image = tp.LoadTexture("data/benchedge2.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE_2, image, 64, 64);

	image = tp.LoadTexture("data/benchedge3.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE_3, image, 64, 64);

	image = tp.LoadTexture("data/benchedgetop2.raw", 64, 64);
	tp.CreateTexture(BENCH_EDGE_TOP_2, image, 64, 64);

	image = tp.LoadTexture("data/benchside.raw", 64, 64);
	tp.CreateTexture(BENCH_SIDE, image, 64, 64);

	image = tp.LoadTexture("data/benchside2.raw", 64, 64);
	tp.CreateTexture(BENCH_SIDE_2, image, 64, 64);

	image = tp.LoadTexture("data/bricks1.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_YZ, image, 128, 128);

	image = tp.LoadTexture("data/bricks2.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_XY, image, 128, 128);

	image = tp.LoadTexture("data/bricks2edge.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_XY_END, image, 128, 128);

	image = tp.LoadTexture("data/bricks1edge.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_YZ_END, image, 128, 128);

	image = tp.LoadTexture("data/bricks075.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_3_4, image, 128, 128);

	image = tp.LoadTexture("data/brick87.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_XY_87WIDTH, image, 128, 128);

	image = tp.LoadTexture("data/brickgap.raw", 128, 32);
	tp.CreateTexture(WALL_BRICK_GAP_YZ, image, 128, 32);

	image = tp.LoadTexture("data/brickgap2.raw", 128, 32);
	tp.CreateTexture(WALL_BRICK_GAP2_YZ, image, 128, 32);
	
	image = tp.LoadTexture("data/bricksecsign.raw", 256, 128);
	tp.CreateTexture(WALL_BRICK_SEC_SIGN, image, 256, 128);

	image = tp.LoadTexture("data/brickshadow.raw", 128, 128);
	tp.CreateTexture(SHADOW_BRICK, image, 128, 128);

	image = tp.LoadTexture("data/bricksUSD.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_USD_YZ, image, 128, 128);

	image = tp.LoadTexture("data/carpet.raw", 32, 32);
	tp.CreateTexture(CARPET, image, 32, 32);

	image = tp.LoadTexture("data/coffeeMachine.raw", 128, 256);
	tp.CreateTexture(COFFEE_MACHINE, image, 128, 256);

	image = tp.LoadTexture("data/cokeMachine.raw", 128, 256);
	tp.CreateTexture(COKE_MACHINE, image, 128, 256);

	image = tp.LoadTexture("data/COsign.raw", 256, 128);
	tp.CreateTexture(CO_SIGN, image, 256, 128);

	image = tp.LoadTexture("data/counterside.raw", 4, 16);
	tp.CreateTexture(COUNTER_SIDE, image, 4, 16);

	image = tp.LoadTexture("data/countertop.raw", 1, 1);
	tp.CreateTexture(COUNTER_TOP, image, 1, 1);

	image = tp.LoadTexture("data/drainpipe.raw", 32, 2);
	tp.CreateTexture(DRAINPIPE, image, 32, 2);

	image = tp.LoadTexture("data/drinksEdge.raw", 16, 2);
	tp.CreateTexture(DRINKS_EDGE, image, 16, 2);

	image = tp.LoadTexture("data/drinksSide.raw", 64, 64);
	tp.CreateTexture(DRINKS_SIDE, image, 64, 64);

	image = tp.LoadTexture("data/drinksSide2.raw", 64, 64);
	tp.CreateTexture(DRINKS_SIDE_2, image, 64, 64);
	
	image = tp.LoadTexture("data/drinksSidetop.raw", 64, 64);
	tp.CreateTexture(DRINKS_TOP, image, 64, 64);

	image = tp.LoadTexture("data/doorpave1.raw",  128, 256);
	tp.CreateTexture(DOORPAVE_1, image, 128, 256);

	image = tp.LoadTexture("data/doorpost1.raw", 1024, 128);
	tp.CreateTexture(DOOR_POST_CHANC, image, 1024, 128);

	image = tp.LoadTexture("data/doorpostSec.raw", 1024, 128);
	tp.CreateTexture(DOOR_POST_SECURITY, image, 1024, 128);

	image = tp.LoadTexture("data/doorpostside1.raw", 64, 1024);
	tp.CreateTexture(DOOR_SIDEPOST_CHANC, image, 64, 1024);

	image = tp.LoadTexture("data/doorPostLibSide.raw", 512, 64);
	tp.CreateTexture(DOOR_POST_LIB, image, 512, 64);

	image = tp.LoadTexture("data/glassboard.raw", 512, 256);
	tp.CreateTexture(GLASS_BOARD, image, 512, 256);

	image = tp.LoadTexture("data/glassboard2.raw", 512, 256);
	tp.CreateTexture(GLASS_BOARD_2, image, 512, 256);

	image = tp.LoadTexture("data/glassboard3.raw", 512, 256);
	tp.CreateTexture(GLASS_BOARD_3, image, 512, 256);

	image = tp.LoadTexture("data/glassboardSide.raw", 2, 16);
	tp.CreateTexture(GLASS_B_SIDE, image, 2, 16);

	image = tp.LoadTexture("data/grass.raw", 64, 64);
	tp.CreateTexture(GRASS, image, 64, 64);

	image = tp.LoadTexture("data/grass2.raw", 64, 64);
	tp.CreateTexture(GRASS_2, image, 64, 64);

	image = tp.LoadTexture("data/grass3.raw", 64, 64);
	tp.CreateTexture(GRASS_HILL, image, 64, 64);

	image = tp.LoadTexture("data/GSsign.raw", 256, 256);
	tp.CreateTexture(GS_SIGN, image, 256, 256);

	image = tp.LoadTexture("data/GSsign2.raw", 256, 256);
	tp.CreateTexture(GS_SIGN_2, image, 256, 256);

	image = tp.LoadTexture("data/GSsignedge.raw", 256, 64);
	tp.CreateTexture(GS_SIGN_EDGE, image, 256, 64);

	image = tp.LoadTexture("data/kbl.raw", 512, 256);
	tp.CreateTexture(KBLT, image, 512, 256);

	image = tp.LoadTexture("data/KBLTside1.raw", 2, 128);
	tp.CreateTexture(KBLT_SIDE_1, image, 2, 128);

	image = tp.LoadTexture("data/KBLTside2.raw", 2, 2);
	tp.CreateTexture(KBLT_SIDE_2, image, 2, 2);
	
	image = tp.LoadTexture("data/kblCorner.raw", 1, 1);
	tp.CreateTexture(KBLT_EDGE_CORNER, image, 1, 1);

	image = tp.LoadTexture("data/kbltEdge.raw", 16, 32);
	tp.CreateTexture(KBLT_EDGE, image, 16, 32);

	image = tp.LoadTexture("data/kbltEdge2.raw", 32, 16);
	tp.CreateTexture(KBLT_EDGE_2, image, 32, 16);

	image = tp.LoadTexture("data/light.raw", 256, 64);
	tp.CreateTexture(LIGHT, image, 256, 64);

	image = tp.LoadTexture("data/lightsupport.raw", 8, 2);
	tp.CreateTexture(LIGHT_SUPPORT, image, 8, 2);

	image = tp.LoadTexture("data/lightsupport2.raw", 2, 8);
	tp.CreateTexture(LIGHT_SUPPORT_2, image, 2, 8);

	image = tp.LoadTexture("data/machineSides.raw", 1, 1);
	tp.CreateTexture(MACHINE_SIDES, image, 1, 1);

	image = tp.LoadTexture("data/machineSides2.raw", 1, 1);
	tp.CreateTexture(MACHINE_SIDES_2, image, 1, 1);

	image = tp.LoadTexture("data/mainPost.raw",  128, 256);
	tp.CreateTexture(MAIN_POST, image, 128, 256);
	
	image = tp.LoadTexture("data/mainPost2.raw", 256, 128);
	tp.CreateTexture(MAIN_POST_2, image, 256, 128);

	image = tp.LoadTexture("data/map2.raw", 256, 512);
	tp.CreateTexture(MAP_2, image, 256, 512);

	image = tp.LoadTexture("data/nexus.raw", 512, 256);
	tp.CreateTexture(NEXUS_SIGN, image, 512, 256);

	image = tp.LoadTexture("data/nexusSide.raw", 2, 16);
	tp.CreateTexture(NEXUS_SIDE, image, 2, 16);

	image = tp.LoadTexture("data/noexit.raw", 256, 64);
	tp.CreateTexture(NO_EXIT, image, 256, 64);

	image = tp.LoadTexture("data/nosmokesign.raw", 256, 128);
	tp.CreateTexture(NO_SMOKE_SIGN, image, 256, 128);

	image = tp.LoadTexture("data/pavement.raw", 128, 64);
	tp.CreateTexture(PAVEMENT, image, 128, 64);

	image = tp.LoadTexture("data/pavement16.raw", 32, 64);
	tp.CreateTexture(PAVEMENT_16, image, 32, 64);

	image = tp.LoadTexture("data/pavementflip.raw", 128, 64);
	tp.CreateTexture(PAVEMENT_FLIP, image, 128, 64);

	image = tp.LoadTexture("data/pavementcorner1.raw", 128, 128);
	tp.CreateTexture(PAVEMENT_CORNER_1, image, 128, 128);

	image = tp.LoadTexture("data/pavementcorner2.raw", 128, 128);
	tp.CreateTexture(PAVEMENT_CORNER_2, image, 128, 128);

	image = tp.LoadTexture("data/pavementtop.raw", 64, 128);
	tp.CreateTexture(PAVEMENT_TOP, image, 64, 128);

	image = tp.LoadTexture("data/pavementtopflip.raw", 64, 128);
	tp.CreateTexture(PAVEMENT_TOP_FLIP, image, 64, 128);

	image = tp.LoadTexture("data/pavementSide.raw", 64, 64);
	tp.CreateTexture(PAVEMENTSIDE_LEFT, image, 64, 64);

	image = tp.LoadTexture("data/pavementSide2.raw", 64, 64);
	tp.CreateTexture(PAVEMENTSIDE_RIGHT, image, 64, 64);

	image = tp.LoadTexture("data/pavementSide3.raw", 64, 64);
	tp.CreateTexture(PAVEMENTSIDE_TOP, image, 64, 64);

	image = tp.LoadTexture("data/phonefront.raw", 512, 32);
	tp.CreateTexture(TELEPHONE_FRONT, image, 512, 32);
	
	image = tp.LoadTexture("data/phoneside1.raw", 32, 256);
	tp.CreateTexture(TELEPHONE_SIDE_1, image, 32, 256);	

	image = tp.LoadTexture("data/phonefront2.raw", 512, 16);
	tp.CreateTexture(TELEPHONE_FRONT_2, image, 512, 16);	
	
	image = tp.LoadTexture("data/phonemainside.raw", 512, 256);
	tp.CreateTexture(TELEPHONE_MAIN_SIDE, image, 512, 256);
	
	image = tp.LoadTexture("data/phonetop1.raw", 512, 128);
	tp.CreateTexture(TELEPHONE_TOP_1, image, 512, 128);

	image = tp.LoadTexture("data/phoneside2.raw", 16, 256);
	tp.CreateTexture(TELEPHONE_SIDE_2, image, 16, 256);

	image = tp.LoadTexture("data/phonetop2.raw", 128, 256);
	tp.CreateTexture(TELEPHONE_TOP_2, image, 128, 256);

	image = tp.LoadTexture("data/phonebottom.raw", 512, 128);
	tp.CreateTexture(TELEPHONE_BOTTOM, image, 512, 128);

	image = tp.LoadTexture("data/phoneFill.raw", 2, 2);
	tp.CreateTexture(TELEPHONE_FILL, image, 2, 2);

	image = tp.LoadTexture("data/phonefront3.raw", 16, 512);
	tp.CreateTexture(TELEPHONE_FRONT_3, image, 16, 512);

	image = tp.LoadTexture("data/PSCsign.raw", 256, 128);
	tp.CreateTexture(PSC_SIGN, image, 256, 128);
	
	image = tp.LoadTexture("data/PSCsign2.raw", 256, 128);
	tp.CreateTexture(PSC_SIGN_2, image, 256, 128);

	image = tp.LoadTexture("data/purplepost.raw", 64, 128);
	tp.CreateTexture(PURPLE_POST, image, 64 ,128);
	
	image = tp.LoadTexture("data/purplepostside.raw", 128, 64);
	tp.CreateTexture(PURPLE_POSTSIDE, image, 128, 64);

	image = tp.LoadTexture("data/redpost.raw", 64, 128);
	tp.CreateTexture(RED_POST, image, 64 ,128);
	
	image = tp.LoadTexture("data/redpostside.raw", 64, 64);
	tp.CreateTexture(RED_POSTSIDE, image, 64, 64);

	image = tp.LoadTexture("data/roofbeam1.raw", 128, 32);
	tp.CreateTexture(ROOF_BEAM_1, image, 128, 32);

	image = tp.LoadTexture("data/roofbeam2.raw", 32, 128);
	tp.CreateTexture(ROOF_BEAM_2, image, 32, 128);

	image = tp.LoadTexture("data/roofbeam3.raw", 64, 128);
	tp.CreateTexture(ROOF_BEAM_3, image, 64, 128);

	image = tp.LoadTexture("data/roofbeam3top.raw", 128, 128);
	tp.CreateTexture(ROOF_BEAM_3_TOP, image, 128, 128);

	image = tp.LoadTexture("data/roofbeam4.raw", 128, 64);
	tp.CreateTexture(ROOF_BEAM_4, image, 128, 64);

	image = tp.LoadTexture("data/roofPlanks.raw", 128, 128);
	tp.CreateTexture(ROOF_PLANKS, image, 128, 128);

	image = tp.LoadTexture("data/roofPlanks2.raw", 128, 128);
	tp.CreateTexture(ROOF_PLANKS_2, image, 128, 128);

	image = tp.LoadTexture("data/rooftop.raw", 2, 128);
	tp.CreateTexture(ROOF_TOP, image, 2, 128);

	image = tp.LoadTexture("data/rooftoplib.raw", 128, 2);
	tp.CreateTexture(ROOF_TOP_LIB, image, 128, 2);

	image = tp.LoadTexture("data/rustyman.raw", 256, 1024);
	tp.CreateTexture(RUSTY_MAN, image, 256, 1024);

	image = tp.LoadTexture("data/securitysign1.raw", 128, 128);
	tp.CreateTexture(SECURITY_SIGN, image, 128, 128);

	image = tp.LoadTexture("data/securitysign2.raw", 128, 128);
	tp.CreateTexture(SECURITY_SIGN_2, image, 128, 128);

	image = tp.LoadTexture("data/sign1.raw", 512, 256);
	tp.CreateTexture(SIGN_1, image, 512, 256);
	
	image = tp.LoadTexture("data/sign1side1.raw", 16, 512);
	tp.CreateTexture(SIGN_1_SIDE_1, image, 16, 512);

	image = tp.LoadTexture("data/sign1side2.raw", 16, 512);
	tp.CreateTexture(SIGN_1_SIDE_2, image, 16, 512);

	image = tp.LoadTexture("data/sign2.raw", 512, 512);
	tp.CreateTexture(SIGN_2, image, 512, 512);

	image = tp.LoadTexture("data/sign2side.raw", 512, 16);
	tp.CreateTexture(SIGN_2_SIDE, image, 512, 16);

	image = tp.LoadTexture("data/statravel.raw", 256, 256);
	tp.CreateTexture(STA_TRAVEL, image, 256, 256);

	image = tp.LoadTexture("data/statraveledge.raw", 256, 64);
	tp.CreateTexture(STA_TRAVEL_EDGE, image, 256, 64);

	image = tp.LoadTexture("data/statravelbracket.raw", 16, 2);
	tp.CreateTexture(STA_TRAVEL_BRACKET, image, 16, 2);

	image = tp.LoadTexture("data/statravel2.raw", 256, 256);
	tp.CreateTexture(STA_TRAVEL_2, image, 256, 256);

	image = tp.LoadTexture("data/statravelbottom.raw", 2, 64);
	tp.CreateTexture(STA_TRAVEL_BOTTOM, image, 2, 64);

	image = tp.LoadTexture("data/stepbricks.raw", 128, 128);
	tp.CreateTexture(WALL_BRICK_STEPS, image, 128, 128);

	image = tp.LoadTexture("data/stepbrickscover.raw", 64, 128);
	tp.CreateTexture(WALL_BRICK_STEPS_COVER, image, 64, 128);

	image = tp.LoadTexture("data/stepbricksedge.raw", 64, 32);
	tp.CreateTexture(WALL_BRICK_STEPS_EDGE, image, 64, 32);
	
	image = tp.LoadTexture("data/stepbricksedge2.raw", 64, 64);
	tp.CreateTexture(WALL_BRICK_STEPS_EDGE_2, image, 64, 64);

	image = tp.LoadTexture("data/stepbrickstop.raw", 32, 128);
	tp.CreateTexture(WALL_BRICK_STEPS_TOP, image, 32, 128);

	image = tp.LoadTexture("data/stepslibrary.raw", 128, 1024);
	tp.CreateTexture(STEPS_LIBRARY, image, 128, 1024);
	
	image = tp.LoadTexture("data/stepslibrarytop.raw", 256, 1024);
	tp.CreateTexture(STEPS_LIBRARY_TOP, image, 256, 1024);

	image = tp.LoadTexture("data/steppaving1.raw", 1024, 512);
	tp.CreateTexture(STEP_PAVING_1, image, 1024, 512);

	image = tp.LoadTexture("data/steppavingedge.raw", 64, 64);
	tp.CreateTexture(STEP_EDGE, image, 64, 64);

	image = tp.LoadTexture("data/sweetMachine.raw", 256, 256);
	tp.CreateTexture(SWEET_MACHINE, image, 256, 256);

	image = tp.LoadTexture("data/telephoneback.raw", 512, 512);
	tp.CreateTexture(TELEPHONE_BACK, image, 512, 512);

	image = tp.LoadTexture("data/ticketcounteredge2.raw", 64, 64);
	tp.CreateTexture(TICKET_COUNTER_EDGE_2, image, 64, 64);

	image = tp.LoadTexture("data/ticketcounteredge3.raw", 64, 64);
	tp.CreateTexture(TICKET_COUNTER_EDGE_3, image, 64, 64);

	image = tp.LoadTexture("data/ticketcountertop.raw", 128, 256);
	tp.CreateTexture(TICKET_COUNTER_TOP, image, 128, 256);

	image = tp.LoadTexture("data/ticketledgeedge.raw", 2, 32);
	tp.CreateTexture(TICKET_LEDGE_EDGE, image, 2, 32);

	image = tp.LoadTexture("data/ticketledge.raw", 2, 128);
	tp.CreateTexture(TICKET_LEDGE, image, 2, 128);

	image = tp.LoadTexture("data/ticketledgeedge2.raw", 32, 2);
	tp.CreateTexture(TICKET_LEDGE_EDGE_2, image, 32, 2);

	image = tp.LoadTexture("data/ticketcounteredge.raw", 128, 32);
	tp.CreateTexture(TICKET_COUNTER_EDGE, image, 128, 32);

	image = tp.LoadTexture("data/toiletdoortop.raw", 32, 256);
	tp.CreateTexture(TOILET_DOOR_TOP, image, 32, 256);

	image = tp.LoadTexture("data/toiletmen.raw", 128, 128);
	tp.CreateTexture(TOILET_MEN, image, 128, 128);

	image = tp.LoadTexture("data/toiletwomen.raw", 128, 128);
	tp.CreateTexture(TOILET_WOMEN, image, 128, 128);

	image = tp.LoadTexture("data/wallgap1.raw", 8, 128);
	tp.CreateTexture(WALL_GAP_1, image, 8, 128);

	image = tp.LoadTexture("data/windowledge1.raw", 32, 1024);
	tp.CreateTexture(WINDOWLEDGE_CHANC_FRONT, image, 32, 1024);

	image = tp.LoadTexture("data/windowledge2.raw", 128, 1024);
	tp.CreateTexture(WINDOWLEDGE_CHANC_TOP, image, 128, 1024);

	image = tp.LoadTexture("data/windowledgeend.raw", 32, 64);
	tp.CreateTexture(WINDOW_LEDGE_END_1, image, 32, 64);

	image = tp.LoadTexture("data/windowledgeend2.raw", 64, 64);
	tp.CreateTexture(WINDOW_LEDGE_END_2, image, 64, 64);

	image = tp.LoadTexture("data/windowledgeLibfa.raw", 1024, 32);
	tp.CreateTexture(WINDOWLEDGE_LIB_A, image, 1024, 32);

	image = tp.LoadTexture("data/windowledgeLibfb.raw", 1024, 32);
	tp.CreateTexture(WINDOWLEDGE_LIB_B, image, 1024, 32);


	image = tp.LoadTexture("data/windowledgeLibta.raw", 1024, 128);
	tp.CreateTexture(WINDOWLEDGE_LIB_TOP_A, image, 1024, 128);

	image = tp.LoadTexture("data/windowledgeLibtb.raw", 1024, 128);
	tp.CreateTexture(WINDOWLEDGE_LIB_TOP_B, image, 1024, 128);

	image = tp.LoadTexture("data/windowledgeUS1.raw", 32, 1024);
	tp.CreateTexture(WINDOWLEDGE_PS_FRONT, image, 32, 1024);

	image = tp.LoadTexture("data/windowledgeUS2.raw", 128, 1024);
	tp.CreateTexture(WINDOWLEDGE_PS_TOP, image, 128, 1024);

	image = tp.LoadTexture("data/windowledgeUS3.raw", 128, 1024);
	tp.CreateTexture(WINDOWLEDGE_PS_BOTT, image, 128, 1024);

	image = tp.LoadTexture("data/windowpost1.raw", 1024, 128);
	tp.CreateTexture(WINDOWPOST_CHANC_FRONT, image, 1024, 128);

	image = tp.LoadTexture("data/windowpostsmall.raw", 512, 128);
	tp.CreateTexture(WINDOWPOST_PHYSSCI_FRONT, image, 512, 128);

	image = tp.LoadTexture("data/windowpostsmallside2.raw", 64, 512);
	tp.CreateTexture(WINDOWPOST_PHYSSCI_RIGHT, image, 64, 512);

	image = tp.LoadTexture("data/windowpostsmallside.raw", 64, 512);
	tp.CreateTexture(WINDOWPOST_PHYSSCI_LEFT, image, 64, 512);
	
	image = tp.LoadTexture("data/windowpostLib.raw", 128, 512);
	tp.CreateTexture(WINDOWPOST_LIB_FRONT, image, 128, 512);

	image = tp.LoadTexture("data/windowpostLibside1.raw", 512, 64);
	tp.CreateTexture(WINDOWPOST_LIB_LEFT, image, 512, 64);

	image = tp.LoadTexture("data/windowpostLibside2.raw", 512, 64);
	tp.CreateTexture(WINDOWPOST_LIB_RIGHT, image, 512, 64);

	image = tp.LoadTexture("data/windowposthalf1.raw", 64, 1024);
	tp.CreateTexture(WINDOWPOST_CHANC_RIGHT, image, 64, 1024);
	
	image = tp.LoadTexture("data/windowposthalf2.raw", 64, 1024);
	tp.CreateTexture(WINDOWPOST_CHANC_LEFT, image, 64, 1024);

	// Larger Textures

	image = tp.LoadTexture("data/windows/stepwindow.raw", 128, 256);
	tp.CreateTexture(STEP_WINDOW, image, 128, 256);
	
	image = tp.LoadTexture("data/windows/chancDoor1.raw", 256, 256);
	tp.CreateTexture(CHANC_DOOR_1, image, 256, 256);

	image = tp.LoadTexture("data/windows/chancDoor2.raw", 256, 256);
	tp.CreateTexture(CHANC_DOOR_2, image, 256, 256);

	image = tp.LoadTexture("data/windows/entrance.raw", 512, 256);
	tp.CreateTexture(ENTRANCE, image, 512, 256);

	image = tp.LoadTexture("data/windows/entrance2.raw",512, 512);
	tp.CreateTexture(ENTRANCE_2, image, 512, 512);
	
	image = tp.LoadTexture("data/windows/exiteast.raw", 512, 512);
	tp.CreateTexture(EXIT_EAST, image, 512, 512);

	image = tp.LoadTexture("data/windows/exitwest.raw", 256, 512);
	tp.CreateTexture(EXIT_WEST, image, 256, 512);

	image = tp.LoadTexture("data/windows/window1.raw", 256, 256);
	tp.CreateTexture(WINDOW_1, image, 256, 256);

	image = tp.LoadTexture("data/windows/window1b.raw", 256, 256);
	tp.CreateTexture(WINDOW_1B, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2.raw", 256, 256);
	tp.CreateTexture(WINDOW_2, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2b.raw", 256, 256);
	tp.CreateTexture(WINDOW_2B, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2c.raw", 256, 256);
	tp.CreateTexture(WINDOW_2C, image, 256, 256);
	
	image = tp.LoadTexture("data/windows/window2d.raw", 256, 256);
	tp.CreateTexture(WINDOW_2D, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2e.raw", 256, 256);
	tp.CreateTexture(WINDOW_2E, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2us.raw", 256, 256);
	tp.CreateTexture(WINDOW_2US, image, 256, 256);

	image = tp.LoadTexture("data/windows/window2usb.raw", 256, 256);
	tp.CreateTexture(WINDOW_2USB, image, 256, 256);

	image = tp.LoadTexture("data/windows/window3.raw", 256, 256);
	tp.CreateTexture(WINDOW_3, image, 256, 256);

	image = tp.LoadTexture("data/windows/window3b.raw", 256, 256);
	tp.CreateTexture(WINDOW_3B, image, 256, 256);
	
	image = tp.LoadTexture("data/windows/window4.raw", 128, 256);
	tp.CreateTexture(WINDOW_4, image, 128, 256);
	
	image = tp.LoadTexture("data/windows/window5.raw", 128, 256);
	tp.CreateTexture(WINDOW_5, image, 128, 256);

	image = tp.LoadTexture("data/windows/window6.raw", 256, 256);
	tp.CreateTexture(WINDOW_6, image, 256, 256);

	image = tp.LoadTexture("data/windows/window7.raw", 256, 256);
	tp.CreateTexture(WINDOW_7, image, 256, 256);

	image = tp.LoadTexture("data/windows/window8.raw", 256, 256);
	tp.CreateTexture(WINDOW_8, image, 256, 256);

	image = tp.LoadTexture("data/windows/window9.raw", 256, 256);
	tp.CreateTexture(WINDOW_9, image, 256, 256);

	image = tp.LoadTexture("data/windows/window10.raw", 256, 256);
	tp.CreateTexture(WINDOW_10, image, 256, 256);

	image = tp.LoadTexture("data/windows/window11.raw", 256, 256);
	tp.CreateTexture(WINDOW_11, image, 256, 256);

	image = tp.LoadTexture("data/windows/window12.raw", 256, 256);
	tp.CreateTexture(WINDOW_12, image, 256, 256);

	image = tp.LoadTexture("data/windows/window13.raw", 256, 256);
	tp.CreateTexture(WINDOW_13, image, 256, 256);

	image = tp.LoadTexture("data/windows/window14.raw", 256, 128);
	tp.CreateTexture(WINDOW_14, image, 256, 128);

	image = tp.LoadTexture("data/windows/window14b.raw", 256, 128);
	tp.CreateTexture(WINDOW_14B, image, 256, 128);

	image = tp.LoadTexture("data/windows/window15.raw", 256, 256);
	tp.CreateTexture(WINDOW_15, image, 256, 256);

	image = tp.LoadTexture("data/windows/window16.raw", 128, 256);
	tp.CreateTexture(WINDOW_16, image, 128, 256);

	image = tp.LoadTexture("data/windows/window17.raw", 128, 256);
	tp.CreateTexture(WINDOW_17, image, 128, 256);

	image = tp.LoadTexture("data/windows/windowLib1.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_1, image, 256, 128);
	
	image = tp.LoadTexture("data/windows/windowLib1a.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_1A, image, 256, 128);

	image = tp.LoadTexture("data/windows/windowLib1b.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_1B, image, 256, 128);

	image = tp.LoadTexture("data/windows/windowLib1c.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_1C, image, 256, 128);

	image = tp.LoadTexture("data/windows/windowLibUSa.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_US_A, image, 256, 128);

	image = tp.LoadTexture("data/windows/windowLibUSb.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_US_B, image, 256, 128);

	image = tp.LoadTexture("data/windows/windowLibDoor1.raw", 256, 256);
	tp.CreateTexture(WINDOW_LIB_DOOR_1, image, 256, 256);

	image = tp.LoadTexture("data/windows/windowLibDoor2.raw", 512, 256);
	tp.CreateTexture(WINDOW_LIB_DOOR_2, image, 512, 256);
	
	image = tp.LoadTexture("data/windows/windowLibLong.raw", 256, 128);
	tp.CreateTexture(WINDOW_LIB_LONG, image, 256, 128);

	image = tp.LoadTexture("data/map.raw", 256, 256);
	tp.CreateTexture(217, image, 256, 256);
	image = tp.LoadTexture("data/welcome.raw", 512, 512);
	tp.CreateTexture(218, image, 512, 512);
	image = tp.LoadTexture("data/thanks.raw", 512, 512);
	tp.CreateTexture(219, image, 512, 512);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	
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