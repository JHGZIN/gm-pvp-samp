stock GivePlayerLevel(playerid, level){
	 g_PlayerData[playerid][g_Level] += level;
	 return SetPlayerScore(playerid, g_PlayerData[playerid][g_Level]);
}

stock SetPlayerMoney(playerid, money){
	 g_PlayerData[playerid][g_Money] += money;
	 return GivePlayerMoney(playerid, g_PlayerData[playerid][g_Money]);
}

stock ColocarAureola(playerid){
	new id;
    SetPlayerAttachedObject(playerid,id,2992,2,0.306000,-0.012000,0.009000,0.000000,-95.299942,-1.399999,1.000000,1.000000,1.000000);
    SetPlayerAttachedObject(2992,Vaga_Aureola1,playerid,id);
    SetPlayerAttachedObject(playerid,id,2992,2,0.313000,-0.007000,0.032999,-0.299999,83.700019,0.000000,1.000000,1.000000,1.000000);
    SetPlayerAttachedObject(2992,Vaga_Aureola2,playerid,id);
}

stock TirarAureola(playerid){
    RemovePlayerAttachedObject(playerid, Vaga_Aureola1);
	RemovePlayerAttachedObject(playerid, Vaga_Aureola2);
}

stock MudarNomeServer(){
	new rdon = random(sizeof(NomesServer));
	SendRconCommand(NomesServer[rdon]);
}

stock ABroadCast(COLOR, const striing[], level){
	foreach(Player, i){
		if (g_PlayerData[i][g_Admin] >= level){
			SendClientMessage(i, COLOR, striing);
		}
	}
	printf("%s", striing);
	return true;
}

stock GetPlayerNameEx(playerid){
	new StrWl2[MAX_PLAYER_NAME];
	GetPlayerName(playerid, StrWl2, sizeof(StrWl2));
	return StrWl2;
}

stock ResetVars(playerid){
	ptsLastFiredWeapon[playerid] = 0;
	KillTimer(ptmCBugFreezeOver[playerid]);
	pCBugging[playerid] = false;
	return true;
}

stock SendClientMessageInRange(Float:_r, playerid,const _s[],c1,c2,c3,c4,c5){
    new Float:_x, Float:_y, Float:_z;
    GetPlayerPos(playerid, _x, _y, _z);
    foreach(Player, i){
        if(GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid))continue;
        if(GetPlayerDistanceFromPoint(i,_x,_y,_z) < _r/16)
        SendClientMessage(i, c1, _s);
        else if(GetPlayerDistanceFromPoint(i,_x,_y,_z) < _r/8)
        SendClientMessage(i, c2, _s);
        else if(GetPlayerDistanceFromPoint(i,_x,_y,_z) < _r/4)
        SendClientMessage(i, c3, _s);
        else if(GetPlayerDistanceFromPoint(i,_x,_y,_z) < _r/2)
        SendClientMessage(i, c4, _s);
        else if(GetPlayerDistanceFromPoint(i,_x,_y,_z) < _r)
        SendClientMessage(i, c5, _s);
    }
    return 1;
}

stock PlayerName(playerid){
	new name[MAX_PLAYER_NAME];
	GetPlayerName(playerid,name,sizeof(name));
	return name;
}

stock LimparChat(playerid, linhas){
	for(new b = 0; b <= linhas; b++) SendClientMessage(playerid, -1, "");
}

stock va_return(const fmat[], {Float,_}:...){
    static buffer[AV_MAX_STRING];
    new argCount = numargs();

    switch (argCount){
        case 0:
            format(buffer, sizeof(buffer), fmat);
        case 1:
            format(buffer, sizeof(buffer), fmat, getarg(1));
        case 2:
            format(buffer, sizeof(buffer), fmat, getarg(1), getarg(2));
        default:
            format(buffer, sizeof(buffer), fmat, getarg(1), getarg(2), getarg(3));
    }
    return buffer;
}

