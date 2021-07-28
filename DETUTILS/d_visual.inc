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

new __WeaponTimer_var[MAX_PLAYERS];

#define MAX_GUN_OBJECTS 3000

enum __Weapon_data__Enum {
    Float:__Weapon_ObjectPosition[ 3 ],
    __Weapon_ObjectID,
    __Weapon_Object_Data[ 2 ],
};
new _WeaponData[ MAX_GUN_OBJECTS ][ __Weapon_data__Enum ];

stock CreateDroppedGun( __Weapon_id, __Weapon_ammo, Float:__Weapon_pos_x, Float:__Weapon_pos_y, Float:__Weapon_pos_z ) {
    for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ ) {
        if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 ) {
            _WeaponData[ __weap_index ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_index ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] = __Weapon_pos_x;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ] = __Weapon_pos_y;
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] = __Weapon_pos_z;
            _WeaponData[ __weap_index ][ __Weapon_ObjectID ] = CreateDynamicObject( __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ], _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, random(360) );
            return 1;
        }
    }
    return 1;
}

#if !defined DETUTILS_COMPATIBILITY_MODE

command throwgun( playerid, params[] )
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    
    if(__WeaponTimer_var[playerid] != 0) return 1;

    new __Weapon_id = GetPlayerWeapon( playerid );
    new __Weapon_ammo = GetPlayerAmmo( playerid );
    if( __Weapon_id > 0 && __Weapon_ammo != 0 )
    {
        if( _g_Script == 0 )
        {
            new __weap_idx = -1;
            for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
            {
                if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 )
                {
                    __weap_idx = __weap_index;
                    break;
                }
            }
            if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "Operation can't be completed at the moment." );
            #if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, __Weapon_id );
            #endif
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            GetPlayerPos( playerid, _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] );
            _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = CreateDynamicObject( __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, client_green, "You threw away {ffffff}%s.", 
                __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
        }
    }
    return true;
}

command destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] , 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, client_green, "You destroyed {ffffff}%s.", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
    return true;
}

command pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] ,
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, client_green, "You picked up {ffffff}%s.", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ], 
        _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
    return true;
}

#else

COMMAND__ throwgun( playerid, params[] )
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return 1;
    
    if(__WeaponTimer_var[playerid] != 0) return 1;

    new __Weapon_id = GetPlayerWeapon( playerid );
    new __Weapon_ammo = GetPlayerAmmo( playerid );
    if( __Weapon_id > 0 && __Weapon_ammo != 0 )
    {
        if( _g_Script == 0 )
        {
            new __weap_idx = -1;
            for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
            {
                if( _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0 ] == 0.0 )
                {
                    __weap_idx = __weap_index;
                    break;
                }
            }
            if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "Operation can't be completed at the moment." );
            #if defined RemovePlayerWeapon
            RemovePlayerWeapon( playerid, __Weapon_id );
            #endif
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = __Weapon_id;
            _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = __Weapon_ammo;
            GetPlayerPos( playerid, _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] );
            _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = CreateDynamicObject( __Weapon_information[ __Weapon_id ][ wModel ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ], _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ], 
                _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ]-1, 93.7, 120.0, 120.0 );
            __WeaponTimer_var[ playerid ] = 30;
            SendClientMessage( playerid, client_green, "You threw away {ffffff}%s.", 
                __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
        }
    }
    return true;
}

COMMAND__ destroygun( playerid, params[] )
{
    if( GetPlayerState( playerid ) != PLAYER_STATE_ONFOOT ) return 1;
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] , 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
            _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, client_green, "You destroyed {ffffff}%s.", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
    return true;
}

COMMAND__ pickgun( playerid, params[] )
{
    if( GetPlayerState(playerid) != PLAYER_STATE_ONFOOT ) return 1;
    
    new __weap_idx = -1;
    for( new __weap_index = 0; __weap_index < MAX_GUN_OBJECTS; __weap_index++ )
    {
        if( IsPlayerInRangeOfPoint( playerid, 5.0, _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 0] ,
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 1 ], 
         _WeaponData[ __weap_index ][ __Weapon_ObjectPosition ][ 2 ] ) )
        {
            __weap_idx = __weap_index;
            break;
        }
    }
    if( __weap_idx == -1 ) return SendClientMessage(playerid, client_green, "No guns nearby." );
    DestroyDynamicObject( _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] );
    SendClientMessage( playerid, client_green, "You picked up {ffffff}%s.", 
        __Weapon_information[ _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] ][ wName ] );
    GivePlayerWeapon( playerid, _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ], 
        _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] );
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 0 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 1 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectPosition ][ 2 ] = 0.0;
    _WeaponData[ __weap_idx ][ __Weapon_ObjectID ] = -1;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 0 ] = 0;
    _WeaponData[ __weap_idx ][ __Weapon_Object_Data ][ 1 ] = 0;
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