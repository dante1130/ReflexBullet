#ifndef LIGHTING_H
#define LIGHTING_H

#include <vector>

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

extern std::vector<Material> Materials;

namespace Lighting
{
	


}



#endif