#define	SECONDS_TO_LOGIN    (60)

new PlayerText:Text_LoginPlayer[MAX_PLAYERS][36], 
	PlayerText:player_TextLoadScreen[MAX_PLAYERS][9],
	
	bool:show_PlayerLoadScreen[MAX_PLAYERS],
	bool:show_playerlogin[MAX_PLAYERS], 
	bool:digitouSenha[MAX_PLAYERS],
	
	playerPorsentagem_Loading[MAX_PLAYERS],
	playerTime_LoadScreen[MAX_PLAYERS],
	PlayerText:Text_PlayerHud[MAX_PLAYERS][12],
	bool:Player_ShowHud[MAX_PLAYERS];


function OnPlayerLogin(playerid){
	new ip[24];
	orm_setkey(g_PlayerData[playerid][ormidPlayer], "id");
	
	GetPlayerIp(playerid, ip, 24);

	new query[128 + 30 + 30 + 10]; 
	mysql_format(DBConn, query, sizeof query, "SELECT * FROM `tablebanned` WHERE `ip` = '%s' OR (IF((SELECT COUNT(*) FROM `tablebanned` WHERE `ip` = '%s') = 0, id = '%d', 1));", ip, ip, g_PlayerData[playerid][g_AccId]);
	mysql_tquery(DBConn, query, "CheckPlayerBanned", "is", playerid, ip);

 	if (orm_errno(g_PlayerData[playerid][ormidPlayer]) == ERROR_OK) {
		if (g_PlayerData[playerid][LoginTimer]) KillTimer(g_PlayerData[playerid][LoginTimer]);
		g_PlayerData[playerid][LoginTimer] = 0;
    	g_PlayerData[playerid][LoginTimer] = SetTimerEx("OnLoginTimeout", SECONDS_TO_LOGIN * 1000, false, "d", playerid);
	}

    create_PlayerTextLogin(playerid);
    return 1;
}

function CheckPlayerBanned(playerid, const ip[]) {
	if(cache_num_rows()){
		new admin_ban[24], motivo_ban[24], date_ban, str[350];
		cache_get_value_name(0, "motivo", motivo_ban);
		cache_get_value_name(0, "admin", admin_ban);
		cache_get_value_int(0, "data_banned", date_ban);
		format(str, sizeof(str), "{FFFFFF}ID: ({007DFB} %i {FFFFFF})\n{FFFFFF}Conta: ({007DFB} %s {FFFFFF})\n\
		{FFFFFF}Motivo: ({007DFB} %s {FFFFFF})\n{FFFFFF}Admin: ({007DFB} %s {FFFFFF})\n{FFFFFF}Data: ({007DFB} %s {FFFFFF})\n\nCaso seja um engano, tire um print e entre em\ncontato conosco no discord para resolvermos!",\
		g_PlayerData[playerid][g_AccId], GetPlayerNameEx(playerid), motivo_ban, admin_ban, convert_tstamp(date_ban));
		ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Viridian {FFFFFF}Banido:", str,"Ok", " ");
		format(str, sizeof str, "{FFFF00}Viridian: O passaporte (%i - %s - %s) banido tentou entrar no servidor.", g_PlayerData[playerid][g_AccId], GetPlayerNameEx(playerid), ip);
		SendMessageToAdmin(str);
		return SetTimerEx("KickPlayer", 1000, false, "i", playerid);
	}
	return 1;
}

function OnLoginTimeout(playerid){
    if (g_PlayerData[playerid][LoginTimer]) {
        KillTimer(g_PlayerData[playerid][LoginTimer]);
        g_PlayerData[playerid][LoginTimer] = 0;
    }

    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{0080C0}Tempo esgotado", "{FFFFFF}VocÃª foi expulso por demorar muito para fazer o login.", "Okay", "");
    SetTimerEx("KickPlayer", 500, false, "i", playerid);
    return 1;
}

