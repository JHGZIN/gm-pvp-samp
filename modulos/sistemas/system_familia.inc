#define MAX_FAMILY 20
#define MAX_NAME_FAMILIA 40

#define CARGO_LIDER 6
#define CARGO_SUBLIDER 5

enum E_FAMILY {
	g_Name[MAX_NAME_FAMILIA],
	g_Chefe,
	g_SubChefe,
    g_Vagas,
    Float:Pos[4],
    g_Vip,
    g_TempoVip,
    bool:g_FamiliaUsada,
	PickupFamilia,
	STREAMER_TAG_3D_TEXT_LABEL:LabelFamilia
};
new g_FamiliaData[MAX_FAMILY][E_FAMILY];

stock CarregarFamilia() {
    new str[128];
    new Cache:PQP = mysql_query(DBConn, "SELECT * FROM `familia`", true);
    if(cache_num_rows()){
        for(new i=0; i < cache_num_rows(); i++) {
	        cache_get_value_name(i, "nome", g_FamiliaData[i][g_Name]);
	        cache_get_value_name_int(i, "lider", g_FamiliaData[i][g_Chefe]);
	        cache_get_value_name_int(i, "sublider", g_FamiliaData[i][g_SubChefe]);
	        cache_get_value_name_int(i, "vagas", g_FamiliaData[i][g_Vagas]);
	        cache_get_value_name_int(i, "vip", g_FamiliaData[i][g_Vip]);
	        cache_get_value_name(i, "diasvip", g_FamiliaData[i][g_TempoVip]);

	        cache_get_value_name_float(i, "posx", g_FamiliaData[i][Pos][0]);
	        cache_get_value_name_float(i, "posy", g_FamiliaData[i][Pos][1]);
	        cache_get_value_name_float(i, "posz", g_FamiliaData[i][Pos][2]);
	        cache_get_value_name_float(i, "posr", g_FamiliaData[i][Pos][3]);

	        g_FamiliaData[i][g_FamiliaUsada] = true;
	        
	        if (g_FamiliaData[i][Pos][0] != 0.0) {
	            format(str, sizeof str, "{FFFFFF}ID: {007DFB}%d {FFFFFF}Familia: {007DFB}%s {FFFFFF}Presione '{007DFB}ALT{FFFFFF}'", i, g_FamiliaData[i][g_Name]);
	            g_FamiliaData[i][LabelFamilia] = CreateDynamic3DTextLabel(str, -1, g_FamiliaData[i][Pos][0], g_FamiliaData[i][Pos][1], g_FamiliaData[i][Pos][2], 5.0);
	            g_FamiliaData[i][PickupFamilia] = CreateDynamicPickup(1314, 23, g_FamiliaData[i][Pos][0], g_FamiliaData[i][Pos][1], g_FamiliaData[i][Pos][2], -1, -1, -1, 5.0);
	        }
        }
    }
    cache_delete(PQP);
    return 1;
}

stock FamilyPossuiLider(org_id){

	new query[110];

	format(query, sizeof query, "SELECT * FROM `users` WHERE `familia` = '%d' AND `cargofamilia` = '%d'", org_id, CARGO_LIDER);
	new Cache:PQP = mysql_query(DBConn, query, true);

	if(cache_num_rows() > 0){

		cache_delete(PQP);
		return 1;
	}

	cache_delete(PQP);
	return 0;
}

stock ReturnLiderFamily(org_id){

	new query[110], pass;

	format(query, sizeof query, "SELECT * FROM `users` WHERE `familia` = '%d' AND `cargofamilia` = '%d'", org_id, CARGO_LIDER);
	new Cache:PQP = mysql_query(DBConn, query, true);

	cache_get_value_name_int(0, "id", pass);

	cache_delete(PQP);
	return pass;
}

stock ReturnNomeLiderFamily(org_id){

	new query[110], nome[24];

	format(query, sizeof query, "SELECT * FROM `users` WHERE `familia` = '%d' AND `cargofamilia` = '%d'", org_id, CARGO_LIDER);
	new Cache:PQP = mysql_query(DBConn, query, true);

	if(cache_num_rows()) cache_get_value_name(0, "nome", nome);
	else nome = "Sem Lider";

	cache_delete(PQP);
	return nome;
}

stock JogadorPertenceFamily(playerid){

	new query[110];

	format(query, sizeof query, "SELECT * FROM `users` WHERE `familia` != '-1' AND `id` = '%d'", g_PlayerData[playerid][g_AccId]);
	new Cache:PQP = mysql_query(DBConn, query, true);

	if(cache_num_rows() > 0){

		cache_delete(PQP);
		return 1;
	}
	return 0;
}

