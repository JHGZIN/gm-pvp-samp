new MySQL:DBConn;

new fAutoC[MAX_PLAYERS];

//Anti C-Bug
new bool:pCBugging[MAX_PLAYERS];
new ptmCBugFreezeOver[MAX_PLAYERS];
new ptsLastFiredWeapon[MAX_PLAYERS];

new String[3500];
new MEGAString[9999];

new realchat = 1;

//=============| Martelinho Admin |========================
new bool:UmMartelinho[MAX_PLAYERS]; //Player name array

new bool:flying[MAX_PLAYERS];

new NomeServer[][] =
{
	"[VIRIDIAN PvP] Melhor PvP Do Brasil.",
	"VIRIDIAN PvP - [PC/Android]",
	"[VIRIDIAN PvP] Sua diversao comeca aqui."
};

/* | => Sistema de Velocimetro <= | */
new bool:PlayerVelocimetro[MAX_PLAYERS];

new PlayerVelocimetroTimer[MAX_PLAYERS];

new Mensagenscima[][] =
{
	"{007DFB}[VIRIDIAN PvP]:{FFFFFF} Que saber todos os comando do Servidor> use: (/comandos)",
	"{007DFB}[VIRIDIAN PvP]:{FFFFFF} Que interagir com os players use: (/ds)",
	"{007DFB}[VIRIDIAN PvP]:{FFFFFF} Nao faca DM em Spawn Isso e motivo de BAN.",
	"{007DFB}[VIRIDIAN PvP]:{FFFFFF} Que acessar nosso discord Link: (https://discord.gg/viridianpvp)"
    //"{007DFB}[VIRIDIAN PvP]:{FFFFFF} Compre vip para ajudar o servidor "

};

enum VehicleData{
    VehicleName[25],
    VehicleModification[25]
};

