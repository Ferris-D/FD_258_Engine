#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
#include "../../Camera/Camera.h"
#include "../../Math/Quaternion.h"

class GameObject
{
public:
	// Model -> Velocity -> Position
	GameObject(Model* model_, glm::vec3 velocity_, glm::vec3 position_ = glm::vec3());
	~GameObject();

	void Update(const float deltaTime_);
	void Render(Camera* camera_);

	glm::vec3 GetPosition() const;
	float GetAngle() const;
	Quaternion GetRotation() const;
	glm::vec3 GetScale() const;
	std::string GetTag() const;
	// ?
	BoundingBox& GetBoundingBox();
	//BoundingBox GetBoundingBox() const;
	bool GetHit() const;

	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(Quaternion rotation_);
	void SetVelocity(glm::vec3 velocity_);
	void SetAVelocity(glm::vec3 avelocity_);
	void SetScale(glm::vec3 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);
private:
	Model* model;
	unsigned int modelInstance;
	glm::vec3 position;
	// 
	glm::vec3 velocity;
	glm::vec3 avelocity;
	// 
	//glm::quat angle;
	Quaternion rotation;
	float angle;
	//glm::vec3 rotation;
	glm::vec3 scale;
	std::string tag;

	BoundingBox boundingBox;

	bool hit;
};

#endif