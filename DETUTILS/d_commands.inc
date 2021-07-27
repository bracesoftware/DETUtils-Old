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

/*

                                                                               
88b           d88                                                              
888b         d888                                                              
88`8b       d8'88                                                              
88 `8b     d8' 88  ,adPPYYba,   ,adPPYba,  8b,dPPYba,   ,adPPYba,   ,adPPYba,  
88  `8b   d8'  88  ""     `Y8  a8"     ""  88P'   "Y8  a8"     "8a  I8[    ""  
88   `8b d8'   88  ,adPPPPP88  8b          88          8b       d8   `"Y8ba,   
88    `888'    88  88,    ,88  "8a,   ,aa  88          "8a,   ,a8"  aa    ]8I  
88     `8'     88  `"8bbdP"Y8   `"Ybbd8"'  88           `"YbbdP"'   `"YbbdP"'  
                                                                               
                                                                               
*/

#if defined _a_cmd_processor_included
        #endinput
#endif 
#define _a_cmd_processor_included

#if !defined MAX_FUNC_NAME

#define MAX_FUNC_NAME (32)

#endif

#define cmd_%0\32; cmd_
#define dbg_%0\32; dbg_
#define cmd_func_%0\32; cmd_func_
#define role_%0\32; role_

#if !defined A_CMDS_COMPATIBILITY_MODE

#define command%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)

#define alias%5command%0(%1[%3]%4)=%2; \
    forward cmd_%0(%1[]);%3public cmd_%0(%1[]){return cmd_%2(%1)%4;%5}

#define _public public
#define forward_ forward

#define debug%1command%0() \
    forward dbg_%0(debugged_cmdtext[], debugged_stateid);%1public dbg_%0(debugged_cmdtext[], debugged_stateid)

#define GetDebuggedCommandName%0(%1) %0debugged_cmdtext%1

#define CMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define YCMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define COMMAND CMD

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define admin%5command%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define role%5command%0(%1,%2[%3]%4,%6) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define create%0role%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }

#else

#define COMMAND__%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)

#define ALIAS__COMMAND__%0(%1[%3]%4)%5=%2; \
    forward cmd_%0(%1[]);%3public cmd_%0(%1[]){return cmd_%2(%1)%4;%5}

#define DEBUG__COMMAND__%0(%1) \
    forward dbg_%0(debugged_cmdtext[], debugged_stateid);%1public dbg_%0(debugged_cmdtext[], debugged_stateid)

#define GETDBGCMD__%0(%1) %0debugged_cmdtext%1

#define ADMIN__COMMAND__%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])

#define ROLE__COMMAND__%0(%1,%2[%3]%4,%6) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])

#define CREATE__ROLE__%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }

#define CMD__:%0(%1) \
    forward  cmd_%0(%1); public cmd_%0(%1)

#define YCMD__:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define COMMAND__ CMD__

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

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

stock CallLocalCommand(const command[], const specifiers[], integner, const string[])
{
    new command_name[MAX_FUNC_NAME];
    format
        (
            command_name, 
            MAX_FUNC_NAME, 
            "cmd_%s", 
            command
        )
    ;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - CallLocalCommand called successfully.");
    #endif
    return CallLocalFunction
                (
                    command_name, 
                    specifiers, 
                    integner, 
                    string
                )
        ;
}

static _g_ChatMode[MAX_PLAYERS];

stock CallRemoteCommand(const command[], const specifiers[], integner, const string[])
{
    new command_name[MAX_FUNC_NAME];
    format
        (
            command_name, 
            MAX_FUNC_NAME, 
            "cmd_%s", 
            command
        )
    ;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - CallRemoteCommand called successfully.");
    #endif
    return CallRemoteFunction
                (
                    command_name, 
                    specifiers, 
                    integner, 
                    string
                )
        ;

}