new VehicleNames[][VehicleData] =
{
    {"Landstalker", "Transfender"},{"Bravura", "Transfender"},{"Buffalo", "Transfender"},{"Linerunner", "none"},{"Perrenial", "Transfender"},{"Sentinel", "Transfender"},{"Dumper", "none"},
    {"Firetruck", "none"},{"Trashmaster", "none"},{"Stretch", "Transfender"},{"Manana", "Transfender"},{"Infernus", "Transfender"},{"Voodoo", "Loco low co"},{"Pony", "none"},{"Mule", "none"},
    {"Cheetah", "Transfender"},{"Ambulance", "none"},{"Leviathan", "none"},{"Moonbeam", "Transfender"},{"Esperanto", "Transfender"},{"Taxi", "Transfender"},{"Washington", "Transfender"},
    {"Bobcat", "Transfender"},{"Mr Whoopee", "none"},{"BF Injection", "none"},{"Hunter", "none"},{"Premier", "Transfender"},{"Enforcer", "none"},{"Securicar", "none"},
    {"Banshee", "Transfender"},{"Predator", "none"},{"Bus", "none"},{"Rhino", "none"},{"Barracks", "none"},{"Hotknife", "none"},{"Trailer 1", "none"},{"Previon", "Transfender"},
    {"Coach", "none"},{"Cabbie", "Transfender"},{"Stallion", "Transfender"},{"Rumpo", "none"},{"RC Bandit", "none"},{"Romero", "Transfender"},{"Packer", "none"},{"Monster", "none"},
    {"Admiral", "Transfender"},{"Squalo", "none"},{"Seasparrow", "none"},{"Pizzaboy", "none"},{"Tram", "none"},{"Trailer 2", "none"},{"Turismo", "Transfender"},
    {"Speeder", "none"},{"Reefer", "none"},{"Tropic", "none"},{"Flatbed", "none"},{"Yankee", "none"},{"Caddy", "none"},{"Solair", "Transfender"},{"Berkley's RC Van", "none"},
    {"Skimmer", "none"},{"PCJ-600", "none"},{"Faggio", "none"},{"Freeway", "none"},{"RC Baron", "none"},{"RC Raider", "none"},{"Glendale", "Transfender"},{"Oceanic", "Transfender"},
    {"Sanchez", "none"},{"Sparrow", "none"},{"Patriot", "none"},{"Quad", "none"},{"Coastguard", "none"},{"Dinghy", "none"},{"Hermes", "Transfender"},{"Sabre", "Transfender"},
    {"Rustler", "none"},{"ZR-350", "Transfender"},{"Walton", "Transfender"},{"Regina", "Transfender"},{"Comet", "Transfender"},{"BMX", "none"},{"Burrito", "none"},{"Camper", "none"},{"Marquis", "none"},
    {"Baggage", "none"},{"Dozer", "none"},{"Maverick", "none"},{"News Chopper", "none"},{"Rancher", "Transfender"},{"FBI Rancher", "none"},{"Virgo", "Transfender"},{"Greenwood", "Transfender"},
    {"Jetmax", "none"},{"Hotring", "none"},{"Sandking", "none"},{"Blista Compact", "Transfender"},{"Police Maverick", "none"},{"Boxville", "none"},{"Benson", "none"},
    {"Mesa", "Transfender"},{"RC Goblin", "none"},{"Hotring Racer A", "none"},{"Hotring Racer B", "none"},{"Bloodring Banger", "none"},{"Rancher", "none"},
    {"Super GT", "Transfender"},{"Elegant", "Transfender"},{"Journey", "none"},{"Bike", "none"},{"Mountain Bike", "none"},{"Beagle", "none"},{"Cropdust", "none"},{"Stunt", "none"},
    {"Tanker", "none"}, {"Roadtrain", "none"},{"Nebula", "Transfender"},{"Majestic", "Transfender"},{"Buccaneer", "Transfender"},{"Shamal", "none"},{"Hydra", "none"},{"FCR-900", "none"},
    {"NRG-500", "none"},{"HPV1000", "none"},{"Cement Truck", "none"},{"Tow Truck", "none"},{"Fortune", "Transfender"},{"Cadrona", "Transfender"},{"FBI Truck", "none"},
    {"Willard", "Transfender"},{"Forklift", "none"},{"Tractor", "none"},{"Combine", "none"},{"Feltzer", "Transfender"},{"Remington", "Loco low co"},{"Slamvan", "Loco low co"},
    {"Blade", "Loco low co"},{"Freight", "none"},{"Streak", "none"},{"Vortex", "none"},{"Vincent", "Transfender"},{"Bullet", "Transfender"},{"Clover", "Transfender"},{"Sadler", "none"},
    {"Firetruck LA", "none"},{"Hustler", "Transfender"},{"Intruder", "Transfender"},{"Primo", "Transfender"},{"Cargobob", "none"},{"Tampa", "Transfender"},{"Sunrise", "Transfender"},{"Merit", "Transfender"},
    {"Utility", "none"},{"Nevada", "none"},{"Yosemite", "none"},{"Windsor", "Transfender"},{"Monster A", "none"},{"Monster B", "none"},{"Uranus", "Wheel Arch Angels"},{"Jester", "Wheel Arch Angels"},
    {"Sultan", "Wheel Arch Angels"},{"Stratum", "Wheel Arch Angels"},{"Elegy", "Wheel Arch Angels"},{"Raindance", "none"},{"RC Tiger", "none"},{"Flash", "Wheel Arch Angels"},{"Tahoma", "Loco low co"},{"Savanna", "Loco low co"},
    {"Bandito", "none"},{"Freight Flat", "none"},{"Streak Carriage", "none"},{"Kart", "none"},{"Mower", "none"},{"Duneride", "none"},{"Sweeper", "none"},
    {"Broadway", "Loco low Co"},{"Tornado", "Loco low Co"},{"AT-400", "none"},{"DFT-30", "none"},{"Huntley", "Transfender"},{"Stafford", "Transfender"},{"BF-400", "none"},{"Newsvan", "none"},
    {"Tug", "none"},{"Trailer 3", "none"},{"Emperor", "Transfender"},{"Wayfarer", "none"},{"Euros", "Transfender"},{"Hotdog", "none"},{"Club", "Transfender"},{"Freight Carriage", "none"},
    {"Trailer 3", "none"},{"Andromada", "none"},{"Dodo", "none"},{"RC Cam", "none"},{"Launch", "none"},{"Police Car (LSPD)", "none"},{"Police Car (SFPD)", "none"},
    {"Police Car (LVPD)", "none"},{"Police Ranger", "none"},{"Picador", "Transfender"},{"S.W.A.T. Van", "none"},{"Alpha", "Transfender"},{"Phoenix", "Transfender"},{"Glendale", "none"},
    {"Sadler", "none"},{"Luggage Trailer A", "none"},{"Luggage Trailer B", "none"},{"Stair Trailer", "none"},{"Boxville", "none"},{"Farm Plow", "none"},
    {"Utility Trailer", "none"}
};

/* =========================================== */

//Mundos mais jogados

new JogadoresArena[4];
new JogadoresMundo[4];

#define TEMPO_INATIVIDADE 20 // 5 minutos (em segundos)

new ultimoMovimento[MAX_PLAYERS];
new bool:estaAFK[MAX_PLAYERS];
new inicioAFK[MAX_PLAYERS];

new Float:PosArenaM4[6][4] = {
    {293.432525,176.226547,1007.171875,69.229820},
    {246.597885,189.396194,1008.171875,318.054748},
    {239.678451,143.212509,1003.023437,349.166839},
    {209.867385,142.011672,1003.023437,275.234680},
    {190.234649,157.576950,1003.023437,267.433013},
    {229.501663,182.211166,1003.031250,140.780014}
};

new Float:Posdescequebra[4][4] = {
    {2454.016357,114.556838,26.123525,119.499893},
    {2465.321044,-33.213405,26.129068,119.499893},
    {2342.853271,-104.910041,26.146219,119.499893},
    {2222.721435,-23.688007,26.129076,119.499893}
};