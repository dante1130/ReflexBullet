#include "LoadTexturesShaysWorld.h"
#include <thread>

TexturedPolygons tp;
unsigned char* image = nullptr;
unsigned char** imageThreading = nullptr;


void DeleteImageFromMemory()
{
	if (image != nullptr)
	{
		delete[] image;
	}
	image = nullptr;

	if (imageThreading != nullptr)
	{
		delete[] imageThreading;
	}
	imageThreading = nullptr;

}


void LoadTextures1()
{
	imageThreading[0] = tp.LoadTexture("data/abovechanctext.raw", 128, 1024);

	imageThreading[1] = tp.LoadTexture("data/abovechanctext2.raw", 128, 1024);

	imageThreading[2] = tp.LoadTexture("data/abovechanctext3.raw", 128, 1024);

	imageThreading[3] = tp.LoadTexture("data/aboveLibText.raw", 1024, 256);

	imageThreading[4] = tp.LoadTexture("data/aboveLibraryText2.raw", 1024, 256);

	imageThreading[5] = tp.LoadTexture("data/aboveUnder4B.raw", 256, 128);

	imageThreading[6] = tp.LoadTexture("data/aboveWindows.raw", 128, 256);

	imageThreading[7] = tp.LoadTexture("data/aboveWindows2.raw", 128, 256);

	imageThreading[8] = tp.LoadTexture("data/aboveWindowsChanc.raw", 128, 256);

	imageThreading[9] = tp.LoadTexture("data/aboveWindows2posts.raw", 128, 256);

	imageThreading[10] = tp.LoadTexture("data/aboveWindows2posts2.raw", 128, 256);

	imageThreading[11] = tp.LoadTexture("data/aboveWindowsLib.raw", 256, 256);

	imageThreading[12] = tp.LoadTexture("data/aboveWindows2lib.raw", 256, 128);

	imageThreading[13] = tp.LoadTexture("data/aboveWindows3bricks.raw", 256, 256);

	imageThreading[14] = tp.LoadTexture("data/abovephysscitext.raw", 256, 1024);

	imageThreading[15] = tp.LoadTexture("data/aboveWindows3bricksXY.raw", 256, 256);

	imageThreading[16] = tp.LoadTexture("data/aboveWindowEdge.raw", 128, 256);

	imageThreading[17] = tp.LoadTexture("data/aboveWindowEdgeLib.raw", 256, 64);

	imageThreading[18] = tp.LoadTexture("data/aboveWindowsLibEdge.raw", 256, 64);

	imageThreading[19] = tp.LoadTexture("data/aboveTicketsText.raw", 256, 256);

	imageThreading[20] = tp.LoadTexture("data/aboveWindowsEdge.raw", 128, 128);

	imageThreading[21] = tp.LoadTexture("data/belowrooffill.raw", 128, 256);

	imageThreading[22] = tp.LoadTexture("data/bench.raw", 64, 64);

	imageThreading[23] = tp.LoadTexture("data/benchedgeside.raw", 64, 64);

	imageThreading[24] = tp.LoadTexture("data/benchedge.raw", 64, 64);

	imageThreading[25] = tp.LoadTexture("data/benchedgetop.raw", 64, 64);

	imageThreading[26] = tp.LoadTexture("data/benchedge2.raw", 64, 64);

	imageThreading[27] = tp.LoadTexture("data/benchedge3.raw", 64, 64);

	imageThreading[28] = tp.LoadTexture("data/benchedgetop2.raw", 64, 64);

	imageThreading[29] = tp.LoadTexture("data/benchside.raw", 64, 64);

	imageThreading[30] = tp.LoadTexture("data/benchside2.raw", 64, 64);

	imageThreading[31] = tp.LoadTexture("data/bricks1.raw", 128, 128);

	imageThreading[32] = tp.LoadTexture("data/bricks2.raw", 128, 128);

	imageThreading[33] = tp.LoadTexture("data/bricks2edge.raw", 128, 128);

	imageThreading[34] = tp.LoadTexture("data/bricks1edge.raw", 128, 128);

	imageThreading[35] = tp.LoadTexture("data/bricks075.raw", 128, 128);

	imageThreading[36] = tp.LoadTexture("data/brick87.raw", 128, 128);

	imageThreading[37] = tp.LoadTexture("data/brickgap.raw", 128, 32);

	imageThreading[38] = tp.LoadTexture("data/brickgap2.raw", 128, 32);

	imageThreading[39] = tp.LoadTexture("data/bricksecsign.raw", 256, 128);

	imageThreading[40] = tp.LoadTexture("data/brickshadow.raw", 128, 128);

	imageThreading[41] = tp.LoadTexture("data/bricksUSD.raw", 128, 128);

	imageThreading[42] = tp.LoadTexture("data/carpet.raw", 32, 32);

	imageThreading[43] = tp.LoadTexture("data/coffeeMachine.raw", 128, 256);

	imageThreading[44] = tp.LoadTexture("data/cokeMachine.raw", 128, 256);

	imageThreading[45] = tp.LoadTexture("data/COsign.raw", 256, 128);

	imageThreading[46] = tp.LoadTexture("data/counterside.raw", 4, 16);

	imageThreading[47] = tp.LoadTexture("data/countertop.raw", 1, 1);

	imageThreading[48] = tp.LoadTexture("data/drainpipe.raw", 32, 2);

	imageThreading[49] = tp.LoadTexture("data/drinksEdge.raw", 16, 2);

	imageThreading[50] = tp.LoadTexture("data/drinksSide.raw", 64, 64);

	imageThreading[51] = tp.LoadTexture("data/drinksSide2.raw", 64, 64);

	imageThreading[52] = tp.LoadTexture("data/drinksSidetop.raw", 64, 64);

	imageThreading[53] = tp.LoadTexture("data/doorpave1.raw", 128, 256);

	imageThreading[54] = tp.LoadTexture("data/doorpost1.raw", 1024, 128);

	imageThreading[55] = tp.LoadTexture("data/doorpostSec.raw", 1024, 128);

	imageThreading[56] = tp.LoadTexture("data/doorpostside1.raw", 64, 1024);

	std::cout << "----Finished thread 1 (Load textures 1)" << std::endl;
}

