/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides in-game visible
 *   stuff.
 *
 *
 */

#if defined detutils_complete_error_boom

#if !defined _d_cmd_processor_included

    #error [samp-detutils]: (error) - Include 'd_commands' before using 'd_visual' include.

#endif

#endif

#if !defined d_fmargs_included

    #error [samp-detutils]: (error) - Include 'd_fmargs' before using 'd_visual' include.

#endif

#if defined DEV_MODE

#include <a_samp>

#endif

#if defined d_visual_included
    #endinput
#endif

#define d_visual_included

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

//-- Players --//

#define INVALID_SCREEN_UPDATE_ID -1
#define SCREEN_UPDATE_PLAYER_TD_SHOW 0
#define SCREEN_UPDATE_PLAYER_TD_HIDE 1
#define SCREEN_UPDATE_GLOBAL_TD_SHOW 2
#define SCREEN_UPDATE_GLOBAL_TD_HIDE 3
#define SCREEN_UPDATE_GAMETEXT_SHOW 4
#define SCREEN_UPDATE_GAMETEXT_HIDE 5
#define SCREEN_UPDATE_GTD_CHANGE_POS 6
#define SCREEN_UPDATE_PTD_CHANGE_POS 7

forward OnPlayerScreenUpdate(playerid, updatetype);

#if defined DETUTILS_NO_FMARGS

enum enum_TextDrawData
{
    Valid,
    Float:Pos[2],
    Float:OldPos[2]
}

new g_TextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];
new g_PlayerTextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];

#endif

// player td update

stock PlayerText:d_v_PlayerTextDrawShow(playerid, PlayerText:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_PLAYER_TD_SHOW);
    }
    return PlayerTextDrawShow(playerid, text);
}

#if defined _ALS_PlayerTextDrawShow
    #undef PlayerTextDrawShow
#else
    #define _ALS_PlayerTextDrawShow
#endif

#define PlayerTextDrawShow d_v_PlayerTextDrawShow

stock PlayerText:d_v_PlayerTextDrawHide(playerid, PlayerText:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_PLAYER_TD_HIDE);
    }
    return PlayerTextDrawHide(playerid, text);
}

#if defined _ALS_PlayerTextDrawHide
    #undef PlayerTextDrawHide
#else
    #define _ALS_PlayerTextDrawHide
#endif

#define PlayerTextDrawHide d_v_PlayerTextDrawHide

// global td update

stock Text:d_v_TextDrawShowForPlayer(playerid, Text:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_GLOBAL_TD_SHOW);
    }
    return Text:TextDrawShowForPlayer(playerid, text);
}

#if defined _ALS_TextDrawShowForPlayer
    #undef TextDrawShowForPlayer
#else
    #define _ALS_TextDrawShowForPlayer
#endif

#define TextDrawShowForPlayer d_v_TextDrawShowForPlayer

stock Text:d_v_TextDrawShowForAll(Text:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        for(new i; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i))
        {
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GLOBAL_TD_SHOW);
        }
    }
    return TextDrawShowForAll(text);
}

#if defined _ALS_TextDrawShowForAll
    #undef TextDrawShowForAll
#else
    #define _ALS_TextDrawShowForAll
#endif

#define TextDrawShowForAll d_v_TextDrawShowForAll

stock Text:d_v_TextDrawHideForPlayer(playerid, Text:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_GLOBAL_TD_HIDE);
    }
    return Text:TextDrawHideForPlayer(playerid, text);
}

#if defined _ALS_TextDrawHideForPlayer
    #undef TextDrawHideForPlayer
#else
    #define _ALS_TextDrawHideForPlayer
#endif

#define TextDrawHideForPlayer d_v_TextDrawHideForPlayer

stock Text:d_v_TextDrawHideForAll(Text:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        for(new i; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i))
        {
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GLOBAL_TD_HIDE);
        }
    }
    return TextDrawHideForAll(text);
}

#if defined _ALS_TextDrawHideForAll
    #undef TextDrawHideForAll
#else
    #define _ALS_TextDrawHideForAll
#endif

#define TextDrawHideForAll d_v_TextDrawHideForAll

// game texts

#if defined DETUTILS_NO_FMARGS

stock d_v_GameTextForPlayer(playerid, const string[], time, style)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_GAMETEXT_SHOW);
        SetTimerEx("OnPlayerScreenUpdate", time, false, "ii", playerid, SCREEN_UPDATE_GAMETEXT_HIDE);
    }
    return GameTextForPlayer(playerid, string, time, style);
}

