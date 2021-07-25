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

#if defined d_extra_included
    #endinput
#endif

#define d_extra_included

#include "d_init.inc"

/*
                                                
88888888ba,                                     
88      `"8b                 ,d                 
88        `8b                88                 
88         88  ,adPPYYba,  MM88MMM  ,adPPYYba,  
88         88  ""     `Y8    88     ""     `Y8  
88         8P  ,adPPPPP88    88     ,adPPPPP88  
88      .a8P   88,    ,88    88,    88,    ,88  
88888888Y"'    `"8bbdP"Y8    "Y888  `"8bbdP"Y8  
                                                
*/

#define MAX_INTERIORS 300

#define MAX_FUNC_NAME (32)

#define util%3function:%0(%1) @utils_%0(%1); public @utils_%0(%1)

stock PlayerText:utils_AnnouncementString[MAX_PLAYERS];
stock Text:utils_AnnouncementUsebox;

stock utils_CallFunction(const func[], const spec[], id)
{
    new funcname[100];
    format(funcname, 100, "@utils_%s", func);
    return CallLocalFunction(funcname, spec, id);
}

stock utils_SetTimer(const func[], delay, bool:a, const spec[], id)
{
    new funcname[100];
    format(funcname, 100, "@utils_%s", func);
    return SetTimerEx(funcname, delay, a, spec, id);
}

#if !defined OnPlayerCommandReceived

    forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

stock utils_Functionid;

stock utils_GlobalFileName[MAX_PLAYERS][MAX_PLAYER_NAME];

#define utils_FormatPlayerDatabaseFileName(%0) \
    format(utils_GlobalFileName[%0],MAX_PLAYER_NAME,"%s.ini",ReturnPlayerName(%0))

new const utils_g_Script = 0;

static utils_g_Client[MAX_PLAYERS];

#if !defined SendClientCheck

    native SendClientCheck(playerid, type, memAddr, memOffset, byteCount);

#endif


#if defined OnPlayerClientCheckReceived

    forward OnPlayerClientCheckReceived(playerid);

#endif

public OnPlayerConnect(playerid)
{
    utils_g_Client[playerid] = 0;
    SendClientCheck(playerid, 0x48, 0, 0, 2);
    if(funcidx("OnPlayerClientCheckReceived") != -1)
    {
        CallLocalFunction("OnPlayerClientCheckReceived", "i", playerid);
    }
    if(funcidx("a_lib_OnPlayerConnect") != -1)
    {
        CallLocalFunction("a_lib_OnPlayerConnect", "i", playerid);
    }
    return 1;
}

forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

public OnClientCheckResponse(playerid, actionid, memaddr, retndata)
{
    if(actionid == 0x48)
    {
        utils_g_Client[playerid] = 1;
    }
    if(funcidx("a_lib_OnClientCheckResponse") != -1)
    {
        CallLocalFunction("a_lib_OnClientCheckResponse", "iiii", playerid, actionid, memaddr, retndata);
    }
    return 1;
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect a_lib_OnPlayerConnect

forward a_lib_OnPlayerConnect(playerid);

#if defined _ALS_OnClientCheckResponse
    #undef OnClientCheckResponse
#else
    #define _ALS_OnClientCheckResponse
#endif

#define OnClientCheckResponse a_lib_OnClientCheckResponse

forward a_lib_OnClientCheckResponse(playerid, actionid, memaddr, retndata);

stock bool:IsPlayerUsingPCClient(playerid)
{
    if(utils_g_Client[playerid] == 1) return true;
    return false;
}

stock bool:IsPlayerUsingAndroidClient(playerid)
{
    if(utils_g_Client[playerid] == 0) return true;
    return false;
}

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

stock ReturnPlayerName(id) 
{
    new utils_PlayerName[ MAX_PLAYER_NAME ];
    
    GetPlayerName( id, utils_PlayerName, sizeof utils_PlayerName);
    return utils_PlayerName;
}

new utils_g_Shifthour, utils_g_Timeshift = 0;

static stock utils_FixHourData(utils_f_Hour)
{
    utils_f_Hour = utils_g_Timeshift+utils_f_Hour;

    if(utils_f_Hour < 0)
    {
        utils_f_Hour = utils_f_Hour+24;
    }
    else if(utils_f_Hour > 23)
    {
        utils_f_Hour = utils_f_Hour-24;
    }
    utils_g_Shifthour = utils_f_Hour;
    return 1;
}

stock SaveLogIntoFile( const utils_FileName[], const utils_Log[]) 
{
    new utils_Entry[ 128 ], 
        utils_sec, 
        utils_minutes, 
        utils_data, 
        utils_day, 
        utils_year, 
        utils_month;

    getdate( utils_year, utils_month, utils_day );

    gettime( utils_sec, utils_minutes, utils_data );

    utils_FixHourData( utils_sec );

    utils_sec = utils_g_Shifthour;
    
    format( utils_Entry, sizeof( utils_Entry ), 
        "%d/%d/%d | %d/%d/%d | %s\r\n", 
        utils_day, utils_month, utils_year, 
        utils_sec, utils_minutes, utils_data, utils_Log );

    new File:utils_File;
    utils_File = fopen( utils_FileName, io_append );

    fwrite( utils_File, utils_Entry );

    fclose( utils_File );
}

stock utils_SetTag( const utils_FileName[], const utils_TagName[] )
{
    SaveLogIntoFile(utils_FileName,utils_TagName);
}