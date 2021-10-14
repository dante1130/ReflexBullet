#include "Audio.h"

std::map<std::string, Mix_Chunk*> Audio::m_sounds;
std::map<std::string, Mix_Music*> Audio::m_music;

int Audio::m_musicVolume = 100;
int Audio::m_sfxVolume = 100;

Audio::Audio()
	: m_soundPos(0)
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_Volume(-1, 100);
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

int Audio::GetSfxVolume()
{
	return m_sfxVolume;
}

int Audio::GetMusicVolume()
{
	return m_musicVolume;
}

void Audio::AddMusic(const char* musicPath, const char* musicName)
{
	Mix_Music* music = nullptr;

	music = Mix_LoadMUS(musicPath);
	if (music) m_music[musicName] = music;
}

void Audio::AddSound(const char* soundPath, const char* soundName)
{
	Mix_Chunk* wave = nullptr;

	wave = Mix_LoadWAV(soundPath);
	if (wave) m_sounds[soundName] = wave;
}

void Audio::PlaySound(const char* soundName)
{
	auto itr = m_sounds.find(soundName);

	if (itr != m_sounds.end()) Mix_PlayChannel(-1, itr->second, 0);
}

void Audio::PlayMusic(const char* musicName)
{
	auto itr = m_music.find(musicName);

	if (itr != m_music.end())
		Mix_PlayMusic(itr->second, -1);
}

void Audio::SetSfxVolume(int volume)
{
	if (volume > 100)
		m_sfxVolume = 100;
	else if (volume < 0)
		m_sfxVolume = 0;
	else
		m_sfxVolume = volume;
	
	for (auto itr = m_sounds.begin(); itr != m_sounds.end(); ++itr)
		Mix_VolumeChunk(itr->second, m_sfxVolume);
}

void Audio::SetMusicVolume(int volume)
{
	if (volume > 100)
		m_musicVolume = 100;
	else if (volume < 0)
		m_musicVolume = 0;
	else
		m_musicVolume = volume;

	Mix_VolumeMusic(m_musicVolume);
}