function load_PlayerLoadScreen(playerid) {
    if (playerPorsentagem_Loading[playerid] < 100) {
        playerPorsentagem_Loading[playerid]++;
        if (IsValidPlayerTextDraw(playerid, player_TextLoadScreen[playerid][8])) {
            PlayerTextDrawSetString(playerid, player_TextLoadScreen[playerid][8], va_return("%d%%", playerPorsentagem_Loading[playerid]));
            PlayerTextDrawShow(playerid, player_TextLoadScreen[playerid][8]);
        }
        return true;
    }

    if (playerTime_LoadScreen[playerid] != 0) KillTimer(playerTime_LoadScreen[playerid]);
    playerTime_LoadScreen[playerid] = 0;

    destroy_PlayerLoadScreen(playerid);
    LoadPlayerLogin(playerid);
    return true;
}

stock LoadPlayerData(playerid) {
    printf("* Debug [LoadPlayerData]: %s comecou uma verificacao de data", PlayerName(playerid));

    format(g_PlayerData[playerid][g_Nome], MAX_PLAYER_NAME, "%s", PlayerName(playerid));
    g_PlayerData[playerid][ormidPlayer] = orm_create("users", DBConn);
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_AccId], "id");
    orm_addvar_string(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Nome], MAX_PLAYER_NAME, "nome");
    orm_addvar_string(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Senha], MAX_PASS_LEN, "senha");
    orm_addvar_string(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Salt], SALT_LEN, "salt");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Level], "level");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Skin], "skin");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_VIP], "vip");
    orm_addvar_string(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_TempoVip], 35, "diasvip");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Avisos], "avisos");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_YouTuber], "youtuber");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Coins], "coins");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_TotalKills], "kills");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Money], "dinheiro");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Admin], "admin");
    orm_addvar_int(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_Familia], "familia");
    orm_addvar_string(g_PlayerData[playerid][ormidPlayer], g_PlayerData[playerid][g_DiscordId], 31, "discord_id");

    orm_setkey(g_PlayerData[playerid][ormidPlayer], "nome");
    orm_load(g_PlayerData[playerid][ormidPlayer], "OnPlayerLogin", "d", playerid);

    printf("* Debug [LoadPlayerData]: %s finalizou uma verificacao de data", PlayerName(playerid));
    return 1;
}

stock SetPlayerData(playerid) {
    GivePlayerMoney(playerid, g_PlayerData[playerid][g_Money]);
    SetPlayerScore(playerid, g_PlayerData[playerid][g_Level]);
    return true;
}

stock saveplayerdata(playerid) {
    if (g_PlayerData[playerid][g_Kills] > g_PlayerData[playerid][g_TotalKills])
        g_PlayerData[playerid][g_TotalKills] = g_PlayerData[playerid][g_Kills];

    orm_update(g_PlayerData[playerid][ormidPlayer]);
    return true;
}

stock LoadPlayerLogin(playerid) {
    LoadPlayerData(playerid);
    create_PlayerTextLogin(playerid);
    LimparChat(playerid, 30);
    return 1;
}

