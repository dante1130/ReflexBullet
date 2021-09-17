#ifndef DISPLAYGAMEWORLD_H
#define DISPLAYGAMEWORLD_H

#include <cstdio>
#include "Object.h"
#include "defines.h"
#include "../include/GL/glut.h"
#include "DisplayGameObjects.h"
#include "Player.h"


/// <summary>
/// Is the toy store obj file used for testing purposes
/// </summary>

extern Player player;
extern Object3D ToyStore;

namespace DGW
{

	/**
	* @brief	Is the master function which handles all the displaying for the game world
	* @param	No param
	* @return	Void
	*/
	void DisplayGameWorldMasterFunction();

	/**
	* @brief	Displays the games current performance metrics
	* @param	No param
	* @return	Void
	*/
	void DisplayPerformanceMetrics();

	void DisplayBullets();

	void RenderBitMapString(void* font, char* string);
}

#endif