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

#define DisableDefaultInteriors DisableInteriorEnterExits

#if !defined MAX_INTERIORS

#define MAX_INTERIORS 300

#endif

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

enum e_DETUtils_INTERIOR_DATA
{
    e_DETUtils_INTERIOR_NAME[32],

    Float:e_DETUtils_INTENTRANCE_X,
    Float:e_DETUtils_INTENTRANCE_Y,
    Float:e_DETUtils_INTENTRANCE_Z,
    Float:e_DETUtils_INTENTRANCE_A,

    Float:e_DETUtils_INTEXIT_X,
    Float:e_DETUtils_INTEXIT_Y,
    Float:e_DETUtils_INTEXIT_Z,
    Float:e_DETUtils_INTEXIT_A,

    e_DETUtils_INTERIOR_INTID,
    e_DETUtils_INTERIOR_INTID_OUT,
    e_DETUtils_INTERIOR_VWID,
    e_DETUtils_INTERIOR_VWID_OUT,

    e_DETUtils_INTERIOR_PICKUP,
    e_DETUtils_INTERIOR_PICKUPID,
    e_DETUtils_INTERIOR_3DLABEL,
    e_DETUtils_INTERIOR_3DLABELID
};

new gDETUtils_PlayersInterior[MAX_PLAYERS];

new InteriorData:[e_DETUtils_INTERIOR_DATA];

new gDETUtils_Interiorid;

new Global:EntranceTitleShown<>[MAX_PLAYERS];

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

#define DETUtils_INTERIORS_TRUE 1
#define DETUtils_INTERIORS_FALSE 0

#define INTERIOR_ACTION_ENTER 0
#define INTERIOR_ACTION_EXIT 1

gDETUtils_InteriorLoadingTime(const playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - tpcll :: Player ( id : %i ) is now controlable.", playerid);
    #endif
    TogglePlayerControllable(playerid,true);
}

static Global:HideAnnouncement<>[MAX_PLAYERS];

static Private:Announcement<>(playerid, const Private:Message<>[])
{
    new cDETUtils_Message[300];

    KillTimer(Global:HideAnnouncement<>[playerid]);

    format(cDETUtils_Message,300,"%s",Private:Message<>);

    TextDrawShowForPlayer(playerid, gDETUtils_AnnouncementUsebox);

    PlayerTextDrawSetString( playerid, gDETUtils_AnnouncementString[ playerid ], cDETUtils_Message );

    PlayerTextDrawShow(playerid,gDETUtils_AnnouncementString[ playerid ]);

    Global:HideAnnouncement<>[playerid] = Global:set_detutils_timer<>("hideannouncement", 4000, false, "i", playerid);
    return DETUtils_INTERIORS_TRUE;
}

DETUtilsFunc:hideannouncement(playerid)
{
    TextDrawHideForPlayer(playerid, gDETUtils_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, gDETUtils_AnnouncementString[playerid]);
    KillTimer(Global:HideAnnouncement<>[playerid]);
    return DETUtils_INTERIORS_TRUE;
}

static Global:CreateAnncTextdraws<>()
{
    gDETUtils_AnnouncementUsebox = TextDrawCreate(366.444427, 363.882232, "usebox");
    TextDrawLetterSize(gDETUtils_AnnouncementUsebox, 0.000000, 1.840366);
    TextDrawTextSize(gDETUtils_AnnouncementUsebox, 267.333312, 0.000000);
    TextDrawAlignment(gDETUtils_AnnouncementUsebox, 1);
    TextDrawColor(gDETUtils_AnnouncementUsebox, 0);
    TextDrawUseBox(gDETUtils_AnnouncementUsebox, true);

    TextDrawBoxColor(gDETUtils_AnnouncementUsebox, 102);
    TextDrawSetShadow(gDETUtils_AnnouncementUsebox, 0);
    TextDrawSetOutline(gDETUtils_AnnouncementUsebox, 0);
    TextDrawFont(gDETUtils_AnnouncementUsebox, 0);
    return DETUtils_INTERIORS_TRUE;
}

