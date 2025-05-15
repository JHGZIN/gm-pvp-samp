function SendVIPMessage(color, striing[]){
    foreach(Player, i){
        if(g_PlayerData[i][g_VIP] >= 1){
            SendClientMessage(i, color, striing);
        }
    }
}

function ScoreLevel(playerid){
	new LevScore;
	LevScore = g_PlayerData[playerid][g_Level];
	SetPlayerScore(playerid, LevScore);
}

function SendMensagens(){
	new random1 = random(sizeof(Mensagenscima));
	SendClientMessageToAll(COR_GERAL, Mensagenscima[random1]);
	return true;
}

function CBugFreezeOver(playerid){
	TogglePlayerControllable(playerid, true);
	pCBugging[playerid] = false;
	return true;
}

function RandomServerNames(){
	new string[128];
	new random1 = random(sizeof(NomeServer));
	format(string, sizeof(string), "hostname %s", NomeServer[random1] );
	SendRconCommand(string);
	return true;
}

function RecarregarNitro(){
    foreach(new i : Player){
        if (IsPlayerLogado(i)){
            if (IsPlayerInAnyVehicle(i) && GetPlayerState(i) == PLAYER_STATE_DRIVER){
                new vehicleid = GetPlayerVehicleID(i);
                AddVehicleComponent(vehicleid, 1010);
            }
        }
    }
    return true;
}

function ChamadaUmSegundo(){
    foreach(new playerid : Player){
        if (IsPlayerLogado(playerid)){
            /*if(strlen(g_PlayerData[playerid][g_TempoVip]) > 0){
                new timestampExpira = parseDateToTimestamp(g_PlayerData[playerid][g_TempoVip]);
                new timestampAtual = getTimestamp();

                if(timestampAtual >= timestampExpira){
                    g_PlayerData[playerid][g_VIP] = 0;
                    format(g_PlayerData[playerid][g_TempoVip], 35, "");
                    
                    new query[100];
                    mysql_format(DBConn, query, sizeof(query), "UPDATE users SET vip = 0, diasvip = NULL WHERE id = %d", g_PlayerData[playerid][g_AccId]);
                    mysql_tquery(DBConn, query);
                    
                    SendClientMessage(playerid, -1, "Seu Vip acabou");
                }
            }
            if (!estaAFK[playerid] && tempoAtual - ultimoMovimento[playerid] >= TEMPO_INATIVIDADE){
                estaAFK[playerid] = true;
                inicioAFK[playerid] = tempoAtual;
            }*/
        }
    }
    return true;
}

function KickPlayer(playerid){
    Kick(playerid);
    return 1;
}