#if defined _ALS_GameTextForPlayer
    #undef GameTextForPlayer
#else
    #define _ALS_GameTextForPlayer
#endif

#define GameTextForPlayer d_v_GameTextForPlayer

stock d_v_GameTextForAll(const string[], time, style)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        for(new i; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i))
        {
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GAMETEXT_SHOW);
            SetTimerEx("OnPlayerScreenUpdate", time, false, "ii", i, SCREEN_UPDATE_GAMETEXT_HIDE);
        }
    }
    return GameTextForAll(string, time, style);
}

#if defined _ALS_GameTextForAll
    #undef GameTextForAll
#else
    #define _ALS_GameTextForAll
#endif

#define GameTextForAll d_v_GameTextForAll

stock Text:d_v_TextDrawCreate(Float:x, Float:y, text[])
{
    new Text:textid = TextDrawCreate
        (
            x,
            y,
            text
        )
    ;
    g_TextDrawData[textid][Pos][0] = x;
    g_TextDrawData[textid][Pos][1] = y;
    if(g_TextDrawData[textid][Valid] == 1 &&
    g_TextDrawData[textid][Pos][0] != g_TextDrawData[textid][OldPos][0] || g_TextDrawData[textid][Pos][1] != g_TextDrawData[textid][OldPos][1])
    {
        if(funcidx("OnPlayerScreenUpdate") != -1)
        {
            for(new i; i < MAX_PLAYERS; i++)
            {
                CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GTD_CHANGE_POS);
            }
        }
    }
    g_TextDrawData[textid][OldPos][0] = x;
    g_TextDrawData[textid][OldPos][1] = y;
    g_TextDrawData[textid][Valid] = 1;
    return textid;
}

#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif

#define TextDrawCreate d_v_TextDrawCreate

stock PlayerText:d_v_CreatePlayerTextDraw(playerid, Float:x, Float:y, text[])
{
    new PlayerText:textid = CreatePlayerTextDraw
        (
            x,
            y,
            text
        )
    ;
    g_PlayerTextDrawData[textid][Pos][0] = x;
    g_PlayerTextDrawData[textid][Pos][1] = y;
    if(g_PlayerTextDrawData[textid][Valid] == 1 &&
    g_PlayerTextDrawData[textid][Pos][0] != g_PlayerTextDrawData[textid][OldPos][0] || g_PlayerTextDrawData[textid][Pos][1] != g_PlayerTextDrawData[textid][OldPos][1])
    {
        if(funcidx("OnPlayerScreenUpdate") != -1)
        {
            CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_PTD_CHANGE_POS);
        }
    }
    g_PlayerTextDrawData[textid][OldPos][0] = x;
    g_PlayerTextDrawData[textid][OldPos][1] = y;
    g_PlayerTextDrawData[textid][Valid] = 1;
    return textid;
}

#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
#else
    #define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw d_v_CreatePlayerTextDraw

#endif

#if defined detutils_complete_error_boom

#if !defined fmargs_GameTextForPlayer && !defined fmargs_GameTextForAll

stock
    fmargs_GameTextForPlayer
