//Variaveis das sala
new PlayerText:Text_PlayerSala[MAX_PLAYERS][24],
	bool:show_TextPlayerSala[MAX_PLAYERS],
	bool:Criandosala[MAX_PLAYERS],
	bool:show_TextPlayerKill[MAX_PLAYERS],
	PlayerText:Text_PlayerKills[MAX_PLAYERS][5],
	bool:ShowPlayerHudSala[MAX_PLAYERS],
	PlayerText:Text_PlayerHudSala[MAX_PLAYERS][10],
	PlayerText:Text_PlayerVitoria[MAX_PLAYERS][2],
	bool:showplayertextvitoria[MAX_PLAYERS],
	TimerVitoria[MAX_PLAYERS];

//Criar o textdraw de criacao da sala
stock CreatePlayerSala(playerid) {
	if (!show_TextPlayerSala[playerid]) {
		Text_PlayerSala[playerid][0] = CreatePlayerTextDraw(playerid, 195.000, 120.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][0], 245.000, 225.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][0], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][0], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][0], 1);
		
		Text_PlayerSala[playerid][1] = CreatePlayerTextDraw(playerid, 175.099, 110.500, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][1], 38.000, 58.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][1], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][1], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][1], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][1], 1);
		
		Text_PlayerSala[playerid][2] = CreatePlayerTextDraw(playerid, 422.699, 110.500, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][2], 38.000, 58.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][2], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][2], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][2], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][2], 1);
		
		Text_PlayerSala[playerid][3] = CreatePlayerTextDraw(playerid, 422.499, 296.600, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][3], 38.000, 58.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][3], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][3], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][3], 1);
		
		Text_PlayerSala[playerid][4] = CreatePlayerTextDraw(playerid, 175.099, 296.599, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][4], 38.000, 58.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][4], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][4], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][4], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][4], 1);
		
		Text_PlayerSala[playerid][5] = CreatePlayerTextDraw(playerid, 181.299, 143.499, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][5], 273.000, 177.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][5], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][5], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][5], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][5], 1);
		
		Text_PlayerSala[playerid][6] = CreatePlayerTextDraw(playerid, 317.000, 128.000, "CONFIGURACAO DE SALA DE COMBATE");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][6], 0.300, 1.500);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][6], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][6], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][6], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][6], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][6], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][6], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][6], 1);
		
		Text_PlayerSala[playerid][7] = CreatePlayerTextDraw(playerid, 200.000, 185.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][7], 85.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][7], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][7], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][7], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][7], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][7], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][7], 1);
		
		Text_PlayerSala[playerid][8] = CreatePlayerTextDraw(playerid, 242.000, 172.000, "NOME DA SALA");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][8], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][8], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][8], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][8], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][8], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][8], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][8], 1);
		
		Text_PlayerSala[playerid][9] = CreatePlayerTextDraw(playerid, 200.000, 185.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][9], 85.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][9], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][9], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][9], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][9], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][9], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][9], 1);
		
		Text_PlayerSala[playerid][10] = CreatePlayerTextDraw(playerid, 392.000, 172.000, "MODO DE COMBATE");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][10], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][10], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][10], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][10], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][10], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][10], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][10], 1);
		
		Text_PlayerSala[playerid][11] = CreatePlayerTextDraw(playerid, 350.000, 185.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][11], 85.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][11], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][11], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][11], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][11], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][11], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][11], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][11], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][11], 1);
		
		Text_PlayerSala[playerid][12] = CreatePlayerTextDraw(playerid, 200.000, 250.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][12], 85.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][12], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][12], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][12], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][12], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][12], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][12], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][12], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][12], 1);
		
		Text_PlayerSala[playerid][13] = CreatePlayerTextDraw(playerid, 242.000, 234.000, "PUBLICO OU PRIVADO");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][13], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][13], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][13], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][13], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][13], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][13], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][13], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][13], 1);
		
		Text_PlayerSala[playerid][14] = CreatePlayerTextDraw(playerid, 350.000, 250.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][14], 85.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][14], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][14], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][14], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][14], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][14], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][14], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][14], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][14], 1);
		
		Text_PlayerSala[playerid][15] = CreatePlayerTextDraw(playerid, 392.000, 234.000, "ARMAS PERMITIDAS");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][15], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][15], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][15], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][15], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][15], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][15], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][15], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][15], 1);
		
		Text_PlayerSala[playerid][16] = CreatePlayerTextDraw(playerid, 210.000, 300.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][16], 65.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][16], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][16], -16776961);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][16], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][16], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][16], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][16], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][16], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][16], 1);
		
		Text_PlayerSala[playerid][17] = CreatePlayerTextDraw(playerid, 360.000, 300.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerSala[playerid][17], 65.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][17], 1);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][17], 16711935);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][17], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][17], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][17], 255);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][17], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][17], 1);
		PlayerTextDrawSetSelectable(playerid, Text_PlayerSala[playerid][17], 1);
		
		Text_PlayerSala[playerid][18] = CreatePlayerTextDraw(playerid, 242.000, 303.799, "CANCELAR");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][18], 0.300, 1.800);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][18], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][18], 1887473919);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][18], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][18], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][18], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][18], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][18], 1);
		
		Text_PlayerSala[playerid][19] = CreatePlayerTextDraw(playerid, 392.000, 303.799, "CRIAR SALA");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][19], 0.300, 1.800);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][19], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][19], 1768516095);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][19], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][19], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][19], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][19], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][19], 1);
		
		Text_PlayerSala[playerid][20] = CreatePlayerTextDraw(playerid, 243.000, 192.000, "Toma jack");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][20], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][20], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][20], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][20], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][20], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][20], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][20], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][20], 1);
		
		Text_PlayerSala[playerid][21] = CreatePlayerTextDraw(playerid, 393.000, 192.000, "Todos contra todos");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][21], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][21], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][21], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][21], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][21], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][21], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][21], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][21], 1);
		
		Text_PlayerSala[playerid][22] = CreatePlayerTextDraw(playerid, 243.000, 256.000, "Privado");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][22], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][22], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][22], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][22], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][22], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][22], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][22], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][22], 1);
		
		Text_PlayerSala[playerid][23] = CreatePlayerTextDraw(playerid, 393.000, 256.000, "Somente Desert");
		PlayerTextDrawLetterSize(playerid, Text_PlayerSala[playerid][23], 0.200, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerSala[playerid][23], 2);
		PlayerTextDrawColor(playerid, Text_PlayerSala[playerid][23], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerSala[playerid][23], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerSala[playerid][23], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerSala[playerid][23], 0);
		PlayerTextDrawFont(playerid, Text_PlayerSala[playerid][23], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerSala[playerid][23], 1);
		show_TextPlayerSala[playerid] = true;
	}
	static str[25];
	format(str, sizeof str, "%s", g_SalaData[playerid][g_NameSala]);
	if (strlen(g_SalaData[playerid][g_NameSala]) > 0)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][20], str);
	else
		format(str, sizeof str, "Sala de %s", PlayerName(playerid)), PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][20], str);

	format(str, sizeof str, "%s", NomeArmas(g_SalaData[playerid][g_WeaponId]));
	if (g_SalaData[playerid][g_WeaponId] > 0)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
	else
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], "NENHUMA");

	if (g_SalaData[playerid][g_PasswordSala] > 0)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][22], "PRIVADO");
	else
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][22], "PUBLICO");

	if (g_SalaData[playerid][g_QualModo] == 0)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "NENHUMA");
	else if (g_SalaData[playerid][g_QualModo] == 1)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "1x1 (Duelo)");
	else if (g_SalaData[playerid][g_QualModo] == 2)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "4x4 (Times)");
	else if (g_SalaData[playerid][g_QualModo] == 2)
		PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "Todos Contra Todos (Opcional)");

	for(new i; i < sizeof Text_PlayerSala[]; i++) PlayerTextDrawShow(playerid, Text_PlayerSala[playerid][i]);
	SelectTextDraw(playerid, 0x00000000);
	return true;
}

