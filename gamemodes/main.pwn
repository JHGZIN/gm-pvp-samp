#include <a_samp>
#include <crashdetect>

#define SSCANF_NO_NICE_FEATURES

#if defined MAX_PLAYERS
	#undef MAX_PLAYERS
#endif
// numero de slots do servidor, isso otimiza muito o servidor.
#define MAX_PLAYERS 100

#include <a_mysql>
#include <streamer>
#include <sscanf2>
#include <Pawn.CMD>
#include <timerfix>
#include <fly>
#include <foreach>
#include <textdraw-streamer>
#include <discord-connector>
#include <discord-cmd>

//ANT CHEAT
#define DEBUG
#include <nex-ac_pt_br.lang>
#include <nex-ac>

//MODULOS
#include "../modulos/dices/define.inc"
#include "../modulos/dices/dialog.inc"
#include "../modulos/dices/player.inc"
#include "../modulos/dices/sala.inc"
#include "../modulos/dices/server.inc"

#include "../modulos/utils/stock.inc"
#include "../modulos/utils/funcoes.inc"

#include "../modulos/comandos/command_admin.inc"
#include "../modulos/comandos/command_animes.inc"
#include "../modulos/comandos/command_player.inc"
#include "../modulos/comandos/command_beneficios.inc"

#include "../modulos/mapas/allmap.inc"

#include "../modulos/prokillerpa/discord.inc"
#include "../modulos/prokillerpa/anti-cheat.inc"

#include "../modulos/sistemas/system_painelvic.inc"
#include "../modulos/sistemas/system_sala.inc"
#include "../modulos/sistemas/system_login.inc"
#include "../modulos/sistemas/system_menuskins.inc"
#include "../modulos/sistemas/system_velocimetro.inc"
#include "../modulos/sistemas/system_familia.inc"
#include "../modulos/sistemas/system_codigos.inc"
#include "../modulos/sistemas/system_notify.inc"
#include "../modulos/sistemas/system_chatkill.inc"

main(){
	CarregarFamilia();
	CreateAllMap();
	CreateAmmu();
	print("Loaded 'main.amx' successfully");
}

public OnGameModeInit(){
	DBConn = mysql_connect_file("database-connect.ini");
	if(mysql_errno(DBConn) != 0){
	    print("[MySQL] ERRO: Nao foi possivel se conectar a database!");
	    SendRconCommand("exit");
	    return false;
	}
	print("[MySQL]: database conectada com sucesso!");
	mysql_query_file(DBConn, "database/viridian.sql");

	//====== Timers =================

	SetTimer("SendMensagens", 500000, 1);
	SetTimer("RandomServerNames", 1000,1);
	SetTimer("RecarregarNitro", 5000, true);
	//SetTimer("ChamadaUmSegundo", 1000, true);

	//===============================

    SendRconCommand("language Portugues - Brasil");
    SendRconCommand("gamemodetext PvP/Fugas | "#SERVER_VERSION);

    //===============================

    ShowNameTags(0);
    UsePlayerPedAnims();
    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
    ShowPlayerMarkers(0);

 	//===============================

    DisableCrashDetectLongCall(); //Disabilitar as detectacoes das longs callbacks, assim evitando flood ao server_log.txt
	
	//===============================

	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 500);
    Streamer_SetVisibleItems(STREAMER_TYPE_PICKUP, 50);
    Streamer_SetVisibleItems(STREAMER_TYPE_CP, 50);
    Streamer_SetVisibleItems(STREAMER_TYPE_RACE_CP, 50);
    Streamer_SetVisibleItems(STREAMER_TYPE_MAP_ICON, 100);
    Streamer_SetVisibleItems(STREAMER_TYPE_3D_TEXT_LABEL, 100);
    Streamer_SetVisibleItems(STREAMER_TYPE_AREA, 20);
    Streamer_SetVisibleItems(STREAMER_TYPE_ACTOR, 10);

	//TextDraw Velocimetro
    gtd_SpeedoMeter[0] = TextDrawCreate(606.5, 417.35, "KM/H");
    TextDrawLetterSize(gtd_SpeedoMeter[0], 0.15, 0.769);
    TextDrawColor(gtd_SpeedoMeter[0], -1);
    TextDrawSetShadow(gtd_SpeedoMeter[0], 0);
    TextDrawSetOutline(gtd_SpeedoMeter[0], 1);
    TextDrawBackgroundColor(gtd_SpeedoMeter[0], 20);

    gtd_SpeedoMeter[1] = TextDrawCreate(524.0, 429.0, "LD_SPAC:white");
    TextDrawTextSize(gtd_SpeedoMeter[1], 97.0, 8.0);
    TextDrawColor(gtd_SpeedoMeter[1], 0xFFFFFFFF);
    TextDrawFont(gtd_SpeedoMeter[1], 4);

    //===============================

	CreateDynamicActor(183, 1660.779174, -2481.662841, 3001.085937, 93.281860, true, 100.0);//comandos
	CreateDynamicActor(187, 1643.270874, -2460.494873, 3001.085937, 185.712371, true, 100.0);//mundos
	CreateDynamicActor(189, 1623.328735, -2481.382080, 3001.085937, 264.997558, true, 100.0);//loja
	CreateDynamicActor(166, 1643.542114, -2504.205322, 3001.085937, 358.782928, true, 100.0);//

    CreateDynamic3DTextLabel("{FFFFFF}Pressione '{007DFB}ALT{FFFFFF}'", -1, 1660.779174, -2481.662841, 3001.085937, 30.0);
    CreateDynamic3DTextLabel("{FFFFFF}Pressione '{007DFB}ALT{FFFFFF}'", -1, 1643.270874, -2460.494873, 3001.085937, 30.0);
    CreateDynamic3DTextLabel("{FFFFFF}Pressione '{007DFB}ALT{FFFFFF}'", -1, 1623.328735, -2481.382080, 3001.085937, 30.0);
    CreateDynamic3DTextLabel("{FFFFFF}Pressione '{007DFB}ALT{FFFFFF}'", -1, 1643.542114, -2504.205322, 3001.085937, 30.0);
    return true;
}

public OnGameModeExit(){
    mysql_close(DBConn);
	return true;
}

public OnPlayerRequestClass(playerid, classid){
	TogglePlayerSpectating(playerid, true);
    TogglePlayerControllable(playerid, false);
    SetPlayerVirtualWorld(playerid, -555);
    InterpolateCameraPos(playerid, -259.148712, 2673.008056, 67.044456, -314.974761, 2735.550048, 66.667938, 60000);
	InterpolateCameraLookAt(playerid, -263.189605, 2675.919433, 66.602264, -317.987152, 2739.540771, 66.664260, 60000);
	return true;
}

