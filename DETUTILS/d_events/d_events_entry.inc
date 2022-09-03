/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   the @event decorator.
 *
 *
 */

#if !defined __file

    #error [DETUtils]: (error) - You're using the deprecated compiler; get the latest Pawn compiler in order use `d_events.inc`!

#endif

#define @DETUTILSEVENTS_KWORD__@%0\32; @DETUTILSEVENTS_KWORD__@
#define @event%0(%1.type%2= @DETUTILSEVENTS_KWORD__@

#define @evnt_%0\32; @evnt_
#define evnttype_%0\32; evnttype_
#define evntfile_%0\32; evntfile_

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

#define @DETUTILSEVENTS_KWORD__@LOCAL%0)%1(%2) \
    stock evnttype_%1() return 0; \
    stock evntfile_%1(){new evnt_filename[32];format(evnt_filename,sizeof evnt_filename,__file); \
        return evnt_filename;} \
    @evnt_%1(%2);@evnt_%1(%2)

#define @DETUTILSEVENTS_KWORD__@GLOBAL%0)%1(%2) \
    stock evntfile_%1(){new evnt_filename[32];format(evnt_filename,sizeof evnt_filename,__file); \
        return evnt_filename;} \
    stock evnttype_%1() return 1;@evnt_%1(%2);@evnt_%1(%2)

#define CallEvent%0("%1",%3) \
    if((evnttype_%1()==0)&&(!strcmp(__file,evntfile_%1()))) \
        CallLocalFunction("@evnt_"#%1,%3);if(evnttype_%1()==1)CallLocalFunction("@evnt_"#%1,%3)


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
    LoadDETUtilsScript(DETUTILS_SCRIPT_EVENTS);
    if(funcidx("d_events_detutilsinit") != -1)
    {
        CallLocalFunction("d_events_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_events_detutilsinit(

forward d_events_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_EVENTS);
    if(funcidx("d_events_detutilsexit") != -1)
    {
        CallLocalFunction("d_events_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_events_detutilsexit(

forward d_events_detutilsexit();