/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   a new system of ALS hooking.
 *
 *
 */

#include "d_als_macros"

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

#include "d_als_impl"

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
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_ALS);
    if(funcidx("d_als_detutilsinit") != -1)
    {
        CallLocalFunction("d_als_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_als_detutilsinit(

forward d_als_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_ALS);
    if(funcidx("d_als_detutilsexit") != -1)
    {
        CallLocalFunction("d_als_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_als_detutilsexit(

forward d_als_detutilsexit();

/*
public OnDETUtilsInit()
{
    // Set the default return value.
    #emit ZERO.pri
    #if defined d_als_detutilsinit
        d_als_detutilsinit();
    #endif
    
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_ALS);

    // Implicitly return the value of the previous call.  This means we can
    // call `main` and return it's return value, without requiring it to
    // have a `return` statement.  It might, but the most common uses don't.
    #emit RETN
    // Return 0, just in case.
    return 0;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif
forward d_als_detutilsinit();

#define OnDETUtilsInit( d_als_detutilsinit(*/