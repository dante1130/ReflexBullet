#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "defines.h"
#include "camera.h"
#include "DisplayGameWorld.h"
#include "fileIO.h"
#include <glut.h>
#include <iostream>


/// <summary>
/// true - if the player is in the game world
/// </summary>
extern bool ActiveGameWorld;

/**
* @brief	Initialises the game objects
* @param	No param
* @return	void
*/
void GameInit(int w, int h);

/**
* @brief	Loads in game object files
* @param	No param
* @return	Void
*/
void LoadGameObjectFiles();

/**
* @brief	If a fixed update loop for the game. This will handle all AI and other fixed update processes
* @param	val	- Some value //currently unused
* @return	Void
*/
void GameFixedUpdateLoop(int val);

/**
* @brief	A non fixed update loop
* @param	No param
* @return	Void
*/
void GameUpdateLoop();

/**
* @brief	Handles all the key inputs for the game world
* @param	key	- The key pressed
* @param	x	- The location of the mouse in the x direction when the key was pressed
* @param	y	- The location of the mouse in the y direction when the key was pressed
* @return	Void
*/
void GameKeys(unsigned char key, int x, int y);

/**
* @brief	Handles all the released key inputs for the game world
* @param	key	- The key pressed
* @param	x	- The location of the mouse in the x direction when the key was pressed
* @param	y	- The location of the mouse in the y direction when the key was pressed
* @return	Void
*/
void GameReleaseKeys(unsigned char key, int x, int y);

/**
* @brief	Handles all the mouse movement in the game world
* @param	x	- The location of the mouse in the x direction
* @param	y	- The location of the mouse in the y direction
* @return	Void
*/
void GameMouseMove(int x, int y);

/**
* @brief	Handles reshaping the game window
* @param	w	- Width of the window
* @param	h	- Height of the window
* @return	Void
*/
void GameReshape(int w, int h);



#endif