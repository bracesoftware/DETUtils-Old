/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides anti-cheat
 *   system for SA:MP.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
	#error [DETUtils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

#if defined d_anticheat_included
	
	#endinput

#endif

#define d_anticheat_included

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

// Variables:

new DET_g_AntiCheatTimer;

// Macros:

#define DETUTILS_AC__%1check:(%0); \
	if(gAntiCheatToggled == 0) return print(\
	"[DETUtils]: (debug) - Function '%0' wasn't executed because anti-cheat system is OFF.");

// Cheat defines:

#define INVALID_CHEAT_TYPE -1 // Currently, there's no use of it.
#define CHEAT_TYPE_MONEY 0
#define CHEAT_TYPE_SKINCHANGER 1
#define CHEAT_TYPE_TELEPORT 2
#define CHEAT_TYPE_HIGHPING 3
#define CHEAT_TYPE_HEALTH 4
#define CHEAT_TYPE_ARMOUR 5
#define CHEAT_TYPE_SPEEDHACK 6
#define CHEAT_TYPE_DIALOG 7
#define CHEAT_TYPE_MENU 8

// Functions:

static stock d_ac_IsPlayerNearSprunk(playerid)
{
	if(IsPlayerInRangeOfPoint(playerid, 4, -2420.219, 984.578, 44.297)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2420.180, 985.945, 44.297)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2225.203, -1153.422, 1025.906)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2576.703, -1284.430, 1061.094)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2155.906, 1606.773, 1000.055)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2209.906, 1607.195, 1000.055)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2222.203, 1606.773, 1000.055)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 495.969, -24.320, 1000.734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 501.828, -1.430, 1000.734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 373.828, -178.141, 1000.734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 330.680, 178.500, 1020.070)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 331.922, 178.500, 1020.070)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 350.906, 206.086, 1008.477)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 361.563, 158.617, 1008.477)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 371.594, 178.453, 1020.070)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 374.891, 188.977, 1008.477)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2155.844, 1607.875, 1000.063)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2202.453, 1617.008, 1000.063)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2209.242, 1621.211, 1000.063)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2222.367, 1602.641, 1000.063)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 500.563, -1.367, 1000.734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 379.039, -178.883, 1000.734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2480.86,-1959.27,12.9609)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1634.11,-2237.53,12.8906)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2139.52,-1161.48,23.3594)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2153.23,-1016.15,62.2344)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -1350.12,493.859,10.5859)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2229.19,286.414,34.7031)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1659.46,1722.86,10.2188)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2647.7,1129.66,10.2188)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2845.73,1295.05,10.7891)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1398.84,2222.61,10.4219)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -1455.12,2591.66,55.2344)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -76.0312,1227.99,19.125)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 662.43,-552.164,15.7109)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -253.742,2599.76,62.2422)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2271.73,-76.4609,25.9609)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1789.21,-1369.27,15.1641)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1729.79,-1943.05,12.9453)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2060.12,-1897.64,12.9297)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1928.73,-1772.45,12.9453)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2325.98,-1645.13,14.2109)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2352.18,-1357.16,23.7734)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1154.73,-1460.89,15.1562)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -1350.12,492.289,10.5859)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2118.97,-423.648,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2118.62,-422.414,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2097.27,-398.336,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2092.09,-490.055,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2063.27,-490.055,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2005.65,-490.055,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2034.46,-490.055,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2068.56,-398.336,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2039.85,-398.336,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -2011.14,-398.336,34.7266)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -1980.79,142.664,27.0703)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2319.99,2532.85,10.2188)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1520.15,1055.27,10.00)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2503.14,1243.7,10.2188)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 2085.77,2071.36,10.4531)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -862.828,1536.61,21.9844)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -14.7031,1175.36,18.9531)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, -253.742,2597.95,62.2422)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 201.016,-107.617,0.898438)) return 1;
	else if(IsPlayerInRangeOfPoint(playerid, 4, 1277.84,372.516,18.9531)) return 1;
	else return 0;
}

