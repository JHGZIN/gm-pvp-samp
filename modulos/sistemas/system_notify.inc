enum eNotify
{
	NotifyIcon,
	NotifyMessage[320],
	NotifySize
}
new InfoNotify[MAX_PLAYERS][3][eNotify];
new MaxPlayerNotify[MAX_PLAYERS];
new PlayerText:TextDrawNotifikasi[MAX_PLAYERS][3*13];
new IndexNotify[MAX_PLAYERS];

//=======[ NOTIFY ]=========//
forward HideNotify(playerid);
public HideNotify(playerid){
	if(!IndexNotify[playerid]) return 1;
	--IndexNotify[playerid];
	MaxPlayerNotify[playerid]--;
	for(new i=-1;++i<13;) PlayerTextDrawDestroy(playerid, TextDrawNotifikasi[playerid][(IndexNotify[playerid]*13)+i]);
	return 1;
}

stock ShowInfo(playerid, const pesan[])
	return ShowNotify(playerid, pesan, 1);
stock ShowError(playerid, const pesan[])
	return ShowNotify(playerid, pesan, 2);
stock SuccesMsg(playerid, const pesan[])
  	return ShowNotify(playerid, pesan, 3);
  	
stock PermissionError(playerid)
	return ShowError(playerid, "VOCE NAO TEM PERMISSAO!");

stock ShowNotify(const playerid, const string:message[], const icon){
	if(MaxPlayerNotify[playerid] == 3) return 1;
	MaxPlayerNotify[playerid]++;
	PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0);
	for(new x=-1; ++x <IndexNotify[playerid];)
	{
		for(new i=-1;++i<13;) PlayerTextDrawDestroy(playerid, TextDrawNotifikasi[playerid][(x*13) + i]);
		InfoNotify[playerid][IndexNotify[playerid]-x] = InfoNotify[playerid][(IndexNotify[playerid]-x)-1];
	}
	format(InfoNotify[playerid][0][NotifyMessage], 320, "%s", message);
	InfoNotify[playerid][0][NotifyIcon] = icon;
	InfoNotify[playerid][0][NotifySize] = 3;
	++IndexNotify[playerid];
	new Float:new_x=0.0;
	for(new x=-1;++x<IndexNotify[playerid];)
	{
		CreateNotify(playerid, x, x * 13, new_x);
		new_x += (InfoNotify[playerid][x][NotifySize]*7.25)+25.0;
	}
	SetTimerEx("HideNotify", 5000, false, "d", playerid);
	return 1;
}

stock CreateNotify(const playerid, index, i, const Float:new_x)
{
	new lines = InfoNotify[playerid][index][NotifySize];
	new Float:x = (lines * 10) + new_x;
	new Float:posisibaru = x+30.0;
	if(InfoNotify[playerid][index][NotifyIcon] == 1)
	{
		TextDrawNotifikasi[playerid][i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 33.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 517.000000, 146.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -7.500000, 25.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 618.000000, 143.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 7.000000, 30.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, -5.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 38.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 511.000000, 151.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -1.500000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 1097458175);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 139.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 14.000000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 1097458175);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 140.000000+posisibaru, "INFO");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.154165, 1.200000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 400.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 149.000000+posisibaru, InfoNotify[playerid][index][NotifyMessage]);
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.116665, 0.850000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 622.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
	    PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);
	}
	if(InfoNotify[playerid][index][NotifyIcon] == 2)
	{
	    TextDrawNotifikasi[playerid][i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 33.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 517.000000, 146.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -7.500000, 25.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 618.000000, 143.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 7.000000, 30.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, -5.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 38.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 511.000000, 151.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -1.500000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -16776961);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 139.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 14.000000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -16776961);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 140.000000+posisibaru, "ERRO");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.154165, 1.200000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 400.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 149.000000+posisibaru, InfoNotify[playerid][index][NotifyMessage]);
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.116665, 0.850000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 622.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
	    PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);
	}
	if(InfoNotify[playerid][index][NotifyIcon] == 3)
	{
        TextDrawNotifikasi[playerid][i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 33.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 506.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 133.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 608.000000, 162.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 20.000000, 21.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 517.000000, 146.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -7.500000, 25.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 618.000000, 143.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 7.000000, 30.500000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, -5.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 142.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 103.000000, 38.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 421278207);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 511.000000, 151.000000+posisibaru, "ld_dual:white");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], -1.500000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 16711935);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 516.000000, 139.000000+posisibaru, "ld_beat:chit");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 4);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.600000, 2.000000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 14.000000, 15.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], 16711935);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 140.000000+posisibaru, "SUCESSO");
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.154165, 1.200000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 400.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);

		TextDrawNotifikasi[playerid][++i] = CreatePlayerTextDraw(playerid, 530.000000, 149.000000+posisibaru, InfoNotify[playerid][index][NotifyMessage]);
		PlayerTextDrawFont(playerid, TextDrawNotifikasi[playerid][i], 2);
		PlayerTextDrawLetterSize(playerid, TextDrawNotifikasi[playerid][i], 0.116665, 0.850000);
		PlayerTextDrawTextSize(playerid, TextDrawNotifikasi[playerid][i], 622.000000, 17.000000);
		PlayerTextDrawSetOutline(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetShadow(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawAlignment(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawColor(playerid, TextDrawNotifikasi[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, TextDrawNotifikasi[playerid][i], 255);
		PlayerTextDrawBoxColor(playerid, TextDrawNotifikasi[playerid][i], 50);
		PlayerTextDrawUseBox(playerid, TextDrawNotifikasi[playerid][i], 0);
		PlayerTextDrawSetProportional(playerid, TextDrawNotifikasi[playerid][i], 1);
		PlayerTextDrawSetSelectable(playerid, TextDrawNotifikasi[playerid][i], 0);
	    PlayerTextDrawShow(playerid, TextDrawNotifikasi[playerid][i]);
	}
	return 1;
}