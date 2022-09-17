/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides
 *   creation of factions, adding
 *   and removing players from them.
 *
 * - Also extends the features of
 *   other includes such as
 *   d_commands or d_properties.
 *
 *
 */

#if !defined DETUTILS_NO_PERMISSIONS

    #include "d_factions_permissions"

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

#define @DETUTILS_CMD_DEC__@FACTION_COMMAND%6,%5.faction%3=%2)%0(%1,%7[%8]%9) DETUTILSCMD_TYPESET__$|<%0>,SLASH_COMMAND_TYPE_FACTION| \
    @DETUTILSCMD_TEAMS_DECL__|%0..%1,%7| @DETUTILSCMD_TEAMS_CHECK__:{%1..|%2|..%0,%7} @DETUTILSCMD_TEAMS_CALL___:|||%0|%1..%7|

#endif

#if defined DETUTILS_NO_PROPERTIES

#define MAX_FACTIONS 256

enum enum_FactionData
{
    ValidFaction,
    FactionName[32],
    FactionMembers
}

new DET_g_FactionCache[MAX_FACTIONS][enum_FactionData];

enum enum_PlayerFactionData
{
    Faction[32]
}

new DET_g_PlayerFactionCache[MAX_PLAYERS][enum_PlayerFactionData];

#endif

forward OnFactionCreate(factionid, factionname[]);
forward OnFactionDelete(factionid, factionname[]);

stock CreateFaction(const name[])
{
    if(!strcmp("NO_FACTION", name, false))
    {
        printf("[DETUtils]: (denied) - Permission to create the faction 'NO_FACTION' denied.");
        return 0;
    }
    for(new i = 1;
        i < MAX_FACTIONS;
        i++)
    {
        if(DET_g_FactionCache[i][ValidFaction] == 0)
        {
            if(funcidx("OnFactionCreate") != -1)
            {
                CallLocalFunction("OnFactionCreate", "is", i, name);
            }
            strmid(DET_g_FactionCache[i][FactionName], name, 0, 32);
            DET_g_FactionCache[i][ValidFaction] = 1;
            #if defined DETUTILS_DEBUG_MODE
            printf("[DETUtils]: (faction create) - Created a faction '%s'.", name);
            #endif
            return 1;
        }
    }
    return 0;
}

stock DeleteFaction(const name[])
{
    if(!strcmp("NO_FACTION", name, false))
    {
        printf("[DETUtils]: (denied) - Permission to delete the faction 'NO_FACTION' denied.");
        return 0;
    }
    for(new i = 1;
        i < MAX_FACTIONS;
        i++)
    {
        if(!strcmp(DET_g_FactionCache[i][FactionName], name, false))
        {
            if(DET_g_FactionCache[i][FactionMembers] != 0)
            {
                printf("[DETUtils]: (faction error) - Unable to delete a faction '%s'; \
                    firstly remove all the players from that faction.", name);
                return 0;
            }
            if(funcidx("OnFactionDelete") != -1)
            {
                CallLocalFunction("OnFactionDelete", "is", i, name);
            }
            #if defined DETUTILS_DEBUG_MODE
            printf("[DETUtils]: (faction delete) - Deleted a faction '%s'.", name);
            #endif
            strmid(DET_g_FactionCache[i][FactionName], "__INVALID_FACTION_NAME", 0, 32);
            DET_g_FactionCache[i][ValidFaction] = 0;
            return 1;
        }
    }
    return 0;
}

stock SetPlayerFaction(playerid, const name[])
{
    if(!strcmp(name, "NO_FACTION", false)) // If the faction is 'NO_FACTION', set player's faction to nothing.
    {
        for(new i = 1;
            i < MAX_FACTIONS;
            i++)
        {
            if(!strcmp(DET_g_FactionCache[i][FactionName], DET_g_PlayerFactionCache[playerid][Faction], false))
            {
                DET_g_FactionCache[i][FactionMembers] --;
            }
        }
        #if defined DETUTILS_DEBUG_MODE
            printf("[DETUtils]: (faction set) - Player '%i' added to a faction '%s'.", playerid, name);
        #endif
        strmid(DET_g_PlayerFactionCache[playerid][Faction], "NO_FACTION", 0, 32);
        return 1;
    }
    else
    {
        for(new i = 1;
            i < MAX_FACTIONS;
            i++)
        {
            if(!strcmp(DET_g_FactionCache[i][FactionName], name, false))
            {
                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (faction set) - Player '%i' added to a faction '%s'.", playerid, name);
                #endif
                DET_g_FactionCache[i][FactionMembers] ++;
                strmid(DET_g_PlayerFactionCache[playerid][Faction], name, 0, 32);
                return 1;
            }
        }
    }
    return 0;
}

stock GetPlayerFaction(playerid, name[], size = sizeof name)
{
    format(name, size, DET_g_PlayerFactionCache[playerid][Faction]);
    return 1;
}

