/*
 * 
 * DETUtils
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

#define @DETUTILSALS_KEYWORD__@%0\32; @DETUTILSALS_KEYWORD__@
#define @als%0(%1) @DETUTILSALS_KEYWORD__@
 
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

#if !defined DETUTILS_NO_HOOK_KEYWORD

    #define hook \
        @als() function

#endif

#if !defined DET_g_Interval
#define DET_g_Interval 1000
#endif
        
#if defined DETUTILS_COMPAT

    #define als @als()

#endif

#define @DET_ALS$
//#define @DHQS_%0\32; @DHQS_
#define @DETUTILSALS_KEYWORD__@break (0)
#define @DETUTILSALS_KEYWORD__@continue (1)

#define @DETUTILSALS_KEYWORD__@function%1(%2) @DET_ALS$ @DETUTILSFUNCGEN$%1..%2$;@DETUTILSFUNCGEN$%1..%2$

#define @DETUTILSALS_KEYWORD__@do%1(%0,%2)%4; \
    @DET_ALS$ @a_detals$ @DET_ALS$ @b_detals$%0$ @DET_ALS$ @c_detals$%2$ @DET_ALS$ @d_detals$..%4$