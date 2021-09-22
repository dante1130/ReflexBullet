#include "LoadTexturesGameWorld.h"

TexturedPolygons tpGW;
unsigned char* GWimage = nullptr;

void LTGW::DeleteImageFromMemory()
{
	GWimage = nullptr;
	if (GWimage == nullptr)
	{
		delete[] GWimage;
	}

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
	


	

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	DeleteImageFromMemory();
}

