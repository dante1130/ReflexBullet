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
#include "../include/gl/glut.h"
#include "../include/glm/vec2.hpp"
#include "../include/glm/vec3.hpp"

//--------------------------------------------------------------------------------------

class Camera
{
public:
	/**
	 * @brief Default constructor.
	 */
	Camera();

	/**
	* @brief Handles all key movement for movement speed.
	* @return void
	*/
	void KeyboardMovement();

	/**
	 * @brief Adds a bounding box to check for collision.
	 * @param max const glm::vec3&
	 * @param min const glm::vec3&
	 * @return void
	 */
	void AddAABB(const glm::vec3& max, const glm::vec3& min);

	/**
	 * @brief Prints the x, y and z values to console, used for debugging.
	 * @return void
	 */
	void PrintPos()
	{
		std::cout << m_pos.x << " " << m_pos.y << " " << m_pos.z << std::endl;
	}
	
	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Set step and rotation size.
	 * @param tempSpeed const GLdouble&
	 * @return void
	 */
	void SetRotateSpeed(const GLdouble& tempSpeed);

	/**
	 * @brief Set movement speed.
	 * @param tempSpeed const GLdouble&
	 * @return void
	 */
	void SetMoveSpeed(const GLdouble& tempSpeed);

	// COLLISION DETECTION FUNCTIONS
	/**
	 * @brief Set collision detection (TRUE = on).
	 * @param tempCol bool
	 * @return void
	 */
	void SetCollisionDetectionOn(bool tempCol);

	/**
	 * @brief Set the co-ordinates of the world.
	 * @param tempX const GLdouble&
	 * @param tempZ const GLdouble&
	 * @return void
	 */
	void SetWorldCoordinates(const GLdouble& tempX, const GLdouble& tempZ);

	/**
	 * @brief Sets the co-ordinate of each plain.
	 * @param tempType const GLint
	 * @param tempStart const glm::vec3&
	 * @param tempEnd const glm::vec3&
	 * @return void
	 */
	void AddPlain(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

	/**
	* @brief	Used diagonal plains (only flat implemented)
	* @brief	tempType	- The type of plain implemented
	* @param	t1			- First coordinate
	* @param	t2			- Second coordinate
	* @param	t3			- Third coordinate
	* @param	t4			- Fourth coordinate
	* @return	Void
	*/
	void Camera::AddPlain(const GLint tempType, const glm::vec3& t1, const glm::vec3& t2, const glm::vec3& t3, const glm::vec3& t4);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/**
	 * @brief Returns the x position of the camera.
	 * @return GLdouble
	 */
	GLdouble GetLR () const;

	/**
	 * @brief Returns the y position of the camera.
	 * @return GLdouble
	 */
	GLdouble GetUD () const;

	/**
	 * @brief Returns the z position of the camera.
	 * @return GLdouble
	 */
	GLdouble GetFB () const;	
	
	/**
	 * @brief position the camera.
	 * @param tempPos const glm::vec3&
	 * @param tempAngle const GLdouble&
	 * @return void
	 */
	void Position(const glm::vec3& tempPos, const GLdouble& tempAngle);

	/**
	 * @brief Used to pass direction to move or rotate forwards or backwards  (i.e. 1, -1 or 0).
	 * @param tempMove const int&
	 * @return void
	 */
	void DirectionFB(const int& tempMove);

	/**
	 * @brief Used to pass direction to move or rotate left and right  (i.e. 1, -1 or 0).
	 * @param tempMove const int&
	 * @return void
	 */
	void DirectionLR(const int& tempMove);

	/**
	 * @brief Used to pass direction to move or rotate up and down  (i.e. 1, -1 or 0).
	 * @param tempMove const int&
	 * @return void
	 */
	void DirectionUD(const int& tempMove);

	/**
	 * @brief Use mouse to look around.
	 * @param x int
	 * @param y int
	 * @return void
	 */
	void MouseMove(int x, int y);

	/**
	 * @brief Display map.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param tempImage const GLuint&
	 * @return void
	 */
	void DisplayMap(const int& screenWidth, const int& screenHeight, const GLuint& tempImage);
	/**
	 * @brief Display welcome screen.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param tempExit const int&
	 * @param tempImage const GLuint&
	 * @return void
	 */
	void DisplayWelcomeScreen(const int& screenWidth, const int& screenHeight, const int& tempExit, const GLuint& tempImage);
	/**
	 * @brief Display no exit.
	 * @param screenWidth const int&
	 * @param screenHeight const int&
	 * @param tempImage const GLuint&
	 * @return void
	 */
	void DisplayNoExit(const int& screenWidth, const int& screenHeight, const GLuint& tempImage);
	
	/**
	* @brief	Sets if the player is crouching
	* @param	setCrouch	- True if crouching, false if not crouching
	* @return	Void
	*/
	void SetCrouch(bool setCrouch);

	/**
	* @brief	Sets the maximum crouch depth of the player
	* @param	max	- The Maximum distance you can crouch
	* @return	Void
	*/
	void SetMaximumCrouchDepth(float max);

	/**
	* @brief	Sets the players camera location
	* @param	x	- X coordinate
	* @param	y	- Y coordinate
	* @param	z	- Z coordiante
	* @return	Void
	*/
	void SetCameraLocation(float x, float y, float z);

private:
	/// Initialize values for first run for m_prev if true
	bool m_firstMouse;

	/// If the player is crouching or not
	bool crouch;
	/// The current crouch depth
	GLdouble crouchDepth;
	/// The maximum crouch depth
	GLdouble maxCrouchDepth;
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

	/// Check whether collision detection is on
	bool m_collisionDetectionOn;

	/// Collision object, contains the AABB to detect collision for 
	Collision m_colDetect;
	/// The map of the camera, contains the textures for the map
	CameraMap m_map;
	/// PlainVector object, contains all the plains
	PlainVector m_plain;
	/// Audio object,
	Audio m_audio;

	/**
	 * @brief Helper function for rotation, calculates radians from degrees.
	 * @param degrees GLdouble
	 * @return GLdouble
	 */
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

	/**
	 * @brief	Overloaded function for setting plain.
	 * @param	moveX const int&
	 * @param	moveZ const int&
	 * @return	Void
	 */
	void SetPlains(const int& moveX, const int& moveZ);

	/**
	 * @brief Resets the camera.
	 * return void
	 */
	void ResetXYZ();

	/**
	 * @brief Calls the glLookAt function.
	 * @return void
	 */
	void callGLLookAt();

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
	// void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
	// void CheckSteps();

	//----------------------------------------------------------------------------------
};

#endif