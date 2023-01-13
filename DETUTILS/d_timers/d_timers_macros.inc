/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Macros for d_timers.
 *
 *
 */

#define @DETUTILSTIMERS_KWORD__@%0\32; @DETUTILSTIMERS_KWORD__@
#define @DETUTILS_task%0(%1.%2type%3= @DETUTILSTIMERS_KWORD__@

#if DETUTILS_ANNOTATION__(task)
    #define @task%0(%1.%2type%3= @DETUTILSTIMERS_KWORD__@
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

#define @d_trpt_%0\32; @d_trpt_
#define @d_tint_%0\32; @d_tint_
#define @d_tmr_%0\32; @d_tmr_ 
#define @d_ret_%0\32; @d_ret_ 

#define DeferTask%0(%1,%2) \
    SetTimerEx("@d_tmr_"%1,CallLocalFunction("@d_tint_"%1,""),CallLocalFunction("@d_trpt_"%1,""),%2)

#define @DETUTILSTIMERS_KWORD__@AUTOMATIC%0,%3.interval%4=%5)%1(%2) \
    @DETUTILSFUNCGEN$d_t_int..%2$;@DETUTILSFUNCGEN$d_t_int..%2$ return %5;\
    @DETUTILSFUNCGEN$d_timerid..%2$;@DETUTILSFUNCGEN$d_timerid..%2$

#define @DETUTILSTIMERS_KWORD__@MANUAL%0,%3.interval%4=%5,%6.repeating%7=%8)%1(%2) \
    @d_trpt_%1();@d_trpt_%1() return %8;@d_tint_%1();@d_tint_%1() return %5; \
    @d_tmr_%1(%2);@d_tmr_%1(%2)