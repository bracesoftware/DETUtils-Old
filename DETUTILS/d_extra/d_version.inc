/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library core file.
 *
 *
 */

#if defined detutils_complete_error_boom
#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif
#endif

#if defined d_version_included

    #endinput

#endif

#define d_version_included

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

#if __Pawn >= 0x0400
    #error [samp-detutils]: (error) - Library does not support Pawn 4.0.x
#elseif __Pawn < 0x0300
    #error [samp-detutils]: (error) - Library does not support Pawn 2.0.x/1.0.x
#endif

#define DETUTILS_VERSION_MAJOR 1
#define DETUTILS_VERSION_MINOR 5
#define DETUTILS_VERSION_PATCH 7

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

#if defined detutils_complete_error_boom

static AnnounceLibraryLoaded_version()
{
    print("|======================================|");
    print("             d_version.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_version.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_version.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_version();
    a_version_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_version_main

#else

#define detutils_version_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_version();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_version.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_version.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_version_OnfsInit") != -1)
    {
        CallLocalFunction("a_version_OnfsInit", "i", playerid);
    }
    return detutils_version_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_version_OnfsInit

forward a_version_OnfsInit();

#endif

#endif