//  texturedPolygon.h
//  Header file for the texturedPolygon class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef TEXTURE_POLYGON_H
#define TEXTURE_POLYGON_H

//--------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <GL/glut.h>

//--------------------------------------------------------------------------------------

/**
 * @class TexturedPolygons
 * @brief Reads in raw image files to create and display textures.
 */
class TexturedPolygons
{
public:
	/**
	 * @brief Constructor.
	 */
	TexturedPolygons();

	//----------------------------------------------------------------------------------

	/**
	 * @brief Returns texture.
	 * @param tempIndex const int&
	 * @return GLuint
	 */
	GLuint GetTexture (const int & tempIndex) const;

	/**
	 * @brief Loads a raw image file into memory.
	 * @param filename char*
	 * @param imgWidth int
	 * @param imgHeight int
	 * @return GLubyte*
	 */
	GLubyte* LoadTexture(char* filename, int imgWidth, int imgHeight);
	
	/**
	 * @brief Set the number of textures to be used.
	 * @param textureNo const int&
	 * @return void
	 */
	void SetTextureCount(const int &textureNo);

	/**
	 * @brief Creates texture and set required values for texture mapping.
	 * @param textureNo int
	 * @param image unsigned char*
	 * @param imgWidth int
	 * @param imgHeight int
	 * @return void
	 */
	void CreateTexture(int textureNo, unsigned char* image, int imgWidth, int imgHeight);

	/**
	 * @brief Calls function to creates display list to contain image.
	 * @param XYZ const int&
	 * @param listNo const int&
	 * @param xImgSize const GLdouble&
	 * @param zImgSize const GLdouble&
	 * @param xStart const GLdouble&
	 * @param yStart const GLdouble&
	 * @param zStart const GLdouble&
	 * @param xTimes const GLdouble&
	 * @param zTimes const GLdouble&
	 * @return void
	 */
	void CreateDisplayList(const int& XYZ, const int& listNo,
						   const GLdouble& xImgSize, const GLdouble& zImgSize,
						   const GLdouble& xStart, const GLdouble& yStart, const GLdouble& zStart,
						   const GLdouble& xTimes, const GLdouble& zTimes);

	/**
	 * @brief Used to create display lists where image is larger than world scale on YZ axis.
	 * @param listNo const int&
	 * @param xStart const GLdouble&
	 * @param yStart const GLdouble&
	 * @param ySize const GLdouble&
	 * @param zStart const GLdouble&
	 * @param zSize const GLdouble&
	 * @param yImgSize const GLdouble&
	 * @param zImgSize const GLdouble&
	 * @return void
	 */
	void CreateYtoZWindowList(const int& listNo, const GLdouble& xStart,
							  const GLdouble& yStart, const GLdouble& ySize,
							  const GLdouble& zStart, const GLdouble& zSize,
							  const GLdouble& yImgSize, const GLdouble& zImgSize);

	/**
	 * @brief Used to create display lists where image is larger than world scale on XY axis.
	 * @param listNo const int&
	 * @param zStart const GLdouble&
	 * @param xStart const GLdouble&
	 * @param xSize const GLdouble&
	 * @param yStart const GLdouble&
	 * @param ySize const GLdouble&
	 * @param xImgSize const GLdouble&
	 * @param yImgSize const GLdouble&
	 * @return void
	 */
	void CreateXtoYWindowList(const int& listNo, const GLdouble& zStart,
							  const GLdouble& xStart, const GLdouble& xSize,
							  const GLdouble& yStart, const GLdouble& ySize,
							  const GLdouble& xImgSize, const GLdouble& yImgSize);
	
