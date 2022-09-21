#ifndef PROCESSSHAYSWORLD_H
#define PROCESSSHAYSWORLD_H

#include <ctime>
#include "camera.h"
#include "texturedPolygons.h"
#include "DisplayShaysWorld.h"
#include "defines.h"
#include "fileIO.h"
#include "Object.h"
#include "DisplayEXTRAShaysWorld.h"
#include "GameManager.h"
#include <thread>
#include <GL/glut.h>

namespace PSW
{
	/**
	* @brief	Initializes settings
	* @param	No param
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

	/**
	* @brief	Checks if the player should be moved to the game world
	* @param	No param
	* @return	Void
	*/
	void GoToGameWorld();

	/**
* @brief	Increments the frame count
* @param	No param
* @return	Void
*/
	void IncrementFrameCount();

}

#endif