/*
 * SA:MP | DEntisT's Utilites 
 * command processor
 *
 *
 * Thanks to:
 *
 * @Zeex - zCMD ideas
 *
 * @DEntisT (me) - upgrades and bug fixes 
 *
 */

#if defined DEV_MODE

#include <a_samp>

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
 
#define MAX_FUNC_NAME (32)

#if !defined A_CMDS_COMPATIBILITY_MODE

#define command%0(%1) \
    forward%0@cmd(%1);public%0@cmd(%1)

#define alias%5command%0(%1[%3]%4)=%2; \
    forward%0@cmd(%1[]);%3public%0@cmd(%1[]){return %2@cmd(%1)%4;%5}

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
    return CallLocalFunction
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

static
        bool:is_opcr_valid = false,
        bool:is_opcp_valid = false;

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    is_opcr_valid = funcidx("OnPlayerCommandReceived") != -1;
    is_opcp_valid = funcidx("OnPlayerCommandPerformed") != -1;

    if (funcidx("a_cmd_processor_OnGameModeInit") != -1)
    {
        return CallLocalFunction("a_cmd_processor_OnGameModeInit", "");
    }      
    return 1;
}

#else

public OnFilterScriptInit()
{
    is_opcr_valid = funcidx("OnPlayerCommandReceived") != -1;
    is_opcp_valid = funcidx("OnPlayerCommandPerformed") != -1;

    if (funcidx("a_cmd_OnFilterScriptInit") != -1)
    {
        return CallLocalFunction("a_cmd_OnFilterScriptInit", "");
    }
    return 1;
}

#endif
 
public OnPlayerCommandText(playerid, cmdtext[])
{
    if (is_opcr_valid && !CallLocalFunction("OnPlayerCommandReceived", 
        "is", 
        playerid, 
        cmdtext))
    {
        return 1;
    }
    new
        position,
        function_name[MAX_FUNC_NAME],
        function_debug[MAX_FUNC_NAME];

    while (cmdtext[++position] > ' ')
    {
        function_name[position-1] = tolower(cmdtext[position]);
    }
    format(function_debug, sizeof(function_debug), "%s@dbg", function_name);
    format(function_name, sizeof(function_name), "%s@cmd", function_name);

    if(funcidx(function_debug) != -1)
    {
        CallLocalFunction(function_debug, "s", cmdtext);
    }

    while (cmdtext[position] == ' ') position++;
    if (!cmdtext[position])
    {
        if (is_opcp_valid)
        {
                return CallLocalFunction("OnPlayerCommandPerformed", 
                    "isi", 
                    playerid, 
                    cmdtext, 
                    CallLocalFunction(function_name, "is", playerid, "\1"));
        }
        return CallLocalFunction(function_name, "is", playerid, "\1");      
    }
    if (is_opcp_valid)
    {
            return CallLocalFunction("OnPlayerCommandPerformed", 
                "isi", 
                playerid, 
                cmdtext, 
                CallLocalFunction(function_name, "is", playerid, cmdtext[position]));
    }

    if (funcidx("a_OnPlayerCommandText") != -1)
    {
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

#else

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_cmd_OnFilterScriptInit

forward a_cmd_OnFilterScriptInit();

#endif
