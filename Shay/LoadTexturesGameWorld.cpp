#include "LoadTexturesGameWorld.h"

TexturedPolygons tpGW;
unsigned char* GWimage = nullptr;

void LTGW::DeleteImageFromMemory()
{
	if (GWimage != nullptr)
	{
		delete[] GWimage;
	}
	GWimage = nullptr;

}

void LTGW::CreateTextures()
{
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// set texture count
	tpGW.SetTextureCount(GWTEXTURE_END);


	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/ToyStore.raw", 1024, 1024);
	tpGW.CreateTexture(TOY_STORE, GWimage, 1024, 1024);


	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Books.raw", 256, 256);
	tpGW.CreateTexture(S_BOOKS, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_ToyBuilding.raw", 128, 128);
	tpGW.CreateTexture(S_TOY_BUILDING, GWimage, 128, 128);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Box_1.raw", 256, 85);
	tpGW.CreateTexture(S_BOX_1, GWimage, 256, 85);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Box_2.raw", 256, 85);
	tpGW.CreateTexture(S_BOX_2, GWimage, 256, 85);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Box_3.raw", 256, 85);
	tpGW.CreateTexture(S_BOX_3, GWimage, 256, 85);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_WoodenBlocks.raw", 128, 128);
	tpGW.CreateTexture(S_WOODEN_BLOCKS, GWimage, 128, 128);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Shelf_1.raw", 512, 512);
	tpGW.CreateTexture(SHELF_1, GWimage, 512, 512);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_StorageContainerBox_1.raw", 256, 256);
	tpGW.CreateTexture(S_STORAGE_CONTAINER_BOX, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Movies_1.raw", 256, 256);
	tpGW.CreateTexture(S_MOVIES, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Sky.raw", 512, 256);
	tpGW.CreateTexture(SKY, GWimage, 512, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/healthBar.raw", 8, 8);
	tpGW.CreateTexture(HEALTH, GWimage, 8, 8);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/wood.raw", 800, 600);
	tpGW.CreateTexture(WOOD, GWimage, 800, 600);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/mpoly.raw", 128, 96);
	tpGW.CreateTexture(S_BOARD_1, GWimage, 128, 96);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/bgammon.raw", 128, 96);
	tpGW.CreateTexture(S_BOARD_2, GWimage, 128, 96);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/pnary.raw", 128, 96);
	tpGW.CreateTexture(S_BOARD_3, GWimage, 128, 96);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/xylophone.raw", 512, 512);
	tpGW.CreateTexture(S_XYLOPHONE, GWimage, 512, 512);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/house.raw", 256, 256);
	tpGW.CreateTexture(S_HOUSE, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/bossBody.raw", 1024, 1024);
	tpGW.CreateTexture(BOSS, GWimage, 1024, 1024);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/robotDummy.raw", 512, 512);
	tpGW.CreateTexture(ROBOT, GWimage, 512, 512);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/lazer.raw", 64, 64);
	tpGW.CreateTexture(B_LAZER, GWimage, 64, 64);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/roofThing.raw", 256, 256);
	tpGW.CreateTexture(B_PIVOT, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Paused.raw", 400, 100);
	tpGW.CreateTexture(T_PAUSED, GWimage, 400, 100);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/StartScreen.raw", 400, 100);
	tpGW.CreateTexture(T_STARTSCREEN, GWimage, 400, 100);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/UpgradeMenu.raw", 400, 100);
	tpGW.CreateTexture(T_UPGRADE_MENU, GWimage, 400, 100);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Options.raw", 400, 100);
	tpGW.CreateTexture(T_OPTIONS, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Resume.raw", 400, 100);
	tpGW.CreateTexture(T_RESUME, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/RestartGame.raw", 400, 100);
	tpGW.CreateTexture(T_RESTART_GAME, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Exit.raw", 400, 100);
	tpGW.CreateTexture(T_EXIT, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/AccuracyAndTime.raw", 400, 100);
	tpGW.CreateTexture(T_ACCURACY_TIME, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/StartGame.raw", 400, 100);
	tpGW.CreateTexture(T_START_GAME, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Credits.raw", 400, 100);
	tpGW.CreateTexture(T_CREDITS, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/AttackSpeed.raw", 400, 100);
	tpGW.CreateTexture(T_ATTACK_SPEED, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/BulletSpeed.raw", 400, 100);
	tpGW.CreateTexture(T_BULLET_SPEED, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Health.raw", 400, 100);
	tpGW.CreateTexture(T_HEALTH, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/MovementSpeed.raw", 400, 100);
	tpGW.CreateTexture(T_MOVEMENT_SPEED, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/BossFight.raw", 400, 100);
	tpGW.CreateTexture(T_BOSS_FIGHT, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/CameraSensitivity.raw", 200, 100);
	tpGW.CreateTexture(T_CAMERA_SENSITIVITY, GWimage, 200, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/MusicVolume.raw", 200, 100);
	tpGW.CreateTexture(T_MUSIC_VOLUME, GWimage, 200, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/SFXVolume.raw", 200, 100);
	tpGW.CreateTexture(T_SFX_VOLUME, GWimage, 200, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Difficulty.raw", 200, 100);
	tpGW.CreateTexture(T_DIFFICULTY, GWimage, 200, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Return.raw", 400, 100);
	tpGW.CreateTexture(T_RETURN, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/MenuOutlineColour.raw", 1, 1);
	tpGW.CreateTexture(T_MENU_OUTLINE_COLOUR, GWimage, 1, 1);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Plus.raw", 100, 50);
	tpGW.CreateTexture(T_PLUS, GWimage, 100, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Minus.raw", 100, 50);
	tpGW.CreateTexture(T_MINUS, GWimage, 100, 50);
	
	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/OptionsMenu.raw", 400, 100);
	tpGW.CreateTexture(T_OPTIONS_MENU, GWimage, 400, 100);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/TrainAnimation/Train.raw", 256, 128);
	tpGW.CreateTexture(T_TRAIN, GWimage, 256, 128);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/DuckPersonAnimation/DuckPerson.raw", 128, 128);
	tpGW.CreateTexture(T_DUCK_PERSON, GWimage, 128, 128);
	
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/s_Books1.raw", 256, 256);
	tpGW.CreateTexture(S_BOOKS2, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/LightHead.raw", 1, 1);
	tpGW.CreateTexture(LIGHT_HEAD, GWimage, 1, 1);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/LightTop.raw", 1, 1);
	tpGW.CreateTexture(LIGHT_TOP, GWimage, 1, 1);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/TrainArea.raw", 256, 256);
	tpGW.CreateTexture(TRAIN_AREA, GWimage, 256, 256);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Chair1.raw", 2, 1);
	tpGW.CreateTexture(TABLE_CHAIR, GWimage, 2, 1);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Chair2.raw", 2, 1);
	tpGW.CreateTexture(TABLE_CHAIR1, GWimage, 2, 1);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Chair3.raw", 2, 1);
	tpGW.CreateTexture(TABLE_CHAIR2, GWimage, 2, 1);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Chair4.raw", 2, 1);
	tpGW.CreateTexture(TABLE_CHAIR3, GWimage, 2, 1);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Table.raw", 2, 1);
	tpGW.CreateTexture(TABLE_TABLE, GWimage, 2, 1);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Box1.raw", 200, 200);
	tpGW.CreateTexture(TABLE_BOX1, GWimage, 200, 200);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Box2.raw", 200, 200);
	tpGW.CreateTexture(TABLE_BOX2, GWimage, 200, 200);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Box3.raw", 200, 200);
	tpGW.CreateTexture(TABLE_BOX3, GWimage, 200, 200);
	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Box4.raw", 200, 200);
	tpGW.CreateTexture(TABLE_BOX4, GWimage, 200, 200);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/LightPlane.raw", 800, 600);
	tpGW.CreateTexture(LIGHT_PLANE, GWimage, 800, 600);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/Speaker.raw", 128, 128);
	tpGW.CreateTexture(SPEAKER, GWimage, 128, 128);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/ClawMachine.raw", 512, 512);
	tpGW.CreateTexture(CLAW_MACHINE, GWimage, 512, 512);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/ShelfEnd.raw", 240, 120);
	tpGW.CreateTexture(SHELF_END, GWimage, 240, 120);

	GWimage = tpGW.LoadTexture("data/object/GameObjects/GameObjectTextures/duckgun.raw", 128, 128);
	tpGW.CreateTexture(DUCK_GUN, GWimage, 128, 128);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/GameOver.raw", 400, 100);
	tpGW.CreateTexture(T_GAME_OVER, GWimage, 400, 100);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Continue.raw", 400, 50);
	tpGW.CreateTexture(T_CONTINUE, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/EnterName.raw", 400, 50);
	tpGW.CreateTexture(T_ENTER_HERE, GWimage, 400, 50);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Victory.raw", 400, 110);
	tpGW.CreateTexture(T_VICTORY, GWimage, 400, 110);

	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/Defeat.raw", 400, 170);
	tpGW.CreateTexture(T_DEFEAT, GWimage, 400, 170);


	GWimage = tpGW.LoadTexture("data/GameSeperateTextures/GameControls.raw", 641, 635);
	tpGW.CreateTexture(T_GAME_CONTROLS, GWimage, 641, 635);




	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	DeleteImageFromMemory();
}

