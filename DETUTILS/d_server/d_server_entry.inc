/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library which is providing
 *   generally server-related functions.
 *
 *
 */

#define PLAYER_CLIENT_UNKNOWN -1
#define PLAYER_CLIENT_ANDROID 0
#define PLAYER_CLIENT_PC 1

new 
	DET_g_Client[MAX_PLAYERS],
	DET_g_PedAnimsUsed = 0;

#define MAX_SERVERCFG_OPTIONS 1000

enum DET__ServerCfgInfo
{
	DET_e_Valid,
	DET_e_Name[64],
	DET_e_Value[1024]
}

new DET_g_ConfigCache[MAX_SERVERCFG_OPTIONS][DET__ServerCfgInfo];

/*
                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      
*/

#include "d_server_impl"

#if !defined DETUTILS_NO_SERVER_CFG

    #include "d_server_cfg"

#else

    #if !defined DETUTILS_NO_MODULE_WARNINGS

        #warning [DETUtils]: (includes) - Sublibrary (submodule) 'd_server_cfg' is disabled.

    #endif

#endif

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

public OnDETUtilsInit()
{
	LoadDETUtilsScript(DETUTILS_SCRIPT_SERVER);
	if(funcidx("d_srv_detutilsinit") != -1)
	{
		CallLocalFunction("d_srv_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_srv_detutilsinit(

forward d_srv_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_SERVER);
    if(funcidx("d_srv_detutilsexit") != -1)
    {
        CallLocalFunction("d_srv_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_srv_detutilsexit(

forward d_srv_detutilsexit();