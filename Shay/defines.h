#ifndef DEFINES_H
#define DEFINES_H

constexpr auto PI = 3.1415962654;

constexpr auto FRAMETIME = 1000 / 60;

constexpr auto CROUCH_DEPTH = -210;
constexpr auto CROUCH_SPEED = 100; //time it takes to fully crouch in milliseconds

//2 - 9874, 3 - 9745, 4 - , 5 - , 6 - , 7 - , 8 -
constexpr auto LEVEL_1_HEIGHT = 9874; 
constexpr auto LEVEL_2_HEIGHT = 9745;
constexpr auto LEVEL_3_HEIGHT = 9616;
constexpr auto LEVEL_4_HEIGHT = 9489.25;
constexpr auto LEVEL_5_HEIGHT = 9358;
constexpr auto LEVEL_6_HEIGHT = 9235;
constexpr auto LEVEL_7_HEIGHT = 9106;

constexpr auto ROW_1_START = -4622.44;
constexpr auto ROW_2_START = -5072.44;
constexpr auto ROW_3_START = -5537.44;
constexpr auto ROW_4_START = -5972.44;
constexpr auto ROW_5_START = -6381.04;
constexpr auto ROW_6_START = -6788.44;
constexpr auto ROW_7_START = -7238.44;
constexpr auto ROW_7_END = -7688.44;

// TEXTURE IMAGE AXISES
constexpr auto XY = 0;
constexpr auto XZ = 1;
constexpr auto YZ = 2;
constexpr auto YZ_FLIP = 3;
constexpr auto XY_FLIP = 4;

// PLAIN TYPES
constexpr auto FLAT_PLAIN					= 0;
constexpr auto XY_PLAIN						= 1;
constexpr auto ZY_PLAIN						= 2;
constexpr auto DIAGONAL_FLAT_PLAIN			= 3;

