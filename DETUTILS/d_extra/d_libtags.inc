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

#if defined A_INTS_COMPATIBILITY_MODE || defined A_CMDS_COMPATIBILITY_MODE

    #define DETUTILS_COMPATIBILITY_MODE

#endif

#if !defined __PawnBuild

    #error [samp-detutils]: (fatal error) - DETUtils require community Pawn compiler. Get it from: github.com/pawn-lang/compiler

#endif

#if defined d_extra_included
    #endinput
#endif

#define d_extra_included

#include "d_init.inc"

#if defined detutils_debug

    #pragma warning disable 231

#endif

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

#define client_green 0x8ba962

#define detutils_visual_TRUE

#define until(%0)%8\10;%9 while( !( %0 ))%8

stock _RemID;

#define rem:<%0>; _RemID++; printf("[samp-detutils]: (rem) - Rem called. ID: %i", _RemID);

#define MAX_INTERIORS 300

#define MAX_FUNC_NAME (32)

#define util%3function:%0(%1) @_%0(%1); public @_%0(%1)

new PlayerText:_AnnouncementString[MAX_PLAYERS];
new Text:_AnnouncementUsebox;

stock _CallFunction(const func[], const spec[], id)
{
    new funcname[100];
    format(funcname, 100, "@_%s", func);
    return CallLocalFunction(funcname, spec, id);
}

stock _SetTimer(const func[], delay, bool:a, const spec[], id)
{
    new funcname[100];
    format(funcname, 100, "@_%s", func);
    return SetTimerEx(funcname, delay, a, spec, id);
}

#if !defined OnPlayerCommandReceived

    forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

stock _Functionid;

stock _GlobalFileName[MAX_PLAYERS][MAX_PLAYER_NAME];

#define _FormatPlayerDatabaseFileName(%0) \
    format(_GlobalFileName[%0],MAX_PLAYER_NAME,"%s.ini",ReturnPlayerName(%0))

new const _g_Script = 0;

static _g_Client[MAX_PLAYERS];

#if !defined SendClientCheck

    native SendClientCheck(playerid, type, memAddr, memOffset, byteCount);

#endif


#if defined OnPlayerClientCheckReceived

    forward OnPlayerClientCheckReceived(playerid);

#endif

public OnPlayerConnect(playerid)
{
    _g_Client[playerid] = 0;
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
        _g_Client[playerid] = 1;
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
    if(_g_Client[playerid] == 1) return true;
    return false;
}

stock bool:IsPlayerUsingAndroidClient(playerid)
{
    if(_g_Client[playerid] == 0) return true;
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

stock _ReturnPlayerName(id) 
{
    new _PlayerName[ MAX_PLAYER_NAME ];
    
    GetPlayerName( id, _PlayerName, sizeof _PlayerName);
    return _PlayerName;
}

new _g_Shifthour, _g_Timeshift = 0;

static stock _FixHourData(_f_Hour)
{
    _f_Hour = _g_Timeshift+_f_Hour;

    if(_f_Hour < 0)
    {
        _f_Hour = _f_Hour+24;
    }
    else if(_f_Hour > 23)
    {
        _f_Hour = _f_Hour-24;
    }
    _g_Shifthour = _f_Hour;
    return 1;
}

stock void:SaveLogIntoFile( const _FileName[], const _Log[]) 
{
    new _Entry[ 128 ], 
        _sec, 
        _minutes, 
        _data, 
        _day, 
        _year, 
        _month;

    getdate( _year, _month, _day );

    gettime( _sec, _minutes, _data );

    _FixHourData( _sec );

    _sec = _g_Shifthour;
    
    format( _Entry, sizeof( _Entry ), 
        "%d/%d/%d | %d/%d/%d | %s\r\n", 
        _day, _month, _year, 
        _sec, _minutes, _data, _Log );

    new File:_File;
    _File = fopen( _FileName, io_append );

    fwrite( _File, _Entry );

    fclose( _File );
}

stock void:_SetTag( const _FileName[], const _TagName[] )
{
    SaveLogIntoFile(_FileName,_TagName);
}

stock strtok(const string[], &index, delimiter = ' ') {
    new length = strlen(string);
    while ((index < length) && (string[index] <= delimiter)) {
        index++;
    }
    new offset = index;
    new result[128];
    while ((index < length) && (string[index] > delimiter) && ((index - offset) < (sizeof(result) - 1))) {
        result[index - offset] = string[index];
        index++;
    }
    result[index - offset] = EOS;
    return result;
}

stock strrest(const string[], &index)
{
    new length = strlen(string);
    while ((index < length) && (string[index] <= ' '))
    {
        index++;
    }
    new offset = index;
    new result[128];
    while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
    {
        result[index - offset] = string[index];
        index++;
    }
    result[index - offset] = EOS;
    return result;
}