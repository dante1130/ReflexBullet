#ifndef DISPLAYEXTRASHAYSWORLD_H
#define DISPLAYEXTRASHAYSWORLD_H

#include "texturedPolygons.h"
#include "defines.h"
#include "LoadTexturesShaysWorld.h"
#include "../include/GL/glut.h"
#include "Object.h"

/// <summary>
/// The environment objects
/// [0] = general
/// [1] = stairs
/// [2] = railing
/// </summary>
extern Object3D EnvironmentOBJ[3];

/// <summary>
/// The small table obj
/// </summary>
extern Object3D SmallTableOBJ;

/// <summary>
/// The big table obj
/// </summary>
extern Object3D BigTableOBJ;

/// <summary>
/// The umbrella obj
/// </summary>
extern Object3D UmbrellaOBJ;

/// <summary>
/// The chair obj
/// </summary>
extern Object3D ChairOBJ;

/// <summary>
/// The bench obj
/// </summary>
extern Object3D BenchOBJ;

/// <summary>
/// The bush obj
/// </summary>
extern Object3D BushOBJ;

/// <summary>
/// The bin obj
/// </summary>
extern Object3D BinOBJ;

/// <summary>
/// The tree obj
/// </summary>
extern Object3D TreeOBJ;

/// <summary>
/// boolean if the sliding door should be opened or not
/// </summary>
extern bool doorOpen;

namespace DisplayExtraArea
{
	/**
	* @brief	Controls all the display functions in this file
	* @param	No param
	* @return	Void
	*/
	void DisplayExtension();

	/**
	* @brief	Controls all the display functions for environment
	* @param	No param
	* @return	Void
	*/
	void DisplayEnvironment();

	/**
	* @brief	Contains all the display functions for chairs
	* @param	No param
	* @return	Void
	*/
	void DisplayChairs();

	/**
	* @brief	Contains all the display functions for benches
	* @param	No param
	* @return	Void
	*/
	void DisplayBenches();

	/**
	* @brief	Contains all the display functions for small tables
	* @param	No param
	* @return	Void
	*/
	void DisplaySmallTable();

	/**
	* @brief	Contains all the display functions for big tables
	* @param	No param
	* @return	Void
	*/
	void DisplayBigTable();

	/**
	* @brief	Contains all the display functions for umbrellas
	* @param	No param
	* @return	Void
	*/
	void DisplayUmbrellas();

	/**
	* @brief	Controls all the functions which display non blend objects
	* @param	No param
	* @return	Void
	*/
	void DisplayNonBlendObjects();

	/**
	* @brief	Displays the small objects around the resutant area
	* @param	No param
	* @return	Void
	*/
	void DisplayResturantObjects();

	/**
	* @brief	This 'fixes' overextended collision boxes which just means it adds objects to the world to make the collision boxes belevable
	* @param	No param
	* @return	Void
	*/
	void FixingOverextendedCollisionBoxes();

	/**
	* @brief	Places the bins in the extended area
	* @param	No param
	* @return	Void
	*/
	void DisplayBins();

	/**
	* @brief	Displays all the bush objects
	* @param	No param
	* @return	Void
	*/
	void DisplayBushes();

	/**
	* @brief	Displays all the main images for the boundary walls
	* @param	No param
	* @return	Void
	*/
	void DisplayEdgeWallEnvironmentPicutres();

	/**
	* @brief	Adds features to fix the entrance to the extended area
	* @param	No param
	* @return	Void
	*/
	void DisplayFixedStartUpArea();

	/**
	* @brief	Displays the canteen walls using traditional openGL techniques
	* @param	No param
	* @return	Void
	*/
	void DisplayCanteen();

	/**
	* @brief	Displays the sliding door for the student hub
	* @param	No param
	* @return	Void
	*/
	void DisplaySlidingDoor();

	/**
	* @brief	Displays the canteen contreen railing 
	* @param	No param
	* @return	Void
	*/
	void DisplayCanteenRailing();

	/**
	* @brief	Displays the overhang under section
	* @param	No param
	* @return	Void
	*/
	void DisplayOverhangUnder();

	/**
	* @brief	Displays the canteens pillars
	* @param	No param
	* @return	Void
	*/
	void DisplayCanteenPillars();

	/**
	* @brief	Displays the entrance pathway using traditional openGL techniques
	* @param	No param
	* @return	Void
	*/
	void DisplayPathways();

	/**
	* @brief	Displays walters resturant
	* @param	No param
	* @return	Void
	*/
	void DisplayWaltersResturant();

	/**
	* @brief	Displays the area left of the stairs
	* @param	No param
	* @return	Void
	*/
	void DisplayLeftAreaOfStairs();

	/**
	* @brief	Draws the section left of the stairs for row 1
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs1ROW();

	/**
	* @brief	Draws the section left of the stairs for row 2
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs2ROW();

	/**
	* @brief	Draws the section left of the stairs for row 3
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs3ROW();

	/**
	* @brief	Draws the section left of the stairs for row 4
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs4ROW();

	/**
	* @brief	Draws the section left of the stairs for row 5
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs5ROW();

	/**
	* @brief	Draws the section left of the stairs for row 6
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs6ROW();

	/**
	* @brief	Draws the section left of the stairs for row 7
	* @param	No param
	* @return	Void
	*/
	void LeftOfStairs7ROW();
}



#endif