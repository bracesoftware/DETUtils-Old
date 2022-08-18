/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_commands.inc
 *
 *
 */

#if defined _INC_code_parse_inc
#define SLASH_COMMAND)%0\10; SLASH_COMMAND)
#define @DETUTILSCMD_BRACKET__$%0$ D%0)
#define main_%0\32; main_
// For parsing.
#define prs_%0\32; prs_
// Also for parsing, stands for `PARSE_`
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

// All for parsing!

#pragma warning disable 217 // Warning 217 is kind of annoying.

#define P@_%0\32; P@_
#define ref_%0\32; ref_
#define ext_%0\32; ext_
#define arr_%0\32; arr_
#define str_%0\32; str_
#define num_%0\32; num_
#define @DETUTILSCMD_ARG_COUNT__%0\32; @DETUTILSCMD_ARG_COUNT__

// These two are moved to a macro, used to save command ID to cache.
#if defined detutils_complete_error_boom
#define DET_PARSE_ID
#define DET_PARSE_CACHE
#endif

#define @DETUTILSCMD_RET_PRINT__@%5@ return printf("*** [DETUtils]: (cmd parse) - Met an unexpected or unknown argument in \n\
													   the command header while parsing.\n\
													   Command: %s"#%5"\n\
													   Make sure that your command header looks like this:\n\
													   @command(...) CMD_NAME__(playerid, params[]) {...}\n\n\n");

