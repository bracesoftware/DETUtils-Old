/*
 *
 * DETUTILS COMMANDS
 *
 *
 * Macro setup
 *
 *
 */

#define DETUTILSCMD_FCMD_ENTRY__|%0|(%1,%2) forward cmd_%0(%1,%2[]); public cmd_%0(%1,%2[])
#define DETUTILSCMD_FLAG_CHECK__|%3|<%0>(%1,%2) { if( !role_%3(%1) ) return 0; return cmd_func_%0(%1,%2); }
#define DETUTILSCMD_CMD_FUNC__|%0|<%1,%2> forward cmd_func_%0(%1,%2[]); public cmd_func_%0(%1,%2[])
#define DETUTILSCMD_PC_DECL__|%0|%1| forward pc_%0(%1);public pc_%0(%1)
#define DETUTILSCMD_PRX_FUNC__<%3> {strmid(g_PlayerCmdData[playerid][PassedPrefix], %3, 0, MAX_PREFIX_LENGTH, MAX_PREFIX_LENGTH); return MAX_PREFIX_LENGTH;}
#define DETUTILSCMD_PRX_CALL__|%0| forward prx_%0(playerid); public prx_%0(playerid)
#define DETUTILSCMD_ACMD_DECL__|%0|%1|%2| forward cmd_%0(%1,%2[]); public cmd_%0(%1,%2[])
#define DETUTILSCMD_ACMD_CHECK__<%1>|%0,%2| {if(!IsPlayerAdmin(%1)) return 0; return CallLocalFunction("cmd_func_"#%0, "is", %1, %2);}//return cmd_func_%0(%1,%2);}
#define DETUTILSCMD_ACMD_CMDFRET__|%0,<%1>,%2| forward cmd_func_%0(%1,%2[]);public cmd_func_%0(%1,%2[])
#define DETUTILSCMD_DECL_CMD__<%0|%1> forward cmd_%0(%1); public cmd_%0(%1)
#define DETUTILSCMD_DECL_CMD__B<%0,%1> forward cmd_%0(%1[]); public cmd_%0(%1[])
#define DETUTILSCMD_RET_CMD__B|%2,%1| {return CallLocalFunction("cmd_"#%2, "is", %1);}
#define DETUTILSCMD_DECL_FLAG__<%1|%2> stock bool:role_%1(%2)
#define DETUTILSCMD_FLAG_DATA_CHECK__|%3| { if(!(%3)) return false; else if(%3) return true; return false;}
#define DETUTILSCMD_PRX_DECL__<|%0|,|%1|> stock const %0[MAX_PREFIX_LENGTH]=%1;

#define INVALID_SLASH_COMMAND_TYPE -1
#define SLASH_COMMAND_TYPE_NORMAL 0
#define SLASH_COMMAND_TYPE_ALIAS 1
#define SLASH_COMMAND_TYPE_ADMIN 2
#define SLASH_COMMAND_TYPE_FLAGGED 3

#define DETUTILSCMD_TYPESET__|<%0>,%1| cty_%0();public cty_%0(){return %1;}