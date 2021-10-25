#ifndef DISPLAYGAMEWORLD_H
#define DISPLAYGAMEWORLD_H


#include <cstdio>
#include "Object.h"
#include "defines.h"
#include "Lighting.h"
#include "DisplayGameObjects.h"
#include "Player.h"
#include "Enemy.h"
#include "LoadTexturesGameWorld.h"
#include "UI.h"
#include "Leaderboards.h"
#include "BossArea.h"

#include <vector>
#include <stdlib.h>
#include <GL/glut.h>


struct ShelfObjectsOBJ
{
	std::vector<Object3D> obj;
	int texture;
};

struct AnimationOBJ
{
	std::vector<Object3D> obj;
	int texture;
	int frame;
};

struct GameWorldObjects
{
	Object3D Shelf_1;
	Object3D ToyStore[2];
	Object3D s_Box;
	Object3D s_Movies;
	Object3D s_Books;
	Object3D Sky;
	Object3D s_Board;
	Object3D cashier[2];
	Object3D TrainArea;
	Object3D LightOBJ[2];
	Object3D Table[5];
	Object3D DisplayShelf[2];
	Object3D Bench;
	Object3D LightPlane;
	Object3D ClawMachine;
	Object3D Speaker;
	Object3D ShelfEnd;
	Object3D Counter;
	Object3D DuckGun;

	std::vector<ShelfObjectsOBJ> Shelf_Objects;

	AnimationOBJ Train;
	AnimationOBJ DuckPerson;
};

struct PauseMenuValues
{
	//Pause menu
	int m_PausedMenuChoosen; //0-unpause, 1-basic pause menu, 2-options, 3-upgrade, 4-start screen, 5-credits, 6-defeat screen, 7-victory screen
	int m_OptionHighlighted;
	bool m_PausedOverStart;
	bool m_UpgradeOverPaused;

	//Leaderboard
	bool m_LeaderboardShowsAccuracyOverTime;
	GLfloat m_LeaderboardSwitchTime = 0;

	//Movement to pause menu
	bool m_floatMoving = false;
	glm::vec3 m_playerPos;
	glm::vec3 m_floatPos;
	glm::vec3 m_playerLook;
	glm::vec3 m_floatLook;
	bool m_WasCrouching = false;

	//Victory record
	Record tempRecord;

	//Controls
	bool m_ShowControls = false;

	PauseMenuValues() : m_PausedMenuChoosen{ 4 }, m_OptionHighlighted{ 0 }, m_PausedOverStart { false }, m_LeaderboardShowsAccuracyOverTime { true },
		m_LeaderboardSwitchTime{ 0 }, m_floatMoving{ false }, m_playerPos{ glm::vec3{0, 0, 0} }, m_floatPos{ glm::vec3{0, 0, 0} }, m_playerLook{ glm::vec3{0, 0, 0} },
		m_floatLook{ glm::vec3{0, 0, 0} }, m_UpgradeOverPaused { false }
	{

	}
};

extern bool wireFrame;
extern bool performanceMetric;
extern bool visibleShelves;
extern bool bossOn;
extern bool displayMap;

extern PauseMenuValues PMV;
extern GLfloat gameRunTime;
extern GLfloat lastUnpausedFrame;
extern GameWorldObjects GWO;
extern Leaderboard LB;
extern RobotEnemies robots;
extern Player player;

namespace DGW
{
	/**
	* @brief	Is the master function which handles all the displaying for the game world
	* @param	No param
	* @return	Void
	*/
	void DisplayGameWorldMasterFunction();

	/**
	* @brief	Displays the shelves around the game world
	* @param	No param
	* @return	Void
	*/
	void DisplayShelves();

	/**
	* @brief	Gets the window size
	* @param	&width		- The width of the window
	* @param	&height		- The height of the window
	* @return	Void
	*/
	void GetSize(int& width, int& height);

