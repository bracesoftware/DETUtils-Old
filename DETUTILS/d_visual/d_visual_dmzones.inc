/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides
 *   creation of DM zones.
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

#define MAX_DM_ZONES 1000

enum enum_PlayerDMData
{
	InDM,
	DMKills
}

new g_PlayerDMCache[MAX_PLAYERS][enum_PlayerDMData];

enum enum_DMZoneData
{
	ValidZone,
	ZoneName[32],
	Float:RandomSpawn1[3],
	Float:RandomSpawn2[3],
	Float:RandomSpawn3[3]
}

new g_DMZoneCache[MAX_DM_ZONES][enum_DMZoneData];

forward OnDeathMatchZoneCreate(zoneid, zonename[]);
forward OnDeathMatchZoneDestroy(zoneid, zonename[]);

stock CreateDeathMatchZone(const name[], Float:x, Float:y, Float:z, Float:x2, Float:y2, Float:z2, Float:x3, Float:y3, Float:z3)
{
	for(new i = 1;
		i < MAX_DM_ZONES;
		i++)
	{
		if(g_DMZoneCache[i][ValidZone] == 0)
		{
			// Save the name:
			strmid(g_DMZoneCache[i][ZoneName], name, 0, 32);

			//Save positions:
			g_DMZoneCache[i][RandomSpawn1][0] = x;
			g_DMZoneCache[i][RandomSpawn1][1] = y;
			g_DMZoneCache[i][RandomSpawn1][2] = z;
			
			g_DMZoneCache[i][RandomSpawn2][0] = x2;
			g_DMZoneCache[i][RandomSpawn2][1] = y2;
			g_DMZoneCache[i][RandomSpawn2][2] = z2;

			g_DMZoneCache[i][RandomSpawn3][0] = x3;
			g_DMZoneCache[i][RandomSpawn3][1] = y3;
			g_DMZoneCache[i][RandomSpawn3][2] = z3;

			// Validate the id `i`
			g_DMZoneCache[i][ValidZone] = 1;

			CallLocalFunction("OnDeathMatchZoneCreate", "is", i, name);
			break;	
		}
	}
	return 1;
}

stock DestroyDeathMatchZone(const name[])
{
	for(new i = 1;
		i < MAX_DM_ZONES;
		i ++)
	{// check
		if(!strcmp(g_DMZoneCache[i][ZoneName], name, false))
		{
			CallLocalFunction("OnDeathMatchZoneDestroy", "is", i, name);
			// Erase the name:
			strmid(g_DMZoneCache[i][ZoneName], "_INVALID_DMZ_NAME_", 0, 32);

			//Save positions:
			g_DMZoneCache[i][RandomSpawn1][0] = 0;
			g_DMZoneCache[i][RandomSpawn1][1] = 0;
			g_DMZoneCache[i][RandomSpawn1][2] = 0;
			
			g_DMZoneCache[i][RandomSpawn2][0] = 0;
			g_DMZoneCache[i][RandomSpawn2][1] = 0;
			g_DMZoneCache[i][RandomSpawn2][2] = 0;

			g_DMZoneCache[i][RandomSpawn3][0] = 0;
			g_DMZoneCache[i][RandomSpawn3][1] = 0;
			g_DMZoneCache[i][RandomSpawn3][2] = 0;

			// Unvalidate the id `i`
			g_DMZoneCache[i][ValidZone] = 0;
		}
	}
	return 0;
}

stock IsValidDeathMatchZone(id)
{
	return g_DMZoneCache[id][ValidZone];
}

stock GetDeathMatchZoneIDByName(const name[])
{
	for(new i = 1;
		i < MAX_DM_ZONES;
		i++)
	{
		if(!strcmp(g_DMZoneCache[i][ZoneName], name, false))
		{
			return i;
		}
	}
	return 0;
}

stock GetDeathMatchZoneName(id)
{
    new name[256];

    strcat(name, g_DMZoneCache[id][ZoneName]);

    return name;
}

