/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this file are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this file except in compliance with 
    the License. You may obtain a copy of the License at 
    http://www.mozilla.org/MPL/
    
    Software distributed under the License is distributed on an "AS IS" basis,
    WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
    for the specific language governing rights and limitations under the
    License.
    
    The Original Code is SA:MP | DETUtils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:
    DEntisT

Thanks:
    Zeex - ideas and ZCMD
    open.mp team - ideas, support, help during development

Very special thanks to:
    Thiadmer - PAWN, whose limits continue to amaze me!
    Kye/Kalcor - SA:MP
    SA:MP Team past, present and future - SA:MP
    open.mp team present and future - SA:MP

Optional plugins:
    Incognito - streamer

*/

#if defined DEV_MODE

#include <a_samp>

#endif

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

#if defined d_interiors_included
    #endinput
#endif

#define d_interiors_included

#define DisableDefaultInteriors DisableInteriorEnterExits

#if !defined MAX_INTERIORS

#define MAX_INTERIORS 300

#endif

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

enum e_utils_INTERIOR_DATA
{
    e_utils_INTERIOR_NAME[32],

    Float:e_utils_INTENTRANCE_X,
    Float:e_utils_INTENTRANCE_Y,
    Float:e_utils_INTENTRANCE_Z,
    Float:e_utils_INTENTRANCE_A,

    Float:e_utils_INTEXIT_X,
    Float:e_utils_INTEXIT_Y,
    Float:e_utils_INTEXIT_Z,
    Float:e_utils_INTEXIT_A,

    e_utils_INTERIOR_INTID,
    e_utils_INTERIOR_INTID_OUT,
    e_utils_INTERIOR_VWID,
    e_utils_INTERIOR_VWID_OUT,

    e_utils_INTERIOR_PICKUP,
    e_utils_INTERIOR_PICKUPID,
    e_utils_INTERIOR_3DLABEL,
    e_utils_INTERIOR_3DLABELID
};

new utils_PlayersInterior[MAX_PLAYERS];

new utils_InteriorData[MAX_INTERIORS][e_utils_INTERIOR_DATA];

new utils_Interiorid;

new utils_EntranceTitleShown[MAX_PLAYERS];

#if !defined col_white
    #define col_white "{ffffff}"
#endif

/*

                                                              
88        88                            88                    
88        88                            88                    
88        88                            88                    
88aaaaaaaa88   ,adPPYba,    ,adPPYba,   88   ,d8   ,adPPYba,  
88""""""""88  a8"     "8a  a8"     "8a  88 ,a8"    I8[    ""  
88        88  8b       d8  8b       d8  8888[       `"Y8ba,   
88        88  "8a,   ,a8"  "8a,   ,a8"  88`"Yba,   aa    ]8I  
88        88   `"YbbdP"'    `"YbbdP"'   88   `Y8a  `"YbbdP"'  
                                                              
                                                              

*/

#define detutils_interiors_TRUE 1
#define detutils_interiors_FALSE 0

#define INTERIOR_ACTION_ENTER 0
#define INTERIOR_ACTION_EXIT 1

utils_InteriorLoadingTime(const playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - tpcll :: Player ( id : %i ) is now controlable.", playerid);
    #endif
    TogglePlayerControllable(playerid,true);
}

static utils_HideAnnouncement[MAX_PLAYERS];

static utils_Announcement(playerid, const utils_Message[])
{
    new cutils_Message[300];

    KillTimer(utils_HideAnnouncement[playerid]);

    format(cutils_Message,300,"%s",utils_Message);

    TextDrawShowForPlayer(playerid, utils_AnnouncementUsebox);

    PlayerTextDrawSetString( playerid, utils_AnnouncementString[ playerid ], cutils_Message );

    PlayerTextDrawShow(playerid,utils_AnnouncementString[ playerid ]);

    utils_HideAnnouncement[playerid] = utils_SetTimer("hideannouncement", 4000, false, "i", playerid);
    return detutils_interiors_TRUE;
}

util function:hideannouncement(playerid)
{
    TextDrawHideForPlayer(playerid, utils_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, utils_AnnouncementString[playerid]);
    KillTimer(utils_HideAnnouncement[playerid]);
    return detutils_interiors_TRUE;
}