public OnPlayerConnect(playerid) {
	create_PlayerLoadScreen(playerid);

	InitChatKillSystem(playerid);
	InitFly(playerid);

    ResetVars(playerid);    
    removeobjetos(playerid);

    textSpeedoMeter[playerid] = CreatePlayerTextDraw(playerid, 590.0, 407.0, "000");
    PlayerTextDrawLetterSize(playerid, textSpeedoMeter[playerid], 0.389, 2.2);
    PlayerTextDrawAlignment(playerid, textSpeedoMeter[playerid], 2);
    PlayerTextDrawColor(playerid, textSpeedoMeter[playerid], -1);
    PlayerTextDrawSetShadow(playerid, textSpeedoMeter[playerid], 0);
    PlayerTextDrawSetOutline(playerid, textSpeedoMeter[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, textSpeedoMeter[playerid], 20);
    PlayerTextDrawFont(playerid, textSpeedoMeter[playerid], 2);

    barSpeedoMeter[playerid] = CreatePlayerTextDraw(playerid, 524.0, 429.0, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, barSpeedoMeter[playerid], 0.0, 8.0);
    PlayerTextDrawColor(playerid, barSpeedoMeter[playerid], 0x0000C2AA);
    PlayerTextDrawFont(playerid, barSpeedoMeter[playerid], 4);

    ultimoMovimento[playerid] = gettime();
    estaAFK[playerid] = false;
    inicioAFK[playerid] = 0;
    g_PlayerData[playerid][g_QualSala] = -1;
	return true;
}

public OnPlayerDisconnect(playerid, reason){
	Destroy_PlayerLogin(playerid);
	destroy_PlayerLoadScreen(playerid);
	DestroyTextVitoriaTD(playerid);
	Destroy_PlayerHud(playerid);
	
	if (g_PlayerData[playerid][g_Logado]){
		if(PlayerVelocimetro[playerid]) 
			KillTimer(PlayerVelocimetroTimer[playerid]);

	    Destroy_PlayerKill(playerid);
	    Destroy_PlayerVitoria(playerid);

	    saveplayerdata(playerid);
		g_PlayerData[playerid][g_Logado] = false;
	}

	if (g_PlayerData[playerid][ormidPlayer] != MYSQL_INVALID_ORM) orm_destroy(g_PlayerData[playerid][ormidPlayer]);
	g_PlayerData[playerid][ormidPlayer] = MYSQL_INVALID_ORM;

	if (g_PlayerData[playerid][g_VehicleId] > 0) DestroyVehicle(g_PlayerData[playerid][g_VehicleId]);
    g_PlayerData[playerid][g_VehicleId] = 0;

    estaAFK[playerid] = false;
    inicioAFK[playerid] = 0;

	if (timerUpdateSpeedoMeter[playerid] != 0) KillTimer(timerUpdateSpeedoMeter[playerid]);
	timerUpdateSpeedoMeter[playerid] = 0;

	ResetExitPlayerSala(playerid);
	ResetVariavelModos(playerid);
	ResetPlayerWeapons(playerid);		

	g_PlayerData[playerid][g_QualSala] = -1;
	g_PlayerData[playerid][g_Qualtime] = UNDFINED;
	g_PlayerData[playerid][g_Emsala] = false;

	Criandosala[playerid] = false;

    if (g_PlayerData[playerid][g_TimerPainelV] != 0) KillTimer(g_PlayerData[playerid][g_TimerPainelV]);
    g_PlayerData[playerid][g_TimerPainelV] = 0;
   
    for (new i = 0; i < 4; i++){g_JogadorId[playerid][i][0] = 0;g_JogadorId[playerid][i][1] = 0;}
    
    new dummy[pData];
    g_PlayerData[playerid] = dummy;

    new dummy2[pSalaData];
    g_SalaData[playerid] = dummy2;

    DeletePVar(playerid, "LiderId");
	DeletePVar(playerid, "FamiliaId");
	return true;
}

public OnPlayerSpawn(playerid){
	if (!g_PlayerData[playerid][g_Logado]){
	    /*if(strlen(g_PlayerData[playerid][g_TempoVip]) > 0 && g_PlayerData[playerid][g_VIP] > 0){
	        new timestampExpira = parseDateToTimestamp(g_PlayerData[playerid][g_TempoVip]);
	        new timestampAtual = getTimestamp();

	        if(timestampAtual >= timestampExpira){
	            // VIP expirado
	            g_PlayerData[playerid][g_VIP] = 0;
	            format(g_PlayerData[playerid][g_TempoVip], 35, "");
	            
	            // Remove no banco, se quiser
	            new query[100];
	            mysql_format(DBConn, query, sizeof(query), "UPDATE users SET vip = 0, diasvip = NULL WHERE id = %d", g_PlayerData[playerid][g_AccId]);
	            mysql_tquery(DBConn, query);

	            ShowInfo(playerid, "SEU VIP EXPIROU!");
	        }
	    }*/
	    CreatePlayerHud(playerid);
		g_PlayerData[playerid][g_Logado] = true;
		SetPlayerData(playerid);

		g_PlayerData[playerid][g_LabelAccid] = CreateDynamic3DTextLabel(va_return("{FFFFFF}%d", g_PlayerData[playerid][g_AccId]), -1, 0.0, 0.0, 0.2, 20.0, playerid);
	}
	return true;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	SetPlayerModosSave(playerid);
	SpawnPlayer(playerid);

    // ProteÃ§Ã£o contra mortes de NPC ou jogadores nÃ£o logados
    if (!g_PlayerData[playerid][g_Logado] || IsPlayerNPC(playerid))
        return true;

    if (killerid != INVALID_PLAYER_ID && g_PlayerData[killerid][g_Logado] && !g_PlayerData[playerid][g_EmMundo][0] && !IsPlayerNPC(killerid))
    {
        if (!g_PlayerData[playerid][g_Logado])
        {
            Ban(playerid);
            return true;
        }

        // Exibe o chat kill para quem estiver em batalha
        foreach (new i : Player)
        {
            if (!IsPlayerConnected(i) || !IsPlayerLogado(i)) continue;

            new bool:iEmBatalha = g_PlayerData[i][g_Emsala] || GetPlayerModoComArma(i);
            new bool:vitimasEmBatalha = g_PlayerData[killerid][g_Emsala] || GetPlayerModoComArma(killerid) || g_PlayerData[playerid][g_Emsala] || GetPlayerModoComArma(playerid);

            if (iEmBatalha && vitimasEmBatalha)
            {
                ShowChatKill(i, GetPlayerNameEx(killerid), GetPlayerNameEx(playerid));
            }
        }

        // Modo com arma: contabiliza mortes e recompensas
        if (GetPlayerModoComArma(playerid))
        {
            g_PlayerData[playerid][g_Mortes]++;
            g_PlayerData[killerid][g_Kills]++;

            GivePlayerLevel(killerid, 1);
            SetPlayerMoney(killerid, 500);
        }

        // Modo por sala: contabiliza estatÃ­sticas e forÃ§a respawn na sala
        if (g_PlayerData[playerid][g_Emsala] && g_PlayerData[killerid][g_Emsala])
        {
            g_PlayerData[playerid][g_MortesSala]++;
            g_PlayerData[killerid][g_KillSala]++;

            new salaid = g_PlayerData[playerid][g_QualSala];

            if (g_PlayerData[playerid][g_Qualtime] == TIMEAZUL)
            {
                g_SalaData[salaid][g_JogadoresMorto][0]++;
                g_SalaData[salaid][g_QtdRoudsGanhos][1]++;
                VitoriaTime(TIMEVERMELHO, salaid);
            }
            else if (g_PlayerData[playerid][g_Qualtime] == TIMEVERMELHO)
            {
                g_SalaData[salaid][g_JogadoresMorto][1]++;
                g_SalaData[salaid][g_QtdRoudsGanhos][0]++;
                VitoriaTime(TIMEAZUL, salaid);
            }
        }
   	}
    else if (killerid == INVALID_PLAYER_ID && !g_PlayerData[playerid][g_EmMundo][0])
    {
        // Morreu sozinho (sem killer)
        if (GetPlayerModoComArma(playerid))
        {
            g_PlayerData[playerid][g_Mortes]++;
        }
    }

    return true;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ){
	if(g_PlayerData[playerid][g_VIP] > 1 || g_PlayerData[playerid][g_Admin] > 0){
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
		    new veh = GetPlayerVehicleID(playerid);
			SetVehiclePos(veh, fX, fY, fZ+1);
		}
		else{
            SetPlayerPosFindZ(playerid, fX, fY, fZ+1);
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
		}
	}
	return true;
}

public OnPlayerText(playerid, text[]){
	if (!IsPlayerLogado(playerid))
		return ShowError(playerid, "VOCE NAO ESTA LOGADO");

	if(gettime() < GetPVarInt(playerid, "AntFloodText")){
        SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {858585}Aguarde 3 Segundos para mandar mensagem no chat novamente!");
        return 0;
    }
	new string[560];
	if(realchat){
		if(g_PlayerData[playerid][g_AdmJob]){
			SetPVarInt(playerid, "AntFloodText", gettime()+3);
			format(string, sizeof(string), "{FF00FF}[Admin]{FFFFFF} %s #%d diz: %s", PlayerName(playerid), g_PlayerData[playerid][g_AccId], text);
			SendClientMessageInRange(20.0, playerid, string,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA);
		}
		else if(g_PlayerData[playerid][g_VIP] == 3){
			SetPVarInt(playerid, "AntFloodText", gettime()+3);
			format(string, sizeof(string), "{FF0000}[VIP GOLDEN]{FFFFFF} %s #%d diz: %s", PlayerName(playerid), g_PlayerData[playerid][g_AccId], text);
			SendClientMessageInRange(20.0, playerid, string,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA);
		}
		else if(g_PlayerData[playerid][g_YouTuber] == 1){
			SetPVarInt(playerid, "AntFloodText", gettime()+3);
			format(string, sizeof(string), "{FF0000}[YouTuber OFC]{FFFFFF} %s #%d diz: %s", PlayerName(playerid), g_PlayerData[playerid][g_AccId], text);
			SendClientMessageInRange(20.0, playerid, string,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA);
		}
		else{
			SetPVarInt(playerid, "AntFloodText", gettime()+3);
			format(string, sizeof(string), "{FFFFFF}%s #%d diz: {FAFAFA}%s", PlayerName(playerid), g_PlayerData[playerid][g_AccId], text);
			SendClientMessageInRange(20.0, playerid, string,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA);
		}
		return 0;
	}
	return 0;
}