stock AddPlayerToDeathMatchZone(playerid, const name[], spawnid, kitlevel)
{
	for(new i = 1;
		i < MAX_DM_ZONES;
		i++)
	{
		if(!strcmp(g_DMZoneCache[i][ZoneName], name, false))
		{
			ResetPlayerWeapons(playerid);
			if(spawnid == 1)
			{
				SetPlayerPos(playerid,
					g_DMZoneCache[i][RandomSpawn1][0],
					g_DMZoneCache[i][RandomSpawn1][1],
					g_DMZoneCache[i][RandomSpawn1][2]);
				g_PlayerDMCache[playerid][InDM] = 1;
				if(kitlevel == 10) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 28, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
				}
				else if(kitlevel == 9) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 32, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 8) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 28, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 7)
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_M4, 999 );
				}
				else if(kitlevel == 6) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 5) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 4) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 3) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 2) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
				}
				else if(kitlevel == 1) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
				}
				else
				{
					printf("[DETUtils]: (dm error) - Invalid kit level; kit level can be 1 .. 10.");
					return 0;
				}
			}
			else if(spawnid == 2)
			{
				SetPlayerPos(playerid,
					g_DMZoneCache[i][RandomSpawn2][0],
					g_DMZoneCache[i][RandomSpawn2][1],
					g_DMZoneCache[i][RandomSpawn2][2]);
				g_PlayerDMCache[playerid][InDM] = 1;
				if(kitlevel == 10) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 28, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
				}
				else if(kitlevel == 9) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 32, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 8) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 28, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 7)
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_M4, 999 );
				}
				else if(kitlevel == 6) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 5) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 4) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 3) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 2) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
				}
				else if(kitlevel == 1) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
				}
				else
				{
					printf("[DETUtils]: (dm error) - Invalid kit level; kit level can be 1 .. 10.");
					return 0;
				}
			}
			else if(spawnid == 3)
			{
				SetPlayerPos(playerid,
					g_DMZoneCache[i][RandomSpawn3][0],
					g_DMZoneCache[i][RandomSpawn3][1],
					g_DMZoneCache[i][RandomSpawn3][2]);
				g_PlayerDMCache[playerid][InDM] = 1;
				if(kitlevel == 10) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 28, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 999 );
				}
				else if(kitlevel == 9) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 32, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 8) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 28, 800 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_MICRO_UZI, 999 );
				}
				else if(kitlevel == 7)
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 27, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
					SetPlayerSkillLevel( playerid, WEAPONSKILL_M4, 999 );
				}
				else if(kitlevel == 6) 
				{
				    GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 5) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 26, 150 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 4) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 31, 400 );
				}
				else if(kitlevel == 3) 
				{
					GivePlayerWeapon( playerid, 24, 150 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
					GivePlayerWeapon( playerid, 30, 400 );
				}
				else if(kitlevel == 2) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
					GivePlayerWeapon( playerid, 29, 400 );
				}
				else if(kitlevel == 1) 
				{
					GivePlayerWeapon( playerid, 24, 200 );
					GivePlayerWeapon( playerid, 25, 100 );
				}
				else
				{
					printf("[DETUtils]: (dm error) - Invalid kit level; kit level can be 1 .. 10.");
					return 0;
				}
			}

			else if(spawnid != 1 && spawnid != 2 && spawnid != 3)
			{
				printf("[DETUtils]: (dm error) - Invalid `spawnid` parameter; `spawnid` can be 1, 2 or 3.");
				return 0;
			}
			break;
		}
	}
	return 1;
}

stock RemovePlayerFromDeathMatchZone(playerid)
{
	g_PlayerDMCache[playerid][InDM] = 0;
	g_PlayerDMCache[playerid][DMKills] = 0;
	SetPlayerHealth(playerid, 0.0000);
	return 1;
}

stock GetPlayerDeathMatchZoneKills(playerid)
{
	if(g_PlayerDMCache[playerid][InDM] == 0) return -1;
	return g_PlayerDMCache[playerid][DMKills];
}

stock IsPlayerInDeathMatchZone(playerid)
{
	return g_PlayerDMCache[playerid][InDM];
}

public OnPlayerDeath(playerid, killerid, reason)
{
	if(killerid != INVALID_PLAYER_ID)
	{	
		if(g_PlayerDMCache[killerid][InDM] == 1)
		{
			g_PlayerDMCache[killerid][DMKills]++;
		}
	}
	if(g_PlayerDMCache[killerid][InDM] == 1)
	{
		g_PlayerDMCache[killerid][InDM] = 0;
	}
	if(funcidx("d_dm_playerdeath") != -1)
    {
        CallLocalFunction("d_dm_playerdeath", "iii", playerid, killerid, reason);
    }
    return 1;
}

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath d_dm_playerdeath

forward d_dm_playerdeath(playerid, killerid, reason);