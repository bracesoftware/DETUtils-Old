/*
 *
 * DETUTILS COMMANDS
 *
 *
 * Macros
 *
 *
 */

#include "d_commands_setup"

#define DETUTILS_CMD_MACROS

#define cmd_%0\32; cmd_
#define dbg_%0\32; dbg_
#define cmd_func_%0\32; cmd_func_
#define cmdf_%0\32; cmdf_
#define cmda_%0\32; cmda_
#define role_%0\32; role_
#define pc_%0\32; pc_
#define prx_%0\32; prx_

#define @cmddecorator_%0\32; @cmddecorator_

#define @command%0(%1.type%2= @cmddecorator_

#define @cmddecorator_SLASH_COMMAND%2)%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define @cmddecorator_ALIAS_COMMAND%3)%0(%1[%4])=%2; \
    forward cmd_%0(%1[]); public cmd_%0(%1[]){return cmd_%2(%1);}

#define @cmddecorator_ADMIN_COMMAND%3)%0(%1,%2[%5]%4) DETUTILSCMD_ACMD_DECL__|%0|%1|%2| \
    DETUTILSCMD_ACMD_CHECK__<%1>|%0,%2| DETUTILSCMD_ACMD_CMDFRET__|%0,<%1>,%2|

#define @cmddecorator_FLAGGED_COMMAND%4,%5.flag%6=%3)%0(%1,%2[%7]%8) DETUTILSCMD_FCMD_ENTRY__|%0|(%1,%2) \
    DETUTILSCMD_FLAG_CHECK__|%3|<%0>(%1,%2) DETUTILSCMD_CMD_FUNC__|%0|<%1,%2>

#define @flag(%0.dependencies%4=%5(%3)%6)%1(%2); \
    stock bool:role_%1(%2) { if(!(%3)) return false; else if(%3) return true; return false;}

#define @cmddecorator_PREFIXED_COMMAND%5,%6.prefix%7=%3)%0(%1) DETUTILSCMD_PRX_CALL__|%0| \
    DETUTILSCMD_PRX_FUNC__<%3> DETUTILSCMD_PC_DECL__|%0|%1|    

#define @prefix%2(%3.value%4=%1)%0(%5)%6; \
    stock const %0[MAX_PREFIX_LENGTH]=%1;
/*
#define @dependency(someshit thing); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }
*/

/*
useless
                                                                               
88b           d88                                                              
888b         d888                                                              
88`8b       d8'88                                                              
88 `8b     d8' 88  ,adPPYYba,   ,adPPYba,  8b,dPPYba,   ,adPPYba,   ,adPPYba,  
88  `8b   d8'  88  ""     `Y8  a8"     ""  88P'   "Y8  a8"     "8a  I8[    ""  
88   `8b d8'   88  ,adPPPPP88  8b          88          8b       d8   `"Y8ba,   
88    `888'    88  88,    ,88  "8a,   ,aa  88          "8a,   ,a8"  aa    ]8I  
88     `8'     88  `"8bbdP"Y8   `"Ybbd8"'  88           `"YbbdP"'   `"YbbdP"'  
                                                                               
                                                                               
*/

#if defined DETUTILS_CMD_MACROS

 #if defined _d_cmd_processor_included
        #endinput
#endif 
#define _d_cmd_processor_included
 
#if !defined MAX_FUNC_NAME

#define MAX_FUNC_NAME (32)

#endif
 
#if defined DETUTILS_COMPAT

#define command%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)
 
#define @newk_Command:%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)//same as thing over this
 
#define alias%5command%0(%1[%3]%4)=%2; \
    forward public cmda_%0(); public cmda_%0(){return 1;}forward cmd_%0(%1[]);%3public cmd_%0(%1[]){return cmd_%2(%1)%4;%5}

#define @newk_CommandAlias:%0(%1[%3]%4)=%2; \
    forward public cmda_%0(); public cmda_%0(){return 1;}forward cmd_%0(%1[]);%3 public cmd_%0(%1[]){return cmd_%2(%1)%4;}

#define CMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define YCMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define COMMAND CMD

#define cmd CMD

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define admin%5command%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define @newk_AdminCommand:%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)
 

#define role%5command%0(%7Role:%6,%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define @newk_RoleCommand:%0(%7Role:%6,%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3 public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])
 

