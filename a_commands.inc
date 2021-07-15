/*
 * SA-MP command processor
 *
 * - "Built-in" command processor
 *    for SA:MP stdlib with 
 *    actual PAWN syntax.
 *
 * Thanks to:
 *
 * @Zeex - zCMD ideas
 *
 * @DEntisT (me) - upgrades and bug fixes 
 *
 */

#include <a_samp>

#if defined _a_cmd_processor_included
        #endinput
#endif 
#define _a_cmd_processor_included
 
#define MAX_FUNC_NAME (32)

#define command%0(%1) \
 	forward%0@cmd(%1);public%0@cmd(%1)

#define alias%5command%0(%1[%3]%4)=%2; \
 	forward%0@cmd(%1[]);%3public%0@cmd(%1[]){return %2@cmd(%1)%4;%5}

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

#define CMD:%0(%1) \
    forward %0@cmd(%1); public %0@cmd(%1)

#if !defined isnull
        #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

forward OnPlayerCommandReceived(playerid, cmdtext[]);
forward OnPlayerCommandPerformed(playerid, cmdtext[], success);
 
static
        bool:is_opcr_valid = false,
        bool:is_opcp_valid = false;
 
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
 
#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit a_cmd_processor_OnGameModeInit
forward a_cmd_processor_OnGameModeInit();
 
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
        function_name[MAX_FUNC_NAME];

    while (cmdtext[++position] > ' ')
    {
        function_name[position-1] = tolower(cmdtext[position]);
    }
    format(function_name, sizeof(function_name), "%s@cmd", function_name);

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
 
#if defined _ALS_OnPlayerCommandText
    #undef OnPlayerCommandText
#else
    #define _ALS_OnPlayerCommandText
#endif
#define OnPlayerCommandText a_OnPlayerCommandText
forward a_OnPlayerCommandText(playerid, cmdtext[]);
