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


#define @a_detals$ new funcname[32];for(new hookindex;hookindex<1000;hookindex++){

#if defined DETUTILS_ALS_CALL_DEBUG

    #define @b_detals$%0$ format(funcname,32,"@%i@%s",hookindex,%0); \
    printf("[DETUtils]: (ALS call debug) - Attempted to call: %s", funcname); \
    if(funcidx(funcname)!= -1){

#endif

#if !defined DETUTILS_ALS_CALL_DEBUG

    #define @b_detals$%0$ format(funcname,32,"@%i@%s",hookindex,%0); \
    if(funcidx(funcname)!= -1){

#endif

#define @c_detals$%0$ if(CallLocalFunction(funcname,%0)==0)break;}
#define @d_detals$..%0$ %0}%0

#if defined detutils_complete_error_boom

stock DET_g_DoAls(const funcname[], const call_format[], {Float,_}:...)
{
    new alsfuncname[32];
    for(new hookindex; hookindex < 1000; hookindex++)
    {
        format(alsfuncname, sizeof alsfuncname, "@%i@%s", hookindex, funcname); 
        printf("[DETUtils]: (ALS call debug) - Attempted to call: %s", alsfuncname); 
        if(funcidx(alsfuncname)!= -1)
        {
            if(CallLocalFunction(alsfuncname, call_format, ...) == 0) break;
        }
    }
    return 1;
}

#endif