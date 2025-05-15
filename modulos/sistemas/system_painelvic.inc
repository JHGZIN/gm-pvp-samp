new PlayerText:PainelVitoriaTD[MAX_PLAYERS][43],
	bool:Show_PainelVitoriaTD[MAX_PLAYERS];

stock CreatePainelVitoriaTD(playerid){
	if (!Show_PainelVitoriaTD[playerid]){		
		PainelVitoriaTD[playerid][0] = CreatePlayerTextDraw(playerid, 110.000, 150.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][0], 190.000, 35.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][0], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][0], 286331391);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][0], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][0], 1);
		
		PainelVitoriaTD[playerid][1] = CreatePlayerTextDraw(playerid, 340.000, 150.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][1], 190.000, 35.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][1], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][1], 286331391);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][1], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][1], 1);
		
		PainelVitoriaTD[playerid][2] = CreatePlayerTextDraw(playerid, 110.000, 186.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][2], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][2], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][2], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][2], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][2], 1);
		
		PainelVitoriaTD[playerid][3] = CreatePlayerTextDraw(playerid, 340.000, 186.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][3], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][3], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][3], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][3], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][3], 1);
		
		PainelVitoriaTD[playerid][4] = CreatePlayerTextDraw(playerid, 110.000, 210.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][4], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][4], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][4], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][4], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][4], 1);
		
		PainelVitoriaTD[playerid][5] = CreatePlayerTextDraw(playerid, 340.000, 210.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][5], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][5], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][5], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][5], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][5], 1);
		
		PainelVitoriaTD[playerid][6] = CreatePlayerTextDraw(playerid, 110.000, 234.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][6], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][6], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][6], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][6], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][6], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][6], 1);
		
		PainelVitoriaTD[playerid][7] = CreatePlayerTextDraw(playerid, 340.000, 234.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][7], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][7], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][7], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][7], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][7], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][7], 1);
		
		PainelVitoriaTD[playerid][8] = CreatePlayerTextDraw(playerid, 110.000, 258.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][8], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][8], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][8], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][8], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][8], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][8], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][8], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][8], 1);
		
		PainelVitoriaTD[playerid][9] = CreatePlayerTextDraw(playerid, 340.000, 258.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, PainelVitoriaTD[playerid][9], 190.000, 23.000);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][9], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][9], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][9], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][9], 4);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][9], 1);
		
		PainelVitoriaTD[playerid][10] = CreatePlayerTextDraw(playerid, 135.059, 160.000, "Jogador(a)");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][10], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][10], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][10], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][10], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][10], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][10], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][10], 1);
		
		PainelVitoriaTD[playerid][11] = CreatePlayerTextDraw(playerid, 200.059, 160.000, "Kills");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][11], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][11], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][11], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][11], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][11], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][11], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][11], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][11], 1);
		
		PainelVitoriaTD[playerid][12] = CreatePlayerTextDraw(playerid, 250.059, 160.000, "Head-Shots");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][12], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][12], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][12], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][12], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][12], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][12], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][12], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][12], 1);
		
		PainelVitoriaTD[playerid][13] = CreatePlayerTextDraw(playerid, 365.058, 160.000, "Jogador(a)");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][13], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][13], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][13], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][13], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][13], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][13], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][13], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][13], 1);
		
		PainelVitoriaTD[playerid][14] = CreatePlayerTextDraw(playerid, 430.058, 160.000, "Kills");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][14], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][14], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][14], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][14], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][14], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][14], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][14], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][14], 1);
		
		PainelVitoriaTD[playerid][15] = CreatePlayerTextDraw(playerid, 480.058, 160.000, "Head-Shots");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][15], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][15], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][15], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][15], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][15], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][15], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][15], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][15], 1);
		
		PainelVitoriaTD[playerid][16] = CreatePlayerTextDraw(playerid, 135.059, 190.000, "Pedrinho_Elmatado");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][16], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][16], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][16], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][16], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][16], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][16], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][16], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][16], 1);
		
		PainelVitoriaTD[playerid][17] = CreatePlayerTextDraw(playerid, 200.059, 190.000, "23");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][17], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][17], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][17], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][17], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][17], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][17], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][17], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][17], 1);
		
		PainelVitoriaTD[playerid][18] = CreatePlayerTextDraw(playerid, 250.059, 190.000, "20");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][18], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][18], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][18], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][18], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][18], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][18], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][18], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][18], 1);
		
		PainelVitoriaTD[playerid][19] = CreatePlayerTextDraw(playerid, 365.058, 190.000, "Jhgzin_Dev");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][19], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][19], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][19], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][19], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][19], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][19], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][19], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][19], 1);
		
		PainelVitoriaTD[playerid][20] = CreatePlayerTextDraw(playerid, 430.058, 190.000, "30");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][20], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][20], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][20], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][20], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][20], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][20], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][20], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][20], 1);
		
		PainelVitoriaTD[playerid][21] = CreatePlayerTextDraw(playerid, 480.058, 190.000, "27");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][21], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][21], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][21], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][21], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][21], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][21], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][21], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][21], 1);
		
		PainelVitoriaTD[playerid][22] = CreatePlayerTextDraw(playerid, 135.059, 213.000, "Pedrinho_Elmatado");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][22], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][22], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][22], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][22], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][22], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][22], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][22], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][22], 1);
		
		PainelVitoriaTD[playerid][23] = CreatePlayerTextDraw(playerid, 200.059, 213.000, "23");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][23], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][23], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][23], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][23], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][23], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][23], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][23], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][23], 1);
		
		PainelVitoriaTD[playerid][24] = CreatePlayerTextDraw(playerid, 250.059, 213.000, "20");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][24], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][24], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][24], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][24], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][24], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][24], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][24], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][24], 1);
		
		PainelVitoriaTD[playerid][25] = CreatePlayerTextDraw(playerid, 365.058, 213.000, "Jhgzin_Dev");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][25], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][25], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][25], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][25], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][25], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][25], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][25], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][25], 1);
		
		PainelVitoriaTD[playerid][26] = CreatePlayerTextDraw(playerid, 430.058, 213.000, "30");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][26], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][26], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][26], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][26], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][26], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][26], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][26], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][26], 1);
		
		PainelVitoriaTD[playerid][27] = CreatePlayerTextDraw(playerid, 480.058, 213.000, "27");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][27], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][27], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][27], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][27], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][27], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][27], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][27], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][27], 1);
		
		PainelVitoriaTD[playerid][28] = CreatePlayerTextDraw(playerid, 135.059, 237.000, "Pedrinho_Elmatado");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][28], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][28], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][28], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][28], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][28], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][28], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][28], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][28], 1);
		
		PainelVitoriaTD[playerid][29] = CreatePlayerTextDraw(playerid, 200.059, 237.000, "23");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][29], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][29], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][29], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][29], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][29], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][29], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][29], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][29], 1);
		
		PainelVitoriaTD[playerid][30] = CreatePlayerTextDraw(playerid, 250.059, 237.000, "20");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][30], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][30], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][30], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][30], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][30], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][30], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][30], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][30], 1);
		
		PainelVitoriaTD[playerid][31] = CreatePlayerTextDraw(playerid, 365.058, 237.000, "Jhgzin_Dev");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][31], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][31], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][31], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][31], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][31], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][31], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][31], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][31], 1);
		
		PainelVitoriaTD[playerid][32] = CreatePlayerTextDraw(playerid, 430.058, 237.000, "30");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][32], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][32], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][32], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][32], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][32], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][32], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][32], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][32], 1);
		
		PainelVitoriaTD[playerid][33] = CreatePlayerTextDraw(playerid, 480.058, 237.000, "27");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][33], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][33], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][33], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][33], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][33], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][33], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][33], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][33], 1);
		
		PainelVitoriaTD[playerid][34] = CreatePlayerTextDraw(playerid, 135.059, 261.000, "Pedrinho_Elmatado");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][34], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][34], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][34], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][34], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][34], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][34], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][34], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][34], 1);
		
		PainelVitoriaTD[playerid][35] = CreatePlayerTextDraw(playerid, 200.059, 261.000, "23");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][35], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][35], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][35], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][35], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][35], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][35], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][35], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][35], 1);
		
		PainelVitoriaTD[playerid][36] = CreatePlayerTextDraw(playerid, 250.059, 261.000, "20");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][36], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][36], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][36], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][36], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][36], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][36], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][36], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][36], 1);
		
		PainelVitoriaTD[playerid][37] = CreatePlayerTextDraw(playerid, 365.058, 261.000, "Jhgzin_Dev");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][37], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][37], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][37], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][37], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][37], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][37], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][37], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][37], 1);
		
		PainelVitoriaTD[playerid][38] = CreatePlayerTextDraw(playerid, 430.058, 261.000, "30");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][38], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][38], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][38], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][38], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][38], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][38], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][38], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][38], 1);
		
		PainelVitoriaTD[playerid][39] = CreatePlayerTextDraw(playerid, 480.058, 261.000, "27");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][39], 0.158, 1.429);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][39], 1);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][39], -1);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][39], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][39], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][39], 0);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][39], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][39], 1);
		
		PainelVitoriaTD[playerid][40] = CreatePlayerTextDraw(playerid, 319.000, 70.000, "VITORIA");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][40], 0.600, 3.398);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][40], 2);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][40], 579543807);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][40], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][40], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][40], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][40], 3);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][40], 1);
		
		PainelVitoriaTD[playerid][41] = CreatePlayerTextDraw(playerid, 259.000, 63.000, "0");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][41], 0.800, 4.798);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][41], 2);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][41], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][41], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][41], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][41], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][41], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][41], 1);
		
		PainelVitoriaTD[playerid][42] = CreatePlayerTextDraw(playerid, 383.000, 63.000, "0");
		PlayerTextDrawLetterSize(playerid, PainelVitoriaTD[playerid][42], 0.800, 4.798);
		PlayerTextDrawAlignment(playerid, PainelVitoriaTD[playerid][42], 2);
		PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][42], 8438015);
		PlayerTextDrawSetShadow(playerid, PainelVitoriaTD[playerid][42], 1);
		PlayerTextDrawSetOutline(playerid, PainelVitoriaTD[playerid][42], 1);
		PlayerTextDrawBackgroundColor(playerid, PainelVitoriaTD[playerid][42], 255);
		PlayerTextDrawFont(playerid, PainelVitoriaTD[playerid][42], 1);
		PlayerTextDrawSetProportional(playerid, PainelVitoriaTD[playerid][42], 1);
		Show_PainelVitoriaTD[playerid] = true;
	}
	for(new i = 0; i < sizeof PainelVitoriaTD[]; i++){
    	switch(i){
    		case 2..9: continue;
    		case 16..42: continue;
    	}
    	PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][i]);
	}
	return true;
}

