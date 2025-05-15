#define FALCONGUARD_NOTIFICACAO (0)
#define FALCONGUARD_EXPULSAO (1)
#define FALCONGUARD_BANIMENTO (2)

forward OnFalconGuardCheat(playerid, type, const feature[]);

/*

                    .o.        ooooo        .oooooo..o 
                    .888.      `888'        d8P'    `Y8 
                    .8"888.      888         Y88bo.      
                    .8' `888.     888          `"Y8888o.  
                    .88ooo8888.    888              `"Y88b 
                    .8'     `888.   888       o oo     .d8P 
                    o88o     o8888o o888ooooood8 8""88888P'  

*/

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif

#if defined _ALS_SetVehiclePos
    #undef SetVehiclePos
#else
    #define _ALS_SetVehiclePos
#endif

#if defined _ALS_SpawnPlayer
    #undef SpawnPlayer
#else
    #define _ALS_SpawnPlayer
#endif

#if defined _ALS_PutPlayerInVehicle
    #undef PutPlayerInVehicle
#else
    #define _ALS_PutPlayerInVehicle
#endif

#if defined _ALS_SetPlayerSkin
    #undef SetPlayerSkin
#else
    #define _ALS_SetPlayerSkin
#endif

#if defined _ALS_CreateVehicle
    #undef CreateVehicle
#else
    #define _ALS_CreateVehicle
#endif

#if defined _ALS_AddStaticVehicle
    #undef AddStaticVehicle
#else
    #define _ALS_AddStaticVehicle
#endif

#if defined _ALS_AddStaticVehicleEx
    #undef AddStaticVehicleEx
#else
    #define _ALS_AddStaticVehicleEx
#endif

#if defined _ALS_DestroyVehicle
    #undef DestroyVehicle
#else
    #define _ALS_DestroyVehicle
#endif

#if defined _ALS_SetVehicleHealth
    #undef SetVehicleHealth
#else
    #define _ALS_SetVehicleHealth
#endif

#if defined _ALS_RepairVehicle
    #undef RepairVehicle
#else
    #define _ALS_RepairVehicle
#endif

#if defined _ALS_GivePlayerWeapon
    #undef GivePlayerWeapon
#else
    #define _ALS_GivePlayerWeapon
#endif

#if defined _ALS_SetPlayerAmmo
    #undef SetPlayerAmmo
#else
    #define _ALS_SetPlayerAmmo
#endif

#if defined _ALS_ResetPlayerWeapons
    #undef ResetPlayerWeapons
#else
    #define _ALS_ResetPlayerWeapons
#endif

#if defined _ALS_ResetPlayerMoney
    #undef ResetPlayerMoney
#else
    #define _ALS_ResetPlayerMoney
#endif

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif

#if defined _ALS_GetPlayerMoney
    #undef GetPlayerMoney
#else
    #define _ALS_GetPlayerMoney
#endif

#if defined _ALS_ChangeVehicleColor
    #undef ChangeVehicleColor
#else
    #define _ALS_ChangeVehicleColor
#endif

#if defined _ALS_SetPlayerHealth
    #undef SetPlayerHealth
#else
    #define _ALS_SetPlayerHealth
#endif

#if defined _ALS_TogglePlayerSpectating
    #undef TogglePlayerSpectating
#else
    #define _ALS_TogglePlayerSpectating
#endif

#if defined _ALS_SetPlayerScore
    #undef SetPlayerScore
#else
    #define _ALS_SetPlayerScore
#endif

#if defined _ALS_SetSpawnInfo
    #undef SetSpawnInfo
#else
    #define _ALS_SetSpawnInfo
#endif

/*

                    .oooooo..o ooooooooooooo   .oooooo.     .oooooo.   oooo    oooo  .oooooo..o 
                    d8P'    `Y8 8'   888   `8  d8P'  `Y8b   d8P'  `Y8b  `888   .8P'  d8P'    `Y8 
                    Y88bo.           888      888      888 888           888  d8'    Y88bo.      
                    `"Y8888o.       888      888      888 888           88888[       `"Y8888o.  
                        `"Y88b      888      888      888 888           888`88b.         `"Y88b 
                    oo     .d8P      888      `88b    d88' `88b    ooo   888  `88b.  oo     .d8P 
                    8""88888P'      o888o      `Y8bood8P'   `Y8bood8P'  o888o  o888o 8""88888P'  

*/



/*

                    ooooooooo.   oooooooooooo oooooooooo.   oooooooooooo oooooooooooo ooooo ooooo      ooo oooooooooooo 
                    `888   `Y88. `888'     `8 `888'   `Y8b  `888'     `8 `888'     `8 `888' `888b.     `8' `888'     `8 
                    888   .d88'  888          888      888  888          888          888   8 `88b.    8   888         
                    888ooo88P'   888oooo8     888      888  888oooo8     888oooo8     888   8   `88b.  8   888oooo8    
                    888`88b.     888    "     888      888  888    "     888    "     888   8     `88b.8   888    "    
                    888  `88b.   888       o  888     d88'  888       o  888          888   8       `888   888       o 
                    o888o  o888o o888ooooood8 o888bood8P'   o888ooooood8 o888o        o888o o8o        `8  o888ooooood8 

*/