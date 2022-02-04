/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides creating
 *   various types of commands in
 *   various types of syntax.
 *
 *
 */

#if !defined _INC_SSCANF

    #warning [samp-detutils]: (warning) - Note that command processing works best with sscanf2 plugin, get it on github.com/y-less/sscanf-3.0

#endif

#if defined _zcmd_included || defined _I_ZCMD_INCLUDED || defined _INC_y_commands

    #error [samp-detutils]: (error) - 'd_commands' can't work together with ZCMD, y_commands or iZCMD.

#endif

#if defined detutils_sscanf

#undef detutils_sscanf

#endif

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

// For naming compatibility

#if !defined DETUTILS_OPENMP_COMPAT

    #define DETUTILS_OPENMP_COMPAT

#endif

#define DET_MAX_CMD 10000

// For parsing.
enum enum_CommandData
{
    DET_REF, 
    DET_EXT, 
    DET_ARR, 
    DET_STR, 
    DET_NUM
}

new g_CommandCache[DET_MAX_CMD][enum_CommandData];

#if !defined MAX_PREFIX_LENGTH

    #define MAX_PREFIX_LENGTH 10

#endif

#include "d_commands_macros"

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

#if defined DETUTILS_OPENMP_COMPAT

    #define GetSlashCommandType Command_GetSlashType

#endif

stock Command_GetSlashType(const cmdtext[])
{
    new cmdname[MAX_FUNC_NAME];
    format(cmdname, sizeof cmdname, "cty_%s", cmdtext);
    if(funcidx(cmdname) == -1) return INVALID_SLASH_COMMAND_TYPE; 
    // If slash command does not exist or command is not slash command (above)
    return CallLocalFunction(cmdname, "");
}

DETUTILS_DECL__ var:g_CaseSensivity<> = 0;

stock ToggleCommandCaseSensivity(bool:toggle)
{
    if(toggle == true)
    {
        DETUTILS@g_CaseSensivity = 1;
    }
    else if(toggle == false)
    {
        DETUTILS@g_CaseSensivity = 0;
    }
    return 1;
}

static Data_g_ChatMode[MAX_PLAYERS];

forward OnCommandStateChange(playerid, cmdtext[], stateid);
forward OnPrefixedCommandStateChange(playerid, cmdtext[], stateid);
/*
stock CallLocalCommand(const command[], const specifiers[], integer, const string[])
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
                    integer, 
                    string
                )
        ;
}

static Data_g_ChatMode[MAX_PLAYERS];

stock CallRemoteCommand(const command[], const specifiers[], integer, const string[])
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
                    integer, 
                    string
                )
        ;

}

stock CallRemotePrefixedCommand(const command[], const specifiers[], integer, const string[])
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
                    integer, 
                    string
                )
        ;

}

stock CallLocalPrefixedCommand(const command[], const specifiers[], integer, const string[])
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
                    integer, 
                    string
                )
        ;

}*/

#define COMMAND_TYPE_LOCAL 0
#define COMMAND_TYPE_REMOTE 1
#define COMMAND_TYPE_LOCAL_PREFIXED 2
#define COMMAND_TYPE_REMOTE_PREFIXED 3

#if defined DETUTILS_OPENMP_COMPAT

    #define CallCommand Command_Call

#endif

#if defined _INC_code_parse_inc

stock Command_Call(const cmdtext[], const playerid, const params[], const type = COMMAND_TYPE_LOCAL)
{
    if(type == COMMAND_TYPE_LOCAL)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "cmd_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 0");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_REMOTE)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "cmd_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 1");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_LOCAL_PREFIXED)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "pc_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 2");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_REMOTE_PREFIXED)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "pc_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 3");
        #endif
        return CallRemoteFunction(command_name, "is", playerid, params);   
    }
    return 1;
}

#elseif !defined _INC_code_parse_inc

stock Command_Call(const cmdtext[], const playerid, const params[], const type = COMMAND_TYPE_LOCAL)
{
    if(type == COMMAND_TYPE_LOCAL)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "cmd_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 0");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_REMOTE)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "cmd_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 1");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_LOCAL_PREFIXED)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "pc_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 2");
        #endif
        return CallLocalFunction(command_name, "is", playerid, params);   
    }
    if(type == COMMAND_TYPE_REMOTE_PREFIXED)
    {
        new command_name[MAX_FUNC_NAME];
        format(command_name, MAX_FUNC_NAME, "pc_%s", cmdtext);
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - Command_Call called successfully. ID: 3");
        #endif
        return CallRemoteFunction(command_name, "is", playerid, params);   
    }
    return 1;
}

