/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - A library which is providing the
 *   automatic testing.
 *
 *
 */

#include "d_testing_impl"

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

stock void:LoadDETUtilsTests()
{
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                DETUtils                ");
    print("           Tests are staring...         ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    new typefunc[32];
    new testfunc[32];
    for(new i; i < 1000; i++)
    {
        format(testfunc, sizeof testfunc, "@%i@d_tst", i);
        format(typefunc, sizeof typefunc, "@%i@d_tst2", i);
        if(funcidx(testfunc) != -1 && funcidx(typefunc) != -1)
        {
            print("                                        ");
            print("                                        ");
            new scriptid = CallLocalFunction(typefunc, "");
            if(scriptid == DETUTILS_SCRIPT_COMMANDS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_commands.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_PROPERTIES)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_properties.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_FMARGS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_fmargs.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_VISUAL)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_visual.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_ANTICHEAT)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_anticheat.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_MAPEDITOR)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_mapeditor.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_FILEQUERIES)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_filequeries.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_FACTIONS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_factions.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_DIALOG)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_dialog.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_VARS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_vars.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_ALS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_als.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_FOREACH)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_foreach.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_TABLES)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_tables.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_DISCORDAPI)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_discordapi.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_PROFILE)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_profile.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_TIMERS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_timers.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_PERMISSIONS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_permissions.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_EVENTS)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_events.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_SERVER)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_server.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_TOML)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_toml.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_YAML)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_yaml.inc [%i]", i);
            }
            if(scriptid == DETUTILS_SCRIPT_TESTING)
            {
                printf("*** [DETUtils]: (testing) - init :: Testing a module: d_testing.inc [%i]", i);
            }
            if(scriptid == -1)
            {
                printf("*** [DETUtils]: (testing) - init :: Performing an user test... [%i]", i);
            }
            print("                                        ");
            CallLocalFunction(testfunc, "");
            print("                                        ");
            print("                                        ");
        }
    }
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                DETUtils                ");
    print("   All tests performed successfully!    ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    return 1;
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

public OnDETUtilsInit()
{
    LoadDETUtilsTests();
    LoadDETUtilsScript(DETUTILS_SCRIPT_TESTING);
    if(funcidx("d_tst_detutilsinit") != -1)
    {
        CallLocalFunction("d_tst_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_tst_detutilsinit(

forward d_tst_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_TESTING);
    if(funcidx("d_tst_detutilsexit") != -1)
    {
        CallLocalFunction("d_tst_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_tst_detutilsexit(

forward d_tst_detutilsexit();