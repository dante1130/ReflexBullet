//  camera.cpp
//
//  Implementation file for Camera Class
//  Defines all the methods declared, but not defined, in camera.h
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#include "Camera.h"

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

	m_collisionDetectionOn = true;

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

void Camera::AddAABB(const glm::vec3& max, const glm::vec3& min)
{
	m_colDetect.Push(max, min);
}

void Camera::SetRotateSpeed(const GLdouble& tempSpeed)
{
	m_rotateSpeed = tempSpeed;
}

void Camera::SetMoveSpeed(const GLdouble& tempSpeed)
{
	m_moveSpeed = tempSpeed;
}

void Camera::SetCollisionDetectionOn(bool tempCol)
{
	m_collisionDetectionOn = tempCol;
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
	if (!(m_colDetect.Collide(glm::dvec3(m_pos.x + xMove, m_pos.y + m_lookK.y, m_pos.z + zMove))))
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
	if (!(m_colDetect.Collide(glm::dvec3(m_pos.x + xMove, m_pos.y + m_lookK.y, m_pos.z + zMove))))
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
	if (m_No_Plains == 0) m_No_Plains = m_plain.Size();


	glm::vec3 plainStart, plainEnd;
	float x1, x2, z1, z2, dif, dist, ratio, area, areaSum;

	for (int i = 0;  i < m_No_Plains; i++)
	{
		plainStart = m_plain.GetStart(i);
		plainEnd = m_plain.GetEnd(i);

		// if camera is positioned on a plain
		if ((m_pos.z <= plainEnd.z) && (m_pos.z >= plainStart.z)
			&& (m_pos.x <= plainEnd.x) && (m_pos.x >= plainStart.x))
		{
			// if flat plain
			if (m_plain.GetType(i) == 0)
			{
				m_pos.y = plainEnd.y;
				
				if ((m_plainNo != i) && m_plainHeight != plainStart.y)
				{
					m_audio.PlaySound("stairstep");
				}

				m_plainNo = i;
				m_plainHeight = plainStart.y;
			}
			// if plain slopes in z direction
			if (m_plain.GetType(i) == 2)
			{
				z1 = plainStart.z;
				z2 = plainEnd.z;
				dif = z1 - z2;

				dist = m_pos.z - z1;
				ratio = (plainStart.y - plainEnd.y) / dif;

				m_pos.y = plainStart.y + ratio * dist;
			}
			// if plain slopes in x direction	
			if (m_plain.GetType(i) == 1)
			{
				x1 = plainStart.x;
				x2 = plainEnd.x;
				dif = x1 - x2;

				dist = m_pos.x - x1;
				ratio = (plainStart.y - plainEnd.y) / dif;

				m_pos.y = plainStart.y + ratio * dist;
			}	

			//if plain is diagonal flat plain
			
		}
		else if (m_plain.GetType(i) == DIAGONAL_FLAT_PLAIN)
		{
			plainStart = m_plain.GetQ2(i) - m_plain.GetStart(i);
			plainEnd = m_plain.GetEnd(i) - m_plain.GetQ2(i);
			area = abs(plainStart.z * plainEnd.x - plainStart.x * plainEnd.z);

			plainStart = m_plain.GetQ4(i) - m_plain.GetEnd(i);
			plainEnd = m_plain.GetQ4(i) - m_plain.GetStart(i);
			area += abs(plainStart.z * plainEnd.x - plainStart.x * plainEnd.z);

			areaSum = AreaPlainTriangle(1, i);
			areaSum += AreaPlainTriangle(2, i);
			areaSum += AreaPlainTriangle(3, i);
			areaSum += AreaPlainTriangle(4, i);

			if (areaSum - area >= -0.01 && areaSum - area <= 0.01)
			{
				m_pos.y = m_plain.GetStart(i).y;
				if ((m_plainNo != i) && m_plainHeight != m_plain.GetStart(i).y)
				{
					m_audio.PlaySound("stairstep");
				}
				m_plainNo = i;
				m_plainHeight = m_plain.GetStart(i).y;
			}
		}
	}
}

GLdouble Camera::AreaPlainTriangle(int edgeNo, int i)
{
	glm::vec3 plainEnd;
	glm::vec3 plainStart;

	if (edgeNo == 1)
	{
		plainStart = m_plain.GetStart(i) - m_plain.GetQ2(i);
		
		plainEnd.x = m_plain.GetStart(i).x - m_pos.x;
		plainEnd.z = m_plain.GetStart(i).z - m_pos.z;
	}
	else if (edgeNo == 2)
	{
		plainStart = m_plain.GetQ2(i) - m_plain.GetEnd(i);

		plainEnd.x = m_plain.GetQ2(i).x - m_pos.x;
		plainEnd.z = m_plain.GetQ2(i).z - m_pos.z;
	}
	else if (edgeNo == 3)
	{
		plainStart = m_plain.GetEnd(i) - m_plain.GetQ4(i);

		plainEnd.x = m_plain.GetEnd(i).x - m_pos.x;
		plainEnd.z = m_plain.GetEnd(i).z - m_pos.z;

	}
	else
	{
		plainStart = m_plain.GetQ4(i) - m_plain.GetStart(i);

		plainEnd.x = m_plain.GetQ4(i).x - m_pos.x;
		plainEnd.z = m_plain.GetQ4(i).z - m_pos.z;
	}

	
	plainStart.y = 0;
	plainEnd.y = 0;

	return abs(plainStart.z * plainEnd.x - plainStart.x * plainEnd.z);
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

//----------------------------------------------------------------------------------------
// Positions camera at co-ordinates of parameters
//----------------------------------------------------------------------------------------
void Camera::Position (const glm::vec3& tempPos, const GLdouble& tempAngle)
{
	ResetXYZ();
	
	m_pos = tempPos;

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

//----------------------------------------------------------------------------------------

void Camera::AddPlain(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd)
{
	m_plain.Push(tempType, tempStart, tempEnd);
}

void Camera::AddPlain(const GLint tempType, const glm::vec3& t1, const glm::vec3& t2, const glm::vec3& t3, const glm::vec3& t4)
{
	m_plain.Push(tempType, t1, t2, t3, t4);
}


void Camera::SetCameraLocation(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}