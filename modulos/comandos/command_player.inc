CMD:tp(playerid){
    new msg2[999];
    msg2[0] = '\0';

    strcat(msg2, "{FFFFFF}Teleportar para LS.");
    strcat(msg2, "{FFFFFF}Teleportar para LV.");
    strcat(msg2, "{FFFFFF}Teleportar para SF.");
    strcat(msg2, "{FFFFFF}Teleportar para Grove.");
    ShowPlayerDialog(playerid, D_TELEPORTE, DIALOG_STYLE_LIST, "{FAFAFA}Teleportes:", msg2, "Teleportsr", "Cancelar");
    return true;
}

CMD:vips(playerid, params[]){
	MEGAString[0] = EOS;
	strcat(MEGAString, "{FFF68F}* Beneficio VIP NORMAL\n", 4500);
	strcat(MEGAString, "{00FF00}>{FFFFFF} /v {858585}> Falar no (Chat VIP)\n", 4500);
	strcat(MEGAString, "{FF00FF}>{FFFFFF} /jetpack {858585}> Pegar seu (Jet-Pack)\n", 4500);
	strcat(MEGAString, "{FF00FF}>{FFFFFF} /vida {858585}> Recupera toda a sua vida\n\n", 4500);

	strcat(MEGAString, "{FFF68F}* Beneficio {FF00FF}VIP RUBI\n", 4500);
	strcat(MEGAString, "{FF00FF}>{FFFFFF} /v {858585}> Falar no (Chat VIP)\n", 4500);
	strcat(MEGAString, "{FF00FF}>{FFFFFF} /car {858585}> Criar qual quer veiculo no Servidor\n", 4500);
	strcat(MEGAString, "{FF00FF}>{FFFFFF} Direito a teleportar clicando no mapa\n\n", 4500);

	strcat(MEGAString, "{FFF68F}* Beneficio {FF0000}VIP GOLDEN\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /v {858585}> Falar no (Chat VIP)\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /jetpack {858585}> Pegar seu (Jet-Pack)\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /car {858585}> Criar qual quer veiculo no Servidor\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /brinquedos {858585}> Pegar qual quer acessorio no servidor\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /efeitos {858585}> Pegar qual quer efeito no servidor\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} /cor {858585}> Mudar a cor do seu NICK\n\n", 4500);

	strcat(MEGAString, "{FFF68F}* Outros Beneficios {FF0000}VIP GOLDEN\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Destaque em atendimento\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Disponivel ter Tag em nosso Forum\n", 4500);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Destaque ao Falar no CHAT LOCAL\n", 4500);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{858585}Beneficios VIP:", MEGAString, "Informado", "");
	return true;
}

CMD:admins(playerid, params[]){
	new Cont = 0;
	MEGAString[0] = EOS;
	new string[500];
	foreach(Player, i)
	{
		if(g_PlayerData[i][g_Admin] > 0)
		{
			if(g_PlayerData[i][g_AdmJob])
			{
				format(string, sizeof(string), "%s\t\t (%d)\t\t {00FF00}Trabalhando\n", GetPlayerNameEx(playerid), g_PlayerData[i][g_Admin]);
				strcat(MEGAString, string);
				Cont++;
			}
			else
			{
				format(string, sizeof(string), "%s\t\t (%d)\t\t {FF0000}Jogando\n", GetPlayerNameEx(playerid), g_PlayerData[i][g_Admin]);
				strcat(MEGAString, string);
				Cont++;
			}
		}
		if(Cont == 0)
		{
			ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{00FF00}Administradores Offline", "\n\n{FFFF00}Nenhum {FF00FF}Admin{FFFF00} Online no momento\n{FFFF00}Acesse: (discord.gg/VIRIDIANpvp)\n\n", "Informado", "");
		}
		else
		{
			new titulo[128];
			format(titulo, sizeof(titulo), "Administradores Online {00FF00}(%d)", Cont);
			ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, titulo, MEGAString, "Informado", "");
		}
	}
	return 1;
}

CMD:efeitos(playerid){
	MEGAString[0] = EOS;
	strcat(MEGAString, "{FF0000}>{FFFFFF} Fogo na Skin {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Explos> Aquatica {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Neve {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Pedras {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Caveira {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Colete {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Fuma> {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Touca de Natal {FF3030}Slot 1\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Caveira e Fogo {FF3030}Slot 1 e 2\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Colete e Fuma> {FF3030}Slot 1 e 2\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Pedras e Explos> Aquatica {FF3030}Slot 1 e 2\n", 800);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Touca de Natal e Neve {FF3030}Slot 1 e 2\n", 800);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{858585}Efeitos:", MEGAString, "Usar", "Fechar");
	return 1;
}