void LoadTextures2()
{

	imageThreading[57] = tp.LoadTexture("data/doorPostLibSide.raw", 512, 64);

	imageThreading[58] = tp.LoadTexture("data/glassboard.raw", 512, 256);

	imageThreading[59] = tp.LoadTexture("data/glassboard2.raw", 512, 256);

	imageThreading[60] = tp.LoadTexture("data/glassboard3.raw", 512, 256);

	imageThreading[61] = tp.LoadTexture("data/glassboardSide.raw", 2, 16);

	imageThreading[62] = tp.LoadTexture("data/grass.raw", 64, 64);

	imageThreading[63] = tp.LoadTexture("data/grass2.raw", 64, 64);

	imageThreading[64] = tp.LoadTexture("data/grass3.raw", 64, 64);

	imageThreading[65] = tp.LoadTexture("data/GSsign.raw", 256, 256);

	imageThreading[66] = tp.LoadTexture("data/GSsign2.raw", 256, 256);
	
	imageThreading[67] = tp.LoadTexture("data/GSsignedge.raw", 256, 64);

	imageThreading[68] = tp.LoadTexture("data/kbl.raw", 512, 256);

	imageThreading[69] = tp.LoadTexture("data/KBLTside1.raw", 2, 128);

	imageThreading[70] = tp.LoadTexture("data/KBLTside2.raw", 2, 2);

	imageThreading[71] = tp.LoadTexture("data/kblCorner.raw", 1, 1);

	imageThreading[72] = tp.LoadTexture("data/kbltEdge.raw", 16, 32);

	imageThreading[73] = tp.LoadTexture("data/kbltEdge2.raw", 32, 16);

	imageThreading[74] = tp.LoadTexture("data/light.raw", 256, 64);

	imageThreading[75] = tp.LoadTexture("data/lightsupport.raw", 8, 2);

	imageThreading[76] = tp.LoadTexture("data/lightsupport2.raw", 2, 8);

	imageThreading[77] = tp.LoadTexture("data/machineSides.raw", 1, 1);

	imageThreading[78] = tp.LoadTexture("data/machineSides2.raw", 1, 1);

	imageThreading[79] = tp.LoadTexture("data/mainPost.raw", 128, 256);

	imageThreading[80] = tp.LoadTexture("data/mainPost2.raw", 256, 128);

	imageThreading[81] = tp.LoadTexture("data/map2.raw", 256, 512);

	imageThreading[82] = tp.LoadTexture("data/nexus.raw", 512, 256);

	imageThreading[83] = tp.LoadTexture("data/nexusSide.raw", 2, 16);

	imageThreading[84] = tp.LoadTexture("data/noexit.raw", 256, 64);

	imageThreading[85] = tp.LoadTexture("data/nosmokesign.raw", 256, 128);

	imageThreading[86] = tp.LoadTexture("data/pavement.raw", 128, 64);

	imageThreading[87] = tp.LoadTexture("data/pavement16.raw", 32, 64);

	imageThreading[88] = tp.LoadTexture("data/pavementflip.raw", 128, 64);

	imageThreading[89] = tp.LoadTexture("data/pavementcorner1.raw", 128, 128);

	imageThreading[90] = tp.LoadTexture("data/pavementcorner2.raw", 128, 128);

	imageThreading[91] = tp.LoadTexture("data/pavementtop.raw", 64, 128);

	imageThreading[92] = tp.LoadTexture("data/pavementtopflip.raw", 64, 128);

	imageThreading[93] = tp.LoadTexture("data/pavementSide.raw", 64, 64);

	imageThreading[94] = tp.LoadTexture("data/pavementSide2.raw", 64, 64);

	imageThreading[95] = tp.LoadTexture("data/pavementSide3.raw", 64, 64);

	imageThreading[96] = tp.LoadTexture("data/phonefront.raw", 512, 32);

	imageThreading[97] = tp.LoadTexture("data/phoneside1.raw", 32, 256);

	imageThreading[98] = tp.LoadTexture("data/phonefront2.raw", 512, 16);

	imageThreading[99] = tp.LoadTexture("data/phonemainside.raw", 512, 256);

	imageThreading[100] = tp.LoadTexture("data/phonetop1.raw", 512, 128);

	imageThreading[101] = tp.LoadTexture("data/phoneside2.raw", 16, 256);

	imageThreading[102] = tp.LoadTexture("data/phonetop2.raw", 128, 256);

	imageThreading[103] = tp.LoadTexture("data/phonebottom.raw", 512, 128);

	imageThreading[104] = tp.LoadTexture("data/phoneFill.raw", 2, 2);

	imageThreading[105] = tp.LoadTexture("data/phonefront3.raw", 16, 512);

	imageThreading[106] = tp.LoadTexture("data/PSCsign.raw", 256, 128);

	imageThreading[107] = tp.LoadTexture("data/PSCsign2.raw", 256, 128);

	imageThreading[108] = tp.LoadTexture("data/purplepost.raw", 64, 128);

	imageThreading[109] = tp.LoadTexture("data/purplepostside.raw", 128, 64);

	imageThreading[110] = tp.LoadTexture("data/redpost.raw", 64, 128);

	imageThreading[111] = tp.LoadTexture("data/redpostside.raw", 64, 64);

	imageThreading[112] = tp.LoadTexture("data/roofbeam1.raw", 128, 32);

	imageThreading[113] = tp.LoadTexture("data/roofbeam2.raw", 32, 128);

	imageThreading[114] = tp.LoadTexture("data/roofbeam3.raw", 64, 128);

	imageThreading[115] = tp.LoadTexture("data/roofbeam3top.raw", 128, 128);

	imageThreading[116] = tp.LoadTexture("data/roofbeam4.raw", 128, 64);

	imageThreading[117] = tp.LoadTexture("data/roofPlanks.raw", 128, 128);

	imageThreading[118] = tp.LoadTexture("data/roofPlanks2.raw", 128, 128);

	imageThreading[119] = tp.LoadTexture("data/rooftop.raw", 2, 128);

	imageThreading[120] = tp.LoadTexture("data/rooftoplib.raw", 128, 2);

	imageThreading[121] = tp.LoadTexture("data/rustyman.raw", 256, 1024);

	imageThreading[122] = tp.LoadTexture("data/securitysign1.raw", 128, 128);

	imageThreading[123] = tp.LoadTexture("data/securitysign2.raw", 128, 128);

	imageThreading[124] = tp.LoadTexture("data/sign1.raw", 512, 256);

	imageThreading[125] = tp.LoadTexture("data/sign1side1.raw", 16, 512);

	imageThreading[126] = tp.LoadTexture("data/sign1side2.raw", 16, 512);

	imageThreading[127] = tp.LoadTexture("data/sign2.raw", 512, 512);

	imageThreading[128] = tp.LoadTexture("data/sign2side.raw", 512, 16);

	imageThreading[129] = tp.LoadTexture("data/statravel.raw", 256, 256);

	imageThreading[130] = tp.LoadTexture("data/statraveledge.raw", 256, 64);

	imageThreading[131] = tp.LoadTexture("data/statravelbracket.raw", 16, 2);

	imageThreading[132] = tp.LoadTexture("data/statravel2.raw", 256, 256);

	imageThreading[133] = tp.LoadTexture("data/statravelbottom.raw", 2, 64);

	imageThreading[134] = tp.LoadTexture("data/stepbricks.raw", 128, 128);

	imageThreading[135] = tp.LoadTexture("data/stepbrickscover.raw", 64, 128);

	imageThreading[136] = tp.LoadTexture("data/stepbricksedge.raw", 64, 32);

	imageThreading[137] = tp.LoadTexture("data/stepbricksedge2.raw", 64, 64);

	imageThreading[138] = tp.LoadTexture("data/stepbrickstop.raw", 32, 128);

	imageThreading[139] = tp.LoadTexture("data/stepslibrary.raw", 128, 1024);

	imageThreading[140] = tp.LoadTexture("data/stepslibrarytop.raw", 256, 1024);

	imageThreading[141] = tp.LoadTexture("data/steppaving1.raw", 1024, 512);

	imageThreading[142] = tp.LoadTexture("data/steppavingedge.raw", 64, 64);

	imageThreading[143] = tp.LoadTexture("data/sweetMachine.raw", 256, 256);

	imageThreading[144] = tp.LoadTexture("data/telephoneback.raw", 512, 512);

	imageThreading[145] = tp.LoadTexture("data/ticketcounteredge2.raw", 64, 64);

	imageThreading[146] = tp.LoadTexture("data/ticketcounteredge3.raw", 64, 64);

	imageThreading[147] = tp.LoadTexture("data/ticketcountertop.raw", 128, 256);

	imageThreading[148] = tp.LoadTexture("data/ticketledgeedge.raw", 2, 32);

	imageThreading[149] = tp.LoadTexture("data/ticketledge.raw", 2, 128);

	imageThreading[150] = tp.LoadTexture("data/ticketledgeedge2.raw", 32, 2);

	imageThreading[151] = tp.LoadTexture("data/ticketcounteredge.raw", 128, 32);

	imageThreading[152] = tp.LoadTexture("data/toiletdoortop.raw", 32, 256);

	imageThreading[153] = tp.LoadTexture("data/toiletmen.raw", 128, 128);

	imageThreading[154] = tp.LoadTexture("data/toiletwomen.raw", 128, 128);

	imageThreading[155] = tp.LoadTexture("data/wallgap1.raw", 8, 128);

	imageThreading[156] = tp.LoadTexture("data/windowledge1.raw", 32, 1024);

	imageThreading[157] = tp.LoadTexture("data/windowledge2.raw", 128, 1024);

	imageThreading[158] = tp.LoadTexture("data/windowledgeend.raw", 32, 64);

	imageThreading[159] = tp.LoadTexture("data/windowledgeend2.raw", 64, 64);

	imageThreading[160] = tp.LoadTexture("data/windowledgeLibfa.raw", 1024, 32);

	imageThreading[161] = tp.LoadTexture("data/windowledgeLibfb.raw", 1024, 32);

	std::cout << "----Finished thread 2 (Load textures 2)" << std::endl;
}

