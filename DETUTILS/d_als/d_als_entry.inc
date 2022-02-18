/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides sending
 *   of file queries. Similar concept
 *   of SQL.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

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

#define @DETUTILSALS_KEYWORD__@%0\32; @DETUTILSALS_KEYWORD__@
#define als @DETUTILSALS_KEYWORD__@
#define @DET_ALS$
#define @DETUTILSALS_KEYWORD__@continue (1)

#define @DETUTILSALS_KEYWORD__@forward%1(%2) @DET_ALS$ @DETUTILSFUNCGEN$%1..%2$
#define @DETUTILSALS_KEYWORD__@public%1(%2) @DET_ALS$ @DETUTILSFUNCGEN$%1..%2$

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
    #if defined detutils_debug
    SaveLogIntoFile("detutils_als.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_als.log", "[samp-detutils]: (debug) - Loaded.");
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

#define OnDETUtilsInit d_als_detutilsinit

forward d_als_detutilsinit();