#ifndef UI_H
#define UI_H

#include <stdlib.h>
#include <GL/glut.h>
#include "LoadTexturesGameWorld.h"
#include "definesGW.h"

extern int totalTime;

void FindTime();

void DrawHUD();

void DisplayBar();

void CalculateBar();

void GetScreenSize(int& width, int& height);

#endif