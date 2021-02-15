#include "StartScene.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

bool StartScene::OnCreate()
{
	std::cout << "Start Scene" << std::endl;
	// Switch to game scene
	CoreEngine::GetInstance()->SetCurrentScene(1);
	return true;
}

void StartScene::Update(const float deltaTime_)
{
}

void StartScene::Render()
{
}