stock GetFactionMemberCount(const name[])
{
    for(new i = 1;
        i < MAX_FACTIONS;
        i++)
    {
        if(!strcmp(DET_g_FactionCache[i][FactionName], name, false))
        {
            return DET_g_FactionCache[i][FactionMembers];
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
    if(strcmp(DET_g_PlayerFactionCache[playerid][Faction], 
        DET_g_PlayerFactionCache[damagedid][Faction],
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
    // Set the internal faction when player disconnects...
    //strmid(DET_g_PlayerFactionCache[playerid][Faction], "NO_FACTION", 0, 32);
    SetPlayerFaction(playerid, "NO_FACTION");

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

stock CreateFactionPropertyEntrance(
        const PropertyName[],
        const factionname[], 
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
        _eVirtualWorldid = 0,
        const event[] = "")
{
    for(new g_PropertyID = 1; 
        g_PropertyID < MAX_PROPERTIES; 
        g_PropertyID++)
        {
            if(DET_g_PropertyData[g_PropertyID][ValidProp] == 0)
            {
                DET_g_PropertyData[g_PropertyID][p_PropertyFaction] = 1;
                strmid(DET_g_PropertyData[g_PropertyID][p_PropFaction], factionname, 0, 32);
                printf("[DETUtils]: (debug) - Property '%s' successfully created, entrance is set to: %f, %f, %f.",
                        PropertyName,
                        Float:_xEntrance, 
                        Float:_yEntrance, 
                        Float:_zEntrance);
                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Property created.");
                #endif

                //g_PropertyID++;

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Property id assigned.");
                #endif

                strmid(DET_g_PropertyData[g_PropertyID][p_PropertyName], 
                        PropertyName, 
                        0, 
                        strlen(PropertyName), 
                        255);

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Saved property name.");
                #endif

                printf("[DETUtils]: (debug) - Property '%s' has an id %d.",PropertyName,g_PropertyID);

                DET_g_PropertyData[g_PropertyID][p_PropertyEntrance_X] = _xEntrance;
                DET_g_PropertyData[g_PropertyID][p_PropertyEntrance_Y] = _yEntrance;
                DET_g_PropertyData[g_PropertyID][p_PropertyEntrance_Z] = _zEntrance;

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Entrance coordinates assigned to property data.");
                #endif

                DET_g_PropertyData[g_PropertyID][p_PropertyExit_X] = _xExit;
                DET_g_PropertyData[g_PropertyID][p_PropertyExit_Y] = _yExit;
                DET_g_PropertyData[g_PropertyID][p_PropertyExit_Z] = _zExit;

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Exit coordinates assigned to property data.");
                #endif

                DET_g_PropertyData[g_PropertyID][p_PropertyIntid] = _eInteriorid;
                DET_g_PropertyData[g_PropertyID][p_PropertyIntid_OUT] = _xInteriorid;
                DET_g_PropertyData[g_PropertyID][p_PropertyVwid] = _eVirtualWorldid;
                DET_g_PropertyData[g_PropertyID][p_PropertyVwid_OUT] = _xVirtualWorldid;

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Virtual world IDs and interior IDs assigned to property data.");
                #endif

                if(Interior != INTERIOR_CUSTOM)
                {
                    #if defined DETUTILS_DEBUG_MODE
                    printf("[DETUtils]: (debug) - Assigned interior map id to property id : %i", Interior);
                    #endif

                    if(Interior == INTERIOR_MARKET_247_1)
                    {
                        DET_g_PropertyData[g_PropertyID][p_PropertyIntid] = 17;
                        DET_g_PropertyData[g_PropertyID][p_PropertyVwid] = 17;
                        _eInteriorid = 17;
                        _eVirtualWorldid = 17;

                        DET_g_PropertyData[g_PropertyID][p_PropertyExit_X] = -25.884498;
                        DET_g_PropertyData[g_PropertyID][p_PropertyExit_Y] = -185.868988;
                        DET_g_PropertyData[g_PropertyID][p_PropertyExit_Z] = 1003.546875;
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
                    #if defined DETUTILS_DEBUG_MODE
                    printf("[DETUtils]: (debug) - Empty string declared.");
                    #endif
                    format(_EntranceLabelString,sizeof(_EntranceLabelString),"{ffffff}[ %s ]\n{ffffff}Enter here!",PropertyName);
                    #if defined DETUTILS_DEBUG_MODE
                    printf("[DETUtils]: (debug) - Formatted the 3D label string successfully.");
                    #endif
                    __Create3DLabelAndPickup(_EntranceLabelString, _xEntrance,_yEntrance,_zEntrance, 
                        _xVirtualWorldid, 19133, 3.0, 
                        DET_g_PropertyData[g_PropertyID][p_PropertyLabelID], 
                        DET_g_PropertyData[g_PropertyID][p_PropertyPickupID]);
                    #if defined DETUTILS_DEBUG_MODE
                    printf("[DETUtils]: (debug) - lab :: Created 3D label and pickup on entrance.");
                    #endif
                    __Create3DLabelAndPickup("Exit here!", DET_g_PropertyData[g_PropertyID][p_PropertyExit_X],
                        DET_g_PropertyData[g_PropertyID][p_PropertyExit_Y], 
                        DET_g_PropertyData[g_PropertyID][p_PropertyExit_Z], 
                        _eVirtualWorldid, 19133, 3.0,
                        DET_g_PropertyData[g_PropertyID][p_PropertyLabel], 
                        DET_g_PropertyData[g_PropertyID][p_PropertyPickup]);
                    #if defined DETUTILS_DEBUG_MODE
                    printf("[DETUtils]: (debug) - pick :: Created 3D label and pickup on exit.");
                    #endif
                }

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - Internal property data assigned.");
                #endif

                if(funcidx("OnPropertyCreate") != -1)
                {
                    CallLocalFunction("OnPropertyCreate", "i", g_PropertyID);
                }

                #if defined DETUTILS_DEBUG_MODE
                printf("[DETUtils]: (debug) - OnPropertyCreate(propertyid) called.");
                #endif

                #if !defined DETUTILS_NO_EVENTS
                    strmid(DET_g_PropertyData[g_PropertyID][p_Event], event, 0, 32);
                #endif

                DET_g_PropertyData[g_PropertyID][ValidProp] = 1;
                DET_g_CreatedProperties ++;
                break;
            }
            else
            {
                if(DET_g_CreatedProperties == MAX_PROPERTIES)
                {
                    #if defined DETUTILS_DEBUG_MODE
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