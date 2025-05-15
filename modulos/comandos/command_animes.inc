CMD:anins(playerid)
{
	SendClientMessage(playerid, COR_GERAL, "Lista de Animes :");
	SendClientMessage(playerid, -1, "{858585}> {FFFFFF}/renderse > /ligar > /desligar > /bebado > /bomba > /apontar > /merda > /mascararse");
	SendClientMessage(playerid, -1, "{858585}> {FFFFFF}/roubar > /cruzarb > /deitar > /abaixar > /vomitar > /comer > /rap > /passaramao");
	SendClientMessage(playerid, -1, "{858585}> {FFFFFF}/cobrar > /overdose > /fumar > /observar > /sentar > /conversar > /fodase > /taichi");
	return 1;
}
CMD:panim(playerid)
{
	ClearAnimations(playerid, 0);
	SCM(playerid, COLOR_REDD, "| VIRIDIAN Anins|: {FFFFFF}Voce parou de fazer animacoes!");
	return 1;
}
CMD:renderse(playerid)
{
	if(gettime() < GetPVarInt(playerid, "AntFloodText"))
    {
        SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {858585}Aguarde 5 Segundos para usar o comando novamente");
        return true;
    }
	SetPVarInt(playerid, "AntFloodText", gettime()+5);
	SetPlayerSpecialAction(playerid, 10);
	return 1;
}
CMD:ligar(playerid)
{
	if(gettime() < GetPVarInt(playerid, "AntFloodText"))
    {
        SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {858585}Aguarde 5 Segundos para usar o comando novamente");
        return true;
    }
	SetPVarInt(playerid, "AntFloodText", gettime()+5);
	SetPlayerSpecialAction(playerid, 11);
	return 1;
}
CMD:desligar(playerid)
{
	if(gettime() < GetPVarInt(playerid, "AntFloodText"))
    {
        SCM(playerid, COLOR_REDD, "[ VIRIDIAN PvP ]: {858585}Aguarde 5 Segundos para usar o comando novamente");
        return true;
    }
	SetPVarInt(playerid, "AntFloodText", gettime()+5);
	SetPlayerSpecialAction(playerid, 13);
	return 1;
}
CMD:bebado(playerid)
{
	AnimBebado(playerid);

	return 1;
}

stock AnimBebado(playerid){
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 0, 1);
	return true;
}
CMD:bomba(playerid)
{
	AnimBomba(playerid);
	return 1;
}
stock AnimBomba(playerid){
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:apontar(playerid)
{

	AnimApontar(playerid);
	return 1;
}
stock AnimApontar(playerid){
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1, 1);
	return true;
}
CMD:merda(playerid)
{

	AnimMerda(playerid);
	return 1;
}
stock AnimMerda(playerid){
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:mascara(playerid)
{

	AnimMascara(playerid);
	return 1;
}
stock AnimMascara(playerid){
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:roubar(playerid)
{
	AnimRoubar(playerid);
	return 1;
}
stock AnimRoubar(playerid){
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:cruzarbraco(playerid)
{
	AnimCruzarBraco(playerid);
	return 1;
}
stock AnimCruzarBraco(playerid){
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1, 1);
	return true;
}

CMD:deitar(playerid)
{

	AnimDeitar(playerid);
	return 1;
}
stock AnimDeitar(playerid){
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "bather", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:abaixar(playerid)
{
	AnimAbaixar(playerid);
	return 1;
}
stock AnimAbaixar(playerid){
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:vomitar(playerid)
{

	AnimVomitar(playerid);
	return 1;
}
stock AnimVomitar(playerid){
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:comer(playerid)
{
	AnimComer(playerid);
	return 1;
}
stock AnimComer(playerid){
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "FOOD", "EAT_Burger", 3.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:rap(playerid)
{
	AnimRap(playerid);
	return 1;
}
stock AnimRap(playerid){
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:passaramao(playerid)
{
	AnimPassarMao(playerid);
	return 1;
}
stock AnimPassarMao(playerid){
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:cobrar(playerid)
{
	AnimCobrar(playerid);
	return 1;
}
stock AnimCobrar(playerid){
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:overdose(playerid)
{
	AnimOver(playerid);
	return 1;
}
stock AnimOver(playerid){
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:fumar(playerid)
{
	AnimFumar(playerid);
	return 1;
}
stock AnimFumar(playerid){
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:sentar(playerid)
{
	AnimSentar(playerid);
	return 1;
}
stock AnimSentar(playerid){
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:conversar(playerid)
{
	AnimChat(playerid);
	return 1;
}
stock AnimChat(playerid){
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:fodase(playerid)
{
 	AnimFodase(playerid);
	return 1;
}
stock AnimFodase(playerid){
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);
	return true;
}
CMD:taichi(playerid)
{
	AnimTaichi(playerid);
	return 1;
}
stock AnimTaichi(playerid){
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
CMD:observar(playerid)
{
	AnimObservar(playerid);
	return 1;
}
stock AnimObservar(playerid){
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	ApplyAnimation(playerid, "BAR", "dnk_stndF_loop", 4.0, 1, 0, 0, 0, 0, 1);
	return true;
}
