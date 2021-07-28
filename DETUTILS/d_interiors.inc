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

enum e__INTERIOR_DATA
{
    e__INTERIOR_NAME[32],

    Float:e__INTENTRANCE_X,
    Float:e__INTENTRANCE_Y,
    Float:e__INTENTRANCE_Z,
    Float:e__INTENTRANCE_A,

    Float:e__INTEXIT_X,
    Float:e__INTEXIT_Y,
    Float:e__INTEXIT_Z,
    Float:e__INTEXIT_A,

    e__INTERIOR_INTID,
    e__INTERIOR_INTID_OUT,
    e__INTERIOR_VWID,
    e__INTERIOR_VWID_OUT,

    e__INTERIOR_PICKUP,
    e__INTERIOR_PICKUPID,
    e__INTERIOR_3DLABEL,
    e__INTERIOR_3DLABELID
};

forward OnCustomInteriorCreated(customintid);

new _PlayersInterior[MAX_PLAYERS];

new _InteriorData[MAX_INTERIORS][e__INTERIOR_DATA];

new _Interiorid;

new _EntranceTitleShown[MAX_PLAYERS];

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

static _HideAnnouncement[MAX_PLAYERS];

static _Announcement(playerid, const _Message[])
{
    new c_Message[300];

    KillTimer(_HideAnnouncement[playerid]);

    format(c_Message,300,"%s",_Message);

    TextDrawShowForPlayer(playerid, _AnnouncementUsebox);

    PlayerTextDrawSetString( playerid, _AnnouncementString[ playerid ], c_Message );

    PlayerTextDrawShow(playerid,_AnnouncementString[ playerid ]);

    _HideAnnouncement[playerid] = _SetTimer("hideannouncement", 4000, false, "i", playerid);
    return detutils_interiors_TRUE;
}

util function:hideannouncement(playerid)
{
    TextDrawHideForPlayer(playerid, _AnnouncementUsebox);
    PlayerTextDrawHide(playerid, _AnnouncementString[playerid]);
    KillTimer(_HideAnnouncement[playerid]);
    return detutils_interiors_TRUE;
}

static _CreateAnncTextDraws()
{
    _AnnouncementUsebox = TextDrawCreate(366.444427, 363.882232, "usebox");
    TextDrawLetterSize(_AnnouncementUsebox, 0.000000, 1.840366);
    TextDrawTextSize(_AnnouncementUsebox, 267.333312, 0.000000);
    TextDrawAlignment(_AnnouncementUsebox, 1);
    TextDrawColor(_AnnouncementUsebox, 0);
    TextDrawUseBox(_AnnouncementUsebox, true);

    TextDrawBoxColor(_AnnouncementUsebox, 102);
    TextDrawSetShadow(_AnnouncementUsebox, 0);
    TextDrawSetOutline(_AnnouncementUsebox, 0);
    TextDrawFont(_AnnouncementUsebox, 0);
    return detutils_interiors_TRUE;
}

#define STRING "string"