stock DestroyTextVitoriaTD(playerid){
	if (Show_PainelVitoriaTD[playerid]){
		for(new i = 0; i < sizeof PainelVitoriaTD[]; i++){
	    	if (PainelVitoriaTD[playerid][i] != PlayerText:INVALID_TEXT_DRAW) {
				PlayerTextDrawDestroy(playerid, PainelVitoriaTD[playerid][i]);
				PainelVitoriaTD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
			}
		}
	}
	Show_PainelVitoriaTD[playerid] = false;
	return true;
}

function TempoDestroyTextVitoriaTD(playerid){
	DestroyTextVitoriaTD(playerid);
	return true;
}

CMD:finalizar(playerid){
    if (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL){
        g_SalaData[g_PlayerData[playerid][g_QualSala]][g_QtdRoudsGanhos][1] = 10;
    }
    else if (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO){
        g_SalaData[g_PlayerData[playerid][g_QualSala]][g_QtdRoudsGanhos][0] = 10;
    }
    g_SalaData[g_PlayerData[playerid][g_QualSala]][g_QtdRouds] = 11;
	return true;
}

stock CreatePainelVitoria(playerid, salaid) {
    CreatePainelVitoriaTD(playerid);

    new pontosAzul = g_SalaData[salaid][g_QtdRoudsGanhos][0];
    new pontosVermelho = g_SalaData[salaid][g_QtdRoudsGanhos][1];

    if (pontosAzul > pontosVermelho) {
        PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][40], (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL) ? "VITORIA" : "DERROTA");
        PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][40], (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL) ? 579543807 : -1962934017);
    }
    else if (pontosVermelho > pontosAzul) {
        PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][40], (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO) ? "VITORIA" : "DERROTA");
        PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][40], (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO) ? 579543807 : -1962934017);
    }
    else {
        PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][40], "EMPATE");
        PlayerTextDrawColor(playerid, PainelVitoriaTD[playerid][40], -1962934017);
    }

    // Exibe placar de pontos
    PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][41], va_return("%d", pontosAzul));
    PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][42], va_return("%d", pontosVermelho));
    PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][40]);
    PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][41]);
    PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][42]);

    // Função auxiliar para exibir os dados dos jogadores
    MostrarDadosJogadores(playerid, salaid);
    return true;
}

