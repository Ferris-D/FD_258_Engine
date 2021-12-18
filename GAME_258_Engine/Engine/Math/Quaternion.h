#ifndef QUATERNION_H
#define QUATERNION_H

#include <glm/glm.hpp>

class Quaternion
{
public:
	Quaternion() {};
	Quaternion(float w_, float x_, float y_, float z_);
	Quaternion(float w_, glm::vec3 v_);
	Quaternion(glm::vec4 v_);

	// return normalized quaternion
	static Quaternion Normalize(Quaternion q_);
	// Normalize the quaternion
	void Normalize();
	// Apply vel to quaternion
	Quaternion ApplyVelocity(Quaternion q_, glm::vec3 av_, float deltaTime_);

	// Add Quaternion to another
	Quaternion operator+ (Quaternion otherQuat_);
	// Multiply Quaternion with another
	Quaternion operator* (Quaternion otherQuat_);
	// Multiply Quaternion by float
	Quaternion operator* (float f_);
	// Divide Quaternion by float
	Quaternion operator/ (float s_);

	//float w;
	glm::vec4 v;
};

#endif