forward OnPlayerCheatDetected(playerid, cheattype);
forward detutils_cheatcheck();
public detutils_cheatcheck()
{
	for(new i = 0; i < MAX_PLAYERS; i++)
	{
		if(IsPlayerConnected(i) && i != INVALID_PLAYER_ID)
		{
			CheckPlayerMoney(i);
			printf("[DETUtils]: (debug) - ac :: Money check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerSkin(i);
			printf("[DETUtils]: (debug) - ac :: Skin check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerPos(i);
			printf("[DETUtils]: (debug) - ac :: Pos check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerPing(i);
			printf("[DETUtils]: (debug) - ac :: Ping check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerArmour(i);
			printf("[DETUtils]: (debug) - ac :: Armour check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerHealth(i);
			printf("[DETUtils]: (debug) - ac :: Health check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerSpeed(i);
			printf("[DETUtils]: (debug) - ac :: Speed check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerDialog(i);
			printf("[DETUtils]: (debug) - ac :: Dialog check performed on %s", ReturnPlayerName(i));
			//sleep(100);
			CheckPlayerMenu(i);
			printf("[DETUtils]: (debug) - ac :: Menu check performed on %s", ReturnPlayerName(i));
		}
	}
	return 1;
}

stock SendPlayerCheatCheck(i, checktype)
{
	switch(checktype)
	{
		case CHEAT_TYPE_MONEY: CheckPlayerMoney(i);
		case CHEAT_TYPE_SKINCHANGER: CheckPlayerSkin(i);
		case CHEAT_TYPE_TELEPORT: CheckPlayerPos(i);
		case CHEAT_TYPE_HIGHPING: CheckPlayerPing(i);
		case CHEAT_TYPE_ARMOUR: CheckPlayerArmour(i);
		case CHEAT_TYPE_HEALTH: CheckPlayerHealth(i);
		case CHEAT_TYPE_SPEEDHACK: CheckPlayerSpeed(i);
		case CHEAT_TYPE_DIALOG: CheckPlayerDialog(i);
		case CHEAT_TYPE_MENU: CheckPlayerMenu(i);
	}
	return 1;
}

new gAntiCheatToggled = 1;

stock ToggleAntiCheatSystem(bool:toggle)
{
	if(toggle == true)
	{
		gAntiCheatToggled = 1;
		return 1;
	}
	if(toggle == false)
	{
		gAntiCheatToggled = 0;
		return 1;
	}
	return INVALID_CHEAT_TYPE;
}

// Anti-cheat code:

enum ENUM_g_PlayerData
{
	bool:Protection,
	Money,
	Skin,
	Float:Pos[3],
	Float:NewPos[3], //for tp hack detection
	bool:UsingTPHack,
	Ping,
	Float:Health,
	Float:Armour,
	Dialog,
	bool:UsingDialogHack,
	Menu:Menu,
	bool:UsingMenuHack
}

new g_PlayerData[MAX_PLAYERS][ENUM_g_PlayerData];

public OnPlayerSpawn(playerid)
{
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, Float:x, Float:y, Float:z);

	new Float:h;
	GetPlayerHealth(playerid, Float:h);

	new Float:a;
	GetPlayerArmour(playerid, Float:a);

	g_PlayerData[playerid][Health] = h;
	g_PlayerData[playerid][Armour] = a;
	
	g_PlayerData[playerid][Pos][0] = x;
	g_PlayerData[playerid][Pos][1] = y;
	g_PlayerData[playerid][Pos][2] = z;

	if(funcidx("d_ac_onplayerspawn") != -1)
	{
		CallLocalFunction("d_ac_onplayerspawn", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerSpawn
	
	#undef OnPlayerSpawn

#else
	
	#define _ALS_OnPlayerSpawn

#endif

#define OnPlayerSpawn d_ac_onplayerspawn

forward d_ac_onplayerspawn(playerid);

#if defined detutils_debug

#if !defined DIALOG_ID_ACSTATS

#define DIALOG_ID_ACSTATS 0

#endif

forward cmd_acstats(playerid, params[]);
public cmd_acstats(playerid, params[])
{
	new p_DialogText[1024];
	format(p_DialogText,
		sizeof p_DialogText,

		"Amount of money: %i\n \
		Your skin ID: %i\n \
		Your position: %f, %f, %f\n \
		Ping: %i\n \
		Health: %f\n \
		Armour: %f\n \
		",

		g_PlayerData[playerid][Money],
		g_PlayerData[playerid][Skin],
		g_PlayerData[playerid][Pos][0],g_PlayerData[playerid][Pos][1],g_PlayerData[playerid][Pos][2],
		g_PlayerData[playerid][Ping],
		g_PlayerData[playerid][Health],
		g_PlayerData[playerid][Armour]);

	ShowPlayerDialog(playerid, 
		DIALOG_ID_ACSTATS, 
		DIALOG_STYLE_MSGBOX, 
		"SA:MP Anti-Cheat - Notice", 
		p_DialogText, 
		"Close", "");
	return 1;
}

#endif

public OnPlayerSpawn(playerid)
{
	new Float:hp, Float:ap;
	GetPlayerHealth(playerid, hp);
	GetPlayerArmour(playerid, ap);

	g_PlayerData[playerid][Money] = GetPlayerMoney(playerid);
	g_PlayerData[playerid][Skin] = GetPlayerSkin(playerid);
	g_PlayerData[playerid][UsingTPHack] = false;
	g_PlayerData[playerid][Health] = hp;
	g_PlayerData[playerid][Armour] = ap;

	if(funcidx("a_ac_OnplayerSpawn") != -1)
	{
		CallLocalFunction("a_ac_OnplayerSpawn", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn a_ac_OnplayerSpawn

forward a_ac_OnplayerSpawn(playerid);

public OnPlayerDisconnect(playerid, reason)
{
	g_PlayerData[playerid][Money] = 0;
	g_PlayerData[playerid][Skin] = 0;
	g_PlayerData[playerid][UsingTPHack] = false;
	g_PlayerData[playerid][Health] = 0;
	g_PlayerData[playerid][Armour] = 0;

	if(funcidx("a_anticheat_Onpds") != -1)
	{
		CallLocalFunction("a_anticheat_Onpds", "ii", playerid, reason);
	}
	return 1;
}

#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect a_anticheat_Onpds

forward a_anticheat_Onpds(playerid, reason);

// DIALOG ANTI-CHEAT:

stock d_ac_ShowPlayerDialog(playerid, dialogid, style, const caption[], const info[], const button1[], const button2[])
{
	ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);
	g_PlayerData[playerid][Dialog] = dialogid;
	return 1;
}

stock CheckPlayerDialog(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerDialog);
	
	if(g_PlayerData[playerid][UsingDialogHack] == true)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_DIALOG);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif

#define ShowPlayerDialog d_ac_ShowPlayerDialog

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid != g_PlayerData[playerid][Dialog])
	{
		g_PlayerData[playerid][UsingDialogHack] = true;
	}

	if(funcidx("d_ac_dialogresponse") != -1)
	{
		//CallLocalFunction("d_ac_dialogresponse", "iiiis", playerid, dialogid, response, listitem, inputtext);
		#if defined d_ac_dialogresponse
		d_ac_dialogresponse(playerid, dialogid, response, listitem, inputtext);
		#endif
	}
	return 1;
}

#if defined _ALS_OnDialogResponse
	#undef OnDialogResponse
#else
	#define _ALS_OnDialogResponse
#endif

#define OnDialogResponse d_ac_dialogresponse

forward d_ac_dialogresponse(playerid, dialogid, response, listitem, inputtext[]);

// MENU SELECTION ANTI-CHEAT:

stock Menu:d_ac_ShowMenuForPlayer(Menu:menuid, playerid)
{
	g_PlayerData[playerid][Menu] = menuid;
	return Menu:ShowMenuForPlayer(Menu:menuid, playerid);
}

stock CheckPlayerMenu(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerMenu);
	
	if(g_PlayerData[playerid][UsingMenuHack] == true)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_MENU);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_ShowMenuForPlayer
	#undef ShowMenuForPlayer
#else
	#define _ALS_ShowMenuForPlayer
#endif

#define ShowMenuForPlayer d_ac_ShowMenuForPlayer

public OnPlayerSelectedMenuRow(playerid, row)
{
	new Menu:menuid = GetPlayerMenu(playerid);
	if(menuid != g_PlayerData[playerid][Menu])
	{
		g_PlayerData[playerid][UsingMenuHack] = true;
	}

	if(funcidx("d_ac_menuresponse") != -1)
	{
		CallLocalFunction("d_ac_menuresponse", "ii", playerid, row);
	}
	return 1;
}

#if defined _ALS_OnPlayerSelectedMenuRow
	#undef OnPlayerSelectedMenuRow
#else
	#define _ALS_OnPlayerSelectedMenuRow
#endif

#define OnPlayerSelectedMenuRow d_ac_menuresponse

forward d_ac_menuresponse(playerid, row);

// MONEY ANTI-CHEAT:

stock d_ac_GivePlayerMoney(playerid, money)
{
	GivePlayerMoney(playerid, money);
	g_PlayerData[playerid][Money] += money;
	return 1;
}

stock CheckPlayerMoney(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerMoney);

	new currentmoney = GetPlayerMoney(playerid);
	if(currentmoney != g_PlayerData[playerid][Money])
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_MONEY);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif

#define GivePlayerMoney d_ac_GivePlayerMoney

// SKIN ANTI-CHEAT:

stock d_ac_SetPlayerSkin(playerid, skin)
{
	SetPlayerSkin(playerid, skin);
	g_PlayerData[playerid][Skin] = skin;
	return 1;
}

stock CheckPlayerSkin(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerSkin);

	new currentskin = GetPlayerSkin(playerid);
	if(currentskin != g_PlayerData[playerid][Skin])
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_SKINCHANGER);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_SetPlayerSkin
	#undef SetPlayerSkin
#else
	#define _ALS_SetPlayerSkin
#endif

#define SetPlayerSkin d_ac_SetPlayerSkin

// TELEPORT ANTI-CHEAT:

#define MAX_PLAYER_SPEED 219

#define MAX_PLAYERPED_SPEED 220

stock Float:d_ac_GetDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2)
{
	return VectorSize(x1-x2, y1-y2, z1-z2);
}

stock d_ac_GetSpeed(playerid) // Also used in Speed Anti Cheat
{
	new Float:d_ac_GetSpeedVar[4];
	if(IsPlayerInAnyVehicle(playerid)) 
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), d_ac_GetSpeedVar[0], d_ac_GetSpeedVar[1], d_ac_GetSpeedVar[2]);
	}
	else GetPlayerVelocity(playerid, d_ac_GetSpeedVar[0], d_ac_GetSpeedVar[1], d_ac_GetSpeedVar[2]);
	d_ac_GetSpeedVar[3] = floatsqroot(floatpower(floatabs(d_ac_GetSpeedVar[0]), 2.0) + floatpower(floatabs(d_ac_GetSpeedVar[1]), 2.0) + floatpower(floatabs(d_ac_GetSpeedVar[2]), 2.0)) * 178.8617875;
	return floatround(d_ac_GetSpeedVar[3]);
}

stock d_ac_GetSpeedMs(playerid) // Also used in Speed Anti Cheat
{
	new Float:d_ac_GetSpeedVar[4], d_ac_KmhSpeed, d_ac_MsSpeed;
	if(IsPlayerInAnyVehicle(playerid)) 
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), d_ac_GetSpeedVar[0], d_ac_GetSpeedVar[1], d_ac_GetSpeedVar[2]);
	}
	else GetPlayerVelocity(playerid, d_ac_GetSpeedVar[0], d_ac_GetSpeedVar[1], d_ac_GetSpeedVar[2]);
	d_ac_GetSpeedVar[3] = floatsqroot(floatpower(floatabs(d_ac_GetSpeedVar[0]), 2.0) + floatpower(floatabs(d_ac_GetSpeedVar[1]), 2.0) + floatpower(floatabs(d_ac_GetSpeedVar[2]), 2.0)) * 178.8617875;
	d_ac_KmhSpeed = floatround(d_ac_GetSpeedVar[3]);
	d_ac_MsSpeed = d_ac_KmhSpeed / 3.6;
	return d_ac_MsSpeed;

}

