/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides using format
 *   inside functions.
 *
 */

#if defined _INC_y_va

    #warning [DETUtils]: (warning) - 'd_fmargs' is not compatible with 'y_va' include.

#endif

/*
                                         
88                                   88  
88                                   88  
88                                   88  
88  88,dPYba,,adPYba,   8b,dPPYba,   88  
88  88P'   "88"    "8a  88P'    "8a  88  
88  88      88      88  88       d8  88  
88  88      88      88  88b,   ,a8"  88  
88  88      88      88  88`YbbdP"'   88  
                        88               
                        88               
*/

// for d_visual

enum enum_TextDrawData
{
    Valid,
    Float:Pos[2],
    Float:OldPos[2]
}

new g_TextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];
new g_PlayerTextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];

// sscanf implementation:
#include "d_fmargs_sscanf"

// Actual FMARGS function implementation:
#include "d_fmargs_impl"

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
    SaveLogIntoFile("detutils_fmargs.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_fmargs.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_FMARGS);
    if(funcidx("d_fmargs_detutilsinit") != -1)
    {
        CallLocalFunction("d_fmargs_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_fmargs_detutilsinit(

forward d_fmargs_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_FMARGS);
    if(funcidx("d_fmargs_detutilsexit") != -1)
    {
        CallLocalFunction("d_fmargs_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_fmargs_detutilsexit(

forward d_fmargs_detutilsexit();