#define create%0role%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }

#define @newk_Role:%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }
 
#define pc_%0\32; pc_
#define prx_%0\32; prx_

#define prefixed%2command%0(%4Prefix:%3,%1) \
    prx_%0(playerid); public prx_%0(playerid){ strmid(g_PlayerCmdData[playerid][PassedPrefix], %3, 0, MAX_PREFIX_LENGTH, MAX_PREFIX_LENGTH); return MAX_PREFIX_LENGTH;}forward pc_%0(%1);public pc_%0(%1)

#define @newk_PrefixedCommand:%0(%4Prefix:%3,%1) \
    prx_%0(playerid); public prx_%0(playerid){ strmid(g_PlayerCmdData[playerid][PassedPrefix], %3, 0, MAX_PREFIX_LENGTH, MAX_PREFIX_LENGTH); return MAX_PREFIX_LENGTH;}forward pc_%0(%1);public pc_%0(%1)

#define @newk_Prefix:%0=%1; \
    stock const %0[MAX_PREFIX_LENGTH]=%1;

#elseif !defined DETUTILS_COMPAT

#define cmd_%0\32; cmd_
#define dbg_%0\32; dbg_
#define cmd_func_%0\32; cmd_func_
#define cmdf_%0\32; cmdf_
#define cmda_%0\32; cmda_
#define role_%0\32; role_

#define command%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)
 
#define Command:%0(%1) \
    forward cmd_%0(%1);public cmd_%0(%1)//same as thing over this
 
#define alias%5command%0(%1[%3]%4)=%2; \
    forward public cmda_%0(); public cmda_%0(){return 1;}forward cmd_%0(%1[]);%3public cmd_%0(%1[]){return cmd_%2(%1)%4;%5}

#define CommandAlias:%0(%1[%3]%4)=%2; \
    forward public cmda_%0(); public cmda_%0(){return 1;}forward cmd_%0(%1[]);%3 public cmd_%0(%1[]){return cmd_%2(%1)%4;}

#define CMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define YCMD:%0(%1) \
    forward cmd_%0(%1); public cmd_%0(%1)

#define COMMAND CMD

#define cmd CMD

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define admin%5command%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define AdminCommand:%0(%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if(!IsPlayerAdmin(%1)) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)
 

#define role%5command%0(%7Role:%6,%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;%5} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[]%5)

#define RoleCommand:%0(%7Role:%6,%1,%2[%3]%4) \
    forward cmd_%0(%1,%2[]);%3 public cmd_%0(%1,%2[]){if( !role_%6(%1) ) return 0; return  cmd_func_%0(%1,%2)%4;} \
    forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])
 

#define create%0role%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }

#define Role:%1(%2,%3); \
    stock bool: role_%1(%2) { if(!(%3)) return false; else return true; }
 
#define pc_%0\32; pc_
#define prx_%0\32; prx_

#define prefixed%2command%0(%4Prefix:%3,%1) \
    prx_%0(playerid); public prx_%0(playerid){ strmid(g_PlayerCmdData[playerid][PassedPrefix], %3, 0, MAX_PREFIX_LENGTH, MAX_PREFIX_LENGTH); return MAX_PREFIX_LENGTH;}forward pc_%0(%1);public pc_%0(%1)

#define PrefixedCommand:%0(%4Prefix:%3,%1) \
    prx_%0(playerid); public prx_%0(playerid){ strmid(g_PlayerCmdData[playerid][PassedPrefix], %3, 0, MAX_PREFIX_LENGTH, MAX_PREFIX_LENGTH); return MAX_PREFIX_LENGTH;}forward pc_%0(%1);public pc_%0(%1)

#define Prefix:%0=%1; \
    stock const %0[MAX_PREFIX_LENGTH]=%1;

#endif
// Code

#define @cmds_%0\32; @cmds_

#define keyword @cmds_
 
#define @cmds_public%0(%1) %0(%1);public%0(%1)
#define @cmds_forward%0(%1) forward%0(%1)

// DAMN CODE
 
#if !defined DETUTILS_COMPATIBILITY_MODE

// DETUTILS_COMPAT

// COMPATIBILITY MODE BELOW IS COMPLETELY USELESS AND IS UNUSABLE!
#else // If compatibility mode is ON
 
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

#endif