#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"
#include "../../Camera/Camera.h"

class GameObject
{
public:
	GameObject(Model* model_);
	~GameObject();

	void Render(Camera* camera_);
private:
	Model* model;
};

#endif