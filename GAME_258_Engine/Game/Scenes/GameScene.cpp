#include "GameScene.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

bool GameScene::OnCreate()
{
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera());
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLightSource(new LightSource(glm::vec3(-1.0f, 0.0f, 2.0f), 0.5f, 0.5f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	CollisionHandler::GetInstance()->OnCreate();

	Model* diceM = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* appleM = new Model("Resources/Models/Apple.obj", "Resources/Materials/Apple.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));

	SceneGraph::GetInstance()->AddModel(diceM);
	SceneGraph::GetInstance()->AddModel(appleM);

	SceneGraph::GetInstance()->AddGameObject(new GameObject(diceM, glm::vec3(-2.0f, 0.0f, -2.0f)), "Box");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(appleM, glm::vec3(1.5f, 0.0f, 0.0f)), "Apple");

	diceM = nullptr;
	appleM = nullptr;
	std::cout << "Game Scene" << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime_)
{
	SceneGraph::GetInstance()->Update(deltaTime_);
}

void GameScene::Render()
{
	//
	CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Box"));
	CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Apple"));
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}
