/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Faction permissions submodule.
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

new DET_g_FactionPermissions[MAX_FACTIONS];

stock SetFactionPermissionInteger(const name[], permissions)
{
	if(!strcmp("NO_FACTION", name, false))
	{
		printf("[DETUtils]: (denied) - Permission to modify the 'NO_FACTION' faction permissions is denied.");
		return 0;
	}
	for(new i = 1;
		i < MAX_FACTIONS;
		i++)
	{
		if(!strcmp(DET_g_FactionCache[i][FactionName], name, false))
		{
			DET_g_FactionPermissions[i] = permissions;
		}
	}
	return 1;
}

public OnPlayerUpdate(playerid)
{
	new factionname[32];
	GetPlayerFaction(playerid, factionname);
	if(strcmp(factionname, "NO_FACTION", false))
	{
		for(new i = 1;
			i < MAX_FACTIONS;
			i++)
		{
			if(!strcmp(DET_g_FactionCache[i][FactionName], factionname, false))
			{
				SetPlayerPermissionInteger(playerid, DET_g_FactionPermissions[i]);
			}
		}
	}
	if(funcidx("d_factperm_playerupdate") != -1)
	{
		CallLocalFunction("d_factperm_playerupdate", "i", playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate( d_factperm_playerupdate(

forward d_factperm_playerupdate(playerid);