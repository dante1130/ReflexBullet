#ifndef DISPLAYSHAYSWORLD_H
#define DISPLAYSHAYSWORLD_H


#include "texturedPolygons.h"
#include "defines.h"
#include "LoadTexturesShaysWorld.h"
#include <GL/glut.h>

/// glut Cylinder
extern GLUquadricObj* glu_cylinder;

/// variables used for translating graphics etc
extern GLdouble step, step2, stepLength;

/**
* @brief	Creates display lists (numbers indicate list numbers) (calls all the display functions)
* @param	No param
* @return	Void
*/
void CreateTextureList();

/**
* @brief	Draws the backdrop (all images) (Calls all the draw functions)
* @param	No param
* @return	Void
*/
void DrawBackdrop(bool lightsOn);

/**
* @brief	Displays the chancellery window and door posts
* @param	No param
* @return	Void
*/
void DisplayChancPosts();

/**
* @brief	Sets the location for where to display the chanc posts
* @param	No param
* @return	Void
*/
void DrawChancPosts();

/**
* @brief	Displays the door posts
* @param	No param
* @return	Void
*/
void DisplayDoorPosts();

/**
* @brief	Sets the location for where to display the door posts
* @param	No param
* @return	Void
*/
void DrawDoorPosts();

/**
* @brief	Displays sections above windows and posts (the bits above the first floor and above the second floor)
* @param	No param
* @return	Void
*/
void DisplayAboveWindowBlock();

/**
* @brief	Sets the location for where to display blocks above windows and posts (the bits above 1st and 2nd floor)
* @param	No param
* @return	Void
*/
void DrawAboveWindowBlock();

/**
* @brief	Displays the purple posts by the guild shop
* @param	No param
* @return	Void
*/
void DisplayPurplePosts();

/**
* @brief	Sets the location for where to display the purple posts by guild shop
* @param	No param
* @return	Void
*/
void DrawPurplePosts();

/**
* @brief	Displays the red posts by sta travel shop
* @param	No param
* @return	Void
*/
void DisplayRedPosts();

/**
* @brief	Sets the location for where to display the red posts by sta travel shop
* @param	No param
* @return	Void
*/
void DrawRedPosts();

/**
* @brief	Displays the main posts (ones closest to the grass)
* @param	No param
* @return	Void
*/
void DisplayMainPosts();

/**
* @brief	Sets the location for where to display the main posts (ones closest to the grass)
* @param	No param
* @return	Void
*/
void DrawMainPosts();

//--------------------------------------------------------------------------------------
//  Display Window and Door Posts on Phys SCi Building
//--------------------------------------------------------------------------------------

/**
* @brief	Displays the windows and door posts on the physical science building
* @param	No param
* @return	Void
*/
void DisplayPhysSciPosts();

/**
* @brief	Sets the location for where to display the physical sciences posts
* @param	No param
* @return	Void
*/
void DrawPhysSciPosts();

/**
* @brief	Displays the paving around the shop doorway
* @param	No param
* @return	Void
*/
void DisplayDoorPaving();

/**
* @brief	Sets the location for where to display the door paving (believe around shop)
* @param	No param
* @return	Void
*/
void DrawDoorPaving();

/**
* @brief	Displays the library posts
* @param	No param
* @return	Void
*/
void DisplayLibraryPosts();

/**
* @brief	Sets the location for where to display the librarys posts
* @param	No param
* @return	Void
*/
void DrawLibraryPosts();

/**
* @brief	Displays the pavement
* @param	No param
* @return	Void
*/
void DisplayPavement();

/**
* @brief	Sets the location for where to display the pavement
* @param	No param
* @return	Void
*/
void DrawPavement();

/**
* @brief	Displays the wall bricks
* @param	No param
* @return	Void
*/
void DisplayBricks();

/**
* @brief	Sets the location for where to display the wall bricks
* @param	No param
* @return	Void
*/
void DrawBricks();


