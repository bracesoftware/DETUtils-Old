/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which allows you
 *   to make plugins in Pawn.
 *
 *
 */

#define @DETUTILSPAWNPDK_KWORD__@%0\32; @DETUTILSPAWNPDK_KWORD__@
#define PAWN_PDK%0:: @DETUTILSPAWNPDK_KWORD__@
#define @pawnpdk_n_%0\32; @pawnpdk_n_
#define @pawnpdk_c_%0\32; @pawnpdk_c_

forward OnPawnPDKInit();

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

// For plugin code

#define @DETUTILSPAWNPDK_KWORD__@plugincode%0.%1OnInit%2(%3) \
    public OnFilterScriptInit()

#define @DETUTILSPAWNPDK_KWORD__@register%2.%3Native%0(%1) \
    @pawnpdk_n_%0(%1);@pawnpdk_n_%0(%1)
#define @DETUTILSPAWNPDK_KWORD__@call%3.%4Callback%0(%1,%2) \
    CallRemoteFunction("@pawnpdk_c_"#%1,%2)

// For script code

new PAWN_PDK_LOAD[64];

#define @DETUTILSPAWNPDK_KWORD__@using%0native%1(%2) \
    CallRemoteFunction("@pawnpdk_n_"#%1,%2)
#define @DETUTILSPAWNPDK_KWORD__@public%0(%1) \
    @pawnpdk_c_%0(%1)
#define @DETUTILSPAWNPDK_KWORD__@forward%0(%1) \
    @pawnpdk_c_%0(%1)

#define @DETUTILSPAWNPDK_KWORD__@plugin%1; \
    format(PAWN_PDK_LOAD,sizeof PAWN_PDK_LOAD,"loadfs ../plugins/%s",%1);SendRconCommand(PAWN_PDK_LOAD);

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
    CallLocalFunction("OnPawnPDKInit", "");
    LoadDETUtilsScript(DETUTILS_SCRIPT_PAWNPDK);
    if(funcidx("d_pawnpdk_detutilsinit") != -1)
    {
        CallLocalFunction("d_pawnpdk_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_pawnpdk_detutilsinit(

forward d_pawnpdk_detutilsinit();