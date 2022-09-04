/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An excel-like table management system.
 *
 *
 */

#define DEFAULT_PLAYER_PERMISSIONS \
 (PLAYER_PERMISSION_SENDMESSAGES | PLAYER_PERMISSION_USECOMMANDS | \
	PLAYER_PERMISSION_USEDIALOGS | PLAYER_PERMISSION_USEVEHICLES | \ 
	PLAYER_PERMISSION_BUNNYHOP)

#define PLAYER_PERMISSION_SENDMESSAGES 0x1
#define PLAYER_PERMISSION_USECOMMANDS 0x2
#define PLAYER_PERMISSION_USEDIALOGS 0x4
#define PLAYER_PERMISSION_USEVEHICLES 0x8
#define PLAYER_PERMISSION_BUNNYHOP 0x10

new DET_g_PlayerPermissions[MAX_PLAYERS];

forward OnPlayerPermissionIntegerChange(playerid, oldpermissions, newpermissions);
forward OnPlayerInsufficientPermissions(playerid, missingpermission);

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

stock SetPlayerPermissionInteger(playerid, permissions)
{
	CallLocalFunction("OnPlayerPermissionIntegerChange", "iii", 
		playerid,
		DET_g_PlayerPermissions[playerid],
		permissions);
	DET_g_PlayerPermissions[playerid] = permissions;
	return 1;
}

// SENDMESSAGES

public OnPlayerText(playerid, text[])
{
	if(!(PLAYER_PERMISSION_SENDMESSAGES & DET_g_PlayerPermissions[playerid]))
	{
		CallLocalFunction("OnPlayerInsufficientPermissions",
			"ii",
			playerid,
			PLAYER_PERMISSION_SENDMESSAGES);
		return 0;
	}
	if(funcidx("d_perm_onplayertext") != -1)
	{
		CallLocalFunction("d_perm_onplayertext", "is", playerid, text);
	}
	return 1;
}

#if defined _ALS_OnPlayerText
	#undef OnPlayerText
#else
	#define _ALS_OnPlayerText
#endif

#define OnPlayerText( d_perm_onplayertext(

forward d_perm_onplayertext(playerid, text[]);

// USECOMMANDS

public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!(PLAYER_PERMISSION_USECOMMANDS & DET_g_PlayerPermissions[playerid]))
	{
		CallLocalFunction("OnPlayerInsufficientPermissions",
			"ii",
			playerid,
			PLAYER_PERMISSION_USECOMMANDS);
		return 0;
	}
	if(funcidx("d_perm_onplayercmdtext") != -1)
	{
		CallLocalFunction("d_perm_onplayercmdtext", "is", playerid, cmdtext);
	}
	return 1;
}

#if defined _ALS_OnPlayerCommandText
	#undef OnPlayerCommandText
#else
	#define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText( d_perm_onplayercmdtext(

forward d_perm_onplayercmdtext(playerid, cmdtext[]);

// USEDIALOGS

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(!(PLAYER_PERMISSION_USEDIALOGS & DET_g_PlayerPermissions[playerid]))
	{
		CallLocalFunction("OnPlayerInsufficientPermissions",
			"ii",
			playerid,
			PLAYER_PERMISSION_USEDIALOGS);
		return 0;
	}
	if(funcidx("d_perm_ondialogresp") != -1)
	{
		CallLocalFunction("d_perm_ondialogresp", "iiiis", 
			playerid,
			dialogid,
			response,
			listitem,
			inputtext);
	}
	return 1;
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse( d_perm_ondialogresp(

forward d_perm_ondialogresp(playerid, dialogid, response, listitem, inputtext[]);

// USEVEHICLES

public OnPlayerUpdate(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		if(!(PLAYER_PERMISSION_USEVEHICLES & DET_g_PlayerPermissions[playerid]))
		{
			CallLocalFunction("OnPlayerInsufficientPermissions",
				"ii",
				playerid,
				PLAYER_PERMISSION_USEVEHICLES);
			RemovePlayerFromVehicle(playerid);
			return 0;
		}
	}
	if(funcidx("d_perm_playerupdate") != -1)
	{
		CallLocalFunction("d_perm_playerupdate", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate( d_perm_playerupdate(

forward d_perm_playerupdate(playerid);

// BUNNYHOP

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(!(PLAYER_PERMISSION_BUNNYHOP & DET_g_PlayerPermissions[playerid]))
	{
		if(!IsPlayerInAnyVehicle(playerid) && newkeys & KEY_JUMP && oldkeys & KEY_SPRINT)
		{
			CallLocalFunction("OnPlayerInsufficientPermissions",
				"ii",
				playerid,
				PLAYER_PERMISSION_BUNNYHOP);

			TogglePlayerControllable(playerid, false);
			SetTimerEx("d_perms_playercontrol", 1000, false, "i", playerid);
			return 1;
		}
	}
	if(funcidx("d_perm_keystatechange") != -1)
	{
		CallLocalFunction("d_perm_keystatechange", "iii", playerid, newkeys, oldkeys);
	}
	return 1;
}

forward d_perms_playercontrol(playerid);
public d_perms_playercontrol(playerid)
{
	return TogglePlayerControllable(playerid, true);
}

#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange( d_perm_keystatechange(

forward d_perm_keystatechange(playerid, newkeys, oldkeys);

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
	#if defined DETUTILS_DEBUG_MODE
	SaveLogIntoFile("detutils_permissions.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_permissions.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_PERMISSIONS);
	if(funcidx("d_perm_detutilsinit") != -1)
	{
		CallLocalFunction("d_perm_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_perm_detutilsinit(

forward d_perm_detutilsinit();

public OnDETUtilsExit()
{
	UnloadDETUtilsScript(DETUTILS_SCRIPT_PERMISSIONS);
	if(funcidx("d_perm_detutilsexit") != -1)
	{
		CallLocalFunction("d_perm_detutilsexit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsExit
	#undef OnDETUtilsExit
#else
	#define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_perm_detutilsexit(

forward d_perm_detutilsexit();