void LoadTextures3()
{
	imageThreading[162] = tp.LoadTexture("data/windowledgeLibta.raw", 1024, 128);

	imageThreading[163] = tp.LoadTexture("data/windowledgeLibtb.raw", 1024, 128);

	imageThreading[164] = tp.LoadTexture("data/windowledgeUS1.raw", 32, 1024);

	imageThreading[165] = tp.LoadTexture("data/windowledgeUS2.raw", 128, 1024);

	imageThreading[166] = tp.LoadTexture("data/windowledgeUS3.raw", 128, 1024);

	imageThreading[167] = tp.LoadTexture("data/windowpost1.raw", 1024, 128);

	imageThreading[168] = tp.LoadTexture("data/windowpostsmall.raw", 512, 128);

	imageThreading[169] = tp.LoadTexture("data/windowpostsmallside2.raw", 64, 512);

	imageThreading[170] = tp.LoadTexture("data/windowpostsmallside.raw", 64, 512);

	imageThreading[171] = tp.LoadTexture("data/windowpostLib.raw", 128, 512);

	imageThreading[172] = tp.LoadTexture("data/windowpostLibside1.raw", 512, 64);

	imageThreading[173] = tp.LoadTexture("data/windowpostLibside2.raw", 512, 64);

	imageThreading[174] = tp.LoadTexture("data/windowposthalf1.raw", 64, 1024);

	imageThreading[175] = tp.LoadTexture("data/windowposthalf2.raw", 64, 1024);

	// Larger Textures

	imageThreading[176] = tp.LoadTexture("data/windows/stepwindow.raw", 128, 256);

	imageThreading[177] = tp.LoadTexture("data/windows/chancDoor1.raw", 256, 256);

	imageThreading[178] = tp.LoadTexture("data/windows/chancDoor2.raw", 256, 256);

	imageThreading[179] = tp.LoadTexture("data/windows/entrance.raw", 512, 256);

	imageThreading[180] = tp.LoadTexture("data/windows/entrance2.raw", 512, 512);

	imageThreading[181] = tp.LoadTexture("data/windows/exiteast.raw", 512, 512);

	imageThreading[182] = tp.LoadTexture("data/windows/exitwest.raw", 256, 512);

	imageThreading[183] = tp.LoadTexture("data/windows/window1.raw", 256, 256);

	imageThreading[184] = tp.LoadTexture("data/windows/window1b.raw", 256, 256);

	imageThreading[185] = tp.LoadTexture("data/windows/window2.raw", 256, 256);

	imageThreading[186] = tp.LoadTexture("data/windows/window2b.raw", 256, 256);

	imageThreading[187] = tp.LoadTexture("data/windows/window2c.raw", 256, 256);

	imageThreading[188] = tp.LoadTexture("data/windows/window2d.raw", 256, 256);

	imageThreading[189] = tp.LoadTexture("data/windows/window2e.raw", 256, 256);

	imageThreading[190] = tp.LoadTexture("data/windows/window2us.raw", 256, 256);

	imageThreading[191] = tp.LoadTexture("data/windows/window2usb.raw", 256, 256);

	imageThreading[192] = tp.LoadTexture("data/windows/window3.raw", 256, 256);

	imageThreading[193] = tp.LoadTexture("data/windows/window3b.raw", 256, 256);

	imageThreading[194] = tp.LoadTexture("data/windows/window4.raw", 128, 256);

	imageThreading[195] = tp.LoadTexture("data/windows/window5.raw", 128, 256);

	imageThreading[196] = tp.LoadTexture("data/windows/window6.raw", 256, 256);

	imageThreading[197] = tp.LoadTexture("data/windows/window7.raw", 256, 256);

	imageThreading[198] = tp.LoadTexture("data/windows/window8.raw", 256, 256);

	imageThreading[199] = tp.LoadTexture("data/windows/window9.raw", 256, 256);

	imageThreading[200] = tp.LoadTexture("data/windows/window10.raw", 256, 256);

	imageThreading[201] = tp.LoadTexture("data/windows/window11.raw", 256, 256);

	imageThreading[202] = tp.LoadTexture("data/windows/window12.raw", 256, 256);

	imageThreading[203] = tp.LoadTexture("data/windows/window13.raw", 256, 256);

	imageThreading[204] = tp.LoadTexture("data/windows/window14.raw", 256, 128);

	imageThreading[205] = tp.LoadTexture("data/windows/window14b.raw", 256, 128);

	imageThreading[206] = tp.LoadTexture("data/windows/window15.raw", 256, 256);

	imageThreading[207] = tp.LoadTexture("data/windows/window16.raw", 128, 256);

	imageThreading[208] = tp.LoadTexture("data/windows/window17.raw", 128, 256);

	imageThreading[209] = tp.LoadTexture("data/windows/windowLib1.raw", 256, 128);

	imageThreading[210] = tp.LoadTexture("data/windows/windowLib1a.raw", 256, 128);

	imageThreading[211] = tp.LoadTexture("data/windows/windowLib1b.raw", 256, 128);

	imageThreading[212] = tp.LoadTexture("data/windows/windowLib1c.raw", 256, 128);

	imageThreading[213] = tp.LoadTexture("data/windows/windowLibUSa.raw", 256, 128);

	imageThreading[214] = tp.LoadTexture("data/windows/windowLibUSb.raw", 256, 128);

	imageThreading[215] = tp.LoadTexture("data/windows/windowLibDoor1.raw", 256, 256);

	imageThreading[216] = tp.LoadTexture("data/windows/windowLibDoor2.raw", 512, 256);

	imageThreading[217] = tp.LoadTexture("data/windows/windowLibLong.raw", 256, 128);

	imageThreading[218] = tp.LoadTexture("data/map.raw", 323, 268);
	imageThreading[219] = tp.LoadTexture("data/welcome.raw", 512, 512);
	imageThreading[220] = tp.LoadTexture("data/thanks.raw", 512, 512);

	std::cout << "----Finished thread 3 (Load textures 3)" << std::endl;
}

