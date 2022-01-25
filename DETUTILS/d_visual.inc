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

#tryinclude <streamer>

#if !defined _streamer_included

    #error [samp-detutils]: (error) - Plugin 'streamer.dll/so' required to run 'd_visual'.

#endif

#if !defined _d_cmd_processor_included

    #error [samp-detutils]: (error) - Include 'd_commands' before using 'd_visual' include.

#endif

#if !defined d_fmargs_included

    #error [samp-detutils]: (error) -  Include 'd_fmargs' before using 'd_visual' include.

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
#define SCREEN_UPDATE_PTEXTDRAW_SHOW 0
#define SCREEN_UPDATE_PTEXTDRAW_HIDE 1
#define SCREEN_UPDATE_GTEXTDRAW_SHOW 2
#define SCREEN_UPDATE_GTEXTDRAW_HIDE 3
#define SCREEN_UPDATE_GAMETEXT_SHOW 4
#define SCREEN_UPDATE_GAMETEXT_HIDE 5

forward OnPlayerScreenUpdate(playerid, screenupdate);

// player td update

stock PlayerText:d_v_PlayerTextDrawShow(playerid, PlayerText:text)
{
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_PTEXTDRAW_SHOW);
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
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_PTEXTDRAW_HIDE);
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
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_GTEXTDRAW_SHOW);
    }
    return TextDrawShowForPlayer(playerid, text);
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
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GTEXTDRAW_SHOW);
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
        CallLocalFunction("OnPlayerScreenUpdate", "ii", playerid, SCREEN_UPDATE_GTEXTDRAW_HIDE);
    }
    return TextDrawHideForPlayer(playerid, text);
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
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, SCREEN_UPDATE_GTEXTDRAW_HIDE);
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

forward OnPlayerPickUpGun(playerid);
forward OnPlayerThrowGun(playerid);
forward OnPlayerDestroyGun(playerid);

#if defined detutils_complete_error_boom

// dummy func
if(funcidx("OnPlayerPickUpGun") != -1) CallLocalFunction("OnPlayerPickUpGun", "i", playerid);

#endif

#define IsValidWeapon(%0) (%0>=1 && %0<=18 || %0>=21 && %0<=46)

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
    if(IsValidWeapon(weaponid))
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

stock CreateDroppedGun( p_WeapID, p_WeapAmmo, Float:__Weapon_pos_x, Float:__Weapon_pos_y, Float:__Weapon_pos_z ) 
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
            g_WeaponData[ p_WeapIndex ][ w_ObjectId ] = CreateDynamicObject( 
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
            //#if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, p_WeapID );
            //#endif
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
            GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
            g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateDynamicObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, DETUTILS_TEXT_THROW_GUN, 
                g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerThrowGun") != -1) CallLocalFunction("OnPlayerThrowGun", "i", playerid);
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
    DestroyDynamicObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, DETUTILS_TEXT_GUN_DESTROY, 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyGun") != -1) CallLocalFunction("OnPlayerDestroyGun", "i", playerid);
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
    DestroyDynamicObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
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
    if(funcidx("OnPlayerPickUpGun") != -1) CallLocalFunction("OnPlayerPickUpGun", "i", playerid);
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
            //#if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, p_WeapID );
            //#endif
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
            g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
            GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
            g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateDynamicObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerThrowGun") != -1) CallLocalFunction("OnPlayerThrowGun", "i", playerid);
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
    DestroyDynamicObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You destroyed {ffffff}%s"COLOUR_GREY".", 
        g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] = 0.0;
    g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = -1;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = 0;
    g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyGun") != -1) CallLocalFunction("OnPlayerDestroyGun", "i", playerid);
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
    DestroyDynamicObject( g_WeaponData[ p_WeapIdx ][ w_ObjectId ] );
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
    if(funcidx("OnPlayerPickUpGun") != -1) CallLocalFunction("OnPlayerPickUpGun", "i", playerid);
    return true;
}

#endif

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

public OnPlayerDeath(playerid)
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
                //#if defined RemovePlayerWeapon
                RemovePlayerWeapon( playerid, p_WeapID );
                //#endif
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] = p_WeapID;
                g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 1 ] = p_WeapAmmo;
                GetPlayerPos( playerid, g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ] );
                g_WeaponData[ p_WeapIdx ][ w_ObjectId ] = CreateDynamicObject( g_WeaponInformation[ p_WeapID ][ wModel ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 0 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 1 ], 
                    g_WeaponData[ p_WeapIdx ][ w_ObjectPos ][ 2 ]-1, 93.7, 120.0, 120.0 );
                __WeaponTimer_var[ playerid ] = 30;
                SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                    g_WeaponInformation[ g_WeaponData[ p_WeapIdx ][ w_WeaponData ][ 0 ] ][ wName ] );
                //if(funcidx("OnPlayerThrowGun") != -1) CallLocalFunction("OnPlayerThrowGun", "i", playerid);
                // We don't want to call OnPlayerThrowGun at player's death since it would get called max 13 times!!
            }
        }
    }
    if(funcidx("d_visual_Onpde") != -1)
    {
        CallLocalFunction("d_visual_Onpde", "i", playerid);
    }
    return 1;
}

#if defined _ALS_OnPlayerDeath
    #undef OnPlayerDeath
#else
    #define _ALS_OnPlayerDeath
#endif

#define OnPlayerDeath d_visual_Onpde

forward d_visual_Onpde(playerid);

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

static void:AnnounceLibraryLoaded_visual()
{
    LoadDETUtilsScript(DETUTILS_SCRIPT_VISUAL);
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_visual();
    d_visual_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main d_visual_main

#else

#undef detutils_visual_TRUE

#define detutils_visual_TRUE 1

public OnFilterScriptInit()
{
    SetTimer("__Weapon_timer", 1000, true);
    AnnounceLibraryLoaded_visual();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_visual.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("d_visual_Onfsutilst") != -1)
    {
        CallLocalFunction("d_visual_Onfsutilst", "i", playerid);
    }
    return detutils_visual_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit d_visual_Onfsutilst

forward d_visual_Onfsutilst();

#endif

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