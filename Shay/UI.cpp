#include "UI.h"


//HUD Stuff
int h, w;
GLfloat healthColour[3] = { 0.0, 1.0, 0.0 };
GLfloat barBottom = 100;
GLfloat barHeight = barBottom + 1;
GLfloat health, startHealth;
bool hudOn = false;

void DrawHUD(Player& player)
{	
	if (hudOn) 
	{
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, w, 0, h);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		glDisable(GL_LIGHTING);
		CalculateBar(player);
		DisplayBar();
		glColor3f(1, 1, 1);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}

void DisplayBar()
{
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(HEALTH));
	glColor3f(healthColour[0], healthColour[1], healthColour[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(70, barBottom, 0);
	glTexCoord2f(1, 0);
	glVertex3f(140, barBottom, 0);
	glTexCoord2f(1, 1);
	glVertex3f(140, barHeight, 0);
	glTexCoord2f(0, 1);
	glVertex3f(70, barHeight, 0);
	glEnd();
}

void CalculateBar(Player& player)
{
	health = player.GetHealth();
	startHealth = player.GetStartHealth();
	if (health >= startHealth)
	{
		healthColour[0] = 0;
		healthColour[1] = 1;
	}
	else if (health >= (startHealth * 0.5))
	{
		healthColour[0] = 1 - ((health - (startHealth * 0.5)) / (startHealth * 0.5));
	}
	else if(!(health <= 0)) {
		healthColour[0] = 1;
		healthColour[1] = health / (startHealth * 0.5);
	}
	else
	{
		healthColour[0] = 1;
		healthColour[1] = 0;
	}

	if (barHeight > barBottom)
		barHeight = (h - barBottom) - (h - (barBottom * 2)) * (1 - (health / startHealth));
	
}

void GetScreenSize(int& width, int& height)
{
	w = width;
	h = height;
}