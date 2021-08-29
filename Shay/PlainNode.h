//  PlainNode.h
//  Header file for the PlainNode class
//  Stores details for each plain.  Each node is stored in each link of the Plain Linked List

//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINNODE_H
#define PLAINNODE_H

//--------------------------------------------------------------------------------------

#include <glm/vec3.hpp>
#include <gl/glut.h>

class PlainNode
{

public:
	PlainNode();
	virtual ~PlainNode();

	//----------------------------------------------------------------------------------

	void Copy(const PlainNode& newNode);
	void Clear();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------
	GLint GetType() const;
	const glm::vec3& GetStart() const;
	const glm::vec3& GetEnd() const;

    // Return the address of the link to the next node in the list
    PlainNode *GetNext () const;

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------
	void SetData(const GLint tempType, const glm::vec3& tempStart, const glm::vec3& tempEnd);

    // Set the address of the link to the next node in the list
    void SetNext (PlainNode *next);

private:
    // The address of the next node in the list
    PlainNode *m_next;

	// Stores type of plain:
	// (0: flat plane)
	// (1: incline from z to y)
	// (2: incline from x to y)
	GLint m_type;

	// stores start and end co-ordinates of plane on x, y and z axis
	glm::vec3 m_plainStart;
	glm::vec3 m_plainEnd;

	//----------------------------------------------------------------------------------

    // Privatized copy constructor and assignment operator
	PlainNode(const PlainNode& newNode);
	PlainNode& operator=(const PlainNode& newNode);
};

#endif

//--------------------------------------------------------------------------------------