static _CreatePlayerTextDraws(playerid)
{
    _AnnouncementString[playerid] = CreatePlayerTextDraw(playerid, 315.111145, 364.373321, "string");
    PlayerTextDrawLetterSize(playerid, _AnnouncementString[playerid], 0.201111, 1.346133);

    PlayerTextDrawAlignment(playerid, _AnnouncementString[playerid], 2);
    PlayerTextDrawColor(playerid, _AnnouncementString[playerid], -1);
    PlayerTextDrawSetShadow(playerid, _AnnouncementString[playerid], 0);

    PlayerTextDrawSetOutline(playerid, _AnnouncementString[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, _AnnouncementString[playerid], 51);
    PlayerTextDrawFont(playerid, _AnnouncementString[playerid], 2);
    PlayerTextDrawSetProportional(playerid, _AnnouncementString[playerid], 1);
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
    TextDrawHideForPlayer(playerid, _AnnouncementUsebox);
    PlayerTextDrawHide(playerid, _AnnouncementString[playerid]);
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
        if( IsPlayerInRangeOfPoint( playerid, 1.5, _InteriorData[ i ][e__INTENTRANCE_X], \
        _InteriorData[ i ][e__INTENTRANCE_Y], _InteriorData[ i ][e__INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == _InteriorData[ i ][e__INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            _InteriorActionid = 0;
            format(_InteriorFunctionName,sizeof(_InteriorFunctionName),
                "int_%s",_InteriorData[ i ][e__INTERIOR_NAME]);

            if(funcidx(_InteriorFunctionName) != -1) CallLocalFunction(_InteriorFunctionName,
                                                                "ii",playerid,_InteriorActionid);

            SetPlayerInterior( playerid, _InteriorData[ i ][e__INTERIOR_INTID] );
            SetPlayerVirtualWorld( playerid, _InteriorData[ i ][e__INTERIOR_VWID] );
            
            SetPlayerPos( playerid, _InteriorData[ i ][e__INTEXIT_X], _InteriorData[ i ][e__INTEXIT_Y], \
            _InteriorData[ i ][e__INTEXIT_Z] );
            
            SetPlayerFacingAngle( playerid, _InteriorData[ i ][e__INTEXIT_A] );
            SetCameraBehindPlayer( playerid );
            
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player entered the interior with id : %i.", i);
            #endif

            TogglePlayerControllable(playerid,false);

            SetPlayerTime( playerid, 12, 0 );
            _InteriorLoadingTime(playerid);
            
            _PlayersInterior[ playerid ] = i;
            
        }
        else if( IsPlayerInRangeOfPoint( playerid, 1.5, _InteriorData[ i ][e__INTEXIT_X], \
        _InteriorData[ i ][e__INTEXIT_Y], _InteriorData[ i ][e__INTEXIT_Z]) && \
        GetPlayerVirtualWorld( playerid ) == _InteriorData[ i ][e__INTERIOR_VWID])
        {
            SetPlayerVirtualWorld( playerid, _InteriorData[ i ][e__INTERIOR_VWID_OUT] );
            SetPlayerInterior( playerid, _InteriorData[ i ][e__INTERIOR_INTID_OUT] );
            
            SetPlayerPos( playerid, _InteriorData[ i ][e__INTENTRANCE_X], _InteriorData[ i ][e__INTENTRANCE_Y], \
            _InteriorData[ i ][e__INTENTRANCE_Z] );
            
            SetPlayerFacingAngle( playerid, _InteriorData[ i ][e__INTENTRANCE_A] );
            SetCameraBehindPlayer( playerid );

            TogglePlayerControllable(playerid,false);

            _InteriorLoadingTime(playerid);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - nearintcallback :: Player exited the interior with id : %i.", i);
            #endif

            _InteriorActionid = 1;
            format(_InteriorFunctionName,sizeof(_InteriorFunctionName),
                "int_%s",_InteriorData[ i ][e__INTERIOR_NAME]);

            if(funcidx(_InteriorFunctionName) != -1) CallLocalFunction(_InteriorFunctionName,"ii",playerid,_InteriorActionid);

            _PlayersInterior[ playerid ] = -1;
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
        if( IsPlayerInRangeOfPoint( playerid, 1.5, _InteriorData[ i ][e__INTENTRANCE_X], \
        _InteriorData[ i ][e__INTENTRANCE_Y], _InteriorData[ i ][e__INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == _InteriorData[ i ][e__INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ) && _EntranceTitleShown[playerid] != 1)
        {
            new _InteriorName[100];
            format(_InteriorName,sizeof(_InteriorName),"Property: %s",_InteriorData[ i ][ e__INTERIOR_NAME ]);
            
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

stock CreateCustomInteriorEx(
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
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
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

    strmid(_InteriorData[_Interiorid][e__INTERIOR_NAME], 
            _InteriorName, 
            0, 
            strlen(_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",_InteriorName,_Interiorid);

    _InteriorData[_Interiorid][e__INTENTRANCE_X] = _xEntrance;
    _InteriorData[_Interiorid][e__INTENTRANCE_Y] = _yEntrance;
    _InteriorData[_Interiorid][e__INTENTRANCE_Z] = _zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    _InteriorData[_Interiorid][e__INTEXIT_X] = _xExit;
    _InteriorData[_Interiorid][e__INTEXIT_Y] = _yExit;
    _InteriorData[_Interiorid][e__INTEXIT_Z] = _zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    _InteriorData[_Interiorid][e__INTERIOR_INTID] = _eInteriorid;
    _InteriorData[_Interiorid][e__INTERIOR_INTID_OUT] = _xInteriorid;
    _InteriorData[_Interiorid][e__INTERIOR_VWID] = _eVirtualWorldid;
    _InteriorData[_Interiorid][e__INTERIOR_VWID_OUT] = _xVirtualWorldid;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.");
    #endif

    new _EntranceLabelString[300];
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Empty string declared.");
    #endif
    format(_EntranceLabelString,sizeof(_EntranceLabelString),"{ffffff}[ %s ]\n"col_white"Enter here!",_InteriorName);
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
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            _InteriorName,
            Float:_xEntrance, 
            Float:_yEntrance, 
            Float:_zEntrance);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior created.");
    #endif

    _Interiorid++;

    strmid(_InteriorData[_Interiorid][e__INTERIOR_NAME], 
            _InteriorName, 
            0, 
            strlen(_InteriorName), 
            255);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Saved interior name.");
    #endif

    printf("Interior '%s' has an id %d.",_InteriorName,_Interiorid);
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Interior id assigned.");
    #endif
    _InteriorData[_Interiorid][e__INTENTRANCE_X] = _xEntrance;
    _InteriorData[_Interiorid][e__INTENTRANCE_Y] = _yEntrance;
    _InteriorData[_Interiorid][e__INTENTRANCE_Z] = _zEntrance;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Entrance coordinates assigned to interior data.");
    #endif

    _InteriorData[_Interiorid][e__INTEXIT_X] = _xExit;
    _InteriorData[_Interiorid][e__INTEXIT_Y] = _yExit;
    _InteriorData[_Interiorid][e__INTEXIT_Z] = _zExit;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - Exit coordinates assigned to interior data.");
    #endif

    _InteriorData[_Interiorid][e__INTERIOR_INTID] = _eInteriorid;
    _InteriorData[_Interiorid][e__INTERIOR_INTID_OUT] = _xInteriorid;
    _InteriorData[_Interiorid][e__INTERIOR_VWID] = _eVirtualWorldid;
    _InteriorData[_Interiorid][e__INTERIOR_VWID_OUT] = _xVirtualWorldid;

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

stock GetLastInterioridUsed()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - GetLastInterioridUsed successfully called.");
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
    _InteriorData[_CustomInteriorid][e__INTENTRANCE_A] = _aAngle;
    _InteriorData[_CustomInteriorid][e__INTEXIT_A] = _bAngle;
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

#if !defined DETUTILS_COMPATIBILITY_MODE

#define interior%0(%1) \
    forward int_%0(%1,_Actionid); \
    public int_%0(%1,_Actionid)

#else

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

#define IsInteriorActionPerformed(%0) \
    (_Actionid == %0)

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