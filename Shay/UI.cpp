#include "UI.h"


//HUD Stuff
int h, w;
bool hudOn = false;

UI::UI(float offX, float offY, float barT, bool orient)
{
	barOffsetX = offX;
	barOffsetY = offY;
	barThickness = barT;
	orientation = orient;
}

void UI::SetExtras()
{
	if (orientation) //horizontal
	{
		barHeight = w - (barOffsetX * 2);
		addon[0] = barThickness;
		addon[1] = barHeight;
		tempOffset = barOffsetX;
	}
	else { //vertical
		barHeight = h - (barOffsetY * 2);
		addon[0] = barHeight;
		addon[1] = barThickness;
		tempOffset = barOffsetY;
	}
}

void UI::DrawHUD(GLfloat health, GLfloat startHealth)
{	
	if (!orientPass)
	{
		SetExtras();
		orientPass = true;
	}
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
		CalculateBar(health, startHealth);
		DisplayBar();
		glColor3f(1, 1, 1);

		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}

void UI::DisplayBar()
{
	glBindTexture(GL_TEXTURE_2D, tpGW.GetTexture(HEALTH));
	glColor3f(healthColour[0], healthColour[1], healthColour[2]);
	glBegin(GL_POLYGON);
		glTexCoord2f(0, 0);
		glVertex3f(barOffsetX, barOffsetY + addon[0], 0);
		glTexCoord2f(1, 0);
		glVertex3f(barOffsetX, barOffsetY, 0);
		glTexCoord2f(1, 1);
		glVertex3f(barOffsetX + addon[1], barOffsetY, 0);
		glTexCoord2f(0, 1);
		glVertex3f(barOffsetX + addon[1], barOffsetY + addon[0], 0);
	glEnd();
}

void UI::CalculateBar(GLfloat health, GLfloat startHealth)
{

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

	
	if (health > 0)
	{
		if (orientation) //horizontal
		{
			GLfloat desiredHeight = (w - barOffsetX) - (w - (barOffsetX * 2)) * (1 - (health / startHealth));
			barHeight = glm::mix(barHeight, desiredHeight, (GLfloat)0.02);
			addon[1] = barHeight - barOffsetX;
		}
		else //vertical
		{
			barHeight = (h - barOffsetY) - (h - (barOffsetY * 2)) * (1 - (health / startHealth));
			addon[0] = barHeight - barOffsetY;
		}
		std::cout << "Bar height: " << barHeight << "   Offset: " << tempOffset << std::endl;
	}
}

void UI::GetScreenSize(int& width, int& height)
{
	w = width;
	h = height;
}