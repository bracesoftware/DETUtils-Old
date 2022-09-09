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

stock d_server_UsePlayerPedAnims()
{
	DET_g_PedAnimsUsed = 1;
	return UsePlayerPedAnims();
}

stock ArePlayerPedAnimsUsed()
{
	return DET_g_PedAnimsUsed;
}

#if defined _ALS_UsePlayerPedAnims
	#undef UsePlayerPedAnims
#else
	#define _ALS_UsePlayerPedAnims
#endif

#define UsePlayerPedAnims d_server_UsePlayerPedAnims

/* =========================================== */

#if !defined DETUTILS_NO_ANDROID_CHECK

#if !defined SendClientCheck

	native SendClientCheck(playerid, type, memAddr, memOffset, byteCount);

#endif

stock d_svr_SendClientCheck(playerid, type, memAddr, memOffset, byteCount)
{
	if(funcidx("OnPlayerClientCheckReceived") != -1)
	{
		CallLocalFunction("OnPlayerClientCheckReceived",
			"iiiii",
			playerid, type, memAddr, memOffset, byteCount);
	}
	return SendClientCheck(playerid, type, memAddr, memOffset, byteCount);
}

#if defined _ALS_SendClientCheck
	#undef SendClientCheck
#else
	#define _ALS_SendClientCheck
#endif

#define SendClientCheck d_svr_SendClientCheck

/* =========================================== */

forward OnPlayerClientCheckReceived(playerid, type, memaddr, memoffset, bytecount);
forward OnPlayerClientCheckPerformed(playerid, actionid, memaddr, retndata);

/* =========================================== */

public OnPlayerConnect(playerid)
{
	DET_g_Client[playerid] = PLAYER_CLIENT_UNKNOWN;
	SendClientCheck(playerid, 0x48, 0, 0, 2);
	if(funcidx("d_svr_OnPlayerConnect") != -1)
	{
		CallLocalFunction("d_svr_OnPlayerConnect", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect d_svr_OnPlayerConnect

forward d_svr_OnPlayerConnect(playerid);

/* =========================================== */

forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);
public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
{
	if(actionid == 0x48)
	{
		if(memaddr == 0) 
		{
			DET_g_Client[playerid] = PLAYER_CLIENT_ANDROID;
		}
		else if(memaddr != 0)
		{
			DET_g_Client[playerid] = PLAYER_CLIENT_PC;
		}
	}
	if(funcidx("OnPlayerClientCheckPerformed") != -1)
	{
		CallLocalFunction("OnPlayerClientCheckPerformed", "iiii", playerid, actionid, memaddr, retndata);
	}
	if(funcidx("d_svr_OnClientCheckResponse") != -1)
	{
		CallLocalFunction("d_svr_OnClientCheckResponse", "iiii", playerid, actionid, memaddr, retndata);
	}
	return 1;
}

#if defined _ALS_OnClientCheckResponse
	#undef OnClientCheckResponse
#else
	#define _ALS_OnClientCheckResponse
#endif

#define OnClientCheckResponse d_svr_OnClientCheckResponse

forward d_svr_OnClientCheckResponse(playerid, actionid, memaddr, retndata);

/* =========================================== */

stock bool:IsPlayerUsingPCClient(playerid)
{
	if(DET_g_Client[playerid] == PLAYER_CLIENT_PC) return true;
	return false;
}

stock bool:IsPlayerUsingAndroidClient(playerid)
{
	if(DET_g_Client[playerid] == PLAYER_CLIENT_ANDROID) return true;
	return false;
}

stock GetPlayerClient(playerid)
{
	return DET_g_Client[playerid];
}

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