(
    i,
    
    const _StringArgs[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
        
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            
            end > start;
            
            end -= 4
        )
        {
            #emit LREF.pri end
            
            #emit PUSH.pri
        }
        #emit PUSH.S _StringArgs
        
        #emit PUSH.C 144
        
        #emit PUSH.C _unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForPlayer
        (
            i,
            
            _unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        GameTextForPlayer
        (
            i,
            
            _StringArgs,
            
            duration,
            
            style
        )
    ;
}

stock
    fmargs_GameTextForAll
(
    const _StringArgs[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
        
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            
            end > start;
            
            end -= 4
        )
        {
            #emit LREF.pri end
            
            #emit PUSH.pri
        }
        #emit PUSH.S _StringArgs
        
        #emit PUSH.C 144
        
        #emit PUSH.C _unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForAll
        (
            _unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        GameTextForAll
        (
            _StringArgs,
            
            duration,
            
            style
        )
    ;
}

#endif
// damn
#endif

// other code for players module

forward OnPlayerScoreSniperHeadshot(playerid, killedid);

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    if(bodypart == 9 && weaponid == 34)
    {
        SetPlayerHealth(damagedid, 0);
        SetPlayerArmour(damagedid, 0);
        if(funcidx("OnPlayerScoreSniperHeadshot") != -1)
            CallLocalFunction("OnPlayerScoreSniperHeadshot", "ii", playerid, damagedid);
    }
    if(funcidx("d_visual_Onpgd") != -1)
    {
        CallLocalFunction("d_visual_Onpgd", "");
    }
    return 1;
}

#if defined _ALS_OnPlayerGiveDamage
    #undef OnPlayerGiveDamage
#else
    #define _ALS_OnPlayerGiveDamage
#endif

#define OnPlayerGiveDamage d_visual_Onpgd

forward d_visual_Onpgd();

#define ReturnPlayerName _ReturnPlayerName

#if defined DETUTILS_OPENMP_COMPAT

#define Message_SendInRange SendMessageInRange

#endif

stock SendMessageInRange(Float:radius, playerid, const string[], colour)
{
    new Float:PozX, Float:PozY, Float:PozZ, i;
    GetPlayerPos( playerid, PozX, PozY, PozZ);
    for(i = 0; i < MAX_PLAYERS; i++)
    {
        if( 
            IsPlayerConnected( i ) && ( GetPlayerVirtualWorld( playerid ) == GetPlayerVirtualWorld( i ) ) 
        ) 
        {
            if( IsPlayerInRangeOfPoint( i, radius, PozX, PozY, PozZ ) ) 
            {
                SendClientMessage(i, colour, string); 
            } 
        } 
    }
    return true;
}

enum d_PlayerWeapInfo
{
    HoldingWeapon,
    Weapon[ 13 ],
    Ammo[ 13 ]
}

new d_PlayerWeaponInfo[MAX_PLAYERS][d_PlayerWeapInfo];

#if defined DETUTILS_OPENMP_COMPAT

#define Animation_PreloadLibrary PreloadAnimationLibrary

#endif

static void:PreloadAnimationLibrary(playerid, const animlib[])
{
    ApplyAnimation(playerid, animlib, "null", 0.0, 0, 0, 0, 0, 0, 1);
}

//-- Vehicles --//

stock KillVehicle(vehicleid)
{
    if(vehicleid == INVALID_VEHICLE_ID) return 0;
    else SetVehicleHealth(vehicleid, 0);
    return 1;
}

// Function I decided to make for d_visual.inc but ended up here
// as d_anticheat.inc's hook.
stock d_v_SetPlayerVehiclePos(playerid, Float:x, Float:y, Float:z)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    new seatid = GetPlayerVehicleSeat(playerid);
    if(seatid != 0) return 0;
    if(!IsPlayerInAnyVehicle(playerid)) return 0;
    SetVehiclePos(vehicleid, x, y, z);
    SetPlayerPos(playerid, x, y, z);
    PutPlayerInVehicle(playerid, vehicleid, 0);
    return 1;
}

//-- Weapons --//

forward OnPlayerPickUpDroppedWeapon(playerid);
forward OnPlayerDropWeapon(playerid);
forward OnPlayerDestroyDroppedWeapon(playerid);

#if defined detutils_complete_error_boom

// dummy func
if(funcidx("OnPlayerPickUpDroppedWeapon") != -1) CallLocalFunction("OnPlayerPickUpDroppedWeapon", "i", playerid);

#endif

#if defined DETUTILS_OPENMP_COMPAT

#define IsValidWeapon Weapon_IsValid

#endif

#define Weapon_IsValid(%0) (%0>=1 && %0<=18 || %0>=21 && %0<=46)

enum g_WeapInfoEnum{
    wName[24],
    wID,
    wSlot,
    wModel
}

