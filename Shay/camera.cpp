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
	crouch = false;
	crouchDepth = 0.0;

	m_rotateSpeed = 0.0;
	m_moveSpeed = 0.0;

	ResetXYZ();

	m_prev.x = 0;
	m_prev.y = 0;

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
	m_pos.x = 0.0f;
	m_pos.y = 1.75f;
	m_pos.z = 0.0f;
	
	m_look.x = 0.0f;
	m_look.y = 0.0f;
	m_look.z = -1.0f;
	
	m_lookK.x = 1.0f;
	m_lookK.y = 1.0f;
	m_lookK.z = 0.0f;
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

	WSKeyboardMovement();
	ADKeyboardMovement();
	
	callGLLookAt();
}

void Camera::SetAABBXZ(const int& tempIndex, const GLdouble& tempX1, const GLdouble& tempZ1, const GLdouble& tempX2, const GLdouble& tempZ2)
{
	SetAABBMaxX(tempIndex, tempX1);
	SetAABBMinX(tempIndex, tempX2);
	SetAABBMaxZ(tempIndex, tempZ1);
	SetAABBMinZ(tempIndex, tempZ2);
}

void Camera::SetAABBMaxX(const int& tempIndex, const GLdouble& tempX)
{
	m_colDetect.SetAABBMaxX(tempIndex, tempX);
}

void Camera::SetAABBMinX(const int& tempIndex, const GLdouble& tempX)
{
	m_colDetect.SetAABBMinX(tempIndex, tempX);
}

void Camera::SetAABBMaxY(const int& tempIndex, const GLdouble& tempY)
{
	m_colDetect.SetAABBMaxY(tempIndex, tempY);
}

void Camera::SetAABBMinY(const int& tempIndex, const GLdouble& tempY)
{
	m_colDetect.SetAABBMinY(tempIndex, tempY);
}

void Camera::SetAABBMaxZ(const int& tempIndex, const GLdouble& tempZ)
{
	m_colDetect.SetAABBMaxZ(tempIndex, tempZ);
}

void Camera::SetAABBMinZ(const int& tempIndex, const GLdouble& tempZ)
{
	m_colDetect.SetAABBMinZ(tempIndex, tempZ);
}

void Camera::SetRotateSpeed(const GLdouble& tempSpeed)
{
	m_rotateSpeed = tempSpeed;
}

void Camera::SetMoveSpeed(const GLdouble& tempSpeed)
{
	m_moveSpeed = tempSpeed;
}

void Camera::SetCollisionDetectionOn(const bool& tempCol)
{
	m_CollisionDetectionOn = tempCol;
}

void Camera::SetNoBoundingBoxes(const int& tempSize)
{
	m_colDetect.SetNoBoundingBoxes(tempSize);
}

void Camera::WSKeyboardMovement()
{
	if (m_deltaMoveFB == 0) { return; }

	float movementSpeed = m_moveSpeed;
	if (m_deltaMoveLR != 0) { movementSpeed *= 0.5; } //So you can't run at twice the speed when running diagonally
	if (crouch) { movementSpeed *= 0.5; }

	float xMove = m_look.x * movementSpeed;
	float zMove = m_look.z* movementSpeed;

	float norm = movementSpeed / sqrt(pow(xMove, 2) + pow(zMove, 2)); //So it runs normally when looking up or down
	xMove *= norm * m_deltaMoveFB; //m_deltaMoveFB is used for the direction
	zMove *= norm * m_deltaMoveFB;
	
	//Checks if player can move in direction based on AABB
	if (!(m_colDetect.Collide(m_pos.x + xMove, m_pos.y + m_lookK.y, m_pos.z + zMove)))
	{
		m_pos.x += xMove;
		m_pos.z += zMove;

		//Makes sure that the camera object is on the right y height
		SetPlains(xMove, zMove);
	}
}