#define @DETUTILSCMD_PR_CACHE__@%5@%0@%1@%2@%3@%4@ \
	{                                               \
		new const DET_PARAM_COUNT=%0+%1+%2+%3+%4;   \
		printf("*** [DETUtils]: (cmd parse) - Parsing a command : "#%5" with %i params.", DET_PARAM_COUNT); \
		if(DET_PARAM_COUNT!=2||%2 !=1||%4 !=1){g_PlayerCmdData[p][ParseProcess] = 0; @DETUTILSCMD_RET_PRINT__@%5@ \
		}                                           \
		g_PlayerCmdData[p][ParseProcess] = 1; return 1;                                   \
	}

// Entry.  Parse all parameter types.
#define @DETUTILSCMD_CMD_PARSE__D:%1(%2) FUNC_PARSER(__DETCMD_PARSETYPE_,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
	stock const ref_%1 = 0, ext_%1 = 0, arr_%1 = 0, str_%1 = 0, num_%1 = 0; \
	P@_%1(p); public P@_%1(p) @DETUTILSCMD_PR_CACHE__@%1@ref_%1@ext_%1@arr_%1@str_%1@num_%1@ %1(%2)

// Counts.  Add one to the relevant number.
#define __DETCMD_PARSETYPE__REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define __DETCMD_PARSETYPE__EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define __DETCMD_PARSETYPE__ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define __DETCMD_PARSETYPE__STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define __DETCMD_PARSETYPE__NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define __DETCMD_PARSETYPE__END(%9)%8$ %8$
#define __DETCMD_PARSETYPE__NUL(%9)%8$ %8$

#define DETUTILSCMD_PARSE|%0,%1| @DETUTILSCMD_CMD_PARSE__D:%0(%1)

#define @DETUTILSCMD_CALLFUNC__|%0$%1$%2| return CallLocalFunction("cmd_func_"#%0, "is", %1, %2);
// Call cmdfunc
#define @DETUTILSCMD_RETFUNC__<%3$%2>  %3,0,%2,%2);return %2
// Return cmd
#define @DETUTILSCMD_STRMID__$ strmid(g_PlayerCmdData[playerid][PassedPrefix]
// Assign prefix to cache
#define @DETUTILSCMD_NEXTLINE_TEST__ 0
// Nextline test
#if defined __DET_PARSETYPE__
#define DETUTILSCMD_ARGS__$ ARR:NUM:EXT:STR:REF:
// For parsing #2
#define DETUTILSCMD_ARGPARSE__<%1$%2> \
 stock ref_%1 = 0,ext_%1 = 0, \
 arr_%1 = 0,str_%1 = 0,@DETUTILSCMD_ARG_COUNT__%1 = 0; \
 %1(%2) 
#define DETUTILSCMD_ARGCOUNT__<%1> \
 ref_%1+ext_%1+ \
 arr_%1+str_%1+@DETUTILSCMD_ARG_COUNT__%1

#define @DETUTILSCMD_ARG_COUNT__@%1$ DETUTILSCMD_ARGCOUNT__<%1> != 2 && @DETUTILSCMD_ARG_COUNT__%1 != 1 && \
 arr_%1 != 1

#define DET_PRS_CMDFAIL__$%1$%2$ \
 printf("*** [DETUtils]: (parse) - Unknown or unexpected arguments met in the command (cmd: %1 | type: %2) \
	header while parsing.\n Make sure that your command header looks like this:\n \
	@command(.type = .., ..) NAME__(playerid, params[]"); 

#define DET_PRS_RES__<%1,%2> \
 main(){if(@DETUTILSCMD_ARG_COUNT__@%1$){DET_PRS_CMDFAIL__$%1$%2$}main_%1();}

// Macro below is the key of command parsing method.
// It hooks main() so parsing can continue.
#define @DETUTILSCMD_M_HOOK__@|%0| #undef main #define main main_%0

// Entry macro.
#define @DETUTILSCMD_ARGS_PARSE__C:%1|%2$%3| \
	FUNC_PARSER(DETUTILSCMD_ARG_COUNT__,ARR:NUM:EXT:STR:REF:)(prs_%1(%2)) \
	DETUTILSCMD_ARGPARSE__<%1$%2> DET_PRS_RES__<%1,%3> @DETUTILSCMD_M_HOOK__@|%1|

	/*
	stock ref_%1 = 0,ext_%1 = 0, \
	arr_%1 = 0,str_%1 = 0,@DETUTILSCMD_ARG_COUNT__%1 = 0; \
	prs_%1(%2) {} \
	main(){if(ref_%1+ext_%1+ arr_%1+str_%1+@DETUTILSCMD_ARG_COUNT__%1 != 2 && @DETUTILSCMD_ARG_COUNT__%1 != 1 && \
	arr_%1 != 1){printf("*** [DETUtils]: (parse) - Unknown or unexpected arguments met in the command (cmd: %1 | type: %2) \
	header while parsing.\n Make sure that your command header looks like this:\n \
	@command(.type = .., ..) NAME__(playerid, params[]");}main_%1();} \
	#undef main #define main main_%1

	// This is what the macro actually looks like.
	*/
	
#define DETUTILSCMD_ARG_COUNT___REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define DETUTILSCMD_ARG_COUNT___EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define DETUTILSCMD_ARG_COUNT___ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define DETUTILSCMD_ARG_COUNT___STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define DETUTILSCMD_ARG_COUNT___NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

#define DETUTILSCMD_ARG_COUNT___END(%9)%8$ %8$
#define DETUTILSCMD_ARG_COUNT___NUL(%9)%8$ %8$

#define @DETUTILSCMD_ARGS_PARSE__B:%1|%2$%3| \
	FUNC_PARSER(DETUTILSCMD_ARG_COUNT__,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
	stock ref_%1 = 0,ext_%1 = 0,arr_%1 = 0,str_%1 = 0,num_%1 = 0; \
	main(){if(ref_%1+ext_%1+arr_%1+str_%1+num_%1 != 2 && @DETUTILSCMD_ARG_COUNT__%1 != 1 && arr_%1 != 1){ \
	printf("*** [DETUtils]: (parse) - Unknown or unexpected arguments met in the command (cmd: "#%1" | type: "#%3") header while parsing.\n Make sure that your command header looks like this:\n @command(.type = .., ..) NAME__(playerid, params[]"); \
	}main_%1();} #if defined _ALS_main #undef main #else #define _ALS_main #endif #define main main_%1 %1(%2) 

// REALLY IMPORTANT MACROS:

#define __DATA_DETUTILS_ARR_NUM_EXT_STR_REF

/*
#define DET_REF_C_prs_%0\32; DET_REF_C_prs_
#define DET_REF_C_prs_%0\32; DET_EXT_C_prs_
#define DET_REF_C_prs_%0\32; DET_ARR_C_prs_
#define DET_REF_C_prs_%0\32; DET_STR_C_prs_
#define DET_REF_C_prs_%0\32; DET_NUM_C_prs_*/


// The entry point.  Defines our parser.
#define @ARRAY_COUNT:%1(%2) FUNC_PARSER(ARRAY_COUNT,ARR:NUM:)(%1(%2)) stock const countOf_%1 = 0; stock const sizeOf_%1 = 0; %1(%2)
#define ARRAY_COUNT_NUM(%9)%8$ %8$
#define ARRAY_COUNT_ARR(%9,%9,%9,%3)%8$%0;%1; %8$%0 + 1;%1 + (%3 +0);
#define ARRAY_COUNT_END(%9)%8$ %8$
#define ARRAY_COUNT_NUL(%9)%8$ %8$

/*
ARRAY_COUNT:my_test_function(a, b[], c, const d[], &e = 6, string:f[] = "hi")
{
}

main()
{
	printf("There are %d array parameters with size %d to \"my_test_function\"", countOf_my_test_function, sizeOf_my_test_function);
}
*/
#define @DETUTILSCMD_ARGS_PARSE__D:%1(%2) FUNC_PARSER(__DETCMD_PARSETYPE_,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
	stock const \
		DET_REF_C_%1 = 0, \
		DET_EXT_C_%1 = 0, \
		DET_ARR_C_%1 = 0, \
		DET_STR_C_%1 = 0, \
		DET_NUM_C_%1 = 0; \
	stock %1(%2)

// Counts.  Add one to the relevant number.
#define __DETCMD_PARSETYPE__REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define __DETCMD_PARSETYPE__EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define __DETCMD_PARSETYPE__ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define __DETCMD_PARSETYPE__STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define __DETCMD_PARSETYPE__NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define __DETCMD_PARSETYPE__END(%9)%8$ %8$
#define __DETCMD_PARSETYPE__NUL(%9)%8$ %8$
#endif

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
#define SLASH_COMMAND_TYPE_TEAM 4
#define SLASH_COMMAND_TYPE_DELAYED 5
#define DETUTILSCMD_TYPESET__$|<%0>,%1| cty_%0();public cty_%0(){return %1;}

#if @DETUTILSCMD_NEXTLINE_TEST__ == 1
#define DETUTILS_CMD_DEC_SLASH_COMMAND%2)\10; DETUTILS_CMD_DEC_SLASH_COMMAND%2)
#define SLASH_COMMAND)\10 SLASH_COMMAND)
#define @DETUTILSCMD_CLS_BRCKT__SC SLASH_COMMAND)
#endif

#define @DETUTILSCMD_DECL_NORM__|%0$%1| \
DETUTILSCMD_TYPESET__$|<%0>,SLASH_COMMAND_TYPE_NORMAL| DETUTILSCMD_DECL_CMD__<%0|%1>
#define @DETUTILSCMD_IMPORTANT__HACK__

#if !defined DETUTILS_NO_TEAMS
#define @DETUTILSCMD_TEAMS_DECL__|%0..%1,%7| cmd_%0(%1,%7[]);public cmd_%0(%1,%7[])
#define @DETUTILSCMD_TEAMS_CHECK__:{%1..|%2|..%0,%7} {if(!strcmp(g_PlayerTeamCache[%1][Team],%2,false)) \
return CallLocalFunction("cmdf_"#%0,"is",%1,%7);return 0;}
#define @DETUTILSCMD_TEAMS_CALL___:|||%0|%1..%7| cmdf_%0(%1,%7[]);public cmdf_%0(%1,%7[])
#endif
#define @DETUTILSCMD_DELAYED_DECL__<%0:%1> cmd_%0(%1[]);public cmd_%0(%1[])
#define @DETUTILSCMD_DELAY_SET__cmd:|%0:%7..%1| {return SetTimerEx("cmdf_"#%0,%7,false,"is",%1);}
#define @DETUTILSCMD_DELAY_CALL__:{..%0|;%1;} cmdf_%0(%1[]);public cmdf_%0(%1[])