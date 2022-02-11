/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides
 *   creation of teams, adding
 *   and removing players from them.
 *
 * - Also extends the features of
 *   other includes such as
 *   d_commands or d_properties.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

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

#if !defined DETUTILS_NO_COMMANDS

#define @DETUTILS_CMD_DEC__@TEAM_COMMAND%6,%5.%4team%3=%2)%0(%1,%7[%8]%9) \
    @DETUTILSCMD_TEAMS_DECL__|%0..%1,%7| @DETUTILSCMD_TEAMS_CHECK__:{%1..|%2|..%0,%7} @DETUTILSCMD_TEAMS_CALL___:|||%0|%1..%7|

#endif

#define MAX_TEAMS 256

enum enum_TeamData
{
	ValidTeam,
	TeamName[32],
	TeamMembers
}

new g_TeamCache[MAX_TEAMS][enum_TeamData];

enum enum_PlayerTeamData
{
	Team[32]
}

new g_PlayerTeamCache[MAX_PLAYERS][enum_PlayerTeamData];

forward OnTeamCreate(teamid, teamname[]);
forward OnTeamDelete(teamid, teamname[]);

stock CreateTeam(const name[])
{
	if(!strcmp("NO_TEAM", name, false))
	{
		printf("[samp-detutils]: (denied) - Permission to create the team 'NO_TEAM' denied.");
		return 0;
	}
	for(new i = 1;
		i < MAX_TEAMS;
		i++)
	{
		if(g_TeamCache[i][ValidTeam] == 0)
		{
			if(funcidx("OnTeamCreate") != -1)
			{
				CallLocalFunction("OnTeamCreate", "is", i, name);
			}
			strmid(g_TeamCache[i][TeamName], name, 0, 32);
			g_TeamCache[i][ValidTeam] = 1;
			#if defined detutils_debug
			printf("[samp-detutils]: (team create) - Created a team '%s'.", name);
			#endif
			return 1;
		}
	}
	return 0;
}

stock DeleteTeam(const name[])
{
	if(!strcmp("NO_TEAM", name, false))
	{
		printf("[samp-detutils]: (denied) - Permission to delete the team 'NO_TEAM' denied.");
		return 0;
	}
	for(new i = 1;
		i < MAX_TEAMS;
		i++)
	{
		if(!strcmp(g_TeamCache[i][TeamName], name, false))
		{
			if(g_TeamCache[i][TeamMembers] != 0)
			{
				printf("[samp-detutils]: (team error) - Unable to delete a team '%s'; \
					firstly remove all the players from that team.", name);
				return 0;
			}
			if(funcidx("OnTeamDelete") != -1)
			{
				CallLocalFunction("OnTeamDelete", "is", i, name);
			}
			#if defined detutils_debug
			printf("[samp-detutils]: (team delete) - Deleted a team '%s'.", name);
			#endif
			strmid(g_TeamCache[i][TeamName], "_INVALID_TEAM_NAME_", 0, 32);
			g_TeamCache[i][ValidTeam] = 0;
			return 1;
		}
	}
	return 0;
}

stock AddPlayerToTeam(playerid, const name[])
{
	if(!strcmp(name, "NO_TEAM", false)) // If the team is 'NO_TEAM', set player's team to nothing.
	{
		#if defined detutils_debug
			printf("[samp-detutils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
		#endif
		strmid(g_PlayerTeamCache[playerid][Team], name, 0, 32);
		return 1;
	}
	else
	{
		for(new i = 1;
			i < MAX_TEAMS;
			i++)
		{
			if(!strcmp(g_TeamCache[i][TeamName], name, false))
			{
				#if defined detutils_debug
				printf("[samp-detutils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
				#endif
				strmid(g_PlayerTeamCache[playerid][Team], name, 0, 32);
				return 1;
			}
		}/*
		if(tmc == 1) // If there is an one team with that name, 
		{
			// Set the team
			#if defined detutils_debug
			printf("[samp-detutils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
			#endif
			strmid(g_PlayerTeamCache[playerid][Team], name, 0, 32);
		}
		if(tmc > 1) // if more than 1 team
		{
			// error
			printf("[samp-detutils]: (team error) - Team '%s' shadows a team at a preceding level.", name);
			return 0;
		}
		if(tmc == 0) // if no teams
		{
			// Error
			printf("[samp-detutils]: (team IID) - No such team ('%s') found.", name);
			return 0;
		}
		return 1;*/
	}
	return 0;
}

// If d_visual is is included, then this will be hooked instead of a hook in d_visual.inc!
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
	// The reason i didn't just simply name these 'Health' or 'Armour'
	// is because the same ones are located in `d_anticheat` 
	// globally in the enumerator.
	new Float:locHealth, Float:locArmour;
	GetPlayerHealth(playerid, locHealth);
	GetPlayerArmour(playerid, locArmour);
	if(strcmp(g_PlayerTeamCache[playerid][Team], 
		g_PlayerTeamCache[damagedid][Team],
		false))
	{
		if(bodypart == 9 && weaponid == 34)
	    {
	        SetPlayerHealth(damagedid, 0);
	        SetPlayerArmour(damagedid, 0);
	        if(funcidx("OnPlayerScoreSniperHeadshot") != -1)
	            CallLocalFunction("OnPlayerScoreSniperHeadshot", "ii", playerid, damagedid);
	    }
	}
	else
	{
		if(locArmour != 0)
		{
			SetPlayerArmour(damagedid, locArmour + amount);
		}
		else if(locArmour == 0)
		{
			SetPlayerHealth(damagedid, locHealth + amount);
		}
	}
    if(funcidx("d_visual_Onpgd") != -1)
    {
        CallLocalFunction("d_visual_Onpgd", "iifii", playerid, damagedid, amount, weaponid, bodypart);
    }
    return 1;
}

#if defined _ALS_OnPlayerGiveDamage
    #undef OnPlayerGiveDamage
#else
    #define _ALS_OnPlayerGiveDamage
#endif

#define OnPlayerGiveDamage d_visual_Onpgd

forward d_visual_Onpgd(playerid, damagedid, Float:amount, weaponid, bodypart);

// When player disconnects.
public OnPlayerDisconnect(playerid, reason)
{
	// Set the internal team when player disconnects...
	strmid(g_PlayerTeamCache[playerid][Team], "NO_TEAM", 0, 32);

    if(funcidx("d_t_disconnect") != -1)
    {
        CallLocalFunction("d_t_disconnect", "ii", playerid, reason);
    }
    return 1;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect d_t_disconnect

forward d_t_disconnect(playerid, reason);

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
	// For all the players:
	for(new i; i < MAX_PLAYERS; i++)
	{
		// Set the internal team...
		strmid(g_PlayerTeamCache[i][Team], "NO_TEAM", 0, 32);
	}

    #if defined detutils_debug
    SaveLogIntoFile("detutils_teams.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_teams.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_TEAMS);
    if(funcidx("d_t_detutilsinit") != -1)
    {
        CallLocalFunction("d_t_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit d_t_detutilsinit

forward d_t_detutilsinit();