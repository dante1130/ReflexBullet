//  camera.cpp
//
//  Implementation file for Camera Class
//  Defines all the methods declared, but not defined, in camera.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "Camera.h"

const unsigned char  *keysPressed;

//SDL event which is used for movement keys

//--------------------------------------------------------------------------------------
// Set initial values
//--------------------------------------------------------------------------------------
Camera::Camera()
{
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;

	ResetXYZ();

	m_prevX = 0;
	m_prevY = 0;

	m_deltaMoveFB = 0;
	m_deltaMoveLR = 0;
	m_deltaMoveUD = 0;

	m_rotateAngleLR = 0.0;
	m_rotateAngleUD = 0.0;
	m_deltaAngleLR = 0.0;
	m_deltaAngleUD = 0.0;

	m_CollisionDetectionOn = true;

	// sound objects
	m_audio.AddSound("sounds/step.wav", "stairstep");
}

//--------------------------------------------------------------------------------------
// Reset camera values
//--------------------------------------------------------------------------------------
void Camera::ResetXYZ()
{
	m_x = 0.0f;
	m_y = 1.75f;
	m_z = 0.0f;
	
	m_lookX = 0.0f;
	m_lookY = 0.0f;
	m_lookZ = -1.0f;
	
	m_lookXX = 1.0f;
	m_lookYY = 1.0f;
	m_lookZZ = 0.0f;
}

void Camera::KeyboardMovement()
{
	bool shift = false;
	bool crouch = false;
	

	/*
	if (GetKeyState(VK_LSHIFT) & 0x80) { shift = true; }
	
	//uses #include <Windows.h>
	if (GetKeyState('W') & 0x80 && !(GetKeyState('S') & 0x80))
	{
		WSKeyboardMovement(true, shift);
	}

	if (GetKeyState('S') & 0x80 && !(GetKeyState('W') & 0x80))
	{
		WSKeyboardMovement(false, shift);
	}

	if (GetKeyState('A') & 0x80 && !(GetKeyState('D') & 0x80))
	{
		ADKeyboardMovement(true, shift);
	}

	if (GetKeyState('D') & 0x80 && !(GetKeyState('A') & 0x80))
	{
		ADKeyboardMovement(false, shift);
	}
	*/

	WSKeyboardMovement(true, false);
	ADKeyboardMovement(true, false);
	
	callGLLookAt();
}

void Camera::WSKeyboardMovement(bool direction, bool sprint)
{
	if (m_deltaMoveFB == 0) { return; }

	float movementSpeed = m_moveSpeed;
	if (sprint) { movementSpeed = movementSpeed * 2; }
	//if (!direction) { movementSpeed = movementSpeed * -1; }
	if (m_deltaMoveLR != 0) { movementSpeed *= 0.5; } //So you can't run at twice the speed when running diagonally

	float xMove = m_lookX * movementSpeed;
	float zMove = m_lookZ * movementSpeed;

	float norm = movementSpeed / sqrt(pow(xMove, 2) + pow(zMove, 2)); //So it runs normally when looking up or down
	xMove *= norm * m_deltaMoveFB; //m_deltaMoveFB is used for the direction
	zMove *= norm * m_deltaMoveFB;
	
	//Checks if player can move in direction based on AABB
	if (!(m_colDetect.Collide(m_x + xMove, m_y + m_lookYY, m_z + zMove)))
	{
		m_x = m_x + xMove;
		m_z = m_z + zMove;


		//Makes sure that the camera object is on the right y height
		SetPlains(xMove, zMove);
	}
}

void Camera::ADKeyboardMovement(bool direction, bool sprint)
{
	if (m_deltaMoveLR == 0) { return; }

	float movementSpeed = m_moveSpeed;
	if (sprint) { movementSpeed = movementSpeed * 2; }
	//if (!direction) { movementSpeed = movementSpeed * -1; }
	if (m_deltaMoveFB != 0) { movementSpeed *= 0.5; } //So you can't run at twice the speed when running diagonally

	float xMove = m_lookZ * movementSpeed;
	float zMove = -m_lookX * movementSpeed;

	float norm = movementSpeed / sqrt(pow(xMove, 2) + pow(zMove, 2)); //So it runs normally when looking up or down
	xMove *= norm * -m_deltaMoveLR; //m_deltaMoveRL is used for the direction
	zMove *= norm * -m_deltaMoveLR;

	//Checks if player can move in direction based on AABB
	if (!(m_colDetect.Collide(m_x + xMove, m_y + m_lookYY, m_z + zMove)))
	{
		m_x = m_x + xMove;
		m_z = m_z + zMove;

		//Makes sure that the camera object is on the right y height
		SetPlains(xMove, zMove);
	}

}



