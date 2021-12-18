#ifndef SOUND_H
#define SOUND_H
#include "SDL_mixer.h"

class Sound
{
public:
	Mix_Music* music;
	Mix_Chunk* sound;
	Sound() 
	{
		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			Debug::FatalError("SDL audio failed to initialize.", "Sound.h", __LINE__);
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			std::cout << "Error : " << Mix_GetError() << std::endl;
		}
		music = Mix_LoadMUS("C:/Users/Masterflash/source/repos/GAME_258_Engine/GAME_258_Engine/Resources/Sound/spin_me_round.mp3");
		sound = Mix_LoadWAV("C:/Users/Masterflash/source/repos/GAME_258_Engine/GAME_258_Engine/Resources/Sound/no_vegetables.wav");
		std::cout << "Sound init" << std::endl;
		//Mix_PlayMusic(music, 1);
	}
	void PlayMusic()
	{
	}
	void PauseMusic()
	{
	}
};

#endif