#endif

//#define GetCommandDebugState%1(%2) %1debugged_stateid%2

#if !defined OnPlayerCommandReceived

    forward OnPlayerCommandReceived(playerid, cmdtext[]);

#endif

#if !defined OnPlayerCommandPerformed

    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);

#endif

#define COMMAND_DEBUG_STATE_INVALID -1
#define COMMAND_DEBUG_STATE_RECEIVED 0
#define COMMAND_DEBUG_STATE_READY 1
#define COMMAND_DEBUG_STATE_PERFORMED 2
#define COMMAND_DEBUG_STATE_STOPPED 3

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
    LoadDETUtilsScript(DETUTILS_SCRIPT_COMMANDS);
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

    new cmd[256+1];
    new idx;
    cmd = strtok(cmdtext, idx);
    new
        position,
        _ClassicFunctionName[MAX_FUNC_NAME],
        _CommandDebugFunc[MAX_FUNC_NAME],
        DET_ParseFunc[MAX_FUNC_NAME];

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
    
    format(_CommandDebugFunc, sizeof(_CommandDebugFunc), "%s", "OnCommandStateChange");
    format(DET_ParseFunc, sizeof(DET_ParseFunc), "P@_%s", _ClassicFunctionName);
    format(_ClassicFunctionName, sizeof(_ClassicFunctionName), "cmd_%s", _ClassicFunctionName);

    printf("*** [samp-detutils]: (cmd parse) - Calling parse function: '%s'", DET_ParseFunc);

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Formatted function strings successfully.");
    #endif

    new Continue = CallLocalFunction(DET_ParseFunc, "");

    if(Continue != 1)
    {
        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_STOPPED);
        }
        return 0;
    }

    if(funcidx(_CommandDebugFunc) != -1)
    {
        CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_RECEIVED);
    }

    #if defined detutils_debug
    printf("[samp-detutils]: (debug) - opct :: Called custom debug function : %s.", _CommandDebugFunc);
    #endif

    while (cmdtext[position] == ' ') position++;

    if(funcidx(_CommandDebugFunc) != -1)
    {
        CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_READY);
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
                    CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
                }
                    #if !defined detutils_sscanf
                    return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext,
                    CallLocalFunction(_ClassicFunctionName, "is", playerid, "\1"));
                    #else
                    return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext,
                    CallLocalFunction(_ClassicFunctionName, "is", playerid, cmd));
                    #endif
        }
        #if defined detutils_debug
        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
        }
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2");
        #endif
        #if !defined detutils_sscanf
        return CallLocalFunction(_ClassicFunctionName, "is", playerid, "\1");
        #else
        return CallLocalFunction(_ClassicFunctionName, "is", playerid, cmd);
        #endif
    }
    if (_IsOnCmdPValid)
    {
        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 3");
        #endif
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, cmdtext, COMMAND_DEBUG_STATE_PERFORMED);
            }
                #if !defined detutils_sscanf
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(_ClassicFunctionName, "is", playerid, cmdtext[position]));
                #else
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(_ClassicFunctionName, "is", playerid, cmd));
                #endif
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

#define DETUTILS_FIX_COMMANDS 1 // random shit

enum enum_PlayerCmdData
{
    PassedPrefix[10]
}

new g_PlayerCmdData[MAX_PLAYERS][enum_PlayerCmdData];

////////////////////////////////////////////////////

