/*
 *
 * DETUtils
 *
 * - Mainfix provides
 *   the main() in filterscripts
 *   too.
 *
 * - This is internal include
 *   so it's included alone.
 *
 */

#if defined d_mainfix_included

    #endscript

#endif

#define d_mainfix_included

/*

Code

*/

#if defined DETUTILS_FILTERSCRIPT_MODE

public OnFilterScriptInit()
{
    main();
    if(funcidx("a_mainfix_fsinit") != -1)
    {
        CallLocalFunction("a_mainfix_fsinit", "");
    }
    OnDETUtilsInit();
    return 1;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_mainfix_fsinit

forward a_mainfix_fsinit();

main()
{
    #if defined DETUTILS_DEBUG_MODE_MODE
    SendRconCommand("hostname [DETUtils]: (test) - Server");
    SetGameModeText("SA:MP | DET-Utils");
    #endif
    a_mainfix_entry();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_mainfix_entry

#else
/*
main()
{
    #if defined DETUTILS_DEBUG_MODE_MODE
    SendRconCommand("hostname [DETUtils]: (test) - Server");
    SetGameModeText("SA:MP | DET-Utils");
    #endif
    a_mainfix_entry();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_mainfix_entry
*/
#endif