stock create_PlayerLoadScreen(playerid) {
	//SetTimerEx("camera_animation", 1000, false, "d", playerid);
	if (!show_PlayerLoadScreen[playerid]) {
		player_TextLoadScreen[playerid][0] = CreatePlayerTextDraw(playerid, -20.000, -20.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, player_TextLoadScreen[playerid][0], 730.000, 550.000);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][0], 1);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][0], 286331391);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][0], 255);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][0], 1);
		
		player_TextLoadScreen[playerid][1] = CreatePlayerTextDraw(playerid, 328.000, 170.000, "VIRIDIAN");
		PlayerTextDrawLetterSize(playerid, player_TextLoadScreen[playerid][1], 1.300, 4.899);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][1], 2);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][1], -16776961);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][1], 1);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][1], 1);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][1], 0);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][1], 1);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][1], 1);
		
		player_TextLoadScreen[playerid][2] = CreatePlayerTextDraw(playerid, 324.000, 170.000, "VIRIDIAN");
		PlayerTextDrawLetterSize(playerid, player_TextLoadScreen[playerid][2], 1.300, 4.899);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][2], 2);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][2], -1);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][2], 1);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][2], 1);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][2], 0);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][2], 1);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][2], 1);
		
		player_TextLoadScreen[playerid][3] = CreatePlayerTextDraw(playerid, 321.000, 207.000, "PVP");
		PlayerTextDrawLetterSize(playerid, player_TextLoadScreen[playerid][3], 0.600, 3.999);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][3], 2);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][3], -1);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][3], 1);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][3], 1);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][3], 0);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][3], 2);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][3], 1);
		
		player_TextLoadScreen[playerid][4] = CreatePlayerTextDraw(playerid, 540.000, 418.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, player_TextLoadScreen[playerid][4], 75.000, 21.000);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][4], 1);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][4], 1145324799);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][4], 255);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][4], 1);
		
		player_TextLoadScreen[playerid][5] = CreatePlayerTextDraw(playerid, 563.000, 422.000, "CARREGANDO...");
		PlayerTextDrawLetterSize(playerid, player_TextLoadScreen[playerid][5], 0.180, 1.230);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][5], 2);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][5], -1);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][5], 1);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][5], 1);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][5], 0);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][5], 1);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][5], 1);
		
		player_TextLoadScreen[playerid][6] = CreatePlayerTextDraw(playerid, 596.000, 414.300, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, player_TextLoadScreen[playerid][6], 21.000, 27.000);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][6], 1);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][6], -1);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][6], 255);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][6], 4);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][6], 1);
		
		player_TextLoadScreen[playerid][7] = CreatePlayerTextDraw(playerid, 597.099, 416.199, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, player_TextLoadScreen[playerid][7], 18.600, 23.700);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][7], 1);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][7], 1145324799);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][7], 255);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][7], 4);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][7], 1);
		
		player_TextLoadScreen[playerid][8] = CreatePlayerTextDraw(playerid, 606.999, 422.700, "");
		PlayerTextDrawLetterSize(playerid, player_TextLoadScreen[playerid][8], 0.109, 0.960);
		PlayerTextDrawAlignment(playerid, player_TextLoadScreen[playerid][8], 2);
		PlayerTextDrawColor(playerid, player_TextLoadScreen[playerid][8], -1);
		PlayerTextDrawSetShadow(playerid, player_TextLoadScreen[playerid][8], 1);
		PlayerTextDrawSetOutline(playerid, player_TextLoadScreen[playerid][8], 1);
		PlayerTextDrawBackgroundColor(playerid, player_TextLoadScreen[playerid][8], 0);
		PlayerTextDrawFont(playerid, player_TextLoadScreen[playerid][8], 1);
		PlayerTextDrawSetProportional(playerid, player_TextLoadScreen[playerid][8], 1);
		show_PlayerLoadScreen[playerid] = true;
	}
	playerPorsentagem_Loading[playerid] = 0;
	for(new i = 0; i < sizeof player_TextLoadScreen[]; i++) PlayerTextDrawShow(playerid, player_TextLoadScreen[playerid][i]);
	
	for (new i = 0; i < 15; i++) SendClientMessage(playerid, -1, "");
	if (playerTime_LoadScreen[playerid] != 0) KillTimer(playerTime_LoadScreen[playerid]);
	playerTime_LoadScreen[playerid] = 0;
	playerTime_LoadScreen[playerid] = SetTimerEx("load_PlayerLoadScreen", 50, true, "d", playerid);
	
	digitouSenha[playerid] = false;
	return true;
}