stock MostrarDadosJogadores(playerid, salaid) {
    new blueIndex[4] = { 16, 22, 28, 34 };
    new blueLinha[4] = { 2, 4, 6, 8 };
    
    new redIndex[4] = { 19, 25, 31, 37 };
    new redLinha[4] = { 3, 5, 7, 9 };

    for (new i = 0; i < 4; i++)
    {
        // --- TIME AZUL ---
        new blue = GetRealID(g_JogadorId[salaid][i][0]);
        if (blue != INVALID_PLAYER_ID && blue >= 0 && IsPlayerConnected(blue) && IsPlayerLogado(blue))
        {
            new baseIndex = blueIndex[i];

            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex], GetPlayerNameEx(blue));
            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex + 1], va_return("%d", g_PlayerData[blue][g_KillSala]));
            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex + 2], va_return("%d", g_PlayerData[blue][g_HeadShot]));

            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][blueLinha[i]]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex + 1]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex + 2]);
        }

        // --- TIME VERMELHO ---
        new red = GetRealID(g_JogadorId[salaid][i][1]);
        if (red != INVALID_PLAYER_ID && red >= 0 && IsPlayerConnected(red) && IsPlayerLogado(red))
        {
            new baseIndex = redIndex[i];

            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex], GetPlayerNameEx(red));
            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex + 1], va_return("%d", g_PlayerData[red][g_KillSala]));
            PlayerTextDrawSetString(playerid, PainelVitoriaTD[playerid][baseIndex + 2], va_return("%d", g_PlayerData[red][g_HeadShot]));

            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][redLinha[i]]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex + 1]);
            PlayerTextDrawShow(playerid, PainelVitoriaTD[playerid][baseIndex + 2]);
        }
    }

    if (g_PlayerData[playerid][g_TimerPainelV] != 0) KillTimer(g_PlayerData[playerid][g_TimerPainelV]);
    g_PlayerData[playerid][g_TimerPainelV] = 0;

    g_PlayerData[playerid][g_TimerPainelV] = SetTimerEx("TempoDestroyTextVitoriaTD", 10000, false, "d", playerid);
    return true;
}