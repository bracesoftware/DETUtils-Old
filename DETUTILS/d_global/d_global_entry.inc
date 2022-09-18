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

#include "d_global_idx"

// After globalidx is included,
// we include the entry point.

#if defined __DETUTILS_INTERNAL_GLOBAL_INC

    #endinput

#endif

#define __DETUTILS_INTERNAL_GLOBAL_INC
#define @DETUTILSGLOBAL_RET__FUNC:%0; {%0;return 1;}
#define @DETUTILSGLOBAL_AMXFUNC__:%0; @glbc_%0();@glbc_%0()

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

#include "d_global_impl"

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
    LoadDETUtilsGlobalCode();
    LoadDETUtilsScript(DETUTILS_SCRIPT_GLOBAL);
    if(funcidx("d_global_detutilsinit") != -1)
    {
        CallLocalFunction("d_global_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_global_detutilsinit(

forward d_global_detutilsinit();

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_GLOBAL);
    if(funcidx("d_global_detutilsexit") != -1)
    {
        CallLocalFunction("d_global_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_global_detutilsexit(

forward d_global_detutilsexit();