static Global:CreatePlayerTextdraws<>(playerid)
{
    gDETUtils_AnnouncementString[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "string");
    PlayerTextDrawLetterSize(playerid, gDETUtils_AnnouncementString[playerid], 0.201111, 1.346133);

    PlayerTextDrawAlignment(playerid, gDETUtils_AnnouncementString[playerid], 2);
    PlayerTextDrawColor(playerid, gDETUtils_AnnouncementString[playerid], -1);
    PlayerTextDrawSetShadow(playerid, gDETUtils_AnnouncementString[playerid], 0);

    PlayerTextDrawSetOutline(playerid, gDETUtils_AnnouncementString[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, gDETUtils_AnnouncementString[playerid], 51);
    PlayerTextDrawFont(playerid, gDETUtils_AnnouncementString[playerid], 2);
    PlayerTextDrawSetProportional(playerid, gDETUtils_AnnouncementString[playerid], 1);
    return DETUtils_INTERIORS_TRUE;
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    Global:CreateAnncTextdraws<>();
    if(funcidx("a_ints_OnGameModeInit") != -1)
    {
        CallLocalFunction("a_ints_OnGameModeInit", "");
    }
    return DETUtils_INTERIORS_TRUE;
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
    Global:CreatePlayerTextdraws<>(playerid);
    if(funcidx("a_ints_OnPlayerConnect") != -1)
    {
        CallLocalFunction("a_ints_OnPlayerConnect", "i", playerid);
    }
    return DETUtils_INTERIORS_TRUE;
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
    TextDrawHideForPlayer(playerid, gDETUtils_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, gDETUtils_AnnouncementString[playerid]);
    if(funcidx("a_ints_OnplayerSpawn") != -1)
    {
        CallLocalFunction("a_ints_OnplayerSpawn", "i", playerid);
    }
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnplayerSpawn
    #undef OnplayerSpawn
#else
    #define _ALS_OnplayerSpawn
#endif

#define OnplayerSpawn a_ints_OnplayerSpawn

forward a_ints_OnplayerSpawn(playerid);

DETUtils_OnPlayerNearEntrance(playerid);
public DETUtils_OnPlayerNearEntrance(playerid)
{
    new Private:InteriorFunctionName<>[100];
    new Private:InteriorActionid<>;
    TogglePlayerControllable(playerid,false);
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            DETUtils_InteriorActionid = 0;
            format(DETUtils_InteriorFunctionName,sizeof(DETUtils_InteriorFunctionName),
                "%s@int",gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_NAME]);

            if(funcidx(DETUtils_InteriorFunctionName) != -1) CallLocalFunction(DETUtils_InteriorFunctionName,
                                                                "ii",playerid,DETUtils_InteriorActionid);

            SetPlayerInterior( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_INTID] );
            SetPlayerVirtualWorld( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID] );
            
            SetPlayerPos( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_X], gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Y], \
            gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Z] );
            
            SetPlayerFacingAngle( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_A] );
            SetCameraBehindPlayer( playerid );
            
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player entered the interior with id : %i.", i);
            #endif

            SetPlayerTime( playerid, 12, 0 );
            gDETUtils_InteriorLoadingTime(playerid);
            
            gDETUtils_PlayersInterior[ playerid ] = i;
            
        }
        else if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Z]) && \
        GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID])
        {
            SetPlayerVirtualWorld( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] );
            SetPlayerInterior( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_INTID_OUT] );
            
            SetPlayerPos( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], \
            gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z] );
            
            SetPlayerFacingAngle( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_A] );
            SetCameraBehindPlayer( playerid );
            gDETUtils_InteriorLoadingTime(playerid);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player exited the interior with id : %i.", i);
            #endif

            DETUtils_InteriorActionid = 1;
            format(DETUtils_InteriorFunctionName,sizeof(DETUtils_InteriorFunctionName),
                "%s@int",gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_NAME]);

            if(funcidx(DETUtils_InteriorFunctionName) != -1) CallLocalFunction(DETUtils_InteriorFunctionName,"ii",playerid,DETUtils_InteriorActionid);

            gDETUtils_PlayersInterior[ playerid ] = -1;
        }
    }
    return DETUtils_INTERIORS_TRUE;
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
    return DETUtils_INTERIORS_TRUE;
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
            DETUtils_OnPlayerNearEntrance(playerid);
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
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange aint_ALS_OnPlayerKeyStateChange

forward aint_ALS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

DETUtilsFunc:reset_gmtext_boolean(playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - keystate :: DETUtilsFunc 'reset_gmtext_boolean' called successfully.");
    #endif

    GlobalVarGet(EntranceTitleShown)[playerid] = 0;
    return DETUtils_INTERIORS_TRUE;
}