stock d_ac_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	SetPlayerPos(playerid, x, y, z);
	g_PlayerData[playerid][Pos][0] = x;
	g_PlayerData[playerid][Pos][1] = y;
	g_PlayerData[playerid][Pos][2] = z;
	return 1;
}

#if defined DETUTILS_OPENMP_COMPAT

#define Player_SetVehiclePos SetPlayerVehiclePos

#endif

stock SetPlayerVehiclePos(playerid, Float:x, Float:y, Float:z)
{
	g_PlayerData[playerid][Pos][0] = x;
	g_PlayerData[playerid][Pos][1] = y;
	g_PlayerData[playerid][Pos][2] = z;
	return d_v_SetPlayerVehiclePos(playerid, x, y, z); // Hooks d_visual.inc function
}

stock CheckPlayerPos(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerPos);

	new Float:x, Float:y, Float:z;

	GetPlayerPos(playerid, x, y, z);

	g_PlayerData[playerid][NewPos][0] = x;
	g_PlayerData[playerid][NewPos][1] = y;
	g_PlayerData[playerid][NewPos][2] = z;

	//new speed = d_ac_GetSpeedMs(playerid); // Because I am checking CheckPlayerPos every second.

	if(!IsPlayerInAnyVehicle(playerid))
	{
		if(ArePlayerPedAnimsUsed())
		{
			new Float:p_MaxPlayerPedSpeed = MAX_PLAYERPED_SPEED / 3.6;

			new Float:distance = d_ac_GetDistance(g_PlayerData[playerid][Pos][0], 
							g_PlayerData[playerid][Pos][1], 
							g_PlayerData[playerid][Pos][2],
							g_PlayerData[playerid][NewPos][0],
							g_PlayerData[playerid][NewPos][1],
							g_PlayerData[playerid][NewPos][2]);

			if(distance > p_MaxPlayerPedSpeed)
			{
				g_PlayerData[playerid][UsingTPHack] = true;
			}
		}
		else if(!ArePlayerPedAnimsUsed())
		{
			new Float:p_MaxPlayerSpeed = MAX_PLAYER_SPEED / 3.6;
			
			new Float:distance = d_ac_GetDistance(g_PlayerData[playerid][Pos][0], 
							g_PlayerData[playerid][Pos][1], 
							g_PlayerData[playerid][Pos][2],
							g_PlayerData[playerid][NewPos][0],
							g_PlayerData[playerid][NewPos][1],
							g_PlayerData[playerid][NewPos][2]);

			if(distance > p_MaxPlayerSpeed)
			{
				g_PlayerData[playerid][UsingTPHack] = true;
			}
		}
		if(IsPlayerInAnyVehicle(playerid))
		{
			g_PlayerData[playerid][UsingTPHack] = false;
		}
	}

	g_PlayerData[playerid][Pos][0] = x;
	g_PlayerData[playerid][Pos][1] = y;
	g_PlayerData[playerid][Pos][2] = z;

	if(g_PlayerData[playerid][UsingTPHack] == true)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_TELEPORT);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif

