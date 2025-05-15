//VIPS

CMD:jetpack(playerid)
{
	new string[128];
	if(g_PlayerData[playerid][g_VIP] < 1)
		return SCM(playerid, COR_GERAL, MSGERRO); 

	format(string, sizeof string, "[JetPack]: %s pegou seu {FFD700}/jetpack", PlayerName(playerid));
	SendClientMessageInRange(35.0, playerid, string,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA,0xa3ffffAA);
	SetPlayerSpecialAction(playerid, 2);
	return true;
}

CMD:v(playerid, result[])
{
	new string[128];
	if(g_PlayerData[playerid][g_VIP] < 1)
		return SCM(playerid, COR_GERAL, MSGERRO);

	if(isnull(result))
		return SendClientMessage(playerid, COLOR_GRAD2, "(/v)ip [texto]");

	if(g_PlayerData[playerid][g_VIP] == 1)
	{
		format(string, sizeof(string), "{8B8989}(Chat VIP) {CD853F}%s: %s **", GetPlayerNameEx(playerid), result);
	}
	else if(g_PlayerData[playerid][g_VIP] == 2)
	{
		format(string, sizeof(string), "{8B8989}(Chat VIP) {FFD700}%s: %s **", GetPlayerNameEx(playerid), result);
	}
    else if(g_PlayerData[playerid][g_VIP] == 3)
    {
		format(string, sizeof(string), "{8B8989}(Chat VIP) {00FFFF}%s: %s **", GetPlayerNameEx(playerid), result);
	}
	SendVIPMessage(0xFF8000AA,string);
	return true;
}

CMD:cor(playerid)
{
	if(g_PlayerData[playerid][g_VIP] < 2)
		return SCM(playerid, COR_GERAL, MSGERRO);

	ShowPlayerDialog(playerid, 2301, DIALOG_STYLE_LIST, "Cores Nick", "{FF0000}Vermelho\n{00FF00}Verde\n{FFFF00}Amarelo\n{FF00FF}Rosa\n{0000FF}Azul Escuro", "Adicionar", "Fechar");
	return true;
}

//YOUTUBERS
CMD:youtubers(playerid, params[]){
	new Cont = 0;
	MEGAString[0] = EOS;
	new string[500];
	foreach(Player, i)
	{
		if(g_PlayerData[i][g_YouTuber] > 0)
		{
			format(string, sizeof(string), "{FF0000}(%d)\t\t (%s)\t\n", playerid, GetPlayerNameEx(playerid));
			strcat(MEGAString, string);
			Cont++;
		}
		if(Cont == 0)
		{
			ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{00FF00}Youtubers Offline", "\n\n{FFFF00}Nenhum {FF00FF}YouTuber{FFFF00} Online no momento\n{FFFF00}Acesse: (discord.gg/VIRIDIANpvp)\n\n", "Informado", "");
		}
		else
		{
			new titulo[128];
			format(titulo, sizeof(titulo), "{FF3030}YouTubers Online {00FF00}(%d)", Cont);
			ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_LIST, titulo, MEGAString, "Informado", "");
		}
	}
	return 1;
}

CMD:youtuber(playerid, result[])
{
	new string[128];
	if(g_PlayerData[playerid][g_YouTuber] < 1)
		return SCM(playerid, COR_GERAL, MSGERRO);

	if(gettime() < GetPVarInt(playerid, "AntFloodText"))
    {
        SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {858585}Aguarde 5 Segundos para usar o comando novamente");
        return true;
    }
	if(isnull(result))
	{
		SendClientMessage(playerid, MSG_USE, "Modo de usar: /youtuber [Texto]");
		return 1;
	}

	SetPVarInt(playerid, "AntFloodText", gettime()+5);
	format(string, sizeof(string), "{FF0000}YouTuber {FFFFFF}%s: {FF0000}%s", PlayerName(playerid), result);
	SendClientMessageToAll(COLOR_REDD, string);
	format(string, sizeof(string), "{FF0000}***********************************************************************************************");
	SendClientMessageToAll(COLOR_REDD, string);
	return 1;
}

CMD:ajudayt(playerid)
{
	if(g_PlayerData[playerid][g_YouTuber] < 1)
		return SCM(playerid, COR_GERAL, MSGERRO);

	strcat(MEGAString, "{FFF68F}* Comandos YouTuber:\n", 4500);
	strcat(MEGAString, "{00FF00}>{FFFFFF} /youtuber{858585} > Anunciar uma live ou video no servidor!\n", 4500);
	strcat(MEGAString, "{FFF68F}* Mais comandos em breve!\n\n", 4500);

	strcat(MEGAString, "{FFF68F}* Benficios YouTuber:\n", 4500);
	strcat(MEGAString, "{858585}* (1) Falar no Chat Destacado\n", 4500);
	strcat(MEGAString, "{858585}* (2) Tag YouTuber em Nosso Forum discord\n", 4500);
	strcat(MEGAString, "{858585}* (3) Acesso Call Privadas em Nosso Discord\n", 4500);
	ShowPlayerDialog(playerid, D_NULL, DIALOG_STYLE_MSGBOX, "{858585}YouTuber Info:", MEGAString, "Informado", "");
	return true;
}
