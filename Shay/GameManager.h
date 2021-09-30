#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include "definesGW.h"
#include "camera.h"
#include "DisplayGameWorld.h"
#include "fileIO.h"
#include "Player.h"
#include "Lighting.h"
#include "Leaderboards.h"
#include "Enemy.h"
#include <GL/glut.h>

/// <summary>
/// true - if the player is in the game world
/// </summary>
extern bool ActiveGameWorld;

namespace GM
{

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
	* @brief	Loads in a game shelf object
	* @param	fileName	- The name of the obj file
	* @param	textureID	- The textures ID for the object
	* @return	Void
	*/
	void LoadGameShelfObject(const std::string& fileName, int textureID);

	/**
	* @brief	Creates AABB collisions for the world
	* @param	No param
	* @return	Void
	*/
	void CreateGameBoundingBoxes();

	/**
	 * @brief	Collision resolution between the available collision types.
	 * @param	No param
	 * @return	void
	 */
	void GameCollisionResolution();

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
	* @brief	Handles the visual game startup
	* @param	No param
	* @return	Void
	*/
	void GameStartUp();

	/**
	* @brief	Handles all the key inputs for the game world
	* @param	key	- The key pressed
	* @param	x	- The location of the mouse in the x direction when the key was pressed
	* @param	y	- The location of the mouse in the y direction when the key was pressed
	* @return	Void
	*/
	void GameKeys(unsigned char key, int x, int y);

	void PauseGame();

	void UnpauseGame();

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
	* @brief	Handles deciding which option should be highlighted when the mouse is moved over it
	* @param	x	- The location of the mouse in the x direction
	* @param	y	- The location of the mouse in the y direction
	* @return	Void
	*/
	void MouseOverOption(int x, int y);
	
	void GameMouseOverOptionOptions(int x, int y, float xMax, float xMin, float yMax, float yMin, float yChange, float xChange);

	/**
	* @brief	Handles when the mouse is clicked
	* @param	button	- Which button was clicked
	* @param	state	- The state of the button
	* @param	x		- The location of the mouse in the x direction
	* @param	y		- The location of the mouse in the y direction
	* @return	Void
	*/
	void GameMouseClick(int button, int state, int x, int y);

	/**
	* @brief	Handles when the mouse is clicked when the game is paused
	* @param	button	- Which button was clicked
	* @param	state	- The state of the button
	* @param	x		- The location of the mouse in the x direction
	* @param	y		- The location of the mouse in the y direction
	* @return	Void
	*/
	void GameMouseClickOption(int button, int state, int x, int y);

	void GameMouseOptionMenuClickOption(int x, int y, float xMax, float xMin, float yMax, float yMin, float yChange, float xChange);

	/**
	* @brief	Decides the action of a button for the menu
	* @param	option	- Which option was selected
	* @return	Void
	*/
	void MenuOptionChoosen(int option);

	/**
	* @brief	Handles reshaping the game window
	* @param	w	- Width of the window
	* @param	h	- Height of the window
	* @return	Void
	*/
	void GameReshape(int w, int h);

	/**
	* @brief	Handles moving the camera when the game is paused
	* @param	No param
	* @return	Void
	*/
	void PausedFloatingPosition();

	void RestartGame();

}

#endif