#define SetPlayerPos d_ac_SetPlayerPos

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif

#define SetVehiclePos d_ac_SetVehiclePos

// HIGH PING ANTI-CHEAT:

stock CheckPlayerPing(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerPing);
	new ping = GetPlayerPing(playerid);
	g_PlayerData[playerid][Ping] = ping;
	if(g_PlayerData[playerid][Ping] > 250)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_HIGHPING);
			return 1;
		}
	}
	return 0;
}

// HEALTH ANTI-CHEAT:

stock d_ac_SetPlayerHealth(playerid, Float:health)
{
	SetPlayerHealth(playerid, health);
	g_PlayerData[playerid][Health] = health;
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	new Float:armour;
	if(GetPlayerArmour(playerid, armour) != 0) 
		g_PlayerData[playerid][Health] = g_PlayerData[playerid][Health] - amount;

	else g_PlayerData[playerid][Armour] = g_PlayerData[playerid][Armour] - amount;

	if(funcidx("d_ac_ptakedmg") != -1)
	{
		CallLocalFunction("d_ac_ptakedmg", "iifii", playerid, issuerid, amount, weaponid, bodypart);
	}
	return 1;
}

#if defined _ALS_OnPlayerTakeDamage
	#undef OnPlayerTakeDamage
#else
	#define _ALS_OnPlayerTakeDamage