	/**
	* @brief	Displays boxes
	* @param	seed	- Used for randomisation
	* @param	rot		- Used for rotation
	* @return	Void
	*/
	void DisplayBoxes(int seed, int rot);

	/**
	* @brief	Displays boards
	* @param	seed	- Used for randomisation
	* @param	rot		- Used for rotation
	* @return	Void
	*/
	void DisplayBoards(int seed, int rot);
	/**
	* @brief	Displays a shalf and its contents based on an object list
	* @param	objectList	- An integer which specifies which object list to use
	* @return	Void
	*/
	void DisplayShelfContents(unsigned int objectList, int seed, glm::vec3 pos);

	/**
	* @brief	Displays a shelf and its contents based on an object list and its constraints (constraints specify when the shelf contents should be displayed)
	* @param	objectList	- An integer which specifies which object list to use
	* @param	xPos		- Position of the cutoff for the x direction
	* @param	xDirection	- specify 1 for positive x direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	zPos		- Position of the cutoff for the z direction
	* @param	zDirection	- specify 1 for positive z direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @return	Void
	*/
	void DisplayShelfContents(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed, int obj, glm::vec3 pos, int LOD);

	/**
	* @brief	Displays a shelf and its contents based on an object list and its constraints (constraints specify when the shelf contents should be displayed)
	* @param	objectList	- An integer which specifies which object list to use
	* @param	xPos		- Position of the cutoff for the x direction
	* @param	xDirection	- specify 1 for positive x direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	zPos		- Position of the cutoff for the z direction
	* @param	zDirection	- specify 1 for positive z direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	ShelfCulling- If you want to cull the shelf too or keep drawing it
	* @param	look		- The players look position
	* @param	pos			- The players position
	* @param	*cullPoints	- The points used to calculate the angle for culling
	* @return	Void
	*/
	void DisplayShelfContentsCulling(unsigned int objectList, int seed,
									 bool ShelfCulling, glm::vec3& look, glm::vec3& pos, float *cullPoints);
	/**
	* @brief	Displays a shelf and its contents based on an object list and its constraints (constraints specify when the shelf contents should be displayed)
	* @param	objectList	- An integer which specifies which object list to use
	* @param	xPos		- Position of the cutoff for the x direction
	* @param	xDirection	- specify 1 for positive x direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	zPos		- Position of the cutoff for the z direction
	* @param	zDirection	- specify 1 for positive z direction and -1 for negative (specify 0 if you don't want a cutoff or use overloaded method)
	* @param	ShelfCulling- If you want to cull the shelf too or keep drawing it
	* @param	look		- The players look position
	* @param	pos			- The players position
	* @param	*cullPoints	- The points used to calculate the angle for culling
	* @return	Void
	*/
	void DisplayShelfContentsCulling(unsigned int objectList, float xPos, int xDirection, float zPos, int zDirection, int seed,
									 bool ShelfCulling, glm::vec3 & look, glm::vec3& pos, float *cullPoints);


	/**
	* @brief	'Randomly' generates a number based on two inputs
	* @param	seed	- A variable used to for the output
	* @param	max		- The maximum number it could be
	* @param	rand	- An extra variable to change the output
	* @return	int		- The number generated
	*/
	int PsudeoNumGen(int seed, int max, int rand);

	/**
	* @brief	Displays the pause menu options
	* @param	No param
	* @return	Void
	*/
	void DisplayPauseMenuOptions();

	/**
	* @brief	Displays individual options for the pause menu
	* @param	texture		- The texture to be attached
	* @param	startPos	- The point to start the polygon
	* @param	yDrop		- The height of the option/polygon
	* @param	width		- The width you want from the polygon.
	* @return	Void
	*/
	void DisplayIndividualOption(int texture, glm::vec3 startPos, float yDrop, float width);

	/**
	* @brief	Displays the leaderboard when the game is paused
	* @param	No param
	* @return	Void
	*/
	void DisplayPauseMenuLeaderboard();

