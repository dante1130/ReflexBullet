#include "UI.h"


//HUD Stuff
int h, w;
float healthColour[3] = { 0.0, 1.0, 0.0 };
float barHeight;
int lastTime = 0;
int totalTime;
int givenTime = 30000; //given 30 seconds

void FindTime()
{
	int timeDifference = glutGet(GLUT_ELAPSED_TIME) - lastTime;
	if (lastTime == 0)
	{
		timeDifference = 0;
	};
	lastTime = glutGet(GLUT_ELAPSED_TIME);
	totalTime += timeDifference;
}

void DrawHUD()
{
	FindTime();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_LIGHTING);
	CalculateBar();
	DisplayBar();
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void DisplayBar()
{
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(HEALTH));
	glColor3f(healthColour[0], healthColour[1], healthColour[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(70, 100, 0);
	glTexCoord2f(1, 0);
	glVertex3f(140, 100, 0);
	glTexCoord2f(1, 1);
	glVertex3f(140, barHeight, 0);
	glTexCoord2f(0, 1);
	glVertex3f(70, barHeight, 0);
	glEnd();
}

void CalculateBar()
{
	if (totalTime >= givenTime)
	{
		healthColour[0] = 1;
		healthColour[1] = 0;
		totalTime = givenTime;
	}
	else if (totalTime <= (givenTime * 0.5))
	{
		healthColour[0] = (float)totalTime / (givenTime * 0.5);
	}
	else {
		healthColour[0] = 1;
		healthColour[1] = 1 - ((float)(totalTime - (givenTime * 0.5)) / (givenTime * 0.5));
	}

	if (totalTime < 0)
		totalTime = 0;

	if (barHeight < 100)
		barHeight = 100;
	else
		barHeight = (h - 100) - (h - 200) * ((float)totalTime / givenTime);
}

void GetScreenSize(int& width, int& height)
{
	w = width;
	h = height;
}