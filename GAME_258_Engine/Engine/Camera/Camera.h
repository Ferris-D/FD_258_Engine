#ifndef CAMERA_H
#define CAMERA_H

#include "../FX/LightSource.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "../Math/Frustum.h"
class GameObject;
class Camera
{
public:
	Camera();
	~Camera();

	void SetPosition(glm::vec3 position_);
	void SetRotation(float yaw_, float pitch_);

	void AddLightSource(LightSource* light_);
	std::vector<LightSource*> GetLights() const;

	glm::mat4 GetView() const;
	glm::mat4 GetPerspective() const;
	glm::mat4 GetOrthographic() const;
	glm::vec3 GetPosition()const;
	float GetNearPlane() const;
	float GetFarPlane() const;

	void ObjectInViewCheck(GameObject* go_);

	void ProcessMouseMovement(glm::vec2 offset_);
	void ProcessMouseZoom(int y_);

	void MoveCameraForward(int y_);

	// Moves the camera not based off of view but actual coordinates it is at
	void MoveCameraRight(float amount_);
	void MoveCameraLeft(float amount_);
	void MoveCameraUp(float amount_);
	void MoveCameraDown(float amount_);

private:
	void UpdateCameraVectors();
	glm::vec3 position;
	glm::mat4 perspective, orthographic, view;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	glm::vec3 forward, up, right, worldUp;

	Frustum viewFrustum;
	std::vector<LightSource*> lights;

};

#endif