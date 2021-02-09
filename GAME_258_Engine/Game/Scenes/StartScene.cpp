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
	return true;
}

void StartScene::Update(const float deltaTime_)
{
	// Switch to game scene after updating once
	CoreEngine::GetInstance()->SetCurrentScene(1);
}

void StartScene::Render()
{
}
