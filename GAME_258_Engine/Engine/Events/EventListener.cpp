#include "EventListener.h"
#include "../Core/CoreEngine.h"

EventListener::~EventListener()
{
}

void EventListener::Update()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		if (sdlEvent.type == SDL_QUIT)
		{
			CoreEngine::GetInstance()->Exit();
		}
		switch (sdlEvent.type)
		{
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_KEYDOWN:
			switch (sdlEvent.key.keysym.sym)
			{
			case SDLK_w:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraForward(0.5);
				break;
			case SDLK_RIGHT:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraRight(0.5f);
				break;
			case SDLK_LEFT:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraLeft(0.5f);
				break;
			case SDLK_UP:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraUp(0.5f);
				break;
			case SDLK_DOWN:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraDown(0.5f);
				break;
			case SDLK_q:
				CoreEngine::GetInstance()->Exit();
				break;
			case SDLK_1:
				CoreEngine::GetInstance()->SetCurrentScene(1);
				break;
			case SDLK_2:
				CoreEngine::GetInstance()->SetCurrentScene(2);
				break;
			case SDLK_F1:
				CoreEngine::GetInstance()->SetMouseLock(SDL_FALSE);
				break;
			case SDLK_F2:
				CoreEngine::GetInstance()->SetMouseLock(SDL_TRUE);
				break;
			}
		case SDL_KEYUP:
			
		default:
			break;
		}
	}
}
