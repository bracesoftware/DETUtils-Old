/*
 * 
 * DETUtils
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

#define @DETUTILS_CMD_DEC__@TEAM_COMMAND%6,%5.team%3=%2)%0(%1,%7[%8]%9) DETUTILSCMD_TYPESET__$|<%0>,SLASH_COMMAND_TYPE_TEAM| \
	@DETUTILSCMD_TEAMS_DECL__|%0..%1,%7| @DETUTILSCMD_TEAMS_CHECK__:{%1..|%2|..%0,%7} @DETUTILSCMD_TEAMS_CALL___:|||%0|%1..%7|

#endif

#if defined DETUTILS_NO_PROPERTIES

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

#endif

forward OnTeamCreate(teamid, teamname[]);
forward OnTeamDelete(teamid, teamname[]);

stock CreateTeam(const name[])
{
	if(!strcmp("NO_TEAM", name, false))
	{
		printf("[DETUtils]: (denied) - Permission to create the team 'NO_TEAM' denied.");
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
			printf("[DETUtils]: (team create) - Created a team '%s'.", name);
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
		printf("[DETUtils]: (denied) - Permission to delete the team 'NO_TEAM' denied.");
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
				printf("[DETUtils]: (team error) - Unable to delete a team '%s'; \
					firstly remove all the players from that team.", name);
				return 0;
			}
			if(funcidx("OnTeamDelete") != -1)
			{
				CallLocalFunction("OnTeamDelete", "is", i, name);
			}
			#if defined detutils_debug
			printf("[DETUtils]: (team delete) - Deleted a team '%s'.", name);
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
		for(new i = 1;
			i < MAX_TEAMS;
			i++)
		{
			if(!strcmp(g_TeamCache[i][TeamName], g_PlayerTeamCache[playerid][Team], false))
			{
				g_TeamCache[i][TeamMembers] --;
			}
		}
		#if defined detutils_debug
			printf("[DETUtils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
		#endif
		strmid(g_PlayerTeamCache[playerid][Team], "NO_TEAM", 0, 32);
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
				printf("[DETUtils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
				#endif
				g_TeamCache[i][TeamMembers] ++;
				strmid(g_PlayerTeamCache[playerid][Team], name, 0, 32);
				return 1;
			}
		}/*
		if(tmc == 1) // If there is an one team with that name, 
		{
			// Set the team
			#if defined detutils_debug
			printf("[DETUtils]: (team set) - Player '%i' added to a team '%s'.", playerid, name);
			#endif
			strmid(g_PlayerTeamCache[playerid][Team], name, 0, 32);
		}
		if(tmc > 1) // if more than 1 team
		{
			// error
			printf("[DETUtils]: (team error) - Team '%s' shadows a team at a preceding level.", name);
			return 0;
		}
		if(tmc == 0) // if no teams
		{
			// Error
			printf("[DETUtils]: (team IID) - No such team ('%s') found.", name);
			return 0;
		}
		return 1;*/
	}
	return 0;
}

