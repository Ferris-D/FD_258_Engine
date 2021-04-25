#ifndef FRUSTUM_H
#define FRUSTUM_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

// Use enumerator because it makes it a lot more readable
enum FrustumSides
{
	RIGHT,
	LEFT,
	BOTTOM,
	TOP,
	FAR,
	NEAR
};

class Frustum
{
public:
	glm::vec4 frustum[6];

	// Takes in the cameras perspective matrix and view matrix
	// Uses these values to calculate the frustum
	void CalculateFrustum(glm::mat4 perspective_, glm::mat4 view_)
	{
		float projection[16]; // Projection matrix
		float model[16];	  // Model matrix
		float clipping[16];   // Clipping planes

		// Write input values to the floats
		const float* pSource = (const float*)glm::value_ptr(perspective_);
		const float* mSource = (const float*)glm::value_ptr(view_);

		for (int i = 0; i < 16; i++)
		{
			projection[i] = pSource[i];
			model[i] = mSource[i];
		}

		// Combining the two matrices
		// projection and model combined onto clipping
		clipping[0] = model[0] * projection[0] + model[1] * projection[4] + model[2] * projection[8] + model[3] * projection[12];
		clipping[1] = model[0] * projection[1] + model[1] * projection[5] + model[2] * projection[9] + model[3] * projection[13];
		clipping[2] = model[0] * projection[2] + model[1] * projection[6] + model[2] * projection[10] + model[3] * projection[14];
		clipping[3] = model[0] * projection[3] + model[1] * projection[7] + model[2] * projection[11] + model[3] * projection[15];

		clipping[4] = model[4] * projection[0] + model[5] * projection[4] + model[6] * projection[8] + model[7] * projection[12];
		clipping[5] = model[4] * projection[1] + model[5] * projection[5] + model[6] * projection[9] + model[7] * projection[13];
		clipping[6] = model[4] * projection[2] + model[5] * projection[6] + model[6] * projection[10] + model[7] * projection[14];
		clipping[7] = model[4] * projection[3] + model[5] * projection[7] + model[6] * projection[11] + model[7] * projection[15];

		clipping[8] = model[8] * projection[0] + model[9] * projection[4] + model[10] * projection[8] + model[11] * projection[12];
		clipping[9] = model[8] * projection[1] + model[9] * projection[5] + model[10] * projection[9] + model[11] * projection[13];
		clipping[10] = model[8] * projection[2] + model[9] * projection[6] + model[10] * projection[10] + model[11] * projection[14];
		clipping[11] = model[8] * projection[3] + model[9] * projection[7] + model[10] * projection[11] + model[11] * projection[15];

		clipping[12] = model[12] * projection[0] + model[13] * projection[4] + model[14] * projection[8] + model[15] * projection[12];
		clipping[13] = model[12] * projection[1] + model[13] * projection[5] + model[14] * projection[9] + model[15] * projection[13];
		clipping[14] = model[12] * projection[2] + model[13] * projection[6] + model[14] * projection[10] + model[15] * projection[14];
		clipping[15] = model[12] * projection[3] + model[13] * projection[7] + model[14] * projection[11] + model[15] * projection[15];

		// Extract from the right plane
		frustum[RIGHT].x = clipping[3] - clipping[0];
		frustum[RIGHT].y = clipping[7] - clipping[4];
		frustum[RIGHT].z = clipping[11] - clipping[8];
		frustum[RIGHT].w = clipping[15] - clipping[12];

		// Normalize
		glm::normalize(frustum[RIGHT]);

		// Extract from the left plane
		frustum[LEFT].x = clipping[3] - clipping[0];
		frustum[LEFT].y = clipping[7] - clipping[4];
		frustum[LEFT].z = clipping[11] - clipping[8];
		frustum[LEFT].w = clipping[15] - clipping[12];

		// Normalize
		glm::normalize(frustum[LEFT]);

		// Extract from the bottom plane
		frustum[BOTTOM].x = clipping[3] - clipping[1];
		frustum[BOTTOM].y = clipping[7] - clipping[5];
		frustum[BOTTOM].z = clipping[11] - clipping[9];
		frustum[BOTTOM].w = clipping[15] - clipping[13];

		// Normalize
		glm::normalize(frustum[BOTTOM]);

		// Extract from the top plane
		frustum[TOP].x = clipping[3] - clipping[1];
		frustum[TOP].y = clipping[7] - clipping[5];
		frustum[TOP].z = clipping[11] - clipping[9];
		frustum[TOP].w = clipping[15] - clipping[13];

		// Normalize
		glm::normalize(frustum[TOP]);

		// Extract from the far plane
		frustum[FAR].x = clipping[3] - clipping[2];
		frustum[FAR].y = clipping[7] - clipping[6];
		frustum[FAR].z = clipping[11] - clipping[10];
		frustum[FAR].w = clipping[15] - clipping[14];

		// Normalize
		glm::normalize(frustum[FAR]);

		// Extract from the near plane
		frustum[NEAR].x = clipping[3] - clipping[2];
		frustum[NEAR].y = clipping[7] - clipping[6];
		frustum[NEAR].z = clipping[11] - clipping[10];
		frustum[NEAR].w = clipping[15] - clipping[14];

		// Normalize
		glm::normalize(frustum[NEAR]);

		std::cout << "Frustum calculated" << std::endl;
	}

	// Checks if any of the corners are within frustum
	// Calculates a points distance from the plane and returns true if the distance is above 0
	bool BoxInFustrum(glm::vec3 position_)
	{
		for (int p = 0; p < 6; p++)
		{
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			if (frustum[p].x * position_.x + frustum[p].y * position_.y + frustum[p].z * position_.z + frustum[p].w > 0)
			{
				continue;
			}
			return false;
		}
		return true;
	}
};

#endif