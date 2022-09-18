/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library providing an execution
 *   of code outside functions.
 *
 *
 */

#define @glbp_%0\32; @glbp_

#define gref_%0\32; gref_
#define gext_%0\32; gext_
#define garr_%0\32; garr_
#define gstr_%0\32; gstr_
#define gnum_%0\32; gnum_

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

#define @__DETGLOBAL_ARGFAIL@%5@ \
    return printf("*** [DETUtils]: (global parse) - Met an extra argument in the global procedure header while parsing.\n\
       Procedure name: '"#%5"'\n\
       Make sure that your global procedure header looks like this:\n\
       global PROCEDURE_NAME__() <fuction/expression>;\n\n\n")

#define @__DETGLOBAL_ARGNUM@%5@%0@%1@%2@%3@%4@ \
    {                                               \
        new const DET_g_GlobalProcedureArgs=%0+%1+%2+%3+%4;   \
        printf("*** [DETUtils]: (global parse) - Parsing a global procedure : '"#%5"' with %i parameters.", DET_g_GlobalProcedureArgs); \
        if(DET_g_GlobalProcedureArgs!=0){DET_g_ProcedureFail[p]=0;@__DETGLOBAL_ARGFAIL@%5@; \
        }DET_g_ProcedureFail[p]=1;return 1;}

// Entry.  Parse all parameter types.
#define @DETUTILSGLOBAL_PROCEDURE__P:%1(%2)%3; FUNC_PARSER(__DETGLOBAL_,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
    stock const gref_%1 = 0, gext_%1 = 0, garr_%1 = 0, gstr_%1 = 0, gnum_%1 = 0; \
    @glbp_%1(p);@glbp_%1(p) @__DETGLOBAL_ARGNUM@%1@gref_%1@gext_%1@garr_%1@gstr_%1@gnum_%1@

// Counts.  Add one to the relevant number.
#define __DETGLOBAL__REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define __DETGLOBAL__EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define __DETGLOBAL__ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define __DETGLOBAL__STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define __DETGLOBAL__NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define __DETGLOBAL__END(%9)%8$ %8$
#define __DETGLOBAL__NUL(%9)%8$ %8$