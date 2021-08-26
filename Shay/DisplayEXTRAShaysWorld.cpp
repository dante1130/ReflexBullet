#include "DisplayEXTRAShaysWorld.h"

//The main environment object
Object3D EnvironmentOBJ;


void DisplayExtension()
{
	//Object test
	glPushMatrix();

	glTranslatef(2613.56, 10000, 9250);
	glRotatef(180, 0, 1, 0);

	EnvironmentOBJ.DisplayObject(TEXT_ENVIRONMENT);


	glPopMatrix();




	return;
}