IsNumeric(const string[]){
	for (new i = 0, j = strlen(string); i < j; i++){
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}

stock GetPlayerSpeed(playerid){
    new Float:velocity[4];
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid),velocity[0],velocity[1],velocity[2]);
    else GetPlayerVelocity(playerid,velocity[0],velocity[1],velocity[2]);
    velocity[3] = floatsqroot(floatpower(floatabs(velocity[0]), 2.0) + floatpower(floatabs(velocity[1]), 2.0) + floatpower(floatabs(velocity[2]), 2.0)) * 97;
    return floatround(velocity[3]);
}

stock IsPlayerLogado(playerid){
    if(playerid == -1 || playerid == INVALID_PLAYER_ID)
        return 0;
    else if(g_PlayerData[playerid][g_Logado])
        return 1;
    else
        return 0;
}

stock GetRealID(steadyID) {
    foreach(new i : Player) 
        if(g_PlayerData[i][g_AccId] == steadyID)
            return i;
    
    return INVALID_PLAYER_ID;
}

stock IsValidInput(const ipstr[])
{
    for(new i = 0; ipstr[i] != EOS; ++i)
    {
        switch(ipstr[i])
        {
            case '0'..'9', 'A'..'Z', 'a'..'z', '_', '[', '@', ']', '.':
                continue;
            default:
                return 0;
        }
    }
    return 1;
}

stock GetNameVip(playerid){
	static str[30];
	if (g_PlayerData[playerid][g_VIP] == 0){
		str = "Undfined";
	}
	else if (g_PlayerData[playerid][g_VIP] == 1){
		str = "VIP NORMAL";
	} else if (g_PlayerData[playerid][g_VIP] == 2){
		str = "VIP RUBI";
	} else if (g_PlayerData[playerid][g_VIP] == 3){
		str = "VIP GOLDEN";
	}
	return str;
}

stock NomeVip(vipid){
    static str[30];
    if (vipid == 1){
        str = "VIP NORMAL";
    } else if (vipid == 2){
        str = "VIP RUBI";
    } else if (vipid == 3){
        str = "VIP GOLDEN";
    }
    return str;
}

stock UltimoLogin(n)
{
    new t[5], msg[30];
 	t[4] = gettime()-n;
	t[0] = t[4] / 3600;
	t[1] = ((t[4] / 60) - (t[0] * 60));
	t[2] = (t[4] - ((t[0] * 3600) + (t[1] * 60)));
	t[3] = (t[0]/24);

	if(t[3] > 0)
	t[0] = t[0] % 24,
	format(msg, sizeof(msg), "%d dia(s) e %d hora(s)", t[3], t[0]);
	else if(t[0] > 0)
	format(msg, sizeof(msg), "%d hora(s) e %d minuto(s)", t[0], t[1]);
	else
	format(msg, sizeof(msg), "%d minuto(s)", t[1]);
	return msg;
}

stock salt(){
    new SALT[SALT_LEN];
    for(new i; i < SALT_LEN-1; i++)
        SALT[i] = random(79) + 47;
    SALT[SALT_LEN-1] =  0;
    return SALT;
}

stock getTimestamp(){
    new year, month, day, hour, minute, second;
    getdate(year, month, day);
    gettime(hour, minute, second);
    return convertToTimestamp(day, month, year, hour, minute, second);
}

stock parseDateToTimestamp(const data[]){
    new year, month, day, hour, minute, second;
    sscanf(data, "d[-]d[-]p<->d[ ]d[:]d[:]d", day, month, year, hour, minute, second);
    return convertToTimestamp(day, month, year, hour, minute, second);
}

stock convertToTimestamp(day, month, year, hour, minute, second){
    new timestamp = 0;
    timestamp += (year - 1970) * 31536000;
    timestamp += (month - 1) * 2628000;
    timestamp += (day - 1) * 86400;
    timestamp += hour * 3600;
    timestamp += minute * 60;
    timestamp += second;
    return timestamp;
}

