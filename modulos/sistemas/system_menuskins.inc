new PlayerText:Text_PlayerMenuSkin[MAX_PLAYERS][30],
	bool:show_TextPlayerMenuSkin[MAX_PLAYERS],
	bool:OlhandoMenuSkin[MAX_PLAYERS],
	Pagina[MAX_PLAYERS] = 1;

#define SKINS_PER_PAGE 18
#define MAX_SKINS 309 // Todas as skin do samp sem o cj

new skinList[MAX_SKINS] = {
    1, 2, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 
    54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68, 69, 70, 71, 72, 73, 75, 76, 77, 
    78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 120, 
    121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 
    140, 141, 142, 143, 144, 145, 146, 147, 148, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 
    179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 
    198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 209, 210, 211, 212, 213, 214, 215, 216, 217, 
    218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 
    237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 
    256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 
    275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 
    294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311
};

new currentPage[MAX_PLAYERS];

stock Create_TextPlayerMenuSkin(playerid){
	if (!show_TextPlayerMenuSkin[playerid]){
		Text_PlayerMenuSkin[playerid][0] = CreatePlayerTextDraw(playerid, 170.000, 115.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][0], 295.000, 260.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][0], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][0], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][0], 1);
		
		Text_PlayerMenuSkin[playerid][1] = CreatePlayerTextDraw(playerid, 150.300, 106.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][1], 40.000, 55.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][1], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][1], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][1], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][1], 1);
		
		Text_PlayerMenuSkin[playerid][2] = CreatePlayerTextDraw(playerid, 150.300, 329.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][2], 40.000, 55.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][2], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][2], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][2], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][2], 1);
		
		Text_PlayerMenuSkin[playerid][3] = CreatePlayerTextDraw(playerid, 447.000, 329.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][3], 40.000, 55.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][3], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][3], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][3], 1);
		
		Text_PlayerMenuSkin[playerid][4] = CreatePlayerTextDraw(playerid, 446.300, 106.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][4], 40.000, 55.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][4], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][4], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][4], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][4], 1);
		
		Text_PlayerMenuSkin[playerid][5] = CreatePlayerTextDraw(playerid, 157.000, 135.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][5], 323.000, 217.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][5], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][5], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][5], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][5], 1);
		
		Text_PlayerMenuSkin[playerid][6] = CreatePlayerTextDraw(playerid, 174.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][6], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][6], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][6], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][6], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][6], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][6], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][6], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][6], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][6], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][6], 1);
		
		Text_PlayerMenuSkin[playerid][7] = CreatePlayerTextDraw(playerid, 224.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][7], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][7], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][7], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][7], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][7], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][7], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][7], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][7], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][7], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][7], 1);
		
		Text_PlayerMenuSkin[playerid][8] = CreatePlayerTextDraw(playerid, 274.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][8], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][8], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][8], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][8], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][8], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][8], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][8], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][8], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][8], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][8], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][8], 1);
		
		Text_PlayerMenuSkin[playerid][9] = CreatePlayerTextDraw(playerid, 324.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][9], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][9], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][9], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][9], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][9], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][9], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][9], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][9], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][9], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][9], 1);
		
		Text_PlayerMenuSkin[playerid][10] = CreatePlayerTextDraw(playerid, 374.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][10], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][10], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][10], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][10], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][10], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][10], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][10], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][10], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][10], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][10], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][10], 1);
		
		Text_PlayerMenuSkin[playerid][11] = CreatePlayerTextDraw(playerid, 424.000, 150.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][11], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][11], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][11], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][11], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][11], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][11], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][11], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][11], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][11], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][11], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][11], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][11], 1);
		
		Text_PlayerMenuSkin[playerid][12] = CreatePlayerTextDraw(playerid, 174.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][12], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][12], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][12], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][12], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][12], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][12], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][12], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][12], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][12], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][12], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][12], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][12], 1);
		
		Text_PlayerMenuSkin[playerid][13] = CreatePlayerTextDraw(playerid, 224.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][13], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][13], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][13], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][13], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][13], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][13], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][13], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][13], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][13], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][13], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][13], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][13], 1);
		
		Text_PlayerMenuSkin[playerid][14] = CreatePlayerTextDraw(playerid, 274.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][14], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][14], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][14], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][14], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][14], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][14], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][14], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][14], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][14], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][14], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][14], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][14], 1);
		
		Text_PlayerMenuSkin[playerid][15] = CreatePlayerTextDraw(playerid, 324.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][15], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][15], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][15], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][15], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][15], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][15], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][15], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][15], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][15], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][15], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][15], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][15], 1);
		
		Text_PlayerMenuSkin[playerid][16] = CreatePlayerTextDraw(playerid, 374.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][16], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][16], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][16], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][16], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][16], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][16], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][16], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][16], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][16], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][16], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][16], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][16], 1);
		
		Text_PlayerMenuSkin[playerid][17] = CreatePlayerTextDraw(playerid, 424.000, 220.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][17], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][17], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][17], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][17], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][17], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][17], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][17], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][17], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][17], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][17], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][17], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][17], 1);
		
		Text_PlayerMenuSkin[playerid][18] = CreatePlayerTextDraw(playerid, 174.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][18], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][18], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][18], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][18], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][18], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][18], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][18], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][18], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][18], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][18], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][18], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][18], 1);
		
		Text_PlayerMenuSkin[playerid][19] = CreatePlayerTextDraw(playerid, 224.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][19], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][19], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][19], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][19], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][19], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][19], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][19], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][19], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][19], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][19], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][19], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][19], 1);
		
		Text_PlayerMenuSkin[playerid][20] = CreatePlayerTextDraw(playerid, 274.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][20], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][20], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][20], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][20], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][20], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][20], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][20], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][20], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][20], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][20], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][20], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][20], 1);
		
		Text_PlayerMenuSkin[playerid][21] = CreatePlayerTextDraw(playerid, 324.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][21], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][21], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][21], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][21], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][21], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][21], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][21], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][21], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][21], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][21], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][21], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][21], 1);
		
		Text_PlayerMenuSkin[playerid][22] = CreatePlayerTextDraw(playerid, 374.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][22], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][22], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][22], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][22], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][22], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][22], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][22], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][22], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][22], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][22], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][22], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][22], 1);
		
		Text_PlayerMenuSkin[playerid][23] = CreatePlayerTextDraw(playerid, 424.000, 290.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][23], 39.800, 50.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][23], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][23], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][23], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][23], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][23], 858993663);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][23], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][23], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][23], -1);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerMenuSkin[playerid][23], 0.000, 0.000, 0.000, 0.899);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerMenuSkin[playerid][23], 0, 0);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][23], 1);
		
		Text_PlayerMenuSkin[playerid][24] = CreatePlayerTextDraw(playerid, 316.000, 123.000, "MENU DE SKINS");
		PlayerTextDrawLetterSize(playerid, Text_PlayerMenuSkin[playerid][24], 0.300, 1.699);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][24], 2);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][24], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][24], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][24], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][24], 0);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][24], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][24], 1);
		
		Text_PlayerMenuSkin[playerid][25] = CreatePlayerTextDraw(playerid, 455.000, 115.000, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][25], 26.000, 35.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][25], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][25], -16776961);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][25], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][25], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][25], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][25], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][25], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][25], 1);
		
		Text_PlayerMenuSkin[playerid][26] = CreatePlayerTextDraw(playerid, 468.400, 123.000, "X");
		PlayerTextDrawLetterSize(playerid, Text_PlayerMenuSkin[playerid][26], 0.369, 1.799);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][26], 2);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][26], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][26], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][26], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][26], 0);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][26], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][26], 1);
		
		Text_PlayerMenuSkin[playerid][27] = CreatePlayerTextDraw(playerid, 360.000, 380.000, "LD_BEAT:right");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][27], 30.000, 40.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][27], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][27], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][27], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][27], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][27], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][27], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][27], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][27], 1);
		
		Text_PlayerMenuSkin[playerid][28] = CreatePlayerTextDraw(playerid, 250.000, 380.000, "LD_BEAT:left");
		PlayerTextDrawTextSize(playerid, Text_PlayerMenuSkin[playerid][28], 30.000, 40.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][28], 1);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][28], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][28], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][28], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][28], 255);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][28], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][28], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerMenuSkin[playerid][28], 1);
		
		Text_PlayerMenuSkin[playerid][29] = CreatePlayerTextDraw(playerid, 320.000, 393.000, "PAGE 0/16");
		PlayerTextDrawLetterSize(playerid, Text_PlayerMenuSkin[playerid][29], 0.300, 1.699);
		PlayerTextDrawAlignment(playerid, Text_PlayerMenuSkin[playerid][29], 2);
		PlayerTextDrawColor(playerid, Text_PlayerMenuSkin[playerid][29], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerMenuSkin[playerid][29], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerMenuSkin[playerid][29], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerMenuSkin[playerid][29], 0);
		PlayerTextDrawFont(playerid, Text_PlayerMenuSkin[playerid][29], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerMenuSkin[playerid][29], 1);
		show_TextPlayerMenuSkin[playerid] = true;
	}
	if (!OlhandoMenuSkin[playerid]){
		for(new i = 0; i < sizeof Text_PlayerMenuSkin[]; i++)PlayerTextDrawShow(playerid, Text_PlayerMenuSkin[playerid][i]);
		SelectTextDraw(playerid, 0x00000000);
		ShowSkinPreview(playerid);
		OlhandoMenuSkin[playerid] = true;
	} else {
		return false;
	}
	return true;
}

