//  camera.h
//  Header file for the camera class
//	Allows the camera to be navigated around the world. 
//	Also sets Plains, Bounding Boxes and view Maps
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#define PI 3.1415962654

#include "collision.h"
#include "cameraMap.h"
#include "PlainLinkedList.h"
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

	//----------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	// sets initial value for bounding boxes (in the array AABB)

	void Camera::SetAABBMaxMin(const int& tempIndex, const glm::vec3& tempMax, const glm::vec3& tempMin);
	void SetAABBMax(const int & tempIndex, const glm::vec3& tempMax);
	void SetAABBMin(const int & tempIndex, const glm::vec3& tempMin);

	// set step and rotation size
	void SetRotateSpeed (const GLdouble &tempSpeed);
	void SetMoveSpeed (const GLdouble &tempSpeed);

	// COLLSION DETECTION FUNCTIONS
	// set collision detection (TRUE = on)
	void SetCollisionDetectionOn (const bool &tempCol);
	// set number of bounding boxes
	void SetNoBoundingBoxes(const int & tempSize);
	// set the co-ordinates of the world
	void SetWorldCoordinates (const GLdouble &tempX, const GLdouble &tempZ);
	// creates a linked list for each quadrant of the world and places the bounding box
	// data in each.  Then clears and deletes AABB array.
	void InitiateBoundingBoxes();

	// sets the co-ordinate of each plain
	void SetPlains(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	GLdouble GetLR () const;
	GLdouble GetUD () const;
	GLdouble GetFB () const;	
	const glm::vec3& GetAABBMax (const int & tempIndex) const;
	const glm::vec3& GetAABBMin (const int & tempIndex) const;
	
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

	// objects
	Collision m_colDetect;
	CameraMap m_map;
	PlainLinkedList m_plain;

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