CMD:brinquedos(playerid){
	MEGAString[0] = EOS;
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> de Bombeiro {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> de Policial {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> Michael Jackson {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> Oper>io {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> de Funkeiro {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> de Veio {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chap> do Harry Potter {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Bolsa de sequestrador {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Fones de ouvido {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Loro Jos> Gigante {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Loro Jos> menor (Ombro) {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Tapa olho de pirata {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Dildo {FF3030}Slot 2\n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Cabe> de galo {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Cabe> de galo gigante Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Cervo {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chifre de boi 1 {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Chifre de boi 2 {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Fanstasia de ob>ora {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Cabe>o do CJ {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Golfinho {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Tubar> {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Fantasia de tartaruga {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Vaca {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Colete no corpo {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Cora>o no peito {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} C4 nas costas {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} M4 nas costas  {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Bazzuka nas costas  {FF3030}Slot 2 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Toca do Papai Noel  {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} Dado na cabe>  {FF3030}Slot 1 \n", 1700);
	strcat(MEGAString, "{FF0000}>{FFFFFF} C4 no peito  {FF3030}Slot 2 \n", 1700);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, "{858585}Brinquedos:", MEGAString, "Usar", "Fechar");
	return 1;
}

CMD:tbrinquedos(playerid){
	for(new i = 0; i < 10; i++){
		if(IsPlayerAttachedObjectSlotUsed(playerid, i)){
			RemovePlayerAttachedObject(playerid, i);
		}
	}
	SendClientMessage(playerid, COLOR_REDD, "Brinquedos removidos com sucesso!");
	return 1;
}

CMD:tfeitos(playerid){
	RemovePlayerAttachedObject(playerid, 1);
	RemovePlayerAttachedObject(playerid, 2);
	SendClientMessage(playerid, COLOR_REDD, "Efeitos removidos com sucesso!");
}

CMD:skin(playerid, params[]){
	Create_TextPlayerMenuSkin(playerid);
	return 1;
}

CMD:creditos(playerid){
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Creditos:", DIALOG_CREDITOS, "OK", #);
	return true;
}

CMD:regras(playerid){
	MEGAString[0] = EOS;
	strcat(MEGAString, "{FFF68F}Regras VIRIDIAN PvP:\n");
	strcat(MEGAString, "{FFFFFF}1 - Proibido Auto C-BUG e C-BUG\n");
	strcat(MEGAString, "{FFFFFF}2 - Proibido SK (Spawn Kill) em Arenas\n");
	strcat(MEGAString, "{FFFFFF}3 - Proibido Atrapalhar PvP, Apenas em Arenas sao permitido o PvP Total de Todos\n");
	strcat(MEGAString, "{FFFFFF}4 - Proibido Atrapalhar acoes organizadas de proposito - ATP\n");
	strcat(MEGAString, "{FFFFFF}5 - Proibido uso de hack's\n");
	strcat(MEGAString, "{FFFFFF}6 - Proibido qualquer desrespeito a qualquer caracteristicas de membros\n");

	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "Regras", MEGAString, "Informado", "");
	return true;
}

CMD:mundos(playerid) {
    new msg[999], msg2[999];

    strcat(msg2, "Mundos\t\tJogadores\n");
    format(msg, sizeof msg, "[1] Fugas:\t\t%d\n", JogadoresMundo[0]);
    strcat(msg2, msg);
    format(msg, sizeof msg, "[2] Desce e Quebra:\t\t%d\n", JogadoresMundo[1]);
    strcat(msg2, msg);
    format(msg, sizeof msg, "[3] Mata-Mata:\t\t%d\n", JogadoresMundo[2]);
    strcat(msg2, msg);

    ShowPlayerDialog(playerid, D_ENTRARMUNDO, DIALOG_STYLE_TABLIST_HEADERS, "MUNDOS VIRIDIAN:", msg2, "Entrar", "Voltar");
	return true;
}

CMD:arena(playerid){
    new msg[999], msg2[999];

    strcat(msg2, "Arenas\tArmas\tJogadores\n");
    format(msg, sizeof msg, "[1] Arena M4:\tM4\t%d\n", JogadoresArena[0]);
    strcat(msg2, msg);
    /*format(msg, sizeof msg, "[2] Sniper:\tSniper\t%d\n", JogadoresArena[1]);
    strcat(msg2, msg);*/
    format(msg, sizeof msg, "[2] Ammunation:\tDesert\t%d\n", JogadoresArena[2]);
    strcat(msg2, msg);
    format(msg, sizeof msg, "[3] Predio:\tDesert\t%d", JogadoresArena[3]);
    strcat(msg2, msg);

    ShowPlayerDialog(playerid, D_ENTRARARENA, DIALOG_STYLE_TABLIST_HEADERS, "ARENAS VIRIDIAN:", msg2, "Entrar", "Voltar");
    return true;
}

CMD:sair(playerid) {
	RemovePlayerSala(playerid);
	return true;
}

CMD:car(playerid, params[]) return callcmd::veh(playerid, params);
CMD:veh(playerid, params[]){
    new Float:x, Float:y, Float:z, Float:a, input[15];

    if (!g_PlayerData[playerid][g_EmMundo][0])
    	return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}Voce nao esta no mundo fuga.");

    if (sscanf(params, "s[15]", input))
        return SendClientMessage(playerid, -1, "USE: /veh [NOME OU ID DO VEICULO]");

    if (strlen(input) < 1 || strlen(input) > 15)
        return SendClientMessage(playerid, -1, "O NOME OU ID DO VEICULO DEVE TER ENTRE 1 E 15 CARACTERES!");

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    new vehicleId = -1;
    new vehicleName[32];
    
    if (IsNumeric(input)) {
        vehicleId = strval(input);

        if (vehicleId < 400 || vehicleId > 611)
            return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}ID do veiculo invalido.");

        format(vehicleName, sizeof(vehicleName), "%s", VehicleNames[vehicleId - 400][VehicleName]);
    } else {
        for (new i; i < sizeof(VehicleNames); i++) {
            if (strfind(VehicleNames[i][VehicleName], input, true) != -1) {
                vehicleId = 400 + i;
                format(vehicleName, sizeof(vehicleName), "%s", VehicleNames[i][VehicleName]);
                break;
            }
        }

        if (vehicleId == -1)
            return SendClientMessage(playerid, -1, "{FF0000}ERRO: {FFFFFF}veiculo nao encontrado. Verifique se digitou o nome corretamente.");
    }

    if (g_PlayerData[playerid][g_VehicleId] != 0)
        DestroyVehicle(g_PlayerData[playerid][g_VehicleId]);

    g_PlayerData[playerid][g_VehicleId] = CreateVehicle(vehicleId, x, y, z+1, a, 135, 135, 0);

    if (g_PlayerData[playerid][g_VehicleId] == INVALID_VEHICLE_ID)
        return SendClientMessage(playerid, -1,  "ERRO AO CRIAR O VEICULO. ID INVALIDO!");

   	static str[250];
   	format(str, sizeof str, "VIRIDIAN: {FFFFFF}Voce spawnou um veiculo %s", vehicleName);
   	SendClientMessage(playerid, -1, str);

    SetVehicleParamsEx(g_PlayerData[playerid][g_VehicleId], VEHICLE_PARAMS_ON, 1, 0, 0, 0, 0, 0);
    PutPlayerInVehicle(playerid, g_PlayerData[playerid][g_VehicleId], 0);
    return 1;
}

CMD:loja(playerid){
    ShowPlayerDialog(playerid, D_LOJACOIN, DIALOG_STYLE_TABLIST, va_return("{007DFB}Loja: {007DFB}%ic", g_PlayerData[playerid][g_Coins]), DIALOG_LOJACOIN, "Selecionar", "Voltar");
	return true;
}

CMD:perfil(playerid){
    new msg[999], msg2[999];
    msg2[0] = '\0';
    strcat(msg2, "\n{007DFB}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	format(msg, sizeof(msg), "\n{FFFFFF}Nome: {00FF00}%s", PlayerName(playerid));
	strcat(msg2, msg);
	format(msg, sizeof(msg), "\n{FFFFFF}Level: {00FF00}%d", GetPlayerScore(playerid));
	strcat(msg2, msg);
    format(msg, sizeof msg, "\n{FFFFFF}Total de kills: {00FF00}%d", g_PlayerData[playerid][g_TotalKills]);
	strcat(msg2, msg);
    /*format(msg, sizeof msg, "\n{FFFFFF}Total de mortes: {00FF00}%d", g_PlayerData[playerid][g_TotalMorte]);
	strcat(msg2, msg);*/
	format(msg, sizeof msg, "\n{FFFFFF}Vip: {00FF00}%s", GetNameVip(playerid));
	strcat(msg2, msg);
	static tempovip[35]; format(tempovip, sizeof tempovip, g_PlayerData[playerid][g_TempoVip]);
    format(msg, sizeof msg, "\n{FFFFFF}Data de expiracao do vip: {00FF00}%s", tempovip);
	strcat(msg2, msg);
	if (g_PlayerData[playerid][g_YouTuber] == 0) {
		strcat(msg2, "\n{FFFFFF}Youtuber: {FF0000}Não");
	} 
	else {
		strcat(msg2, "\n{FFFFFF}Youtuber: {00FF00}Sim");
	}
	if (g_PlayerData[playerid][g_Admin] == 0) {
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

CMD:topkills(playerid){
	new players_Data[MAX_PLAYERS][2], tempVar, i, j, k;
	for(i = 0, j = MAX_PLAYERS; i < j; ++i)
	{
		if(IsPlayerConnected(i) && IsPlayerLogado(playerid))
		{
		    players_Data[tempVar][0] = g_PlayerData[i][g_TotalKills];
			players_Data[tempVar++][1] = i;
		}
	}
	for(i = 0, j = 0; i < tempVar; ++i)
	{
		j = players_Data[i][0];

		for(k = i - 1; k > -1; --k)
		{
			if(j > players_Data[k][0])
			{
				players_Data[k][0] ^= players_Data[k + 1][0], players_Data[k + 1][0] ^= players_Data[k][0], players_Data[k][0] ^= players_Data[k + 1][0];
				players_Data[k][1] ^= players_Data[k + 1][1], players_Data[k + 1][1] ^= players_Data[k][1], players_Data[k][1] ^= players_Data[k + 1][1];
			}
		}
	}
    new gs_Buffer[1500] = EOS;
    strcat(gs_Buffer, "{0095FF}Posicao\t{FFFFFF}Jogador(a)\t{0080C0}Kills");
	for(i = 0; i < 10; ++i)
	{
		if(tempVar <= i)
			break;

		GetPlayerName(players_Data[i][1], String, 24);
		format(String, sizeof(String), "\n{0095FF}%d° Lugar\t{FFFFFF}%s #%d\t{228B22}%d", i+1, String, g_PlayerData[players_Data[i][1]][g_AccId], players_Data[i][0]);
		strcat(gs_Buffer, String);
	}
	format(String, sizeof(String), "{FFFFFF}Top 10 {228B22}Kills");
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_TABLIST_HEADERS, String, gs_Buffer, "Fechar", "");
	return true;
}

CMD:comandos(playerid){
	new msg2[2048];
	msg2[0] = '\0';

	strcat(msg2, "\n{007DFB}/Tp {FFFFFF}| Escolher um local para ir ate ele.");
	strcat(msg2, "\n{007DFB}/Admins {FFFFFF}| Ver os admins que estao em servico.");
	/*strcat(msg2, "\n{007DFB}/Efeitos {FFFFFF}| Ver Algumas Informacoes Basica Do Jogador(a).");
	strcat(msg2, "\n{007DFB}/Brinquedos {FFFFFF}| Ver Todos Id Dos Jogadores Logados.");
	strcat(msg2, "\n{007DFB}/Tbrinquedos {FFFFFF}| Voar Pelo Servidor.");
	strcat(msg2, "\n{007DFB}/Tfeitos {FFFFFF}| Expulsar um Jogador(a) Do Servidor.");
	strcat(msg2, "\n{007DFB}/skin {FFFFFF}| Limpar o Chat Para Todos Os Jogadores Logado No Servidor.");*/
	strcat(msg2, "\n{007DFB}/Creditos {FFFFFF}| Ver os creditos do servidor.");
	strcat(msg2, "\n{007DFB}/Regras {FFFFFF}| Ver as regras do servidor.");
	strcat(msg2, "\n{007DFB}/Mundos {FFFFFF}| Escolher um mundo para esta jogando.");
	strcat(msg2, "\n{007DFB}/Arena {FFFFFF}| Escolher uma arena para esta jogando.");
	strcat(msg2, "\n{007DFB}/Sair {FFFFFF}| Sair de uma arena, mundo ou sala.");
	strcat(msg2, "\n{007DFB}/Veh ou /Car {FFFFFF}| Criar um veiculo(funciona somente do mundo fugas).");
	strcat(msg2, "\n{007DFB}/Loja {FFFFFF}| Ver a loja coins do servidor.");
	strcat(msg2, "\n{007DFB}/Perfil {FFFFFF}| Ver algumas informacoes sobre minha conta.");
	strcat(msg2, "\n{007DFB}/Topkills {FFFFFF}| Ver o top 10 jogadores que fizeram mais kills.");

	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Comandos:", msg2, "OK", "");
	return true;
}