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

#define @DETUTILSTESTING_KWORD__@%0\32; @DETUTILSTESTING_KWORD__@
#define @testing%0(%1.subject%2= @DETUTILSTESTING_KWORD__@

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

stock DETUtilsAssert(assertion, const success[], const fail[])
{
    if((assertion))
    {
        printf("*** [DETUtils]: (testing) - assert :: Assertion successful : %s", success);
        return 1;
    }
    if(!(assertion)) 
    {
        printf("*** [DETUtils]: (testing) - assert :: Assertion failed : %s", fail);
        return 0;
    }
    return 0;
}

#define @d_tst%0\32; @d_tst
#define @d_tst2%0\32; @d_tst2

// for user tests
#define @DETUTILSTESTING_KWORD__@CUSTOM%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return -1; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$

// for internal tests
#define @DETUTILSTESTING_KWORD__@SCRIPT_COMMANDS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_COMMANDS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$

#define @DETUTILSTESTING_KWORD__@SCRIPT_PROPERTIES%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_PROPERTIES; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$

#define @DETUTILSTESTING_KWORD__@SCRIPT_FMARGS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_FMARGS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$

#define @DETUTILSTESTING_KWORD__@SCRIPT_VISUAL%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_VISUAL; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_ANTICHEAT%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_ANTICHEAT; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_FILEQUERIES%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_FILEQUERIES; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_MAPEDITOR%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_MAPEDITOR; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_DISCORDAPI%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_DISCORDAPI; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_FACTIONS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_FACTIONS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_DIALOG%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_DIALOG; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_VARS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_VARS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_ALS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_ALS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_FOREACH%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_FOREACH; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_TABLES%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_TABLES; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_SERVER%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_SERVER; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_PROFILE%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_PROFILE; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_TIMERS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_TIMERS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_TOML%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_TOML; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_PERMISSIONS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_PERMISSIONS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_EVENTS%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_EVENTS; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_YAML%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_YAML; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$
    
#define @DETUTILSTESTING_KWORD__@SCRIPT_TESTING%0)%1(%2) \
    @DETUTILSFUNCGEN$d_tst2..%2$;@DETUTILSFUNCGEN$d_tst2..%2$ return DETUTILS_SCRIPT_TESTING; \
    @DETUTILSFUNCGEN$d_tst..%2$;@DETUTILSFUNCGEN$d_tst..%2$