new g_WeaponInformation[ 47 ][ g_WeapInfoEnum ] = {
    {"No gun", 0, 0, 0 },
    {"Brass Knuckles", 1, 0, 331 },
    {"Golf Club", 2, 1, 333 },
    {"Nightstick", 3, 1, 334 },
    {"Knife", 4, 1, 335 },
    {"Baseball Bat", 5, 1, 336 },
    {"Shovel", 6, 1, 337 },
    {"Pool Cue", 7, 1, 338 },
    {"Katana", 8, 1, 339 },
    {"Chainsaw", 9, 1, 341 },
    {"Double-ended Dildo", 10, 10, 321 },
    {"Dildo", 11, 10, 321 },
    {"Vibrator", 12, 10, 323 },
    {"Silver Vibrator", 13, 10, 324 },
    {"Flowers", 14, 10, 325 },
    {"Cane", 15, 10, 326 },
    {"Grenade", 16, 8, 342 },
    {"Tear Gas", 17, 8, 343 },
    {"Molotov Cocktail", 18, 8, 344 },
    {"No gun", 19, -1, 0 },
    {"No gun", 20, -1, 0 },
    {"No gun", 21, -1, 0 },
    {"Colt .45", 22, 2, 346 },
    {"Silenced Colt .45", 23, 2, 347 },
    {"Desert Eagle", 24, 2, 348 },
    {"Shotgun", 25, 3, 349 },
    {"Sawnoff Shotgun", 26, 3, 350 },
    {"Combat Shotgun", 27, 3, 351 },
    {"Micro SMG", 28, 4, 352 },
    {"MP5", 29, 4, 353 },
    {"AK47", 30, 5, 355 },
    {"M4", 31, 5, 356 },
    {"Tec-9", 32, 4, 372 },
    {"Country Rifle", 33, 6, 357 },
    {"Sniper Rifle", 34, 6, 358 },
    {"RPG", 35, 7, 359 },
    {"HS Rocket", 36, 7, 360 },
    {"Flamethrower", 37, 7, 361 },
    {"Minigun", 38, 7, 362 },
    {"Satchel Charge", 39, 8, 363 },
    {"Detonator", 40, 12, 364 },
    {"Spraycan", 41, 9, 365 },
    {"Fire Extinguisher", 42, 9, 366 },
    {"Camera", 43, 9, 367 },
    {"Night Vis Goggles", 44, 11, 368 },
    {"Thermal Goggles", 45, 11, 369 },
    {"Parachute", 46, 11, 371 }
};

stock d_vs_GivePlayerWeapon(playerid, weaponid, ammo)
{
    if(Weapon_IsValid(weaponid))
    {
        d_PlayerWeaponInfo[playerid][Weapon][g_WeaponInformation[weaponid][wSlot]] = weaponid;
        d_PlayerWeaponInfo[playerid][Ammo][ g_WeaponInformation[weaponid][wSlot] ] += ammo;
        GivePlayerWeapon( playerid, weaponid, ammo );
    }
    return 1;
}

#if defined _ALS_GivePlayerWeapon
    #undef GivePlayerWeapon
#else
    #define _ALS_GivePlayerWeapon
#endif

#define GivePlayerWeapon d_vs_GivePlayerWeapon

#if defined DETUTILS_OPENMP_COMPAT

#define Player_WeaponRemove RemovePlayerWeapon

#endif

stock RemovePlayerWeapon( playerid, weaponid ) 
{
    ResetPlayerWeapons( playerid );

    for( new i = 0; i < 13; i ++ ) 
    {
        if( d_PlayerWeaponInfo[ playerid ][Weapon][i] != weaponid ) 
        {
            GivePlayerWeapon( playerid, 
                d_PlayerWeaponInfo[ playerid ][Weapon][i], 
                d_PlayerWeaponInfo[ playerid ][ Ammo ][i] );
        }
        else 
        {
            d_PlayerWeaponInfo[ playerid ][ Weapon ][i] = 0;
            d_PlayerWeaponInfo[ playerid ][ Ammo ][ i ] = 0;
        }
    }
    return 1;
}

stock d_v_ResetPlayerWeapons(playerid)
{
    ResetPlayerWeapons(playerid);
    for(new i; i < 13; i ++)
    {
        d_PlayerWeaponInfo[ playerid ][ Weapon ][i] = 0;
        d_PlayerWeaponInfo[ playerid ][ Ammo ][ i ] = 0;
    }
    return 1;
}

#if defined _ALS_ResetPlayerWeapons
    #undef ResetPlayerWeapons
#else
    #define _ALS_ResetPlayerWeapons
#endif

#define ResetPlayerWeapons d_v_ResetPlayerWeapons

forward OnPlayerWeaponChange(playerid, oldweapon, newweapon);