void LoadTextures4()
{

	imageThreading[221] = tp.LoadTexture("data/ConcreteWalkway.raw", 1024, 1024);

	imageThreading[222] = tp.LoadTexture("data/WoodWalkway.raw", 1024, 1024);

	imageThreading[223] = tp.LoadTexture("data/Drain.raw", 256, 256);

	imageThreading[224] = tp.LoadTexture("data/bigTable.raw", 1536, 1024);

	imageThreading[225] = tp.LoadTexture("data/concreteWall.raw", 1024, 1024);

	imageThreading[226] = tp.LoadTexture("data/umbrella.raw", 512, 512);

	imageThreading[227] = tp.LoadTexture("data/chair.raw", 2048, 2048);

	imageThreading[228] = tp.LoadTexture("data/edgeWallBackLeft.raw", 2024, 1024);

	imageThreading[229] = tp.LoadTexture("data/edgeWallLeftDiagonal.raw", 2024, 1024);

	imageThreading[230] = tp.LoadTexture("data/edgeWallRightDiagonal.raw", 2024, 1024);

	imageThreading[231] = tp.LoadTexture("data/edgeWallBack.raw", 2024, 1024);

	imageThreading[232] = tp.LoadTexture("data/WR_Right1.raw", 1024, 512);

	imageThreading[233] = tp.LoadTexture("data/WR_Right3.raw", 1024, 512);

	imageThreading[234] = tp.LoadTexture("data/WR_Right2.raw", 1024, 512);

	imageThreading[235] = tp.LoadTexture("data/CanteenColour1.raw", 1024, 512);

	imageThreading[236] = tp.LoadTexture("data/CanteenColour2.raw", 1024, 512);

	imageThreading[237] = tp.LoadTexture("data/edgeWallRight1.raw", 2024, 1024);

	imageThreading[238] = tp.LoadTexture("data/edgeWallRight2.raw", 2024, 1024);

	imageThreading[239] = tp.LoadTexture("data/edgeWallRight3.raw", 2024, 1024);

	imageThreading[240] = tp.LoadTexture("data/object/railingText.raw", 256, 256);

	imageThreading[241] = tp.LoadTexture("data/object/environmentStairsText.raw", 2024, 2024);

	imageThreading[242] = tp.LoadTexture("data/studentHubWall.raw", 512, 512);

	imageThreading[243] = tp.LoadTexture("data/studentHubDoor.raw", 512, 512);

	imageThreading[244] = tp.LoadTexture("data/canteenWall1.raw", 512, 412);

	imageThreading[245] = tp.LoadTexture("data/canteenWall2.raw", 512, 412);

	imageThreading[246] = tp.LoadTexture("data/canteenWall3.raw", 512, 412);

	imageThreading[247] = tp.LoadTexture("data/canteenWall4.raw", 512, 412);

	imageThreading[248] = tp.LoadTexture("data/edgeCornerWall.raw", 512, 512);

	imageThreading[249] = tp.LoadTexture("data/object/bushText.raw", 512, 512);

	imageThreading[250] = tp.LoadTexture("data/hubDoorLeft.raw", 256, 512);

	imageThreading[251] = tp.LoadTexture("data/hubDoorRight.raw", 256, 400);

	imageThreading[252] = tp.LoadTexture("data/object/binText.raw", 1024, 512);

	imageThreading[253] = tp.LoadTexture("data/object/bark.raw", 512, 512);


	std::cout << "----Finished thread 4 (Load textures 4)" << std::endl;
}

