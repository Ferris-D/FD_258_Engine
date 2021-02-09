#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

bool GameScene::OnCreate()
{
	std::cout << "Game Scene" << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime_)
{
	// Printing out delta time to debug log
	Debug::Info( std::to_string(deltaTime_), "Window.cpp", __LINE__);
}

void GameScene::Render()
{
}
