new
    Text:gtd_SpeedoMeter[2],
    timerUpdateSpeedoMeter[MAX_PLAYERS],
    PlayerText:barSpeedoMeter[MAX_PLAYERS],
    PlayerText:textSpeedoMeter[MAX_PLAYERS]
    ;

stock GetVehicleSpeed(vehicleid){
    new Float:xPos[3];
    GetVehicleVelocity(vehicleid, xPos[0], xPos[1], xPos[2]);
    return floatround(floatsqroot(xPos[0] * xPos[0] + xPos[1] * xPos[1] + xPos[2] * xPos[2]) * 170.00);
}

stock ShowPlayerSpeedoMeter(playerid){
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return;

    TextDrawShowForPlayer(playerid, gtd_SpeedoMeter[0]);
    TextDrawShowForPlayer(playerid, gtd_SpeedoMeter[1]);

    PlayerTextDrawSetString(playerid, textSpeedoMeter[playerid], "000");
    PlayerTextDrawShow(playerid, textSpeedoMeter[playerid]);

    PlayerTextDrawTextSize(playerid, barSpeedoMeter[playerid], 0.0, 8.0);
    PlayerTextDrawShow(playerid, barSpeedoMeter[playerid]);

    if (timerUpdateSpeedoMeter[playerid] != 0) KillTimer(timerUpdateSpeedoMeter[playerid]);
    timerUpdateSpeedoMeter[playerid] = 0;

    timerUpdateSpeedoMeter[playerid] = SetTimerEx("UpdatePlayerSpeedoMeter", 150, true, "i", playerid);
}

stock HidePlayerSpeedoMeter(playerid){
    KillTimer(timerUpdateSpeedoMeter[playerid]);

    TextDrawHideForPlayer(playerid, gtd_SpeedoMeter[0]);
    TextDrawHideForPlayer(playerid, gtd_SpeedoMeter[1]);

    PlayerTextDrawHide(playerid, textSpeedoMeter[playerid]);
    PlayerTextDrawHide(playerid, barSpeedoMeter[playerid]);
}

function UpdatePlayerSpeedoMeter(playerid){
    if (GetPlayerState(playerid) != PLAYER_STATE_DRIVER) {
        HidePlayerSpeedoMeter(playerid);
        return;
    }
    new
        str[4],
        vehicleid = GetPlayerVehicleID(playerid),
        modelid = GetVehicleModel(vehicleid),
        speed = GetVehicleSpeed(vehicleid)
    ;

    format(str, sizeof str, "%03i", speed);
    PlayerTextDrawSetString(playerid, textSpeedoMeter[playerid], str);
    PlayerTextDrawShow(playerid, textSpeedoMeter[playerid]);

    static const Float:VehiclesTopSpeed[] = { 157.0, 147.0, 186.0, 110.0, 133.0, 164.0, 110.0, 148.0, 100.0, 158.0, 129.0, 221.0, 168.0, 110.0, 105.0, 192.0, 154.0, 270.0, 115.0, 149.0, 145.0, 154.0, 140.0, 99.0,  135.0, 270.0, 173.0, 165.0, 157.0, 201.0, 190.0, 130.0, 94.0,  110.0, 167.0, 0.0,   149.0, 158.0, 142.0, 168.0, 136.0, 145.0, 139.0, 126.0, 110.0, 164.0, 270.0, 270.0, 111.0, 0.0,   0.0,   193.0, 270.0, 60.0,  135.0, 157.0, 106.0, 95.0,  157.0, 136.0, 270.0, 160.0, 111.0, 142.0, 145.0, 145.0, 147.0, 140.0, 144.0, 270.0, 157.0, 110.0, 190.0, 190.0, 149.0, 173.0, 270.0, 186.0, 117.0, 140.0, 184.0, 73.0,  156.0, 122.0, 190.0, 99.0,  64.0,  270.0, 270.0, 139.0, 157.0, 149.0, 140.0, 270.0, 214.0, 176.0, 162.0, 270.0, 108.0, 123.0, 140.0, 145.0, 216.0, 216.0, 173.0, 140.0, 179.0, 166.0, 108.0, 79.0,  101.0, 270.0, 270.0, 270.0, 120.0, 142.0, 157.0, 157.0, 164.0, 270.0, 270.0, 160.0, 176.0, 151.0, 130.0, 160.0, 158.0, 149.0, 176.0, 149.0, 60.0,  70.0,  110.0, 167.0, 168.0, 158.0, 173.0, 0.0,   0.0,   270.0, 149.0, 203.0, 164.0, 151.0, 150.0, 147.0, 149.0, 142.0, 270.0, 153.0, 145.0, 157.0, 121.0, 270.0, 144.0, 158.0, 113.0, 113.0, 156.0, 178.0, 169.0, 154.0, 178.0, 270.0, 145.0, 165.0, 160.0, 173.0, 146.0, 0.0,   0.0,   93.0,  60.0,  110.0, 60.0,  158.0, 158.0, 270.0, 130.0, 158.0, 153.0, 151.0, 136.0, 85.0,  0.0,   153.0, 142.0, 165.0, 108.0, 162.0, 0.0,   0.0,   270.0, 270.0, 130.0, 190.0, 175.0, 175.0, 175.0, 158.0, 151.0, 110.0, 169.0, 171.0, 148.0, 152.0, 0.0,   0.0,   0.0,   108.0, 0.0,   0.0 };

    PlayerTextDrawTextSize(playerid, barSpeedoMeter[playerid], ((96.0 * speed) / VehiclesTopSpeed[modelid - 400]), 8.0);
    PlayerTextDrawShow(playerid, barSpeedoMeter[playerid]);
}
