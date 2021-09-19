#include "Audio.h"

std::map<std::string, Mix_Chunk*> Audio::m_sounds;

Audio::Audio()
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
}

Audio::~Audio()
{
	for (auto itr = m_sounds.begin(); itr != m_sounds.end(); ++itr)
	{
		Mix_FreeChunk(itr->second);
		itr->second = nullptr;
	}

	Mix_CloseAudio();
}

void Audio::AddSound(const char* soundPath, const char* soundName)
{
	Mix_Chunk* wave = nullptr;

	wave = Mix_LoadWAV(soundPath);
	if (wave == nullptr) return;

	m_sounds[soundName] = wave;
}

void Audio::PlaySound(const char* soundName)
{
	auto itr = m_sounds.find(soundName);
	
	if (itr != m_sounds.end())
	{
		Mix_PlayChannel(-1, itr->second, 0);
	}
}