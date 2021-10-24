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
#include "BossArea.h"
#include <thread>
#include <ctime>
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
	* @brief	Loads in Animation
	* @param	No param
	* @return	Void
	*/
	void LoadAnimation();

	/**
	* @brief	Loads in an Animation frame
	* @param	tempName	- The name of the file
	* @param	AOBJ		- The animation object to store the frame to
	* @return	Void
	*/
	void LoadAnimationFrame(std::string tempName, AnimationOBJ& AOBJ);

	/**
	* @brief	Loads in a game shelf object
	* @param	fileName	- The name of the obj file
	* @param	textureID	- The textures ID for the object
	* @param	LODNumber	- The number of objects for the object (the same object at different level of details)
	* @return	Void
	*/
	void LoadGameShelfObject(const std::string& fileName, int textureID, int LODNumber);

	/**
	* @brief	Loads a LOD object into a shelf object
	* @param	fileName	- The name of the obj file
	* @param	soOBJ		- A shelf object you want to store the obj into
	* @return	Void
	*/
	void StoreLODObj(std::string& fileName, ShelfObjectsOBJ& soOBJ);

	/**
	* @brief	Creates AABB collisions for the world
	* @param	No param
	* @return	Void
	*/
	void CreateGameBoundingBoxes();

	void ChangeToBossCover();

	/**
	 * @brief	Collision resolution between the available collision types.
	 * @param	No param
	 * @return	void
	 */
	void GameCollisionResolution();

	void PlayerBulletCollisionResolution();

	void EnemyBulletCollisionResolution();

	void BossBulletCollisionResolution();

	/**
	* @brief	If a fixed update loop for the game. This will handle all AI and other fixed update processes
	* @param	val	- Some value //currently unused
	* @return	Void
	*/
	void GameFixedUpdateLoop(int val);

	void GameFixedUpdates(float delta);

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

	/**
	* @brief	Reads in the keyboard input to store into a string
	* @param	string	- The string you want to store to
	* @param	key		- The key the user pressed
	* @param	maximum	- The maximum length the string is allowed to be
	* @return	Void
	*/
	void ReadKeysForString(std::string& string, unsigned char& key, int maximum);

	/**
	* @brief	Pauses the game
	* @param	No param
	* @return	Void
	*/
	void PauseGame();

	/**
	* @brief	Unpauses the game
	* @param	No param
	* @return	Void
	*/
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
	
	/**
	* @brief	Handles when the mouse is moved over the option paused menu
	* @param	x		- The location of the mouse in the x direction
	* @param	y		- The location of the mouse in the y direction
	* @param	xMax	- The maximum x value
	* @param	xMin	- The minimum x value
	* @param	yMax	- The maximum y value
	* @param	yMin	- The minimum y value
	* @param	yChange	- The change in y value for an option
	* @param	xChange - The change in x value for an option
	* @return	Void
	*/
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

	/**
	* @brief	Handles when the mouse is clicked when the game is paused on the options menu
	* @param	x		- The location of the mouse in the x direction
	* @param	y		- The location of the mouse in the y direction
	* @param	xMax	- The maximum x value
	* @param	xMin	- The minimum x value
	* @param	yMax	- The maximum y value
	* @param	yMin	- The minimum y value
	* @param	yChange	- The change in y value for an option
	* @param	xChange - The change in x value for an option
	* @return	Void
	*/
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

	/**
	* @brief	Restarts the game
	* @param	No param
	* @return	Void
	*/
	void RestartGame();

	void ProgressGame();

	void ExitGame(int num);

}

#endif