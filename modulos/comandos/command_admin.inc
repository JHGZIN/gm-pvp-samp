CMD:aa(playerid, params[]){
	if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

    if (g_PlayerData[playerid][g_Admin] == 1){
	    new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{007DFB}/Jogar {FFFFFF}| Entrar/Sair do modo adm.");
	    strcat(msg2, "\n{007DFB}/Ir {FFFFFF}| Ir Ate Um Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Vperfil {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Ids {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	    strcat(msg2, "\n{007DFB}/Voar {FFFFFF}| Voar Pelo Servidor.");
	    strcat(msg2, "\n{007DFB}/Kick {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	    strcat(msg2, "\n{007DFB}/Lchat {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");

    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos Suporte:", msg2, "OK", "");
    } else if (g_PlayerData[playerid][g_Admin] == 2){
	    new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{007DFB}/Jogar {FFFFFF}| Entrar/Sair do modo adm.");
	    strcat(msg2, "\n{007DFB}/Ir {FFFFFF}| Ir Ate Um Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Trazer {FFFFFF}| Trazer Um Jogador ate Sua Pocisao.");
	    strcat(msg2, "\n{007DFB}/Vperfil {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Ids {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	    strcat(msg2, "\n{007DFB}/Voar {FFFFFF}| Voar Pelo Servidor.");
	    strcat(msg2, "\n{007DFB}/Kick {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	    strcat(msg2, "\n{007DFB}/Lchat {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");
	    strcat(msg2, "\n{007DFB}/Tv {FFFFFF}| Telar/Para de Telar Um Jogador(a)");

    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos Ajudante:", msg2, "OK", "");
    } else if (g_PlayerData[playerid][g_Admin] == 3){
    	new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{007DFB}/Jogar {FFFFFF}| Entrar/Sair do modo adm.");
	    strcat(msg2, "\n{007DFB}/Ir {FFFFFF}| Ir Ate Um Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Trazer {FFFFFF}| Trazer Um Jogador ate Sua Pocisao.");
	    strcat(msg2, "\n{007DFB}/Vperfil {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Ids {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	    strcat(msg2, "\n{007DFB}/Voar {FFFFFF}| Voar Pelo Servidor.");
	    strcat(msg2, "\n{007DFB}/Kick {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	    strcat(msg2, "\n{007DFB}/Lchat {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");
	    strcat(msg2, "\n{007DFB}/Tv {FFFFFF}| Telar/Para de Telar Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Banir {FFFFFF}| Telar/Para de Telar Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Desbanir {FFFFFF}| Telar/Para de Telar Um Jogador(a)");

    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos Administrador:", msg2, "OK", "");
    } else if (g_PlayerData[playerid][g_Admin] == 4){
    	new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{007DFB}/Jogar {FFFFFF}| Entrar/Sair do modo adm.");
	    strcat(msg2, "\n{007DFB}/Ir {FFFFFF}| Ir Ate Um Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Trazer {FFFFFF}| Trazer Um Jogador ate Sua Pocisao.");
	    strcat(msg2, "\n{007DFB}/Vperfil {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Ids {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	    strcat(msg2, "\n{007DFB}/Voar {FFFFFF}| Voar Pelo Servidor.");
	    strcat(msg2, "\n{007DFB}/Kick {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	    strcat(msg2, "\n{007DFB}/Lchat {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");
	    strcat(msg2, "\n{007DFB}/Tv {FFFFFF}| Telar/Para de Telar Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Banir {FFFFFF}| Banir um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Desbanir {FFFFFF}| Desbanir um Jogador(a)");

    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos Fundador:", msg2, "OK", "");
    } else if (g_PlayerData[playerid][g_Admin] == 5){
    	new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{007DFB}/Jogar {FFFFFF}| Entrar/Sair do modo adm.");
	    strcat(msg2, "\n{007DFB}/Ir {FFFFFF}| Ir Ate Um Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Trazer {FFFFFF}| Trazer Um Jogador ate Sua Pocisao.");
	    strcat(msg2, "\n{007DFB}/Vperfil {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	    strcat(msg2, "\n{007DFB}/Ids {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	    strcat(msg2, "\n{007DFB}/Voar {FFFFFF}| Voar Pelo Servidor.");
	    strcat(msg2, "\n{007DFB}/Kick {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	    strcat(msg2, "\n{007DFB}/Lchat {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");
	    strcat(msg2, "\n{007DFB}/Tv {FFFFFF}| Telar/Para de Telar Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Banir {FFFFFF}| Banir um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Desbanir {FFFFFF}| Desbanir um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/SetCoins {FFFFFF}| Setar Coins Em Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/DarVip {FFFFFF}| Setar Um Vip Para Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Rvip {FFFFFF}| Remover Um Vip de Um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/SetYtb {FFFFFF}| Setar Youtube Em um Jogador(a)");
	    strcat(msg2, "\n{007DFB}/Rytb {FFFFFF}| Remover Youtube De Um Jogador(a)");
	    //strcat(msg2, "\n{007DFB}/Skydive {FFFFFF}| SkydrJogador(a)");
	    strcat(msg2, "\n{007DFB}/Kitadmdono {FFFFFF}| Ficar Full No servidor.");

    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos Fundador/Dono:", msg2, "OK", "");
    }
	return true;
}

CMD:ir(playerid, params[]){
    new id, realID;
    if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

    if(sscanf(params, "d", id))
    	return SendClientMessage(playerid, -1, "Modo de usar: /ir [ID do Player]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
    if (realID == playerid)
    	return 1;

    static str[150], Float:Pos[4];
    GetPlayerPos(realID, Pos[0], Pos[1], Pos[2]);
    GetPlayerFacingAngle(realID, Pos[3]);
    SetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    SetPlayerFacingAngle(playerid,Pos[3]+1);

    format(str, sizeof str, "VOCE FOI ATE O(A) JOGADOR(A) %s #%d.", GetPlayerNameEx(realID), id);
    SuccesMsg(playerid, str);

    format(str, sizeof str, "O(A) ADMIN %s #%d FOI ATE SUA POSICAO.", GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId]);
    SuccesMsg(realID, str);
    return 1;
}

CMD:trazer(playerid, params[]){
    new id, realID;
    if(g_PlayerData[playerid][g_Admin] < 2)
    	return PermissionError(playerid);

    if(sscanf(params, "d", id))
    	return SendClientMessage(playerid, -1, "Modo de usar: /trazer [ID do Player]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
    if (realID == playerid)
    	return 1;

    static str[150], Float:Pos[4];
    GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    GetPlayerFacingAngle(realID, Pos[3]);
    SetPlayerPos(realID, Pos[0], Pos[1], Pos[2]);
    SetPlayerFacingAngle(realID,Pos[3]+1);

    format(str, sizeof str, "VOCE TROUXE O(A) JOGADOR(A) %s #%d PARA SUA POSICAO.", GetPlayerNameEx(realID), id);
    SuccesMsg(playerid, str);
    format(str, sizeof str, "O(A) ADMIN %s #%d TROUXE ATE ELE.", GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId]);
    SuccesMsg(realID, str);
    return 1;
}

CMD:vperfil(playerid, params[]){
    new id, realID;
    if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

    if(sscanf(params, "d", id))
    	return SendClientMessage(playerid, -1, "Modo de usar: /vperfil [ID do Player]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
    if (realID == playerid)
    	return 1;

    new msg[999], msg2[999];
    msg2[0] = '\0';
    strcat(msg2, "\n{007DFB}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	format(msg, sizeof(msg), "\n{FFFFFF}Nome: {00FF00}%s", PlayerName(realID));
	strcat(msg2, msg);
	format(msg, sizeof(msg), "\n{FFFFFF}Level: {00FF00}%d", GetPlayerScore(realID));
	strcat(msg2, msg);
    format(msg, sizeof msg, "\n{FFFFFF}Total de kills: {00FF00}%d", g_PlayerData[realID][g_TotalKills]);
	strcat(msg2, msg);
    /*format(msg, sizeof msg, "\n{FFFFFF}Total de mortes: {00FF00}%d", g_PlayerData[playerid][g_TotalMorte]);
	strcat(msg2, msg);*/
	format(msg, sizeof msg, "\n{FFFFFF}Vip: {00FF00}%s", GetNameVip(realID));
	strcat(msg2, msg);
	static tempovip[35]; format(tempovip, sizeof tempovip, g_PlayerData[realID][g_TempoVip]);
    format(msg, sizeof msg, "\n{FFFFFF}Data de expiracao do vip: {00FF00}%s", tempovip);
	strcat(msg2, msg);
	if (g_PlayerData[realID][g_YouTuber] == 0) {
		strcat(msg2, "\n{FFFFFF}Youtuber: {FF0000}Não");
	}  
	else {
		strcat(msg2, "\n{FFFFFF}Youtuber: {00FF00}Sim");
	}
	if (g_PlayerData[realID][g_Admin] == 0) {
		strcat(msg2, "\n{FFFFFF}Admin: {FF0000}Não");
	} 
	else {
		strcat(msg2, "\n{FFFFFF}Admim: {00FF00}Sim");
	}
	strcat(msg2, "\n{FFFFFF}Familia: {FF0000}Undefined");
    strcat(msg2, "\n\n{007DFB}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FAFAFA}Info conta:", msg2, "OK", ##);
	return true;
}

CMD:ids(playerid, params[]){
	if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);
	if(!IsPlayerLogado(playerid))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
	new str[2000], str2[250];
	foreach(new i : Player){
		if(IsPlayerLogado(i)){
			format(str2, sizeof str2, "{FFFFFF}Nome (%s) - ID (%i)\n", GetPlayerNameEx(i), g_PlayerData[i][g_AccId]);
			strcat(str, str2);
		}
	}
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{0080C0}Informacoes:", str, "OK", #);
	return true;
}

CMD:lchat(playerid){
	if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

	for(new i = 0; i < 50; i++){
		SendClientMessageToAll(COR_GERAL, " ");
	}
	return 1;
}

CMD:jogar(playerid){
	new string[129];
	if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

	if(g_PlayerData[playerid][g_AdmJob]) {
		g_PlayerData[playerid][g_AdmJob] = false;
		format(string, sizeof(string), "[Administracao]: %s esta jogando!", PlayerName(playerid));
		SendClientMessageToAll(0xFF00FFAA, string);
		SetPlayerHealth(playerid, 200);
		SetPlayerArmour(playerid, 0.0);
		TirarAureola(playerid);
	}
	else{
		g_PlayerData[playerid][g_AdmJob] = true;
		format(string, sizeof(string), "[Administracao]: %s esta trabalhando!", PlayerName(playerid));
		SendClientMessageToAll(0xFF00FFAA, string);
		SetPlayerHealth(playerid, 999999);
		SetPlayerArmour(playerid, 9999999);
		ColocarAureola(playerid);
		SetPlayerSkin(playerid, 217);
		ResetPlayerWeapons(playerid);
	}
	return true;
}

CMD:setcoins(playerid, params[]){
    new id, valor, realID;
    if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);

    if(sscanf(params, "dd", id, valor))
    	return SendClientMessage(playerid, -1, "Modo de usar: /setcoins [ID do Player] [Valor]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
    if (valor <= 0)
    	g_PlayerData[realID][g_Coins] = 0;
    else if (valor > 0) {
    	g_PlayerData[realID][g_Coins] += valor;
    }

    static str[250];
    format(str, sizeof str, "VOCE SETO %d COINS NO JOGADOR(A) %s.", valor, PlayerName(realID));
	SuccesMsg(playerid, str);

    format(str, sizeof str, "O ADMIN %s SETO %d COINS EM VOCE.", PlayerName(playerid), valor);
	SuccesMsg(realID, str);
    return 1;
}

CMD:darvip(playerid, params[]){
    new id, vipid, dias, realID;
    if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);

    if(sscanf(params, "ddd", id, vipid, dias))
    	return SendClientMessage(playerid, -1, "Modo de usar: /darvip [ID do Player] [Vip Id] [Dias Vip]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
    
    if (vipid < 1 && vipid > 3) 
    	return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Digite o vipid valido.");
    
    DarVIP(realID, dias, vipid);

    static str[250];
    format(str, sizeof str, "VOCE SETO VIP %s NO JOGADOR(A) %s", NomeVip(vipid), PlayerName(realID));
	SuccesMsg(playerid, str);
    return 1;
}

CMD:rvip(playerid, params[]){
	new string[500];
	if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);

	new id, realID, motivo[128];
	if(sscanf(params, "ds[128]", id, motivo))
		return SCM(playerid, MSG_USE, "Modo de usar: /rvip [ID do Player] [Motivo]");
	
	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

	g_PlayerData[realID][g_VIP] = 0;
	g_PlayerData[realID][g_TempoVip] = 0;

	ShowError(realID, "SEU VIP FOI RETIRADO.");

	format(string, sizeof(string), "{00FF00}%s{FF4500} foi retirado de VIP do Servidor pelo admin %s, Motivo: %s", PlayerName(realID), PlayerName(playerid), motivo);
    SendClientMessageToAll(COLOR_REDD, string);

   	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{FF3030}Retirada VIP:", "\n\nSeu VIP foi retirado, caso acha isso errado acesse:\n{FFFFFF}(discord.gg/VIRIDIANpvp)\n\n", "Fechar", "");
	return true;
}

CMD:setytb(playerid, params[]){
	new id, realID;
	if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);

	if(sscanf(params, "d", id))
		return SCM(playerid, MSG_USE, "Modo de usar: /setytb [ID do Player]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	
	if(g_PlayerData[realID][g_YouTuber])
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Este ID ja tem o beneficio de Youtuber.");

	g_PlayerData[realID][g_YouTuber] = 1;
	
    static str[150];
    format(str, sizeof str, "VOCE SETOU O(A) JOGADOR(A) %s #%d COMO YOUTUBER.", GetPlayerNameEx(realID), id);
    SuccesMsg(playerid, str);
    format(str, sizeof str, "O(A) ADMIN %s #%d SETOU VOCE COMO YOUTUBER.", GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId]);
    SuccesMsg(realID, str);
	return 1;
}

CMD:rytb(playerid, params[]){
	new id, realID;
	if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);
	
	if(sscanf(params, "d", id))
		return SCM(playerid, MSG_USE, "Modo de usar: /rytb [ID do Player]");
	
	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	
	if(!g_PlayerData[realID][g_YouTuber])
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Este ID nao tem o beneficio de Youtuber.");
	
	g_PlayerData[realID][g_YouTuber] = 0;

    static str[150];
    format(str, sizeof str, "VOCE REMOVEU O(A) JOGADOR(A) %s #%d DE YOUTUBER.", GetPlayerNameEx(realID), id);
    SuccesMsg(playerid, str);
    format(str, sizeof str, "O(A) ADMIN %s #%d RETIROU VOCE DE YOUTUBER.", GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId]);
    ShowError(realID, str);
	return 1;
}

CMD:cnn2(playerid, result[]){
	if(g_PlayerData[playerid][g_Admin] >= 1){
		if(isnull(result)){
			SendClientMessage(playerid, MSG_USE, "Modo de usar: /cnn2 [Formato ~n~-Novalinha ~r~-vermelho ~g~-verde ~b~-azul ~w~-branco ~y~-amarelo]");
			return 1;
		}
		new string[128];
		format(string, sizeof(string), "~p~%s: ~w~%s",GetPlayerNameEx(playerid),result);
		foreach(Player, i)
		{
			GameTextForPlayer(i, string, 5000, 0);
		}
		return 1;
	}
	else{
		SendClientMessage(playerid, COLOR_GRAD1, "Voce nao e um Admin!");
	}
	return 1;
}

CMD:cnn3(playerid, result[]){
	if(g_PlayerData[playerid][g_Admin] >= 1){
		if(isnull(result)){
			return SendClientMessage(playerid, MSG_USE, "Modo de usar: /cnn2 [Formato ~n~-Novalinha ~r~-vermelho ~g~-verde ~b~-azul ~w~-branco ~y~-amarelo]");
		}
		new string[128];
		format(string, sizeof(string), "~p~%s: ~w~%s",GetPlayerNameEx(playerid),result);
		foreach(Player, i)
		{
			GameTextForPlayer(i, string, 5000, 1);
		}
		return 1;
	}
	else {
		SendClientMessage(playerid, COLOR_GRAD1, "Voce nao e um Admin!");
	}
	return 1;
}

CMD:skydive(playerid, params[]){
	if (g_PlayerData[playerid][g_Admin] < 5)
	{
		SendClientMessage(playerid, COLOR_GRAD1, "Você não esta autorizado a usar este comando!");
	}
	new Float:slx, Float:sly, Float:slz;
	GetPlayerPos(playerid, slx, sly, slz);
	if (IsPlayerConnected(playerid))
	{
		SetPlayerPos(playerid,slx, sly, slz+2500);
		SendClientMessage(playerid, COLOR_REDD, "UUUUP!!!");
	}
	return true;
}

CMD:kitadmdono(playerid, params[]){
	if(g_PlayerData[playerid][g_Admin] < 5)
		return true;

	ResetPlayerWeapons(playerid);
	GivePlayerWeapon(playerid, 46, 1);
	GivePlayerWeapon(playerid, 24, 9999999999);
	GivePlayerWeapon(playerid, 35, 9999999999);
	GivePlayerWeapon(playerid, 31, 9999999999);
	GivePlayerWeapon(playerid, 29, 9999999999);
	GivePlayerWeapon(playerid, 25, 9999999999);
	GivePlayerWeapon(playerid, 4, 1);
	GivePlayerWeapon(playerid, 34, 9999999999);
	GivePlayerWeapon(playerid, 43, 9999999999);
	GivePlayerWeapon(playerid, 16, 9999999999);
	GivePlayerWeapon(playerid, 38, 9999999999);
	SetPlayerArmour(playerid, 100);
	SetPlayerHealth(playerid, 200);

	SuccesMsg(playerid, "VOCE PEFOU KITADMDONO!");
	return 1;
}

CMD:voar(playerid){
     if(g_PlayerData[playerid][g_Admin] < 1){
	      SendClientMessage(playerid, COR_GERAL, MSGERRO);
	      return 1;
	 }
	 if(!g_PlayerData[playerid][g_AdmJob])
	 	return SCM(playerid, COR_GERAL, MSGJOGAR);

	 if(flying[playerid] == false)
	 {
	      flying[playerid] = true;
          StartFly(playerid);
		  format(String, sizeof(String), "AdmCmd: %s ativou o modo voar.", PlayerName(playerid));
	      ABroadCast(COLOR_REDD,String,1);
     }
     else
     {
          flying[playerid] = false;
          StopFly(playerid);
          format(String, sizeof(String), "ADMCMD: %s desativou o modo voar.", PlayerName(playerid));
	      ABroadCast(COLOR_REDD,String,1);
	 }
     return 1;
}

CMD:martelinhoadmin(playerid){
	if(g_PlayerData[playerid][g_Admin] == 5)
	{
		new martelinhomessage[49+MAX_PLAYER_NAME];
		if(UmMartelinho[playerid] == false)
		{
		    UmMartelinho[playerid] = true;
		    SetPlayerAttachedObject(playerid, 9, 18635, 6, -0.211000, -0.093999, 0.000000, 4.699998, 8.100019, -0.500001, 3.759002, 4.369003, 2.290000); //We attach the martelinho object in the player's right hand.
			GivePlayerWeapon(playerid,5,1);
			format(martelinhomessage,sizeof(martelinhomessage),"{FF00FF}O admin %s pegou seu martelinho admin.",PlayerName(playerid));
			SendClientMessageToAll(-1, martelinhomessage);
		}
		else
		{
		    UmMartelinho[playerid] = false;
	     	RemovePlayerAttachedObject(playerid, 9);
	     	format(martelinhomessage,sizeof(martelinhomessage),"{FF00FF}O admin %s guardou seu martelinho admin",PlayerName(playerid));
			SendClientMessageToAll(-1,martelinhomessage);
		}
	}
	return 1;
}

CMD:av(playerid, result[]){
	new string[1000];
	if(IsPlayerConnected(playerid))
	{
		if(isnull(result))
		{
			SendClientMessage(playerid, MSG_USE, "Modo de usar: /av [Texto]");
			return 1;
		}
		if(g_PlayerData[playerid][g_Admin] >= 1)
		{
			new lolz[25];
			if(g_PlayerData[playerid][g_Admin] == 1)lolz = "{00FF00}Suporte";
			if(g_PlayerData[playerid][g_Admin] == 2)lolz = "{FFFF00}Ajudante";
			if(g_PlayerData[playerid][g_Admin] == 3)lolz = "{ADFF2F}Administrador";
			if(g_PlayerData[playerid][g_Admin] == 5)lolz = "{FF0000}Fundador";

			format(string, sizeof(string), "{FF00FF}x ~~~~~~~~~~~~~~~~ x {FFFFFF}Aviso Administrativo {FF00FF}x ~~~~~~~~~~~~~~~~ x ", g_PlayerData[playerid][g_Admin], lolz, PlayerName(playerid), result);
			SendClientMessageToAll(COLOR_REDD, string);
			format(string, sizeof(string), "%s, {FF00FF}%s: {FFFFFF}%s", lolz, PlayerName(playerid), result);
			SendClientMessageToAll(COLOR_REDD, string);
		}
	}
	return 1;
}

CMD:tv(playerid,params[]){
    new id, realID;
    if(g_PlayerData[playerid][g_Admin] < 2)
    	return SendClientMessage(playerid, -1, MSGERRO);

    if(!g_PlayerData[playerid][g_AdmJob])
    	return SCM(playerid, COLOR_REDD, MSGJOGAR);

    if(sscanf(params, "d", id))
    	return SendClientMessage(playerid, MSG_USE, "Modo de usar: /tv [ID do Player]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

    if(realID == playerid)
    	return SendClientMessage(playerid, COR_GERAL, "[ERRO]: voce nao se assistir!");

    static str[96]; 
    format(str, sizeof str, "VOCE ESTA TELANDO O JOGADOR %s #%d", GetPlayerNameEx(realID), g_PlayerData[realID][g_AccId]);
   	ShowInfo(playerid, str);

	TogglePlayerSpectating(playerid, 1);
	if (IsPlayerInAnyVehicle(realID))
		PlayerSpectatePlayer(playerid, realID);
	else
		//PlayerSpectatePlayer(playerid, realID);
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(realID));
	GameTextForPlayer(playerid, "~r~Tv~n~~w~ON", 5000, 3);
	return 1;
}

CMD:tvoff(playerid,params[]){
    if(!IsPlayerAdmin(playerid) && g_PlayerData[playerid][g_Admin] < 2)
    	return SendClientMessage(playerid, -1, MSGERRO);

    if(!g_PlayerData[playerid][g_AdmJob])
    	return SCM(playerid, COLOR_REDD, MSGJOGAR);

    TogglePlayerSpectating(playerid, 0);
    if (IsPlayerInAnyVehicle(playerid))
		PlayerSpectatePlayer(playerid, playerid);
	else
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(playerid));
	GameTextForPlayer(playerid, "~r~Tv~n~~w~OFF", 5000, 3);
	return 1;
}

CMD:a(playerid, result[]){
	new gstring[1000];
	if(IsPlayerConnected(playerid))
	{
		if(isnull(result))
		{
			SendClientMessage(playerid, MSG_USE, "Modo de usar: (/a)dmin [chat administracao]");
			return 1;
		}
		if (g_PlayerData[playerid][g_Admin] >= 1)
		{
			new lolz[25];
			if(g_PlayerData[playerid][g_Admin] == 1)lolz = "{00FF00}Suporte";
			if(g_PlayerData[playerid][g_Admin] == 2)lolz = "{FFFF00}Ajudante";
			if(g_PlayerData[playerid][g_Admin] == 3)lolz = "{ADFF2F}Administrador";
			if(g_PlayerData[playerid][g_Admin] == 5)lolz = "{FF0000}Fundador";

			format(gstring, sizeof(gstring), "{FF00FF}*%d* [%s{FF00FF}]: %s: %s", g_PlayerData[playerid][g_Admin], lolz, PlayerName(playerid), result);
			ABroadCast(COLOR_REDD, gstring, 1);// Chat dos Administradores
		}
	}
	return 1;
}

CMD:daradmin(playerid, params[]){
    new id, nivel, realID, string[250];
    if(g_PlayerData[playerid][g_Admin] <= 0)
    	return PermissionError(playerid);
		
	if(sscanf(params, "dd", id, nivel))
    	return SendClientMessage(playerid, -1, "Modo de usar: /dardmin [ID do Player] [Nivel]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

    if (realID == playerid)
    	return ShowError(playerid, "VOCE NAO PODE SETA ADMIN EM VOCE MESMO!");
    if(nivel < 0 && nivel  > 5)
    	return SendClientMessage(playerid, COLOR_REDD, "[ERRO]:{FFFFFF} Voce nao pode criar admin maior que ( 5 )");

    g_PlayerData[realID][g_Admin] = nivel;
    
    format(string, sizeof(string), "VOCE SETOU O(A) JOGADOR %s #%d COM NIVEL %d DE ADMIN.", PlayerName(playerid), g_PlayerData[playerid][g_AccId], nivel);
    SuccesMsg(playerid, string);
    format(string, sizeof(string), "O(A) ADMIN %s #%d SETOU VOCE COM NIVEL %d DE ADMIN.", PlayerName(playerid), g_PlayerData[playerid][g_AccId], nivel);
    SuccesMsg(realID, string);
    return 1;
}

CMD:radmin(playerid, params[]){
    new id, realID, Motivo[128], string[250];

    if(sscanf(params, "ds[128]", id, Motivo))
    	return SendClientMessage(playerid, -1, "Modo de usar: /retiraradmin [ID do Player] [Motivo]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

    g_PlayerData[realID][g_Admin] = 0;

    format(string, sizeof(string), "[Limpar Admin]: %s limpou o admin do (%s), Motivo: %s", PlayerName(playerid), PlayerName(id), Motivo);
    SendClientMessageToAll(COLOR_REDD, string);
    return 1;
}

CMD:kick(playerid, params[]){
	new string[125];
    if(g_PlayerData[playerid][g_Admin] < 1)
    	return PermissionError(playerid);

    new id, realID, Motivo[125];
    if(sscanf(params, "ds[125]", id, Motivo))
    	return SCM(playerid, MSG_USE, "Modo de usar: /kick [ID] x [Motivo]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

	if(strlen(Motivo) > 24)
		return SCM(playerid, COLOR_REDD, "Texto muito grande!");

    format(string, sizeof(string), "[ VIRIDIAN PvP ]:{FFFFFF} O admin %s kickou o jogador %s do servidor, Motivo: %s", PlayerName(playerid), PlayerName(realID), Motivo);
    SendClientMessageToAll(COLOR_REDD, string);
    SetTimerEx("KickPlayer", 1000, false, "i", id);
    return true;
}

CMD:matar(playerid, params[]){
	if (g_PlayerData[playerid][g_Admin] < 5)
		return PermissionError(playerid);
    new id, realID;
    if(sscanf(params, "d", id))
    	return SCM(playerid, MSG_USE, "Modo de usar: /matar [ID]");

	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
    	return ShowError(playerid, "PLAYERID OFFLINE!");

	SetPlayerHealth(realID, 0.0);

	SuccesMsg(playerid, "VOCE MATOU O JOGADORID COM SUCESSO.");
	return true;
}

CMD:banidos(playerid, params[]){
	if (g_PlayerData[playerid][g_Admin] < 3)
		return PermissionError(playerid);
	if(!IsPlayerLogado(playerid))
		return ShowError(playerid, "PLAYERID OFFLINE!");
	mysql_tquery(DBConn, "SELECT `id`, `data_banned`, `motivo`, `admin` FROM `tablebanned`;", "SelectBanneds", "i", playerid);
	return true;
}

function SelectBanneds(playerid){
	if(cache_num_rows()){
		new id, data_banned, motivo[16], adm[MAX_PLAYER_NAME + 1], string[2056];
		strcat(string, "{FFFFFF}ID\t{FFFFFF}Data\t{FFFFFF}Motivo\t{FFFFFF}Admin\n");
		for(new i; i < cache_num_rows(); i++){
			cache_get_value_name(i, "motivo", motivo);
			cache_get_value_name(i, "admin", adm);
			cache_get_value_int(i, "id", id);
			cache_get_value_int(i, "data_banned", data_banned);
			strcat(string, va_return("%i\t{FF0000}%s\t%s\t%s\n", id, convert_tstamp(data_banned), motivo, adm));
		}
		ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_TABLIST_HEADERS, "{007DFB}Banidos:", string, "Fechar", #);
	}
	else{
		ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_TABLIST_HEADERS, "{007DFB}Banidos:", "{FFFFFF}Sem resultados ate o momento.", "Fechar", #);
	}
	return true;
}

CMD:banir(playerid, params[]){
	if (g_PlayerData[playerid][g_Admin] < 3)
		return PermissionError(playerid);
	new id, realID, motivo[15], ip[17];
	if(g_PlayerData[playerid][g_Admin] < 4)
		return ShowError(playerid, "COMANDO INVALIDO");
	if(sscanf(params, "ds[15]", id, motivo))
		return ShowInfo(playerid, "USE: /BANIR [ID][MOTIVO]");
	realID = GetRealID(id);
	if(strlen(motivo) < 1 || strlen(motivo) > 15)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}O motivo precisa ter de 1 a 15 caracteres");
	if(!IsPlayerConnected(realID))
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}ID inativo. Use: '/agendarban'");
	if(!IsPlayerLogado(playerid))
		return ShowError(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
		return ShowError(playerid, "PLAYERID OFFLINE!");
	if(realID == playerid) 
		return ShowError(playerid, "VOCE NAO PODE BANIR VOCE MESMO!");
	GetPlayerIp(realID, ip, 16);
	new str[250];
	format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) foi banido do servidor, motivo (%s).", GetPlayerNameEx(realID), motivo);
	SendMessageToPlayersLogados(str);
	SetTimerEx("KickPlayer", 500, false, "i", realID);
	new query[500]; mysql_format(DBConn, query, sizeof query, "INSERT INTO `tablebanned` (`id`, `data_banned`, `motivo`, `admin`, `ip`) VALUES ('%d', '%d','%s', '%s', '%s');", id, gettime(), motivo, GetPlayerNameEx(playerid), ip);
	mysql_query(DBConn, query, false);
	return true;
}

CMD:agendarban(playerid, params[]){
    new id, motivo[15];
	if (g_PlayerData[playerid][g_Admin] < 3)
		return PermissionError(playerid);
	if(sscanf(params, "ds[15]", id, motivo))
		return ShowInfo(playerid, "USE: /AGENDARBAN [ID] [MOTIVO]");
	if(strlen(motivo) < 1 || strlen(motivo) > 15)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}O motivo precisa ter de 1 a 15 caracteres");
	if(IsPlayerConnected(GetRealID(id)))
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}ID ativo. Use: '/banir'");
	if(!IsPlayerLogado(playerid))
		return ShowError(playerid, "PLAYERID OFFLINE!");
	mysql_tquery(DBConn, va_return("SELECT * FROM `users` WHERE `id` = '%d';", id), "SelectUserForBanAgendate", "iis", playerid, id, motivo);
	return true;
}

function SelectUserForBanAgendate(playerid, id, const motivo[]){
	if(!cache_num_rows())
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Nao existe nenhuma conta com este ID!");

	new name[25];
	cache_get_value_name(0, "nome", name);
	mysql_tquery(DBConn, va_return("SELECT * FROM `tablebanned` WHERE `id` = '%d';", id), "SelectBanForBan", "iiss", playerid, id, motivo, name);
	return true;
}

function SelectBanForBan(playerid, id, const motivo[], const name[]){
	if(!cache_num_rows()){
		new query[450], str[250];
		mysql_format(DBConn, query, sizeof query, "INSERT INTO `tablebanned` (`id`, `data_banned`, `motivo`, `admin`) VALUES ('%d', '%d', '%s', '%s');", id, gettime(), motivo, GetPlayerNameEx(playerid));
		mysql_query(DBConn, query, false);
		format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) foi banido do servidor pelo admin (%s), motivo (%s).", name, GetPlayerNameEx(playerid), motivo);
		SendMessageToPlayersLogados(str);
	}
	else{
		SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Esta conta ja esta banida!");
		return true;
	}
	return true;
}

CMD:desbanir(playerid, params[]){
	new id, realID;
	if (g_PlayerData[playerid][g_Admin] < 3)
		return PermissionError(playerid);
	if(sscanf(params, "d", id))
		return ShowInfo(playerid, "USE: /DESBAN [id]");
	if(!IsPlayerLogado(playerid))
		return ShowError(playerid, "PLAYERID OFFLINE!");
	realID = GetRealID(id);
	mysql_tquery(DBConn, va_return("SELECT * FROM `tablebanned` WHERE `id` = '%d';", id), "SelectBanForDesban", "iii", playerid, id, realID);
	return true;
}

function SelectBanForDesban(playerid, id, realID){
	if(!cache_num_rows())
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Esta conta nao esta banida.");
	mysql_query(DBConn, va_return("DELETE FROM `tablebanned` WHERE `id`= '%d';", id), false);
	va_SendClientMessage(playerid, -1, "{007DFB}VIRIDIAN: {FFFFFF}A conta ID: (%i) foi desbanida por voce.", id);
	if(IsPlayerConnected(realID)){
		SendClientMessage(realID, -1, "{007DFB}VIRIDIAN: {FFFFFF}Sua conta foi desbanida, relogue.");
		SetTimerEx("KickPlayer", 500, false, "i", realID);
	}
	return true;
}

CMD:setaviso(playerid, params[]){
	new id, realID, quantidade, motivo[15], ip[17], query[220];
	if (g_PlayerData[playerid][g_Admin] < 2)
		return PermissionError(playerid);
	if(sscanf(params, "dds[15]", id, quantidade, motivo))
		return ShowInfo(playerid, "USE: /SETAVISO [ID][QUANTIDADE][MOTIVO]");
	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}ID Inativo. '/agendaraviso'");
	if(!IsPlayerLogado(realID))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	if(quantidade < 1 || quantidade > 3)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}A quantidade precisa ser de 1 a 3.");
	if(strlen(motivo) < 1 || strlen(motivo) > 15)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}O motivo precisa ter de 1 a 15 caracteres");
	if(!IsPlayerLogado(playerid))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	g_PlayerData[realID][g_Avisos] += quantidade;
	if(g_PlayerData[realID][g_Avisos] > 3)
		g_PlayerData[realID][g_Avisos] = 3;
	new str[250];
	format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) levou (%d) aviso(s) do admin (%s), motivo: (%s)", GetPlayerNameEx(realID), quantidade, GetPlayerNameEx(playerid), motivo, g_PlayerData[realID][g_Avisos]);
	SendMessageToPlayersLogados(str);
	if(g_PlayerData[realID][g_Avisos] == 3){
		GetPlayerIp(realID, ip, 17);
		format(query, sizeof query, "INSERT INTO `tablebanned` (`id`, `data_banned`, `motivo`, `admin`, `ip`) VALUES ('%i', '%i', '3/3', 'Carl Johnson', '%s');", id, gettime(), ip);
		mysql_query(DBConn, query, false);
	
	 	format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) foi banido do servidor, motivo: (3/3 avisos).", GetPlayerNameEx(realID));
		SendMessageToPlayersLogados(str);
		g_PlayerData[realID][g_Avisos] = 0;
		SetTimerEx("KickPlayer", 500, false, "i", realID);
	}
	return 1;
}

CMD:agendaraviso(playerid, params[]){
	new id, quantidade, motivo[15];
	if (g_PlayerData[playerid][g_Admin] < 2)
		return PermissionError(playerid);
	if(sscanf(params, "dds[15]", id, quantidade, motivo))
		return ShowInfo(playerid, "USE: /AGENDARAVISO [ID][QUANTIDAE][MOTIVO]");
	if(!IsPlayerLogado(playerid))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	if(IsPlayerConnected(GetRealID(id)))
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}ID Ativo. Use '/setaviso'");
	if(quantidade > 3 || quantidade < 1)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}A quantidade precisa ser de 1 a 3.");
	if(strlen(motivo) < 1 || strlen(motivo) > 15)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}O motivo precisa ter de 1 a 15 caracteres");
	mysql_tquery(DBConn, va_return("SELECT * FROM `Player` WHERE `id` = '%d';", id), "SelectForAgendaWarning", "iiis", playerid, id, quantidade, motivo);
	return 1;
}

function SelectForAgendaWarning(playerid, id, quantidade, const motivo[]){
	if(!cache_num_rows())
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Nao existe nenhuma conta com este ID!");
	new nome[25], avisos;
	cache_get_value_name(0, "nome", nome);
	cache_get_value_int(0, "avisos", avisos);
	mysql_tquery(DBConn, va_return("SELECT * FROM `tablebanned` WHERE `id` = '%d';", id), "SelectBanForWarning", "iiiiss", playerid, id, quantidade, avisos, motivo, nome);
	return 1;
}

function SelectBanForWarning(playerid, id, quantidade, avisos, const motivo[], const nome[]){
	if(cache_num_rows())
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Este player nao pode levar avisos pois esta banido!");
	avisos += quantidade;
	if(avisos > 3){
		avisos = 3;
	}
	new str[250];
	format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) levou (%i) avisos do admin (%s), motivo: (%s)", nome, quantidade, GetPlayerNameEx(playerid), motivo);
	SendMessageToPlayersLogados(str);
	if(avisos == 3){
		new query[220];
		avisos = 0;
		format(query, sizeof query, "INSERT INTO `tablebanned` (`id`, `data_banned`, `motivo`, `admin`) VALUES ('%i', '%i', '3/3', 'Carl Johnson');", id, gettime());
		mysql_query(DBConn, query, false);
		format(query, sizeof query, "UPDATE `users` SET `avisos` = '%i', `aviso_agendado` = '0', `motivo_aviso` = ' ' WHERE `id` = '%d';", avisos, id);
		mysql_query(DBConn, query, false);
		format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) foi banido do servidor, motivo: (3/3).", nome);
		SendMessageToPlayersLogados(str);
	}
	new query[250];
	format(query, sizeof query, "UPDATE `users` SET `avisos` = '%i', `aviso_agendado` = '1', `motivo_aviso` = '%s' WHERE `id` = '%i';", avisos, motivo, id); 
	mysql_query(DBConn, query, false);
	return 1;
}

CMD:limparaviso(playerid, params[]){
	new id, realID, quantidade;
	if (g_PlayerData[playerid][g_Admin] < 2)
		return PermissionError(playerid);
	if(sscanf(params, "dd", id, quantidade))
		return ShowInfo(playerid, "USE: /LIMPARAVISO [ID] [QUANTIDADE]");
	realID = GetRealID(id);
	if(!IsPlayerConnected(realID))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(realID))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	if(!IsPlayerLogado(playerid))
		return ShowInfo(playerid, "PLAYERID OFFLINE!");
	if(quantidade < 1 || quantidade > 2)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}A quantidade precisa ser de 1 a 2.");
	if(g_PlayerData[realID][g_Avisos] == 0)
		return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Este player nao tem avisos para ser limpo.");
	g_PlayerData[realID][g_Avisos] -= quantidade;
	if(g_PlayerData[realID][g_Avisos] < 0)
		g_PlayerData[realID][g_Avisos] = 0;
	new str[250];
	format(str, sizeof str, "{007DFB}VIRIDIAN: {FFFFFF}(%s) teve (%i) avisos limpos pelo admin (%s)", GetPlayerNameEx(realID), quantidade, GetPlayerNameEx(playerid));
	SendMessageToPlayersLogados(str);
	return 1;
}