public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags){
    if(result == -1){
    	ShowError(playerid, "COMANDO INVALIDO!");
    }
    return true;
}

public OnPlayerStateChange(playerid, newstate, oldstate){
    if (newstate == PLAYER_STATE_DRIVER) {
        new vehicleid = GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective;

        GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
        SetVehicleParamsEx(vehicleid, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, alarm, doors, bonnet, boot, objective);

        ShowPlayerSpeedoMeter(playerid);

        AddVehicleComponent(vehicleid, 1010);
    }
   	if (oldstate == PLAYER_STATE_DRIVER) {
        HidePlayerSpeedoMeter(playerid);
    }
	return true;
}

public OnPlayerEnterCheckpoint(playerid){
    DisablePlayerCheckpoint(playerid);
	return true;
}

public OnPlayerRequestSpawn(playerid){
    SendClientMessage(playerid, 0xFF0000AA, "| ERRO | Voce precisa efetuar o login para jogar.");
    return 0;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys){
 	if(newkeys & KEY_CROUCH){
        fAutoC[playerid] = 0;
 	}
 	if(!pCBugging[playerid] && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT){
		if(PRESSED(KEY_FIRE))
		{
			switch(GetPlayerWeapon(playerid))
			{
				case WEAPON_DEAGLE, WEAPON_SHOTGUN, WEAPON_SNIPER:
				{
					ptsLastFiredWeapon[playerid] = gettime();
				}
			}
		}
		else if(PRESSED(KEY_CROUCH))
		{
			if((gettime() - ptsLastFiredWeapon[playerid]) < 5)
			{
				TogglePlayerControllable(playerid, false);

				pCBugging[playerid] = true;

				GameTextForPlayer(playerid, "~r~~p~PARE COM O ~n~~w~C-Bug!", 3000, 4);
				SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {FFFFFF}Pare com o C-Bug ! Ou tomara {FF0000}AVISO");

				KillTimer(ptmCBugFreezeOver[playerid]);
				ptmCBugFreezeOver[playerid] = SetTimerEx("CBugFreezeOver", 3000, false, "i", playerid);
			}
		}
	}
	
	if (newkeys == KEY_WALK) { //ALT
		if (GetPlayerSpeed(playerid) == 0) {
			if (IsPlayerInRangeOfPoint(playerid, 4.0, 1660.779174, -2481.662841, 3001.085937)) {//comandos
				callcmd::comandos(playerid);
			}
			if (IsPlayerInRangeOfPoint(playerid, 4.0, 1643.270874, -2460.494873, 3001.085937)) {//mundos
				callcmd::mundos(playerid);
			}
			if (IsPlayerInRangeOfPoint(playerid, 4.0, 1623.328735, -2481.382080, 3001.085937)) {//loja
				callcmd::loja(playerid);
			}
			if (IsPlayerInRangeOfPoint(playerid, 4.0, 1643.542114, -2504.205322, 3001.085937)) {//Arenas
				callcmd::arena(playerid);
			}
		}
	}
	return true;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart){
	if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		if(g_PlayerData[playerid][g_Logado] == true) {
			if(bodypart == 9) {
				PlayerPlaySound(playerid, 17802,0.0,0.0,0.0);
				PlayerPlaySound(damagedid, 17802,0.0,0.0,0.0);
				SetPlayerHealth(damagedid, 0.0);
				g_PlayerData[playerid][g_HeadShot] += 1;
			}
			else {
				GameTextForPlayer(playerid, "~g~+9", 3000, 1);
				GameTextForPlayer(damagedid, "~r~-9", 3000, 1);
				PlayerPlaySound(playerid, 17802,0.0,0.0,0.0);
				PlayerPlaySound(damagedid, 17802,0.0,0.0,0.0);
				return true;
			}
			/*new Infod[430];
			format(Infod, 50, "DANO -%.0f", amount);
			TextDrawSetString(Atingir[0], Infod);
			TextDrawShowForPlayer(playerid, Atingir[0]);
			SetTimerEx("RemoveTextDraw", 2000, false, "i", playerid);*/
		}
	}
	return true;
}

public OnRconLoginAttempt(ip[], password[], success){
    if(!success){
        new pip[16], str[250];
        foreach(Player, i){
            GetPlayerIp(i, pip, sizeof(pip));
            if(new_strcmp(pip, ip)){
                if(!new_strcmp(PlayerName(i), "Jhgzin_Dev") || !new_strcmp(PlayerName(i), "Jhgzin_Silva")){
	                format(str, sizeof(str), "{007DFB}[ViridianGuard]: {FFFFFF}O(a) jogador(a) %s foi kickado ( Motivo: Tentativa de Login RCON )", PlayerName(i));
					SendClientMessageToAll(0xFF0000FF, str);
					GameTextForPlayer(i, "~r~Kickado!", 3000, 0);
					Kick(i);
				}
				return true;
            }
        }
    }
	return true;
}

