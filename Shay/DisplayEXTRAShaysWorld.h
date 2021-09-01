#ifndef DISPLAYEXTRASHAYSWORLD_H
#define DISPLAYEXTRASHAYSWORLD_H

#include "texturedPolygons.h"
#include "defines.h"
#include "LoadTexturesShaysWorld.h"
#include <GL/glut.h>
#include "Object.h"

extern Object3D EnvironmentOBJ;
extern Object3D SmallTableOBJ;
extern Object3D BigTableOBJ;

namespace DisplayExtraArea
{
	/**
	* @brief	Controls all the display functions in this file
	* @param	No param
	* @return	Void
	*/
	void DisplayExtension();

	/**
	* @brief	Controls all the functions which display non blend objects
	* @param	No param
	* @return	Void
	*/
	void DisplayNonBlendObjects();

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
	* @brief	Displays the canteen contreen railing 
	* @param	No param
	* @return	Void
	*/
	void DisplayCanteenRailing();


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