stock TotalMembrosOrg(org){

	new query[60];

	format(query, sizeof query, "SELECT * FROM `users` WHERE `familia` = '%d'", org);
	new Cache:PQP = mysql_query(DBConn, query, true);

	new total = cache_num_rows();

	cache_delete(PQP);
	return total;
}

/*CMD:criarfamilia(playerid) return callcmd::cfamilia(playerid);
CMD:cfamilia(playerid){
	if (g_PlayerData[playerid][g_Admin] <= 0)
		return SendClientMessage(playerid, 0xFF0000AA, "| ERRO | Comando invalido.");

	ShowPlayerDialog(playerid, D_CRIARFAMILIA, DIALOG_STYLE_INPUT, "{FAFAFA}Nome Familia:", "Digite o nome da familia para esta criando:", "Confirmar", "Cancelar");
	return 1;
}*/

CMD:deletarfamilia(playerid) return callcmd::dfamilia(playerid);
CMD:deletefamilia(playerid) return callcmd::dfamilia(playerid);
CMD:dfamilia(playerid){
	if(g_PlayerData[playerid][g_Admin] < 5)
    	return PermissionError(playerid);

	new msg[60], msg2[60 * 20];
 	msg2[0] = '\0';

	for(new i; i < MAX_FAMILY; i++){
		if (g_FamiliaData[i][g_FamiliaUsada]){
			format(msg, sizeof msg, "{007DFB}Nome: {FFFFFF}%s {007DFB}Lider: {FFFFFF}%s\n", g_FamiliaData[i][g_Name], ReturnNomeLiderFamily(i));
			strcat(msg2, msg);
		}
	}

	ShowPlayerDialog(playerid, D_DELETARFAMILIA, DIALOG_STYLE_LIST, "Escolha a Familia", msg2, "Deletar", "Cancelar");
	return true;
}

CMD:familias(playerid)
{
    new formatmsg[128], msgfamilia[2048];
    msgfamilia[0] = '\0';

    for (new i; i < MAX_FAMILY; i++){
        if (g_FamiliaData[i][g_FamiliaUsada]){
            format(formatmsg, sizeof formatmsg, "{007DFB}Nome: {FFFFFF}%s {007DFB}Lider: {FFFFFF}%s\n", g_FamiliaData[i][g_Name], ReturnNomeLiderFamily(i));
            strcat(msgfamilia, formatmsg);
        }
    }

    if (strlen(msgfamilia) <= 0)
    {
    	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_TABLIST, "{007DFB}Famílias", "Nenhuma família encontrada.", "Fechar", "");
        return true;
    }

    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_TABLIST, "{007DFB}Famílias", msgfamilia, "Fechar", " ");
    return true;
}

CMD:aceitarconvite(playerid){
	new liderid, familiaid, query[110];
	if (!g_PlayerData[playerid][g_Convite])
		return ShowError(playerid, "VOCE NAO TEM NEHUM CONVITE!");

	liderid = GetPVarInt(playerid, "LiderId");
	familiaid = GetPVarInt(playerid, "FamiliaId");
	format(query, sizeof query, "UPDATE `users` SET `familia` ='%d' WHERE `id` = '%d'", familiaid, g_PlayerData[playerid][g_AccId]);
	mysql_query(DBConn, query, false);
	g_PlayerData[playerid][g_Familia] = familiaid;
	g_PlayerData[playerid][g_Convite] = false;
	va_SendClientMessage(playerid, -1, "{007DFB}Aviso: {FFFFFF}Voce aceitor o covite para entrar na familia: {007DFB}%s", g_FamiliaData[familiaid][g_Name]);
	va_SendClientMessage(liderid, -1, "{007DFB}Aviso: {FFFFFF}O(a) jogador(a) %s #%d aceito o convite para entrar na familia: {007DFB}%s", GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId], g_FamiliaData[familiaid][g_Name]);
	DeletePVar(playerid, "LiderId");
	DeletePVar(playerid, "FamiliaId");
	return true;
}