//Destroir todos os textdraw de criacao da sala
stock Destroy_PlayerSala(playerid) {
    if (show_TextPlayerSala[playerid] == true) {
        for (new i = 0; i < sizeof Text_PlayerSala[]; i++) {
            PlayerTextDrawDestroy(playerid, Text_PlayerSala[playerid][i]);
            Text_PlayerSala[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    CancelSelectTextDraw(playerid);
    Criandosala[playerid] = false;
    show_TextPlayerSala[playerid] = false;
    return true;
}

//Criar o textdraw
stock Create_TextPlayerKill(playerid){
	if (!show_TextPlayerKill[playerid]) {
		Text_PlayerKills[playerid][0] = CreatePlayerTextDraw(playerid, 570.000, 110.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerKills[playerid][0], 46.000, 12.499);
		PlayerTextDrawAlignment(playerid, Text_PlayerKills[playerid][0], 1);
		PlayerTextDrawColor(playerid, Text_PlayerKills[playerid][0], 79);
		PlayerTextDrawSetShadow(playerid, Text_PlayerKills[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerKills[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerKills[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_PlayerKills[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerKills[playerid][0], 1);
		
		Text_PlayerKills[playerid][1] = CreatePlayerTextDraw(playerid, 569.000, 112.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerKills[playerid][1], 11.000, 10.199);
		PlayerTextDrawAlignment(playerid, Text_PlayerKills[playerid][1], 1);
		PlayerTextDrawColor(playerid, Text_PlayerKills[playerid][1], 16711935);
		PlayerTextDrawSetShadow(playerid, Text_PlayerKills[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerKills[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerKills[playerid][1], 0);
		PlayerTextDrawFont(playerid, Text_PlayerKills[playerid][1], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerKills[playerid][1], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerKills[playerid][1], 1254);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerKills[playerid][1], 0.000, 0.000, 0.000, 1.000);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerKills[playerid][1], 0, 0);
		
		Text_PlayerKills[playerid][2] = CreatePlayerTextDraw(playerid, 594.000, 112.000, "_");
		PlayerTextDrawTextSize(playerid, Text_PlayerKills[playerid][2], 11.000, 10.199);
		PlayerTextDrawAlignment(playerid, Text_PlayerKills[playerid][2], 1);
		PlayerTextDrawColor(playerid, Text_PlayerKills[playerid][2], -16776961);
		PlayerTextDrawSetShadow(playerid, Text_PlayerKills[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerKills[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerKills[playerid][2], 0);
		PlayerTextDrawFont(playerid, Text_PlayerKills[playerid][2], 5);
		PlayerTextDrawSetProportional(playerid, Text_PlayerKills[playerid][2], 0);
		PlayerTextDrawSetPreviewModel(playerid, Text_PlayerKills[playerid][2], 1254);
		PlayerTextDrawSetPreviewRot(playerid, Text_PlayerKills[playerid][2], 0.000, 0.000, 0.000, 1.000);
		PlayerTextDrawSetPreviewVehCol(playerid, Text_PlayerKills[playerid][2], 0, 0);
		
		Text_PlayerKills[playerid][3] = CreatePlayerTextDraw(playerid, 578.999, 112.799, "99+");
		PlayerTextDrawLetterSize(playerid, Text_PlayerKills[playerid][3], 0.180, 0.810);
		PlayerTextDrawTextSize(playerid, Text_PlayerKills[playerid][3], 0.000, -0.009);
		PlayerTextDrawAlignment(playerid, Text_PlayerKills[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_PlayerKills[playerid][3], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerKills[playerid][3], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerKills[playerid][3], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerKills[playerid][3], 0);
		PlayerTextDrawFont(playerid, Text_PlayerKills[playerid][3], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerKills[playerid][3], 1);
		
		Text_PlayerKills[playerid][4] = CreatePlayerTextDraw(playerid, 603.999, 112.799, "99+");
		PlayerTextDrawLetterSize(playerid, Text_PlayerKills[playerid][4], 0.180, 0.810);
		PlayerTextDrawTextSize(playerid, Text_PlayerKills[playerid][4], 0.000, -0.009);
		PlayerTextDrawAlignment(playerid, Text_PlayerKills[playerid][4], 1);
		PlayerTextDrawColor(playerid, Text_PlayerKills[playerid][4], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerKills[playerid][4], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerKills[playerid][4], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerKills[playerid][4], 0);
		PlayerTextDrawFont(playerid, Text_PlayerKills[playerid][4], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerKills[playerid][4], 1);	
		show_TextPlayerKill[playerid] = true;
	}
	for(new i; i < sizeof Text_PlayerKills[]; i++) PlayerTextDrawShow(playerid, Text_PlayerKills[playerid][i]);
	static str[11];
	if (g_PlayerData[playerid][g_Kills] < 99){
		format(str, sizeof str, "%d", g_PlayerData[playerid][g_Kills]); 
		PlayerTextDrawSetString(playerid, Text_PlayerKills[playerid][3], str);
	}
	else if (g_PlayerData[playerid][g_Kills] > 99){
		PlayerTextDrawSetString(playerid, Text_PlayerKills[playerid][3], "99+");
	}
	if (g_PlayerData[playerid][g_Mortes] < 99){
		format(str, sizeof str, "%d", g_PlayerData[playerid][g_Mortes]); 
		PlayerTextDrawSetString(playerid, Text_PlayerKills[playerid][4], str);
	}
	else if (g_PlayerData[playerid][g_Mortes] > 99){
		PlayerTextDrawSetString(playerid, Text_PlayerKills[playerid][4], "99+");
	}	
	return true;
}

//Destroir todos os textdraw 
stock Destroy_PlayerKill(playerid) {
    if (show_TextPlayerKill[playerid] == true) {
        for (new i = 0; i < sizeof Text_PlayerKills[]; i++) {
            PlayerTextDrawDestroy(playerid, Text_PlayerKills[playerid][i]);
            Text_PlayerKills[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    if (g_PlayerData[playerid][g_Kills] > 0) g_PlayerData[playerid][g_TotalKills] += g_PlayerData[playerid][g_Kills];
	g_PlayerData[playerid][g_Kills] = 0;
	g_PlayerData[playerid][g_Mortes] = 0;
    show_TextPlayerKill[playerid] = false;
    return true;
}

stock Create_TextPlayerHudSala(playerid){
	if (!ShowPlayerHudSala[playerid]){
		Text_PlayerHudSala[playerid][0] = CreatePlayerTextDraw(playerid, 253.000, 10.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHudSala[playerid][0], 45.000, 25.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][0], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][0], 170);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][0], 1);
		
		Text_PlayerHudSala[playerid][1] = CreatePlayerTextDraw(playerid, 341.000, 10.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHudSala[playerid][1], 47.000, 25.000);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][1], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][1], 170);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][1], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][1], 1);
		
		Text_PlayerHudSala[playerid][2] = CreatePlayerTextDraw(playerid, 254.000, 12.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHudSala[playerid][2], 17.399, 20.697);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][2], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][2], 137494392);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][2], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][2], 1);
		
		Text_PlayerHudSala[playerid][3] = CreatePlayerTextDraw(playerid, 369.000, 12.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHudSala[playerid][3], 17.399, 20.697);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][3], -16777096);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][3], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][3], 1);
		
		Text_PlayerHudSala[playerid][4] = CreatePlayerTextDraw(playerid, 289.000, 17.000, "TIME 1");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][4], 0.158, 1.169);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][4], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][4], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][4], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][4], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][4], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][4], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][4], 1);
		
		Text_PlayerHudSala[playerid][5] = CreatePlayerTextDraw(playerid, 352.000, 17.000, "TIME 2");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][5], 0.158, 1.169);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][5], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][5], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][5], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][5], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][5], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][5], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][5], 1);
		
		Text_PlayerHudSala[playerid][6] = CreatePlayerTextDraw(playerid, 263.100, 11.500, "0");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][6], 0.358, 2.170);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][6], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][6], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][6], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][6], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][6], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][6], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][6], 1);
		
		Text_PlayerHudSala[playerid][7] = CreatePlayerTextDraw(playerid, 378.100, 11.500, "0");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][7], 0.358, 2.170);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][7], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][7], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][7], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][7], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][7], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][7], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][7], 1);
		
		Text_PlayerHudSala[playerid][8] = CreatePlayerTextDraw(playerid, 320.000, 10.000, "00:00");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][8], 0.179, 1.299);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][8], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][8], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][8], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][8], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][8], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][8], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][8], 1);
		
		Text_PlayerHudSala[playerid][9] = CreatePlayerTextDraw(playerid, 320.000, 21.000, "RODADA 0/0");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHudSala[playerid][9], 0.179, 1.319);
		PlayerTextDrawAlignment(playerid, Text_PlayerHudSala[playerid][9], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHudSala[playerid][9], -84215126);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHudSala[playerid][9], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHudSala[playerid][9], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHudSala[playerid][9], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHudSala[playerid][9], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHudSala[playerid][9], 1);
		ShowPlayerHudSala[playerid] = true;
	}
	for(new i; i < sizeof Text_PlayerHudSala[]; i++) PlayerTextDrawShow(playerid, Text_PlayerHudSala[playerid][i]);
	return true;
}

