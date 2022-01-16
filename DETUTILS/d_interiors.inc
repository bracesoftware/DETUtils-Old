/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides creating
 *   of interior entrances and exits.
 *
 *
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

enum enum_InteriorData
{
    i_InteriorName[32],

    Float:i_InteriorEntrance_X,
    Float:i_InteriorEntrance_Y,
    Float:i_InteriorEntrance_Z,
    Float:i_InteriorEntrance_A,

    Float:i_InteriorExit_X,
    Float:i_InteriorExit_Y,
    Float:i_InteriorExit_Z,
    Float:i_InteriorExit_A,

    i_InteriorIntid,
    i_InteriorIntid_OUT,
    i_InteriorVwid,
    i_InteriorVwid_OUT,

    e__INTERIOR_PICKUP,
    e__INTERIOR_PICKUPID,
    e__INTERIOR_3DLABEL,
    e__INTERIOR_3DLABELID
};

forward OnCustomInteriorCreated(customintid);
forward OnPlayerEnterInterior(playerid);
forward OnPlayerExitInterior(playerid);

new _PlayersInterior[MAX_PLAYERS];

new g_InteriorData[MAX_INTERIORS][enum_InteriorData];

new _Interiorid;

new _EntranceTitleShown[MAX_PLAYERS];

// Interior IDs:

#define INTERIOR_CUSTOM         -1
#define INTERIOR_MARKET_247_1    0
#define INTERIOR_MARKET_247_2    1
#define INTERIOR_MARKET_247_3    2
#define INTERIOR_MARKET_247_4    3
#define INTERIOR_MARKET_247_5    4
#define INTERIOR_MARKET_247_6    5

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

#define int_%0\32; int_

#define detutils_interiors_TRUE 1
#define detutils_interiors_FALSE 0

#define INTERIOR_ACTION_ENTER 0
#define INTERIOR_ACTION_EXIT 1

void:_InteriorLoadingTime(const playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - tpcll :: Player ( id : %i ) is now controlable.", playerid);
    #endif
    rem:<To prevent symbol-never-used error:>;
    new _c = playerid;
    _c++;
    SetTimer("_ToggleControllable", 1000, false);
}

static g_HideAnnouncement[MAX_PLAYERS];

static _Announcement(playerid, const _Message[])
{
    new c_Message[300];

    KillTimer(g_HideAnnouncement[playerid]);

    format(c_Message,300,"%s",_Message);

    TextDrawShowForPlayer(playerid, g_AnnouncementUsebox);

    PlayerTextDrawSetString( playerid, g_AnnouncementString[ playerid ], c_Message );

    PlayerTextDrawShow(playerid,g_AnnouncementString[ playerid ]);

    g_HideAnnouncement[playerid] = _SetTimer("hideannouncement", 4000, false, "i", playerid);
    return detutils_interiors_TRUE;
}

util function:hideannouncement(playerid)
{
    TextDrawHideForPlayer(playerid, g_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, g_AnnouncementString[playerid]);
    KillTimer(g_HideAnnouncement[playerid]);
    return detutils_interiors_TRUE;
}

static _CreateAnncTextDraws()
{
    g_AnnouncementUsebox = TextDrawCreate(366.444427, 363.882232, "usebox");
    TextDrawLetterSize(g_AnnouncementUsebox, 0.000000, 1.840366);
    TextDrawTextSize(g_AnnouncementUsebox, 267.333312, 0.000000);
    TextDrawAlignment(g_AnnouncementUsebox, 1);
    TextDrawColor(g_AnnouncementUsebox, 0);
    TextDrawUseBox(g_AnnouncementUsebox, true);

    TextDrawBoxColor(g_AnnouncementUsebox, 102);
    TextDrawSetShadow(g_AnnouncementUsebox, 0);
    TextDrawSetOutline(g_AnnouncementUsebox, 0);
    TextDrawFont(g_AnnouncementUsebox, 0);
    return detutils_interiors_TRUE;
}

#define STRING "string"