public OnPlayerUpdate(playerid)
{
    new weap = GetPlayerWeapon(playerid);
    if(d_PlayerWeaponInfo[ playerid ][ HoldingWeapon ] != weap)
    {
        CallLocalFunction("OnPlayerWeaponChange", "iii", playerid, d_PlayerWeaponInfo[ playerid ][ HoldingWeapon ], weap);
    }
    if(funcidx("d_v_playerupdate") != -1)
    {
        CallLocalFunction("d_v_playerupdate", "i", playerid);
    }
    d_PlayerWeaponInfo[ playerid ][ HoldingWeapon ] = weap;
    return 1;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate d_v_playerupdate

forward d_v_playerupdate(playerid);

// - Commands - //

static stock __WeaponTimer_var[MAX_PLAYERS];

#if !defined MAX_DROPPED_GUNS

#define MAX_DROPPED_GUNS 2000

#endif
new _CreatedDroppedGuns;

enum __Weapon_data__Enum {
    Float:w_ObjectPos[ 3 ],
    w_ObjectId,
    w_WeaponData[ 2 ],
};
new g_WeaponData[ MAX_DROPPED_GUNS ][ __Weapon_data__Enum ];

#if defined DETUTILS_OPENMP_COMPAT

#define Weapon_Create CreateDroppedWeapon

#endif

stock CreateDroppedWeapon( p_WeapID, p_WeapAmmo, Float:__Weapon_pos_x, Float:__Weapon_pos_y, Float:__Weapon_pos_z ) 
{
    if(_CreatedDroppedGuns == MAX_DROPPED_GUNS)
    {
        #if defined detutils_debug
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            if(i != INVALID_PLAYER_ID)
            {
                d_SendWarningMessage(i, DETUTILS_TEXT_MAX_GUN_REACH);
            }
        }
        #endif
        return 0;
    }
    for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ ) 
    {
        if( g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] == 0.0 ) 
        {
            g_WeaponData[ p_WeapIndex ][ w_WeaponData ][ 0 ] = p_WeapID;
            g_WeaponData[ p_WeapIndex ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] = __Weapon_pos_x;
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ] = __Weapon_pos_y;
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] = __Weapon_pos_z;
            g_WeaponData[ p_WeapIndex ][ w_ObjectId ] = CreateObject( 
                g_WeaponInformation[ p_WeapID ][ wModel ], 
                g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ],
                 g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, random(360) );
            
            _CreatedDroppedGuns++;
            return 1;
        }
    }
    return 1;
}

#define SPECIAL_ACTION_DROP_WEAPON 26
#define SPECIAL_ACTION_DESTROY_WEAPON 27
#define SPECIAL_ACTION_PICKUP_WEAPON 28

stock d_v_SetPlayerSpecialAction(playerid, actionid)
{
    if(actionid == SPECIAL_ACTION_DROP_WEAPON)
    {
        if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
        
        #if defined detutils_debug
        if(__WeaponTimer_var[playerid] != 0) return d_SendWarningMessage(playerid, DETUTILS_TEXT_CMD_TIMER);
        #else
        if(__WeaponTimer_var[playerid] != 0) return 1;
        #endif

        new p_WeapID = GetPlayerWeapon( playerid );
        new p_WeapAmmo = GetPlayerAmmo( playerid );
        if( p_WeapID > 0 && p_WeapAmmo != 0 )
        {
            if( _g_Script == 0 )
            {
                new p_WeapIdx = -1;
                for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
                {
                    if( g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] == 0.0 )
                    {
                        p_WeapIdx = p_WeapIndex;
                        break;
                    }
                }
                if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_CANNOT_OPERATE);
                //#if defined Player_WeaponRemove
                Player_WeaponRemove( playerid, p_WeapID );
                //#endif
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
                GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
                g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
                __WeaponTimer_var[ playerid ] = 30;
                SendClientMessage( playerid, -1, DETUTILS_TEXT_THROW_GUN, 
                    g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
                if(funcidx("OnPlayerDropWeapon") != -1) CallLocalFunction("OnPlayerDropWeapon", "i", playerid);
            }
        }
    }
    if(actionid == SPECIAL_ACTION_DESTROY_WEAPON)
    {
        if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
        new p_WeapIdx = -1;
        for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
        {
            if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] , 
                g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
            {
                p_WeapIdx = p_WeapIndex;
                break;
            }
        }
        if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_NOGUN_NEARBY);
        DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
        SendClientMessage( playerid, -1, DETUTILS_TEXT_GUN_DESTROY, 
            g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
        if(funcidx("OnPlayerDestroyDroppedWeapon") != -1) CallLocalFunction("OnPlayerDestroyDroppedWeapon", "i", playerid);
    }
    if(actionid == SPECIAL_ACTION_PICKUP_WEAPON)
    {
        if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
        
        new p_WeapIdx = -1;
        for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
        {
            if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] ,
             g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
             g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
            {
                p_WeapIdx = p_WeapIndex;
                break;
            }
        }
        if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_NOGUN_NEARBY);
        DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
        SendClientMessage( playerid, -1, DETUTILS_TEXT_GUN_PICK, 
            g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
        GivePlayerWeapon( playerid, g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ], 
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] );
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
        g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
        if(funcidx("OnPlayerPickUpDroppedWeapon") != -1) CallLocalFunction("OnPlayerPickUpDroppedWeapon", "i", playerid);
    }
    else return SetPlayerSpecialAction(playerid, actionid);
    return 1;
}