stock Destroy_PlayerHudSala(playerid) {
    if (ShowPlayerHudSala[playerid]) {
        for (new i = 0; i < sizeof Text_PlayerHudSala[]; i++) {
        	if (IsPlayerTextDrawVisible(playerid, Text_PlayerHudSala[playerid][i])){
	            PlayerTextDrawDestroy(playerid, Text_PlayerHudSala[playerid][i]);
	            Text_PlayerHudSala[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        	}
        }
    }
    new salaid = g_PlayerData[playerid][g_QualSala];
    if (g_SalaData[salaid][g_TimerSala] != 0) KillTimer(g_SalaData[salaid][g_TimerSala]);
	g_SalaData[salaid][g_TimerSala] = 0;
    if (g_PlayerData[playerid][g_TimerVitoriaPlayerSala] != 0) KillTimer(g_PlayerData[playerid][g_TimerVitoriaPlayerSala]);
	g_PlayerData[playerid][g_TimerVitoriaPlayerSala] = 0;
    ShowPlayerHudSala[playerid] = false;
    return true;
}

function ResetPlayerSala(playerid){
	ResetPlayerWeapons(playerid);
	SetPlayerVirtualWorld(playerid, 0);
    SetPlayerInterior(playerid, 1);
    SetPlayerPos(playerid, 1643.445800, -2481.078125, 3002.085937+1);
    SetPlayerFacingAngle(playerid, 87.933044);
    SetPlayerArmour(playerid, 0);
    SetPlayerHealth(playerid, 100);
    Destroy_PlayerHudSala(playerid);

    if (g_PlayerData[playerid][g_TimerPlayerSala] != 0) KillTimer(g_PlayerData[playerid][g_TimerPlayerSala]);
    g_PlayerData[playerid][g_TimerPlayerSala] = 0;

	g_PlayerData[playerid][g_QualSala] = -1;
	g_PlayerData[playerid][g_Qualtime] = UNDFINED;
	g_PlayerData[playerid][g_Emsala] = false;

    new dummy2[pSalaData];
    g_SalaData[playerid] = dummy2;
	return true;
}

function TempoSala(salaid)
{
    if (!g_SalaData[salaid][g_SalaCriada])
        return true;

    if (g_SalaData[salaid][g_SegundosSala] > 0)
    {
        g_SalaData[salaid][g_SegundosSala]--;
        if (g_SalaData[salaid][g_SegundosSala] <= 0 && g_SalaData[salaid][g_MinutosSala] > 0)
        {
            g_SalaData[salaid][g_SegundosSala] = 59;
            g_SalaData[salaid][g_MinutosSala]--;
        }
    }

    new acabou_tempo = (g_SalaData[salaid][g_SegundosSala] <= 0 && g_SalaData[salaid][g_MinutosSala] <= 0);

    foreach (new playerid : Player)
    {
        if (g_PlayerData[playerid][g_QualSala] != salaid || !g_PlayerData[playerid][g_Emsala])
            continue;

        if (acabou_tempo)
        {
            g_SalaData[salaid][g_SegundosSala] = 1;
            g_SalaData[salaid][g_MinutosSala] = 1;
            g_SalaData[salaid][g_QtdRouds] += 1;

            if (g_SalaData[salaid][g_QtdRouds] == g_SalaData[salaid][g_MaxRouds])
            {
                KillTimer(g_SalaData[salaid][g_TimerSala]);
                g_SalaData[salaid][g_TimerSala] = 0;
               	SetPlayerForaSala(playerid);
               	return 1;
            }

            ResetPlayerWeapons(playerid);
            SetPlayerHealth(playerid, 100);
            SetPlayerArmour(playerid, 100);
            GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);

            if (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL)
            {
                SetPlayerVirtualWorld(playerid, salaid);
                SetPlayerInterior(playerid, 0);
                SetPlayerPos(playerid, 1501.739624, -1466.230224, 63.859375);
            }
            else if (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO)
            {
                SetPlayerVirtualWorld(playerid, salaid);
                SetPlayerInterior(playerid, 0);
                SetPlayerPos(playerid, 1541.481933, -1466.260253, 63.859375);
            }
            SetPlayerSkin(playerid, g_PlayerData[playerid][g_Skin]);
        }

        if (g_SalaData[salaid][g_QtdRouds] > g_SalaData[salaid][g_MaxRouds]){
        	KillTimer(g_SalaData[salaid][g_TimerSala]);
            g_SalaData[salaid][g_TimerSala] = 0;

            ResetPlayerWeapons(playerid);
            CreatePainelVitoria(playerid, salaid);
            if (g_PlayerData[playerid][g_TimerPlayerSala] != 0) KillTimer(g_PlayerData[playerid][g_TimerPlayerSala]);
            g_PlayerData[playerid][g_TimerPlayerSala] = 0;
            g_PlayerData[playerid][g_TimerPlayerSala] = SetTimerEx("ResetPlayerSala", 5000, false, "d", playerid);
        }

        PlayerTextDrawSetString(playerid, Text_PlayerHudSala[playerid][6], va_return("%d", g_SalaData[salaid][g_QtdRoudsGanhos][0]));
        PlayerTextDrawSetString(playerid, Text_PlayerHudSala[playerid][7], va_return("%d", g_SalaData[salaid][g_QtdRoudsGanhos][1]));
        PlayerTextDrawSetString(playerid, Text_PlayerHudSala[playerid][8],  va_return("%02d:%02d", g_SalaData[salaid][g_MinutosSala], g_SalaData[salaid][g_SegundosSala]));
        PlayerTextDrawSetString(playerid, Text_PlayerHudSala[playerid][9],  va_return("RODADA %d/%d", g_SalaData[salaid][g_QtdRouds], g_SalaData[salaid][g_MaxRouds]));
    }
    return true;
}

