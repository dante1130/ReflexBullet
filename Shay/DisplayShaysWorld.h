#ifndef DISPLAYSHAYSWORLD_H
#define DISPLAYSHAYSWORLD_H

#include "texturedPolygons.h"
#include "defines.h"
#include <GL/glut.h>

extern TexturedPolygons tp;
// Glut Cylinder
extern GLUquadricObj* glu_cylinder;
// varibles used for tarnslating graphics etc
extern GLdouble step, step2, stepLength;


//--------------------------------------------------------------------------------------
//  Create display lists
//	Numbers indicate list numbers
//--------------------------------------------------------------------------------------
void CreateTextureList();

//--------------------------------------------------------------------------------------
//  Called from the main display function to draw the backdrop (all images)
//--------------------------------------------------------------------------------------
void DrawBackdrop(bool lightsOn);

//--------------------------------------------------------------------------------------
// Display the chancellery windoe and door posts
//--------------------------------------------------------------------------------------
void DisplayChancPosts();
void DrawChancPosts();

//--------------------------------------------------------------------------------------
// Display Door Posts
//--------------------------------------------------------------------------------------
void DisplayDoorPosts();
void DrawDoorPosts();

//--------------------------------------------------------------------------------------
// Display blocks above Windows and Posts
//--------------------------------------------------------------------------------------
void DisplayAboveWindowBlock();
void DrawAboveWindowBlock();

//--------------------------------------------------------------------------------------
// Display Purple Posts by Guild Shop
//--------------------------------------------------------------------------------------
void DisplayPurplePosts();
void DrawPurplePosts();

//--------------------------------------------------------------------------------------
// Display Red Posts by Sta Travel Shop
//--------------------------------------------------------------------------------------
void DisplayRedPosts();
void DrawRedPosts();

//--------------------------------------------------------------------------------------
// Display Main Posts
//--------------------------------------------------------------------------------------
void DisplayMainPosts();
void DrawMainPosts();

//--------------------------------------------------------------------------------------
//  Display Window and Door Posts on Phys SCi Building
//--------------------------------------------------------------------------------------
void DisplayPhysSciPosts();
void DrawPhysSciPosts();

//--------------------------------------------------------------------------------------
//  Display Paving Around Shop Doorway
//--------------------------------------------------------------------------------------
void DisplayDoorPaving();
void DrawDoorPaving();


//--------------------------------------------------------------------------------------
// Display window and door posts of library
//--------------------------------------------------------------------------------------
void DisplayLibraryPosts();
void DrawLibraryPosts();

//--------------------------------------------------------------------------------------
//  Display Pavement
//--------------------------------------------------------------------------------------
void DisplayPavement();
void DrawPavement();

//--------------------------------------------------------------------------------------
// Display Wall Bricks
//--------------------------------------------------------------------------------------
void DisplayBricks();
void DrawBricks();












//--------------------------------------------------------------------------------------
// Display Roof
//--------------------------------------------------------------------------------------
void DisplayRoof();
void DrawRoof();

// --------------------------------------------------------------------------------------
//  Creates Angled Roof Beams
// --------------------------------------------------------------------------------------
void DrawAngledRoofBeam(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);
void DrawAngledRoofBeam2(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);

//--------------------------------------------------------------------------------------
// Display Steps
//--------------------------------------------------------------------------------------
void DisplayEntranceSteps();
void DrawEntranceSteps();

//--------------------------------------------------------------------------------------
// Display Bench
//--------------------------------------------------------------------------------------
void DisplayBench();
void DrawBench();



// Display Extras (signs etc)
void DisplayExtras();
void DrawExtras();

// Display larger textures such as windows and doors
void DisplayLargerTextures();
void DrawLargerTextures();

// Display grass and slopes
void DisplayGrass();
void DrawGrass();


// Display Light Fittings
void DisplayLights();
void DrawLights();

// Display drainpipe and tuckshop serving counter
void DisplayCylinders();

void DrawCylinders();

// Display Wall by Entrance
void DisplayStepBricks();


void DrawStepBricks();

//Map and Welcome screens
void DrawMapExit();



/////////////////////////////////////////
//DISPLAY DISPLAY LISTS BLOCK
/////////////////////////////////////////


#endif // DISPLAYSHAYSWORLD_H