/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - An extension to the DCC plugin.
 *
 *
 */

#include "d_core_funcgen"

#if defined d_core_included

    #endinput

#endif

#define d_core_included

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

#if defined DETUTILS_COMPAT

#define @newk_%0\32; @newk_

#define DETUTILS @newk_

#endif

// Include the these first
// becase they contain important
// information and functions
// used by the rest of the core
// itself.
#include "d_core_text"
#include "d_core_thirdpartyinclude"
#include "d_core_version"
#include "d_core_memory"

// "Compilefix":
#if !defined DETUTILS_NO_COMPILEFIX

#include "d_core_compilefix"

#endif

// And now the rest of the core.
#include "d_core_errors"
#include "d_core_funcs"
#include "d_core_init"

#if !defined DETUTILS_NO_REM

#include "d_core_rem"

#endif

// Debugging is really important.
#include "d_core_debug"

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

public OnDETUtilsInit()
{
    if(funcidx("d_core_detutilsinit") != -1)
    {
        CallLocalFunction("d_core_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_core_detutilsinit(

forward d_core_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    if(funcidx("d_core_detutilsexit") != -1)
    {
        CallLocalFunction("d_core_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_core_detutilsexit(

forward d_core_detutilsexit();