void LoadTextures5()
{

	std::cout << "----Finished thread 5 (Load textures 5)" << std::endl;
}


void CreateTextures()
{
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// set texture count
	tp.SetTextureCount(TEXTURE_END);

	imageThreading = new unsigned char*[TEXTURE_END];

	std::thread LoadText1(LoadTextures1);
	std::thread LoadText2(LoadTextures2);
	std::thread LoadText3(LoadTextures3);
	std::thread LoadText4(LoadTextures4);

	image = tp.LoadTexture("data/object/tetris.raw", 2024, 2024);
	tp.CreateTexture(TEXT_ENVIRONMENT_GENERAL, image, 2024, 2024);


	LoadText1.join();
	LoadText2.join();
	LoadText3.join();
	LoadText4.join();


	// load and create textures
	tp.CreateTexture(ABOVE_CHANC_TEXT, imageThreading[0], 128, 1024);

	tp.CreateTexture(ABOVE_CHANC_TEXT_2, imageThreading[1], 128, 1024);

	tp.CreateTexture(ABOVE_CHANC_TEXT_3, imageThreading[2], 128, 1024);

	tp.CreateTexture(ABOVE_LIB_TEXT, imageThreading[3], 1024, 256);

	tp.CreateTexture(ABOVE_LIB_TEXT_2, imageThreading[4], 1024, 256);

	tp.CreateTexture(ABOVE_UNDER_4B, imageThreading[5], 256, 128);

	tp.CreateTexture(ABOVE_WINDOW_BLOCK, imageThreading[6], 128, 256);

	tp.CreateTexture(ABOVE_WINDOW_BLOCK_2, imageThreading[7], 128, 256);

	tp.CreateTexture(ABOVE_WINDOW_BLOCK_CHANC, imageThreading[8], 128, 256);

	tp.CreateTexture(ABOVE_UNDER_POSTS, imageThreading[9], 128, 256);

	tp.CreateTexture(ABOVE_UNDER_POSTS_2, imageThreading[10], 256, 128);

	tp.CreateTexture(ABOVE_LIB, imageThreading[11], 256, 256);

	tp.CreateTexture(ABOVE_WINDOW_UNDER_LIB, imageThreading[12], 256, 128);

	tp.CreateTexture(ABOVE_WINDOW_BLOCK_3, imageThreading[13], 256, 256);

	tp.CreateTexture(ABOVE_PHYS_SCI_TEXT, imageThreading[14], 256, 1024);

	tp.CreateTexture(ABOVE_WINDOW_BLOCK_XY_3, imageThreading[15], 256, 256);

	tp.CreateTexture(ABOVE_WINDOW_EDGE_3B, imageThreading[16], 128, 256);

	tp.CreateTexture(ABOVE_WINDOW_EDGE_3B_LIB, imageThreading[17], 256, 64);

	tp.CreateTexture(ABOVE_WINDOW_EDGE_4B_LIB, imageThreading[18], 256, 64);

	tp.CreateTexture(ABOVE_TICKETS_TEXT, imageThreading[19], 256, 256);

	tp.CreateTexture(ABOVE_CHANC_EDGE, imageThreading[20], 128, 128);

	tp.CreateTexture(BELOW_ROOF_FILL, imageThreading[21], 128, 256);

	tp.CreateTexture(BENCH_TOP, imageThreading[22], 64, 64);

	tp.CreateTexture(BENCH_EDGE_SIDE, imageThreading[23], 64, 64);

	tp.CreateTexture(BENCH_EDGE, imageThreading[24], 64, 64);

	tp.CreateTexture(BENCH_EDGE_TOP, imageThreading[25], 64, 64);

	tp.CreateTexture(BENCH_EDGE_2, imageThreading[26], 64, 64);

	tp.CreateTexture(BENCH_EDGE_3, imageThreading[27], 64, 64);

	tp.CreateTexture(BENCH_EDGE_TOP_2, imageThreading[28], 64, 64);

	tp.CreateTexture(BENCH_SIDE, imageThreading[29], 64, 64);

	tp.CreateTexture(BENCH_SIDE_2, imageThreading[30], 64, 64);

	tp.CreateTexture(WALL_BRICK_YZ, imageThreading[31], 128, 128);

	tp.CreateTexture(WALL_BRICK_XY, imageThreading[32], 128, 128);

	tp.CreateTexture(WALL_BRICK_XY_END, imageThreading[33], 128, 128);

	tp.CreateTexture(WALL_BRICK_YZ_END, imageThreading[34], 128, 128);

	tp.CreateTexture(WALL_BRICK_3_4, imageThreading[35], 128, 128);

	tp.CreateTexture(WALL_BRICK_XY_87WIDTH, imageThreading[36], 128, 128);

	tp.CreateTexture(WALL_BRICK_GAP_YZ, imageThreading[37], 128, 32);

	tp.CreateTexture(WALL_BRICK_GAP2_YZ, imageThreading[38], 128, 32);

	tp.CreateTexture(WALL_BRICK_SEC_SIGN, imageThreading[39], 256, 128);

	tp.CreateTexture(SHADOW_BRICK, imageThreading[40], 128, 128);

	tp.CreateTexture(WALL_BRICK_USD_YZ, imageThreading[41], 128, 128);

	tp.CreateTexture(CARPET, imageThreading[42], 32, 32);

	tp.CreateTexture(COFFEE_MACHINE, imageThreading[43], 128, 256);

	tp.CreateTexture(COKE_MACHINE, imageThreading[44], 128, 256);

	tp.CreateTexture(CO_SIGN, imageThreading[45], 256, 128);

	tp.CreateTexture(COUNTER_SIDE, imageThreading[46], 4, 16);

	tp.CreateTexture(COUNTER_TOP, imageThreading[47], 1, 1);

	tp.CreateTexture(DRAINPIPE, imageThreading[48], 32, 2);

	tp.CreateTexture(DRINKS_EDGE, imageThreading[49], 16, 2);

	tp.CreateTexture(DRINKS_SIDE, imageThreading[50], 64, 64);

	tp.CreateTexture(DRINKS_SIDE_2, imageThreading[51], 64, 64);

	tp.CreateTexture(DRINKS_TOP, imageThreading[52], 64, 64);

	tp.CreateTexture(DOORPAVE_1, imageThreading[53], 128, 256);

	tp.CreateTexture(DOOR_POST_CHANC, imageThreading[54], 1024, 128);

	tp.CreateTexture(DOOR_POST_SECURITY, imageThreading[55], 1024, 128);

	tp.CreateTexture(DOOR_SIDEPOST_CHANC, imageThreading[56], 64, 1024);

	tp.CreateTexture(DOOR_POST_LIB, imageThreading[57], 512, 64);

	tp.CreateTexture(GLASS_BOARD, imageThreading[58], 512, 256);

	tp.CreateTexture(GLASS_BOARD_2, imageThreading[59], 512, 256);

	tp.CreateTexture(GLASS_BOARD_3, imageThreading[60], 512, 256);

	tp.CreateTexture(GLASS_B_SIDE, imageThreading[61], 2, 16);

	tp.CreateTexture(GRASS, imageThreading[62], 64, 64);

	tp.CreateTexture(GRASS_2, imageThreading[63], 64, 64);

	tp.CreateTexture(GRASS_HILL, imageThreading[64], 64, 64);

	tp.CreateTexture(GS_SIGN, imageThreading[65], 256, 256);

	tp.CreateTexture(GS_SIGN_2, imageThreading[66], 256, 256);

	tp.CreateTexture(GS_SIGN_EDGE, imageThreading[67], 256, 64);

	tp.CreateTexture(KBLT, imageThreading[68], 512, 256);

	tp.CreateTexture(KBLT_SIDE_1, imageThreading[69], 2, 128);

	tp.CreateTexture(KBLT_SIDE_2, imageThreading[70], 2, 2);

	tp.CreateTexture(KBLT_EDGE_CORNER, imageThreading[71], 1, 1);

	tp.CreateTexture(KBLT_EDGE, imageThreading[72], 16, 32);

	tp.CreateTexture(KBLT_EDGE_2, imageThreading[73], 32, 16);

	tp.CreateTexture(LIGHT, imageThreading[74], 256, 64);

	tp.CreateTexture(LIGHT_SUPPORT, imageThreading[75], 8, 2);

	tp.CreateTexture(LIGHT_SUPPORT_2, imageThreading[76], 2, 8);

	tp.CreateTexture(MACHINE_SIDES, imageThreading[77], 1, 1);

	tp.CreateTexture(MACHINE_SIDES_2, imageThreading[78], 1, 1);

	tp.CreateTexture(MAIN_POST, imageThreading[79], 128, 256);

	tp.CreateTexture(MAIN_POST_2, imageThreading[80], 256, 128);

	tp.CreateTexture(MAP_2, imageThreading[81], 256, 512);

	tp.CreateTexture(NEXUS_SIGN, imageThreading[82], 512, 256);

	tp.CreateTexture(NEXUS_SIDE, imageThreading[83], 2, 16);

	tp.CreateTexture(NO_EXIT, imageThreading[84], 256, 64);

	tp.CreateTexture(NO_SMOKE_SIGN, imageThreading[85], 256, 128);

	tp.CreateTexture(PAVEMENT, imageThreading[86], 128, 64);

	tp.CreateTexture(PAVEMENT_16, imageThreading[87], 32, 64);

	tp.CreateTexture(PAVEMENT_FLIP, imageThreading[88], 128, 64);

	tp.CreateTexture(PAVEMENT_CORNER_1, imageThreading[89], 128, 128);

	tp.CreateTexture(PAVEMENT_CORNER_2, imageThreading[90], 128, 128);

	tp.CreateTexture(PAVEMENT_TOP, imageThreading[91], 64, 128);

	tp.CreateTexture(PAVEMENT_TOP_FLIP, imageThreading[92], 64, 128);

	tp.CreateTexture(PAVEMENTSIDE_LEFT, imageThreading[93], 64, 64);

	tp.CreateTexture(PAVEMENTSIDE_RIGHT, imageThreading[94], 64, 64);

	tp.CreateTexture(PAVEMENTSIDE_TOP, imageThreading[95], 64, 64);

	tp.CreateTexture(TELEPHONE_FRONT, imageThreading[96], 512, 32);

	tp.CreateTexture(TELEPHONE_SIDE_1, imageThreading[97], 32, 256);

	tp.CreateTexture(TELEPHONE_FRONT_2, imageThreading[98], 512, 16);

	tp.CreateTexture(TELEPHONE_MAIN_SIDE, imageThreading[99], 512, 256);

	tp.CreateTexture(TELEPHONE_TOP_1, imageThreading[100], 512, 128);

	tp.CreateTexture(TELEPHONE_SIDE_2, imageThreading[101], 16, 256);

	tp.CreateTexture(TELEPHONE_TOP_2, imageThreading[102], 128, 256);

	tp.CreateTexture(TELEPHONE_BOTTOM, imageThreading[103], 512, 128);

	tp.CreateTexture(TELEPHONE_FILL, imageThreading[104], 2, 2);

	tp.CreateTexture(TELEPHONE_FRONT_3, imageThreading[105], 16, 512);

	tp.CreateTexture(PSC_SIGN, imageThreading[106], 256, 128);

	tp.CreateTexture(PSC_SIGN_2, imageThreading[107], 256, 128);

	tp.CreateTexture(PURPLE_POST, imageThreading[108], 64, 128);

	tp.CreateTexture(PURPLE_POSTSIDE, imageThreading[109], 128, 64);

	tp.CreateTexture(RED_POST, imageThreading[110], 64, 128);

	tp.CreateTexture(RED_POSTSIDE, imageThreading[111], 64, 64);

	tp.CreateTexture(ROOF_BEAM_1, imageThreading[112], 128, 32);

	tp.CreateTexture(ROOF_BEAM_2, imageThreading[113], 32, 128);

	tp.CreateTexture(ROOF_BEAM_3, imageThreading[114], 64, 128);

	tp.CreateTexture(ROOF_BEAM_3_TOP, imageThreading[115], 128, 128);

	tp.CreateTexture(ROOF_BEAM_4, imageThreading[116], 128, 64);

	tp.CreateTexture(ROOF_PLANKS, imageThreading[117], 128, 128);

	tp.CreateTexture(ROOF_PLANKS_2, imageThreading[118], 128, 128);

	tp.CreateTexture(ROOF_TOP, imageThreading[119], 2, 128);

	tp.CreateTexture(ROOF_TOP_LIB, imageThreading[120], 128, 2);

	tp.CreateTexture(RUSTY_MAN, imageThreading[121], 256, 1024);

	tp.CreateTexture(SECURITY_SIGN, imageThreading[122], 128, 128);

	tp.CreateTexture(SECURITY_SIGN_2, imageThreading[123], 128, 128);

	tp.CreateTexture(SIGN_1, imageThreading[124], 512, 256);

	tp.CreateTexture(SIGN_1_SIDE_1, imageThreading[125], 16, 512);

	tp.CreateTexture(SIGN_1_SIDE_2, imageThreading[126], 16, 512);

	tp.CreateTexture(SIGN_2, imageThreading[127], 512, 512);

	tp.CreateTexture(SIGN_2_SIDE, imageThreading[128], 512, 16);

	tp.CreateTexture(STA_TRAVEL, imageThreading[129], 256, 256);

	tp.CreateTexture(STA_TRAVEL_EDGE, imageThreading[130], 256, 64);

	tp.CreateTexture(STA_TRAVEL_BRACKET, imageThreading[131], 16, 2);

	tp.CreateTexture(STA_TRAVEL_2, imageThreading[132], 256, 256);

	tp.CreateTexture(STA_TRAVEL_BOTTOM, imageThreading[133], 2, 64);

	tp.CreateTexture(WALL_BRICK_STEPS, imageThreading[134], 128, 128);

	tp.CreateTexture(WALL_BRICK_STEPS_COVER, imageThreading[135], 64, 128);

	tp.CreateTexture(WALL_BRICK_STEPS_EDGE, imageThreading[136], 64, 32);

	tp.CreateTexture(WALL_BRICK_STEPS_EDGE_2, imageThreading[137], 64, 64);

	tp.CreateTexture(WALL_BRICK_STEPS_TOP, imageThreading[138], 32, 128);

	tp.CreateTexture(STEPS_LIBRARY, imageThreading[139], 128, 1024);

	tp.CreateTexture(STEPS_LIBRARY_TOP, imageThreading[140], 256, 1024);

	tp.CreateTexture(STEP_PAVING_1, imageThreading[141], 1024, 512);

	tp.CreateTexture(STEP_EDGE, imageThreading[142], 64, 64);

	tp.CreateTexture(SWEET_MACHINE, imageThreading[143], 256, 256);

	tp.CreateTexture(TELEPHONE_BACK, imageThreading[144], 512, 512);

	tp.CreateTexture(TICKET_COUNTER_EDGE_2, imageThreading[145], 64, 64);

	tp.CreateTexture(TICKET_COUNTER_EDGE_3, imageThreading[146], 64, 64);

	tp.CreateTexture(TICKET_COUNTER_TOP, imageThreading[147], 128, 256);

	tp.CreateTexture(TICKET_LEDGE_EDGE, imageThreading[148], 2, 32);

	tp.CreateTexture(TICKET_LEDGE, imageThreading[149], 2, 128);

	tp.CreateTexture(TICKET_LEDGE_EDGE_2, imageThreading[150], 32, 2);

	tp.CreateTexture(TICKET_COUNTER_EDGE, imageThreading[151], 128, 32);

	tp.CreateTexture(TOILET_DOOR_TOP, imageThreading[152], 32, 256);

	tp.CreateTexture(TOILET_MEN, imageThreading[153], 128, 128);

	tp.CreateTexture(TOILET_WOMEN, imageThreading[154], 128, 128);

	tp.CreateTexture(WALL_GAP_1, imageThreading[155], 8, 128);

	tp.CreateTexture(WINDOWLEDGE_CHANC_FRONT, imageThreading[156], 32, 1024);

	tp.CreateTexture(WINDOWLEDGE_CHANC_TOP, imageThreading[157], 128, 1024);

	tp.CreateTexture(WINDOW_LEDGE_END_1, imageThreading[158], 32, 64);

	tp.CreateTexture(WINDOW_LEDGE_END_2, imageThreading[159], 64, 64);

	tp.CreateTexture(WINDOWLEDGE_LIB_A, imageThreading[160], 1024, 32);

	tp.CreateTexture(WINDOWLEDGE_LIB_B, imageThreading[161], 1024, 32);

	tp.CreateTexture(WINDOWLEDGE_LIB_TOP_A, imageThreading[162], 1024, 128);

	tp.CreateTexture(WINDOWLEDGE_LIB_TOP_B, imageThreading[163], 1024, 128);

	tp.CreateTexture(WINDOWLEDGE_PS_FRONT, imageThreading[164], 32, 1024);

	tp.CreateTexture(WINDOWLEDGE_PS_TOP, imageThreading[165], 128, 1024);

	tp.CreateTexture(WINDOWLEDGE_PS_BOTT, imageThreading[166], 128, 1024);

	tp.CreateTexture(WINDOWPOST_CHANC_FRONT, imageThreading[167], 1024, 128);

	tp.CreateTexture(WINDOWPOST_PHYSSCI_FRONT, imageThreading[168], 512, 128);

	tp.CreateTexture(WINDOWPOST_PHYSSCI_RIGHT, imageThreading[169], 64, 512);

	tp.CreateTexture(WINDOWPOST_PHYSSCI_LEFT, imageThreading[170], 64, 512);

	tp.CreateTexture(WINDOWPOST_LIB_FRONT, imageThreading[171], 128, 512);

	tp.CreateTexture(WINDOWPOST_LIB_LEFT, imageThreading[172], 512, 64);

	tp.CreateTexture(WINDOWPOST_LIB_RIGHT, imageThreading[173], 512, 64);

	tp.CreateTexture(WINDOWPOST_CHANC_RIGHT, imageThreading[174], 64, 1024);

	tp.CreateTexture(WINDOWPOST_CHANC_LEFT, imageThreading[175], 64, 1024);

	// Larger Textures

	tp.CreateTexture(STEP_WINDOW, imageThreading[176], 128, 256);

	tp.CreateTexture(CHANC_DOOR_1, imageThreading[177], 256, 256);

	tp.CreateTexture(CHANC_DOOR_2, imageThreading[178], 256, 256);

	tp.CreateTexture(ENTRANCE, imageThreading[179], 512, 256);

	tp.CreateTexture(ENTRANCE_2, imageThreading[180], 512, 512);

	tp.CreateTexture(EXIT_EAST, imageThreading[181], 512, 512);

	tp.CreateTexture(EXIT_WEST, imageThreading[182], 256, 512);

	tp.CreateTexture(WINDOW_1, imageThreading[183], 256, 256);

	tp.CreateTexture(WINDOW_1B, imageThreading[184], 256, 256);

	tp.CreateTexture(WINDOW_2, imageThreading[185], 256, 256);

	tp.CreateTexture(WINDOW_2B, imageThreading[186], 256, 256);

	tp.CreateTexture(WINDOW_2C, imageThreading[187], 256, 256);

	tp.CreateTexture(WINDOW_2D, imageThreading[188], 256, 256);

	tp.CreateTexture(WINDOW_2E, imageThreading[189], 256, 256);

	tp.CreateTexture(WINDOW_2US, imageThreading[190], 256, 256);

	tp.CreateTexture(WINDOW_2USB, imageThreading[191], 256, 256);

	tp.CreateTexture(WINDOW_3, imageThreading[192], 256, 256);

	tp.CreateTexture(WINDOW_3B, imageThreading[193], 256, 256);

	tp.CreateTexture(WINDOW_4, imageThreading[194], 128, 256);

	tp.CreateTexture(WINDOW_5, imageThreading[195], 128, 256);

	tp.CreateTexture(WINDOW_6, imageThreading[196], 256, 256);

	tp.CreateTexture(WINDOW_7, imageThreading[197], 256, 256);

	tp.CreateTexture(WINDOW_8, imageThreading[198], 256, 256);

	tp.CreateTexture(WINDOW_9, imageThreading[199], 256, 256);

	tp.CreateTexture(WINDOW_10, imageThreading[200], 256, 256);

	tp.CreateTexture(WINDOW_11, imageThreading[201], 256, 256);

	tp.CreateTexture(WINDOW_12, imageThreading[202], 256, 256);

	tp.CreateTexture(WINDOW_13, imageThreading[203], 256, 256);

	tp.CreateTexture(WINDOW_14, imageThreading[204], 256, 128);

	tp.CreateTexture(WINDOW_14B, imageThreading[205], 256, 128);

	tp.CreateTexture(WINDOW_15, imageThreading[206], 256, 256);

	tp.CreateTexture(WINDOW_16, imageThreading[207], 128, 256);

	tp.CreateTexture(WINDOW_17, imageThreading[208], 128, 256);

	tp.CreateTexture(WINDOW_LIB_1, imageThreading[209], 256, 128);
	
	tp.CreateTexture(WINDOW_LIB_1A, imageThreading[210], 256, 128);

	tp.CreateTexture(WINDOW_LIB_1B, imageThreading[211], 256, 128);

	tp.CreateTexture(WINDOW_LIB_1C, imageThreading[212], 256, 128);

	tp.CreateTexture(WINDOW_LIB_US_A, imageThreading[213], 256, 128);

	tp.CreateTexture(WINDOW_LIB_US_B, imageThreading[214], 256, 128);

	tp.CreateTexture(WINDOW_LIB_DOOR_1, imageThreading[215], 256, 256);

	tp.CreateTexture(WINDOW_LIB_DOOR_2, imageThreading[216], 512, 256);

	tp.CreateTexture(WINDOW_LIB_LONG, imageThreading[217], 256, 128);

	tp.CreateTexture(217, imageThreading[218], 323, 268);

	tp.CreateTexture(218, imageThreading[219], 512, 512);

	tp.CreateTexture(219, imageThreading[220], 512, 512);
	
	tp.CreateTexture(CONCRETE_WALKWAY_TEXTURE, imageThreading[221], 1024, 1024);

	tp.CreateTexture(WOOD_WALKWAY_TEXTURE, imageThreading[222], 1024, 1024);

	tp.CreateTexture(DRAIN, imageThreading[223], 256, 256);

	tp.CreateTexture(BIG_TABLE, imageThreading[224], 1536, 1024);

	tp.CreateTexture(CONCRETE_WALL, imageThreading[225], 1024, 1024);

	tp.CreateTexture(UMBRELLA, imageThreading[226], 512, 512);

	tp.CreateTexture(CHAIR, imageThreading[227], 2048, 2048);

	tp.CreateTexture(EDGE_WALL_TOILETS, imageThreading[228], 2024, 1024);

	tp.CreateTexture(EDGE_WALL_LEFT_DIAGONAL, imageThreading[229], 2024, 1024);

	tp.CreateTexture(EDGE_WALL_RIGHT_DIAGONAL, imageThreading[230], 2024, 1024);

	tp.CreateTexture(EDGE_WALL_FAR_BACK, imageThreading[231], 2024, 1024);

	tp.CreateTexture(RESTURANT_STAIRS, imageThreading[232], 1024, 512);
	
	tp.CreateTexture(RESTURANT_COLOUR_SIDE, imageThreading[233], 1024, 512);
	
	tp.CreateTexture(RESTURANT_DINNING, imageThreading[234], 1024, 512);

	tp.CreateTexture(CANTEEN_COLOUR_1, imageThreading[235], 1024, 512);

	tp.CreateTexture(CANTEEN_COLOUR_2, imageThreading[236], 1024, 512);
	
	tp.CreateTexture(EDGE_WALL_RIGHT1, imageThreading[237], 2024, 1024);

	tp.CreateTexture(EDGE_WALL_RIGHT2, imageThreading[238], 2024, 1024);

	tp.CreateTexture(EDGE_WALL_RIGHT3, imageThreading[239], 2024, 1024);

	tp.CreateTexture(TEXT_ENVIRONMENT_RAILING, imageThreading[240], 256, 256);

	tp.CreateTexture(TEXT_ENVIRONMENT_STAIRS, imageThreading[241], 2024, 2024);

	tp.CreateTexture(STUDENTHUB_WALL, imageThreading[242], 512, 512);

	tp.CreateTexture(STUDENTHUB_DOOR, imageThreading[243], 512, 512);

	tp.CreateTexture(CANTEEN_WALL1, imageThreading[244], 512, 412);

	tp.CreateTexture(CANTEEN_WALL2, imageThreading[245], 512, 412);

	tp.CreateTexture(CANTEEN_WALL3, imageThreading[246], 512, 412);

	tp.CreateTexture(CANTEEN_WALL4, imageThreading[247], 512, 412);

	tp.CreateTexture(EDGE_WALL_CLOSE_RIGHT, imageThreading[248], 512, 512);

	tp.CreateTexture(BUSH_TEXTURE, imageThreading[249], 512, 512);

	tp.CreateTexture(STUDENTHUB_DOOR_LEFT, imageThreading[250], 256, 512);

	tp.CreateTexture(STUDENTHUB_DOOR_RIGHT, imageThreading[251], 256, 400);

	tp.CreateTexture(BIN_TEXTURE, imageThreading[252], 1024, 512);

	tp.CreateTexture(TREE_TEXTURE, imageThreading[253], 512, 512);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	DeleteImageFromMemory();
}
