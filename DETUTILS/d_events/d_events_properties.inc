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

#define @prpe_%0\32; @prpe_
#define @prpp_%0\32; @prpp_

#define pref_%0\32; pref_
#define pext_%0\32; pext_
#define parr_%0\32; parr_
#define pstr_%0\32; pstr_
#define pnum_%0\32; pnum_

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

#define @DETUTILSEVENTS_PARSEFAIL2@%5@ \
    return printf("*** [DETUtils]: (event parse) - Met an unexpected or unknown argument in \n\
       the property event header while parsing.\n\
       Property event: '"#%5"'\n\
       Make sure that your event header looks like this:\n\
       @event(.type = PROPERTY_EVENT) EVENT_NAME__(playerid, propertyid, actionid) {...}\n\n\n")

#define @DETUTILSEVENT_DLG_CACHE__2@%5@%0@%1@%2@%3@%4@ \
    {                                               \
        new const DET_g_DialogParamCount=%0+%1+%2+%3+%4;   \
        printf("*** [DETUtils]: (event parse) - Parsing a property event : '"#%5"' with %i parameters.", DET_g_DialogParamCount); \
        if(DET_g_DialogParamCount!=3||%4 != 3){DET_g_PropertyParser[p]=0;@DETUTILSEVENTS_PARSEFAIL2@%5@; \
        }DET_g_PropertyParser[p]=1;return 1;}

// Entry.  Parse all parameter types.
#define @DETUTILSEVENT_PARSE__P:%1(%2) FUNC_PARSER(__DETEVENT_PROPERTY_,ARR:NUM:EXT:STR:REF:)(%1(%2)) \
    stock const pref_%1 = 0, pext_%1 = 0, parr_%1 = 0, pstr_%1 = 0, pnum_%1 = 0; \
    @prpp_%1(p);@prpp_%1(p) @DETUTILSEVENT_DLG_CACHE__2@%1@pref_%1@pext_%1@parr_%1@pstr_%1@pnum_%1@ %1(%2)

// Counts.  Add one to the relevant number.
#define __DETEVENT_PROPERTY__REF(%9)%8$%0,%1,%2,%3,%4; %8$%0 + 1,%1,%2,%3,%4;
#define __DETEVENT_PROPERTY__EXT(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1 + 1,%2,%3,%4;
#define __DETEVENT_PROPERTY__ARR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2 + 1,%3,%4;
#define __DETEVENT_PROPERTY__STR(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3 + 1,%4;
#define __DETEVENT_PROPERTY__NUM(%9)%8$%0,%1,%2,%3,%4; %8$%0,%1,%2,%3,%4 + 1;

// Endings
#define __DETEVENT_PROPERTY__END(%9)%8$ %8$
#define __DETEVENT_PROPERTY__NUL(%9)%8$ %8$

// Entry point #2
#define @DETUTILSEVENTS_KWORD__@PROPERTY_EVENT%0)%1(%2) \
    @DETUTILSEVENT_PARSE__P:%1(%2){} @prpe_%1(%2); @prpe_%1(%2)