stock GetTeamMemberCount(const name[])
{
	for(new i = 1;
		i < MAX_TEAMS;
		i++)
	{
		if(!strcmp(g_TeamCache[i][TeamName], name, false))
		{
			return g_TeamCache[i][TeamMembers];
		}
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
	//strmid(g_PlayerTeamCache[playerid][Team], "NO_TEAM", 0, 32);
	AddPlayerToTeam(playerid, "NO_TEAM");

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

#if !defined DETUTILS_NO_PROPERTIES

stock CreatePropertyEntranceForTeam(
		const PropertyName[],
		const teamname[], 
		Float:_xEntrance, 
		Float:_yEntrance, 
		Float:_zEntrance,  
		_xInteriorid,  
		_xVirtualWorldid,
		bool:Labels = false,
		Interior = INTERIOR_CUSTOM,
		Float:_xExit = 0.000, 
		Float:_yExit = 0.000, 
		Float:_zExit = 0.000, 
		_eInteriorid = 0,
		_eVirtualWorldid = 0)
{
	for(new g_PropertyID = 1; 
		g_PropertyID < MAX_PROPERTIES; 
		g_PropertyID++)
		{
			if(g_PropertyData[g_PropertyID][ValidProp] == 0)
			{
				g_PropertyData[g_PropertyID][p_PropertyTeam] = 1;
				strmid(g_PropertyData[g_PropertyID][p_PropTeam], teamname, 0, 32);
				printf("[DETUtils]: (debug) - Property '%s' successfully created, entrance is set to: %f, %f, %f.",
						PropertyName,
						Float:_xEntrance, 
						Float:_yEntrance, 
						Float:_zEntrance);
				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Property created.");
				#endif

				//g_PropertyID++;

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Property id assigned.");
				#endif

				strmid(g_PropertyData[g_PropertyID][p_PropertyName], 
						PropertyName, 
						0, 
						strlen(PropertyName), 
						255);

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Saved property name.");
				#endif

				printf("[DETUtils]: (debug) - Property '%s' has an id %d.",PropertyName,g_PropertyID);

				g_PropertyData[g_PropertyID][p_PropertyEntrance_X] = _xEntrance;
				g_PropertyData[g_PropertyID][p_PropertyEntrance_Y] = _yEntrance;
				g_PropertyData[g_PropertyID][p_PropertyEntrance_Z] = _zEntrance;

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Entrance coordinates assigned to property data.");
				#endif

				g_PropertyData[g_PropertyID][p_PropertyExit_X] = _xExit;
				g_PropertyData[g_PropertyID][p_PropertyExit_Y] = _yExit;
				g_PropertyData[g_PropertyID][p_PropertyExit_Z] = _zExit;

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Exit coordinates assigned to property data.");
				#endif

				g_PropertyData[g_PropertyID][p_PropertyIntid] = _eInteriorid;
				g_PropertyData[g_PropertyID][p_PropertyIntid_OUT] = _xInteriorid;
				g_PropertyData[g_PropertyID][p_PropertyVwid] = _eVirtualWorldid;
				g_PropertyData[g_PropertyID][p_PropertyVwid_OUT] = _xVirtualWorldid;

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Virtual world IDs and interior IDs assigned to property data.");
				#endif

				if(Interior != INTERIOR_CUSTOM)
				{
					#if defined detutils_debug
					printf("[DETUtils]: (debug) - Assigned interior map id to property id : %i", Interior);
					#endif

					if(Interior == INTERIOR_MARKET_247_1)
					{
						g_PropertyData[g_PropertyID][p_PropertyIntid] = 17;
						g_PropertyData[g_PropertyID][p_PropertyVwid] = 17;
						_eInteriorid = 17;
						_eVirtualWorldid = 17;

						g_PropertyData[g_PropertyID][p_PropertyExit_X] = -25.884498;
						g_PropertyData[g_PropertyID][p_PropertyExit_Y] = -185.868988;
						g_PropertyData[g_PropertyID][p_PropertyExit_Z] = 1003.546875;
					}
					if(Interior == INTERIOR_MARKET_247_2)
					{
						DETUTILS_PROP_PARAMS__(6.091179,-29.271898,1003.549438,10);
					}
					if(Interior == INTERIOR_MARKET_247_3)
					{
						DETUTILS_PROP_PARAMS__(-30.946699,-89.609596,1003.546875,18);
					}
					if(Interior == INTERIOR_MARKET_247_4)
					{
						DETUTILS_PROP_PARAMS__(-25.132598,-139.066986,1003.546875,16);
					}
					if(Interior == INTERIOR_MARKET_247_5)
					{
						DETUTILS_PROP_PARAMS__(-27.312299,-29.277599,1003.557250,4);
					}
					if(Interior == INTERIOR_MARKET_247_6)
					{
						DETUTILS_PROP_PARAMS__(-26.691598,-55.714897,1003.546875,6);
					}
				}

				if(Labels == true)
				{
					new _EntranceLabelString[300];
					#if defined detutils_debug
					printf("[DETUtils]: (debug) - Empty string declared.");
					#endif
					format(_EntranceLabelString,sizeof(_EntranceLabelString),"{ffffff}[ %s ]\n{ffffff}Enter here!",PropertyName);
					#if defined detutils_debug
					printf("[DETUtils]: (debug) - Formatted the 3D label string successfully.");
					#endif
					__Create3DLabelAndPickup(_EntranceLabelString, _xEntrance,_yEntrance,_zEntrance, 
						_xVirtualWorldid, 19133, 3.0, 
						g_PropertyData[g_PropertyID][p_PropertyLabelID], 
						g_PropertyData[g_PropertyID][p_PropertyPickupID]);
					#if defined detutils_debug
					printf("[DETUtils]: (debug) - lab :: Created 3D label and pickup on entrance.");
					#endif
					__Create3DLabelAndPickup("Exit here!", g_PropertyData[g_PropertyID][p_PropertyExit_X],
						g_PropertyData[g_PropertyID][p_PropertyExit_Y], 
						g_PropertyData[g_PropertyID][p_PropertyExit_Z], 
						_eVirtualWorldid, 19133, 3.0,
						g_PropertyData[g_PropertyID][p_PropertyLabel], 
						g_PropertyData[g_PropertyID][p_PropertyPickup]);
					#if defined detutils_debug
					printf("[DETUtils]: (debug) - pick :: Created 3D label and pickup on exit.");
					#endif
				}

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - Internal property data assigned.");
				#endif

				if(funcidx("OnPropertyCreate") != -1)
				{
					CallLocalFunction("OnPropertyCreate", "i", g_PropertyID);
				}

				#if defined detutils_debug
				printf("[DETUtils]: (debug) - OnPropertyCreate(propertyid) called.");
				#endif

				g_PropertyData[g_PropertyID][ValidProp] = 1;
				DET_g_CreatedProperties ++;
				break;
			}
			else
			{
				if(DET_g_CreatedProperties == MAX_PROPERTIES)
				{
					#if defined detutils_debug
					for(new i = 0; i < MAX_PLAYERS; i++)
					{
						if(i != INVALID_PLAYER_ID)
						{
							d_SendWarningMessage(i, DETUTILS_TEXT_MAX_PROPS_REACH);
						}
					}
					#endif
					return 0;
				}
			}
		}
	return 1;
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
	// For all the players:
	for(new i; i < MAX_PLAYERS; i++)
	{
		// Set the internal team...
		strmid(g_PlayerTeamCache[i][Team], "NO_TEAM", 0, 32);
	}

	#if defined detutils_debug
	SaveLogIntoFile("detutils_teams.log", "[DETUtils]: (debug) - Loading...");
	SaveLogIntoFile("detutils_teams.log", "[DETUtils]: (debug) - Loaded.");
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

#define OnDETUtilsInit( d_t_detutilsinit(

forward d_t_detutilsinit();