static _CreatePlayerTextDraws(playerid)
{
    g_AnnouncementString[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "string");
    PlayerTextDrawLetterSize(playerid, g_AnnouncementString[playerid], 0.201111, 1.346133);

    PlayerTextDrawAlignment(playerid, g_AnnouncementString[playerid], 2);
    PlayerTextDrawColor(playerid, g_AnnouncementString[playerid], -1);
    PlayerTextDrawSetShadow(playerid, g_AnnouncementString[playerid], 0);

    PlayerTextDrawSetOutline(playerid, g_AnnouncementString[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, g_AnnouncementString[playerid], 51);
    PlayerTextDrawFont(playerid, g_AnnouncementString[playerid], 2);
    PlayerTextDrawSetProportional(playerid, g_AnnouncementString[playerid], 1);
    return detutils_interiors_TRUE;
}

forward _ToggleControllable();

public _ToggleControllable()
{
    for(new i; i < MAX_PLAYERS; i++)
    {
        TogglePlayerControllable(i, true);
    }
    rem:<This is used to prevent player being frozen for several minutes>;
    return 1;
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    _CreateAnncTextDraws();
    
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
    _CreatePlayerTextDraws(playerid);
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
    TextDrawHideForPlayer(playerid, g_AnnouncementUsebox);
    PlayerTextDrawHide(playerid, g_AnnouncementString[playerid]);
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

_OnPlayerNearEntrance(playerid);

public _OnPlayerNearEntrance(playerid)
{
    new _InteriorFunctionName[100];
    new _InteriorActionid;
    
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, g_InteriorData[ i ][i_InteriorEntrance_X], \
        g_InteriorData[ i ][i_InteriorEntrance_Y], g_InteriorData[ i ][i_InteriorEntrance_Z]) \
        && GetPlayerVirtualWorld( playerid ) == g_InteriorData[ i ][i_InteriorVwid_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            _InteriorActionid = 0;
            format(_InteriorFunctionName,sizeof(_InteriorFunctionName),
                "OnInteriorActionPerformed",g_InteriorData[ i ][i_InteriorName]);

            if(funcidx(_InteriorFunctionName) != -1) CallLocalFunction(_InteriorFunctionName,
                                                                "iii",playerid,i,_InteriorActionid);

            SetPlayerInterior( playerid, g_InteriorData[ i ][i_InteriorIntid] );
            SetPlayerVirtualWorld( playerid, g_InteriorData[ i ][i_InteriorVwid] );
            
            d_ac_SetPlayerPos( playerid, g_InteriorData[ i ][i_InteriorExit_X], g_InteriorData[ i ][i_InteriorExit_Y], \
            g_InteriorData[ i ][i_InteriorExit_Z] );
            
            SetPlayerFacingAngle( playerid, g_InteriorData[ i ][i_InteriorExit_A] );
            SetCameraBehindPlayer( playerid );
            
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player entered the interior with id : %i.", i);
            #endif

            TogglePlayerControllable(playerid,false);

            SetPlayerTime( playerid, 12, 0 );
            _InteriorLoadingTime(playerid);
            
            _PlayersInterior[ playerid ] = i;
            
            if(funcidx("OnPlayerEnterInterior") != -1)
                CallLocalFunction("OnPlayerEnterInterior", "i", playerid);
            
        }
        else if( IsPlayerInRangeOfPoint( playerid, 1.5, g_InteriorData[ i ][i_InteriorExit_X], \
        g_InteriorData[ i ][i_InteriorExit_Y], g_InteriorData[ i ][i_InteriorExit_Z]) && \
        GetPlayerVirtualWorld( playerid ) == g_InteriorData[ i ][i_InteriorVwid])
        {
            SetPlayerVirtualWorld( playerid, g_InteriorData[ i ][i_InteriorVwid_OUT] );
            SetPlayerInterior( playerid, g_InteriorData[ i ][i_InteriorIntid_OUT] );
            
            d_ac_SetPlayerPos( playerid, g_InteriorData[ i ][i_InteriorEntrance_X], g_InteriorData[ i ][i_InteriorEntrance_Y], \
            g_InteriorData[ i ][i_InteriorEntrance_Z] );
            
            SetPlayerFacingAngle( playerid, g_InteriorData[ i ][i_InteriorEntrance_A] );
            SetCameraBehindPlayer( playerid );

            TogglePlayerControllable(playerid,false);

            _InteriorLoadingTime(playerid);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player exited the interior with id : %i.", i);
            #endif

            _InteriorActionid = 1;
            format(_InteriorFunctionName,sizeof(_InteriorFunctionName),
                "OnInteriorActionPerformed",g_InteriorData[ i ][i_InteriorName]);

            if(funcidx(_InteriorFunctionName) != -1) CallLocalFunction(_InteriorFunctionName,"iii",playerid,i,_InteriorActionid);

            _PlayersInterior[ playerid ] = -1;
            
            if(funcidx("OnPlayerExitInterior") != -1)
                CallLocalFunction("OnPlayerExitInterior", "i", playerid);
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
            _OnPlayerNearEntrance(playerid);
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

    _EntranceTitleShown[playerid] = 0;
    return detutils_interiors_TRUE;
}

public OnPlayerUpdate(playerid)
{
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, g_InteriorData[ i ][i_InteriorEntrance_X], \
        g_InteriorData[ i ][i_InteriorEntrance_Y], g_InteriorData[ i ][i_InteriorEntrance_Z]) \
        && GetPlayerVirtualWorld( playerid ) == g_InteriorData[ i ][i_InteriorVwid_OUT] \
        && !IsPlayerInAnyVehicle( playerid ) && _EntranceTitleShown[playerid] != 1)
        {
            new _InteriorName[100];
            format(_InteriorName,sizeof(_InteriorName),"Property: %s",g_InteriorData[ i ][ i_InteriorName ]);
            
            _Announcement(playerid, _InteriorName);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - playerupdate :: Gametext shown.");
            #endif
            _EntranceTitleShown[playerid] = 1;
            _SetTimer("ResOnUpdateBool", 10000, false, "i", playerid);
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
        const _LabelString[], 
        Float:_xPosition, 
        Float:_yPosition, 
        Float:_zPosition,  
        _VirtualWorld, 
        _Pickupid, 
        Float:_LabelRadius ) 
{
    if(IsValidString(_LabelString))
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: String checking finished.");
    #endif

    if(_VirtualWorld < 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Virtual world validity checked.");
    #endif

    if(_LabelRadius <= 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Label visibility radius check finished.");
    #endif

    if(_Pickupid < 0)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Pickup id validity checked.");
    #endif

    Create3DTextLabel(
                            _LabelString, 
                            0xffffffff, 
                            _xPosition, 
                            _yPosition, 
                            _zPosition, 
                            _LabelRadius, 
                            _VirtualWorld);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created 3d label successfully.");
    #endif

    CreatePickup(
                    _Pickupid, 
                    1, 
                    _xPosition, 
                    _yPosition, 
                    _zPosition, 
                    _VirtualWorld);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - c3dladp :: Created dynamic pickup successfully.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Operation completed successfully. Error code: ERRNULL");
    #endif

    return detutils_interiors_TRUE;
}

stock CreateInteriorEntrance(
        const _InteriorName[], 
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
    if(_Interiorid == MAX_INTERIORS)
    {
        #if defined detutils_debug
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            if(i != INVALID_PLAYER_ID)
            {
                d_SendWarningMessage(i, "Maximum number of created interiors reached.");
            }
        }
        #endif
        return 0;
    }
    printf("[samp-detutils]: (debug) - Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            _InteriorName,
            Float:_xEntrance, 
            Float:_yEntrance, 
            Float:_zEntrance);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    _Interiorid++;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif

    strmid(g_InteriorData[_Interiorid][i_InteriorName], 
            _InteriorName, 
            0, 
            strlen(_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("[samp-detutils]: (debug) - Interior '%s' has an id %d.",_InteriorName,_Interiorid);

    g_InteriorData[_Interiorid][i_InteriorEntrance_X] = _xEntrance;
    g_InteriorData[_Interiorid][i_InteriorEntrance_Y] = _yEntrance;
    g_InteriorData[_Interiorid][i_InteriorEntrance_Z] = _zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    g_InteriorData[_Interiorid][i_InteriorExit_X] = _xExit;
    g_InteriorData[_Interiorid][i_InteriorExit_Y] = _yExit;
    g_InteriorData[_Interiorid][i_InteriorExit_Z] = _zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    g_InteriorData[_Interiorid][i_InteriorIntid] = _eInteriorid;
    g_InteriorData[_Interiorid][i_InteriorIntid_OUT] = _xInteriorid;
    g_InteriorData[_Interiorid][i_InteriorVwid] = _eVirtualWorldid;
    g_InteriorData[_Interiorid][i_InteriorVwid_OUT] = _xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    if(Interior != INTERIOR_CUSTOM)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Assigned interior map id to interior id : %i", Interior);
        #endif

        if(Interior == INTERIOR_MARKET_247_1)
        {
            g_InteriorData[_Interiorid][i_InteriorIntid] = 17;
            g_InteriorData[_Interiorid][i_InteriorVwid] = 17;

            g_InteriorData[_Interiorid][i_InteriorExit_X] = -25.884498;
            g_InteriorData[_Interiorid][i_InteriorExit_Y] = -185.868988;
            g_InteriorData[_Interiorid][i_InteriorExit_Z] = 1003.546875;
        }
    }

    if(Labels == true)
    {
        new _EntranceLabelString[300];
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Empty string declared.");
        #endif
        format(_EntranceLabelString,sizeof(_EntranceLabelString),"{ffffff}[ %s ]\n{ffffff}Enter here!",_InteriorName);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Formatted the 3D label string successfully.");
        #endif
        Create3DLabelAndPickup(_EntranceLabelString, _xEntrance,_yEntrance,_zEntrance, _xVirtualWorldid, 19133, 3.0);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on entrance.");
        #endif
        Create3DLabelAndPickup("Exit here!", _xExit,_yExit,_zExit, _eVirtualWorldid, 19133, 3.0);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Streamer :: Created 3D label and pickup on exit.");
        #endif
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif

    if(funcidx("OnCustomInteriorCreated") != -1)
    {
        CallLocalFunction("OnCustomInteriorCreated", "i", _Interiorid);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - OnCustomInteriorCreated(customintid) called.");
    #endif

    return detutils_interiors_TRUE;
}

#if defined detutils_complete_error_boom

stock CreateCustomInterior(
        const _InteriorName[], 
        Float:_xEntrance, 
        Float:_yEntrance, 
        Float:_zEntrance, 
        Float:_xExit, 
        Float:_yExit, 
        Float:_zExit, 
        _eInteriorid, 
        _xInteriorid, 
        _eVirtualWorldid, 
        _xVirtualWorldid)
{
    if(_Interiorid == MAX_INTERIORS)
    {
        #if defined detutils_debug
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            if(i != INVALID_PLAYER_ID)
            {
                d_SendWarningMessage(i, "Maximum number of created interiors reached.");
            }
        }
        #endif
        return 0;
    }
    printf("[samp-detutils]: (debug) - Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            _InteriorName,
            Float:_xEntrance, 
            Float:_yEntrance, 
            Float:_zEntrance);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    _Interiorid++;

    strmid(g_InteriorData[_Interiorid][i_InteriorName], 
            _InteriorName, 
            0, 
            strlen(_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("[samp-detutils]: (debug) - Interior '%s' has an id %d.",_InteriorName,_Interiorid);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif
    g_InteriorData[_Interiorid][i_InteriorEntrance_X] = _xEntrance;
    g_InteriorData[_Interiorid][i_InteriorEntrance_Y] = _yEntrance;
    g_InteriorData[_Interiorid][i_InteriorEntrance_Z] = _zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    g_InteriorData[_Interiorid][i_InteriorExit_X] = _xExit;
    g_InteriorData[_Interiorid][i_InteriorExit_Y] = _yExit;
    g_InteriorData[_Interiorid][i_InteriorExit_Z] = _zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    g_InteriorData[_Interiorid][i_InteriorIntid] = _eInteriorid;
    g_InteriorData[_Interiorid][i_InteriorIntid_OUT] = _xInteriorid;
    g_InteriorData[_Interiorid][i_InteriorVwid] = _eVirtualWorldid;
    g_InteriorData[_Interiorid][i_InteriorVwid_OUT] = _xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Internal interior data assigned.");
    #endif

    if(funcidx("OnCustomInteriorCreated") != -1)
    {
        CallLocalFunction("OnCustomInteriorCreated", "i", _Interiorid);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - OnCustomInteriorCreated(customintid) called.");
    #endif

    return detutils_interiors_TRUE;
}

#endif

stock bool:IsPlayerInCustomInterior(playerid)
{
    if(_PlayersInterior[ playerid ] == -1) return false;
    else return true;
}

stock ClearPlayerInteriorData(playerid)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData called successfully.");
    #endif
    _PlayersInterior[playerid] = -1;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ClearPlayerInteriorData action successfully performed.");
    #endif
    return detutils_interiors_TRUE;
}

stock GetLastInteriorIDUsed()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - GetLastInteriorIDUsed successfully called.");
    #endif
    return _Interiorid;
}

stock SetInteriorEntranceCustomAngles(
        const _CustomInteriorid,
        Float:_aAngle,
        Float:_bAngle)
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set interior (intid : %i) angles to %f-%f.", 
        _CustomInteriorid, _aAngle, _bAngle);
    #endif
    g_InteriorData[_CustomInteriorid][i_InteriorEntrance_A] = _aAngle;
    g_InteriorData[_CustomInteriorid][i_InteriorExit_A] = _bAngle;
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

// Bug fix:

public OnPlayerSpawn(playerid)
{
    TogglePlayerControllable(playerid, 1);
    if(funcidx("a_int_Onplayerspawn") != -1)
    {
        CallLocalFunction("a_int_Onplayerspawn", "i", playerid);
    }
    return detutils_interiors_TRUE;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn a_int_Onplayerspawn

forward a_int_Onplayerspawn(playerid);

//////////////////////////////////////////////////

//#if !defined DETUTILS_COMPATIBILITY_MODE

forward OnInteriorActionPerformed(playerid, interiorid, actionid);

stock GetInteriorName(_InteriorId)
{
    new InteriorName[256];
    format(InteriorName, sizeof InteriorName, "%s", g_InteriorData[_InteriorId][i_InteriorName]);
    return InteriorName;
}

stock GetInteriorIDByName(const _InteriorName[])
{
    new __InteriorName[256];
    for(new _IntCount = 0; 
        _IntCount < MAX_INTERIORS; 
        _IntCount++)
    {
        format(__InteriorName, 256, "%s", g_InteriorData[_IntCount][i_InteriorName]);
        if(!strcmp(__InteriorName, _InteriorName))
        {
            return _IntCount;
        }
    }
    return 0;
}

#if defined detutils_complete_error_boom

#define public%3OnInteriorActionPerformed%2(%0,%1) \
    forward int_%0(%1); \
    public int_%0(%1)


#endif

#if defined detutils_complete_error_boom

#define INTERIOR__%0(%1) \
    forward int_%0(%1,_Actionid); \
    public int_%0(%1,_Actionid)

#endif

stock SetPlayerCustomInterior(_p_Playerid, p_Interiorid)
{
    if(p_Interiorid < -1)
        return detutils_interiors_FALSE;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Successfully set players (id : %i) interior to %i.", _p_Playerid, p_Interiorid);
    #endif

    _PlayersInterior[_p_Playerid] = p_Interiorid;
    return detutils_interiors_TRUE;
}

#if defined detutils_complete_error_boom

#define IsInteriorActionPerformed(%0) \
    (_Actionid == %0) >>> data * plus / Check;

#endif

static void:AnnounceLibraryLoaded_int()
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
    _CreateAnncTextDraws();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_interiors.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_int();

    if(funcidx("a_int_OnFilterScriptInit") != -1)
    {
        CallLocalFunction("a_int_OnFilterScriptInit", "");
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