public OnPlayerUpdate(playerid)
{
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ) && Global:EntranceTitleShown<>[playerid] != 1)
        {
            new DETUtils_InteriorName[100];
            format(DETUtils_InteriorName,sizeof(DETUtils_InteriorName),"Property: %s",gDETUtils_InteriorData[ i ][ e_DETUtils_INTERIOR_NAME ]);
            
            Private:Announcement<>(playerid, DETUtils_InteriorName);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - playerupdate :: Gametext shown.");
            #endif
            GlobalVarGet(EntranceTitleShown)[playerid] = 1;
            Global:set_detutils_timer<>("reset_gmtext_boolean", 10000, false, "i", playerid);
        }
    }
    if(funcidx("aint_ALS_OnPlayerUpdate") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerUpdate", "i", playerid);
    }
    return DETUtils_INTERIORS_TRUE;
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
        const DETUtils_LabelString[], 
        Float:DETUtils_xPosition, 
        Float:DETUtils_yPosition, 
        Float:DETUtils_zPosition, 
        DETUtils_Interior, 
        DETUtils_VirtualWorld, 
        DETUtils_Pickupid, 
        Float:DETUtils_LabelRadius ) 
{
    if(IsValidString(DETUtils_LabelString))
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: String checking finished.");
    #endif

    if(DETUtils_Interior < 0)
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Interiorid validity checked.");
    #endif

    if(DETUtils_VirtualWorld < 0)
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Virtual world validity checked.");
    #endif

    if(DETUtils_LabelRadius <= 0)
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Label visibility radius check finished.");
    #endif

    if(DETUtils_Pickupid < 0)
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Pickup id validity checked.");
    #endif

    CreateDynamic3DTextLabel(
                            DETUtils_LabelString, 
                            0x0059FFAA, 
                            DETUtils_xPosition, 
                            DETUtils_yPosition, 
                            DETUtils_zPosition, 
                            DETUtils_LabelRadius, 
                            INVALID_PLAYER_ID, 
                            INVALID_VEHICLE_ID, 
                            0, 
                            DETUtils_VirtualWorld, 
                            DETUtils_Interior, 
                            -1, 
                            20.0);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created 3d label successfully.");
    #endif

    CreateDynamicPickup(
                    DETUtils_Pickupid, 
                    1, 
                    DETUtils_xPosition, 
                    DETUtils_yPosition, 
                    DETUtils_zPosition, 
                    DETUtils_VirtualWorld, 
                    DETUtils_Interior);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created dynamic pickup successfully.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Operation completed successfully. Error code: ERRNULL");
    #endif

    return DETUtils_INTERIORS_TRUE;
}

stock CreateCustomInteriorEx(
        const DETUtils_InteriorName[], 
        Float:DETUtils_xEntrance, 
        Float:DETUtils_yEntrance, 
        Float:DETUtils_zEntrance, 
        Float:DETUtils_xExit, 
        Float:DETUtils_yExit, 
        Float:DETUtils_zExit, 
        DETUtils_eInteriorid, 
        DETUtils_xInteriorid, 
        DETUtils_eVirtualWorldid, 
        DETUtils_xVirtualWorldid)
{
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            DETUtils_InteriorName,
            Float:DETUtils_xEntrance, 
            Float:DETUtils_yEntrance, 
            Float:DETUtils_zEntrance);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    gDETUtils_Interiorid++;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif

    strmid(gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_NAME], 
            DETUtils_InteriorName, 
            0, 
            strlen(DETUtils_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",DETUtils_InteriorName,gDETUtils_Interiorid);

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_X] = DETUtils_xEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Y] = DETUtils_yEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Z] = DETUtils_zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_X] = DETUtils_xExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Y] = DETUtils_yExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Z] = DETUtils_zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID] = DETUtils_eInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID_OUT] = DETUtils_xInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID] = DETUtils_eVirtualWorldid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID_OUT] = DETUtils_xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    new DETUtils_EntranceLabelString[300];
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Empty string declared.");
    #endif
    format(DETUtils_EntranceLabelString,sizeof(DETUtils_EntranceLabelString),"{ffffff}[ %s ]\n"col_white"Enter here!",DETUtils_InteriorName);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Formatted the 3D label string successfully.");
    #endif
    Create3DLabelAndPickup(DETUtils_EntranceLabelString, DETUtils_xEntrance,DETUtils_yEntrance,DETUtils_zEntrance, -1, -1, 19133, 2.0);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on entrance.");
    #endif
    Create3DLabelAndPickup("Exit here!", DETUtils_xExit,DETUtils_yExit,DETUtils_zExit, -1, -1, 19133, 2.0);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on exit.");
    #endif
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif
    return DETUtils_INTERIORS_TRUE;
}