//Criar e setar a sala para o player
stock CriarPlayerSala(playerid) {
	g_SalaData[playerid][g_SalaCriada] = true;
	g_SalaData[playerid][g_QtdRoudsGanhos][0] = 0; g_SalaData[playerid][g_QtdRoudsGanhos][1] = 0;
	g_PlayerData[playerid][g_CriouSala] = true;
	SetarPlayerSala(playerid, playerid);
	SuccesMsg(playerid, "SALA CRIADA COM SUCESSO.");	
	return true;
}

stock SetPosPlayerDeath(playerid, Float:x, Float:y, Float:z, Float:a){
	g_PlayerData[playerid][PosDeath][0] = x; 
	g_PlayerData[playerid][PosDeath][1] = y;
	g_PlayerData[playerid][PosDeath][2] = z;
	g_PlayerData[playerid][PosDeath][3] = a;
	return true;
}

function SetPlayerWeapon(salaid){
	foreach(new playerid : Player){
		if (g_PlayerData[playerid][g_QualSala] == salaid){
			ResetPlayerWeapons(playerid);
			SetPlayerHealth(playerid, 100);
			SetPlayerArmour(playerid, 100);
			GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);
		}
	}
	return true;
}

//Mandar o jogador para a sala caso ele seja abatido
stock SetarPlayerSala(playerid, salaid) {
	g_PlayerData[playerid][g_QualSala] = salaid;
	g_PlayerData[playerid][g_Emsala] = true;
	g_SalaData[salaid][g_QtdPlayerSala] += 1;
	if (g_SalaData[salaid][g_QualModo] == 1){
		Create_TextPlayerHudSala(playerid);
		Escolhertimealeatorio(playerid, salaid);
	} else if (g_SalaData[salaid][g_QualModo] == 2){
		Create_TextPlayerHudSala(playerid);
		ShowPlayerDialog(playerid, D_ESCOLHERTIME, DIALOG_STYLE_MSGBOX, "Selecione seu time:", "Selecione o time que voce deseja jogar.\nE preciso os times esta completo para comecar.", "TIME 1", "TIME 2");
	} else if (g_SalaData[salaid][g_QualModo] == 3){
		
	}
	return true;
}

//Setar o jogador na sala escolhida
stock SetPlayerForaSala(playerid){
	ResetPlayerWeapons(playerid);
	SetPlayerInterior(playerid, 1);
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
	SetPlayerArmour(playerid, 0);
	SetPlayerHealth(playerid, 100);
	Destroy_PlayerHudSala(playerid);
	for (new i = 0; i < 4; i++){g_JogadorId[playerid][i][0] = 0;g_JogadorId[playerid][i][1] = 0;}
	new dummy2[pSalaData];
    g_SalaData[playerid] = dummy2;	
	return true;
}

stock Escolhertimealeatorio(playerid, salaid)
{
    new time = random(2); // 0 = azul, 1 = vermelho

    if (g_SalaData[salaid][g_QualModo] != 1)
        return true;

    // Tenta colocar no time sorteado
    if (TentarSetarNoTime(playerid, salaid, time))
    {
        // ok
    }
    else if (TentarSetarNoTime(playerid, salaid, 1 - time)) // tenta no outro time
    {
        // ok
    }

    // Se ambos os times estiverem cheios, inicia o round
    if (g_SalaData[salaid][g_JogadoresNesseTime][0] == g_SalaData[salaid][g_MaxPlayerTime][0] &&
        g_SalaData[salaid][g_JogadoresNesseTime][1] == g_SalaData[salaid][g_MaxPlayerTime][1])
    {
        g_SalaData[salaid][g_MinutosSala] = 0;
        g_SalaData[salaid][g_SegundosSala] = 59;

        if (g_SalaData[salaid][g_TimerSala] != 0)
            KillTimer(g_SalaData[salaid][g_TimerSala]);

        g_SalaData[salaid][g_TimerSala] = SetTimerEx("TempoSala", 1000, true, "d", salaid);
        SetTimerEx("SetPlayerWeapon", 100, false, "d", salaid);
    }
    return true;
}

stock TentarSetarNoTime(playerid, salaid, time)
{
    if (g_SalaData[salaid][g_JogadoresNesseTime][time] >= g_SalaData[salaid][g_MaxPlayerTime][time])
        return false;

    g_SalaData[salaid][g_JogadoresNesseTime][time]++;
    g_PlayerData[playerid][g_Qualtime] = (time == 0) ? TIMEAZUL : TIMEVERMELHO;
    SavePlayerIdPainelVic(playerid, salaid, time);
    SetPlayerVirtualWorld(playerid, salaid);
    SetPlayerInterior(playerid, 0);

    if (time == 0) {
        SetPlayerPos(playerid, 1501.739624, -1466.230224, 63.859375);
        SetPosPlayerDeath(playerid, 1501.739624, -1466.230224, 63.859375, 273.975128);
        SendClientMessage(playerid, -1, "Voce foi setado no time 1");
    }
    else {
        SetPlayerPos(playerid, 1541.481933, -1466.260253, 63.859375);
        SetPosPlayerDeath(playerid, 1541.481933, -1466.260253, 63.859375, 84.488395);
        SendClientMessage(playerid, -1, "Voce foi setado no time 2");
    }
    return true;
}

