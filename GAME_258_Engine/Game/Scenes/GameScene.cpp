#include "GameScene.h"

GameScene::GameScene() :shape(nullptr), shape2(nullptr)
{
}

GameScene::~GameScene()
{
	delete shape;
	shape = nullptr;

	delete shape2;
	shape2 = nullptr;
}

bool GameScene::OnCreate()
{
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	// Triangle 1
	Vertex v;
	std::vector<Vertex> vertexList;
	vertexList.reserve(3);
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	//
	std::cout << "Created Triangle 1" << std::endl;
	Model* model = new Model();
	model->AddMesh(new Mesh(vertexList));
	shape = new GameObject(model);

	// Triangle 2
	vertexList.clear();
	vertexList.reserve(3);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	//
	std::cout << "Created Triangle 2" << std::endl;
	Model* model2 = new Model();
	model2->AddMesh(new Mesh(vertexList));
	shape2 = new GameObject(model2);

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
	shape->Render();
	shape2->Render();
}
