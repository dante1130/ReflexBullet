#ifndef LIGHTING_H
#define LIGHTING_H

#include <vector>
#include <GL/glut.h>

struct Material
{
	///	Ks is weighting against the specular exponent Ns
	float Ns;
	///	Ambient colour of the material
	float Ka[3];
	///	Diffuse colour of the material
	float Kd[3];
	///	Specular colour of the material
	float Ks[3];
	/// Emission colour of the material
	float Ke[3];
	///	Specifies index of refraction
	float Ni;
	///	Transparency where 1 = fully opaque
	float d;

	Material()
	{
		Ns = 500;
		d = 1;
		Ni = 1;

		for (int i = 0; i < 3; ++i)
		{
			Ke[i] = 0.0f;
			Ka[i] = 0.05f;
			Kd[i] = 0.95f;
			Ks[i] = 1.0f;
		}
	}
};

struct Light
{
	/// Which light is being used
	int light;
	/// The position of the light
	GLfloat light_position[4];
	/// The lights ambient value
	GLfloat light_ambient[4];
	/// The lights diffuse value
	GLfloat light_diffuse[4];
	/// The lights specular value
	float light_specular[4];
	/// The lights drop off values. Higher = larger drop off
	float dropOff;
};

/// Materials	- A vector of materials
extern std::vector<Material> Materials;

namespace Lighting
{
	/**
	* @brief	Initialises the lighting properties
	* @param	No param
	* @return	Void
	*/
	void LightingInit();

	/**
	* @brief	Initialises individual lights
	* @param	No param
	* @return	Void
	*/
	void LightInit();

	/**
	* @brief	Initialises some basic materials
	* @param	No param
	* @return	Void
	*/
	void MaterialInit();

	/**
	* @brief	Updates all the lights in the scene
	* @param	No param
	* @return	Void
	*/
	void UpdateLighting();

	/**
	* @brief	Re-sets the location of a specific light
	* @param	light	- The light that you want to update
	* @return	Void
	*/
	void SetLight(int light);

	/**
	* @brief	Sets the lights position
	* @param	light	- The light that you want to update
	* @param	pos[3]	- The position of the light
	* @return	Void
	*/
	void SetLightPosition(int light, GLfloat pos[3]);

	/**
	* @brief	Sets the lights ambient component
	* @param	light	- The light that you want to update
	* @param	amb[3]	- The ambient value of the light
	* @return	Void
	*/
	void SetLightAmbient(int light, GLfloat amb[3]);

	/**
	* @brief	Sets the lights diffuse component
	* @param	light	- The light that you want to update
	* @param	diff[3]	- The diffuse value of the light
	* @return	Void
	*/
	void SetLightDiffuse(int light, GLfloat diff[3]);

	/**
	* @brief	Sets the lights specular component
	* @param	light	- The light that you want to update
	* @param	spec[3]	- The specular value of the light
	* @return	Void
	*/
	void SetLightSpec(int light, GLfloat spec[3]);

	/**
	* @brief	Sets the lights drop off
	* @param	light	- The light that you want to update
	* @param	dropOff	- The dropOff of the light (larger = more dropOff)
	* @return	Void
	*/
	void SetLightDropOff(int light, GLfloat dropOff);

	/**
	* @brief	Enables the light
	* @param	light	- The light that you want to update
	* @return	Void
	*/
	void EnableLight(int light);

	/**
	* @brief	Disables the light
	* @param	light	- The light that you want to update
	* @return	Void
	*/
	void DisableLight(int light);

}


#endif