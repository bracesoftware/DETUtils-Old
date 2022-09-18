/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   the @event decorator.
 *
 *
 */

#define @dlge_%0\32; @dlge_
#define @dlgp_%0\32; @dlgp_

#define dref_%0\32; dref_
#define dext_%0\32; dext_
#define darr_%0\32; darr_
#define dstr_%0\32; dstr_
#define dnum_%0\32; dnum_

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

#define @DETUTILSEVENTS_PARSEFAIL@%5@ \
    return printf("*** [DETUtils]: (event parse) - Met an unexpected or unknown argument in the dialog event header while parsing.\n\
       Dialog event: '"#%5"'\n\
       Make sure that your event header looks like this:\n\
       @event(.type = DIALOG_EVENT) EVENT_NAME__(playerid, response, listitem inputtext[]) {...}\n\n\n")

#define @DETUTILSEVENT_DLG_CACHE__@%5@%0@%1@%2@%3@%4@ \
    {                                               \
        new const DET_g_DialogParamCount=%0+%1+%2+%3+%4;   \
        printf("*** [DETUtils]: (event parse) - Parsing a dialog event : '"#%5"' with %i parameters.", DET_g_DialogParamCount); \
        if(DET_g_DialogParamCount!=4||%2 !=1||%4 !=3){DET_g_DialogParser[p]=0;@DETUTILSEVENTS_PARSEFAIL@%5@; \
        }DET_g_DialogParser[p]=1;return 1;}

// Entry.  Parse all parameter types.
#define @DETUTILSEVENT_PARSE__D:%1(%2) FUNC_PARSER(__DETEVENT_DIALOG_,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
    stock const dref_%1 = 0, dext_%1 = 0, darr_%1 = 0, dstr_%1 = 0, dnum_%1 = 0; \
    @dlgp_%1(p);@dlgp_%1(p) @DETUTILSEVENT_DLG_CACHE__@%1@dref_%1@dext_%1@darr_%1@dstr_%1@dnum_%1@ %1(%2)

// Counts.  Add one to the relevant number.
#define __DETEVENT_DIALOG__REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define __DETEVENT_DIALOG__EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define __DETEVENT_DIALOG__ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define __DETEVENT_DIALOG__STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define __DETEVENT_DIALOG__NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define __DETEVENT_DIALOG__END(%9)%8$ %8$
#define __DETEVENT_DIALOG__NUL(%9)%8$ %8$

// Entry point #2
#define @DETUTILSEVENTS_KWORD__@DIALOG_EVENT%0)%1(%2) \
    @DETUTILSEVENT_PARSE__D:%1(%2){}@dlge_%1(%2); @dlge_%1(%2)