stock SavePlayerIdPainelVic(playerid, salaid, time){
    if (time == 0) {
    	if (g_SalaData[salaid][g_QualModo] == 1){
        	g_JogadorId[salaid][0][0] = g_PlayerData[playerid][g_AccId];
    	} 
    	if (g_SalaData[playerid][g_QualModo] == 2){
        	if (g_JogadorId[salaid][0][0] != 0){
        		g_JogadorId[salaid][0][0] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][1][0] != 0){
        		g_JogadorId[salaid][1][0] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][2][0] != 0){
        		g_JogadorId[salaid][2][0] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][3][0] != 0){
        		g_JogadorId[salaid][3][0] = g_PlayerData[playerid][g_AccId];
        	}
    	}
    }
    else {
    	if (g_SalaData[salaid][g_QualModo] == 1){
    		g_JogadorId[salaid][0][1] = g_PlayerData[playerid][g_AccId];
    	}
    	if (g_SalaData[salaid][g_QualModo] == 2){
        	if (g_JogadorId[salaid][0][1] != 0){
        		g_JogadorId[salaid][0][1] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][1][1] != 0){
        		g_JogadorId[salaid][1][1] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][2][1] != 0){
        		g_JogadorId[salaid][2][1] = g_PlayerData[playerid][g_AccId];
        	}
        	if (g_JogadorId[salaid][3][1] != 0){
        		g_JogadorId[salaid][3][1] = g_PlayerData[playerid][g_AccId];
        	}
    	}
    }
	return true;
}

stock EscolherTime(playerid, salaid, time)
{
    if (g_SalaData[salaid][g_QualModo] != 1)
        return true;

    // Tenta colocar no time sorteado
    if (TentarSetarTime(playerid, salaid, time))
    {
        // ok
    }
    else if (TentarSetarTime(playerid, salaid, 1 - time)) // tenta no outro time
    {
        // ok
    }

    // Se ambos os times estiverem cheios, inicia o round
    if (g_SalaData[salaid][g_JogadoresNesseTime][0] == g_SalaData[salaid][g_MaxPlayerTime][0] &&
        g_SalaData[salaid][g_JogadoresNesseTime][1] == g_SalaData[salaid][g_MaxPlayerTime][1])
    {
        g_SalaData[salaid][g_MinutosSala] = 1;
        g_SalaData[salaid][g_SegundosSala] = 59;

        if (g_SalaData[salaid][g_TimerSala] != 0)
            KillTimer(g_SalaData[salaid][g_TimerSala]);

        g_SalaData[salaid][g_TimerSala] = SetTimerEx("TempoSala", 1000, true, "d", salaid);
        SetTimerEx("SetPlayerWeapon", 100, false, "d", salaid);
    }
    return true;
}

stock TentarSetarTime(playerid, salaid, time){
    if (g_SalaData[salaid][g_JogadoresNesseTime][time] >= g_SalaData[salaid][g_MaxPlayerTime][time])
        return false;

    g_SalaData[salaid][g_JogadoresNesseTime][time]++;
    g_PlayerData[playerid][g_Qualtime] = (time == 0) ? TIMEAZUL : TIMEVERMELHO;
    SavePlayerIdPainelVic(playerid, salaid, time);
    SetPlayerVirtualWorld(playerid, salaid);
    SetPlayerInterior(playerid, 0);

    if (time == 0)
    {
        SetPlayerPos(playerid, 1501.739624, -1466.230224, 63.859375);
        SetPosPlayerDeath(playerid, 1501.739624, -1466.230224, 63.859375, 273.975128);
        SendClientMessage(playerid, -1, "Voce foi setado no time 1");
    }
    else
    {
        SetPlayerPos(playerid, 1541.481933, -1466.260253, 63.859375);
        SetPosPlayerDeath(playerid, 1541.481933, -1466.260253, 63.859375, 84.488395);
        SendClientMessage(playerid, -1, "Voce foi setado no time 2");
    }
    return true;
}

stock ShwoArenasSala(playerid) {
	new msg[999], msg2[999];

    strcat(msg2, "Tipo da arena\n");
    format(msg, sizeof msg, "[1] Arena 4x4\n");
    strcat(msg2, msg);
    format(msg, sizeof msg, "[2] Arena 1x1\n");
    strcat(msg2, msg);
    format(msg, sizeof msg, "[3] Ammunation\n");
    strcat(msg2, msg);
    format(msg, sizeof msg, "[4] Predio\n");
    strcat(msg2, msg);

    ShowPlayerDialog(playerid, D_ARENASALA, DIALOG_STYLE_TABLIST_HEADERS, "ARENAS QUE SERA USADA EM SUA SALA", msg2, "Selecionar", "Voltar");
	return 1;
}

stock ContarJogadoresVivosPorTime(sala_id, team) {
    new vivos = 0;
    foreach(new i : Player){
        if (g_PlayerData[i][g_Logado] && g_PlayerData[i][g_QualSala] == sala_id && g_PlayerData[i][g_Qualtime] == team) {
            vivos++;
        }
    }
    return vivos;
}

stock VitoriaTime(team, sala_id) {
    EnviarMensagemSala(sala_id, team);
    ResetarSala(sala_id);
    return true;
}

function TimeDestroyVitoria(playerid){
	Destroy_PlayerVitoria(playerid);
	return true;
}