// TEXTURES
// Grass Textures
constexpr auto GRASS						= 1;
constexpr auto GRASS_2						= 2;
constexpr auto GRASS_HILL					= 3;
// Pavement Textures
constexpr auto PAVEMENT						= 4;
constexpr auto PAVEMENT_TOP					= 5;
constexpr auto PAVEMENTSIDE_LEFT			= 6;
constexpr auto PAVEMENTSIDE_RIGHT			= 7;
constexpr auto PAVEMENTSIDE_TOP				= 8;
constexpr auto PAVEMENT_CORNER_1			= 9;
constexpr auto PAVEMENT_CORNER_2			= 10;
constexpr auto PAVEMENT_FLIP				= 11;
constexpr auto PAVEMENT_TOP_FLIP			= 12;
constexpr auto PAVEMENT_16					= 13;
constexpr auto DOORPAVE_1					= 14;
// Wall Brick Textures
constexpr auto WALL_BRICK_YZ				= 15;
constexpr auto WALL_BRICK_XY				= 16;
constexpr auto WALL_BRICK_XY_87WIDTH		= 17;
constexpr auto WALL_BRICK_GAP_YZ			= 18;
constexpr auto WALL_BRICK_GAP2_YZ			= 19;
constexpr auto	WALL_BRICK_USD_YZ			= 20;
constexpr auto WALL_BRICK_XY_END			= 21;
constexpr auto WALL_BRICK_YZ_END			= 22;
constexpr auto	WALL_GAP_1					= 23;
constexpr auto WALL_BRICK_3_4				= 24;
constexpr auto SHADOW_BRICK					= 25;
constexpr auto WALL_BRICK_SEC_SIGN			= 216;
// Window Post Textures
constexpr auto WINDOWPOST_CHANC_FRONT		= 26;
constexpr auto WINDOWPOST_CHANC_RIGHT	   = 27;
constexpr auto WINDOWPOST_CHANC_LEFT	   = 28;
constexpr auto WINDOWLEDGE_CHANC_FRONT		= 29;
constexpr auto WINDOWLEDGE_CHANC_TOP		= 30;
constexpr auto WINDOWPOST_PHYSSCI_FRONT		= 31;
constexpr auto WINDOWPOST_PHYSSCI_RIGHT		= 32;
constexpr auto WINDOWPOST_PHYSSCI_LEFT		= 33;
constexpr auto	WINDOWPOST_LIB_FRONT		= 34;
constexpr auto	WINDOWPOST_LIB_LEFT			= 35;
constexpr auto	WINDOWPOST_LIB_RIGHT		= 36;
// Door Post Textures
constexpr auto DOOR_POST_SECURITY			= 37;
// Window Ledge Textures
constexpr auto WINDOWLEDGE_PS_FRONT			= 38;
constexpr auto WINDOWLEDGE_PS_TOP			= 39;
constexpr auto WINDOWLEDGE_PS_BOTT			= 40;
constexpr auto WINDOWLEDGE_LIB_A			= 41;
constexpr auto WINDOWLEDGE_LIB_B			= 42;
constexpr auto WINDOWLEDGE_LIB_TOP_A		= 43;
constexpr auto WINDOWLEDGE_LIB_TOP_B		= 44;
constexpr auto WINDOW_LEDGE_END_1			= 45;
constexpr auto WINDOW_LEDGE_END_2			= 46;
// Main Post Textures
constexpr auto	MAIN_POST					= 47;
constexpr auto	MAIN_POST_2					= 48;
// Door Post Textures
constexpr auto DOOR_POST_CHANC				= 49;
constexpr auto DOOR_SIDEPOST_CHANC			= 50;
constexpr auto DOOR_POST_LIB				= 215;
// Coloured Posts Textures
constexpr auto PURPLE_POST					= 51;
constexpr auto PURPLE_POSTSIDE				= 52;
constexpr auto RED_POST						= 53;
constexpr auto RED_POSTSIDE					= 54;
// Roof Textures
constexpr auto ROOF_TOP						= 55;
constexpr auto ROOF_TOP_LIB					= 56;
constexpr auto ROOF_PLANKS					= 57;
constexpr auto ROOF_BEAM_1					= 58;
constexpr auto ROOF_PLANKS_2				= 59;
constexpr auto ROOF_BEAM_2					= 60;
constexpr auto BELOW_ROOF_FILL				= 61;
constexpr auto ROOF_BEAM_3					= 62;
constexpr auto ROOF_BEAM_4					= 63;
constexpr auto ROOF_BEAM_3_TOP				= 64;
// KBLT Textures
constexpr auto KBLT							= 65;
constexpr auto KBLT_EDGE					= 66;
constexpr auto KBLT_EDGE_2					= 67;
constexpr auto KBLT_EDGE_CORNER				= 68;
constexpr auto KBLT_SIDE_1					= 69;
constexpr auto KBLT_SIDE_2					= 70;
// Sign and Other Textures
constexpr auto NEXUS_SIGN					= 71;
constexpr auto NEXUS_SIDE					= 72;
constexpr auto SECURITY_SIGN				= 73;
constexpr auto SECURITY_SIGN_2				= 74;
constexpr auto SIGN_1						= 75;
constexpr auto SIGN_1_SIDE_1				= 76;
constexpr auto SIGN_1_SIDE_2				= 77;
constexpr auto SIGN_2						= 78;
constexpr auto SIGN_2_SIDE					= 79;
constexpr auto PSC_SIGN						= 80;
constexpr auto PSC_SIGN_2					= 81;
constexpr auto CO_SIGN						= 82;
constexpr auto STA_TRAVEL					= 83;
constexpr auto STA_TRAVEL_EDGE				= 84;
constexpr auto STA_TRAVEL_BRACKET			= 85;
constexpr auto STA_TRAVEL_2					= 86;
constexpr auto STA_TRAVEL_BOTTOM			= 87;
constexpr auto TOILET_MEN					= 88;
constexpr auto TOILET_WOMEN					= 89;
constexpr auto GS_SIGN						= 90;
constexpr auto GS_SIGN_2					= 91;
constexpr auto GS_SIGN_EDGE					= 92;
constexpr auto MAP_2						= 93;
constexpr auto GLASS_BOARD					= 94;
constexpr auto GLASS_BOARD_2				= 95;
constexpr auto GLASS_BOARD_3				= 96;
constexpr auto GLASS_B_SIDE					= 97;
constexpr auto RUSTY_MAN					= 98;
constexpr auto NO_SMOKE_SIGN				= 99;
constexpr auto CARPET						= 100;
// Drinks Machine Textures
constexpr auto DRINKS_SIDE					= 101;
constexpr auto DRINKS_TOP					= 102;
constexpr auto DRINKS_EDGE					= 103;
constexpr auto DRINKS_SIDE_2				= 104;
constexpr auto COKE_MACHINE					= 105;
constexpr auto COFFEE_MACHINE				= 106;
constexpr auto SWEET_MACHINE				= 107;
constexpr auto MACHINE_SIDES				= 108;
constexpr auto MACHINE_SIDES_2				= 109;
// Telephone Box Textures
constexpr auto TELEPHONE_BACK				= 110;
constexpr auto TELEPHONE_FRONT				= 111;
constexpr auto TELEPHONE_SIDE_1				= 112;
constexpr auto TELEPHONE_FRONT_2			= 113;
constexpr auto TELEPHONE_MAIN_SIDE			= 114;
constexpr auto TELEPHONE_TOP_1				= 115;
constexpr auto TELEPHONE_SIDE_2				= 116;
constexpr auto TELEPHONE_TOP_2				= 117;
constexpr auto TELEPHONE_BOTTOM				= 118;
constexpr auto TELEPHONE_FILL				= 119;
constexpr auto TELEPHONE_FRONT_3			= 120;
// Step Textures
constexpr auto STEPS_LIBRARY				= 121;
constexpr auto STEPS_LIBRARY_TOP			= 122;
constexpr auto	STEP_PAVING_1				= 123;
constexpr auto	STEP_EDGE					= 124;