public OnPlayerUpdate(playerid){
	if (g_PlayerData[playerid][g_Logado]){
	    if (estaAFK[playerid]){
	        new tempoAFK = gettime() - inicioAFK[playerid];
	        new msg[64];
	        format(msg, sizeof(msg), "{FFFFFF}* Voce saiu do modo AFK {FF8000}%02d:%02d.", tempoAFK / 60, tempoAFK % 60);
	        SendClientMessage(playerid, 0x00FF00FF, msg);

	        estaAFK[playerid] = false;
	        inicioAFK[playerid] = 0;
	    }
	    
	    ultimoMovimento[playerid] = gettime();
		
		new str[11];
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

	    if(GetPlayerMoney(playerid) != g_PlayerData[playerid][g_Money]){
	        ResetPlayerMoney(playerid);
	        GivePlayerMoney(playerid, g_PlayerData[playerid][g_Money]);
	    }
	    
	    new hora, minutos, segundos;
		gettime(hora, minutos, segundos);
	    PlayerTextDrawSetString(playerid, Text_PlayerHud[playerid][11], va_return("%02d:%02d", hora, minutos));
	}
	return true;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    switch(dialogid) {
	    case D_REGISTRO: {
			if(response){
			    if(strlen(inputtext) >= 5 && strlen(inputtext) <= 20){
			    	g_PlayerData[playerid][g_Salt] = salt();
	                SHA256_PassHash(inputtext, g_PlayerData[playerid][g_Salt], g_PlayerData[playerid][g_Senha], MAX_PASS_LEN);

					digitouSenha[playerid] = true;
		            for(new i = 0; i < strlen(inputtext); i++)
		            {
		                inputtext[i] = '#';
		            }
			        PlayerTextDrawSetString(playerid, Text_LoginPlayer[playerid][29], inputtext);
			    }
			    else {
		    		ShowPlayerDialog(playerid, D_REGISTRO, DIALOG_STYLE_PASSWORD, "{858585}Senha Registro", "Digite sua senha abaixo:", "Confirmar", "Cancelar");
			    }
			}
		}
		case D_SENHA: {
			if(response) {
			    if(strlen(inputtext) > 0) {
			    	new hash[MAX_PASS_LEN];
	                SHA256_PassHash(inputtext, g_PlayerData[playerid][g_Salt], hash, MAX_PASS_LEN);
				    if(strlen(inputtext) < 6 || strcmp(g_PlayerData[playerid][g_Senha], hash)){
				    	ShowPlayerDialog(playerid, D_SENHA, DIALOG_STYLE_PASSWORD, "{858585}Senha Login", "Digite sua senha abaixo:", "Confirmar", "Cancelar");
				    }
				    else {
				    	digitouSenha[playerid] = true;
			            for(new i = 0; i < strlen(inputtext); i++)
			            {
			                inputtext[i] = '#';
			            }
			            PlayerTextDrawSetString(playerid, Text_LoginPlayer[playerid][29], inputtext);
				    }
				}
				else {
		    		ShowPlayerDialog(playerid, D_SENHA, DIALOG_STYLE_PASSWORD, "{858585}Senha Login", "Digite sua senha abaixo:", "Confirmar", "Cancelar");
				}
			}
		}
    	case D_DIGITARSENHASALA: {
    		if (response) {
	    		if (strval(inputtext)) {
		    		if (strlen(inputtext) >= 2  && strlen(inputtext) <= 7) {
		    			g_SalaData[playerid][g_PasswordSala] = strval(inputtext);
			            PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][22], "PRIVADO");
		    		} else {
		    			return ShowPlayerDialog(playerid, D_DIGITARSENHASALA, DIALOG_STYLE_PASSWORD, "{FF0000}ERRO: SENHA GRANDE", "Digite sua senha novamente:\nA senha da sua sala deve conter pelomento 2 numeros.", "Tentar Novamente", "Cancelar");
		    		}
		    	} else {
		    		return ShowPlayerDialog(playerid, D_DIGITARSENHASALA, DIALOG_STYLE_PASSWORD, "{FF0000}ERRO: SENHA INVALIDA", "Digite sua senha novamente:\nA senha da sua sala deve conter somente numeros.", "Tentar Novamente", "Cancelar");
		    	}    		
	    	}
    	}
		case D_ENTRARSALA: {
		    if (response) {
		        new salaSelecionada = listitem; // Pega o ÃƒÂ­ndice da sala escolhida
		        new bool:salaEncontrada = false;
		        
		        if (g_PlayerData[playerid][g_Emsala])
		        	return SendClientMessage(playerid, -1, "{FF0000}Erro: {FFFFFF}Voce ja esta em uma sala.");

		        foreach (new i : Player) {
		            if (g_SalaData[i][g_SalaCriada]) {
		                if (salaSelecionada == 0) { // Selecionou esta sala
		                	
		                	if (g_SalaData[i][g_PasswordSala] > 0){
		                		ShowPlayerDialog(playerid, D_PASSWORDSALA, DIALOG_STYLE_PASSWORD, "SALA PRIVADA", "Digite a senha abaixo para esta entrando na sala", "Confiarmar", "Voltar");
		                    } else {
						        if (i < 0 || i >= MAX_PLAYERS || !g_SalaData[i][g_SalaCriada])
						            return SendClientMessage(playerid, -1, "FF0000}Erro: {FFFFFF}Esta sala nao existe mais!");

		                        SetarPlayerSala(playerid, i);
		                    }
		                    g_PlayerData[playerid][g_SelectSalaId] = listitem;
		                    salaEncontrada = true;
		                    break;
		                }
		                salaSelecionada--; // Continua verificando as prÃƒÂ³ximas salas
		            }
		        }
		        if (!salaEncontrada) SendClientMessage(playerid, -1, "FF0000}Erro: {FFFFFF}Nao foi possivel entrar nessa sala.");
		    }
		}
		case D_PASSWORDSALA:{
		    if (response){
		        new salaId = g_PlayerData[playerid][g_SelectSalaId];

		        if (salaId < 0 || salaId >= MAX_PLAYERS || !g_SalaData[salaId][g_SalaCriada])
		            return SendClientMessage(playerid, -1, "FF0000}Erro: {FFFFFF}Esta sala nao existe mais!");

		        if (strval(inputtext) != g_SalaData[salaId][g_PasswordSala]) {
		            ShowPlayerDialog(playerid, D_PASSWORDSALA, DIALOG_STYLE_PASSWORD, "SALA PRIVADA", "{FF0000}Senha incorreta! Tente novamente.\n{FFFFFF}Digite a senha abaixo para esta entrando na sala", "Confiarmar", "Voltar");
		        }
		        else {
		        	SetarPlayerSala(playerid, salaId);
		            SendClientMessage(playerid, -1, "Voce entrou na sala com sucesso!");
		        }

		    }
		}
    	case D_WEAPONSALA: {
			if (!response)
				return true;

			switch(listitem) {
				case 0: {
	    			g_SalaData[playerid][g_WeaponId] = 24; g_SalaData[playerid][g_MunicaoWeapon] = 50;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
				case 1: {
	    			g_SalaData[playerid][g_WeaponId] = 31; g_SalaData[playerid][g_MunicaoWeapon] = 150;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
				case 2: {
	    			g_SalaData[playerid][g_WeaponId] = 30; g_SalaData[playerid][g_MunicaoWeapon] = 150;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
				case 3: {
	    			g_SalaData[playerid][g_WeaponId] = 34; g_SalaData[playerid][g_MunicaoWeapon] = 100;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
				case 4: {
	    			g_SalaData[playerid][g_WeaponId] = 25; g_SalaData[playerid][g_MunicaoWeapon] = 150;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
				case 5: {
	    			g_SalaData[playerid][g_WeaponId] = 26; g_SalaData[playerid][g_MunicaoWeapon] = 150;
					static str[20]; format(str, sizeof str, "%s",  NomeArmas(g_SalaData[playerid][g_WeaponId]));
	    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][23], str);
				}
			}
    	}
    	case D_NOMEDASALA: {
    		if (response) {
	    		if (strlen(inputtext)) {
		    		if (strlen(inputtext) >= 1 && strlen(inputtext) <= 24) {
		    			format(g_SalaData[playerid][g_NameSala], 24, "%s", inputtext);
		    			PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][20], g_SalaData[playerid][g_NameSala]);
		    		} else {
		    			return ShowPlayerDialog(playerid, D_NOMEDASALA, DIALOG_STYLE_INPUT, "{FF0000}ERRO: NOME INVALIDA", "Digite novamente o nome da sala:\n{FF0000}Aviso: Voce nao pode digitar qualquer nome cuidado oque voce ira digita.", "Tentar Novamente", "Cancelar");
		    		}
		    	} else {
		    		return ShowPlayerDialog(playerid, D_NOMEDASALA, DIALOG_STYLE_INPUT, "{FF0000}ERRO: NOME INVALIDA", "Digite novamente o nome da sala:\nLembrando que voce nao pode digitar numeros.", "Tentar Novamente", "Cancelar");
		    	}    		
	    	}
    	}

		case D_MODODCOMBATE: {
			if (!response)
				return true;

			switch(listitem) {
				case 0: { //1x1 (Duelo)
					PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "1x1 (Duelo)");
					g_SalaData[playerid][g_QualModo] = 1;
					g_SalaData[playerid][g_QtdPlayer] = 2;
					g_SalaData[playerid][g_MaxPlayerTime][0] = 1; g_SalaData[playerid][g_MaxPlayerTime][1] = 1;
					g_SalaData[playerid][g_QtdRouds] = 1; g_SalaData[playerid][g_MaxRouds] = 10;
				}
				case 1: { //4x4 (Times)
					PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "4x4 (Times)");
					g_SalaData[playerid][g_QualModo] = 2; g_SalaData[playerid][g_QtdPlayer] = 8;
					g_SalaData[playerid][g_MaxPlayerTime][0] = 4; g_SalaData[playerid][g_MaxPlayerTime][1] = 4;
					g_SalaData[playerid][g_QtdRouds] = 1; g_SalaData[playerid][g_MaxRouds] = 20;
				}
				case 2: { //Todos Contra Todos (Opcional)
					SendClientMessage(playerid, -1, "ESSE MODO ESTA EM DESENVOLVIMENTO");
					PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "UNDFINED");
					//PlayerTextDrawSetString(playerid, Text_PlayerSala[playerid][21], "Todos Contra Todos (Opcional)");
					//g_SalaData[playerid][g_QualModo] = 3; g_SalaData[playerid][g_QtdPlayer] = 20;
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////////////////////

		case D_ENTRARARENA: {
			if (!response)
				return true;

			switch(listitem) {
				case 0: { //Arena M4
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");
					
					ResetPlayerWeapons(playerid);
			    	SetPlayerInterior(playerid, 3);    	
					SetPlayerVirtualWorld(playerid, 0);
					new rand = random(6);
			    	SetPlayerPos(playerid, PosArenaM4[rand][0],PosArenaM4[rand][1],PosArenaM4[rand][2]);
			    	SetPlayerFacingAngle(playerid, PosArenaM4[rand][3]);
			    	SetPlayerArmour(playerid, 100);
			    	SetPlayerHealth(playerid, 200);
			    	GivePlayerWeapon(playerid, 31, 400);
			    	ResetVariavelModos(playerid);
			    	JogadoresArena[0]++;
			    	g_PlayerData[playerid][g_EmArena][0] = true;
			    	Create_TextPlayerKill(playerid);
			    	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para Arena M4.");
				}
				/*case 1: { //Arena Sniper
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);
					SetPlayerInterior(playerid, 1);    	
					SetPlayerVirtualWorld(playerid, 2);
			    	SetPlayerPos(playerid, 1642.316406, -2480.656494, 3001.085937);
			    	SetPlayerArmour(playerid, 100);
			    	SetPlayerHealth(playerid, 200);
			    	GivePlayerWeapon(playerid, 34, 250);
			    	ResetVariavelModos(playerid);
			    	JogadoresArena[1]++;
			    	g_PlayerData[playerid][g_EmArena][1] = true;
			    	Create_TextPlayerKill(playerid);
				   	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para Arena Sniper.");
				}*/
				case 1: { //Ammunation
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);
			    	SetPlayerInterior(playerid, 0);    	
					SetPlayerVirtualWorld(playerid, 0);
			    	SetPlayerPos(playerid, 1206.8820,-922.3835,42.9461);
			    	SetPlayerArmour(playerid, 100);
			    	SetPlayerHealth(playerid, 200);
			    	GivePlayerWeapon(playerid, 24, 200);
			    	ResetVariavelModos(playerid);
			    	JogadoresArena[2]++;
			    	g_PlayerData[playerid][g_EmArena][2] = true;
			    	Create_TextPlayerKill(playerid);
				   	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para Ammunation.");
				}
				case 2: { //Predio
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);
			    	SetPlayerInterior(playerid, 0);    	
					SetPlayerVirtualWorld(playerid, 0);
			    	SetPlayerPos(playerid, 1520.879638, -1467.438232, 63.859375);
			    	SetPlayerArmour(playerid, 100);
			    	SetPlayerHealth(playerid, 200);
			    	GivePlayerWeapon(playerid, 24, 200);
			    	ResetVariavelModos(playerid);
					JogadoresArena[3]++;
					g_PlayerData[playerid][g_EmArena][3] = true;
					Create_TextPlayerKill(playerid);
				   	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para o Predio.");
				}
			}
		}

		case D_ENTRARMUNDO: {
			if (!response)
				return true;

			switch(listitem) {
				case 0: {//Mundo fugas
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);
			    	SetPlayerArmour(playerid, 0);
			    	SetPlayerHealth(playerid, 200);
					SetPlayerPos(playerid, 2479.291992, -1658.503784, 13.340848);
					SetPlayerFacingAngle(playerid, 88.070365);
					SetPlayerInterior(playerid, 0);
					SetPlayerVirtualWorld(playerid, 0);
					ResetVariavelModos(playerid);
			    	g_PlayerData[playerid][g_EmMundo][0] = true; 
			    	JogadoresMundo[0]++;
			    	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para o mundo fugas.");
				}
				case 1: {//Mundo desce e quebrar
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);	
					new rand = random(4);
			    	SetPlayerPos(playerid, Posdescequebra[rand][0],Posdescequebra[rand][1],Posdescequebra[rand][2]);
			    	SetPlayerFacingAngle(playerid, Posdescequebra[rand][3]);
					if (g_PlayerData[playerid][g_VehicleId] > 0) {
						DestroyVehicle(g_PlayerData[playerid][g_VehicleId]);
						g_PlayerData[playerid][g_VehicleId] = 0;
	    			}		    	
    				g_PlayerData[playerid][g_VehicleId] = CreateVehicle(522, Posdescequebra[rand][0],Posdescequebra[rand][1],Posdescequebra[rand][2],Posdescequebra[rand][3], 0, 1, false);
			    	SetVehicleParamsEx(g_PlayerData[playerid][g_VehicleId], VEHICLE_PARAMS_ON, 1, 0, 0, 0, 0, 0);
			    	PutPlayerInVehicle(playerid, g_PlayerData[playerid][g_VehicleId], 0);
			    	GivePlayerWeapon(playerid, 31, 250);
			    	SetPlayerArmour(playerid, 0);
			    	SetPlayerHealth(playerid, 200);
			    	SetPlayerInterior(playerid, 0);
			    	SetPlayerVirtualWorld(playerid, 0);
			    	ResetVariavelModos(playerid);
			    	g_PlayerData[playerid][g_EmMundo][1] = true; 
			    	JogadoresMundo[1]++;
			    	Create_TextPlayerKill(playerid);
			    	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para o mundo desce e quebrar.");
				}
				case 2: {//Mundo Mata-Mata
					if (GetPlayerModo(playerid))
						return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}VocÃª jÃ¡ esta em uma modo use /sair e tente novamente.");

					ResetPlayerWeapons(playerid);
					SetPlayerInterior(playerid, 1);    	
					SetPlayerVirtualWorld(playerid, 222);
					new rand = random(6);
			    	SetPlayerPos(playerid, PosArenaM4[rand][0],PosArenaM4[rand][1],PosArenaM4[rand][2]);
			    	SetPlayerFacingAngle(playerid, PosArenaM4[rand][3]);
			    	SetPlayerArmour(playerid, 100);
			    	SetPlayerHealth(playerid, 200);
			    	ResetVariavelModos(playerid);
				    g_PlayerData[playerid][g_EmMundo][2] = true; 
			    	JogadoresMundo[2]++;
			    	Create_TextPlayerKill(playerid);
			    	SendClientMessage(playerid, -1, "{007DFB}Viridian: {FFFFFF}VocÃª foi para o mundo Mata-Mata.");
				}
			}
		}
		//
		case D_LOJACOIN: {
			if (!response)
				return true;
			switch(listitem){
				case 0: {
    				ShowPlayerDialog(playerid, D_ESCOLHERVIP, DIALOG_STYLE_TABLIST, "Vips", DIALOG_LOJAVIP, "Selecionar", "Voltar");
				}
				case 1: {
    				ShowPlayerDialog(playerid, D_ESCOLHERFAMILY, DIALOG_STYLE_TABLIST, "Familia", DIALOG_FAMILIA, "Selecionar", "Voltar");
				}
				case 2: {
					ShowPlayerDialog(playerid, D_RESGATARCODIGO, DIALOG_STYLE_INPUT, "Resgatar Codigo", "Digite o codigo de resgate abaixo:", "Regatar", "Voltar");
				}
			}
		}
		case D_ESCOLHERFAMILY: {
			if (response){
				if (g_PlayerData[playerid][g_Coins] >= 20){
					ShowPlayerDialog(playerid, D_CRIARFAMILIA, DIALOG_STYLE_INPUT, "{FAFAFA}Nome:", "Digite o nome para sua familia:", "Confirmar", "Sair");
				} else {
					ShowError(playerid, "VOCE NAO TEM COINS SUFICIENTE!");
				}
			} else {
				callcmd::loja(playerid);
			}
		}
		case D_RESGATARCODIGO: {
			if (!response)
				return true;

		    if (isnull(inputtext)) return ShowPlayerDialog(playerid, D_RESGATARCODIGO, DIALOG_STYLE_INPUT, "Resgatar Codigo", "Digite o codigo de resgate abaixo:", "Regatar", "Voltar");

		    new code[64], query[128];
		    format(code, sizeof code, "%s", inputtext);

		    mysql_format(DBConn, query, sizeof(query), "SELECT * FROM `codigos` WHERE `codigo` = '%e' LIMIT 1", code);
		    mysql_tquery(DBConn, query, "OnResgatarCodigo", "is", playerid, code);
		}
		case D_ESCOLHERVIP: {
			if (response){
				switch(listitem){
					case 0: {
	    				ShowPlayerDialog(playerid, D_COMPRARVIPN, DIALOG_STYLE_TABLIST, "Comprar Vip Normal", DIALOG_VIPNORMAL, "Selecionar", "Voltar");
					}
					case 1: {
	    				ShowPlayerDialog(playerid, D_COMPRARVIPR, DIALOG_STYLE_TABLIST, "Comprar Vip Rubir", DIALOG_VIPRUBI, "Selecionar", "Voltar");
					}
					case 2: {
	    				ShowPlayerDialog(playerid, D_COMPRARVIPG, DIALOG_STYLE_TABLIST, "Comprar Vip Golden", DIALOG_VIPGOLDEN, "Selecionar", "Voltar");
					}
				}
			} else {
				callcmd::loja(playerid);
			}
		}
		case D_COMPRARVIPN: {
			if (!response)
				return true;

			switch(listitem){
				case 0: {
					if (g_PlayerData[playerid][g_Coins] > 10){
						DarVIP(playerid, 30, 1);
					    g_PlayerData[playerid][g_Coins] -= 10;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
						SendClientMessage(playerid, -1, "{FFFFFF}Voce comprou o VIP NORMAL valido por 30 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
					}
				}
				case 1: {
					if (g_PlayerData[playerid][g_Coins] > 20){
						DarVIP(playerid, 60, 1);
					    g_PlayerData[playerid][g_Coins] -= 20;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
						SendClientMessage(playerid, -1, "{FFFFFF}Voce comprou o VIP NORMAL valido por 60 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
					}
				}
				case 2: {
					if (g_PlayerData[playerid][g_Coins] > 30){
						DarVIP(playerid, 365, 1);
					    g_PlayerData[playerid][g_Coins] -= 30;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
						SendClientMessage(playerid, -1, "{FFFFFF}Voce comprou o VIP NORMAL valido por 365 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFFFF}======================== VIP NORMAL =========================");
					}
				}
			}
		}
		case D_COMPRARVIPR: {
			if (!response)
				return true;

			switch(listitem){
				case 0: {
					if (g_PlayerData[playerid][g_Coins] > 40){
						DarVIP(playerid, 30, 2);
					    g_PlayerData[playerid][g_Coins] -= 40;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
						SendClientMessage(playerid, -1, "{7200E4}Voce comprou o VIP RUBI valido por 30 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
					}
				}
				case 1: {
					if (g_PlayerData[playerid][g_Coins] > 50){
						DarVIP(playerid, 60, 2);
					    g_PlayerData[playerid][g_Coins] -= 50;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
						SendClientMessage(playerid, -1, "{7200E4}Voce comprou o VIP RUBI valido por 60 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
					}
				}
				case 2: {
					if (g_PlayerData[playerid][g_Coins] > 60){
						DarVIP(playerid, 365, 2);
					    g_PlayerData[playerid][g_Coins] -= 60;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
						SendClientMessage(playerid, -1, "{7200E4}Voce comprou o VIP RUBI valido por 365 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{7200E4}======================== VIP RUBI =========================");
					}
				}
			}
		}
		case D_COMPRARVIPG: {
			if (!response)
				return true;

			switch(listitem){
				case 0: {
					if (g_PlayerData[playerid][g_Coins] > 70){
						DarVIP(playerid, 30, 3);
					    g_PlayerData[playerid][g_Coins] -= 70;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
						SendClientMessage(playerid, -1, "{FFFF0C}Voce comprou o VIP GOLDEN valido por 30 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
					}
				}
				case 1: {
					if (g_PlayerData[playerid][g_Coins] > 80){
						DarVIP(playerid, 60, 3);
					    g_PlayerData[playerid][g_Coins] -= 80;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
						SendClientMessage(playerid, -1, "{FFFF0C}Voce comprou o VIP GOLDEN valido por 60 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
					}
				}
				case 2: {
					if (g_PlayerData[playerid][g_Coins] > 90){
						DarVIP(playerid, 365, 3);
					    g_PlayerData[playerid][g_Coins] -= 90;
					    LimparChat(playerid, 50);
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
						SendClientMessage(playerid, -1, "{FFFF0C}Voce comprou o VIP GOLDEN valido por 365 dias, use /beneficios");
					    SendClientMessage(playerid, -1, "{FFFF0C}======================== VIP GOLDEN =========================");
					}
				}
			}
		}
		case D_CRIARFAMILIA: {
			if (!response)
				return true;
			if (!IsNumeric(inputtext)){
				if (strlen(inputtext) >= 5 && strlen(inputtext) <= 40){
	                new i;
	                for(i = 1; i < MAX_FAMILY; i++){
	                    if(!g_FamiliaData[i][g_FamiliaUsada]){
	                    	new query2[70];
						    mysql_format(DBConn, query2, sizeof query2, "SELECT id FROM familia WHERE nome = '%e' LIMIT 1", inputtext);
						    new Cache:PQP = mysql_query(DBConn, query2, true);
						    if (cache_num_rows() == 0) {
		                      	format(g_FamiliaData[i][g_Name], MAX_NAME_FAMILIA, inputtext);
		                        g_FamiliaData[i][g_Chefe] = g_PlayerData[playerid][g_AccId];
		                        g_FamiliaData[i][g_SubChefe] = -1;
		                        g_FamiliaData[i][g_Vagas] = 25;
		                        g_FamiliaData[i][g_FamiliaUsada] = true;
		                        new query3[110];
		                        format(query3, sizeof query3, "UPDATE `users` SET `familia` ='%d', `familia` ='%d' WHERE `id` = '%d'", (i-1), CARGO_LIDER, g_PlayerData[playerid][g_AccId]);
								mysql_query(DBConn, query3, false);

		                        g_PlayerData[playerid][g_Familia] = (i-1);
		                        g_PlayerData[playerid][g_CargoFamilia] = CARGO_LIDER;
		                        
		                        g_PlayerData[playerid][g_Coins] -= 20;

		                        static str[68]; format(str, sizeof str, "{007DFB}Loja: {FFFFFF}%s criou uma nova familia! '/loja'", GetPlayerNameEx(playerid));
		                        SendMessageToPlayersLogados(str);

		                        new query[170]; 
		                        mysql_format(DBConn, query, sizeof query, "INSERT INTO `familia` (`id`, `nome`, `lider`, `sublider`, `vagas`) VALUES ('%i', '%s', '%i', '%i', '%i');", i, g_FamiliaData[i][g_Name], g_FamiliaData[i][g_Chefe], g_FamiliaData[i][g_SubChefe], g_FamiliaData[i][g_Vagas]);
		                        mysql_query(DBConn, query, false);
						    } else {
						        ShowError(playerid, "JA EXISTE UMA FAMILIA COM ESSE NOME.");
						    }
						    cache_delete(PQP);
	                        break;
	                    }
	                }
	                if(i == MAX_FAMILY)
	                    return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}A quantidade maxima de familias foi atingida. (20)");			
        		} else {
					ShowPlayerDialog(playerid, D_CRIARFAMILIA, DIALOG_STYLE_INPUT, "{FAFAFA}Nome:", "{FF0000}ERRO: O nome da famila tem que ser de 10 a 40 caracter\n{FFFFFF}Digite o nome para sua familia:", "Confirmar", "sair");
				}
			}
		}
		case D_DELETARFAMILIA: {
			if (!response)
				return true;

			new id = (listitem);
			if(!g_FamiliaData[id][g_FamiliaUsada])
    			return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Esta familia nao existe.");

		    new query[54 + 10]; 
		    mysql_format(DBConn, query, sizeof query, "DELETE FROM `familia` WHERE `id` = '%i';", (id+1));
		    mysql_query(DBConn, query, false);

          	format(g_FamiliaData[id][g_Name], MAX_NAME_FAMILIA, "");
            g_FamiliaData[id][g_Chefe] = -1;
            g_FamiliaData[id][g_SubChefe] = -1;
            g_FamiliaData[id][g_Vagas] = 0;
            g_FamiliaData[id][g_FamiliaUsada] = false;
            g_FamiliaData[id][Pos][0] = 0;
            g_FamiliaData[id][Pos][1] = 0;
            g_FamiliaData[id][Pos][2] = 0;
            g_FamiliaData[id][Pos][3] = 0;
            g_FamiliaData[id][g_Vip] = 0;

		    if(g_FamiliaData[id][Pos][0] != 0.0){
		        DestroyDynamic3DTextLabel(g_FamiliaData[id][LabelFamilia]);
		        DestroyDynamicPickup(g_FamiliaData[id][PickupFamilia]);
		    }

		    g_FamiliaData[id][LabelFamilia] = Text3D:INVALID_3DTEXT_ID;
		    g_FamiliaData[id][PickupFamilia] = -1;

		    va_SendClientMessage(playerid, -1, "{007DFB}Familia: {FFFFFF}A familia ID: ({007DFB}%i{FFFFFF}) foi deletada com sucesso.", id);
		}
		/*case D_SETVIPFAMILIA: {
			if (!response)
				return true;
			switch(listitem){
				case 0: {
					SendClientMessage(playerid, -1, "{00FF00}Vip Prata definido com sucesso.");
					g_PFamiliaData[playerid][g_Vip] = 1; g_PFamiliaData[playerid][g_TempoVip] = ConvertDays(30);
					callcmd::cfamilia(playerid);
				}
				case 1: {
					SendClientMessage(playerid, -1, "{00FF00}Vip Bronze definido com sucesso.");
					g_PFamiliaData[playerid][g_Vip] = 2; g_PFamiliaData[playerid][g_TempoVip] = ConvertDays(30);
					callcmd::cfamilia(playerid);
				}
				case 2: {
					SendClientMessage(playerid, -1, "{00FF00}Vip Ouro definido com sucesso.");
					g_PFamiliaData[playerid][g_Vip] = 3; g_PFamiliaData[playerid][g_TempoVip] = ConvertDays(30);
					callcmd::cfamilia(playerid);
				}
			}
		}
		case D_POSFAMILIA: {
			if (!response)
				return true;
			switch(listitem){
				case 0: {
					ShowPlayerDialog(playerid, D_CONFIRMARPOS, DIALOG_STYLE_MSGBOX, "{FAFAFA}Confirmar Posicao familia:", "VocÃª deseja definir essa posicao para exibir o icone da familia?\nSe vocÃª tive nÃ£o tiver uma posicÃ£o definida e clicar em nÃ£o ficara a posicÃ£o salva recentemente.", "Sim", "NÃ£o");
				}
			}
		}
		case D_CONFIRMARPOS:{
			if (response){
				GetPlayerPos(playerid, g_PFamiliaData[playerid][Pos][0], g_PFamiliaData[playerid][Pos][1], g_PFamiliaData[playerid][Pos][0]);
				GetPlayerFacingAngle(playerid, g_PFamiliaData[playerid][Pos][3]);
				SendClientMessage(playerid, -1, "{00FF00}Voce definiu essa posicao que voce esta para exibir o icone da familia.");
			} else {
				SendClientMessage(playerid, -1, "{FF0000}Voce desistiu de colocar essa posicao.");
			}
		}*/
		case D_TELEPORTE:{
			switch(listitem){
				case 0:{
					if (GetPlayerState(playerid) == 2){
						new tmpcar = GetPlayerVehicleID(playerid);
						SetVehiclePos(tmpcar,  1481.2043,-1698.1680,14.0469);
						SetVehicleZAngle(tmpcar, 180.0000);
					}
					else
					{
						SetPlayerPos(playerid, 1481.2043,-1698.1680,14.0469);
						SetPlayerFacingAngle(playerid, 0.2459);
						SendClientMessage(playerid, -1, "{007DFB}| VIRIDIAN TP |: {FFFFFF}Voce foi teleportado para [ Las Venturas ]!");
						SetPlayerInterior(playerid,0);
						SetPlayerVirtualWorld(playerid, 0);
					}
				}
				case 1:{
					if (GetPlayerState(playerid) == 2){
						new tmpcar = GetPlayerVehicleID(playerid);
						SetVehiclePos(tmpcar, 1699.2, 1435.1, 10.7);
						SetPlayerArmour(playerid, 0);
					    SetPlayerHealth(playerid,100);
					    GivePlayerWeapon(playerid, 0, 0);
				    	return 1;
					}
					else
					{
						SetPlayerPos(playerid, 1699.2,1435.1, 10.7);
						SendClientMessage(playerid, -1, "{007DFB}| VIRIDIAN TP |: {FFFFFF}Voce foi teleportado para [ Las Venturas ]!");
						SetPlayerInterior(playerid,0);
						SetPlayerVirtualWorld(playerid, 0);
					}
				}
				case 2:{
					if (GetPlayerState(playerid) == 2)
			    	{
			    		new tmpcar = GetPlayerVehicleID(playerid);
			    		SetVehiclePos(tmpcar, -2724.3208,-314.6010,7.1862);
			    	}
			    	else
			    	{
			    		SetPlayerPos(playerid, -2724.3208,-314.6010,7.1862);
						SendClientMessage(playerid, -1, "{007DFB}| VIRIDIAN TP |: {FFFFFF}Voce foi teleportado para [ Las Venturas ]!");
			    		SetPlayerInterior(playerid,0);
			    		SetPlayerVirtualWorld(playerid, 0);
			    	}
				}
				case 3:{

				}
			}
		}
		case D_ESCOLHERTIME:{
			new salaid = g_PlayerData[playerid][g_QualSala];
			if (response){
				if (g_SalaData[salaid][g_QualModo] == 2){
					if (g_SalaData[salaid][g_JogadoresNesseTime][0] < g_SalaData[salaid][g_MaxPlayerTime][0]){
						g_SalaData[salaid][g_JogadoresNesseTime][0] ++;
						g_PlayerData[playerid][g_Qualtime] = TIMEAZUL;
						SetPlayerVirtualWorld(playerid, salaid);
						SetPlayerInterior(playerid, 0);
						SetPlayerPos(playerid, 1501.739624, -1466.230224, 63.859375);
						SendClientMessage(playerid, -1, "Voce foi setado no time 1");
						SetPosPlayerDeath(playerid, 1501.739624, -1466.230224, 63.859375, 273.975128);
					}

					if (g_SalaData[salaid][g_JogadoresNesseTime][0] == g_SalaData[salaid][g_MaxPlayerTime][0] && g_SalaData[salaid][g_JogadoresNesseTime][1] == g_SalaData[salaid][g_MaxPlayerTime][1]){
						g_SalaData[salaid][g_MinutosSala] = 1; g_SalaData[salaid][g_SegundosSala] = 59;
						if (g_SalaData[salaid][g_TimerSala] != 0) KillTimer(g_SalaData[salaid][g_TimerSala]);
						g_SalaData[salaid][g_TimerSala] = 0;
						g_SalaData[salaid][g_TimerSala] = SetTimerEx("TempoSala", 1000, true, "d", g_PlayerData[playerid][g_QualSala]);
						SetTimerEx("SetPlayerWeapon", 100, false, "d", g_PlayerData[playerid][g_QualSala]);
					}
				}
			} else {
				if (g_SalaData[salaid][g_QualModo] == 2){
					if (g_SalaData[salaid][g_JogadoresNesseTime][1] < g_SalaData[salaid][g_MaxPlayerTime][1]){
						g_SalaData[salaid][g_JogadoresNesseTime][1] ++;
						g_PlayerData[playerid][g_Qualtime] = TIMEVERMELHO;
						SetPlayerVirtualWorld(playerid, salaid);
						SetPlayerInterior(playerid, 0);
						SetPlayerPos(playerid, 1541.481933, -1466.260253, 63.859375);
						SetPosPlayerDeath(playerid, 1541.481933, -1466.260253, 63.859375, 84.488395);
						SendClientMessage(playerid, -1, "Voce foi setado no time 2");
					}

					if (g_SalaData[salaid][g_JogadoresNesseTime][0] == g_SalaData[salaid][g_MaxPlayerTime][0] && g_SalaData[salaid][g_JogadoresNesseTime][1] == g_SalaData[salaid][g_MaxPlayerTime][1]){
						g_SalaData[salaid][g_MinutosSala] = 1; g_SalaData[salaid][g_SegundosSala] = 59;
						if (g_SalaData[salaid][g_TimerSala] != 0) KillTimer(g_SalaData[salaid][g_TimerSala]);
						g_SalaData[salaid][g_TimerSala] = 0;
						g_SalaData[salaid][g_TimerSala] = SetTimerEx("TempoSala", 1000, true, "d", g_PlayerData[playerid][g_QualSala]);
						SetTimerEx("SetPlayerWeapon", 100, false, "d", g_PlayerData[playerid][g_QualSala]);
					}
				}
			}
		}
		case D_NEWSENHA:{
			if (response){
			    if(strlen(inputtext) >= 5 && strlen(inputtext) <= 20){
			    	g_PlayerData[playerid][g_Salt] = salt();
	                SHA256_PassHash(inputtext, g_PlayerData[playerid][g_Salt], g_PlayerData[playerid][g_Senha], MAX_PASS_LEN);

					digitouSenha[playerid] = true;
		            for(new i = 0; i < strlen(inputtext); i++)
		            {
		                inputtext[i] = '#';
		            }
			        PlayerTextDrawSetString(playerid, Text_LoginPlayer[playerid][29], inputtext);
			    }
			    else {
		    		ShowPlayerDialog(playerid, D_NEWSENHA, DIALOG_STYLE_PASSWORD, "{007DFB}Nova senha login", "Digite sua nova senha abaixo:", "Confirmar", "Cancelar");
			    }
			}
		}
		case D_CODIGO:{
		    if (response){
		        if (strval(inputtext) != g_PlayerData[playerid][g_CodigoR]) {
					ShowPlayerDialog(playerid, D_CODIGO, DIALOG_STYLE_INPUT, "{007DFB}Codigo de recuperacao", "{FF0000}ERRO: O codigo que voce digitou e invalido.\n{FFFFFF}Digite novamente o codigo enviado em sua DM no discord:", "Confirmar", "Cancelar");
		        }
		        else {
		        	new query[150];
		        	g_PlayerData[playerid][g_CodigoR] = 0;
    				mysql_format(DBConn, query, sizeof query, "UPDATE `users` SET `codigodiscord` = '0' WHERE `id` = '%d'", g_PlayerData[playerid][g_AccId]);
    				mysql_query(DBConn, query, false);

    				ShowPlayerDialog(playerid, D_NEWSENHA, DIALOG_STYLE_PASSWORD, "{007DFB}Nova senha login", "Digite sua nova senha abaixo:", "Confirmar", "Cancelar");
		        }
		    }
		}		
    }
	return true;
}

public ClickDynamicPlayerTextdraw(playerid, PlayerText:playertextid){
    if(playertextid == Text_LoginPlayer[playerid][31]) {
        if(check_PlayerhasAccount(playerid)){
	    	ShowPlayerDialog(playerid, D_SENHA, DIALOG_STYLE_PASSWORD, "{858585}Senha Login", "Digite sua senha abaixo:", "Confirmar", "Cancelar");
        }
        else {
 			ShowPlayerDialog(playerid, D_REGISTRO, DIALOG_STYLE_PASSWORD, "{858585}Senha Registro", "Digite sua senha abaixo", "Confirmar", "Cancelar");
        }    
    }
    else if(playertextid == Text_LoginPlayer[playerid][32]){
        if(check_PlayerhasAccount(playerid)){
            if(digitouSenha[playerid] == true){
	            TogglePlayerControllable(playerid, true);
	            TogglePlayerSpectating(playerid, false);

		        LimparChat(playerid, 20);
		        SetPlayerVirtualWorld(playerid, 0);
		        SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][g_Skin], 1643.445800, -2481.078125, 3001.085937+1, 87.933044, 0, 0, 0, 0, 0, 0);
		        SpawnPlayer(playerid);
		        SetPlayerInterior(playerid, 1);
	            Destroy_PlayerLogin(playerid);
			}
            else{
                SendClientMessage(playerid, 0xFF0000AA, "Voce nao digitou a senha para logar");
            }
        }
        else {
            if(digitouSenha[playerid] == true){
	            TogglePlayerControllable(playerid, true);
	            TogglePlayerSpectating(playerid, false);

		        LimparChat(playerid, 20);	
		        SetPlayerVirtualWorld(playerid, 0);
		        g_PlayerData[playerid][g_Skin] = 29;
		        SetSpawnInfo(playerid, NO_TEAM, g_PlayerData[playerid][g_Skin], 1643.445800, -2481.078125, 3001.085937+1, 87.933044, 0, 0, 0, 0, 0, 0);
		        SpawnPlayer(playerid);
		        SetPlayerInterior(playerid, 1);
	            Destroy_PlayerLogin(playerid);

		        //Execultar a criacao da conta
           	 	orm_insert(g_PlayerData[playerid][ormidPlayer], "OnPlayerRegistred", "i", playerid);
            }
            else{
                SendClientMessage(playerid, 0xFF0000AA, "Voce nao digitou a senha para registrar");
            }
        }
    }
    if (playertextid == Text_LoginPlayer[playerid][35]){
    	if (strlen(g_PlayerData[playerid][g_DiscordId]) > 0){
		    if(gettime() < GetPVarInt(playerid, "AntFloodCodigo"))
		        return ShowError(playerid, "AGUARDE 10 SEGUNDOS PARA CLICAR NOVAMENTE!");

    		SendClientMessage(playerid, -1, "{007DFB}VIRIDIAN: {FFFFFF}Aguarde em quando enviamos o codigo em seu discord.");
			SetPVarInt(playerid, "AntFloodCodigo", gettime()+10);

    		new query[167]; g_PlayerData[playerid][g_CodigoR] = GeraCodigo();
    		mysql_format(DBConn, query, sizeof query, "UPDATE `users` SET `recuperacao` ='1', `codigodiscord` ='%d' WHERE `id` = '%d'", g_PlayerData[playerid][g_CodigoR], g_PlayerData[playerid][g_AccId]);
    		mysql_query(DBConn, query, false);

			ShowPlayerDialog(playerid, D_CODIGO, DIALOG_STYLE_INPUT, "{007DFB}Codigo de recuperacao", "Digite o codigo enviado em sua DM no discord:", "Confirmar", "Cancelar");
    	} 
    	else return ShowError(playerid, "VOCE NAO TEM UM DISCORD VINCULADO.");
    }

    //Sala
    if (playertextid == Text_PlayerSala[playerid][12]) {//PUBLICO OU PRIVADO
        ShowPlayerDialog(playerid, D_DIGITARSENHASALA, DIALOG_STYLE_PASSWORD, "SENHA SALA", "Digite abaixo a senha da sua sala caso quira que ela seja privada:", "Confirmar", "Cancelar");
    }
    if (playertextid == Text_PlayerSala[playerid][9]) {//NOME DA SALA
    	ShowPlayerDialog(playerid, D_NOMEDASALA, DIALOG_STYLE_INPUT, "NOME DA SALA", "Digite abaixo a quantidade de jogadores:", "Confirmar", "Cancelar");	
    }
    if (playertextid ==  Text_PlayerSala[playerid][11]) {//MODO DE COMBATE
    	ShowModoCombate(playerid);
    }
    if (playertextid ==  Text_PlayerSala[playerid][14]) {//ARMAS PERMITIDAS
    	ShowArmaSala(playerid);
	}
    if (playertextid == Text_PlayerSala[playerid][16]) {//Fechar
		Destroy_PlayerSala(playerid);
		Criandosala[playerid] = false;
		new dummy2[pSalaData];
    	g_SalaData[playerid] = dummy2;
	}
    if (playertextid == Text_PlayerSala[playerid][17]) {//Criar
    	if (g_SalaData[playerid][g_QualModo] == 0 && g_SalaData[playerid][g_WeaponId] == 0) {
    		return ShowError(playerid, "ADICIONE TODOS OS COMPONETD PARA ESTA CRIANDO SUA SALA.");
    	}
    	Criandosala[playerid] = false;
    	Destroy_PlayerSala(playerid);
    	CriarPlayerSala(playerid);
    }

    //Menu Skin
    if (playertextid == Text_PlayerMenuSkin[playerid][25]) {
    	Destroy_PlayerMenuSala(playerid);
	}
    if (playertextid == Text_PlayerMenuSkin[playerid][27]) {
    	if (currentPage[playerid] >= 16){
    		currentPage[playerid] = 16;
			return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}NAO FOI ENCONTRDA MAIS PAGINA");
    	} else if (currentPage[playerid] < 16) {
    		currentPage[playerid] += 1;
			PlayerTextDrawSetString(playerid, Text_PlayerMenuSkin[playerid][29], va_return("PAGE %d/16", currentPage[playerid]));
	    	ShowSkinPreview(playerid);    		
    		
    	}
	}
    if (playertextid == Text_PlayerMenuSkin[playerid][28]) {
		if (currentPage[playerid] <= 0){
			currentPage[playerid] = 0;
			return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}NAO FOI ENCONTRDA MAIS PAGINA");
	    } else if (currentPage[playerid] > 0) {
			currentPage[playerid] -= 1;
	    	PlayerTextDrawSetString(playerid, Text_PlayerMenuSkin[playerid][29], va_return("PAGE %d/16", currentPage[playerid]));
	    	ShowSkinPreview(playerid);	    	
	    }
    }
    for (new i = 0, previewID = 6; i < SKINS_PER_PAGE && previewID <= 23; i++, previewID++) {
        if (playertextid == Text_PlayerMenuSkin[playerid][previewID]) {
            new startIndex = currentPage[playerid] * SKINS_PER_PAGE;
            if (startIndex + i < MAX_SKINS) {
                new selectedSkin = skinList[startIndex + i];
                
                if (selectedSkin >= 1 && selectedSkin <= 311)
                	SetPlayerSkin(playerid, selectedSkin), SendClientMessage(playerid, -1, "{00FF00}Skin alterada com sucesso.");
                else 
                	return ShowError(playerid, "SKIN INVALIDA.");
                Destroy_PlayerMenuSala(playerid);
            }
            return true;
        }
    }
    return true;
}