public OnPlayerText(playerid, text[])
{
    if(Data_g_ChatMode[playerid] == 1)
    {
        if(funcidx("OnPrefixedCommandReceived") != -1)
        {
            CallLocalFunction("OnPrefixedCommandReceived", "is", playerid, text);
        }
        
        new _CommandDebugFunc[32];

        format(_CommandDebugFunc,
            sizeof(_CommandDebugFunc), 
            "OnPrefixedCommandStateChange");

        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_RECEIVED);
        }

        new PrxFuncName[32], CmdFuncName[32], len;

        format(PrxFuncName, sizeof PrxFuncName,
            "prx_%s", text);
    
        strdel(PrxFuncName, 4, 5);

        format(CmdFuncName, sizeof CmdFuncName,
            "pc_%s", text);

        strdel(CmdFuncName, 3, 4);

        #if defined detutils_complete_error_boom
        for(i = 0; i < MAX_FUNC_NAME; i++)
        {
            if(strcmp(PrxFuncName[i], " ", false))
            {
                nullpos = i;
                break;
            }
        }

        size = sizeof PrxFuncName;

        strmid(params, PrxFuncName, nullpos, 32, 32);

        strdel(PrxFuncName, nullpos, size);

        size = sizeof CmdFuncName;

        nullpos = (nullpos - 1);

        strdel(CmdFuncName, nullpos, size);
        #endif
        CallLocalFunction(PrxFuncName, "i", playerid);

        /*CallLocalFunction("OnPlayerPassCommandPrefix", "isss", 
            playerid, text, text[0], g_PlayerCmdData[playerid][PassedPrefix][0]);*/
        

        //new PrefixPass = CallLocalFunction("OnPlayerPassCommandPrefix", "isss", playerid, text, text[0], g_PlayerCmdData[playerid][PassedPrefix]);

        new expcprx[10];
        if(funcidx(PrxFuncName) != -1) format(expcprx, sizeof expcprx,
            "%s", g_PlayerCmdData[playerid][PassedPrefix][0]);

        if(funcidx(PrxFuncName) == -1) format(expcprx, sizeof expcprx, " ");

        new prx[10];
        format(prx, sizeof prx,
            "%c", text[0]);

        if(funcidx("OnPlayerPassCommandPrefix") != -1)
        {
            if(OnPlayerPassCommandPrefix(
                playerid, text, prx, expcprx
            ) != 1)
            {
                #if defined detutils_debug
                    printf("[samp-detutils]: (debug) - opt :: Passed prefix returned 0");
                #endif
                if(funcidx(_CommandDebugFunc) != -1)
                {
                    CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_STOPPED);
                }
                return 0;
            }
        }

        #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: PrxFuncName: %s / CmdFuncName: %s / Passed prefix: %s", 
                PrxFuncName, CmdFuncName, g_PlayerCmdData[playerid][PassedPrefix]);
        #endif

        len = strlen(g_PlayerCmdData[playerid][PassedPrefix]);

        if(len < 1)
        {
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_INVALID);
            }
        }

        if(g_PlayerCmdData[playerid][PassedPrefix][0] == text[0])
        //if(strcmp(g_PlayerCmdData[playerid][PassedPrefix], text[0], false))
        {
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_READY);
            }

            CallLocalFunction(CmdFuncName, "is", playerid, text);

            if(funcidx("OnPrefixedCommandPerformed") != -1)
            {
                CallLocalFunction("OnPrefixedCommandPerformed", "isi", playerid, text, 1);
            }

            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
            }
            return 1;
        }
        else
        {
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
            }

            if(funcidx("OnPrefixedCommandPerformed") != -1)
            {
                return CallLocalFunction("OnPrefixedCommandPerformed", "isi", playerid, text, 0);
            }
            return 1;
        }
    }
    if(Data_g_ChatMode[playerid] == 0 && funcidx("a_cmd_OnPlayerText") != -1)
    {
        CallLocalFunction("a_cmd_OnPlayerText", "is", playerid, text);
    }
    return 1;
}

////////////////////////////////////////////////////

#if defined detutils_complete_error_boom