static utils_CreateAnncTextDraws()
{
    utils_AnnouncementUsebox = TextDrawCreate(366.444427, 363.882232, "usebox");
    TextDrawLetterSize(utils_AnnouncementUsebox, 0.000000, 1.840366);
    TextDrawTextSize(utils_AnnouncementUsebox, 267.333312, 0.000000);
    TextDrawAlignment(utils_AnnouncementUsebox, 1);
    TextDrawColor(utils_AnnouncementUsebox, 0);
    TextDrawUseBox(utils_AnnouncementUsebox, true);

    TextDrawBoxColor(utils_AnnouncementUsebox, 102);
    TextDrawSetShadow(utils_AnnouncementUsebox, 0);
    TextDrawSetOutline(utils_AnnouncementUsebox, 0);
    TextDrawFont(utils_AnnouncementUsebox, 0);
    return detutils_interiors_TRUE;
}

static utils_CreatePlayerTextDraws(playerid)
{
    utils_AnnouncementString[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "string");
    PlayerTextDrawLetterSize(playerid, utils_AnnouncementString[playerid], 0.201111, 1.346133);

    PlayerTextDrawAlignment(playerid, utils_AnnouncementString[playerid], 2);
    PlayerTextDrawColor(playerid, utils_AnnouncementString[playerid], -1);
    PlayerTextDrawSetShadow(playerid, utils_AnnouncementString[playerid], 0);

    PlayerTextDrawSetOutline(playerid, utils_AnnouncementString[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, utils_AnnouncementString[playerid], 51);
    PlayerTextDrawFont(playerid, utils_AnnouncementString[playerid], 2);
    PlayerTextDrawSetProportional(playerid, utils_AnnouncementString[playerid], 1);
    return detutils_interiors_TRUE;
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    utils_CreateAnncTextDraws();
    if(funcidx("a_ints_OnGameModeInit") != -1)
    {
        CallLocalFunction("a_ints_OnGameModeInit", "");
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_ints_OnGameModeInit

forward a_ints_OnGameModeInit();

#endif

public OnPlayerConnect(playerid)
{
    utils_CreatePlayerTextDraws(playerid);
    if(funcidx("a_ints_OnPlayerConnect") != -1)
    {
        CallLocalFunction("a_ints_OnPlayerConnect", "i", playerid);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect a_ints_OnPlayerConnect

forward a_ints_OnPlayerConnect(playerid);

public OnPlayerSpawn(playerid)
{
    TextDrawHideForPlayer(playerid, utils_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, utils_AnnouncementString[playerid]);
    if(funcidx("a_ints_OnplayerSpawn") != -1)
    {
        CallLocalFunction("a_ints_OnplayerSpawn", "i", playerid);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn a_ints_OnplayerSpawn

forward a_ints_OnplayerSpawn(playerid);

utils_OnPlayerNearEntrance(playerid);

public utils_OnPlayerNearEntrance(playerid)
{
    new utils_InteriorFunctionName[100];
    new utils_InteriorActionid;
    TogglePlayerControllable(playerid,false);
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, utils_InteriorData[ i ][e_utils_INTENTRANCE_X], \
        utils_InteriorData[ i ][e_utils_INTENTRANCE_Y], utils_InteriorData[ i ][e_utils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == utils_InteriorData[ i ][e_utils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            utils_InteriorActionid = 0;
            format(utils_InteriorFunctionName,sizeof(utils_InteriorFunctionName),
                "%s@int",utils_InteriorData[ i ][e_utils_INTERIOR_NAME]);

            if(funcidx(utils_InteriorFunctionName) != -1) CallLocalFunction(utils_InteriorFunctionName,
                                                                "ii",playerid,utils_InteriorActionid);

            SetPlayerInterior( playerid, utils_InteriorData[ i ][e_utils_INTERIOR_INTID] );
            SetPlayerVirtualWorld( playerid, utils_InteriorData[ i ][e_utils_INTERIOR_VWID] );
            
            SetPlayerPos( playerid, utils_InteriorData[ i ][e_utils_INTEXIT_X], utils_InteriorData[ i ][e_utils_INTEXIT_Y], \
            utils_InteriorData[ i ][e_utils_INTEXIT_Z] );
            
            SetPlayerFacingAngle( playerid, utils_InteriorData[ i ][e_utils_INTEXIT_A] );
            SetCameraBehindPlayer( playerid );
            
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player entered the interior with id : %i.", i);
            #endif

            SetPlayerTime( playerid, 12, 0 );
            utils_InteriorLoadingTime(playerid);
            
            utils_PlayersInterior[ playerid ] = i;
            
        }
        else if( IsPlayerInRangeOfPoint( playerid, 1.5, utils_InteriorData[ i ][e_utils_INTEXIT_X], \
        utils_InteriorData[ i ][e_utils_INTEXIT_Y], utils_InteriorData[ i ][e_utils_INTEXIT_Z]) && \
        GetPlayerVirtualWorld( playerid ) == utils_InteriorData[ i ][e_utils_INTERIOR_VWID])
        {
            SetPlayerVirtualWorld( playerid, utils_InteriorData[ i ][e_utils_INTERIOR_VWID_OUT] );
            SetPlayerInterior( playerid, utils_InteriorData[ i ][e_utils_INTERIOR_INTID_OUT] );
            
            SetPlayerPos( playerid, utils_InteriorData[ i ][e_utils_INTENTRANCE_X], utils_InteriorData[ i ][e_utils_INTENTRANCE_Y], \
            utils_InteriorData[ i ][e_utils_INTENTRANCE_Z] );
            
            SetPlayerFacingAngle( playerid, utils_InteriorData[ i ][e_utils_INTENTRANCE_A] );
            SetCameraBehindPlayer( playerid );
            utils_InteriorLoadingTime(playerid);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player exited the interior with id : %i.", i);
            #endif

            utils_InteriorActionid = 1;
            format(utils_InteriorFunctionName,sizeof(utils_InteriorFunctionName),
                "%s@int",utils_InteriorData[ i ][e_utils_INTERIOR_NAME]);

            if(funcidx(utils_InteriorFunctionName) != -1) CallLocalFunction(utils_InteriorFunctionName,"ii",playerid,utils_InteriorActionid);

            utils_PlayersInterior[ playerid ] = -1;
        }
    }
    return detutils_interiors_TRUE;
}

public OnPlayerDisconnect(playerid, reason)
{
    ClearPlayerInteriorData(playerid);
    if(funcidx("aint_ALS_OnPlayerDisconnect") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerDisconnect", "ii", playerid, reason);
    }
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - playerdiscc :: Player interior data cleared.");
    #endif
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect aint_ALS_OnPlayerDisconnect

forward aint_ALS_OnPlayerDisconnect(playerid, reason);

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if( newkeys == KEY_SECONDARY_ATTACK)
    {
        if(GetPlayerState(playerid) == 1)
        {
            utils_OnPlayerNearEntrance(playerid);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - keystate :: OnPlayerNearEntrance called successfully.");
            #endif
        }

        if( GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_NONE && \
        GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_CUFFED)
        {
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }
    }
    if(funcidx("aint_ALS_OnPlayerKeyStateChange") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerKeyStateChange", "iii", playerid, newkeys, oldkeys);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange aint_ALS_OnPlayerKeyStateChange

forward aint_ALS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

util function:ResOnUpdateBool(playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - keystate :: util function 'ResOnUpdateBool' called successfully.");
    #endif

    utils_EntranceTitleShown[playerid] = 0;
    return detutils_interiors_TRUE;
}

public OnPlayerUpdate(playerid)
{
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, utils_InteriorData[ i ][e_utils_INTENTRANCE_X], \
        utils_InteriorData[ i ][e_utils_INTENTRANCE_Y], utils_InteriorData[ i ][e_utils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == utils_InteriorData[ i ][e_utils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ) && utils_EntranceTitleShown[playerid] != 1)
        {
            new utils_InteriorName[100];
            format(utils_InteriorName,sizeof(utils_InteriorName),"Property: %s",utils_InteriorData[ i ][ e_utils_INTERIOR_NAME ]);
            
            utils_Announcement(playerid, utils_InteriorName);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - playerupdate :: Gametext shown.");
            #endif
            utils_EntranceTitleShown[playerid] = 1;
            utils_SetTimer("ResOnUpdateBool", 10000, false, "i", playerid);
        }
    }
    if(funcidx("aint_ALS_OnPlayerUpdate") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerUpdate", "i", playerid);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate aint_ALS_OnPlayerUpdate

forward aint_ALS_OnPlayerUpdate(playerid);

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

stock Create3DLabelAndPickup( 
        const utils_LabelString[], 
        Float:utils_xPosition, 
        Float:utils_yPosition, 
        Float:utils_zPosition, 
        utils_Interior, 
        utils_VirtualWorld, 
        utils_Pickupid, 
        Float:utils_LabelRadius ) 
{
    if(IsValidString(utils_LabelString))
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: String checking finished.");
    #endif

    if(utils_Interior < 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Interiorid validity checked.");
    #endif

    if(utils_VirtualWorld < 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Virtual world validity checked.");
    #endif

    if(utils_LabelRadius <= 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Label visibility radius check finished.");
    #endif

    if(utils_Pickupid < 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Pickup id validity checked.");
    #endif

    CreateDynamic3DTextLabel(
                            utils_LabelString, 
                            0x0059FFAA, 
                            utils_xPosition, 
                            utils_yPosition, 
                            utils_zPosition, 
                            utils_LabelRadius, 
                            INVALID_PLAYER_ID, 
                            INVALID_VEHICLE_ID, 
                            0, 
                            utils_VirtualWorld, 
                            utils_Interior, 
                            -1, 
                            20.0);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created 3d label successfully.");
    #endif

    CreateDynamicPickup(
                    utils_Pickupid, 
                    1, 
                    utils_xPosition, 
                    utils_yPosition, 
                    utils_zPosition, 
                    utils_VirtualWorld, 
                    utils_Interior);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created dynamic pickup successfully.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Operation completed successfully. Error code: ERRNULL");
    #endif

    return detutils_interiors_TRUE;
}

stock CreateCustomInteriorEx(
        const utils_InteriorName[], 
        Float:utils_xEntrance, 
        Float:utils_yEntrance, 
        Float:utils_zEntrance, 
        Float:utils_xExit, 
        Float:utils_yExit, 
        Float:utils_zExit, 
        utils_eInteriorid, 
        utils_xInteriorid, 
        utils_eVirtualWorldid, 
        utils_xVirtualWorldid)
{
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            utils_InteriorName,
            Float:utils_xEntrance, 
            Float:utils_yEntrance, 
            Float:utils_zEntrance);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    utils_Interiorid++;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif

    strmid(utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_NAME], 
            utils_InteriorName, 
            0, 
            strlen(utils_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",utils_InteriorName,utils_Interiorid);

    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_X] = utils_xEntrance;
    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_Y] = utils_yEntrance;
    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_Z] = utils_zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_X] = utils_xExit;
    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_Y] = utils_yExit;
    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_Z] = utils_zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_INTID] = utils_eInteriorid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_INTID_OUT] = utils_xInteriorid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_VWID] = utils_eVirtualWorldid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_VWID_OUT] = utils_xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    new utils_EntranceLabelString[300];
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Empty string declared.");
    #endif
    format(utils_EntranceLabelString,sizeof(utils_EntranceLabelString),"{ffffff}[ %s ]\n"col_white"Enter here!",utils_InteriorName);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Formatted the 3D label string successfully.");
    #endif
    Create3DLabelAndPickup(utils_EntranceLabelString, utils_xEntrance,utils_yEntrance,utils_zEntrance, -1, -1, 19133, 2.0);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on entrance.");
    #endif
    Create3DLabelAndPickup("Exit here!", utils_xExit,utils_yExit,utils_zExit, -1, -1, 19133, 2.0);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on exit.");
    #endif
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif
    return detutils_interiors_TRUE;
}

stock CreateCustomInterior(
        const utils_InteriorName[], 
        Float:utils_xEntrance, 
        Float:utils_yEntrance, 
        Float:utils_zEntrance, 
        Float:utils_xExit, 
        Float:utils_yExit, 
        Float:utils_zExit, 
        utils_eInteriorid, 
        utils_xInteriorid, 
        utils_eVirtualWorldid, 
        utils_xVirtualWorldid)
{
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            utils_InteriorName,
            Float:utils_xEntrance, 
            Float:utils_yEntrance, 
            Float:utils_zEntrance);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    utils_Interiorid++;

    strmid(utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_NAME], 
            utils_InteriorName, 
            0, 
            strlen(utils_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",utils_InteriorName,utils_Interiorid);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif
    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_X] = utils_xEntrance;
    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_Y] = utils_yEntrance;
    utils_InteriorData[utils_Interiorid][e_utils_INTENTRANCE_Z] = utils_zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_X] = utils_xExit;
    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_Y] = utils_yExit;
    utils_InteriorData[utils_Interiorid][e_utils_INTEXIT_Z] = utils_zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_INTID] = utils_eInteriorid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_INTID_OUT] = utils_xInteriorid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_VWID] = utils_eVirtualWorldid;
    utils_InteriorData[utils_Interiorid][e_utils_INTERIOR_VWID_OUT] = utils_xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif

    return detutils_interiors_TRUE;
}