/**
* @brief	Displays everything related to the roof
* @param	No param
* @return	Void
*/void DisplayRoof();

/**
* @brief	Sets the location for where to display every thing involving the roof (including beams)
* @param	No param
* @return	Void
*/
void DrawRoof();

/**
* @brief	Sets the location for where to display the angled roof beam in the X axis
*
* @param	int listNo			- Where to store the coordiantes
* @param	GLdouble xStart		- Location to start the beam along the x coordinate
* @param	GLdouble yStart		- Location to start the beam along the y coordinate
* @param	GLdouble x			- Location along x coordiante
* @param	GLdouble y			- Location along y coordinate
* @param	GLdouble z			- Location along z coordinate
* @param	Gldouble beamSize	- Size of beam for texture mapping (meters)
* @param	int listAdd			- Size of list of roof beams (number of roof beams)
*
* @return	Void
*/
void DrawAngledRoofBeamX(int listNo, GLdouble xStart, GLdouble yStart, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize, int listAdd);

/**
* @brief	Sets the location for where to display the angled roof beam in the Z axis
*
* @param	int listNo			- Where to store the coordiantes
* @param	GLdouble zStart		- Location to start the beam along the z coordinate
* @param	GLdouble yStart		- Location to start the beam along the y coordinate
* @param	GLdouble x			- Location along x coordiante
* @param	GLdouble y			- Location along y coordinate
* @param	GLdouble z			- Location along z coordinate
* @param	Gldouble beamSize	- Size of beam for texture mapping (meters)
* @param	int listAdd			- Size of list of roof beams (number of roof beams)
*
* @return	Void
*/
void DrawAngledRoofBeamZ(int listNo, GLdouble zStart, GLdouble yStart, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize, int listAdd);

/**
* @brief	Displays the enterence steps
* @param	No param
* @return	Void
*/
void DisplayEntranceSteps();

/**
* @brief	Sets the location for where to display the entrance steps
* @param	No param
* @return	Void
*/
void DrawEntranceSteps();

/**
* @brief	Displays the benches
* @param	No param
* @return	Void
*/
void DisplayBench();

/**
* @brief	Sets the location for where to display the benches
* @param	No param
* @return	Void
*/
void DrawBench();



/**
* @brief	Displays all the extra sections (signs etc)
* @param	No param
* @return	Void
*/
void DisplayExtras();
/**
* @brief	Sets the location for where to display all extra textures (signs etc)
* @param	No param
* @return	Void
*/
void DrawExtras();

/**
* @brief	Displays all the larger textures (windows, doors, etc)
* @param	No param
* @return	Void
*/
void DisplayLargerTextures();

/**
* @brief	Sets the location for where to display larger textures (windows & doors, etc)
* @param	No param
* @return	Void
*/
void DrawLargerTextures();

/**
* @brief	Displays the grass area
* @param	No param
* @return	Void
*/
void DisplayGrass();

/**
* @brief	Sets the location for where to display the grass area
* @param	No param
* @return	Void
*/
void DrawGrass();

/**
* @brief	Displays the lights on the roof
* @param	No param
* @return	Void
*/
void DisplayLights();

/**
* @brief	Sets the location for where to display the lights
* @param	No param
* @return	Void
*/
void DrawLights();

/**
* @brief	Displays the drainpipe and tuckshop serving counter
* @param	No param
* @return	Void
*/
void DisplayCylinders();

/**
* @brief	Sets location for where to display various cylinders (drainpipe and tuckstop counter)
* @param	No param
* @return	Void
*/
void DrawCylinders();

/**
* @brief	Displays the wall by the enterence
* @param	No param
* @return	Void
*/
void DisplayStepBricks();

/**
* @brief	Sets location for where to display the map and welcome screen
* @param	No param
* @return	Void
*/
void DrawStepBricks();

/**
* @brief	Sets location for where to display the map and welcome screen
* @param	No param
* @return	Void
*/
void DrawMapExit();

#endif // DISPLAYSHAYSWORLD_H