static stock CreateTextDrawnVitoria(playerid, type, time=5000){
	if (!showplayertextvitoria[playerid]){
		Text_PlayerVitoria[playerid][0] = CreatePlayerTextDraw(playerid, 317.000, 199.000, "VITORIA");
		PlayerTextDrawLetterSize(playerid, Text_PlayerVitoria[playerid][0], 1.000, 4.499);
		PlayerTextDrawAlignment(playerid, Text_PlayerVitoria[playerid][0], 2);
		PlayerTextDrawColor(playerid, Text_PlayerVitoria[playerid][0], 6553855);
		PlayerTextDrawSetShadow(playerid, Text_PlayerVitoria[playerid][0], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerVitoria[playerid][0], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerVitoria[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_PlayerVitoria[playerid][0], 3);
		PlayerTextDrawSetProportional(playerid, Text_PlayerVitoria[playerid][0], 1);
		showplayertextvitoria[playerid] = true;
	}
    if (g_PlayerData[playerid][g_Qualtime] == type) {
    	PlayerTextDrawSetString(playerid, Text_PlayerVitoria[playerid][0], "VITORIA");
    	PlayerTextDrawColor(playerid, Text_PlayerVitoria[playerid][0], 6553855);
		PlayerTextDrawShow(playerid, Text_PlayerVitoria[playerid][0]);	
    }
    else {
    	PlayerTextDrawSetString(playerid, Text_PlayerVitoria[playerid][0], "DERROTA");
		PlayerTextDrawColor(playerid, Text_PlayerVitoria[playerid][0], -1962934017);
		PlayerTextDrawShow(playerid, Text_PlayerVitoria[playerid][0]);
    }
	TimerVitoria[playerid] = SetTimerEx("TimeDestroyVitoria", time, false, "d", playerid);
	return true;
}

stock Destroy_PlayerVitoria(playerid) {
    if (showplayertextvitoria[playerid]) {
        for (new i = 0; i < sizeof Text_PlayerVitoria[]; i++) {
        	if (IsPlayerTextDrawVisible(playerid, Text_PlayerVitoria[playerid][i])){
	            PlayerTextDrawDestroy(playerid, Text_PlayerVitoria[playerid][i]);
	            Text_PlayerVitoria[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        	}
        }
    }
    if (TimerVitoria[playerid] != 0) KillTimer(TimerVitoria[playerid]);
    TimerVitoria[playerid] = 0;
    showplayertextvitoria[playerid] = false;
    return true;
}

stock EnviarMensagemSala(sala_id, team){
	foreach(new i : Player){
        if(g_PlayerData[i][g_QualSala] == sala_id){
			CreateTextDrawnVitoria(i, team);
        }
    }
	return true;
}

function ResetPlayerVitoria(salaid){
    foreach(new playerid : Player){
    	if(g_PlayerData[playerid][g_QualSala] == salaid){
	        SetPlayerInterior(playerid, 0);
	        SetPlayerVirtualWorld(playerid, salaid);
	        SetPlayerHealth(playerid, 100.0);
	        SetPlayerArmour(playerid, 100.0);
	        SetPlayerSkin(playerid, g_PlayerData[playerid][g_Skin]);

		    if (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL && g_SalaData[salaid][g_QtdRoudsGanhos][0] < 11) {
		        SetPlayerPos(playerid, 1501.739624, -1466.230224, 63.859375);
		    	GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);
		    }
		    else if (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO && g_SalaData[salaid][g_QtdRoudsGanhos][1] < 11) {
		        SetPlayerPos(playerid, 1541.481933, -1466.260253, 63.859375);
		        GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);
		    }
		    if (g_PlayerData[playerid][g_TimerVitoriaPlayerSala] != 0) KillTimer(g_PlayerData[playerid][g_TimerVitoriaPlayerSala]);
	    	g_PlayerData[playerid][g_TimerVitoriaPlayerSala] = 0;
    	}
    }
   	g_SalaData[salaid][g_MinutosSala] = 1; g_SalaData[salaid][g_SegundosSala] = 1;
	g_SalaData[salaid][g_QtdRouds] += 1;
	return true;
}

stock ResetarSala(sala_id) {
    g_SalaData[sala_id][g_JogadoresMorto][0] = 0;  // Reseta mortes do time azul
    g_SalaData[sala_id][g_JogadoresMorto][1] = 0;  // Reseta mortes do time vermelho
	
	foreach(new playerid : Player){
        if(g_PlayerData[playerid][g_QualSala] == sala_id){
        	if (g_SalaData[sala_id][g_QtdRouds] < 11){
	        	ResetPlayerWeapons(playerid);
	        	if (g_PlayerData[playerid][g_TimerVitoriaPlayerSala] != 0) KillTimer(g_PlayerData[playerid][g_TimerVitoriaPlayerSala]);
		    	g_PlayerData[playerid][g_TimerVitoriaPlayerSala] = 0;
	    		g_PlayerData[playerid][g_TimerVitoriaPlayerSala] = SetTimerEx("ResetPlayerVitoria", 100, false, "d", sala_id);
    		}
    	}
    }
	return true;
}

//Todos os comandos da sala
CMD:criarsala(playerid) {
	if (g_PlayerData[playerid][g_CriouSala])
		return ShowError(playerid, "VOCE JA TEM UMA SALA CRIADA.");
	
	if (!Criandosala[playerid])
		CreatePlayerSala(playerid);
	else 
		Destroy_PlayerSala(playerid);
	return true;
}

CMD:deletarsala(playerid) {
	if (g_PlayerData[playerid][g_CriouSala]){
    	g_PlayerData[playerid][g_CriouSala] = false;
		foreach (new i : Player) {
			if (g_PlayerData[i][g_QualSala] == playerid) {
				g_PlayerData[i][g_QualSala] = -1;
				g_PlayerData[i][g_Qualtime] = UNDFINED;
				g_PlayerData[i][g_Emsala] = false;
				ResetPlayerWeapons(i);
				SetPlayerInterior(i, 1);
				SetPlayerVirtualWorld(i, 1);
		    	SetPlayerPos(i, 1643.445800, -2481.078125, 3001.085937+1);
		    	SetPlayerArmour(i, 0);
		    	SetPlayerHealth(i, 100);
		    	Destroy_PlayerHudSala(i);
		    	ShowInfo(i, "A SALA QUE VOCE PARTICIPA FOI DELETADA.");
			}
		}
		new dummy2[pSalaData];
	    g_SalaData[playerid] = dummy2;
	} else {
		ShowError(playerid, "VOCE NAO TEM NEMHUMA SALA CRIADA.");
	}
	return true;
}

CMD:sala(playerid) {
	new msg[999], msg2[999];
    new count = 0;

    foreach (new i : Player) {
        if (g_SalaData[i][g_SalaCriada]) {
			strcat(msg2, "Nome\tJogadores\tModo de combate\tArma\tPublico ou Privada\n");
			format(msg, sizeof msg, "%s\t%d/%d\t%s\t%s\t%s\n",\
			NomeSala(g_SalaData[i][g_NameSala], i), g_SalaData[i][g_QtdPlayerSala],\
			g_SalaData[i][g_QtdPlayer], ReturnModoDCombate(g_SalaData[i][g_QualModo]), NomeArmas(g_SalaData[i][g_WeaponId]), Privadaoupublica(g_SalaData[i][g_PasswordSala]));
			strcat(msg2, msg);
            count++;
        }
    }

    if (count == 0) {
        ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "SALA DISPONIVEIS", "Nao tem nemhuma sala disponivel no momento.", "Fechar", "");
    } else {
        ShowPlayerDialog(playerid, D_ENTRARSALA, DIALOG_STYLE_TABLIST_HEADERS, "SALA DISPONIVEIS", msg2, "Entrar", "Cancelar");
    }
	return true;
}