stock convertTimestampToDate(timestamp, &day, &month, &year, &hour, &minute, &second){
    year = 1970;
    while (timestamp >= 31536000) {
        timestamp -= 31536000;
        year++;
    }

    month = 1;
    while (timestamp >= 2628000) {
        timestamp -= 2628000;
        month++;
    }

    day = 1;
    while (timestamp >= 86400) {
        timestamp -= 86400;
        day++;
    }

    hour = timestamp / 3600;
    timestamp %= 3600;
    minute = timestamp / 60;
    second = timestamp % 60;
}

stock DarVIP(playerid, dias, vipid){
    new year, month, day, hour, minute, second;
    getdate(year, month, day);
    gettime(hour, minute, second);

    new timestampAtual = convertToTimestamp(day, month, year, hour, minute, second);
    new segundosParaAdicionar = dias * 86400; // 86400 segundos em 1 dia
    new timestampFinal = timestampAtual + segundosParaAdicionar;

    // Converte timestamp final de volta para data
    convertTimestampToDate(timestampFinal, day, month, year, hour, minute, second);

    new data[25];
    format(data, sizeof(data), "%02d-%02d-%04d %02d:%02d:%02d", day, month, year, hour, minute, second);

    format(g_PlayerData[playerid][g_TempoVip], 35, "%s", data);
    g_PlayerData[playerid][g_VIP] = vipid;

    new str[64];
    format(str, sizeof(str), "Voce recebeu %d dias de VIP! Expira em: %s",  NomeVip(vipid), data);
    SendClientMessage(playerid, -1, str);
    return true;
}

stock va_SendClientMessage(playerid, color, const message[], {Float,_}:...) {
    static
        args,
        start,
        end,
        string[298]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (args > 9)
    {
        #emit ADDR.pri message
        #emit STOR.pri start

        for (end = start + (args - 8); end > start; end -= 4)
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S message
        #emit PUSH.C 298
        #emit PUSH.C string

        #emit LOAD.S.pri 8
        #emit ADD.C 4
        #emit PUSH.pri

        #emit SYSREQ.C format
        #emit LCTRL 5
        #emit SCTRL 4

        SendClientMessage(playerid, color, string);
        return 1;
    }
    SendClientMessage(playerid, color, message);
    return 1;
}

stock GetMaskedIP(playerid, const dest[], size){
    new ip[16];
    GetPlayerIp(playerid, ip, sizeof(ip));
    new part1[4], part2[4], part3[4];
    sscanf(ip, "p.p.p", part1, part2, part3);
    format(dest, sizeof size, "%s.%s.%s.***", part1, part2, part3);
    return dest;
}

stock convert_tstamp(n) {
    new t[5], Converter[75];
    t[4] = n-gettime();
    t[0] = t[4] / 3600;
    t[1] = ((t[4] / 60) - (t[0] * 60));
    t[2] = (t[4] - ((t[0] * 3600) + (t[1] * 60)));
    t[3] = (t[0]/24);

    if(t[3] > 0)
        t[0] = t[0] % 24,
        format(Converter, sizeof(Converter), "%d Dia%s %02d:%02d:%02d", t[3], t[3] > 1 ? ("s") : (""), t[0], t[1], t[2]);
    else if(t[0] > 0) format(Converter, sizeof(Converter), "%02d:%02d:%02d", t[0], t[1], t[2]);
    else format(Converter, sizeof(Converter), "%02d:%02d", t[1], t[2]);
    return Converter;
}

stock SendMessageToPlayersLogados(const msg[]){
    foreach(new i : Player){
        if (IsPlayerLogado(i)){
            SendClientMessage(i, -1, msg);
        }
    }
    return true;
}

stock GeraCodigo(){
    return random(900000) + 100000; // Gera de 100000 a 999999
}