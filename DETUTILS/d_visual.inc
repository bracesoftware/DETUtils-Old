/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this _GlobalFileName are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this _GlobalFileName except in compliance with 
    the License. You may obtain __weap_index copy of the License at 
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

new PlayerText:d_FadeTextDraw[MAX_PLAYERS];
new d_fade_count[MAX_PLAYERS];
new d_fade_timer[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    d_FadeTextDraw[ playerid ] = CreatePlayerTextDraw( playerid, -5.000, -2.000, "~n~");
    PlayerTextDrawFont(playerid, d_FadeTextDraw[ playerid ], 3);
    PlayerTextDrawUseBox(playerid, d_FadeTextDraw[ playerid ], 1);
    PlayerTextDrawLetterSize(playerid, d_FadeTextDraw[ playerid ], 0.500000, 50.300003);
    PlayerTextDrawBoxColor(playerid, d_FadeTextDraw[ playerid ], -1);
    PlayerTextDrawTextSize(playerid, d_FadeTextDraw[ playerid ], 655.000, 625.000);
    PlayerTextDrawColor(playerid, d_FadeTextDraw[ playerid ], -1);

    if(funcidx("d_visual_Onpc") != -1)
    {
        CallLocalFunction("d_visual_Onpc", "i", playerid);
    }
    return 1;
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect d_visual_Onpc

forward d_visual_Onpc(playerid);

forward d_TextDrawFading( playerid );
public d_TextDrawFading( playerid ) {

    d_fade_count[ playerid ]++;

    PlayerTextDrawHide( playerid, d_FadeTextDraw[ playerid ] );
    PlayerTextDrawShow( playerid, d_FadeTextDraw[ playerid ] );

    if( d_fade_count[ playerid ] == 1 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000000A );
    if( d_fade_count[ playerid ] == 2 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000010 );
    if( d_fade_count[ playerid ] == 3 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000001A );
    if( d_fade_count[ playerid ] == 4 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000020 );
    if( d_fade_count[ playerid ] == 5 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000002A );
    if( d_fade_count[ playerid ] == 6 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000030 );
    if( d_fade_count[ playerid ] == 7 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000003A );
    if( d_fade_count[ playerid ] == 8 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000040 );
    if( d_fade_count[ playerid ] == 9 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000004A );
    if( d_fade_count[ playerid ] == 10 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000050 );
    if( d_fade_count[ playerid ] == 11 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000005A );
    if( d_fade_count[ playerid ] == 12 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000060 );
    if( d_fade_count[ playerid ] == 13 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000006A );
    if( d_fade_count[ playerid ] == 14 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000070 );
    if( d_fade_count[ playerid ] == 15 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000007A );
    if( d_fade_count[ playerid ] == 16 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000080 );
    if( d_fade_count[ playerid ] == 17 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000008A );
    if( d_fade_count[ playerid ] == 18 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000090 );
    if( d_fade_count[ playerid ] == 19 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000009A );
    if( d_fade_count[ playerid ] == 20 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000A1 );
    if( d_fade_count[ playerid ] == 21 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000AA );
    if( d_fade_count[ playerid ] == 22 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000B1 );
    if( d_fade_count[ playerid ] == 23 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000BB );
    if( d_fade_count[ playerid ] == 24 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000C1 );
    if( d_fade_count[ playerid ] == 25 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000CC );
    if( d_fade_count[ playerid ] == 26 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000D1 );
    if( d_fade_count[ playerid ] == 27 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000DD );
    if( d_fade_count[ playerid ] == 28 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000E1 );
    if( d_fade_count[ playerid ] == 29 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000EE );
    if( d_fade_count[ playerid ] == 30 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000F1 );
    if( d_fade_count[ playerid ] == 31 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000FF );
    // Completely Black
    if( d_fade_count[ playerid ] == 32 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000F1 );
    if( d_fade_count[ playerid ] == 33 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000EE );
    if( d_fade_count[ playerid ] == 34 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000E1 );
    if( d_fade_count[ playerid ] == 35 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000DD );
    if( d_fade_count[ playerid ] == 36 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000D1 );
    if( d_fade_count[ playerid ] == 37 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000CC );
    if( d_fade_count[ playerid ] == 38 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000C1 );
    if( d_fade_count[ playerid ] == 39 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000BB );
    if( d_fade_count[ playerid ] == 40 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000B1 );
    if( d_fade_count[ playerid ] == 41 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000AA );
    if( d_fade_count[ playerid ] == 42 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000A1 );
    if( d_fade_count[ playerid ] == 43 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000009A );
    if( d_fade_count[ playerid ] == 44 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000090 );
    if( d_fade_count[ playerid ] == 45 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000008A );
    if( d_fade_count[ playerid ] == 46 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000080 );
    if( d_fade_count[ playerid ] == 47 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000007A );
    if( d_fade_count[ playerid ] == 48 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000070 );
    if( d_fade_count[ playerid ] == 49 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000006A );
    if( d_fade_count[ playerid ] == 50 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000060 );
    if( d_fade_count[ playerid ] == 51 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000005A );
    if( d_fade_count[ playerid ] == 52 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000050 );
    if( d_fade_count[ playerid ] == 53 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000004A );
    if( d_fade_count[ playerid ] == 54 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000040 );
    if( d_fade_count[ playerid ] == 55 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000003A );
    if( d_fade_count[ playerid ] == 56 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000030 );
    if( d_fade_count[ playerid ] == 57 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000002A );
    if( d_fade_count[ playerid ] == 58 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000020 );
    if( d_fade_count[ playerid ] == 59 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000001A );
    if( d_fade_count[ playerid ] == 60 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x00000010 );
    if( d_fade_count[ playerid ] == 61 ) return PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x0000000A );
    if( d_fade_count[ playerid ] == 62 ) return PlayerTextDrawHide( playerid, d_FadeTextDraw[ playerid ] ), d_fade_count[ playerid ] = 0, KillTimer( d_fade_timer[ playerid ] );

    return true;
}