#if defined _ALS_SetPlayerSpecialAction
    #undef SetPlayerSpecialAction
#else
    #define _ALS_SetPlayerSpecialAction
#endif
#define SetPlayerSpecialAction d_v_SetPlayerSpecialAction

public OnPlayerSpawn(playerid)
{
    SetCameraBehindPlayer(playerid);
    if(funcidx("d_v_playerspawn") != -1)
    {
        CallLocalFunction("d_v_playerspawn", "i", playerid);
    }
    return 1;
}

#if defined _ALS_OnPlayerSpawn
    #undef OnPlayerSpawn
#else
    #define _ALS_OnPlayerSpawn
#endif

#define OnPlayerSpawn d_v_playerspawn

forward d_v_playerspawn(playerid);

forward __Weapon_timer();

public __Weapon_timer()
{
    for(new i; i < MAX_PLAYERS; i++)
        if( __WeaponTimer_var[ i ] > 0 ) __WeaponTimer_var[ i ]--;

    return 1;
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    SetTimer("__Weapon_timer", 1000, true);
    if(funcidx("d_visual_Ongminit") != -1)
    {
        CallLocalFunction("d_visual_Ongminit", "");
    }
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit d_visual_Ongminit

forward d_visual_Ongminit();

#endif

//////////////////////

public OnPlayerDeath(playerid, killerid, reason)
{
    for( new i = 0; i < 13; i ++ ) 
    {
        new p_WeapID = GetPlayerWeapon( playerid );
        new p_WeapAmmo = GetPlayerAmmo( playerid );
        if( p_WeapID > 0 && p_WeapAmmo != 0 )
        {
            if( _g_Script == 0 )
            {
                new p_WeapIdx = -1;
                for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
                {
                    if( g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] == 0.0 )
                    {
                        p_WeapIdx = p_WeapIndex;
                        break;
                    }
                }
                if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, 
                    ""COLOUR_GREY"Operation can't be completed at the moment." );
                //#if defined Player_WeaponRemove
                Player_WeaponRemove( playerid, p_WeapID );
                //#endif
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
                GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
                g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
                __WeaponTimer_var[ playerid ] = 30;
                SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                    g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
                //if(funcidx("OnPlayerDropWeapon") != -1) CallLocalFunction("OnPlayerDropWeapon", "i", playerid);
                // We don't want to call OnPlayerDropWeapon at player's death since it would get called max 13 times!!
            }
        }
    }
    if(funcidx("d_visual_Onpde") != -1)
    {
        CallLocalFunction("d_visual_Onpde", "iii", playerid, killerid, reason);
    }
    return 1;
}

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath d_visual_Onpde