stock destroy_PlayerLoadScreen(playerid) {
	if (playerTime_LoadScreen[playerid] != 0) KillTimer(playerTime_LoadScreen[playerid]);
	playerTime_LoadScreen[playerid] = 0;
	if (show_PlayerLoadScreen[playerid]) {
		for (new i = 0; i < sizeof player_TextLoadScreen[]; i++) {
			if (player_TextLoadScreen[playerid][i] != PlayerText:INVALID_TEXT_DRAW) {
				PlayerTextDrawDestroy(playerid, player_TextLoadScreen[playerid][i]);
				player_TextLoadScreen[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
			}
		}
	}
	show_PlayerLoadScreen[playerid] = false;
	playerPorsentagem_Loading[playerid] = 0;
	return true;
}

stock create_PlayerTextLogin(playerid) {
	if (!show_playerlogin[playerid]){
		Text_LoginPlayer[playerid][0] = CreatePlayerTextDraw(playerid, 243.000, 130.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][0], 150.000, 230.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][0], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][0], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][0], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][0], 1);
		
		Text_LoginPlayer[playerid][1] = CreatePlayerTextDraw(playerid, 253.000, 110.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][1], 130.000, 270.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][1], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][1], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][1], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][1], 1);
		
		Text_LoginPlayer[playerid][2] = CreatePlayerTextDraw(playerid, 237.598, 101.708, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][2], 32.000, 51.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][2], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][2], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][2], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][2], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][2], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][2], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][2], 1);
		
		Text_LoginPlayer[playerid][3] = CreatePlayerTextDraw(playerid, 366.497, 101.708, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][3], 32.000, 51.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][3], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][3], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][3], 1);
		
		Text_LoginPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 366.497, 337.308, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][4], 32.000, 51.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][4], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][4], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][4], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][4], 1);
		
		Text_LoginPlayer[playerid][5] = CreatePlayerTextDraw(playerid, 237.649, 337.299, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][5], 32.000, 51.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][5], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][5], 858993663);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][5], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][5], 1);
		
		Text_LoginPlayer[playerid][6] = CreatePlayerTextDraw(playerid, 259.000, 176.960, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][6], 121.000, 39.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][6], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][6], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][6], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][6], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][6], 1);
		
		Text_LoginPlayer[playerid][7] = CreatePlayerTextDraw(playerid, 253.000, 184.960, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][7], 132.000, 24.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][7], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][7], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][7], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][7], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][7], 1);
		
		Text_LoginPlayer[playerid][8] = CreatePlayerTextDraw(playerid, 250.408, 173.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][8], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][8], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][8], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][8], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][8], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][8], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][8], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][8], 1);
		
		Text_LoginPlayer[playerid][9] = CreatePlayerTextDraw(playerid, 250.438, 193.779, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][9], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][9], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][9], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][9], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][9], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][9], 1);
		
		Text_LoginPlayer[playerid][10] = CreatePlayerTextDraw(playerid, 370.709, 173.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][10], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][10], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][10], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][10], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][10], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][10], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][10], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][10], 1);
		
		Text_LoginPlayer[playerid][11] = CreatePlayerTextDraw(playerid, 370.709, 194.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][11], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][11], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][11], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][11], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][11], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][11], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][11], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][11], 1);
		
		Text_LoginPlayer[playerid][12] = CreatePlayerTextDraw(playerid, 259.000, 226.960, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][12], 121.000, 39.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][12], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][12], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][12], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][12], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][12], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][12], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][12], 1);
		
		Text_LoginPlayer[playerid][13] = CreatePlayerTextDraw(playerid, 253.000, 234.960, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][13], 132.000, 24.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][13], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][13], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][13], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][13], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][13], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][13], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][13], 1);
		
		Text_LoginPlayer[playerid][14] = CreatePlayerTextDraw(playerid, 250.408, 223.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][14], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][14], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][14], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][14], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][14], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][14], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][14], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][14], 1);
		
		Text_LoginPlayer[playerid][15] = CreatePlayerTextDraw(playerid, 250.438, 243.779, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][15], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][15], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][15], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][15], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][15], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][15], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][15], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][15], 1);
		
		Text_LoginPlayer[playerid][16] = CreatePlayerTextDraw(playerid, 370.709, 223.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][16], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][16], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][16], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][16], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][16], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][16], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][16], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][16], 1);
		
		Text_LoginPlayer[playerid][17] = CreatePlayerTextDraw(playerid, 370.709, 244.059, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][17], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][17], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][17], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][17], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][17], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][17], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][17], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][17], 1);
		
		Text_LoginPlayer[playerid][18] = CreatePlayerTextDraw(playerid, 259.000, 326.959, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][18], 121.000, 39.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][18], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][18], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][18], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][18], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][18], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][18], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][18], 1);
		
		Text_LoginPlayer[playerid][19] = CreatePlayerTextDraw(playerid, 253.000, 334.959, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][19], 132.000, 24.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][19], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][19], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][19], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][19], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][19], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][19], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][19], 1);
		
		Text_LoginPlayer[playerid][20] = CreatePlayerTextDraw(playerid, 250.408, 323.058, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][20], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][20], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][20], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][20], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][20], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][20], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][20], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][20], 1);
		
		Text_LoginPlayer[playerid][21] = CreatePlayerTextDraw(playerid, 250.438, 343.778, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][21], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][21], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][21], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][21], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][21], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][21], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][21], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][21], 1);
		
		Text_LoginPlayer[playerid][22] = CreatePlayerTextDraw(playerid, 370.709, 323.058, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][22], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][22], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][22], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][22], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][22], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][22], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][22], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][22], 1);
		
		Text_LoginPlayer[playerid][23] = CreatePlayerTextDraw(playerid, 370.709, 344.058, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][23], 17.000, 26.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][23], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][23], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][23], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][23], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][23], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][23], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][23], 1);
		
		Text_LoginPlayer[playerid][24] = CreatePlayerTextDraw(playerid, 256.000, 178.000, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][24], 14.000, 23.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][24], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][24], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][24], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][24], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][24], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][24], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][24], 1);
		
		Text_LoginPlayer[playerid][25] = CreatePlayerTextDraw(playerid, 254.199, 195.399, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][25], 18.000, 19.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][25], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][25], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][25], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][25], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][25], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][25], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][25], 1);
		
		Text_LoginPlayer[playerid][26] = CreatePlayerTextDraw(playerid, 258.000, 243.300, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][26], 10.000, 15.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][26], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][26], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][26], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][26], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][26], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][26], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][26], 1);
		
		Text_LoginPlayer[playerid][27] = CreatePlayerTextDraw(playerid, 263.299, 257.058, "U");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][27], 0.479, -3.138);
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][27], 0.008, 0.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][27], 2);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][27], 8438015);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][27], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][27], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][27], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][27], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][27], 1);
		
		Text_LoginPlayer[playerid][28] = CreatePlayerTextDraw(playerid, 278.248, 188.059, "Jhgzin_dev");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][28], 0.289, 1.779);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][28], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][28], 2004318207);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][28], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][28], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][28], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][28], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][28], 1);
		
		Text_LoginPlayer[playerid][29] = CreatePlayerTextDraw(playerid, 278.248, 236.059, "Senha");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][29], 0.289, 1.779);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][29], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][29], 2004318207);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][29], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][29], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][29], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][29], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][29], 1);
		
		Text_LoginPlayer[playerid][30] = CreatePlayerTextDraw(playerid, 319.348, 333.140, "REGISTRAR");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][30], 0.549, 2.609);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][30], 2);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][30], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][30], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][30], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][30], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][30], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][30], 1);
		
		Text_LoginPlayer[playerid][31] = CreatePlayerTextDraw(playerid, 271.000, 229.619, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][31], 105.000, 35.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][31], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][31], 0);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][31], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][31], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][31], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][31], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][31], 1);
		PlayerTextDrawSetSelectable(playerid, Text_LoginPlayer[playerid][31], 1);
		
		Text_LoginPlayer[playerid][32] = CreatePlayerTextDraw(playerid, 267.000, 329.219, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][32], 105.000, 35.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][32], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][32], 0);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][32], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][32], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][32], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][32], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][32], 1);
		PlayerTextDrawSetSelectable(playerid, Text_LoginPlayer[playerid][32], 1);
		
		Text_LoginPlayer[playerid][33] = CreatePlayerTextDraw(playerid, 319.248, 125.139, "Login Viridian");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][33], 0.559, 2.799);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][33], 2);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][33], 512819199);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][33], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][33], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][33], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][33], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][33], 1);
		
		Text_LoginPlayer[playerid][34] = CreatePlayerTextDraw(playerid, 316.248, 269.140, "ESQUECI MINHA SENHA");
		PlayerTextDrawLetterSize(playerid, Text_LoginPlayer[playerid][34], 0.208, 1.340);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][34], 2);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][34], 1145324799);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][34], 1);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][34], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][34], 0);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][34], 1);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][34], 1);
		
		Text_LoginPlayer[playerid][35] = CreatePlayerTextDraw(playerid, 279.000, 270.618, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_LoginPlayer[playerid][35], 74.000, 11.000);
		PlayerTextDrawAlignment(playerid, Text_LoginPlayer[playerid][35], 1);
		PlayerTextDrawColor(playerid, Text_LoginPlayer[playerid][35], 0);
		PlayerTextDrawSetShadow(playerid, Text_LoginPlayer[playerid][35], 0);
		PlayerTextDrawSetOutline(playerid, Text_LoginPlayer[playerid][35], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_LoginPlayer[playerid][35], 255);
		PlayerTextDrawFont(playerid, Text_LoginPlayer[playerid][35], 4);
		PlayerTextDrawSetProportional(playerid, Text_LoginPlayer[playerid][35], 1);
		PlayerTextDrawSetSelectable(playerid, Text_LoginPlayer[playerid][35], 1);
		show_playerlogin[playerid] = true;
	}

    if(check_PlayerhasAccount(playerid)) PlayerTextDrawSetString(playerid, Text_LoginPlayer[playerid][30], "LOGAR");
    PlayerTextDrawSetString(playerid, Text_LoginPlayer[playerid][28], GetPlayerNameEx(playerid));

	for(new i = 0; i < sizeof Text_LoginPlayer[]; i++) PlayerTextDrawShow(playerid, Text_LoginPlayer[playerid][i]);
	SelectTextDraw(playerid, 0);
	return 1;
}

