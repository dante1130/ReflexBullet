#ifndef LOADTEXTURESGAMEWORLD_H
#define LOADTEXTURESGAMEWORLD_H


#include "texturedPolygons.h"
#include "definesGW.h"
#include <GL/glut.h>

extern TexturedPolygons tpGW;

namespace LTGW
{
	/**
	* @brief	Creates the textures for the game world
	* @param	No param
	* @return	Void
	*/
	void CreateTextures();

	/**
	* @brief	Deletes image from memory
	* @param	No param
	* @return	Void
	*/
	void DeleteImageFromMemory();
}



#endif