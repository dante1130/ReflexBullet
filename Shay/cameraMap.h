//  cameraMap.h
//  Header file for the cameraMap class
//  Displays a map and welcome screen in 2D on the screen
//  
//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef CAMERA_MAP_H
#define CAMERA_MAP_H

#include "../include/GL/glut.h"

//--------------------------------------------------------------------------------------

/**
 * @class CameraMap
 * @brief Provides methods that display a 2D map and welcome screen.
 */
class CameraMap
{
public:
	/**
	 * @brief Constructor.
	 */
	CameraMap();

	//----------------------------------------------------------------------------------

	/**
	 * @brief Display the map.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param xPos const GLdouble&
	 * @param zPos const GLdouble&
	 * @param tempImage const GLuint&
	 * @return void
	 */
	void DisplayMap(const int& screenWidth, const int& screenHeight,
					const GLdouble& xPos, const GLdouble& zPos,
					const GLuint& tempImage);

	/**
	 * @brief Display the welcome screen.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param tempExit const int&
	 * @param tempImage const GLuint& 
	 * @return void
	 */
	void DisplayWelcomeScreen(const int& screenWidth, const int& screenHeight,
							  const int& tempExit, const GLuint& tempImage);

	/**
	 * @brief Display the no exit screen.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param tempImage const GLuint&
	 */
	void DisplayNoExit(const int& screenWidth, const int& screenHeight,
					   const GLuint& tempImage);
};

#endif

//--------------------------------------------------------------------------------------