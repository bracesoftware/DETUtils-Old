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

#if !defined A_CMDS_COMPATIBILITY_MODE

#define command%0(%1) \
    forward%0@cmd(%1);public%0@cmd(%1)

#define alias%5command%0(%1[%3]%4)=%2; \
    forward%0@cmd(%1[]);%3public%0@cmd(%1[]){return %2@cmd(%1)%4;%5}

#define _public public
#define forward_ forward

#define debug%1command%0() \
    forward%0@dbg(debugged_cmdtext[]);%1public%0@dbg(debugged_cmdtext[])

#define GetDebuggedCommandName%0(%1) %0debugged_cmdtext%1

#define CMD:%0(%1) \
    forward %0@cmd(%1); public %0@cmd(%1)

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define admin%5command%0(%1,%2[%3]%4) \
    forward%0@cmd(%1,%2[]);%3public%0@cmd(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return %0@cmd_func(%1,%2)%4;%5} \
    forward%0@cmd_func(%1,%2[]);public%0@cmd_func(%1,%2[]%5)

#else

#define COMMAND__%0(%1) \
    forward%0@cmd(%1);public%0@cmd(%1)

#define ALIAS__COMMAND__%0(%1[%3]%4)%5=%2; \
    forward%0@cmd(%1[]);%3public%0@cmd(%1[]){return %2@cmd(%1)%4;%5}

#define DEBUG__COMMAND__%0(%1) \
    forward%0@dbg(debugged_cmdtext[]);%1public%0@dbg(debugged_cmdtext[])

#define GETDBGCMD__%0(%1) %0debugged_cmdtext%1

#define ADMIN__COMMAND__%0(%1,%2[%3]%4) \
    forward%0@cmd(%1,%2[]);%3public%0@cmd(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return %0@cmd_func(%1,%2)%4;} \
    forward%0@cmd_func(%1,%2[]);public%0@cmd_func(%1,%2[])

#define CMD__:%0(%1) \
    forward %0@cmd(%1); public %0@cmd(%1)

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
            "%s@cmd", 
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

static utils_g_ChatMode[MAX_PLAYERS];

