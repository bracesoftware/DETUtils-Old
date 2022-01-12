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
    
    The Original Code is SA:MP | utils.
    
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

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

#if defined d_anticheat_included
    
    #endinput

#endif

#define d_anticheat_included

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

// Variables:

new gAntiCheatTimer;

// Macros:

#define anticheat_system_check(%0); \
    if(gAntiCheatToggled == 0) return print(\
    "[samp-detutils]: (debug) - Function '%0' wasn't executed because anti-cheat system is OFF.");

// Cheat defines:

#define CHEAT_TYPE_MONEY 0
#define CHEAT_TYPE_SKINCHANGER 1
#define CHEAT_TYPE_TELEPORT 2
#define CHEAT_TYPE_HIGHPING 3
#define CHEAT_TYPE_HEALTH 4
#define CHEAT_TYPE_ARMOUR 5

// Functions:

forward OnPlayerCheatDetected(playerid, cheattype);
forward detutils_cheatcheck(playerid);
public detutils_cheatcheck()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(i != INVALID_PLAYER_ID)
        {
            CheckPlayerMoney(i);
            CheckPlayerSkin(i);
            CheckPlayerPos(i);
            CheckPlayerPing(i);
            CheckPlayerArmour(i);
            CheckPlayerHealth(i);
        }
    }
    return 1;
}

#if !defined FILTERSCRIPT

main()
{
    gAntiCheatTimer = SetTimer("detutils_cheatcheck", 60000, true);
    a_anticheat_maina();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_anticheat_maina

public OnGameModeExit()
{
    KillTimer(gAntiCheatTimer);
    if(funcidx("a_anticheat_Ongmexit") != -1)
    {
        CallLocalFunction("a_anticheat_Ongmexit", "");
    }
    return 1;
}

#if defined _ALS_OnGameModeExit
    #undef OnGameModeExit
#else
    #define _ALS_OnGameModeExit
#endif

#define OnGameModeExit a_anticheat_Ongmexit

forward a_anticheat_Ongmexit();

#else

public OnFilterScriptInit()
{
    gAntiCheatTimer = SetTimer("detutils_cheatcheck", 60000, true);
    if(funcidx("a_anticheat_OnfsInita") != -1)
    {
        CallLocalFunction("a_anticheat_OnfsInita", "i", playerid);
    }
    return detutils_anticheat_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_anticheat_OnfsInita

forward a_anticheat_OnfsInita();

public OnFilterScriptExit()
{
    KillTimer(gAntiCheatTimer);
    if(funcidx("a_anticheat_Onfsexit") != -1)
    {
        CallLocalFunction("a_anticheat_Onfsexit", "");
    }
    return 1;
}

#if defined _ALS_OnFilterScriptExit
    #undef OnFilterScriptExit
#else
    #define _ALS_OnFilterScriptExit
#endif

#define OnFilterScriptExit a_anticheat_Onfsexit

forward a_anticheat_Onfsexit();


#endif

new gAntiCheatToggled = 1;

stock ToggleAntiCheatSystem(bool:toggle)
{
    if(toggle == true)
    {
        gAntiCheatToggled = 1;
        return 1;
    }
    if(toggle == false)
    {
        gAntiCheatToggled = 0;
        return 1;
    }
}

// Anti-cheat code:

enum ENUM_g_PlayerInfo
{
    Money,
    Skin,
    Float:Pos[3],
    bool:UsingTPHack = false,
    Ping,
    Float:Health,
    Float:Armour
}

new g_PlayerInfo[MAX_PLAYERS][ENUM_g_PlayerInfo];


public OnPlayerDisconnect(playerid, reason)
{
    g_PlayerInfo[playerid][Money] = 0;
    g_PlayerInfo[playerid][Skin] = 0;
    g_PlayerInfo[playerid][UsingTPHack] = false;
    g_PlayerInfo[playerid][Health] = 0;
    g_PlayerInfo[playerid][Armour] = 0;
    if(funcidx("a_anticheat_Onpds") != -1)
    {
        CallLocalFunction("a_anticheat_Onpds", "");
    }
    return 1;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect a_anticheat_Onpds

forward a_anticheat_Onpds(playerid, reason);

// MONEY ANTI-CHEAT:

stock d_ac_GivePlayerMoney(playerid, money)
{
    GivePlayerMoney(playerid, money);
    g_PlayerInfo[playerid][Money] += money;
    return 1;
}

stock CheckPlayerMoney(playerid)
{
    anticheat_system_check(CheckPlayerMoney);

    new currentmoney = GetPlayerMoney(playerid);
    if(currentmoney != g_PlayerInfo[playerid][Money])
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_MONEY);
            return 1;
        }
    }
    return 0;
}

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif

