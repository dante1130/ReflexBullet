#ifndef UI_H
#define UI_H

#include <stdlib.h>
#include <GL/glut.h>

#include "LoadTexturesGameWorld.h"
#include "definesGW.h"
#include "BaseCharacter.h"



extern bool hudOn;

class UI {
public:

	UI(float offX, float offY, float barT, bool orient);
	void DrawHUD(GLfloat health, GLfloat startHealth);
	void GetScreenSize(int& width, int& height);

private:

	void DisplayBar();
	void CalculateBar(GLfloat health, GLfloat startHealth);
	void SetExtras();

	bool orientation;
	GLfloat healthColour[3] = { 0.0, 1.0, 0.0 };
	GLfloat barOffsetX, barOffsetY;
	GLfloat barThickness;
	GLfloat barHeight;

	bool orientPass = false;
	GLfloat tempOffset;
	GLfloat addon[2] = { 0.0 };
};


#endif