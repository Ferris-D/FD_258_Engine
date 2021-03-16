#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include "../Core/Debug.h"
#include <glm/glm.hpp>

class LightSource
{
public:
	LightSource(glm::vec3 position_, float ambient_, float diffuse_, float specular_, glm::vec3 colour_);
	~LightSource();

	// Getters for the light
	glm::vec3 GetPosition();
	float GetAmbient();
	float GetDiffuse();
	float GetSpecular();
	glm::vec3 GetColour();

	// Setters for the light
	void SetPosition(glm::vec3 position_);
	void SetAmbient(float ambient_);
	void SetDiffuse(float diffuse_);
	void SetSpecular(float specular_);
	void SetColour(glm::vec3 colour_);

private:
	glm::vec3 position;
	float ambient;
	float diffuse;
	float specular;
	glm::vec3 colour;
};

#endif