	/**
	* @brief	Displays individual leaderboard records
	* @param	yCoord		- The y coordinate of where to start displaying the record from
	* @param	recordIndex	- Which record is to be displayed
	* @param	num			- The place on the leaderboard e.g., if 1 then top of leaderboard
	* @return	Void
	*/
	void DisplayIndividualLeaderboardRecord(float yCoord, int recordIndex, int num);
	
	/**
	* @brief	Displays the upgrade menu options
	* @param	No param
	* @return	Void
	*/
	void DisplayUpgradeMenu();

	/**
	* @brief	Displays the options menu
	* @param	No param
	* @return	Void
	*/
	void DisplayOptionsMenu();

	/**
	* @brief	Displays the start screen menu
	* @param	No param
	* @return	Void
	*/
	void DisplayStartScreen();

	/**
	* @brief	Displays the credits menu
	* @param	No param
	* @return	Void
	*/
	void DisplayCredits();

	/**
	* @brief	Displays the defeat screen
	* @param	No param
	* @return	Void
	*/
	void DisplayDefeatScreen();

	/**
	* @brief	Displays the victory screen
	* @param	No param
	* @return	Void
	*/
	void DisplayVictoryScreen();

	/**
	* @brief	Displays different animations
	* @param	No param
	* @return	Void
	*/
	void DisplayAnimation();

	/**
	* @brief	Displays the cachier
	* @param	No param
	* @return	Void
	*/
	void DisplayCashier();

	/**
	* @brief	Displays the area around the train (tracks, etc.)
	* @param	No param
	* @return	Void
	*/
	void DisplayAreaHoldingTrain();

	/**
	* @brief	Displays the lights
	* @param	No param
	* @return	Void
	*/
	void DisplayLights();

	/**
	* @brief	Displays the tables
	* @param	No param
	* @return	Void
	*/
	void DisplayTables();

	/**
	* @brief	Displays the individual tables and their objects as well as determining the LOD to use
	* @param	No param
	* @return	Void
	*/
	void DisplayIndividualTable(int seed, int rand, glm::vec3 playerPos, glm::vec3 tablePos);

	/**
	* @brief	Displays the display shelves
	* @param	No param
	* @return	Void
	*/
	void DisplayDisplayShelves();

	/**
	* @brief	Displays the benches
	* @param	No param
	* @return	Void
	*/
	void DisplayBench();

	/**
	* @brief	Displays individual objects on the benche
	* @param	seed		- Used for randomness
	* @param	rand		- Used for more rnadomness
	* @param	playerPos	- The players position
	* @param	benchPos	- The benches position
	* @return	Void
	*/
	void DisplayObjectsOnBench(int seed, int rand, glm::vec3 playerPos, glm::vec3 benchPos);

	/**
	* @brief	Displays the claw machines
	* @param	No param
	* @return	Void
	*/
	void DisplayClawMachine();

	/**
	* @brief	Displays the plane holding the light
	* @param	No param
	* @return	Void
	*/
	void DisplayPlaneWithLight();

	/**
	* @brief	Displays the speakers placed around the toy store
	* @param	No param
	* @return	Void
	*/
	void DisplaySpeakers();

	/**
	* @brief	Displays the shelf ends at the back middle of the store
	* @param	No param
	* @return	Void
	*/
	void DisplayShelfEnd();

	/**
	* @brief	Displays the games current performance metrics
	* @param	No param
	* @return	Void
	*/
	void DisplayPerformanceMetrics();

	/**
	* @brief	Displays the duck gun
	* @param	No param
	* @return	Void
	*/
	void DisplayDuckGun();

	/**
	* @brief	Renders a string onto the screen for a specific font
	* @param	*font		- The font you want to use
	* @param	string		- The string you want to dispaly
	* @return	Void
	*/
	void RenderBitMapString(void* font, std::string string);

	/**
	* @brief	Displays the controls for the game
	* @param	No param
	* @return	Void
	*/
	void DisplayControls();



}

#endif