stock CallRemotePrefixedCommand(const command[], const specifiers[], integner, const string[])
{
    new command_name[MAX_FUNC_NAME];
    format
        (
            command_name, 
            MAX_FUNC_NAME, 
            "pc_%s", 
            command
        )
    ;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - CallRemoteCommand called successfully.");
    #endif
    return CallRemoteFunction
                (
                    command_name, 
                    specifiers, 
                    integner, 
                    string
                )
        ;

}

stock CallLocalPrefixedCommand(const command[], const specifiers[], integner, const string[])
{
    new command_name[MAX_FUNC_NAME];
    format
        (
            command_name, 
            MAX_FUNC_NAME, 
            "pc_%s", 
            command
        )
    ;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - CallRemoteCommand called successfully.");
    #endif
    return CallLocalFunction
                (
                    command_name, 
                    specifiers, 
                    integner, 
                    string
                )
        ;

}

#define GetCommandDebugState%1(%2) %1debugged_stateid%2

#if !defined OnPlayerCommandReceived

    forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

#define COMMAND_DEBUG_STATE_RECEIVED 0
#define COMMAND_DEBUG_STATE_READY 1
#define COMMAND_DEBUG_STATE_PERFORMED 2

/*
                                         
88                                   88  
""                                   88  
                                     88  
88  88,dPYba,,adPYba,   8b,dPPYba,   88  
88  88P'   "88"    "8a  88P'    "8a  88  
88  88      88      88  88       d8  88  
88  88      88      88  88b,   ,a8"  88  
88  88      88      88  88`YbbdP"'   88  
                        88               
                        88               
*/

static void:AnnounceLibraryLoaded()
{
    print("|======================================|");
    print("             d_commands.inc             ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

static
        bool:_IsOnCmdRValid = false,
        bool:_IsOnCmdPValid = false;

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    _IsOnCmdRValid = funcidx("OnPlayerCommandReceived") != -1;
    _IsOnCmdPValid = funcidx("OnPlayerCommandPerformed") != -1;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ongminit :: Commands init...");
    SaveLogIntoFile("det_commands.log", "[samp-detutils]: (debug) - Loading...");
    #endif

    if (funcidx("a_cmd_processor_OnGameModeInit") != -1)
    {
        return CallLocalFunction("a_cmd_processor_OnGameModeInit", "");
    }      
    return 1;
}

main()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ongminit :: Commands loading finished.");
    SaveLogIntoFile("det_commands.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded();
    a_cmd_main();
}

#else

public OnFilterScriptInit()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - onfsinit :: Commands loading finished.");
    SaveLogIntoFile("det_commands.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("det_commands.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded();
    _IsOnCmdRValid = funcidx("OnPlayerCommandReceived") != -1;
    _IsOnCmdPValid = funcidx("OnPlayerCommandPerformed") != -1;

    if (funcidx("a_cmd_OnFilterScriptInit") != -1)
    {
        return CallLocalFunction("a_cmd_OnFilterScriptInit", "");
    }
    return 1;
}

#endif

public OnPlayerDisconnect(playerid, reason)
{
    _ClearChatModeData(playerid);
    if(funcidx("a_cmd_OnPlayerDisconnect") != -1)
    {
        CallLocalFunction("a_cmd_OnPlayerDisconnect", "ii", playerid, reason);
    }
    return 1;
}
 
public OnPlayerCommandText(playerid, cmdtext[])
{
    if (_IsOnCmdRValid && !CallLocalFunction("OnPlayerCommandReceived", 
        "is", 
        playerid, 
        cmdtext))
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned 1.");
        #endif
        return 1;
    }
    new
        position,
        _ClassicFunctionName[MAX_FUNC_NAME],
        _CommandDebugFunc[MAX_FUNC_NAME];

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Successfully declared variables.");
    #endif

    while (cmdtext[++position] > ' ')
    {
        _ClassicFunctionName[position-1] = tolower(cmdtext[position]);
    }
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: cmdtext[] validated.");
    #endif
    format(_CommandDebugFunc, sizeof(_CommandDebugFunc), "dbg_%s", _ClassicFunctionName);
    format(_ClassicFunctionName, sizeof(_ClassicFunctionName), "cmd_%s", _ClassicFunctionName);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Formatted function strings successfully.");
    #endif

    if(funcidx(_CommandDebugFunc) != -1)
    {
        CallLocalFunction(_CommandDebugFunc, "si", cmdtext, COMMAND_DEBUG_STATE_RECEIVED);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Called custom debug function : %s.", _CommandDebugFunc);
    #endif

    while (cmdtext[position] == ' ') position++;

    if(funcidx(_CommandDebugFunc) != -1)
    {
        CallLocalFunction(_CommandDebugFunc, "si", cmdtext, COMMAND_DEBUG_STATE_READY);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: position variable validated.");
    #endif
    if (!cmdtext[position])
    {
        if (_IsOnCmdPValid)
        {
            #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 1");
            #endif
                if(funcidx(_CommandDebugFunc) != -1)
                {
                    CallLocalFunction(_CommandDebugFunc, "si", cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
                }
                return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext, 
                    CallLocalFunction(_ClassicFunctionName, "is", playerid, "\1"));
        }
        #if defined detutils_debug
        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "si", cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
        }
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2");
        #endif
        return CallLocalFunction(_ClassicFunctionName, "is", playerid, "\1");      
    }
    if (_IsOnCmdPValid)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 3");
        #endif
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "si", cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
            }
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(_ClassicFunctionName, "is", playerid, cmdtext[position]));
    }

    if (funcidx("a_OnPlayerCommandText") != -1)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned its hook call.");
        #endif
        CallLocalFunction("a_OnPlayerCommandText", 
            "is", 
            playerid, 
            cmdtext);
    }

    return CallLocalFunction(_ClassicFunctionName, "is", playerid, cmdtext[position]);
}

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
 