stock NomeArmas(armaid){
    new name[35];
    switch(armaid)
    {
        case 1: name = "Soco Ingles";
        case 2: name = "Taco de Golfe";
        case 3: name = "Cacetete";
        case 4: name = "Faca";
        case 5: name = "Taco de Baseball";
        case 6: name = "Pa";
        case 7: name = "Taco de Sinuca";
        case 8: name = "Katana";
        case 9: name = "Motoserra";
        case 10: name = "Dildo Roxo";
        case 11: name = "Dildo";
        case 12: name = "Vibrador";
        case 13: name = "Vibrador de Prata";
        case 14: name = "Flores";
        case 15: name = "Cano";
        case 16: name = "Granada";
        case 17: name = "Gas Lacrimogenio";
        case 18: name = "Coquetel Molotov";
        case 22: name = "Pistola 9mm";
        case 23: name = "Five-Seven";
        case 24: name = "PT";
        case 25: name = "Shotgun";
        case 26: name = "Sawnoff ";
        case 27: name = "Combat Shotgun";
        case 28: name = "Uzi";
        case 29: name = "MP5";
        case 30: name = "AK-47";
        case 31: name = "M4";
        case 32: name = "Tec-9";
        case 33: name = "Country Rifle";
        case 34: name = "Sniper Rifle";
        case 35: name = "RPG";
        case 36: name = "HS Rocket";
        case 37: name = "Lanca-chamas";
        case 38: name = "Minigun";
        case 39: name = "Satchel Charge";
        case 40: name = "Detonador";
        case 41: name = "Lata de Spray";
        case 42: name = "Extintor";
        case 43: name = "Camera";
        case 44: name = "Oculos Noturno";
        case 45: name = "Osculo Termal";
        case 46: name = "Parachute";
        default: name = "Nenhuma";
    }
    return name;
}

stock ShowModoCombate(playerid){
	new msg2[999];

    strcat(msg2, "Modo de combate\tMaximo de jogadores\n");
    strcat(msg2, "{00C080}[1]: {FFFFFF}1x1 (Duelo)\t2 Jogadores\n");
    strcat(msg2, "{00C080}[2]: {FFFFFF}4x4 (Times)\t8 Jogadores\n");
    strcat(msg2, "{00C080}[3]: {FFFFFF}Todos Contra Todos (Opcional)\t20 Jogadores");

    return ShowPlayerDialog(playerid, D_MODODCOMBATE, DIALOG_STYLE_TABLIST_HEADERS, "MODO DE COMBATE:", msg2, "Selecionar", "Cancelar");
}

stock ShowArmaSala(playerid){
	new msg2[999];

    strcat(msg2, "Nome Arma\tNumero de balas\tDano arma\n");
    strcat(msg2, "{00C080}[1]: {FFFFFF}DESERT EAGLE\n");
    strcat(msg2, "{00C080}[2]: {FFFFFF}M4\n");
    strcat(msg2, "{00C080}[3]: {FFFFFF}AK-47\n");
	strcat(msg2, "{00C080}[4]: {FFFFFF}SNIPER\n");
	strcat(msg2, "{00C080}[5]: {FFFFFF}SHOTGUN\n");
	strcat(msg2, "{00C080}[6]: {FFFFFF}SPAS12");

    return ShowPlayerDialog(playerid, D_WEAPONSALA, DIALOG_STYLE_TABLIST_HEADERS, "ESCOLHER ARMA SALA:", msg2, "Selecionar", "Cancelar");
}