forward OnPlayerScreenFade(playerid);

stock FadePlayerScreen(playerid) 
{

    if( d_fade_count[ playerid ] >= 32 ) return false;

    d_fade_timer[ playerid ] = SetTimerEx( "d_TextDrawFading", 50, true, "i", playerid );
    PlayerTextDrawShow( playerid, d_FadeTextDraw[ playerid ] );
    PlayerTextDrawBoxColor( playerid, d_FadeTextDraw[ playerid ], 0x000000FF );
    d_fade_count[ playerid ] = 32;
    if(funcidx("OnPlayerScreenFade") != -1)
    {
        CallLocalFunction("OnPlayerScreenFade", "i", playerid);
    }
    return true;
}

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
    Weapon[ 13 ],
    Ammo[ 13 ]
}

new d_PlayerWeaponInfo[MAX_PLAYERS][d_PlayerWeapInfo];

//-- Vehicles --//

stock KillVehicle(vehicleid)
{
    if(vehicleid == INVALID_VEHICLE_ID) return 0;
    else SetVehicleHealth(vehicleid, 0);
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

enum ___Weapon_information{
    wName[24],
    wID,
    wSlot,
    wModel
}

new __Weapon_information[ 47 ][ ___Weapon_information ] = {
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
        d_PlayerWeaponInfo[playerid][Weapon][__Weapon_information[weaponid][wSlot]] = weaponid;
        d_PlayerWeaponInfo[playerid][Ammo][ __Weapon_information[weaponid][wSlot] ] += ammo;
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

// - Commands - //

static stock __WeaponTimer_var[MAX_PLAYERS];

#if !defined MAX_DROPPED_GUNS

#define MAX_DROPPED_GUNS 2000

#endif
new _CreatedDroppedGuns;

enum __Weapon_data__Enum {
    Float:__Weapon_ObjectPosition[ 3 ],
    __Weapon_ObjectID,
    __Weapon_Object_Data[ 2 ],
};
new _WeaponData[ MAX_DROPPED_GUNS ][ __Weapon_data__Enum ];

stock CreateDroppedGun( __Weapon_id, __Weapon_ammo, Float:__Weapon_pos_x, Float:__Weapon_pos_y, Float:__Weapon_pos_z ) 
{
    if(_CreatedDroppedGuns == MAX_DROPPED_GUNS)
    {
        #if defined detutils_debug
        for(new i = 0; i < MAX_PLAYERS; i++)
        {
            if(i != INVALID_PLAYER_ID)
            {
                d_SendWarningMessage(i, "Maximum number of dropped gun objects reached.");
            }
        }
        #endif
        return 0;
    }
    for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ ) 
    {
        if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 ) 
        {
            _WeaponData[ __weap_index ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_index ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] = __Weapon_pos_x;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ] = __Weapon_pos_y;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] = __Weapon_pos_z;
            _WeaponData[ __weap_index ][ __Weapon_ObjectID ] = CreateDynamicObject( 
                __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ],
                 _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, random(360) );
            
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
    if(__WeaponTimer_var[playerid] != 0) return d_SendWarningMessage(playerid, "The player tried to use the command but the timer was not over yet.");
    #else
    if(__WeaponTimer_var[playerid] != 0) return 1;
    #endif

    new __Weapon_id = GetPlayerWeapon( playerid );
    new __Weapon_ammo = GetPlayerAmmo( playerid );
    if( __Weapon_id > 0 && __Weapon_ammo != 0 )
    {
        if( _g_Script == 0 )
        {
            new __weap_idx = -1;
            for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
            {
                if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 )
                {
                    __weap_idx = __weap_index;
                    break;
                }
            }
            if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"Operation can't be completed at the moment." );
            //#if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, __Weapon_id );
            //#endif
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            GetPlayerPos( playerid, _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] );
            _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = CreateDynamicObject( __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerThrowGun") != -1) CallLocalFunction("OnPlayerThrowGun", "i", playerid);
        }
    }
    return true;
}

command destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] , 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You destroyed {ffffff}%s"COLOUR_GREY".", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyGun") != -1) CallLocalFunction("OnPlayerDestroyGun", "i", playerid);
    return true;
}

command pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] ,
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You picked up {ffffff}%s"COLOUR_GREY".", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ], 
        _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
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

    new __Weapon_id = GetPlayerWeapon( playerid );
    new __Weapon_ammo = GetPlayerAmmo( playerid );
    if( __Weapon_id > 0 && __Weapon_ammo != 0 )
    {
        if( _g_Script == 0 )
        {
            new __weap_idx = -1;
            for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
            {
                if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 )
                {
                    __weap_idx = __weap_index;
                    break;
                }
            }
            if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"Operation can't be completed at the moment." );
            //#if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, __Weapon_id );
            //#endif
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            GetPlayerPos( playerid, _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] );
            _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = CreateDynamicObject( __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, -1, ""COLOUR_GREY"You threw away {ffffff}%s"COLOUR_GREY".", 
                __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
            if(funcidx("OnPlayerThrowGun") != -1) CallLocalFunction("OnPlayerThrowGun", "i", playerid);
        }
    }
    return true;
}

COMMAND__ destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] , 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You destroyed {ffffff}%s"COLOUR_GREY".", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
    if(funcidx("OnPlayerDestroyGun") != -1) CallLocalFunction("OnPlayerDestroyGun", "i", playerid);
    return true;
}

COMMAND__ pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_DROPPED_GUNS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] ,
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, -1, ""COLOUR_GREY"No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, -1, ""COLOUR_GREY"You picked up {ffffff}%s"COLOUR_GREY".", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ], 
        _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
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
    print("|======================================|");
    print("              d_visual.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
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