#define GivePlayerMoney d_ac_GivePlayerMoney

// SKIN ANTI-CHEAT:

stock d_ac_SetPlayerSkin(playerid, skin)
{
    SetPlayerSkin(playerid, skin);
    g_PlayerInfo[playerid][Skin] = skin;
    return 1;
}

stock CheckPlayerSkin(playerid)
{
    anticheat_system_check(CheckPlayerSkin);

    new currentskin = GetPlayerSkin(playerid);
    if(currentskin != g_PlayerInfo[playerid][Skin])
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_SKINCHANGER);
            return 1;
        }
    }
    return 0;
}

#if defined _ALS_SetPlayerSkin
    #undef SetPlayerSkin
#else
    #define _ALS_SetPlayerSkin
#endif

#define SetPlayerSkin d_ac_SetPlayerSkin

// TELEPORT ANTI-CHEAT:

stock d_ac_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
    SetPlayerPos(playerid, x, y, z);
    g_PlayerInfo[playerid][Pos][0] = x;
    g_PlayerInfo[playerid][Pos][1] = y;
    g_PlayerInfo[playerid][Pos][2] = z;
    return 1;
}

stock CheckPlayerPos(playerid)
{
    anticheat_system_check(CheckPlayerPos);
    if(g_PlayerInfo[playerid][UsingTPHack] == true)
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_TELEPORT);
            return 1;
        }
    }
    return 0;
}

#if defined _ALS_SetPlayerPos
    #undef SetPlayerPos
#else
    #define _ALS_SetPlayerPos
#endif

#define SetPlayerPos d_ac_SetPlayerPos

// HIGH PING ANTI-CHEAT:

stock CheckPlayerPing(playerid)
{
    anticheat_system_check(CheckPlayerPing);
    new ping = GetPlayerPing(playerid);
    g_PlayerInfo[playerid][Ping] = ping;
    if(g_PlayerInfo[playerid][Ping] > 250)
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_HIGHPING);
            return 1;
        }
    }
    return 0;
}

// HEALTH ANTI-CHEAT:

stock d_ac_SetPlayerHealth(playerid, Float:health)
{
    SetPlayerHealth(playerid, health);
    g_PlayerInfo[playerid][Health] = health;
    return 1;
}

stock CheckPlayerHealth(playerid)
{
    anticheat_system_check(CheckPlayerHealth);
    new Float:health;
    GetPlayerHealth(playerid, Float:health);
    if(health != g_PlayerInfo[playerid][Health])
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_HEALTH);
            return 1;
        }
    }
    return 0;
}

#if defined _ALS_SetPlayerHealth
    #undef SetPlayerHealth
#else
    #define _ALS_SetPlayerHealth
#endif

#define SetPlayerHealth d_ac_SetPlayerHealth

// ARMOUR ANTI-CHEAT:

stock d_ac_SetPlayerArmour(playerid, Float:armour)
{
    SetPlayerArmour(playerid, armour);
    g_PlayerInfo[playerid][Armour] = armour;
    return 1;
}

stock CheckPlayerArmour(playerid)
{
    anticheat_system_check(CheckPlayerArmour);
    new Float:armour;
    GetPlayerArmour(playerid, Float:armour);
    if(armour != g_PlayerInfo[playerid][Armour])
    {
        if(funcidx("OnPlayerCheatDetected") != -1)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, CHEAT_TYPE_ARMOUR);
            return 1;
        }
    }
    return 0;
}

#if defined _ALS_SetPlayerArmour
    #undef SetPlayerArmour
#else
    #define _ALS_SetPlayerArmour
#endif

#define SetPlayerArmour d_ac_SetPlayerArmour

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

static AnnounceLibraryLoaded_anticheat()
{
    print("|======================================|");
    print("            d_anticheat.inc             ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_anticheat.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_anticheat.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_anticheat();
    a_anticheat_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_anticheat_main

#else

#define detutils_anticheat_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_anticheat();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_anticheat.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_anticheat.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_anticheat_OnfsInit") != -1)
    {
        CallLocalFunction("a_anticheat_OnfsInit", "i", playerid);
    }
    return detutils_anticheat_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_anticheat_OnfsInit

forward a_anticheat_OnfsInit();

#endif