void Camera::ADKeyboardMovement()
{
	if (m_deltaMoveLR == 0) { return; }

	float movementSpeed = m_moveSpeed;
	if (m_deltaMoveFB != 0) { movementSpeed *= 0.5; } //So you can't run at twice the speed when running diagonally
	if (crouch) { movementSpeed *= 0.5; }

	float xMove = m_look.z * movementSpeed;
	float zMove = -m_look.x * movementSpeed;

	float norm = movementSpeed / sqrt(pow(xMove, 2) + pow(zMove, 2)); //So it runs normally when looking up or down
	xMove *= norm * -m_deltaMoveLR; //m_deltaMoveRL is used for the direction
	zMove *= norm * -m_deltaMoveLR;

	//Checks if player can move in direction based on AABB
	if (!(m_colDetect.Collide(m_pos.x + xMove, m_pos.y + m_lookK.y, m_pos.z + zMove)))
	{
		m_pos.x += xMove;
		m_pos.z += zMove;

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
	m_deltaAngleLR = x - m_prev.x;
	m_deltaAngleUD = m_prev.y - y;

	// updates the previous x and y values
	m_prev.x = x;
	m_prev.y = y;

	// updates the rotation angle
	m_rotateAngleLR += m_deltaAngleLR;
	m_rotateAngleUD += m_deltaAngleUD;

	// clamps between rotation angles of 89 and -89
	if (m_rotateAngleUD > 89.0f)
		m_rotateAngleUD = 89.0f;
	else if (m_rotateAngleUD < -89.0f)
		m_rotateAngleUD = -89.0f;

	m_look.x = sin(degreesToRadians(m_rotateAngleLR)) * cos(degreesToRadians(m_rotateAngleUD));
	m_look.y = sin(degreesToRadians(m_rotateAngleUD));
	m_look.z = -cos(degreesToRadians(m_rotateAngleLR)) * cos(degreesToRadians(m_rotateAngleUD));

	int winW = glutGet(GLUT_WINDOW_WIDTH);
	int winH = glutGet(GLUT_WINDOW_HEIGHT);

	m_prev.x = winW / 2;   
	m_prev.y = winH / 2;
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
		if ((m_pos.z <= m_Plain.GetZEnd(i)) && (m_pos.z >= m_Plain.GetZStart(i))
			&& (m_pos.x <= m_Plain.GetXEnd(i)) && (m_pos.x >= m_Plain.GetXStart(i)))
		{
			// if flat plain
			if (m_Plain.GetType(i) == 0)
			{
				m_pos.y = m_Plain.GetYStart(i);
				
				if ((m_plainNo != i) && m_plainHeight != m_Plain.GetYStart(i))
				{
					m_audio.PlaySound("stairstep");
				}

				m_plainNo = i;
				m_plainHeight = m_Plain.GetYStart(i);
			}
			// if plain slopes in z direction
			if (m_Plain.GetType(i) == 2)
			{
				float z1 = m_Plain.GetZStart(i);
				float z2 = m_Plain.GetZEnd(i);
				float dif = z1 - z2;

				float dist = m_pos.z - z1;
				float ratio = (m_Plain.GetYStart(i) - m_Plain.GetYEnd(i)) / dif;

				m_pos.y = m_Plain.GetYStart(i) + ratio * dist;
			}
			// if plain slopes in x direction	
			if (m_Plain.GetType(i) == 1)
			{
				float x1 = m_Plain.GetXStart(i);
				float x2 = m_Plain.GetXEnd(i);
				float dif = x1 - x2;

				float dist = m_pos.x - x1;
				float ratio = (m_Plain.GetYStart(i) - m_Plain.GetYEnd(i)) / dif;

				m_pos.y = m_Plain.GetYStart(i) + ratio * dist;
			}		
		}
	}
}

GLdouble Camera::GetLR() const
{
	return m_pos.x;
}

GLdouble Camera::GetUD() const
{
	return m_pos.y;
}

GLdouble Camera::GetFB() const
{
	return m_pos.z;
}

GLdouble Camera::GetAABBMaxX(const int& tempIndex) const
{
	return m_colDetect.GetAABBMaxX(tempIndex);
}

GLdouble Camera::GetAABBMinX(const int& tempIndex) const
{
	return m_colDetect.GetAABBMinX(tempIndex);
}

GLdouble Camera::GetAABBMaxY(const int& tempIndex) const
{
	return m_colDetect.GetAABBMaxY(tempIndex);
}

GLdouble Camera::GetAABBMinY(const int& tempIndex) const
{
	return m_colDetect.GetAABBMinY(tempIndex);
}

GLdouble Camera::GetAABBMaxZ(const int& tempIndex) const
{
	return m_colDetect.GetAABBMaxZ(tempIndex);
}

GLdouble Camera::GetAABBMinZ(const int& tempIndex) const
{
	return m_colDetect.GetAABBMinZ(tempIndex);
}

//----------------------------------------------------------------------------------------
// Positions camera at co-ordinates of parameters
//----------------------------------------------------------------------------------------
void Camera::Position (GLdouble const & tempX, GLdouble const & tempY,
			           GLdouble const & tempZ, GLdouble const & tempAngle)
{
	ResetXYZ();
	
	m_pos.x = tempX;
	m_pos.y = tempY;
	m_pos.z = tempZ;

	// rotate to correct angle
	m_rotateAngleLR = tempAngle * (PI / 180);
	m_look.x = sin(m_rotateAngleLR);
	m_look.z = -cos(m_rotateAngleLR);
	m_lookK.x = sin(m_rotateAngleLR + (float) PI/2.0);
	m_lookK.z = -cos(m_rotateAngleLR + (float) PI/2.0);
	m_rotateAngleUD = 0.0;
	m_deltaAngleUD = 0.0;

	// redisplay
	callGLLookAt();
}


void Camera::SetCrouch(bool setCrouch)
{
	crouch = setCrouch;
	crouchTime = glutGet(GLUT_ELAPSED_TIME);
}

void Camera::CrouchDistance()
{
	if (crouch && crouchDepth == -210) return;
	if (!crouch && crouchDepth == 0) return;

	float change = CROUCH_DEPTH * ((float)(glutGet(GLUT_ELAPSED_TIME) - crouchTime) / CROUCH_SPEED);
	if (!crouch) change *= -1;

	crouchDepth = crouchDepth + change;
	crouchTime = glutGet(GLUT_ELAPSED_TIME);

	if (crouchDepth < -210) crouchDepth = -210;
	if (crouchDepth > 0) crouchDepth = 0;
}


//----------------------------------------------------------------------------------------
//  Redisplay new camera view
//----------------------------------------------------------------------------------------
void Camera::callGLLookAt()
{
	glLoadIdentity();
	CrouchDistance();
	gluLookAt(m_pos.x, m_pos.y + crouchDepth, m_pos.z, m_pos.x + m_look.x,	// Eye
			  m_pos.y + m_look.y + crouchDepth, m_pos.z + m_look.z,			// Look at
			  0, 1, 0);														// Up
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

void Camera::InitiateBoundingBoxes()
{
	m_colDetect.CreateLinkedList();
}

//----------------------------------------------------------------------------------------

void Camera::SetPlains (const int tempType,
				        const GLdouble tempXs, const GLdouble tempXe,
				        const GLdouble tempYs, const GLdouble tempYe,
				        const GLdouble tempZs, const GLdouble tempZe)
{
	m_Plain.AddToStart(tempType, tempXs, tempXe, tempYs, tempYe, tempZs, tempZe);
}