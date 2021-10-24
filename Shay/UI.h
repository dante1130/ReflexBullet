#ifndef UI_H
#define UI_H

#include <stdlib.h>
#include <GL/glut.h>
#include <glm/glm.hpp>

#include "LoadTexturesGameWorld.h"
#include "definesGW.h"
#include "BaseCharacter.h"


extern bool hudOn;

class UI {
public:

	/**
	 * @brief Constructor for health bar UI.
	 * @param offX float
	 * @param offY float
	 * @param barT float
	 * @param orient bool
	 */
	UI(float offX, float offY, float barT, bool orient);
	/**
	 * @brief Constructor for health bar UI.
	 * @param health GLfloat
	 * @param startHealth GLfloat
	 * @return void
	 */
	void DrawHUD(GLfloat health, GLfloat startHealth);
	/**
	 * @brief Used to obtain size of screen.
	 * @param width int&
	 * @param height int&
	 * @return void
	 */
	void GetScreenSize(int& width, int& height);

private:

	/**
	 * @brief Displays health bar on-screen.
	 * @return void
	 */
	void DisplayBar();
	/**
	 * @brief Calculates size of bar determined by
	 * base characters health and start health.
	 * @param health GLfloat
	 * @param startHealth GLfloat
	 * @return void
	 */
	void CalculateBar(GLfloat health, GLfloat startHealth);
	/**
	 * @brief Sets specific values determined by the bars
	 * orientation.
	 * @return void
	 */
	void SetExtras();

	bool orientation; //orientation of health bar
	GLfloat healthColour[3] = { 0.0, 1.0, 0.0 }; // RGB values of health bar
	GLfloat barOffsetX, barOffsetY; //distance from left or bottom of screen respectively
	GLfloat barThickness; //thickness of bar
	GLfloat barHeight; //length of bar

	GLfloat tempOffset; //records temporary offset depending on orientation
	GLfloat addon[2] = { 0.0 }; //stores temporary values for height and thickness depending on orientation
};


#endif