public OnPlayerText(playerid, text[])
{
    //#if defined DETUTILS_FIX_COMMANDS
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

     ///////////////////////////////

    if(Data_g_ChatMode[playerid] == 1)
    {
        if (funcidx("OnPrefixedCommandReceived") != -1 && !CallLocalFunction("OnPrefixedCommandReceived", 
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
            _PrefixFuncName[MAX_FUNC_NAME],
            _CommandDebugFunc[32];
            //_CommandParameters[64],
            //_nullpos;

        format(_CommandDebugFunc,
            sizeof(_CommandDebugFunc), 
            "OnPrefixedCommandStateChange");

        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_RECEIVED);
        }

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

        if(funcidx(_PrefixFuncName) != -1)
        {
            format(_ActPrefix, sizeof(_ActPrefix), "%s", CallLocalFunction(_PrefixFuncName, ""));

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) formatted active prefix var.");
            #endif
        }
        else if(funcidx(_PrefixFuncName) == -1)
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: Prefix function name for command %s doesn't exist.", text);
            #endif
            new textmsg[256];
            format(textmsg, 256, DETUTILS_TEXT_UNK_PRX_FUNC, text);
            d_SendWarningMessage(playerid, textmsg); 
        }

        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_READY);
        }

        new l_CommandPrefix[1];
        format(l_CommandPrefix, 1, "%s", text[0]);

        if(!strcmp(g_PlayerCmdData[playerid][PassedPrefix], l_CommandPrefix, false)) // for some reason, text[0] was returning a whole string ???
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) performed if-pattern check.");
            printf("[samp-detutils]: (debug) - opt :: _ActPrefix: %s / text[0]: %s", g_PlayerCmdData[playerid][PassedPrefix], l_CommandPrefix);
            #endif
            strdel(_FunctionName, 3, 4);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func. ID: 1");
            #endif

            /*for(new i = 0; i < sizeof _FunctionName; i++)
            {
                if(strfind(_FunctionName[i], " "))
                {
                    _nullpos = i;
                    break;
                }
            }

            strdel(_FunctionName, _nullpos, sizeof _FunctionName);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: Command parameters var : %s", _CommandParameters);
            #endif
            */
        
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: _PrefixFuncName: %s / _FunctionName: %s", _PrefixFuncName, _FunctionName);
            #endif

            if(funcidx("OnPrefixedCommandPerformed") != -1)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(_FunctionName, "iss", playerid, text));

                if(funcidx(_CommandDebugFunc) != -1)
                {
                    CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
                }
                return 0;
            }
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
            #endif
            CallLocalFunction(_FunctionName, "iss", playerid, text);
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
            }
            return 0;
        }
    }
    if(Data_g_ChatMode[playerid] == 0)
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

public OnPlayerText(playerid, text[])
{
    #if defined DETUTILS_FIX_COMMANDS
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

     ///////////////////////////////

    if(Data_g_ChatMode[playerid] == 1)
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
            _PrefixFuncName[MAX_FUNC_NAME],
            _CommandDebugFunc[32],
            _CommandParameters[64],
            _nullpos;

        format(_CommandDebugFunc,
            sizeof(_CommandDebugFunc), 
            "OnPrefixedCommandStateChange");

        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_RECEIVED);
        }

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
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) declared active prefix variable!");
        #endif

        format(_ActPrefix, sizeof(_ActPrefix), CallLocalFunction(_PrefixFuncName, ""));

        #if defined detutils_debug
        printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) formatted active prefix var.");
        #endif

        if(funcidx(_CommandDebugFunc) != -1)
        {
            CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_READY);
        }

        if(!strcmp(_ActPrefix, text[0]))
        {
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) performed if-pattern check.");
            #endif
            strdel(_FunctionName, 3, 4);
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) called strdel func. ID: 1");
            #endif

            for(new i = 0; i < sizeof _FunctionName; i++)
            {
                if(strfind(_FunctionName[i], " "))
                {
                    _nullpos = i;
                    break;
                }
            }

            format(_CommandParameters, sizeof _CommandParameters,
                "%s%s%s%s%s%s%s",
                _FunctionName[_nullpos],
                _FunctionName[_nullpos+1],
                _FunctionName[_nullpos+2],
                _FunctionName[_nullpos+3],
                _FunctionName[_nullpos+4],
                _FunctionName[_nullpos+5],
                _FunctionName[_nullpos+6]);

            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: Command parameters var : %s", _CommandParameters);
            #endif
            //strdel(_FunctionName, _nullpos, sizeof _FunctionName);
        
            if(_IsOnCmdPValid)
            {
                #if defined detutils_debug
                printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 0");
                #endif
                CallLocalFunction("OnPrefixedCommandPerformed", 
                    "isi", playerid, text, 
                    CallLocalFunction(_FunctionName, "iss", playerid, text));

                if(funcidx(_CommandDebugFunc) != -1)
                {
                    CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
                }
                return 0;
            }
            #if defined detutils_debug
            printf("[samp-detutils]: (debug) - opt :: OnPlayerText(playerid, text[]) returned function call. ID: 1");
            #endif
            CallLocalFunction(_FunctionName, "iss", playerid, text);
            if(funcidx(_CommandDebugFunc) != -1)
            {
                CallLocalFunction(_CommandDebugFunc, "isi", playerid, text, COMMAND_DEBUG_STATE_PERFORMED);
            }
            return 0;
        }
    }
    if(Data_g_ChatMode[playerid] == 0)
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
    #endif
    #if !defined DETUTILS_FIX_COMMANDS
    return data check:bool;
    #endif
}

