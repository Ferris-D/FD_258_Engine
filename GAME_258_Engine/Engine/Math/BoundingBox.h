#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

struct BoundingBox
{
	glm::vec3 maxVert, minVert;
	glm::mat4 transform;

	inline BoundingBox()
	{
		maxVert = minVert = glm::vec3();
		transform = glm::mat4();
	}

	inline BoundingBox(glm::vec3 maxVert_, glm::vec3 minVert_, glm::mat4 transform_)
	{
		maxVert = maxVert_;
		minVert = minVert_;
		transform = transform_;
	}

	inline bool Intersects(BoundingBox* box_)
	{
		glm::vec3 minCorner = GetTransformedPoint(minVert, transform);
		glm::vec3 maxCorner = GetTransformedPoint(maxVert, transform);

		glm::vec3 otherMinCorner = GetTransformedPoint(box_->minVert, box_->transform);
		glm::vec3 otherMaxCorner = GetTransformedPoint(box_->maxVert, box_->transform);

		// Check if the two boxes ranges collide
		return (minCorner.x <= otherMaxCorner.x) && (minCorner.y <= otherMaxCorner.y) && (minCorner.z <= otherMaxCorner.z) &&
			   (maxCorner.x >= otherMinCorner.x) && (maxCorner.y >= otherMinCorner.y) && (maxCorner.z >= otherMinCorner.z);
	}

private:
	inline glm::vec3 GetTransformedPoint(glm::vec3 point_, glm::mat4 transform_)
	{
		return glm::vec3(transform_[3].x, transform_[3].y, transform_[3].z) + point_;
	}
};

#endif