CMD:familia(playerid, params[]){
	if (g_PlayerData[playerid][g_Familia] < 0)
	    return ShowError(playerid, "VOCE NAO ESTA EM UMA FAMILIA!");

	if (isnull(params)) {
	    new msg2[2048];
	    msg2[0] = '\0';

	    strcat(msg2, "\n{FFFFFF}Comando /familia {007DFB}'nome'");
	    strcat(msg2, "\n{007DFB}convidar {FFFFFF}| Convidar membros para sua familia.");
	    strcat(msg2, "\n{007DFB}convidarsub {FFFFFF}| Convidar um SubLider para sua familia.");
	    strcat(msg2, "\n{007DFB}limparvaga {FFFFFF}| Expulse aquele membro atrapalhado!");
	    strcat(msg2, "\n{007DFB}info {FFFFFF}| Infomacoes sobre sua familia.");
	    strcat(msg2, "\n{007DFB}chat {FFFFFF}| Converse com outros membros.");
	    strcat(msg2, "\n{007DFB}sair {FFFFFF}| Sair de uma familia.");
	    strcat(msg2, "\n{007DFB}membros {FFFFFF}| Ver membros da familia que estao online.");
	    strcat(msg2, "\n{007DFB}nikc {FFFFFF}| Inserir/Retirar o nome da familia da cabeca.");
	    strcat(msg2, "\n{007DFB}config {FFFFFF}| Configurar a posicao do menu VIP.");

	    ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{007DFB}Familia:", msg2, "Ok", " ");
	    return 1;
	}
	new subcmd[32], extra[128];
	if (sscanf(params, "s[32]S()[128]", subcmd, extra))
	    return SendClientMessage(playerid, -1, "{FFFFFF}Use {007DFB}/familia {FFFFFF}[subcomando] [argumento opcional]");

	if (!strcmp(params, "convidar", true)) {
		if (g_PlayerData[playerid][g_CargoFamilia] != CARGO_LIDER || g_PlayerData[playerid][g_CargoFamilia] != CARGO_SUBLIDER)
			return ShowError(playerid, "VOCE NAO TEM PERMISSAO PARA ESTA FAZER ESSA ACAO.");

		if (isnull(extra)) return SendClientMessage(playerid, -1, "{FF0000}[ERRO] {FFFFFF}Use: /familia convidar [id/nome]");
		new targetid = strval(extra), realID;
		realID = GetRealID(targetid);
		if(!IsPlayerConnected(playerid)) 
			return ShowError(playerid, "PLAYERID OFFLINE!");
		if(!IsPlayerConnected(realID)) 
			return ShowError(playerid, "PLAYERID OFFLINE!");
		if(!IsPlayerLogado(realID)) 
			return ShowError(playerid, "PLAYERID OFFLINE!");
		if(realID == playerid) 
			return ShowError(playerid, "VOCE NAO PODE CONVIDAR VOCE MESMO!");
		
		new Float:x, Float:y, Float:z;
		GetPlayerPos(realID, x, y, z);
		if (!IsPlayerInRangeOfPoint(playerid, 4.0, x, y, z))
			return ShowError(playerid, "VOCE ESTA MUITO LONGE DESSE JOGADOR.");

		SetPVarInt(realID, "LiderId", playerid);
		SetPVarInt(realID, "FamiliaId", g_PlayerData[playerid][g_Familia]);

		g_PlayerData[realID][g_Convite] = true;

		va_SendClientMessage(realID, -1, "{007DFB}Aviso: {FFFFFF}Voce recebeu um covite para entrar na familia: {007DFB}%s {FFFFFF}use {007DFB}'/aceitarconvite'{FFFFFF} caso quira entrar.", g_FamiliaData[g_PlayerData[playerid][g_Familia]][g_Name]);
	}
	else if (!strcmp(params, "convidarsub", true)) {

	}
	else if (!strcmp(params, "limparvaga", true)) {

	}
	else if (!strcmp(params, "info", true)) {
		
	}
	else if (!strcmp(params, "chat", true)) {
		if (isnull(extra)) return SendClientMessage(playerid, -1, "[ERRO] Use: /familia chat [mensagem]");

		new msg[144];
		format(msg, sizeof(msg), "[CHAT FAMÍLIA] %s: %s", PlayerName(playerid), extra);

		// Envia para todos da família (simulando com todos os players)
		foreach(new i : Player){
			if (!IsPlayerLogado(i)) continue;
			if (g_PlayerData[i][g_Familia] == g_PlayerData[playerid][g_Familia]){
				SendClientMessage(i, -1, msg);
			}
		}
	}
	else {
		SendClientMessage(playerid, -1, "{FFFFFF}Use {007DFB}/familia {FFFFFF}para ver os clmandos.");
	}
	return 1;
}