#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

/**
 * @struct XYZ
 * @brief Stores x,y,z co-ordinates.
 */
struct XYZ
{
	/// Coordinates represented in x, y and z
	GLdouble x, y, z;
};

/**
 * @struct BoundingBox
 * @brief Stores max and min values of co-ordinates.
 */
struct BoundingBox
{
	/// Maximum extent
	XYZ max;
	/// Minimum extent
	XYZ min;
};

#endif 
