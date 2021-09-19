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
	///	Specifies index of refraction
	float Ni;
	///	Transparency where 1 = fully opaque
	float d;
};

struct Light
{
	int light;
	GLfloat light_position[4];
	GLfloat light_ambient[4];
	GLfloat light_diffuse[4];
	float light_specular[4];
	float dropOff;
};


extern std::vector<Material> Materials;


namespace Lighting
{
	void LightingInit();

	void LightInit();

	void MaterialInit();

	void UpdateLighting();

	void SetLight(int light);


}


#endif