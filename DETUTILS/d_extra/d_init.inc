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

#if defined d_init_included

    #endscript

#endif

#define d_init_included

#if defined DEV_MODE

#tryinclude <a_samp>

#if !defined _inc_a_samp

    #error [samp-detutils]: (error) - You need to have a_samp.inc file in your includes folder.

#endif

#endif

#if defined _d_data_included

    #error [samp-detutils]: (error) - Unusable code reached.

#endif

#include "d_version"
#include "d_text"

public const detutils_ver = 0x1;

#define DETUTILS_SCRIPT_COMMANDS 0
#define DETUTILS_SCRIPT_PROPERTIES 1
#define DETUTILS_SCRIPT_FMARGS 2
#define DETUTILS_SCRIPT_VISUAL 3
#define DETUTILS_SCRIPT_ANTICHEAT 4
#define DETUTILS_SCRIPT_FILEQUERIES 5
#define DETUTILS_SCRIPT_MAPEDITOR 6

stock void:LoadDETUtilsScript(scriptid)
{
    if(scriptid == DETUTILS_SCRIPT_COMMANDS)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_commands.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PROPERTIES)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_properties.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FMARGS)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_fmargs.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_VISUAL)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_visual.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_ANTICHEAT)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_anticheat.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_MAPEDITOR)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_mapeditor.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FILEQUERIES)
    {
        print("*** [samp-detutils]: (module) - Loaded: d_filequeries.inc");
    }
}

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

static const DET_g_Version[1][10] = { ""DETUTILS_VERSION_MAJOR"."DETUTILS_VERSION_MINOR"."DETUTILS_VERSION_PATCH"" };

#endif

static void:AnnounceLibraryLoading_init()
{
    new DET_g_Version[26];
    format(DET_g_Version, sizeof(DET_g_Version), "%i.%i.%i", DETUTILS_VERSION_MAJOR, DETUTILS_VERSION_MINOR, DETUTILS_VERSION_PATCH);
    print("|======================================|");
    print("                                        ");
    print("            SA:MP | DETUtils            ");
    print("        System is now loading...        ");
    print("                                        ");
    printf("              Version: %s              ", DET_g_Version);
    print("                                        ");
    print("               By: DEntisT              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    #if defined DETUTILS_COMPATIBILITY_MODE
    print(" SA:MP | DETUtils - Compatibility mode is on.");
    #endif
    print("                                        ");
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    if(funcidx("a_init_OnGameModeInit") != -1)
    {
        a_init_OnGameModeInit();
    }
    OnDETUtilsInit();
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_init_OnGameModeInit

#if defined detutils_debug

main()
{
    SendRconCommand("hostname [samp-detutils]: (test) - Server");
    SetGameModeText("SA:MP | DET-Utils");
    a_init_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_init_main

#endif

forward a_init_OnGameModeInit();

#else

public OnFilterScriptInit()
{
    if(funcidx("a_init_OnFilterScriptInit") != -1)
    {
        a_init_OnFilterScriptInit();
    }
    OnDETUtilsInit();
    return 1;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_init_OnFilterScriptInit

forward a_init_OnFilterScriptInit();

#endif

forward OnDETUtilsInit();
public OnDETUtilsInit()
{
    AnnounceLibraryLoading_init();
    if(funcidx("a_init_OnDETUtilsInit") != -1)
    {
        CallLocalFunction("a_init_OnDETUtilsInit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit a_init_OnDETUtilsInit

forward a_init_OnDETUtilsInit();