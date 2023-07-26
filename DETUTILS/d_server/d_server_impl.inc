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
