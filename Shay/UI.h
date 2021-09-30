#ifndef UI_H
#define UI_H

#include <stdlib.h>
#include <GL/glut.h>

#include "LoadTexturesGameWorld.h"
#include "definesGW.h"
#include "Player.h"



extern bool hudOn;


void DrawHUD(Player& player);

void DisplayBar();

void CalculateBar(Player& player);

void GetScreenSize(int& width, int& height);

#endif