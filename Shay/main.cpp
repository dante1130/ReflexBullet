#include <cstdlib>
#include <cmath>
#include <ctime>
#include "../include/GL/glut.h"

#include "fileIO.h"
#include "ProcessShaysWorld.h"

//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
/**
* @brief	Main function
* @param	argc	- Int of how many arguments in char array
* @param	argv	- Char array
* @return	int
*/
int main(int argc, char** argv)
{
	std::cout << "Hello World!" << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Duck and Cover 2: Duck Harder");

	PSW::myinit();

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(PSW::keys);
	glutKeyboardUpFunc(PSW::releaseKeys);
	
	glutDisplayFunc(PSW::Display);
	glutTimerFunc(FRAMETIME, PSW::RenderLoop, 0);

	glutMouseFunc(PSW::Mouse);

	glutSetCursor(GLUT_CURSOR_NONE);

	glutReshapeFunc(PSW::reshape);
	glutMainLoop();

	return 0;
}