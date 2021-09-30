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

	/// <summary>
	/// ////////////////////////////////////DELETE AFTER
	/// 
	/// 
	/// PLACE HOLDER TEXTURE
	/// 
	/// </summary>
	GWimage = tpGW.LoadTexture("data/object/environmentStairsText.raw", 2024, 2024);
	tpGW.CreateTexture(0, GWimage, 2024, 2024);


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

	


	

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	DeleteImageFromMemory();
}

