#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "../include/glm/vec3.hpp"

/**
 * @struct BoundingBox
 * @brief Stores max and min values of co-ordinates.
 */
struct BoundingBox
{
	/// Maximum extent
	glm::vec3 max;
	/// Minimum extent
	glm::vec3 min;
};


#endif 