stock Destroy_PlayerLogin(playerid) {
    if (g_PlayerData[playerid][LoginTimer] != 0) KillTimer(g_PlayerData[playerid][LoginTimer]);
	g_PlayerData[playerid][LoginTimer] = 0;
    if (show_playerlogin[playerid] == true) {
        for (new i = 0; i < sizeof Text_LoginPlayer[]; i++) {
        	if (Text_LoginPlayer[playerid][i] != PlayerText:INVALID_TEXT_DRAW) {
	            PlayerTextDrawDestroy(playerid, Text_LoginPlayer[playerid][i]);
	            Text_LoginPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
            }
        }
    }
    CancelSelectTextDraw(playerid);
    show_playerlogin[playerid] = false;
    return true;
}

stock check_PlayerhasAccount(playerid) {
	new query[76]; mysql_format(DBConn, query, sizeof query, "SELECT * FROM `users` WHERE `nome`='%s' LIMIT 1;", PlayerName(playerid));
	mysql_query(DBConn, query);
	if (cache_num_rows() > 0)
		return true;
	return false;
}

stock CreatePlayerHud(playerid){
	if (!Player_ShowHud[playerid]){
		Text_PlayerHud[playerid][0] = CreatePlayerTextDraw(playerid, 280.300, 5.000, "V");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHud[playerid][0], 0.700, 3.539);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][0], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][0], 40677375);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][0], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][0], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][0], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][0], 3);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][0], 1);
		
		Text_PlayerHud[playerid][1] = CreatePlayerTextDraw(playerid, 322.000, 34.000, "PVP");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHud[playerid][1], 0.400, 1.939);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][1], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][1], 512819199);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][1], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][1], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][1], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][1], 3);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][1], 1);
		
		Text_PlayerHud[playerid][2] = CreatePlayerTextDraw(playerid, 327.000, 5.000, "IRIDIAN");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHud[playerid][2], 0.700, 3.539);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][2], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][2], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][2], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][2], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][2], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][2], 3);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][2], 1);
		
		Text_PlayerHud[playerid][3] = CreatePlayerTextDraw(playerid, 485.000, 5.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][3], 43.000, 20.150);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][3], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][3], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][3], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][3], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][3], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][3], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][3], 1);
		
		Text_PlayerHud[playerid][4] = CreatePlayerTextDraw(playerid, 535.000, 5.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][4], 43.000, 20.150);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][4], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][4], 286331391);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][4], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][4], 1);
		
		Text_PlayerHud[playerid][5] = CreatePlayerTextDraw(playerid, 486.399, 4.600, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][5], 8.599, 12.199);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][5], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][5], 40677375);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][5], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][5], 1);
		
		Text_PlayerHud[playerid][6] = CreatePlayerTextDraw(playerid, 485.000, 14.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][6], 11.599, 12.199);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][6], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][6], 40677375);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][6], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][6], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][6], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][6], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][6], 1);
		
		Text_PlayerHud[playerid][7] = CreatePlayerTextDraw(playerid, 534.199, 5.600, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][7], 13.599, 20.199);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][7], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][7], 40677375);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][7], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][7], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][7], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][7], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][7], 1);
		
		Text_PlayerHud[playerid][8] = CreatePlayerTextDraw(playerid, 540.299, 11.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][8], 1.199, 6.499);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][8], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][8], 255);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][8], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][8], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][8], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][8], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][8], 1);
		
		Text_PlayerHud[playerid][9] = CreatePlayerTextDraw(playerid, 541.299, 15.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, Text_PlayerHud[playerid][9], 2.399, 2.599);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][9], 1);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][9], 255);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][9], 0);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][9], 0);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][9], 255);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][9], 4);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][9], 1);
		
		Text_PlayerHud[playerid][10] = CreatePlayerTextDraw(playerid, 510.999, 8.000, "%d");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHud[playerid][10], 0.180, 1.290);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][10], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][10], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][10], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][10], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][10], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][10], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][10], 1);
		
		Text_PlayerHud[playerid][11] = CreatePlayerTextDraw(playerid, 558.999, 8.040, "%02d:%02d");
		PlayerTextDrawLetterSize(playerid, Text_PlayerHud[playerid][11], 0.210, 1.340);
		PlayerTextDrawAlignment(playerid, Text_PlayerHud[playerid][11], 2);
		PlayerTextDrawColor(playerid, Text_PlayerHud[playerid][11], -1);
		PlayerTextDrawSetShadow(playerid, Text_PlayerHud[playerid][11], 1);
		PlayerTextDrawSetOutline(playerid, Text_PlayerHud[playerid][11], 1);
		PlayerTextDrawBackgroundColor(playerid, Text_PlayerHud[playerid][11], 0);
		PlayerTextDrawFont(playerid, Text_PlayerHud[playerid][11], 1);
		PlayerTextDrawSetProportional(playerid, Text_PlayerHud[playerid][11], 1);
		Player_ShowHud[playerid] = true;
	}
	new hora, minutos, segundos;
	gettime(hora, minutos, segundos);
	PlayerTextDrawSetString(playerid, Text_PlayerHud[playerid][10], va_return("%d", g_PlayerData[playerid][g_AccId]));
	PlayerTextDrawSetString(playerid, Text_PlayerHud[playerid][11], va_return("%02d:%02d", hora, minutos));
	for(new i = 0; i < sizeof Text_PlayerHud[]; i++) PlayerTextDrawShow(playerid, Text_PlayerHud[playerid][i]);
	return true;
}

stock Destroy_PlayerHud(playerid) {
    if (Player_ShowHud[playerid] == true) {
        for (new i = 0; i < sizeof Text_PlayerHud[]; i++) {
        	if (Text_PlayerHud[playerid][i] != PlayerText:INVALID_TEXT_DRAW) {
	            PlayerTextDrawDestroy(playerid, Text_PlayerHud[playerid][i]);
	            Text_PlayerHud[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
            }
        }
    }
    Player_ShowHud[playerid] = false;
    return true;
}