#endif

#if defined _ALS_OnPlayerText
    #undef OnPlayerText
#else
    #define _ALS_OnPlayerText
#endif

#define OnPlayerText a_cmd_OnPlayerText

forward a_cmd_OnPlayerText(playerid, text[]);

#if defined detutils_complete_error_boom

#if !defined DETUTILS_COMPATIBILITY_MODE

command chatmode(playerid, params[])
{
    if(Data_g_ChatMode[playerid] == 0)
    {
        //SendClientMessage(playerid, -1, "SERVER: Chat mode switched to custom-prefixed commands mode.");
        Data_g_ChatMode[playerid] = 1;
        return 1;
    }
    else if(Data_g_ChatMode[playerid] == 1)
    {
        //SendClientMessage(playerid, -1, "SERVER: Chat mode switched to plain-text messages mode.");
        Data_g_ChatMode[playerid] = 0;
        return 1;
    }
    return 0;
}

#else

COMMAND__ chatmode(playerid, params[])
{
    if(Data_g_ChatMode[playerid] == 0)
    {
        //SendClientMessage(playerid, -1, "SERVER: Chat mode switched to custom-prefixed commands mode.");
        Data_g_ChatMode[playerid] = 1;
        return 1;
    }
    else if(Data_g_ChatMode[playerid] == 1)
    {
        //SendClientMessage(playerid, -1, "SERVER: Chat mode switched to plain-text messages mode.");
        Data_g_ChatMode[playerid] = 0;
        return 1;
    }
    return 0;
}

#endif

#endif // I hate this compatibility mode xd, making new ones

forward cmd_chatmode(playerid, params[]); 
public cmd_chatmode(playerid, params[])
{
    if(Data_g_ChatMode[playerid] == 0)
    {
        SendClientMessage(playerid, -1, DETUTILS_TEXT_CHATMODE_PRX);
        Data_g_ChatMode[playerid] = 1;
        return 1;
    }
    else if(Data_g_ChatMode[playerid] == 1)
    {
        SendClientMessage(playerid, -1, DETUTILS_TEXT_CHATMODE_MSG);
        Data_g_ChatMode[playerid] = 0;
        return 1;
    }
    return 0;
}

static stock _ClearChatModeData(playerid)
{
    return Data_g_ChatMode[playerid] = 0;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect a_cmd_OnPlayerDisconnect

forward a_cmd_OnPlayerDisconnect(playerid, reason);

////////////////////////////////////////////////////////

/*

#define prefixed%2command%0(%1)%4[%3] \
    stock prx_%0(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

#define @newk_PrefixedCommand:%0(%1)%4[%3] \
    stock prx_%0(){new p[1];format(p,sizeof(p),%3);return p;}forward pc_%0(%1);public pc_%0(%1)

*/

////////////////////////////////////LMAO////////////////////

#if defined detutils_complete_error_boom

#if !defined DETUTILS_COMPATIBILITY_MODE

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

#endif

#define CHAT_MODE_PLAIN_TEXT_MESSAGES 0
#define CHAT_MODE_PREFIXED_COMMANDS 1

stock GetPlayerChatMode(playerid)
{
    if(Data_g_ChatMode[playerid] == CHAT_MODE_PLAIN_TEXT_MESSAGES)
    {
        return CHAT_MODE_PLAIN_TEXT_MESSAGES;
    }
    else if(Data_g_ChatMode[playerid] == CHAT_MODE_PREFIXED_COMMANDS)
    {
        return CHAT_MODE_PREFIXED_COMMANDS;
    }
    else return -1;
}

stock void:SetPlayerChatMode(playerid, chatmode)
{
    if(chatmode == CHAT_MODE_PLAIN_TEXT_MESSAGES)
    {
        Data_g_ChatMode[playerid] = 0;
    }
    else if(chatmode == CHAT_MODE_PREFIXED_COMMANDS)
    {
        Data_g_ChatMode[playerid] = 1;
    }
}

forward OnPlayerPassCommandPrefix(playerid, cmdtext[], passedprefix[], expectedprefix[]);