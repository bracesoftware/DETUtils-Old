/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this utils_GlobalFileName are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this utils_GlobalFileName except in compliance with 
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

#define DEV_MODE
#if defined DEV_MODE

#include <a_samp>

#endif

#if defined d_data_included
    #endinput
#endif

#define d_data_included

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

#define skinid GetPlayerSkin(playerid)
#define vehicleid GetPlayerVehicleID(playerid)
#define teamid GetPlayerTeam(playerid)
#define ammo GetPlayerAmmo(playerid)
#define interiorid GetPlayerInterior(playerid)
#define stateid GetPlayerState(playerid)
#define worldid GetPlayerVirtualWorld(playerid)
#define score GetPlayerScore(playerid)
#define ping GetPlayerPing(playerid)
#define color GetPlayerColor(playerid)
#define weaponid GetPlayerWeapon(playerid)
#define menuid GetPlayerMenu(playerid)
#define drunklevel GetPlayerDrunkLevel(playerid)
#define fightingstyle GetPlayerFightingStyle(playerid)
#define seatid GetPlayerVehicleSeat(playerid)
#define money GetPlayerMoney(playerid)

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

static AnnounceLibraryLoaded_data()
{
    print("|======================================|");
    print("                d_data.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_data();
    a_data_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_data_main

#else

#define detutils_data_TRUE 1

public OnFilterScriptutilst()
{
    AnnounceLibraryLoaded_data();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_data_Onfsutilst") != -1)
    {
        CallLocalFunction("a_data_Onfsutilst", "i", playerid);
    }
    return detutils_data_TRUE;
}

#if defined _ALS_OnFilterScriptutilst
    #undef OnFilterScriptutilst
#else
    #define _ALS_OnFilterScriptutilst
#endif

#define OnFilterScriptutilst a_data_Onfsutilst

forward a_data_Onfsutilst();

#endif