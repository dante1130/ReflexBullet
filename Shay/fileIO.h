
#ifndef FILEIO_H
#define FILEIO_H

#include "Object.h"


#include <sstream>
#include <string>
#include <fstream>

/** 
 * \brief Reads file and stores values inside Object3D obj
 * \param fileName std::string 
 * \param obj Object3D&
 * \return void
 *
 */
void readObjFile(const std::string& fileName, Object3D& obj);
/** 
 * \brief Converts combined v and vt string into values
 * \param str std::string
 * \return FaceBase
 *
 */
FaceBase StringToFace(const std::string& str);

#endif
