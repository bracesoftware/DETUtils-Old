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

#else

#define COMMAND__%0(%1) \
    forward%0@cmd(%1);public%0@cmd(%1)

#define ALIAS__COMMAND__%0(%1[%3]%4)%5=%2; \
    forward%0@cmd(%1[]);%3public%0@cmd(%1[]){return %2@cmd(%1)%4;%5}

#define DEBUG__COMMAND__%0(%1) \
    forward%0@dbg(debugged_cmdtext[]);%1public%0@dbg(debugged_cmdtext[])

#define GETDBGCMD__%0(%1) %0debugged_cmdtext%1

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
        bool:utils_IsOnPlayerCmdReceivedValid = false,
        bool:utils_IsOnPlayerCmdPerformValid = false;

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    utils_IsOnPlayerCmdReceivedValid = funcidx("OnPlayerCommandReceived") != -1;
    utils_IsOnPlayerCmdPerformValid = funcidx("OnPlayerCommandPerformed") != -1;

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

public OnFilterScriptInit()
{
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - onfsinit :: Commands loading finished.");
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_commands.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded();
    utils_IsOnPlayerCmdReceivedValid = funcidx("OnPlayerCommandReceived") != -1;
    utils_IsOnPlayerCmdPerformValid = funcidx("OnPlayerCommandPerformed") != -1;

    if (funcidx("a_cmd_OnFilterScriptInit") != -1)
    {
        return CallLocalFunction("a_cmd_OnFilterScriptInit", "");
    }
    return 1;
}

#endif
 
public OnPlayerCommandText(playerid, cmdtext[])
{
    if (utils_IsOnPlayerCmdReceivedValid && !CallLocalFunction("OnPlayerCommandReceived", 
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
        function_name[MAX_FUNC_NAME],
        function_debug[MAX_FUNC_NAME];

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Successfully declared variables.");
    #endif

    while (cmdtext[++position] > ' ')
    {
        function_name[position-1] = tolower(cmdtext[position]);
    }
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: cmdtext[] validated.");
    #endif
    format(function_debug, sizeof(function_debug), "%s@dbg", function_name);
    format(function_name, sizeof(function_name), "%s@cmd", function_name);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Formatted function strings successfully.");
    #endif

    if(funcidx(function_debug) != -1)
    {
        CallLocalFunction(function_debug, "s", cmdtext);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Called custom debug function : %s.", function_debug);
    #endif

    while (cmdtext[position] == ' ') position++;
    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: position variable validated.");
    #endif
    if (!cmdtext[position])
    {
        if (utils_IsOnPlayerCmdPerformValid)
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 1");
            #endif
                return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext, 
                    CallLocalFunction(function_name, "is", playerid, "\1"));
        }
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2");
        #endif
        return CallLocalFunction(function_name, "is", playerid, "\1");      
    }
    if (utils_IsOnPlayerCmdPerformValid)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 3");
        #endif
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(function_name, "is", playerid, cmdtext[position]));
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
    return CallLocalFunction(function_name, "is", playerid, cmdtext[position]);
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