//  camera.h
//  Header file for the camera class
//	Allows the camera to be navigated around the world. 
//	Also sets Plains, Bounding Boxes and view Maps
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#include "collision.h"
#include "cameraMap.h"
#include "PlainVector.h"
#include "Audio.h"
#include "defines.h"

#include <iostream>
#include <cmath>
#include <gl/glut.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

//--------------------------------------------------------------------------------------

class Camera
{
public:
	Camera();

	/**
	* @brief	Handles all key movement for movement speed
	* @return	void
	*/
	void KeyboardMovement();

	void AddAABB(const glm::vec3& max, const glm::vec3& min);

	void PrintPos()
	{
		std::cout << m_pos.x << " " << m_pos.y << " " << m_pos.z << std::endl;
	}
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	// set step and rotation size
	void SetRotateSpeed (const GLdouble &tempSpeed);
	void SetMoveSpeed (const GLdouble &tempSpeed);

	// COLLSION DETECTION FUNCTIONS
	// set collision detection (TRUE = on)
	void SetCollisionDetectionOn(bool tempCol);

	// set the co-ordinates of the world
	void SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ);

	// sets the co-ordinate of each plain
	void AddPlain(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

	/**
	* @brief	Used diagonal plains (only flat implemented)
	* @brief	tempType	- The type of plain implemented
	* @param	t1			- First quardinate
	* @param	t2			- Second quardinate
	* @param	t3			- Third quardinate
	* @param	t4			- Fourth quardinate
	* @return	Void
	*/
	void Camera::AddPlain(const GLint tempType, const glm::vec3& t1, const glm::vec3& t2, const glm::vec3& t3, const glm::vec3& t4);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	GLdouble GetLR () const;
	GLdouble GetUD () const;
	GLdouble GetFB () const;	
	
	// position the camera
	void Position(const glm::vec3& tempPos, const GLdouble& tempAngle);

	// Used to pass direction to move or rotate  (i.e. 1, -1 or 0)
	void DirectionFB(int const & tempMove);
	void DirectionLR(int const & tempMove);
	void DirectionUD(int const & tempMove);

	// Use mouse to look around
	void MouseMove(int x, int y);

	// display map
	void DisplayMap(const int & screenWidth, const int & screenHeight, 
		            const GLuint & tempImage);
	// display welcome screen
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight,
							   const int & tempExit, const GLuint & tempImage);
	// display no exit
	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);
	
	/**
	* @brief	Sets if the player is crouching
	* @param	setCrouch	- True if crouching, false if not crouching
	* @return	Void
	*/
	void SetCrouch(bool setCrouch);

	/**
	* @brief	Sets the players camera location
	* @param	x	- X coordinate
	* @param	y	- Y coordinate
	* @param	z	- Z coordiante
	* @return	Void
	*/
	void SetCameraLocation(float x, float y, float z);

private:
	bool m_firstMouse;

	/// If the player is crouching or not
	bool crouch;
	/// The current crouch depth
	GLdouble crouchDepth;
	/// When the function was last called
	long crouchTime; 

	/// Step incline increments.
	GLdouble m_incrementX, m_incrementZ;
	/// Number of plains.
	int m_No_Plains;
	/// The plain's number.
	int m_plainNo;
	/// Height of the plain.
	GLdouble m_plainHeight;

	// rotation variables
	/// Previous mouse position.
	glm::ivec2 m_prev; 
	/// yaw.
	GLdouble m_rotateAngleLR, m_deltaAngleLR;
	/// pitch.
	GLdouble m_rotateAngleUD, m_deltaAngleUD;

	// movement variables
	/// The position.
	glm::dvec3 m_pos;
		
	/// The previous position.
	GLdouble m_zLast, m_xLast;

	/// The center or where to look at.
	glm::dvec3 m_look;
	glm::dvec3 m_lookK; // I don't know what this is yet.
	/// Delta for movement.
	GLdouble m_deltaMoveLR, m_deltaMoveFB, m_deltaMoveUD;
	/// Direction of where the player is going.
	GLdouble m_direction;

	// Movement speed (step size)
	/// Speed of which the camera rotates.
	GLdouble m_rotateSpeed;
	/// Movement speed.
	GLdouble m_moveSpeed;

	// Helper function for rotation
	GLdouble degreesToRadians(GLdouble degrees);
	
	/**
	* @brief	Finds the area of a triangle between the players coordinates and points on plain
	* @param	edgeNo	- Which edge you are one. E.g., first point - q2 is 1, q2 - end point is 2 etc.
	* @param	i		- The plains that you are testing
	* @return	GLdouble - area of triangle
	*/
	GLdouble Camera::AreaPlainTriangle(int edgeNo, int i);

	/**
	* @brief	Handles W and S key movement of player
	* @param	No param
	* @return	Void
	*/
	void WSKeyboardMovement();

	/**
	* @brief	Handles A and D key movement of player
	* @param	No param
	* @return	Void
	*/
	void ADKeyboardMovement();

	/**
	* @brief	Calculates how far down the player has crouched
	* @param	No param
	* @return	Void
	*/
	void CrouchDistance();

	// overloaded function for setting plain
	void SetPlains(const int & moveX, const int & moveZ);

	// resets camera
	void ResetXYZ();
	// display new view
	void callGLLookAt();

	bool m_collisionDetectionOn;

	/// Collision object
	Collision m_colDetect;
	/// The map of the camera
	CameraMap m_map;
	/// PlainVector object
	PlainVector m_plain;

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
// 	void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
// 	void CheckSteps();

	Audio m_audio;

	//----------------------------------------------------------------------------------

    // Privatized copy constructor and assignment operator
    Camera (const Camera &cam) {};
    Camera &operator = (const Camera &cam) {};
};

#endif