//--------------------------------------------------------------------------------------
//  Determine direction
//--------------------------------------------------------------------------------------
void Camera::DirectionFB(int const & tempMove)
{
	m_deltaMoveFB = tempMove;
	
}
//--------------------------------------------------------------------------------------
void Camera::DirectionLR(int const & tempMove)
{
	// tempMove possible values
	// 1 = D is pressed
	// 2 = D is released
	// 1 = A is pressed
	// 2 = A is released

	if (tempMove == 1 && m_deltaMoveLR == -1){
		m_deltaMoveLR = 0;
	}
	else if (tempMove == -1 && m_deltaMoveLR == 1)
	{
		m_deltaMoveLR = 0;
	}
	else if (tempMove == 2 && m_deltaMoveLR == 1)
	{
		m_deltaMoveLR = 0;
	}
	else if (tempMove == 2 && m_deltaMoveLR == 0)
	{
		m_deltaMoveLR = -1;
	}
	else if (tempMove == -2 && m_deltaMoveLR == -1)
	{
		m_deltaMoveLR = 0;
	}
	else if (tempMove == -2 && m_deltaMoveLR == 0)
	{
		m_deltaMoveLR = 1;
	}
	else
	{
		m_deltaMoveLR = tempMove;
	}


}
//--------------------------------------------------------------------------------------
// Not used but allows up and don movement
void Camera::DirectionUD(int const & tempMove)
{
	m_deltaMoveUD = tempMove;
}


//----------------------------------------------------------------------------------------
//  Rotates camera based on mouse movement
//----------------------------------------------------------------------------------------
void Camera::MouseMove(int x, int y)
{
	// calculate delta by offsetting it with the previous x and y values with new values
	m_deltaAngleLR = x - m_prevX;
	m_deltaAngleUD = m_prevY - y;

	// updates the previous x and y values
	m_prevX = x;
	m_prevY = y;

	// updates the rotation angle
	m_rotateAngleLR += m_deltaAngleLR;
	m_rotateAngleUD += m_deltaAngleUD;

	// clamps between rotation angles of 89 and -89
	if (m_rotateAngleUD > 89.0f)
		m_rotateAngleUD = 89.0f;
	else if (m_rotateAngleUD < -89.0f)
		m_rotateAngleUD = -89.0f;

	m_lookX = sin(degreesToRadians(m_rotateAngleLR)) * cos(degreesToRadians(m_rotateAngleUD));
	m_lookY = sin(degreesToRadians(m_rotateAngleUD));
	m_lookZ = -cos(degreesToRadians(m_rotateAngleLR)) * cos(degreesToRadians(m_rotateAngleUD));

	int winW = glutGet(GLUT_WINDOW_WIDTH);
	int winH = glutGet(GLUT_WINDOW_HEIGHT);

	m_prevX = winW / 2;   
	m_prevY = winH / 2;
	glutWarpPointer(winW / 2, winH / 2);  //centers the cursor

	callGLLookAt();
}

//--------------------------------------------------------------------------------------
// Helper function for rotation
//--------------------------------------------------------------------------------------
GLdouble Camera::degreesToRadians(GLdouble degrees)
{
	return degrees * PI / 180;
}

