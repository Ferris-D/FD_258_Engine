#ifndef SCENE1_H
#define SCENE1_H

#include "../../Engine/Core/CoreEngine.h"

class Scene1 : public Scene
{
public:
	Scene1();
	virtual ~Scene1();

	bool OnCreate() override;
	void Update(const float deltaTime_) override;
	void Render() override;
private:
};

#endif