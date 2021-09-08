#ifndef LOADTEXTURESSHAYSWORLD_H
#define LOADTEXTURESSHAYSWORLD_H

#include "defines.h"
#include "texturedPolygons.h"

/// <summary>
/// A textured polygons object used to get textures from
/// </summary>
extern TexturedPolygons tp;

/**
 * @brief	Delete raw image and clear memory.
 * @return	void
 */
void DeleteImageFromMemory();

/**
* @brief	Loads and Creates all the textures for shays world
* @param	No param
* @return	Void
*/
void CreateTextures();

#endif