stock bool:IsPlayerInCustomInterior(playerid)
{
    if(utils_PlayersInterior[ playerid ] == -1) return false;
    else return true;
}

stock ClearPlayerInteriorData(playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData called successfully.");
    #endif
    utils_PlayersInterior[playerid] = -1;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData action successfully performed.");
    #endif
    return detutils_interiors_TRUE;
}

stock GetLastInterioridUsed()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - GetLastInterioridUsed successfully called.");
    #endif
    return utils_Interiorid;
}

stock SetInteriorEntranceCustomAngles(
        const utils_CustomInteriorid,
        Float:utils_aAngle,
        Float:utils_bAngle)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set interior (intid : %i) angles to %f-%f.", 
        utils_CustomInteriorid, utils_aAngle, utils_bAngle);
    #endif
    utils_InteriorData[utils_CustomInteriorid][e_utils_INTENTRANCE_A] = utils_aAngle;
    utils_InteriorData[utils_CustomInteriorid][e_utils_INTEXIT_A] = utils_bAngle;
    return detutils_interiors_TRUE;
}

/*

                                                                                                 
88888888888                                                          db         88888888ba   88  
88                          ,d                                      d88b        88      "8b  88  
88                          88                                     d8'`8b       88      ,8P  88  
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,         d8'  `8b      88aaaaaa8P'  88  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8        d8YaaaaY8b     88""""""'    88  
88              )888(       88     88          ,adPPPPP88       d8""""""""8b    88           88  
88            ,d8" "8b,     88,    88          88,    ,88      d8'        `8b   88           88  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8     d8'          `8b  88           88  
                                                                                                 
                                                                                                 
*/

