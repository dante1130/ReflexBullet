#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <glm/vec3.hpp>
#include <string>
#include <map>

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

	static int GetSfxVolume();

	static int GetMusicVolume();
	

	/**
	* @brief	Loads a .wav file based on a given path, and gives a label for the sound.
	* @param	soundPath const char*
	* @param	soundName const char*
	* @return	void
	*/
	static void AddSound(const char* soundPath, const char* soundName);

	/**
	* @brief	Loads a music file based on a given path, and gives a label for the music.
	* @param	musicPath const char*
	* @param	soundName const char*
	* @return	void
	*/
	static void AddMusic(const char* musicPath, const char* musicName);

	/**
	* @brief	Plays the sound based on the label of the sound effect.
	* @param	soundName const char*
	* @return	void
	*/
	void PlaySound(const char* soundName);

	/**
	* @brief	Plays the music based on the label of the music effect.
	* @param	musicName const char*
	* @return	void
	*/
	static void PlayMusic(const char* musicName);

	static void SetSfxVolume(int volume);

	static void SetMusicVolume(int volume);

private:
	/// Sounds stored as values into a map, key is a string that contains the label.
	static std::map<std::string, Mix_Chunk*> m_sounds;

	/// Music stored as values into a map, key is a string that contains the label.
	static std::map<std::string, Mix_Music*> m_music;

	static int m_sfxVolume;

	static int m_musicVolume;

	/// Position of which the sound should be played
	glm::vec3 m_soundPos;
};

#endif