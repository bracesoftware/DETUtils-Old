/*
 * 
 * SA:MP DEntisT's Utilities
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

#if !defined DET_g_Interval
#define DET_g_Interval 1000
#endif

#define @DETUTILSALS_KEYWORD__@%0\32; @DETUTILSALS_KEYWORD__@
#define als @DETUTILSALS_KEYWORD__@
#define @DET_ALS$
//#define @DHQS_%0\32; @DHQS_
#define @DETUTILSALS_KEYWORD__@break (0)
#define @DETUTILSALS_KEYWORD__@continue (1)
/*
#define @DETUTILSALS_KEYWORD__@sleep (2)
#define @DETUTILSALS_KEYWORD__@if%0(%1sleep%3(%4)%2) if(@DHQS_%4==1)
#define @DETUTILSALS_KEYWORD__@init%0; new @DHQS_%0;
*/
#define @DETUTILSALS_KEYWORD__@function%1(%2) @DET_ALS$ @DETUTILSFUNCGEN$%1..%2$;@DETUTILSFUNCGEN$%1..%2$

#if defined DETUTILS_ALS_CALL_DEBUG

#define @a_detals$ new funcname[32];for(new hookindex;hookindex<1000;hookindex++){
#define @b_detals$%0$ format(funcname,32,"@%i@%s",hookindex,%0); \
printf("[samp-detutils]: (ALS call debug) - Attempted to call: %s", funcname); \
if(funcidx(funcname)!= -1){
#define @c_detals$%0$ if(CallLocalFunction(funcname,%0)==0)break;}
#define @d_detals$..%0$ %0}%0

/*
#define @a_detals$ \
    new funcname[32];\
    for(new hookindex;hookindex<1000;hookindex++){
#define @b_detals$%0$ \
        format(funcname,32,"@%i@%s",hookindex,#%0);\
        printf("[samp-detutils]: (ALS call debug) - Attempted to call: %s", funcname);\
        if(funcidx(funcname)!= -1){
#define @c_detals$%0$ \
        new cllres=CallLocalFunction(funcname,%0);\
        if(cllres==0)break;
#define @c_detals_extra$%0..%1$ \
        else if(cllres==2){ \
            format(funcname,32,"@%i@%s",hookindex+1,#%0);\
            SetTimerEx(funcname,DET_g_Interval,false,%1); break;}}
#define @d_detals$..%0$ %0}%0
*/
#else // If debug is disabled!
/*
#define @a_detals$ \
    new funcname[32];\
    for(new hookindex;hookindex<1000;hookindex++){
#define @b_detals$%0$ \
        format(funcname,32,"@%i@%s",hookindex,#%0);\
        if(funcidx(funcname)!= -1){
#define @c_detals$%0$ \
        new cllres=CallLocalFunction(funcname,%0);\
        if(cllres==0)break;
#define @c_detals_extra$%0..%1$ \
        else if(cllres==2){ \
            format(funcname,32,"@%i@%s",hookindex+1,#%0);\
            SetTimerEx(funcname,DET_g_Interval,false,%1); break;}}
#define @d_detals$..%0$ %0}%0
*/

#define @a_detals$ new @DET_ALS$ funcname[32];for(new hookindex;hookindex<1000;hookindex++){
#define @b_detals$%0$ @DET_ALS$ format(funcname,32,"@%i@%s",hookindex,%0);if(funcidx(funcname)!= -1){
#define @c_detals$%0$ @DET_ALS$ if(CallLocalFunction(funcname,%0)==0)break;}
#define @d_detals$..%0$ %0}%0

#endif
/*
#define @DETUTILSALS_KEYWORD__@do%1(%0,%2)%4; \
    @a_detals$ @b_detals$%0$ @c_detals$%2$ @c_detals_extra$%0..%2$ @d_detals$..%4$
*/

#define @DETUTILSALS_KEYWORD__@do%1(%0,%2)%4; \
    @DET_ALS$ @a_detals$ @DET_ALS$ @b_detals$%0$ @DET_ALS$ @c_detals$%2$ @DET_ALS$ @d_detals$..%4$

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

#if defined DETUTILS_OLD_HOOK
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

#define OnDETUtilsInit( d_als_detutilsinit(

forward d_als_detutilsinit();
#endif
/*
public OnDETUtilsInit()
{
    // Set the default return value.
    #emit ZERO.pri
    #if defined d_als_detutilsinit
        d_als_detutilsinit();
    #endif
    
    #if defined detutils_debug
    SaveLogIntoFile("detutils_als.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_als.log", "[samp-detutils]: (debug) - Loaded.");
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