// Larger Window and Door Textures Etc
constexpr auto WINDOW_1						= 125;
constexpr auto WINDOW_2						= 126;
constexpr auto WINDOW_3						= 127;
constexpr auto WINDOW_4						= 128;
constexpr auto WINDOW_5						= 129;
constexpr auto WINDOW_6						= 130;
constexpr auto WINDOW_7						= 131;
constexpr auto WINDOW_8						= 132;
constexpr auto WINDOW_9						= 133;
constexpr auto WINDOW_10					= 134;
constexpr auto WINDOW_11					= 135;
constexpr auto WINDOW_12					= 136;
constexpr auto WINDOW_13					= 137;
constexpr auto WINDOW_14					= 138;
constexpr auto WINDOW_14B					= 139;
constexpr auto WINDOW_15					= 140;
constexpr auto WINDOW_16					= 141;
constexpr auto WINDOW_17					= 142;
constexpr auto WINDOW_2B					= 143;
constexpr auto WINDOW_2C					= 144;
constexpr auto WINDOW_2US					= 145;
constexpr auto WINDOW_3B					= 146;
constexpr auto WINDOW_2USB					= 147;
constexpr auto WINDOW_LIB_1					= 148;
constexpr auto WINDOW_LIB_1A				= 149;
constexpr auto WINDOW_LIB_1B				= 150;
constexpr auto WINDOW_LIB_1C				= 151;
constexpr auto WINDOW_LIB_US_A				= 152;
constexpr auto WINDOW_LIB_US_B				= 153;
constexpr auto WINDOW_LIB_DOOR_1			= 154;
constexpr auto WINDOW_LIB_DOOR_2			= 155;
constexpr auto WINDOW_LIB_LONG				= 156;
constexpr auto ENTRANCE						= 157;
constexpr auto ENTRANCE_2					= 158;
constexpr auto EXIT_EAST					= 159;
constexpr auto EXIT_WEST					= 220;
constexpr auto CHANC_DOOR_1					= 160;
constexpr auto CHANC_DOOR_2					= 161;
constexpr auto WINDOW_2D					= 162;
constexpr auto WINDOW_2E					= 163;
constexpr auto WINDOW_1B					= 164;
constexpr auto STEP_WINDOW					= 221;

