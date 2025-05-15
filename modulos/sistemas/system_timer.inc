new bool:timer_TextShow[MAX_PLAYERS], 
	   PlayerText:text_TimerPlayer[MAX_PLAYERS][7]
	   ;

enum E_TIMEFLOW  {
	Hour = 5,
	Minute = 59,
	Second,
	TimerFlow,
	bool:TimerHudShow
}

new g_TimeFlow[E_TIMEFLOW];

forward StartTimer();
public StartTimer() {
	if(g_TimeFlow[Second] >= 3) {
	    g_TimeFlow[Second] = 0;
	    g_TimeFlow[Minute] ++;
	}
	else if(g_TimeFlow[Minute] >= 59) {
	    g_TimeFlow[Minute] = 0;
	    g_TimeFlow[Hour] ++;
	}
	else if(g_TimeFlow[Hour] > 23) {
	    g_TimeFlow[Hour] = 0;
	    g_TimeFlow[Hour] ++;
	}
    SetTimer("StartTimer", 1000, false);
    g_TimeFlow[Second] ++;
	SetWorldTime(g_TimeFlow[Hour]);
	return true;
}

stock Create_PlayerTextTimer(playerid) {
	if(!timer_TextShow[playerid]) {
		text_TimerPlayer[playerid][0] = CreatePlayerTextDraw(playerid, 479.000, 5.000, "LD_SPAC:white");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][0], 92.000, 21.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][0], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][0], 20);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][0], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][0], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][0], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][0], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][0], 1);
		
		text_TimerPlayer[playerid][1] = CreatePlayerTextDraw(playerid, 534.098, 4.399, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][1], 14.000, 22.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][1], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][1], -166);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][1], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][1], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][1], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][1], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][1], 1);
		
		text_TimerPlayer[playerid][2] = CreatePlayerTextDraw(playerid, 549.000, 9.798, "20:40");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][2], 0.199, 1.140);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][2], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][2], -116);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][2], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][2], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][2], 0);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][2], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][2], 1);
		
		text_TimerPlayer[playerid][3] = CreatePlayerTextDraw(playerid, 540.200, 9.798, "L");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][3], 0.230, 0.819);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][3], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][3], 140);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][3], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][3], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][3], 0);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][3], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][3], 1);
		
		text_TimerPlayer[playerid][4] = CreatePlayerTextDraw(playerid, 481.599, 4.399, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][4], 7.000, 13.000);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][4], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][4], -166);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][4], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][4], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][4], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][4], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][4], 1);
		
		text_TimerPlayer[playerid][5] = CreatePlayerTextDraw(playerid, 479.199, 14.099, "LD_BEAT:chit");
		PlayerTextDrawTextSize(playerid, text_TimerPlayer[playerid][5], 11.900, 13.800);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][5], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][5], -166);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][5], 0);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][5], 0);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][5], 255);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][5], 4);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][5], 1);
		
		text_TimerPlayer[playerid][6] = CreatePlayerTextDraw(playerid, 492.000, 10.798, "99999999");
		PlayerTextDrawLetterSize(playerid, text_TimerPlayer[playerid][6], 0.209, 1.150);
		PlayerTextDrawAlignment(playerid, text_TimerPlayer[playerid][6], 1);
		PlayerTextDrawColor(playerid, text_TimerPlayer[playerid][6], -116);
		PlayerTextDrawSetShadow(playerid, text_TimerPlayer[playerid][6], 1);
		PlayerTextDrawSetOutline(playerid, text_TimerPlayer[playerid][6], 1);
		PlayerTextDrawBackgroundColor(playerid, text_TimerPlayer[playerid][6], 0);
		PlayerTextDrawFont(playerid, text_TimerPlayer[playerid][6], 1);
		PlayerTextDrawSetProportional(playerid, text_TimerPlayer[playerid][6], 1);
		timer_TextShow[playerid] = true;
	}
    for (new i = 0; i < sizeof text_TimerPlayer[]; i++) PlayerTextDrawShow(playerid, text_TimerPlayer[playerid][i]);
	return true;
}

stock Destroy_PlayerTextTimer(playerid) {
    if (timer_TextShow[playerid]) {
        for (new i = 0; i < sizeof text_TimerPlayer[]; i++) {
            PlayerTextDrawDestroy(playerid, text_TimerPlayer[playerid][i]);
            text_TimerPlayer[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
        }
    }
    timer_TextShow[playerid] = false;
    return true;
}

stock Update_PlayerTextTimer(playerid){
	static str[11]; format(str, sizeof str, "%02d:%02d", g_TimeFlow[Hour], g_TimeFlow[Minute]);
	PlayerTextDrawSetString(playerid, text_TimerPlayer[playerid][2], str);

	format(str, sizeof str, "%d", g_PlayerData[playerid][g_AccId]);
	PlayerTextDrawSetString(playerid, text_TimerPlayer[playerid][6], str);
	return 1;
}

CMD:timer(playerid, params[]) {
	static newhour, str[30];
	if (sscanf(params, "d", newhour)) SendClientMessage(playerid, 0xFF0000AA, "Use: /timer [Hour]");
	g_TimeFlow[Hour] = newhour;
	format(str, sizeof str, "New schedule set: %02d:%02d", newhour);
	SendClientMessage(playerid, -1, str);
	return true;
}

CMD:hud(playerid, params[]) {
	if (!g_TimeFlow[TimerHudShow]){
		for (new i = 0; i < sizeof text_TimerPlayer[]; i++) PlayerTextDrawHide(playerid, text_TimerPlayer[playerid][i]);
		g_TimeFlow[TimerHudShow] = true;
		SendClientMessage(playerid, -1, "Hud hour on!");
	}
	else {
		for (new i = 0; i < sizeof text_TimerPlayer[]; i++) PlayerTextDrawShow(playerid, text_TimerPlayer[playerid][i]);
		g_TimeFlow[TimerHudShow] = false;
		SendClientMessage(playerid, -1, "Hud hour off!");
	}
	return true;
}