//--------------------------------------------------------------------------------------
// Is ok to move camera backwards and forwards
//--------------------------------------------------------------------------------------
bool Camera::MoveFBOK()
{
	bool tempReturn;
	if (m_deltaMoveFB < 0 || m_deltaMoveFB > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}

//--------------------------------------------------------------------------------------
// Is ok to move camera sideways
//--------------------------------------------------------------------------------------
bool Camera::MoveLROK()
{
	bool tempReturn;
	if (m_deltaMoveLR < 0 || m_deltaMoveLR > 0)
	{
		tempReturn = true;
	}
	else
	{
		tempReturn = false;
	}
	return tempReturn;
}




//----------------------------------------------------------------------------------------
//  Places camera at the correct level on the current plain
//----------------------------------------------------------------------------------------
void Camera::SetPlains(const int & moveX, const int & moveZ)
{

	// store number of plains (stops from looping through linked list each time)
	if (m_No_Plains == 0) m_No_Plains = m_Plain.GetListSize();

	for (int i = 0;  i < m_No_Plains; i++)
	{
		// if camera is positioned on a plain
		if ((m_z <= m_Plain.GetZend(i)) && (m_z >= m_Plain.GetZstart(i))
			&& (m_x <= m_Plain.GetXend(i)) && (m_x >= m_Plain.GetXstart(i)))
		{
			// if flat plain
			if (m_Plain.GetType(i) == 0)
			{
				m_y = m_Plain.GetYstart(i);
				
				if ((m_plainNo != i) && m_plainHeight != m_Plain.GetYstart(i))
				{
					m_audio.PlaySound("stairstep");
				}

				m_plainNo = i;
				m_plainHeight = m_Plain.GetYstart(i);
			}
			// if plain slopes in z direction
			if (m_Plain.GetType(i) == 2)
			{
				float z1 = m_Plain.GetZstart(i);
				float z2 = m_Plain.GetZend(i);
				float dif = z1 - z2;

				float dist = m_z - z1;
				float ratio = (m_Plain.GetYstart(i) - m_Plain.GetYend(i)) / dif;

				m_y = m_Plain.GetYstart(i) + ratio * dist;

			}
			// if plain slopes in x direction	
			if (m_Plain.GetType(i) == 1)
			{
				// if plain slopes up or down
				if (m_xLast > m_x)
				{
					m_incrementX = ((m_y - m_Plain.GetYstart(i)) / (m_x - m_Plain.GetXstart(i)));
				}
				else
				{
					m_incrementX = ((m_Plain.GetYend(i) - m_y) / (m_Plain.GetXend(i) - m_x));
				}
				m_y += (m_incrementX * moveX);
			}		
		}
	}
}

//----------------------------------------------------------------------------------------
// Moves camera up and down (NOT USED)
//----------------------------------------------------------------------------------------
void Camera::MoveUD()
{
	if (m_CollisionDetectionOn)
	{
		GLdouble startY = m_y + m_deltaMoveUD * (m_lookYY) * m_moveSpeed * 5.0;

		if (!(m_colDetect.Collide(m_x + m_lookXX, startY + m_lookYY, m_z + m_lookZZ)))
		{
			m_y += m_deltaMoveUD * (m_lookYY) * m_moveSpeed;
			callGLLookAt();
		}
	}
	else
	{
		m_y += m_deltaMoveUD * (m_lookYY) * m_moveSpeed;
		callGLLookAt();
	}
}

//----------------------------------------------------------------------------------------
// Rotates camera left and right
//----------------------------------------------------------------------------------------
void Camera::RotateLR()
{
	m_rotateAngleLR += m_deltaAngleLR;
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	callGLLookAt();
}

//----------------------------------------------------------------------------------------
//  Rotates camera up and down
//----------------------------------------------------------------------------------------
void Camera::LookUD()
{
	m_rotateAngleUD += m_deltaAngleUD;
	m_lookY = sin(m_rotateAngleUD);
	callGLLookAt();
}

//----------------------------------------------------------------------------------------
// Positions camera at co-ordinates of parameters
//----------------------------------------------------------------------------------------
void Camera::Position (GLdouble const & tempX, GLdouble const & tempY,
			           GLdouble const & tempZ, GLdouble const & tempAngle)
{
	ResetXYZ();
	
	m_x = tempX;
	m_y = tempY;
	m_z = tempZ;

	// rotate to correct angle
	m_rotateAngleLR = tempAngle * (PI / 180);
	m_lookX = sin(m_rotateAngleLR);
	m_lookZ = -cos(m_rotateAngleLR);
	m_lookXX = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookZZ = -cos(m_rotateAngleLR + (float) PI/2.0);
	m_rotateAngleUD = 0.0;
	m_deltaAngleUD = 0.0;

	// redislay
	callGLLookAt();
}




//----------------------------------------------------------------------------------------
//  Redisplay new camera view
//----------------------------------------------------------------------------------------
void Camera::callGLLookAt()
{
	glLoadIdentity();
	gluLookAt(m_x, m_y, m_z, 
		      m_x + m_lookX, m_y + m_lookY, m_z + m_lookZ,
			  0.0f, 1.0f, 0.0f);
}

//--------------------------------------------------------------------------------------
// Display map of world
//----------------------------------------------------------------------------------------

void Camera::DisplayMap(const int & screenWidth, const int & screenHeight, 
		                const GLuint & tempImage)
{
	m_map.DisplayMap(screenWidth, screenHeight, GetLR (), GetFB (), tempImage);
}

//--------------------------------------------------------------------------------------
// Display welcome or exit page
//----------------------------------------------------------------------------------------

void Camera::DisplayWelcomeScreen(const int & screenWidth, const int & screenHeight, 
		                const int & tempExit, const GLuint & tempImage)
{
	 m_map.DisplayWelcomeScreen(screenWidth, screenHeight, tempExit, tempImage);
}

//--------------------------------------------------------------------------------------
// Display welcome or exit page
//----------------------------------------------------------------------------------------

void Camera::DisplayNoExit(const int & screenWidth, const int & screenHeight, 
		                   const GLuint & tempImage)
{
	 m_map.DisplayNoExit(screenWidth, screenHeight, tempImage);
}

//----------------------------------------------------------------------------------------

void Camera::SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ)
{
	m_colDetect.SetWorldX(tempX);
	m_colDetect.SetWorldZ(tempZ);
}

//----------------------------------------------------------------------------------------

void Camera::SetPlains (const int tempType,
				        const GLdouble tempXs, const GLdouble tempXe,
				        const GLdouble tempYs, const GLdouble tempYe,
				        const GLdouble tempZs, const GLdouble tempZe)
{
	m_Plain.AddToStart(tempType, tempXs, tempXe, tempYs, tempYe, tempZs, tempZe);
}