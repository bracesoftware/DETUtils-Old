/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which recreates 
 *   an object editing system.
 *
 *
 */

new Text:DET_g_EditObjectTD[30];

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

#include "d_editobject_impl"

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
    DET_g_EditObjectTD[0] = TextDrawCreate(550.888916, 221.517776, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[0], 0.000000, 9.141109);
    TextDrawTextSize(DET_g_EditObjectTD[0], 467.777801, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[0], 1);
    TextDrawColor(DET_g_EditObjectTD[0], 0);
    TextDrawUseBox(DET_g_EditObjectTD[0], true);
    TextDrawBoxColor(DET_g_EditObjectTD[0], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[0], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[0], 0);
    TextDrawFont(DET_g_EditObjectTD[0], 0);

    DET_g_EditObjectTD[1] = TextDrawCreate(474.666717, 249.386718, "X");
    TextDrawLetterSize(DET_g_EditObjectTD[1], 0.449999, 1.600000);
    TextDrawAlignment(DET_g_EditObjectTD[1], 1);
    TextDrawColor(DET_g_EditObjectTD[1], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[1], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[1], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[1], 51);
    TextDrawFont(DET_g_EditObjectTD[1], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[1], 1);

    DET_g_EditObjectTD[2] = TextDrawCreate(475.111114, 267.804473, "Y");
    TextDrawLetterSize(DET_g_EditObjectTD[2], 0.449999, 1.600000);
    TextDrawAlignment(DET_g_EditObjectTD[2], 1);
    TextDrawColor(DET_g_EditObjectTD[2], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[2], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[2], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[2], 51);
    TextDrawFont(DET_g_EditObjectTD[2], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[2], 1);

    DET_g_EditObjectTD[3] = TextDrawCreate(475.555603, 285.226684, "Z");
    TextDrawLetterSize(DET_g_EditObjectTD[3], 0.449999, 1.600000);
    TextDrawAlignment(DET_g_EditObjectTD[3], 1);
    TextDrawColor(DET_g_EditObjectTD[3], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[3], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[3], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[3], 51);
    TextDrawFont(DET_g_EditObjectTD[3], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[3], 1);

    DET_g_EditObjectTD[4] = TextDrawCreate(545.111083, 251.384429, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[4], 0.000000, 1.453210);
    TextDrawTextSize(DET_g_EditObjectTD[4], 487.333343, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[4], 1);
    TextDrawColor(DET_g_EditObjectTD[4], 0);
    TextDrawUseBox(DET_g_EditObjectTD[4], true);
    TextDrawBoxColor(DET_g_EditObjectTD[4], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[4], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[4], 0);
    TextDrawFont(DET_g_EditObjectTD[4], 0);

    DET_g_EditObjectTD[5] = TextDrawCreate(545.555541, 270.300018, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[5], 0.000000, 1.397899);
    TextDrawTextSize(DET_g_EditObjectTD[5], 487.777801, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[5], 1);
    TextDrawColor(DET_g_EditObjectTD[5], 0);
    TextDrawUseBox(DET_g_EditObjectTD[5], true);
    TextDrawBoxColor(DET_g_EditObjectTD[5], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[5], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[5], 0);
    TextDrawFont(DET_g_EditObjectTD[5], 0);

    DET_g_EditObjectTD[6] = TextDrawCreate(545.111083, 289.215545, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[6], 0.000000, 1.231978);
    TextDrawTextSize(DET_g_EditObjectTD[6], 488.222198, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[6], 1);
    TextDrawColor(DET_g_EditObjectTD[6], 0);
    TextDrawUseBox(DET_g_EditObjectTD[6], true);
    TextDrawBoxColor(DET_g_EditObjectTD[6], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[6], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[6], 0);
    TextDrawFont(DET_g_EditObjectTD[6], 0);

    DET_g_EditObjectTD[7] = TextDrawCreate(475.111114, 229.973327, "LD_SPAC:white");
    TextDrawLetterSize(DET_g_EditObjectTD[7], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[7], 31.111114, 12.942214);
    TextDrawAlignment(DET_g_EditObjectTD[7], 1);
    TextDrawColor(DET_g_EditObjectTD[7], 0x000000FF);
    TextDrawSetShadow(DET_g_EditObjectTD[7], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[7], 0);
    TextDrawFont(DET_g_EditObjectTD[7], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[7], true);

    DET_g_EditObjectTD[8] = TextDrawCreate(510.666564, 229.973342, "LD_SPAC:white");
    TextDrawLetterSize(DET_g_EditObjectTD[8], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[8], 33.333316, 12.444461);
    TextDrawAlignment(DET_g_EditObjectTD[8], 1);
    TextDrawColor(DET_g_EditObjectTD[8], 0x000000FF);
    TextDrawSetShadow(DET_g_EditObjectTD[8], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[8], 0);
    TextDrawFont(DET_g_EditObjectTD[8], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[8], true);

    DET_g_EditObjectTD[9] = TextDrawCreate(479.555572, 231.466735, "POS");
    TextDrawLetterSize(DET_g_EditObjectTD[9], 0.266889, 0.893155);
    TextDrawAlignment(DET_g_EditObjectTD[9], 1);
    TextDrawColor(DET_g_EditObjectTD[9], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[9], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[9], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[9], 51);
    TextDrawFont(DET_g_EditObjectTD[9], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[9], 1);

    DET_g_EditObjectTD[10] = TextDrawCreate(517.333007, 230.471191, "ROT");
    TextDrawLetterSize(DET_g_EditObjectTD[10], 0.238000, 1.012621);
    TextDrawAlignment(DET_g_EditObjectTD[10], 1);
    TextDrawColor(DET_g_EditObjectTD[10], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[10], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[10], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[10], 51);
    TextDrawFont(DET_g_EditObjectTD[10], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[10], 1);

    DET_g_EditObjectTD[11] = TextDrawCreate(492.888885, 251.875549, "ld_beat:left");
    TextDrawLetterSize(DET_g_EditObjectTD[11], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[11], 17.777811, 15.431104);
    TextDrawAlignment(DET_g_EditObjectTD[11], 1);
    TextDrawColor(DET_g_EditObjectTD[11], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[11], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[11], 0);
    TextDrawFont(DET_g_EditObjectTD[11], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[11], true);

    DET_g_EditObjectTD[12] = TextDrawCreate(521.333618, 250.382232, "ld_beat:right");
    TextDrawLetterSize(DET_g_EditObjectTD[12], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[12], 19.111135, 16.426673);
    TextDrawAlignment(DET_g_EditObjectTD[12], 1);
    TextDrawColor(DET_g_EditObjectTD[12], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[12], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[12], 0);
    TextDrawFont(DET_g_EditObjectTD[12], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[12], true);

    DET_g_EditObjectTD[13] = TextDrawCreate(491.555633, 268.799957, "ld_beat:left");
    TextDrawLetterSize(DET_g_EditObjectTD[13], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[13], 17.777769, 14.933345);
    TextDrawAlignment(DET_g_EditObjectTD[13], 1);
    TextDrawColor(DET_g_EditObjectTD[13], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[13], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[13], 0);
    TextDrawFont(DET_g_EditObjectTD[13], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[13], true);

    DET_g_EditObjectTD[14] = TextDrawCreate(522.666809, 268.302215, "ld_beat:right");
    TextDrawLetterSize(DET_g_EditObjectTD[14], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[14], 17.333328, 16.924436);
    TextDrawAlignment(DET_g_EditObjectTD[14], 1);
    TextDrawColor(DET_g_EditObjectTD[14], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[14], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[14], 0);
    TextDrawFont(DET_g_EditObjectTD[14], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[14], true);

    DET_g_EditObjectTD[15] = TextDrawCreate(491.111053, 287.217864, "ld_beat:left");
    TextDrawLetterSize(DET_g_EditObjectTD[15], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[15], 17.777759, 15.928884);
    TextDrawAlignment(DET_g_EditObjectTD[15], 1);
    TextDrawColor(DET_g_EditObjectTD[15], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[15], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[15], 0);
    TextDrawFont(DET_g_EditObjectTD[15], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[15], true);

    DET_g_EditObjectTD[16] = TextDrawCreate(523.555480, 288.213256, "ld_beat:right");
    TextDrawLetterSize(DET_g_EditObjectTD[16], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[16], 17.333328, 14.933338);
    TextDrawAlignment(DET_g_EditObjectTD[16], 1);
    TextDrawColor(DET_g_EditObjectTD[16], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[16], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[16], 0);
    TextDrawFont(DET_g_EditObjectTD[16], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[16], true);

    DET_g_EditObjectTD[17] = TextDrawCreate(472.888977, 209.066726, "Object Edit Menu");
    TextDrawLetterSize(DET_g_EditObjectTD[17], 0.366889, 1.719466);
    TextDrawAlignment(DET_g_EditObjectTD[17], 1);
    TextDrawColor(DET_g_EditObjectTD[17], 1);
    TextDrawSetShadow(DET_g_EditObjectTD[17], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[17], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[17], 51);
    TextDrawFont(DET_g_EditObjectTD[17], 0);
    TextDrawSetProportional(DET_g_EditObjectTD[17], 1);

    DET_g_EditObjectTD[18] = TextDrawCreate(530.222534, 334.506500, "ld_chat:thumbup");
    TextDrawLetterSize(DET_g_EditObjectTD[18], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[18], 15.555522, 16.426633);
    TextDrawAlignment(DET_g_EditObjectTD[18], 1);
    TextDrawColor(DET_g_EditObjectTD[18], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[18], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[18], 0);
    TextDrawFont(DET_g_EditObjectTD[18], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[18], true);

    DET_g_EditObjectTD[19] = TextDrawCreate(508.444335, 334.506622, "ld_chat:thumbdn");
    TextDrawLetterSize(DET_g_EditObjectTD[19], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[19], 16.444488, 16.924453);
    TextDrawAlignment(DET_g_EditObjectTD[19], 1);
    TextDrawColor(DET_g_EditObjectTD[19], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[19], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[19], 0);
    TextDrawFont(DET_g_EditObjectTD[19], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[19], true);
    
    DET_g_EditObjectTD[20] = TextDrawCreate(551.332702, 309.624511, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[20], 0.000000, 2.238393);
    TextDrawTextSize(DET_g_EditObjectTD[20], 467.777618, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[20], 1);
    TextDrawColor(DET_g_EditObjectTD[20], 0);
    TextDrawUseBox(DET_g_EditObjectTD[20], true);
    TextDrawBoxColor(DET_g_EditObjectTD[20], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[20], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[20], 0);
    TextDrawFont(DET_g_EditObjectTD[20], 0);

    DET_g_EditObjectTD[21] = TextDrawCreate(485.333404, 311.608947, "Update~n~rate");
    TextDrawLetterSize(DET_g_EditObjectTD[21], 0.129555, 0.853333);
    TextDrawAlignment(DET_g_EditObjectTD[21], 2);
    TextDrawColor(DET_g_EditObjectTD[21], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[21], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[21], 1);
    TextDrawBackgroundColor(DET_g_EditObjectTD[21], 51);
    TextDrawFont(DET_g_EditObjectTD[21], 2);
    TextDrawSetProportional(DET_g_EditObjectTD[21], 1);

    DET_g_EditObjectTD[22] = TextDrawCreate(546.000000, 313.606658, "usebox");
    TextDrawLetterSize(DET_g_EditObjectTD[22], 0.000000, 1.287283);
    TextDrawTextSize(DET_g_EditObjectTD[22], 497.111083, 0.000000);
    TextDrawAlignment(DET_g_EditObjectTD[22], 1);
    TextDrawColor(DET_g_EditObjectTD[22], 0);
    TextDrawUseBox(DET_g_EditObjectTD[22], true);
    TextDrawBoxColor(DET_g_EditObjectTD[22], 102);
    TextDrawSetShadow(DET_g_EditObjectTD[22], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[22], 0);
    TextDrawFont(DET_g_EditObjectTD[22], 0);

    DET_g_EditObjectTD[23] = TextDrawCreate(501.777954, 312.106658, "ld_beat:left");
    TextDrawLetterSize(DET_g_EditObjectTD[23], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[23], 17.333320, 15.431093);
    TextDrawAlignment(DET_g_EditObjectTD[23], 1);
    TextDrawColor(DET_g_EditObjectTD[23], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[23], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[23], 0);
    TextDrawFont(DET_g_EditObjectTD[23], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[23], true);

    DET_g_EditObjectTD[24] = TextDrawCreate(525.777893, 311.608917, "ld_beat:right");
    TextDrawLetterSize(DET_g_EditObjectTD[24], 0.000000, 0.000000);
    TextDrawTextSize(DET_g_EditObjectTD[24], 17.333330, 16.426651);
    TextDrawAlignment(DET_g_EditObjectTD[24], 1);
    TextDrawColor(DET_g_EditObjectTD[24], -1);
    TextDrawSetShadow(DET_g_EditObjectTD[24], 0);
    TextDrawSetOutline(DET_g_EditObjectTD[24], 0);
    TextDrawFont(DET_g_EditObjectTD[24], 4);
    TextDrawSetSelectable(DET_g_EditObjectTD[24], true);
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_editobject.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_editobject.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_EDITOBJECT);
    if(funcidx("d_editobj_detutilsinit") != -1)
    {
        CallLocalFunction("d_editobj_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_editobj_detutilsinit(

forward d_editobj_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_EDITOBJECT);
    if(funcidx("d_editobj_detutilsexit") != -1)
    {
        CallLocalFunction("d_editobj_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_editobj_detutilsexit(

forward d_editobj_detutilsexit();

/*
public OnDETUtilsInit()
{
    // Set the default return value.
    #emit ZERO.pri
    #if defined d_als_detutilsinit
        d_als_detutilsinit();
    #endif
    
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_als.log", "[DETUtils]: (debug) - Loaded.");
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