#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;

CoreEngine::CoreEngine() :window(nullptr), isRunning(false){}

CoreEngine::~CoreEngine(){}

CoreEngine* CoreEngine::GetInstance()
{
	if (engineInstance.get() == nullptr)
	{
		engineInstance.reset(new CoreEngine);
	}
	return engineInstance.get();
}

// Create a window pointer
// Then call onto window to make a window with given parameters
bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
	window = new Window();
	if (!window->OnCreate(name_, width_, height_))
	{
		std::cout << "Window failed to initialize" << std::endl;
		OnDestroy();
		return isRunning = false;
 	}
	return isRunning = true;
}

// Update and render if running, If not running then calls destroy
void CoreEngine::Run()
{
	while (isRunning)
	{
		Update(0.016f);
		Render();
	}
	if (!isRunning)
	{
		OnDestroy();
	}
}

bool CoreEngine::GetIsRunning()
{
	return isRunning;
}

// Physics
void CoreEngine::Update(const float deltaTime_)
{
}

void CoreEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Game render here soon
	SDL_GL_SwapWindow(window->GetWindow());
}

// Delete and clears the window pointer, then shutdown SDL and exit
void CoreEngine::OnDestroy()
{
	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
}