stock ShowPublicoouPrivado(playerid){
	new msg2[999];
    
    strcat(msg2, "Caso voce escolha publico qualquer pessoa entra em usa sala.\n");
    strcat(msg2, "Agora se voce escolher privado sua sala precisara de uma senha para entra.\n");
    strcat(msg2, "Click em uma das opcoes abaixo.\n");

    return ShowPlayerDialog(playerid, #, DIALOG_STYLE_MSGBOX, "ESCOLHA SE VAI SER PUBLICO OU PRIVADO:", msg2, "Publico", "Privado");
}

stock ReturnModoDCombate(typemode){
    new name[35];
    switch(typemode){
        case 1: name = "1x1 (Duelo)";
        case 2: name = "4x4 (Times)";
        case 3: name = "Todos Contra Todos";
        default: name = "Nenhuma";
    }
	return name;
}

stock Privadaoupublica(type){
	static str[50];
	if (type > 0) {
		str = "Privado";
	} else {
		str = "Publico";
	}
	return str;
}

stock NomeSala(const name[], id){
	static str[50];
	if (strlen(name) > 0){
		format(str, sizeof str, "%s", name);
	} else {
		format(str, sizeof str, "Sala de %s", PlayerName(id));
	}
	return str;
}

stock GetPlayerModo(playerid){
	if (g_PlayerData[playerid][g_Emsala] == true || g_PlayerData[playerid][g_EmArena][0] == true
	|| g_PlayerData[playerid][g_EmArena][1] == true || g_PlayerData[playerid][g_EmArena][2] == true
  	|| g_PlayerData[playerid][g_EmArena][3] == true || g_PlayerData[playerid][g_EmMundo][0] == true
 	|| g_PlayerData[playerid][g_EmMundo][1] == true || g_PlayerData[playerid][g_EmMundo][2] == true)
		return 1;
 	else 
 		return 0;
}

stock GetPlayerModoComArma(playerid){
	if (g_PlayerData[playerid][g_EmArena][0] == true || g_PlayerData[playerid][g_EmArena][1] == true
	|| g_PlayerData[playerid][g_EmArena][2] == true || g_PlayerData[playerid][g_EmArena][3] == true
 	|| g_PlayerData[playerid][g_EmMundo][1] == true || g_PlayerData[playerid][g_EmMundo][2] == true)
		return 1;
 	else 
 		return 0;
}

stock ResetExitPlayerSala(playerid){
	if (g_PlayerData[playerid][g_CriouSala]){
    	g_PlayerData[playerid][g_CriouSala] = false;
    	g_SalaData[g_PlayerData[playerid][g_QualSala]][g_QtdPlayerSala] --;
		foreach (new i : Player) {
			if (g_PlayerData[i][g_QualSala] == playerid) {
				Destroy_PlayerHudSala(i);
				g_PlayerData[i][g_QualSala] = -1;
				g_PlayerData[i][g_Qualtime] = UNDFINED;
				g_PlayerData[i][g_Emsala] = false;
				ResetPlayerWeapons(i);
				SetPlayerInterior(i, 1);
				SetPlayerVirtualWorld(i, 1);
		    	SetPlayerPos(i, 1643.445800, -2481.078125, 3001.085937+1);
		    	SetPlayerArmour(i, 0);
		    	SetPlayerHealth(i, 100);
		    	ShowInfo(i, "A SALA QUE VOCE PARTICIPA FOI DELETADA.");
			}
		}
		new dummy2[pSalaData];
	    g_SalaData[playerid] = dummy2;
	}
	return true;
}

stock ResetVariavelModos(playerid) {
    if (g_PlayerData[playerid][g_EmArena][0]) {
        JogadoresArena[0]--;
        g_PlayerData[playerid][g_EmArena][0] = false;
    }
    else if (g_PlayerData[playerid][g_EmArena][1]) {
        JogadoresArena[1]--;
        g_PlayerData[playerid][g_EmArena][1] = false;
    }
    else if (g_PlayerData[playerid][g_EmArena][2]) {
        JogadoresArena[2]--;
        g_PlayerData[playerid][g_EmArena][2] = false;
    }
    else if (g_PlayerData[playerid][g_EmArena][3]) {
        JogadoresArena[3]--;
        g_PlayerData[playerid][g_EmArena][3] = false;
    }

    if (g_PlayerData[playerid][g_EmMundo][0]) {
        JogadoresMundo[0]--;
        g_PlayerData[playerid][g_EmMundo][0] = false;
    }
    else if (g_PlayerData[playerid][g_EmMundo][1]) {
        JogadoresMundo[1]--;
        g_PlayerData[playerid][g_EmMundo][1] = false;
    }
    else if (g_PlayerData[playerid][g_EmMundo][2]) {
        JogadoresMundo[2]--;
        g_PlayerData[playerid][g_EmMundo][2] = false;
    }
    return true;
}



stock SetPlayerModosSave(playerid){
    if (g_PlayerData[playerid][g_Emsala] && !IsPlayerNPC(playerid)) {
		TogglePlayerControllable(playerid, true);
		TogglePlayerSpectating(playerid, false);

        new salaid = g_PlayerData[playerid][g_QualSala];

        ResetPlayerWeapons(playerid);
        SetPlayerInterior(playerid, 0);
        SetPlayerVirtualWorld(playerid, salaid);
        SetPlayerHealth(playerid, 100);
        SetPlayerArmour(playerid, 100);
        //SetPlayerSkin(playerid, g_PlayerData[playerid][g_Skin]);

	    // Respawn no time
	    if (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL && g_SalaData[salaid][g_QtdRoudsGanhos][0] < 11) {
	        SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][g_Skin], 1501.739624, -1466.230224, 63.859375, 273.975128, 0, 0, 0, 0, 0, 0);
	    	GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);
	    }
	    else if (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO && g_SalaData[salaid][g_QtdRoudsGanhos][1] < 11) {
	        SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][g_Skin], 1541.481933, -1466.260253, 63.859375, 273.975128, 0, 0, 0, 0, 0, 0);
	        GivePlayerWeapon(playerid, g_SalaData[salaid][g_WeaponId], g_SalaData[salaid][g_MunicaoWeapon]);
	    }
    }
    /*else if (g_PlayerData[playerid][g_EmArena][0] && !IsPlayerNPC(playerid)){
    	TogglePlayerControllable(playerid, true);
		TogglePlayerSpectating(playerid, false);

		ResetPlayerWeapons(playerid);
    	SetPlayerInterior(playerid, 3);    	
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerArmour(playerid, 100);
    	SetPlayerHealth(playerid, 100);
    	GivePlayerWeapon(playerid, 31, 400);
		new rand = random(6);
    	SetPlayerPos(playerid, PosArenaM4[rand][0],PosArenaM4[rand][1],PosArenaM4[rand][2]);
    	SetPlayerFacingAngle(playerid, PosArenaM4[rand][3]);
    }
    if (!g_PlayerData[playerid][g_Emsala] && !g_PlayerData[playerid][g_EmArena][0]
    	&& !g_PlayerData[playerid][g_EmArena][1] && ! g_PlayerData[playerid][g_EmArena][2]
    	&& !g_PlayerData[playerid][g_EmArena][3] && !g_PlayerData[playerid][g_EmMundo][0]
    	&& !g_PlayerData[playerid][g_EmMundo][1] && !g_PlayerData[playerid][g_EmMundo][2]
    	&& !IsPlayerNPC(playerid)) {

		TogglePlayerControllable(playerid, true);
		TogglePlayerSpectating(playerid, false);

        ResetPlayerWeapons(playerid);
        SetPlayerInterior(playerid, 1);	        
        SetPlayerVirtualWorld(playerid, 1);
        SetPlayerHealth(playerid, 100.0);
        SetPlayerArmour(playerid, 0.0);
        SetPlayerSkin(playerid, g_PlayerData[playerid][g_Skin]);
	    SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    }
    if (g_PlayerData[playerid][g_EmMundo][1]){
		ResetPlayerWeapons(playerid);	
		new rand = random(4);
    	SetPlayerPos(playerid, Posdescequebra[rand][0],Posdescequebra[rand][1],Posdescequebra[rand][2]);
    	SetPlayerFacingAngle(playerid, Posdescequebra[rand][3]);
		if (g_PlayerData[playerid][g_VehicleId] > 0) {
			DestroyVehicle(g_PlayerData[playerid][g_VehicleId]);
	    	g_PlayerData[playerid][g_VehicleId] = 0;
	    }
		g_PlayerData[playerid][g_VehicleId] = CreateVehicle(522, Posdescequebra[rand][0],Posdescequebra[rand][1],Posdescequebra[rand][2]+1,Posdescequebra[rand][3], 0, 1, false);
    	PutPlayerInVehicle(playerid, g_PlayerData[playerid][g_VehicleId], 0);
    	GivePlayerWeapon(playerid, 31, 250);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
    	SetPlayerInterior(playerid, 0);
    	SetPlayerVirtualWorld(playerid, 0);
    	//Create_TextPlayerKill(playerid);
    }*/
	return true;
}

stock RemovePlayerSala(playerid){
	if (g_PlayerData[playerid][g_Emsala] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);		    	
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
    	Destroy_PlayerHudSala(playerid);
		g_SalaData[g_PlayerData[playerid][g_QualSala]][g_QtdPlayerSala] -= 1;
		g_PlayerData[playerid][g_Emsala] = false;
	}
	else if (g_PlayerData[playerid][g_EmArena][0] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresArena[0]--;
		g_PlayerData[playerid][g_EmArena][0] = false;
		Destroy_PlayerKill(playerid);
	}
	else if (g_PlayerData[playerid][g_EmArena][1] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresArena[1]--;
		g_PlayerData[playerid][g_EmArena][1] = false;
		Destroy_PlayerKill(playerid);
	}
	else if (g_PlayerData[playerid][g_EmArena][2] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);	
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresArena[2]--;
		g_PlayerData[playerid][g_EmArena][2] = false;
		Destroy_PlayerKill(playerid);
	}
	else if (g_PlayerData[playerid][g_EmArena][3] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresArena[3]--;
		g_PlayerData[playerid][g_EmArena][3] = false;
		Destroy_PlayerKill(playerid);
	}
	else if (g_PlayerData[playerid][g_EmMundo][0] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresMundo[0]--;
		g_PlayerData[playerid][g_EmMundo][0] = false;
	}
	else if (g_PlayerData[playerid][g_EmMundo][1] == true) {
		ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid, 1);
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresMundo[1]--;
		g_PlayerData[playerid][g_EmMundo][1] = false;
		Destroy_PlayerKill(playerid);
	}
	else if (g_PlayerData[playerid][g_EmMundo][2] == true) {
		ResetPlayerWeapons(playerid);		
		SetPlayerInterior(playerid, 1);	    	
		SetPlayerVirtualWorld(playerid, 0);
    	SetPlayerPos(playerid, 1643.445800, -2481.078125, 3001.085937+1);
    	SetPlayerArmour(playerid, 0);
    	SetPlayerHealth(playerid, 100);
		JogadoresMundo[2]--;
		g_PlayerData[playerid][g_EmMundo][2] = false;
		Destroy_PlayerKill(playerid);
	}
	return true;
}