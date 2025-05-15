#define MAX_CHATKILL_MESSAGES 5

new PlayerText:ChatKillTD[MAX_PLAYERS][MAX_CHATKILL_MESSAGES][3];
new ChatKillTimer[MAX_PLAYERS][MAX_CHATKILL_MESSAGES];
new ChatKillCount[MAX_PLAYERS];

stock InitChatKillSystem(playerid)
{
    for (new i = 0; i < MAX_CHATKILL_MESSAGES; i++)
    {
        new Float:baseY = 230.0 - (i * 20.0);

        ChatKillTD[playerid][i][0] = CreatePlayerTextDraw(playerid, 70.000, baseY, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, ChatKillTD[playerid][i][0], 87.000, 17.000);
        PlayerTextDrawColor(playerid, ChatKillTD[playerid][i][0], 286331391);
        PlayerTextDrawBackgroundColor(playerid, ChatKillTD[playerid][i][0], 255);
        PlayerTextDrawFont(playerid, ChatKillTD[playerid][i][0], 4);
        PlayerTextDrawSetProportional(playerid, ChatKillTD[playerid][i][0], 1);

        ChatKillTD[playerid][i][1] = CreatePlayerTextDraw(playerid, 70.000, baseY, "LD_TATT:9gun2");
        PlayerTextDrawTextSize(playerid, ChatKillTD[playerid][i][1], 13.000, 17.000);
        PlayerTextDrawColor(playerid, ChatKillTD[playerid][i][1], 8438015);
        PlayerTextDrawFont(playerid, ChatKillTD[playerid][i][1], 4);
        PlayerTextDrawSetProportional(playerid, ChatKillTD[playerid][i][1], 1);

        ChatKillTD[playerid][i][2] = CreatePlayerTextDraw(playerid, 85.000, baseY + 1.0, "");
        PlayerTextDrawLetterSize(playerid, ChatKillTD[playerid][i][2], 0.119, 1.200);
        PlayerTextDrawColor(playerid, ChatKillTD[playerid][i][2], -1);
        PlayerTextDrawFont(playerid, ChatKillTD[playerid][i][2], 1);
        PlayerTextDrawSetProportional(playerid, ChatKillTD[playerid][i][2], 1);
    }

    ChatKillCount[playerid] = 0;
    return true;
}

stock ShowChatKill(playerid, const killer[], const victim[])
{
    new slot = ChatKillCount[playerid];

    if (slot >= MAX_CHATKILL_MESSAGES)
    {
        for (new i = 1; i < MAX_CHATKILL_MESSAGES; i++)
        {
            for (new j = 0; j < 3; j++)
            {
            	new msg[64];
    			format(msg, sizeof(msg), "%s matou %s", killer, victim);
                PlayerTextDrawSetString(playerid, ChatKillTD[playerid][i - 1][j], msg);
            }
        }
        slot = MAX_CHATKILL_MESSAGES - 1;
    }

    new msg[64];
    format(msg, sizeof(msg), "%s matou %s", killer, victim);
    PlayerTextDrawSetString(playerid, ChatKillTD[playerid][slot][2], msg);

    for (new i = 0; i < 3; i++)
    {
        PlayerTextDrawShow(playerid, ChatKillTD[playerid][slot][i]);
    }

    if (ChatKillTimer[playerid][slot]) KillTimer(ChatKillTimer[playerid][slot]);
    ChatKillTimer[playerid][slot] = SetTimerEx("HideChatKillSlot", 5000, false, "dd", playerid, slot);

    if (ChatKillCount[playerid] < MAX_CHATKILL_MESSAGES) ChatKillCount[playerid]++;
    return true;
}

function HideChatKillSlot(playerid, slot)
{
    for (new i = 0; i < 3; i++)
    {
        PlayerTextDrawHide(playerid, ChatKillTD[playerid][slot][i]);
    }
    ChatKillTimer[playerid][slot] = 0;
    if (ChatKillCount[playerid] > 0) ChatKillCount[playerid]--;
    return true;
}
