#ifndef DISPLAYGAMEWORLD_H
#define DISPLAYGAMEWORLD_H

#include "Object.h"
#include "defines.h"
#include <glut.h>
#include <stdio.h>


/// <summary>
/// Is the toy store obj file used for testing purposes
/// </summary>
extern Object3D ToyStore;

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

void RenderBitMapString(void* font, char* string);

#endif