	/**
	 * @brief Used to create display lists where image is on an angle.
	 * @param listNo const int&
	 * @param imageWidth const GLdouble&
	 * @param imageHeight const GLdouble&
	 * @param x1 const GLdouble&
	 * @param x2 const GLdouble&
	 * @param x3 const GLDouble&
	 * @param x4 const GLDouble&
	 * @param y1 const GLDouble&
	 * @param y2 const GLDouble&
	 * @param y3 const GLDouble&
	 * @param y4 const GLDouble&
	 * @param z1 const GLDouble&
	 * @param z2 const GLDouble&
	 * @param z3 const GLDouble&
	 * @param z4 const GLDouble&
	 * @param smallestX const int&
	 * @param smallestZ const int&
	 * @return void
	 */
	void CreateAngledPolygon(const int& listNo,
							 const GLdouble& imageWidth, const GLdouble& imageHeight,
							 const GLdouble& x1, const GLdouble& x2,
							 const GLdouble& x3, const GLdouble& x4,
							 const GLdouble& y1, const GLdouble& y2,
							 const GLdouble& y3, const GLdouble& y4,
							 const GLdouble& z1, const GLdouble& z2,
							 const GLdouble& z3, const GLdouble& z4,
							 const int& smallestX, const int& smallestZ);

private:
	/// pointer to display list
	std::vector<GLuint> m_texture;

	/**
	 * @brief Returns image file.
	 * @param fileName char*
	 * @param width int
	 * @param height int
	 * @return GLubyte*
	 */
	GLubyte* LoadRawImageFile(char* fileName, int width, int height);

	/**
	 * @brief Creates display list to contain image on X Z axis.
	 * @param xImgSize const GLdouble&
	 * @param zImgSize const GLdouble&
	 * @param xStart const GLdouble&
	 * @param yStart const GLdouble&
	 * @param zStart const GLdouble&
	 * @param xTimes const GLdouble&
	 * @param zTimes const GLdouble&
	 * @return void
	 */
	void CreateXtoZTextureList(const GLdouble& xImgSize, const GLdouble& zImgSize,
							   const GLdouble& xStart, const GLdouble& yStart, const GLdouble& zStart,
							   const GLdouble& xTimes, const GLdouble& zTimes);

	/**
	 * @brief Creates display list to contain image on X Y axis.
	 * @param xImgSize const GLdouble&
	 * @param yImgSize const GLdouble&
	 * @param xStart const GLdouble&
	 * @param yStart const GLdouble&
	 * @param zStart const GLdouble&
	 * @param xTimes const GLdouble&
	 * @param yTimes const GLdouble&
	 * @param flip const bool&
	 * @return void
	 */
	void CreateXtoYTextureList(const GLdouble& xImgSize, const GLdouble& yImgSize,
							   const GLdouble& xStart, const GLdouble& yStart, const GLdouble& zStart,
							   const GLdouble& xTimes, const GLdouble& yTimes, const bool& flip);

	/**
	 * @brief Creates display list to contain image on Y Z axis.
	 * @param yImgSize const GLdouble&
	 * @param zImgSize const GLdouble&
	 * @param xStart const GLdouble&
	 * @param yStart const GLdouble&
	 * @param zStart const GLdouble&
	 * @param yTimes const GLdouble&
	 * @param zTimes const GLdouble&
	 * @param flip const bool&
	 * @return void
	 */
	void CreateYtoZTextureList(const GLdouble& yImgSize, const GLdouble& zImgSize,
							   const GLdouble& xStart, const GLdouble& yStart, const GLdouble& zStart,
							   const GLdouble& yTimes, const GLdouble& zTimes, const bool& flip);
	
	/**
	 * @brief Called from CreateAngledPolygon determine how images are displayed.
	 * @param xzImage1 GLdouble&
	 * @param xzImage2 GLdouble&
	 * @param xzImage3 GLdouble&
	 * @param xzImage4 GLdouble&
	 * @param imageSize const GLdouble&
	 * @return void
	 */
	void CreateTextureScale(GLdouble& xzImage1, GLdouble& xzImage2,
							GLdouble& xzImage3, GLdouble& xzImage4,
							const GLdouble& imageSize);

	//----------------------------------------------------------------------------------

};

#endif

//----------------------------------------------------------------------------------