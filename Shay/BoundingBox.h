#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/vec3.hpp>

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

	BoundingBox() : max(0), min(0) {}

	BoundingBox(const glm::vec3& max, const glm::vec3& min) : max(max), min(min) {}
};

#endif