#if !defined A_INTS_COMPATIBILITY_MODE

#define interior%0(%1) \
    forward%0@int(%1,utils_Actionid); \
    public%0@int(%1,utils_Actionid)

#else

#define INTERIOR__%0(%1) \
    forward%0@int(%1,utils_Actionid); \
    public%0@int(%1,utils_Actionid)

#endif

stock SetPlayerCustomInterior(utils_p_Playerid, putils_Interiorid)
{
    if(putils_Interiorid < -1)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set players (id : %i) interior to %i.", utils_p_Playerid, putils_Interiorid);
    #endif

    utils_PlayersInterior[utils_p_Playerid] = putils_Interiorid;
    return detutils_interiors_TRUE;
}

#define IsInteriorActionPerformed(%0) \
    utils_Actionid == %0

static AnnounceLibraryLoaded_int()
{
    print("|======================================|");
    print("            d_interiors.inc             ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_int();
    a_int_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_int_main

#else

public OnFilterScriptInit()
{
    utils_CreateAnncTextDraws();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_int();

    if(funcidx("a_int_OnFilterScriptInit") != -1)
    {
        CallLocalFunction("a_int_OnFilterScriptInit", "i", playerid);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_int_OnFilterScriptInit

forward a_int_OnFilterScriptInit();

#endif