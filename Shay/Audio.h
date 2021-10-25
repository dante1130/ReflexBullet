#ifndef AUDIO_H
#define AUDIO_H

#include <SDL.h>
#include <iostream> // debugging purposes
#include <SDL_mixer.h>
#include <glm/vec3.hpp>
#include <string>
#include <map>

/**
* @class	Audio
* @author	Andrew Ho
* @brief	Plays sound effects and music.
* 
* Encapsulated audio player using SDL_Mixer, can be used to play load sound files
* and play them as an sfx or music.
* 
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
	 * @brief	Getter for the sfx volume.
	 * @return	int
	 */
	static int GetSfxVolume();

	/**
	 * @brief	Getter for the music volume.
	 * @return	int
	 */
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
	* @param	musicName const char*
	* @return	void
	*/
	static void AddMusic(const char* musicPath, const char* musicName);

	/**
	* @brief	Plays the sound based on the label of the sound effect.
	* @param	soundName const char*
	* @return	void
	*/
	static void PlaySound(const char* soundName);

	/**
	* @brief	Plays the music based on the label of the music effect.
	* @param	musicName const char*
	* @return	void
	*/
	static void PlayMusic(const char* musicName);

	/**
	 * @brief	Getter for the sfx volume.
	 * @param	musicName const char*
	 * @return	void
	 */
	static void PlayMusicFadeIn(const char* musicName);

	/**
	 * @brief	Setter for sfx volume.
	 * @param	volume int
	 * @return  void
	 */
	static void SetSfxVolume(int volume);

	/**
	 * @brief	Setter for music volume.
	 * @param	volume int
	 * @return  void
	 */
	static void SetMusicVolume(int volume);

private:
	/// Sounds stored as values into a map, key is a string that contains the label.
	static std::map<std::string, Mix_Chunk*> m_sounds;

	/// Music stored as values into a map, key is a string that contains the label.
	static std::map<std::string, Mix_Music*> m_music;

	/// The sfx volume.
	static int m_sfxVolume;

	/// The music volume.
	static int m_musicVolume;

	/// Position of which the sound should be played
	glm::vec3 m_soundPos;
};

#endif