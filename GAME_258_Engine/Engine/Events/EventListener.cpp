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
			case SDLK_RIGHT:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraRight(1.0f);
				break;
			case SDLK_LEFT:
				CoreEngine::GetInstance()->GetCamera()->MoveCameraLeft(1.0f);
				break;
			}
		case SDL_KEYUP:
			
		default:
			break;
		}
	}
}
