/*
 *
 * DETUTILS COMMANDS
 *
 *
 * Macro setup
 *
 *
 */

#if defined _INC_code_parse_inc
#define D%0)\10; D%0)
#define @DETUTILSCMD_BRACKET__$%0$ D%0)
#define main_%0\32; main_
// For parsing.
#define prs_%0\32; prs_
// Also for parsing, stands for `PARSE_`
#endif

// All for parsing!

#define @DETUTILSCMD_PARSE_REF__%0\32; @DETUTILSCMD_PARSE_REF__
#define @DETUTILSCMD_PARSE_EXT__%0\32; @DETUTILSCMD_PARSE_EXT__
#define @DETUTILSCMD_PARSE_ARR__%0\32; @DETUTILSCMD_PARSE_ARR__
#define @DETUTILSCMD_PARSE_STR__%0\32; @DETUTILSCMD_PARSE_STR__
#define @DETUTILSCMD_PARSE_INT__%0\32; @DETUTILSCMD_PARSE_INT__

#define @DETUTILSCMD_CALLFUNC__|%0$%1$%2| return CallLocalFunction("cmd_func_"#%0, "is", %1, %2);
// Call cmdfunc
#define @DETUTILSCMD_RETFUNC__<%3$%2>  %3,0,%2,%2);return %2
// Return cmd
#define @DETUTILSCMD_STRMID__$ strmid(g_PlayerCmdData[playerid][PassedPrefix]
// Assign prefix to cache
#define @DETUTILSCMD_NEXTLINE_TEST__ 0
// Nextline test

#define DETUTILSCMD_ARGS__$ ARR:NUM:EXT:STR:REF:
// For parsing #2
#define DETUTILSCMD_ARGPARSE__<%1$%2> \
 stock @DETUTILSCMD_PARSE_REF__%1 = 0,@DETUTILSCMD_PARSE_EXT__%1 = 0, \
 @DETUTILSCMD_PARSE_ARR__%1 = 0,@DETUTILSCMD_PARSE_STR__%1 = 0,@DETUTILSCMD_PARSE_INT__%1 = 0; \
 prs_%1(%2) {}
#define DETUTILSCMD_ARGCOUNT__<%1> \
 @DETUTILSCMD_PARSE_REF__%1+@DETUTILSCMD_PARSE_EXT__%1+ \
 @DETUTILSCMD_PARSE_ARR__%1+@DETUTILSCMD_PARSE_STR__%1+@DETUTILSCMD_PARSE_INT__%1

#define @DETUTILSCMD_ARG_COUNT__$%1$ DETUTILSCMD_ARGCOUNT__<%1> != 2 && @DETUTILSCMD_PARSE_INT__%1 != 1 && \
 @DETUTILSCMD_PARSE_ARR__%1 != 1

#define DETUTILSCMD_PARSE_CMDFAIL__$%1$%2$ \
 printf("*** [samp-detutils]: (parse) - Unknown or unexpected arguments met in the command (cmd: %1 | type: %2) \
    header while parsing.\n Make sure that your command header looks like this:\n \
    @command(.type = .., ..) NAME__(playerid, params[]"); 

#define DETUTILSCMD_PARSE_RES__<%1,%2> \
 main(){if(@DETUTILSCMD_ARG_COUNT__$%1$){DETUTILSCMD_PARSE_CMDFAIL__$%1$%2$}main_%1();}

// Macro below is the key of command parsing method.
// It hooks main() so parsing can continue.
#define @DETUTILSCMD_M_HOOK__@|%0| #undef main #define main main_%0

// Entry macro.
#define @DETUTILSCMD_PARSE_ARGS__:%1|%2$%3| \
    FUNC_PARSER(DETUTILSCMD_PARSE_INT__,ARR:NUM:EXT:STR:REF:)(prs_%1(%2)) \
    DETUTILSCMD_ARGPARSE__<%1$%2> DETUTILSCMD_PARSE_RES__<%1,%3> @DETUTILSCMD_M_HOOK__@|%1|
    

#define DETUTILSCMD_PARSE_INT___REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define DETUTILSCMD_PARSE_INT___EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define DETUTILSCMD_PARSE_INT___ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define DETUTILSCMD_PARSE_INT___STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define DETUTILSCMD_PARSE_INT___NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

#define DETUTILSCMD_PARSE_INT___END(%9)%8$ %8$
#define DETUTILSCMD_PARSE_INT___NUL(%9)%8$ %8$

// IMPORTANT MACROS:

#define @DETUTILSCMD_PARSE_ARGS__B:%1(%2) FUNC_PARSER(ALL_COUNT,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
    stock const \
        refCount_%1 = 0, \
        extCount_%1 = 0, \
        arrCount_%1 = 0, \
        strCount_%1 = 0, \
        numCount_%1 = 0; \
    public %1(%2)

// Counts.  Add one to the relevant number.
#define ALL_COUNT_REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define ALL_COUNT_EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define ALL_COUNT_ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define ALL_COUNT_STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define ALL_COUNT_NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define ALL_COUNT_END(%9)%8$ %8$
#define ALL_COUNT_NUL(%9)%8$ %8$

#define DETUTILSCMD_FCMD_ENTRY__|%0|(%1,%2) forward cmd_%0(%1,%2[]); public cmd_%0(%1,%2[])
#define DETUTILSCMD_FLAG_CHECK__|%3|<%0>(%1,%2) { if( !role_%3(%1) ) return 0; return cmd_func_%0(%1,%2); }
#define DETUTILSCMD_CMD_FUNC__|%0|<%1,%2> forward cmd_func_%0(%1,%2[]); public cmd_func_%0(%1,%2[])
#define DETUTILSCMD_PC_DECL__|%0|%1| forward pc_%0(%1);public pc_%0(%1)
#define DETUTILSCMD_PRX_FUNC__<%3> {@DETUTILSCMD_STRMID__$,@DETUTILSCMD_RETFUNC__<%3$ MAX_PREFIX_LENGTH>;}
#define DETUTILSCMD_PRX_CALL__|%0| forward prx_%0(playerid); public prx_%0(playerid)
#define DETUTILSCMD_ACMD_DECL__|%0|%1|%2| forward cmd_%0(%1,%2[]); public cmd_%0(%1,%2[])
#define DETUTILSCMD_ACMD_CHECK__<%1>|%0,%2| {if(!IsPlayerAdmin(%1)) return 0; @DETUTILSCMD_CALLFUNC__|%0$%1$%2|}
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
#define DETUTILSCMD_TYPESET__$|<%0>,%1| cty_%0();public cty_%0(){return %1;}

#if @DETUTILSCMD_NEXTLINE_TEST__ == 1
#define DETUTILS_CMD_DEC_SLASH_COMMAND%2)\10; DETUTILS_CMD_DEC_SLASH_COMMAND%2)
#define SLASH_COMMAND)\10 SLASH_COMMAND)
#define @DETUTILSCMD_CLS_BRCKT__SC SLASH_COMMAND)
#endif

#define @DETUTILSCMD_DECL_NORM__|%0$%1| \
DETUTILSCMD_TYPESET__$|<%0>,SLASH_COMMAND_TYPE_NORMAL| DETUTILSCMD_DECL_CMD__<%0|%1>