#endif

#define OnPlayerTakeDamage d_ac_ptakedmg

forward d_ac_ptakedmg(playerid, issuerid, Float:amount, weaponid, bodypart);

stock CheckPlayerHealth(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerHealth);

	new Float:p_Health, bool:UsingStaticHack = false;
	GetPlayerHealth(playerid,p_Health);
	if(p_Health < g_PlayerData[playerid][Health])
	{
		g_PlayerData[playerid][Health] = g_PlayerData[playerid][Health] + 2;
	}
	if(d_ac_IsPlayerNearSprunk(playerid))
	{
		g_PlayerData[playerid][Health] = g_PlayerData[playerid][Health] + 2;
	}
	if(p_Health > g_PlayerData[playerid][Health] && !d_ac_IsPlayerNearSprunk(playerid))
	{
		UsingStaticHack = true;
	}

	if(UsingStaticHack == true)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_HEALTH);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif

#define SetPlayerHealth d_ac_SetPlayerHealth

// ARMOUR ANTI-CHEAT:

stock d_ac_SetPlayerArmour(playerid, Float:armour)
{
	SetPlayerArmour(playerid, armour);
	g_PlayerData[playerid][Armour] = armour;
	return 1;
}

stock CheckPlayerArmour(playerid)
{
	DETUTILS_AC__ check:(CheckPlayerArmour);
	
	new Float:p_Armour, bool:UsingStaticHack = false;
	GetPlayerHealth(playerid,p_Armour);
	if(p_Armour < g_PlayerData[playerid][Armour])
	{
		g_PlayerData[playerid][Armour] = g_PlayerData[playerid][Armour] + 2;
	}
	if(p_Armour > g_PlayerData[playerid][Armour])
	{
		UsingStaticHack = true;
	}

	if(UsingStaticHack == true)
	{
		if(funcidx("OnPlayerCheatDetected") != -1)
		{
			CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_ARMOUR);
			return 1;
		}
	}
	return 0;
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif

#define SetPlayerArmour d_ac_SetPlayerArmour

// SPEED HACK ANTI-CHEAT:

static bool:d_ac_aerovehicle(vehid)
{
	switch(GetVehicleModel(vehid))
	{
		case 417, 425, 447, 460, 469, 476, 487, 488, 497, 511, 512, 513, 519,
		520, 548, 553, 563, 577, 592, 593: return true;
	}
	return (false);
}

stock CheckPlayerSpeed(playerid)
{
	if(d_ac_GetSpeed(playerid) > 291)
	{
		if(!d_ac_aerovehicle(GetPlayerVehicleID(playerid)))
		{
			if(funcidx("OnPlayerCheatDetected") != -1)
			{
				CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_SPEEDHACK);
				return 1;
			}
		}
	}
	return 0;
}

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
	DET_g_AntiCheatTimer = SetTimer("detutils_cheatcheck", 60000, true);
	#if defined detutils_debug
	SaveLogIntoFile("detutils_anticheat.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_anticheat.log", "[DETUtils]: (debug) - Loaded.");
	#endif
	LoadDETUtilsScript(DETUTILS_SCRIPT_ANTICHEAT);
	if(funcidx("d_ac_detutilsinit") != -1)
	{
		CallLocalFunction("d_ac_detutilsinit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsInit
	#undef OnDETUtilsInit
#else
	#define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_ac_detutilsinit(

forward d_ac_detutilsinit();

public OnDETUtilsExit()
{
	KillTimer(DET_g_AntiCheatTimer);
	if(funcidx("d_ac_detutilsexit") != -1)
	{
		CallLocalFunction("d_ac_detutilsexit", "");
	}
	return 1;
}

#if defined _ALS_OnDETUtilsExit
	#undef OnDETUtilsExit
#else
	#define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit d_ac_detutilsexit

forward d_ac_detutilsexit();