#define AC_MAX_CODES 51
#define AC_MAX_CODE_LENGTH (3 + 1)
#define AC_MAX_CODE_NAME_LENGTH (500)

new AC_MAX_MESSAGE[250];
new bool:AC_TPHACK[MAX_PLAYERS];

static const AC_CODE_NAME[AC_MAX_CODES][AC_MAX_CODE_NAME_LENGTH] =  
{ 
    {"AirBreak (onfoot)"}, //0
    {"AirBreak (in vehicle)"}, //1
    {"Teleport (onfoot)"}, //2
    {"Teleport (in vehicle)"}, //3
    {"Teleport (into/between vehicles)"}, //4
    {"Teleport (vehicle to player)"}, //5
    {"Teleport (pickups)"}, //6
    {"FlyHack (onfoot)"}, //7
    {"FlyHack (in vehicle)"}, //8
    {"SpeedHack (onfoot)"}, //9
    {"SpeedHack (in vehicle)"}, //10
    {"Health hack (in vehicle)"}, //11
    {"Health hack (onfoot)"}, //12
    {"Armour hack"}, //13
    {"Money hack"}, //14
    {"Ammo hack (add)"}, //15
    {"Ammo hack (infinite)"}, //16
    {"Special actions hack"}, //17
    {"GodMode from bullets (onfoot)"}, //18
    {"GodMode from bullets (in vehicle)"}, //19
    {"Invisible hack"}, //20
    {"Lagcomp-spoof"}, //21
    {"Tuning hack"}, //22
    {"Parkour mod"}, //23
    {"Quick turn"}, //24
    {"FakeSpawn"}, //25
    {"FakeKill"}, //26
    {"Pro Aim"}, //27
    {"CJ run"}, //28
    {"CarShot"}, //29
    {"CarJack"}, //30
    {"UnFreeze"}, //31
    {"AFK Ghost"}, //32
    {"Full Aiming"}, //33
    {"Fake NPC"}, //34
    {"Reconnect"}, //35
    {"High ping"}, //36
    {"Dialog hack"}, //37
    {"Sandbox"}, //38
    {"Invalid version"}, //39
    {"Rcon hack"}, //40
    {"Tuning crasher"}, //41
    {"Invalid seat crasher"}, //42
    {"Dialog crasher"}, //43
    {"Attached object crasher"}, //44
    {"Weapon Crasher"}, //45
    {"Connects to one slot"}, //46
    {"Flood callback functions"}, //47
    {"Flood change seat"}, //48
    {"Anti-DoS"}, //49
    {"Anti-NOPs"} //50
}; 

stock SendMessageToAdmin(const message[]) {
    foreach(new i : Player) {
        if (g_PlayerData[i][g_Admin] > 0) {
            SendClientMessage(i, -1, message);
        }        
    }
    return true;
}

forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code) {
    new DCC_Channel:logantcheat = DCC_FindChannelById(ANTCHEATCHANNEL_ID);

    if (type) BlockIpAddress(ip_address, 0);
    else {
        switch (code) {
            case 6, 14, 27, 28, 32, 35, 38, 40, 47, 48:
                return true;

            case 2: {
                if (!AC_TPHACK[playerid]) return true;

                format(AC_MAX_MESSAGE, sizeof(AC_MAX_MESSAGE),
                    "{007DFB}[ViridianGuard]: {FFFFFF}%s(%d) esta sendo acusado de possivel uso de cheat: %s (#%03d). Use '/tv %d' para verificar.",
                    PlayerName(playerid), g_PlayerData[playerid][g_AccId], AC_CODE_NAME[code], code, g_PlayerData[playerid][g_AccId]);
                SendMessageToAdmin(AC_MAX_MESSAGE);
                return true;
            }
            case 13, 15, 16: {
                if (!g_PlayerData[playerid][g_Emsala]) {
                    format(AC_MAX_MESSAGE, sizeof(AC_MAX_MESSAGE), 
                        "{007DFB}[ViridianGuard]: {FFFFFF}%s(%d) esta sendo acusado de possivel uso de cheat: %s (#%03d). Use '/tv %d' para verificar.",
                        GetPlayerNameEx(playerid), g_PlayerData[playerid][g_AccId], AC_CODE_NAME[code], code, g_PlayerData[playerid][g_AccId]);
                    SendMessageToAdmin(AC_MAX_MESSAGE);

                    if (code == 13) SetPlayerArmour(playerid, 0.0);
                    else ResetPlayerWeapons(playerid);
                }
                return true;
            }

            case 41:
                return SendClientMessage(playerid, 0xFF0000AA, UNKNOWN_CLIENT_MSG);

            default: {
                format(AC_MAX_MESSAGE, sizeof(AC_MAX_MESSAGE),
                    "[ViridianGuard]: Voce foi kickado por suspeita de uso de cheat: %s (#%03d)", AC_CODE_NAME[code], code);
                SendClientMessage(playerid, 0xFF0000AA, AC_MAX_MESSAGE);
                AntiCheatKickWithDesync(playerid, code);

                format(AC_MAX_MESSAGE, sizeof(AC_MAX_MESSAGE),
                    "Jogador(a): %s - #%d foi kickado(a) por suspeita de uso de cheat: %s (#%03d)",
                    PlayerName(playerid), g_PlayerData[playerid][g_AccId], AC_CODE_NAME[code], code);
                DCC_SendEmbedAntCheat(logantcheat, "ViridianGuard - Jogador kickado", AC_MAX_MESSAGE, GetPlayerSkin(playerid));

                format(AC_MAX_MESSAGE, sizeof(AC_MAX_MESSAGE),
                    "{007DFB}[ViridianGuard]: {FFFFFF}%s(%d) foi kickado(a) por suspeita de uso de cheat: %s (#%03d)",
                    PlayerName(playerid), g_PlayerData[playerid][g_AccId], AC_CODE_NAME[code], code);
                SendMessageToAdmin(AC_MAX_MESSAGE);
            }
        }
    }
    return true;
}