stock CallRemoteCommand(const command[], const specifiers[], integner, const string[])
{
    new command_name[MAX_FUNC_NAME];
    format
        (
            command_name, 
            MAX_FUNC_NAME, 
            "%s@cmd", 
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

#if !defined OnPlayerCommandReceived

    forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

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

static AnnounceLibraryLoaded()
{
    print("|======================================|");
    print("             d_commands.inc             ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

static
        bool:utils_IsOnCmdRValid = false,
        bool:utils_IsOnCmdPValid = false;

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    utils_IsOnCmdRValid = funcidx("OnPlayerCommandReceived") != -1;
    utils_IsOnCmdPValid = funcidx("OnPlayerCommandPerformed") != -1;

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - ongminit :: Commands init...");
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loading...");
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
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded();
    a_cmd_main();
}

#else

public OnPlayerDisconnect(playerid, reason)
{
    utils_ClearChatModeData(playerid);
    if(funcidx("a_cmd_OnPlayerDisconnect") != -1)
    {
        CallLocalFunction("a_cmd_OnPlayerDisconnect", "ii", playerid, reason);
    }
    return 1;
}

public OnFilterScriptInit()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - onfsinit :: Commands loading finished.");
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded();
    utils_IsOnCmdRValid = funcidx("OnPlayerCommandReceived") != -1;
    utils_IsOnCmdPValid = funcidx("OnPlayerCommandPerformed") != -1;

    if (funcidx("a_cmd_OnFilterScriptInit") != -1)
    {
        return CallLocalFunction("a_cmd_OnFilterScriptInit", "");
    }
    return 1;
}

#endif
 
public OnPlayerCommandText(playerid, cmdtext[])
{
    if (utils_IsOnCmdRValid && !CallLocalFunction("OnPlayerCommandReceived", 
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
        utils_ClassicFunctionName[MAX_FUNC_NAME],
        utils_CommandDebugFunc[MAX_FUNC_NAME];

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Successfully declared variables.");
    #endif

    while (cmdtext[++position] > ' ')
    {
        utils_ClassicFunctionName[position-1] = tolower(cmdtext[position]);
    }
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: cmdtext[] validated.");
    #endif
    format(utils_CommandDebugFunc, sizeof(utils_CommandDebugFunc), "%s@dbg", utils_ClassicFunctionName);
    format(utils_ClassicFunctionName, sizeof(utils_ClassicFunctionName), "%s@cmd", utils_ClassicFunctionName);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Formatted function strings successfully.");
    #endif

    if(funcidx(utils_CommandDebugFunc) != -1)
    {
        CallLocalFunction(utils_CommandDebugFunc, "s", cmdtext);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Called custom debug function : %s.", utils_CommandDebugFunc);
    #endif

    while (cmdtext[position] == ' ') position++;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: position variable validated.");
    #endif
    if (!cmdtext[position])
    {
        if (utils_IsOnCmdPValid)
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 1");
            #endif
                return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext, 
                    CallLocalFunction(utils_ClassicFunctionName, "is", playerid, "\1"));
        }
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2");
        #endif
        return CallLocalFunction(utils_ClassicFunctionName, "is", playerid, "\1");      
    }
    if (utils_IsOnCmdPValid)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 3");
        #endif
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(utils_ClassicFunctionName, "is", playerid, cmdtext[position]));
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
    return CallLocalFunction(utils_ClassicFunctionName, "is", playerid, cmdtext[position]);
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
    if(utils_g_Script == 1)
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

        if (utils_IsOnCmdRValid && !CallLocalFunction("OnPrefixedCommandReceived", 
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
            utils_Prefix[MAX_FUNC_NAME],
            utils_FunctionName[MAX_FUNC_NAME];

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared variables!");
        #endif

        while(text[++position] > ' ')
        {
            utils_FunctionName[position-1] = tolower(text[position]);
        }

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) validated text[] and position;.");
            #endif

        format(utils_Prefix, sizeof(utils_Prefix),
            "%s@prx", utils_FunctionName);

        strdel(utils_Prefix, 0, 1);

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) generated cmd_prx funcname.");
            #endif

        format(utils_FunctionName, sizeof(utils_FunctionName), 
            "pc@%s", text);
        
        strdel(utils_FunctionName, 3, 4);

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
            if(utils_IsOnCmdPValid)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                return CallLocalFunction("OnPrefixedCommandPerformed", 
                            "isi", playerid, text, 
                            CallLocalFunction(utils_FunctionName, "is", playerid, "\1"));
            }
            #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
                #endif
            return CallLocalFunction(utils_FunctionName, "is", playerid, "\1");
        }
        if(utils_IsOnCmdPValid)
        {
            #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 2");
                #endif
            return CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(utils_FunctionName, "is", playerid, text[position]));
        }
        #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 3");
                #endif
        return CallLocalFunction(utils_FunctionName, "is", playerid, text[position]);
    
    }

    if(utils_g_ChatMode[playerid] == 1)
    {
        if (utils_IsOnCmdRValid && !CallLocalFunction("OnPrefixedCommandReceived", 
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
            utils_FunctionName[MAX_FUNC_NAME],
            utils_PrefixFuncName[MAX_FUNC_NAME];

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared variables!");
        #endif

        format(utils_PrefixFuncName, sizeof(utils_PrefixFuncName),
            "%s_prx", text);

        format(utils_FunctionName, sizeof(utils_FunctionName),
            "pc_%s", text);

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) string formattion finished.");
        #endif

        strdel(utils_PrefixFuncName, 0, 1);

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func.");
        #endif

        new utils_ActPrefix[MAX_FUNC_NAME];

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared active_prefix variable!");
        #endif

        format(utils_ActPrefix, sizeof(utils_ActPrefix), "%s", CallLocalFunction(utils_PrefixFuncName, ""));

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) formatted active prefix var.");
        #endif

        if(!strcmp(utils_ActPrefix, text[0]))
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) performed if-pattern check.");
            #endif
            strdel(utils_FunctionName, 3, 4);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func. ID: 1");
            #endif
            if(utils_IsOnCmdPValid)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(utils_FunctionName, "is", playerid, text));
                return 0;
            }
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
            #endif
            CallLocalFunction(utils_FunctionName, "is", playerid, text);
            return 0;
        }
    }
    if(utils_g_ChatMode[playerid] == 0)
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
    if(utils_g_ChatMode[playerid] == 0)
    {
        SendClientMessage(playerid, -1, "SERVER: Chat mode switched to custom-prefixed commands mode.");
        utils_g_ChatMode[playerid] = 1;
        return 1;
    }
    else if(utils_g_ChatMode[playerid] == 1)
    {
        SendClientMessage(playerid, -1, "SERVER: Chat mode switched to plain-text messages mode.");
        utils_g_ChatMode[playerid] = 0;
        return 1;
    }
    return 0;
}

static stock utils_ClearChatModeData(playerid)
{
    return utils_g_ChatMode[playerid] = 0;
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

#define prefixed%2command%0(%1,%3) \
    stock%0_prx(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

#else

#define pc@%0\32; pc@

#define PREFIXED__COMMAND__%0(%1,%3) \
    stock%0_prx(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

#endif