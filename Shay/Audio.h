#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <map>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_mixer.lib")

class Audio
{
public:
	Audio();

	~Audio();

	void AddSound(const char* soundPath, const char* soundName);

	void PlaySound(const char* soundName);

private:
	/// <soundName, soundClip>
	std::map<std::string, Mix_Chunk*> m_sounds;

	// Commented out, for future use.
	/// <soundName, musicClip>
	// std::map<std::string, Mix_Music*> m_music;
};

#endif