forward d_visual_Onpde(playerid, killerid, reason);

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
    SetTimer("__Weapon_timer", 1000, true);
    LoadDETUtilsScript(DETUTILS_SCRIPT_VISUAL);
    #if defined detutils_debug
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("d_visual_detutilsinit") != -1)
    {
        CallLocalFunction("d_visual_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit d_visual_detutilsinit

forward d_visual_detutilsinit();

// for satisfication

stock KillPlayer(playerid)
{
    if(playerid == INVALID_PLAYER_ID) return 0;
    else SetPlayerHealth(playerid, 0);
    return 1;
}

stock KillAllPlayers()
{
    new id;
    for(id = 0; id < MAX_PLAYERS; id ++)
    {
        if(id != INVALID_PLAYER_ID) SetPlayerHealth(id, 0);
    }
    return 1;
}

#if defined detutils_complete_error_boom

#if !defined DETUTILS_COMPATIBILITY_MODE

command throwgun( playerid, params[] )
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    
    #if defined detutils_debug
    if(__WeaponTimer_var[playerid] != 0) return d_SendWarningMessage(playerid, DETUTILS_TEXT_CMD_TIMER);
    #else
    if(__WeaponTimer_var[playerid] != 0) return 1;
    #endif

    new p_WeapID = GetPlayerWeapon( playerid );
    new p_WeapAmmo = GetPlayerAmmo( playerid );
    if( p_WeapID > 0 && p_WeapAmmo != 0 )
    {
        if( _g_Script == 0 )
        {
            new p_WeapIdx = -1;
            for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
            {
                if( g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] == 0.0 )
                {
                    p_WeapIdx = p_WeapIndex;
                    break;
                }
            }
            if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_CANNOT_OPERATE);
            //#if defined Player_WeaponRemove
            Player_WeaponRemove( playerid, p_WeapID );
            //#endif
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
            GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
            g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, DETUTILS_TEXT_THROW_GUN, 
                g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerDropWeapon") != -1) CallLocalFunction("OnPlayerDropWeapon", "i", playerid);
        }
    }
    return true;
}

command destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new p_WeapIdx = -1;
    for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] , 
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
        {
            p_WeapIdx = p_WeapIndex;
            break;
        }
    }
    if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_NOGUN_NEARBY);
    DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, DETUTILS_TEXT_GUN_DESTROY, 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyDroppedWeapon") != -1) CallLocalFunction("OnPlayerDestroyDroppedWeapon", "i", playerid);
    return true;
}

command pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new p_WeapIdx = -1;
    for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] ,
         g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
         g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
        {
            p_WeapIdx = p_WeapIndex;
            break;
        }
    }
    if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, DETUTILS_TEXT_NOGUN_NEARBY);
    DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, DETUTILS_TEXT_GUN_PICK, 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ], 
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerPickUpDroppedWeapon") != -1) CallLocalFunction("OnPlayerPickUpDroppedWeapon", "i", playerid);
    return true;
}

#else

COMMAND__ throwgun( playerid, params[] )
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    
    #if defined detutils_debug
    if(__WeaponTimer_var[playerid] != 0) return d_SendWarningMessage(playerid, "The player tried to use the command but the timer was not over yet.");
    #else
    if(__WeaponTimer_var[playerid] != 0) return 1;
    #endif

    new p_WeapID = GetPlayerWeapon( playerid );
    new p_WeapAmmo = GetPlayerAmmo( playerid );
    if( p_WeapID > 0 && p_WeapAmmo != 0 )
    {
        if( _g_Script == 0 )
        {
            new p_WeapIdx = -1;
            for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
            {
                if( g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0 ] == 0.0 )
                {
                    p_WeapIdx = p_WeapIndex;
                    break;
                }
            }
            if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"Operation can't be completed at the moment." );
            //#if defined Player_WeaponRemove
            Player_WeaponRemove( playerid, p_WeapID );
            //#endif
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
            GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
            g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerDropWeapon") != -1) CallLocalFunction("OnPlayerDropWeapon", "i", playerid);
        }
    }
    return true;
}

COMMAND__ destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new p_WeapIdx = -1;
    for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] , 
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
            g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
        {
            p_WeapIdx = p_WeapIndex;
            break;
        }
    }
    if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You destroyed {ffffff}%s"COLOUR_GREY".", 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyDroppedWeapon") != -1) CallLocalFunction("OnPlayerDestroyDroppedWeapon", "i", playerid);
    return true;
}

COMMAND__ pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new p_WeapIdx = -1;
    for( new p_WeapIndex = 0; p_WeapIndex < MAX_DROPPED_GUNS; p_WeapIndex++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 0] ,
         g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 1 ], 
         g_WeaponData[ p_WeapIndex ][ w_ObjectPos ][ 2 ] ) )
        {
            p_WeapIdx = p_WeapIndex;
            break;
        }
    }
    if( p_WeapIdx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You picked up {ffffff}%s"COLOUR_GREY".", 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ], 
        g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerPickUpDroppedWeapon") != -1) CallLocalFunction("OnPlayerPickUpDroppedWeapon", "i", playerid);
    return true;
}

#endif
// asshole
#endif