#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif

#define OnPlayerCommandText a_OnPlayerCommandText

forward a_OnPlayerCommandText(playerid, cmdtext[]);

#if !defined FILTERSCRIPT

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_cmd_processor_OnGameModeInit

forward a_cmd_processor_OnGameModeInit();

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_cmd_main

#else

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_cmd_OnFilterScriptInit

forward a_cmd_OnFilterScriptInit();

#endif

forward OnPrefixedCommandReceived(playerid, cmdtext[]);

forward OnPrefixedCommandPerformed(playerid, cmdtext[], success);

stock strgetfc(const string[]) 
{
    return ((string)[0] > 255) ? string{0} : string[0];
}

public OnPlayerText(playerid, text[])
{
    if(_g_Script == 1)
    {
        #if defined a_cmds_opthook

        if(funcidx("a_cmd_OnPlayerText") != -1)
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned its hook call.");
            #endif
            CallLocalFunction("a_cmd_OnPlayerText", "is", playerid, text);
        }

        #endif

        if (_IsOnCmdRValid && !CallLocalFunction("OnPrefixedCommandReceived", 
            "is", 
            playerid, 
            text))
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned 1.");
            #endif
            return 1;
        }

        new
            position,
            _Prefix[MAX_FUNC_NAME],
            _FunctionName[MAX_FUNC_NAME];

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared variables!");
        #endif

        while(text[++position] > ' ')
        {
            _FunctionName[position-1] = tolower(text[position]);
        }

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) validated text[] and position;.");
            #endif

        format(_Prefix, sizeof(_Prefix),
            "%s@prx", _FunctionName);

        strdel(_Prefix, 0, 1);

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) generated cmd_prx funcname.");
            #endif

        format(_FunctionName, sizeof(_FunctionName), 
            "pc@%s", text);
        
        strdel(_FunctionName, 3, 4);

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) generated cmd funcname.");
            #endif

        while(text[position] == ' ')
        {
            position++;
        }

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) position ++");
            #endif

        if(!text[position])
        {
            if(_IsOnCmdPValid)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                return CallLocalFunction("OnPrefixedCommandPerformed", 
                            "isi", playerid, text, 
                            CallLocalFunction(_FunctionName, "is", playerid, "\1"));
            }
            #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
                #endif
            return CallLocalFunction(_FunctionName, "is", playerid, "\1");
        }
        if(_IsOnCmdPValid)
        {
            #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 2");
                #endif
            return CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(_FunctionName, "is", playerid, text[position]));
        }
        #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 3");
                #endif
        return CallLocalFunction(_FunctionName, "is", playerid, text[position]);
    
    }

    if(_g_ChatMode[playerid] == 1)
    {
        if (_IsOnCmdRValid && !CallLocalFunction("OnPrefixedCommandReceived", 
            "is", 
            playerid, 
            text))
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned 1.");
            #endif
            return 1;
        }

        static 
            _pos,
            _FunctionName[MAX_FUNC_NAME],
            _PrefixFuncName[MAX_FUNC_NAME];

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared variables!");
        #endif

        if(_g_Script == 1)
        {

            while (text[++_pos] > ' ')
            {
                _FunctionName[_pos-1] = tolower(text[_pos]);
            }

            _pos = 0;

            while(text[++_pos] > ' ')
            {
                _PrefixFuncName[_pos-1] = tolower(text[_pos]);
            }

        }

        format(_PrefixFuncName, sizeof(_PrefixFuncName),
            "prx_%s", text);

        format(_FunctionName, sizeof(_FunctionName),
            "pc_%s", text);

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) string formattion finished.");
        #endif

        if(_g_Script == 1)
        {
            while(text[_pos] == ' ')
            {
                _pos++;
            }

        }
        
        strdel(_PrefixFuncName, 4, 5);

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func.");
        #endif

        new _ActPrefix[MAX_FUNC_NAME];

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared active_prefix variable!");
        #endif

        format(_ActPrefix, sizeof(_ActPrefix), "%s", CallLocalFunction(_PrefixFuncName, ""));

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) formatted active prefix var.");
        #endif

        if(!strcmp(_ActPrefix, text[0]))
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) performed if-pattern check.");
            #endif
            strdel(_FunctionName, 3, 4);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func. ID: 1");
            #endif
            if(_IsOnCmdPValid)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(_FunctionName, "is", playerid, text));
                return 0;
            }
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
            #endif
            CallLocalFunction(_FunctionName, "is", playerid, text);
            return 0;
        }
    }
    if(_g_ChatMode[playerid] == 0)
    {
        if(funcidx("a_cmd_OnPlayerText") != -1)
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned its hook call.");
            #endif
            CallLocalFunction("a_cmd_OnPlayerText", "is", playerid, text);
        }
    }
    return 1;
}

#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif

#define OnPlayerText a_cmd_OnPlayerText

forward a_cmd_OnPlayerText(playerid, text[]);

command chatmode(playerid, params[])
{
    if(_g_ChatMode[playerid] == 0)
    {
        SendClientMessage(playerid, -1, "SERVER: Chat mode switched to custom-prefixed commands mode.");
        _g_ChatMode[playerid] = 1;
        return 1;
    }
    else if(_g_ChatMode[playerid] == 1)
    {
        SendClientMessage(playerid, -1, "SERVER: Chat mode switched to plain-text messages mode.");
        _g_ChatMode[playerid] = 0;
        return 1;
    }
    return 0;
}

static stock _ClearChatModeData(playerid)
{
    return _g_ChatMode[playerid] = 0;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect a_cmd_OnPlayerDisconnect

forward a_cmd_OnPlayerDisconnect(playerid, reason);

#if !defined A_CMDS_COMPATIBILITY_MODE

#define pc_%0\32; pc_
#define prx_%0\32; prx_

#define prefixed%2command%0(%1,%3) \
    stock prx_%0(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

#else

#define pc_%0\32; pc_
#define prx_%0\32; prx_

#define PREFIXED__COMMAND__%0(%1,%3) \
    stock prx_%0(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

#endif