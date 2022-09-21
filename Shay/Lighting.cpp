#include "Lighting.h"

std::vector<Material> Materials;
int m_NumberOfLights = 7;

Light lights[8];

void Lighting::LightingInit()
{
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	GLfloat ambient[] = { 0.05, 0.05, 0.05 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	glEnable(GL_NORMALIZE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	LightInit();
	MaterialInit();
}

void Lighting::LightInit()
{
	int light[] = { 16384, 16385, 16386,  16387,  16388, 16389, 16390, 16391, };
	GLfloat light_position[8][4] = { {10, 2, 1, 1,},
									{1.5, 3, 1.5, 1},
									{-2, 2, 13, 1},
									{1.5, 3, 24.5, 1},
									{18.5, 3, 1.5, 1},
									{18.5, 3, 13, 1},
									{18.5, 3, 24.5, 1},
									{10, 3, 24, 1} };
	GLfloat light_ambient[4] = { 0.01, 0.01, 0.01, 1 };
	GLfloat light_diffuse[4] = { 1, 0.95, 0.88, 1 };
	GLfloat light_specular[4] = { 1, 1, 1, 1 };
	GLfloat dropOff = 0.25;

	for (int count = 0; count < m_NumberOfLights; count++)
	{
		for (int i = 0; i < 4; ++i)
		{
			lights[count].light_position[i] = light_position[count][i];
			lights[count].light_ambient[i] = light_ambient[i];
			lights[count].light_diffuse[i] = light_diffuse[i];
			lights[count].light_specular[i] = light_specular[i];
		}

		lights[count].dropOff = dropOff;
		lights[count].light = light[count];

		
		glLightfv(lights[count].light, GL_AMBIENT, lights[count].light_ambient);
		glLightfv(lights[count].light, GL_DIFFUSE, lights[count].light_diffuse);
		glLightfv(lights[count].light, GL_SPECULAR, lights[count].light_specular);
		glLightf(lights[count].light, GL_LINEAR_ATTENUATION, lights[count].dropOff);
		glEnable(lights[count].light);
	}
	float v[] = { 1, 0.95, 0.88, 1 };
	glLightfv(lights[0].light, GL_DIFFUSE, v);
	glLightf(lights[0].light, GL_LINEAR_ATTENUATION, 0.2);
	
	glDisable(GL_LIGHT7);
}

void Lighting::MaterialInit()
{
	

}

// Sets a light's properties
float z = 1;
void Lighting::SetLight(int index)
{
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(lights[index].light_position[0], lights[index].light_position[1], lights[index].light_position[2]);
	//glutSolidCube(0.5);
	glPopMatrix();


	glLightfv(lights[index].light, GL_POSITION, lights[index].light_position);

	glPopMatrix();
}

void Lighting::UpdateLighting(void)
{
	for (int i = 0; i < m_NumberOfLights; i++)
	{
		SetLight(i);
	}
}

void Lighting::SetLightPosition(int light, GLfloat pos[3])
{
	lights[light].light_position[0] = pos[0];
	lights[light].light_position[1] = pos[1];
	lights[light].light_position[2] = pos[2];
}

void Lighting::SetLightAmbient(int light, GLfloat amb[3])
{
	lights[light].light_ambient[0] = amb[0];
	lights[light].light_ambient[1] = amb[1];
	lights[light].light_ambient[2] = amb[2];
}

void Lighting::SetLightDiffuse(int light, GLfloat diff[3])
{
	lights[light].light_diffuse[0] = diff[0];
	lights[light].light_diffuse[1] = diff[1];
	lights[light].light_diffuse[2] = diff[2];
}

void Lighting::SetLightSpec(int light, GLfloat spec[3])
{
	lights[light].light_specular[0] = spec[0];
	lights[light].light_specular[1] = spec[1];
	lights[light].light_specular[2] = spec[2];

}

void Lighting::SetLightDropOff(int light, GLfloat dropOff)
{
	lights[light].dropOff = dropOff;
}

void Lighting::EnableLight(int light)
{
	glEnable(lights[light].light);
}

void Lighting::DisableLight(int light)
{
	glDisable(lights[light].light);
}