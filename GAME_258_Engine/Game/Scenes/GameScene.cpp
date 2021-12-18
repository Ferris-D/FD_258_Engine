#include "GameScene.h"
#include "../../Engine/FX/Sound.h"

GameScene::GameScene(){}

GameScene::~GameScene(){}

bool GameScene::OnCreate()
{
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera());
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLightSource(new LightSource(glm::vec3(-4.0f, 0.0f, 2.0f), 0.5f, 0.5f, 0.5f, glm::vec3(1.0f, 1.0f, 1.0f)));

	CollisionHandler::GetInstance()->OnCreate(100.0f);


	Sound* sm = new Sound();

	//Model* tetra1 = new Model("Resources/Models/Tetrahedron1.obj", "Resources/Materials/Tetrahedron1.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* tetra = new Model("Resources/Models/Tetrahedron1.obj", "Resources/Materials/Tetrahedron1.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	Model* box = new Model("Resources/Models/Dice.obj", "Resources/Materials/Dice.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));

	SceneGraph::GetInstance()->AddModel(tetra);
	SceneGraph::GetInstance()->AddModel(box);
	
	SceneGraph::GetInstance()->AddGameObject(new GameObject(tetra, glm::vec3(0.5f,0.0f,0.0f), glm::vec3(-3.0f, 0.0f, 0.0f)), "Tetrahedron 1");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(tetra, glm::vec3(-0.5f,0.0f,0.0f), glm::vec3(3.0f, 0.0f, 0.0f)), "Tetrahedron 2");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(box, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -5.0f)), "Box 1");

	SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1")->SetRotation(Quaternion(0, glm::vec3(0.0f, 0.0f, 0.0f)));
	SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2")->SetRotation(Quaternion(0, glm::vec3(0.0f, 0.0f, 0.0f)));
	SceneGraph::GetInstance()->GetGameObject("Box 1")->SetRotation(Quaternion(0, glm::vec3(1.0f, 0.0f, 0.0f)));

	SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1")->SetAVelocity(glm::vec3(0.0f,0.45f,0.0f));
	SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2")->SetAVelocity(glm::vec3(0.0f,-0.45f,0.0f));
	SceneGraph::GetInstance()->GetGameObject("Box 1")->SetAVelocity(glm::vec3(0.0f,-0.45f,0.0f));
	hit = false;
	tetra = nullptr;
	box = nullptr;
	delete tetra;
	delete box;
	std::cout << "Game Scene" << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime_)
{
	if (
		SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1")->
		GetBoundingBox().Intersects(&SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2")->GetBoundingBox())
		)
	{
		hit = true;
		std::cout << SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1")->GetTag() << " has collided with " <<
			SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2")->GetTag() << std::endl;
	}
	else
	{
		std::cout << "No collision" << std::endl;
	}
	SceneGraph::GetInstance()->Update(deltaTime_);
}

void GameScene::Render()
{
	//CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Tetrahedron 1"));
	//CoreEngine::GetInstance()->GetCamera()->ObjectInViewCheck(SceneGraph::GetInstance()->GetGameObject("Tetrahedron 2"));
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}
