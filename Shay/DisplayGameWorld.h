#ifndef DISPLAYGAMEWORLD_H
#define DISPLAYGAMEWORLD_H


#include <cstdio>
#include "Object.h"
#include "defines.h"
#include "Lighting.h"
#include "DisplayGameObjects.h"
#include "Player.h"
#include "EnemyAI.h"
#include "LoadTexturesGameWorld.h"
#include <vector>
#include <stdlib.h>
#include <GL/glut.h>


struct ShelfObjectsOBJ
{
	Object3D obj;
	int texture;
};

struct AnimationOBJ
{
	std::vector<Object3D> obj;
	int texture;
};


extern Player player;
extern Object3D Shelf_1;
extern Object3D ToyStore;
extern std::vector<ShelfObjectsOBJ> Shelf_Objects;
extern Object3D s_Box;
extern Object3D s_Movies;
extern Object3D s_Books;

extern bool wireFrame;
extern bool performanceMetric;

namespace DGW
{
	/**
	* @brief	Is the master function which handles all the displaying for the game world
	* @param	No param
	* @return	Void
	*/
	void DisplayGameWorldMasterFunction();

	/**
	* @brief	Displays the shelves around the game world
	* @param	No param
	* @return	Void
	*/
	void DisplayShelves();

	/**
	* @brief	Displays a shalf and its contents based on an object list
	* @param	objectList	- An integer which specifies which object list to use
	* @return	Void
	*/
	void DisplayShelfContents(unsigned int objectList, int seed);

	/**
	* @brief	Displays a shelf and its contents based on an object list and its constraints (constraints specify when the shelf contents should be displayed)
	* @param	objectList	- An integer which specifies which object list to use
	* @param	xPos		- Position of the cutoff for the x direction
	* @param	xDirection	- specify 1 for positive x direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	zPos		- Position of the cutoff for the z direction
	* @param	zDirection	- specify 1 for positive z direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @return	Void
	*/
	void DisplayShelfContents(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed);

	/**
	* @brief	'Randomly' generates a number based on two inputs
	* @param	seed	- A variable used to for the output
	* @param	max		- The maximum number it could be
	* @param	rand	- An extra variable to change the output
	* @return	int		- The number generated
	*/
	int PsudeoNumGen(int seed, int max, int rand);

	/**
	* @brief	Displays the games current performance metrics
	* @param	No param
	* @return	Void
	*/
	void DisplayPerformanceMetrics();

	void RenderBitMapString(void* font, char* string);
}

#endif