// Above Window Block Textures
constexpr auto ABOVE_WINDOW_BLOCK			= 165;
constexpr auto ABOVE_WINDOW_BLOCK_2			= 166;
constexpr auto ABOVE_WINDOW_BLOCK_3			= 167;
constexpr auto ABOVE_WINDOW_EDGE_3B			= 168;
constexpr auto ABOVE_WINDOW_BLOCK_XY_3		= 169;
constexpr auto	ABOVE_LIB					= 170;
constexpr auto	ABOVE_UNDER_POSTS			= 171;
constexpr auto ABOVE_UNDER_POSTS_2			= 172;
constexpr auto ABOVE_WINDOW_UNDER_LIB		= 173;
constexpr auto ABOVE_WINDOW_BLOCK_CHANC		= 174;
constexpr auto ABOVE_WINDOW_EDGE_3B_LIB		= 175;
constexpr auto ABOVE_WINDOW_EDGE_4B_LIB		= 176;
constexpr auto ABOVE_UNDER_4B				= 177;
constexpr auto ABOVE_CHANC_TEXT				= 178;
constexpr auto ABOVE_CHANC_TEXT_2			= 179;
constexpr auto ABOVE_PHYS_SCI_TEXT			= 180;
constexpr auto ABOVE_CHANC_TEXT_3			= 181;
constexpr auto ABOVE_LIB_TEXT				= 182;
constexpr auto ABOVE_LIB_TEXT_2				= 183;
constexpr auto ABOVE_TICKETS_TEXT			= 184;
constexpr auto ABOVE_CHANC_EDGE				= 185;
constexpr auto TOILET_DOOR_TOP				= 186;
// Light Fitting Textures
constexpr auto LIGHT						= 187;
constexpr auto	LIGHT_SUPPORT				= 188;
constexpr auto	LIGHT_SUPPORT_2				= 189;
// Bench Textures
constexpr auto BENCH_TOP					= 190;
constexpr auto BENCH_SIDE					= 191;
constexpr auto BENCH_SIDE_2					= 192;
constexpr auto BENCH_EDGE					= 193;
constexpr auto BENCH_EDGE_TOP				= 194;
constexpr auto BENCH_EDGE_SIDE				= 195;
constexpr auto BENCH_EDGE_TOP_2				= 196;
constexpr auto BENCH_EDGE_2					= 197;
constexpr auto BENCH_EDGE_3					= 198;
// Ticket Counter and Ledge Textures
constexpr auto TICKET_COUNTER_TOP			= 200;
constexpr auto TICKET_COUNTER_EDGE			= 201;
constexpr auto TICKET_COUNTER_EDGE_2		= 202;
constexpr auto TICKET_COUNTER_EDGE_3		= 203;
constexpr auto TICKET_LEDGE					= 204;
constexpr auto TICKET_LEDGE_EDGE			= 205;
constexpr auto TICKET_LEDGE_EDGE_2			= 206;
// Wall by Steps Textures
constexpr auto WALL_BRICK_STEPS_TOP			= 207;
constexpr auto WALL_BRICK_STEPS				= 208;
constexpr auto WALL_BRICK_STEPS_COVER		= 209;
constexpr auto WALL_BRICK_STEPS_EDGE		= 210;
constexpr auto WALL_BRICK_STEPS_EDGE_2		= 211;
// Extra Textures
constexpr auto DRAINPIPE					= 212;
constexpr auto COUNTER_TOP					= 213;
constexpr auto COUNTER_SIDE					= 214;
// Welcome, Exit and Map Screens
constexpr auto MAP							= 217;
constexpr auto WELCOME						= 218;
constexpr auto EXIT							= 219;
constexpr auto NO_EXIT						= 222;

constexpr auto TEXT_ENVIRONMENT				= 223;

constexpr auto WOOD_WALKWAY_TEXTURE			= 224;
constexpr auto CONCRETE_WALKWAY_TEXTURE		= 225;
constexpr auto DRAIN						= 226;
constexpr auto SMALL_TABLE					= 227;
constexpr auto BIG_TABLE					= 228;

constexpr auto TEXTURE_END					= 230;
// 229 Next

#endif