stock CreateCustomInterior(
        const DETUtils_InteriorName[], 
        Float:DETUtils_xEntrance, 
        Float:DETUtils_yEntrance, 
        Float:DETUtils_zEntrance, 
        Float:DETUtils_xExit, 
        Float:DETUtils_yExit, 
        Float:DETUtils_zExit, 
        DETUtils_eInteriorid, 
        DETUtils_xInteriorid, 
        DETUtils_eVirtualWorldid, 
        DETUtils_xVirtualWorldid)
{
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            DETUtils_InteriorName,
            Float:DETUtils_xEntrance, 
            Float:DETUtils_yEntrance, 
            Float:DETUtils_zEntrance);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    gDETUtils_Interiorid++;

    strmid(gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_NAME], 
            DETUtils_InteriorName, 
            0, 
            strlen(DETUtils_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",DETUtils_InteriorName,gDETUtils_Interiorid);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_X] = DETUtils_xEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Y] = DETUtils_yEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Z] = DETUtils_zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_X] = DETUtils_xExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Y] = DETUtils_yExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Z] = DETUtils_zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID] = DETUtils_eInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID_OUT] = DETUtils_xInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID] = DETUtils_eVirtualWorldid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID_OUT] = DETUtils_xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif

    return DETUtils_INTERIORS_TRUE;
}

stock bool:IsPlayerInCustomInterior(playerid)
{
    if(gDETUtils_PlayersInterior[ playerid ] == -1) return false;
    else return true;
}

stock ClearPlayerInteriorData(playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData called successfully.");
    #endif
    gDETUtils_PlayersInterior[playerid] = -1;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData action successfully performed.");
    #endif
    return DETUtils_INTERIORS_TRUE;
}

stock GetLastInterioridUsed()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - GetLastInterioridUsed successfully called.");
    #endif
    return gDETUtils_Interiorid;
}

stock SetInteriorEntranceCustomAngles(
        const DETUtils_CustomInteriorid,
        Float:DETUtils_aAngle,
        Float:DETUtils_bAngle)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set interior (intid : %i) angles to %f-%f.", 
        DETUtils_CustomInteriorid, DETUtils_aAngle, DETUtils_bAngle);
    #endif
    gDETUtils_InteriorData[DETUtils_CustomInteriorid][e_DETUtils_INTENTRANCE_A] = DETUtils_aAngle;
    gDETUtils_InteriorData[DETUtils_CustomInteriorid][e_DETUtils_INTEXIT_A] = DETUtils_bAngle;
    return DETUtils_INTERIORS_TRUE;
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
    forward%0@int(%1,DETUtils_Actionid); \
    public%0@int(%1,DETUtils_Actionid)

#else

#define INTERIOR__%0(%1) \
    forward%0@int(%1,DETUtils_Actionid); \
    public%0@int(%1,DETUtils_Actionid)

#endif

stock SetPlayerCustomInterior(DETUtils_p_Playerid, pDETUtils_Interiorid)
{
    if(pDETUtils_Interiorid < -1)
        return DETUtils_INTERIORS_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set players (id : %i) interior to %i.", DETUtils_p_Playerid, pDETUtils_Interiorid);
    #endif

    gDETUtils_PlayersInterior[DETUtils_p_Playerid] = pDETUtils_Interiorid;
    return DETUtils_INTERIORS_TRUE;
}

#define IsInteriorActionPerformed(%0) \
    DETUtils_Actionid == %0

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
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loading...");
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
    Global:CreateAnncTextdraws<>();
    AnnounceLibraryLoaded_int();

    if(funcidx("a_int_OnFilterScriptInit") != -1)
    {
        CallLocalFunction("a_int_OnFilterScriptInit", "i", playerid);
    }
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_int_OnFilterScriptInit

forward a_int_OnFilterScriptInit();

#endif