stock Destroy_PlayerMenuSala(playerid) {
    if (show_TextPlayerMenuSkin[playerid] == true) {
        for (new i = 0; i < sizeof Text_PlayerMenuSkin[]; i++) {
            PlayerTextDrawDestroy(playerid, Text_PlayerMenuSkin[playerid][i]);
            Text_PlayerMenuSkin[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    if (OlhandoMenuSkin[playerid]){
	    CancelSelectTextDraw(playerid);
	    currentPage[playerid] = 0;
	    Pagina[playerid] = 1;
	    OlhandoMenuSkin[playerid] = false;
	    show_TextPlayerMenuSkin[playerid] = false;
	}
    return true;
}

stock ShowSkinPreview(playerid) {
    new startIndex = currentPage[playerid] * SKINS_PER_PAGE;
    
    for (new i = 0, previewID = 6; i < SKINS_PER_PAGE && previewID <= 23; i++, previewID++) {
        if (startIndex + i >= MAX_SKINS) 
            break; 

        new previewModel = skinList[startIndex + i]; // Pegando a skin correta
        PlayerTextDrawSetPreviewModel(playerid, Text_PlayerMenuSkin[playerid][previewID], previewModel);
    	PlayerTextDrawShow(playerid, Text_PlayerMenuSkin[playerid][previewID]);
    }
}