/*
 * 
 * DETUtils
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

    #error [DETUtils]: (error) - You need to have a_samp.inc file in your includes folder.

#endif

#endif

#if defined _d_data_included

    #error [DETUtils]: (error) - Unusable code reached.

#endif

#include "d_version"
#include "d_text"
#include "d_errors"

//DETUTILS_STATIC_MODE

#define __DETUTILS_STATIC

#if defined DETUTILS_STATIC_MODE

    #undef __DETUTILS_STATIC
    #define __DETUTILS_STATIC static

#endif

//public const detutils_ver = 0x1;

stock void:SaveDETUtilsLog(const message[]) 
{
    new formatted_message[ 128 ], 
        second, 
        minutes, 
        day2, 
        day, 
        year, 
        month;

    getdate(year, month, day);

    gettime(second, minutes, day2);
    
    format(formatted_message, 
        sizeof formatted_message, 
        "%d:%d:%d | %d:%d:%d @ %s\r\n", 
        day, month, year, 
        second, minutes, day2, message);

    new File:LogFile = fopen("detutils.log", io_append);

    fwrite(LogFile, formatted_message);

    fclose(LogFile);
}

#define DETUTILS_SCRIPT_COMMANDS 0
#define DETUTILS_SCRIPT_PROPERTIES 1
#define DETUTILS_SCRIPT_FMARGS 2
#define DETUTILS_SCRIPT_VISUAL 3
#define DETUTILS_SCRIPT_ANTICHEAT 4
#define DETUTILS_SCRIPT_FILEQUERIES 5
#define DETUTILS_SCRIPT_MAPEDITOR 6
#define DETUTILS_SCRIPT_DISCORDAPI 7
#define DETUTILS_SCRIPT_FACTIONS 8
#define DETUTILS_SCRIPT_DIALOG 9
#define DETUTILS_SCRIPT_VARS 10
#define DETUTILS_SCRIPT_ALS 11
#define DETUTILS_SCRIPT_FOREACH 12
#define DETUTILS_SCRIPT_TABLES 13
#define DETUTILS_SCRIPT_SERVER 14
#define DETUTILS_SCRIPT_PROFILE 15
#define DETUTILS_SCRIPT_TIMERS 16
#define DETUTILS_SCRIPT_TOML 17
#define DETUTILS_SCRIPT_PERMISSIONS 18
#define DETUTILS_SCRIPT_EVENTS 19
#define DETUTILS_SCRIPT_YAML 20
#define DETUTILS_SCRIPT_TESTING 21

stock void:LoadDETUtilsScript(scriptid)
{
    if(scriptid == DETUTILS_SCRIPT_COMMANDS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_commands.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_commands.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PROPERTIES)
    {
        print("*** [DETUtils]: (module) - Loaded: d_properties.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_properties.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FMARGS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_fmargs.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_fmargs.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_VISUAL)
    {
        print("*** [DETUtils]: (module) - Loaded: d_visual.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_visual.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_ANTICHEAT)
    {
        print("*** [DETUtils]: (module) - Loaded: d_anticheat.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_anticheat.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_MAPEDITOR)
    {
        print("*** [DETUtils]: (module) - Loaded: d_mapeditor.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_mapeditor.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FILEQUERIES)
    {
        print("*** [DETUtils]: (module) - Loaded: d_filequeries.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_filequeries.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FACTIONS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_factions.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_factions.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_DIALOG)
    {
        print("*** [DETUtils]: (module) - Loaded: d_dialog.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_dialog.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_VARS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_vars.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_vars.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_ALS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_als.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_als.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FOREACH)
    {
        print("*** [DETUtils]: (module) - Loaded: d_foreach.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_foreach.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TABLES)
    {
        print("*** [DETUtils]: (module) - Loaded: d_tables.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_tables.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_DISCORDAPI)
    {
        print("*** [DETUtils]: (module) - Loaded: d_discordapi.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_discordapi.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PROFILE)
    {
        print("*** [DETUtils]: (module) - Loaded: d_profile.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_profile.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TIMERS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_timers.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_timers.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PERMISSIONS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_permissions.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_permissions.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_EVENTS)
    {
        print("*** [DETUtils]: (module) - Loaded: d_events.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_events.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_SERVER)
    {
        print("*** [DETUtils]: (module) - Loaded: d_server.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_server.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TOML)
    {
        print("*** [DETUtils]: (module) - Loaded: d_toml.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_toml.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_YAML)
    {
        print("*** [DETUtils]: (module) - Loaded: d_yaml.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_yaml.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TESTING)
    {
        print("*** [DETUtils]: (module) - Loaded: d_testing.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Loaded: d_testing.inc");
    }
}

stock void:UnloadDETUtilsScript(scriptid)
{
    if(scriptid == DETUTILS_SCRIPT_COMMANDS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_commands.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_commands.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PROPERTIES)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_properties.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_properties.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FMARGS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_fmargs.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_fmargs.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_VISUAL)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_visual.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_visual.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_ANTICHEAT)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_anticheat.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_anticheat.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_MAPEDITOR)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_mapeditor.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_mapeditor.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FILEQUERIES)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_filequeries.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_filequeries.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FACTIONS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_factions.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_factions.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_DIALOG)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_dialog.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_dialog.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_VARS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_vars.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_vars.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_ALS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_als.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_als.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_FOREACH)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_foreach.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_foreach.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TABLES)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_tables.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_tables.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_DISCORDAPI)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_discordapi.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_discordapi.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PROFILE)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_profile.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_profile.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TIMERS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_timers.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_timers.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_PERMISSIONS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_permissions.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_permissions.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_EVENTS)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_events.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_events.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_SERVER)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_server.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_server.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TOML)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_toml.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_toml.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_YAML)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_yaml.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_yaml.inc");
    }
    if(scriptid == DETUTILS_SCRIPT_TESTING)
    {
        print("*** [DETUtils]: (module) - Unloaded: d_testing.inc");
        SaveDETUtilsLog("[DETUtils]: (module) - Unloaded: d_testing.inc");
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

#define @DETUTILSSTRING_NULL__1 ""
#define DET_gV_%0\32; DET_gV_
#define @DETUTILSSTRING_NULL__2 "",""
#define @DETUTILSSTRING_NULL__3 "","",""
#define @DETUTILSSTRING_NULL__4 "","","",""
#define varfunc%0(%1) stock DET_gV_%0(%1) 
#define @DETUTILSSTRING_NULL__5 "","","","","",
#define @DETUTILSSTRING_NULL__6 "","","","","","",
#define @DETUTILSSTRING_NULL__7 "","","","","","","",
#define @DETUTILSSTRING_NULL__8 "","","","","","","","",
#define @DETUTILSSTRING_NULL__9 "","","","","","","","","",
#define @DETUTILSSTRING_NULL__10 "","","","","","","","","","",

#define @DETUTILSFMARGS_TAGS__: {Float,_,bool}:

#if defined detutils_complete_error_boom

__DETUTILS_STATIC const DET_g_Version[1][10] = { ""DETUTILS_VERSION_MAJOR"."DETUTILS_VERSION_MINOR"."DETUTILS_VERSION_PATCH"" };

#endif

__DETUTILS_STATIC void:LoadDETUtils()
{
    new DET_g_Version[26];
    format(DET_g_Version, sizeof(DET_g_Version), "%i.%i.%i-R%i", 
        DETUTILS_VERSION_MAJOR, 
        DETUTILS_VERSION_MINOR, 
        DETUTILS_VERSION_PATCH,
        DETUTILS_VERSION_RELEASE);
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                DETUtils                ");
    print("        System is now loading...        ");
    print("                                        ");
    printf("              Version: %s              ", DET_g_Version);
    print("                                        ");
    print("               By: DEntisT              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    #if defined DETUTILS_FILTERSCRIPT_MODE
    print(" SA:MP | DETUtils - Filterscript mode is ON.");
    #endif
    #if defined DETUTILS_TESTING_MODE
    print(" SA:MP | DETUtils - Testing mode is ON.");
    #endif
    print("                                        ");
}

__DETUTILS_STATIC void:UnloadDETUtils()
{
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                DETUtils                ");
    print("          System is unloading...        ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    #if defined DETUTILS_FILTERSCRIPT_MODE
    print(" SA:MP | DETUtils - Filterscript mode is OFF.");
    #endif
    #if defined DETUTILS_TESTING_MODE
    print(" SA:MP | DETUtils - Testing mode is OFF.");
    #endif
    print("                                        ");
}

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    if(funcidx("a_init_OnGameModeInit") != -1)
    {
        CallLocalFunction("a_init_OnGameModeInit","");
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

forward a_init_OnGameModeInit();

//

public OnGameModeExit()
{
    if(funcidx("a_init_OnGameModeExit") != -1)
    {
        CallLocalFunction("a_init_OnGameModeExit","");
    }
    OnDETUtilsExit();
    return 1;
}

#if defined _ALS_OnGameModeExit
    #undef OnGameModeExit
#else
    #define _ALS_OnGameModeExit
#endif

#define OnGameModeExit a_init_OnGameModeExit

forward a_init_OnGameModeExit();

#else

public OnFilterScriptInit()
{
    if(funcidx("a_init_OnFilterScriptInit") != -1)
    {
        CallLocalFunction("a_init_OnFilterScriptInit", "");
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

//

public OnFilterScriptExit()
{
    if(funcidx("a_init_OnFilterScriptExit") != -1)
    {
        CallLocalFunction("a_init_OnFilterScriptExit","");
    }
    OnDETUtilsExit();
    return 1;
}

#if defined _ALS_OnFilterScriptExit
    #undef OnFilterScriptExit
#else
    #define _ALS_OnFilterScriptExit
#endif

#define OnFilterScriptExit a_init_OnFilterScriptExit

forward a_init_OnFilterScriptExit();

#endif

// Internal callbacks!

forward OnDETUtilsInit();
public OnDETUtilsInit()
{
    #if defined DETUTILS_DEBUG_MODE
    SendRconCommand("hostname [DETUtils]: (test) - Server");
    SetGameModeText("SA:MP | DET-Utils");
    #endif
    LoadDETUtils();
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

forward OnDETUtilsExit();
public OnDETUtilsExit()
{
    UnloadDETUtils();
    if(funcidx("a_init_OnDETUtilsExit") != -1)
    {
        CallLocalFunction("a_init_OnDETUtilsExit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit a_init_OnDETUtilsExit

forward a_init_OnDETUtilsExit();