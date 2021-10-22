#include "GameScene.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

bool GameScene::OnCreate()
{
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera());
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLightSource(new LightSource(glm::vec3(-4.0f, 0.0f, 2.0f), 0.5f, 0.5f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	CollisionHandler::GetInstance()->OnCreate(100.0f);

	//Model* tetra1 = new Model("Resources/Models/Tetrahedron1.obj", "Resources/Materials/Tetrahedron1.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* tetra = new Model("Resources/Models/Tetrahedron1.obj", "Resources/Materials/Tetrahedron1.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* box = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));

	SceneGraph::GetInstance()->AddModel(tetra);
	SceneGraph::GetInstance()->AddModel(box);

	SceneGraph::GetInstance()->AddGameObject(new GameObject(tetra, 0.045f, glm::vec3(0.5f,0.0f,0.0f), glm::vec3(-3.0f, 0.0f, 0.0f)), "Tetrahedron 1");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(tetra, -0.045f, glm::vec3(-0.5f,0.0f,0.0f), glm::vec3(3.0f, 0.0f, 0.0f)), "Tetrahedron 2");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(box, 0.005f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -5.0f)), "Box 1");
	
	tetra = nullptr;
	box = nullptr;
	std::cout << "Game Scene" << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime_)
{
	SceneGraph::GetInstance()->Update(deltaTime_);
}

void GameScene::Render()
{
	//CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1"));
	//CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2"));
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}
