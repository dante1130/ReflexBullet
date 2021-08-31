#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <map>

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2_mixer.lib")

/**
* @class	Audio
* @author	Andrew Ho
* @brief	Plays sound effects and music.
* 
* Audio player using SDL_Mixer, can be used to play load .wav files
* and play them.
* 
* Future implementations include playing music.
*/
class Audio
{
public:

	/**
	* @brief	Initializes SDL Audio and SDL Mixer.
	* @param	No param
	* @return	void
	*/
	Audio();

	/**
	* @brief	Frees up memory of mix chunks and erases the map.
	* @param	No param
	* @return	void
	*/
	~Audio();

	/**
	* @brief	Loads a .wav file based on a given path, and gives a label for the sound.
	* @param	No param
	* @return	void
	*/
	void AddSound(const char* soundPath, const char* soundName);

	/**
	* @brief	Plays the sound based on the label of the sound effect.
	* @param	No param
	* @return	void
	*/
	void PlaySound(const char* soundName);

private:
	/// Sounds stored as values into a map, key is a string that contains the label.
	std::map<std::string, Mix_Chunk*> m_sounds;

	// Not used for now.
	/// Music stored as values into a map, key is a string that contains the label.
	// std::map<std::string, Mix_Music*> m_music;
};

#endif