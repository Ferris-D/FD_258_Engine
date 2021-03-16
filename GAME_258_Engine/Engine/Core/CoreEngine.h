#ifndef COREENGINE_H
#define COREENGINE_H

#include "../Rendering/3D/GameObject.h"
#include "../Graphics/ShaderHandler.h"
#include "../Graphics/TextureHandler.h"
#include "../Camera/Camera.h"

#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"
#include "Scene.h"
#include <memory>

class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	static CoreEngine* GetInstance();

	// Create a window pointer
	// Then call onto window to make a window with given parameters
	bool OnCreate(std::string name_, int width_, int height_);

	// Update and render if running, If not running then calls destroy
	void Run();
	void Exit();

	bool GetIsRunning();
	int GetCurrentScene() const;
	float GetScreenWidth() const;
	float GetScreenHeight() const;
	Camera* GetCamera() const;

	void SetGameInterface(GameInterface* gameInterface_);
	void SetCurrentScene(int sceneNum_);
	void SetCamera(Camera* camera_);

private:
	CoreEngine();
	~CoreEngine();

	void Update(const float deltaTime_);
	void Render();
	// Delete and clears the window pointer, then shutdown SDL and exit
	void OnDestroy();

	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;
	
	Window* window;
	bool isRunning;

	Timer* timer;
	unsigned int fps;

	GameInterface* gameInterface;

	int currentSceneNum;

	Camera* camera;
};

#endif