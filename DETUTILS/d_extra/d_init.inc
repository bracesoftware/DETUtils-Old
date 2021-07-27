/*

                            =============================
                              SA:MP DEntisT's Utilities
                            =============================

Legal:
    Version: MPL 1.1
    
    The contents of this file are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this file except in compliance with 
    the License. You may obtain a copy of the License at 
    http://www.mozilla.org/MPL/
    
    Software distributed under the License is distributed on an "AS IS" basis,
    WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
    for the specific language governing rights and limitations under the
    License.
    
    The Original Code is SA:MP | utils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:
    DEntisT

Thanks:
    open.mp team - ideas, support, help during development

Very special thanks to:
    Thiadmer - PAWN, whose limits continue to amaze me!
    Kye/Kalcor - SA:MP
    SA:MP Team past, present and future - SA:MP
    open.mp team present and future - SA:MP

Optional plugins:
    Incognito - streamer

*/

#if defined d_init_included

    #endscript

#endif

#define d_init_included

#if defined DEV_MODE

#tryinclude <a_samp>

#if !defined _inc_a_samp

    #error [samp-detutils]: (error) - You need to have a_samp.inc file in your includes folder.

#endif

#endif

#if defined d_data_included

    #error [samp-detutils]: (error) - Unusable code reached.

#endif

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

static const DET_g_Version[1][10] = { "1.0" };

#if !defined FILTERSCRIPT

public OnGameModeInit()
{
    if(funcidx("a_init_OnGameModeInit") != -1)
    {
        a_init_OnGameModeInit();
    }
    OnDETUtilsInit();
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit a_init_OnGameModeInit

forward a_init_OnGameModeInit();

#else

public OnFilterScriptInit()
{
    if(funcidx("a_init_OnFilterScriptInit") != -1)
    {
        a_init_OnFilterScriptInit();
    }
    OnDETUtilsInit();
    return 1;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_init_OnFilterScriptInit

forward a_init_OnFilterScriptInit();

#endif

forward OnDETUtilsInit();
public OnDETUtilsInit()
{
    AnnounceLibraryLoading_init();
    return 1;
}

static AnnounceLibraryLoading_init()
{
    print("|======================================|");
    print("                                        ");
    print("            SA:MP | DETUtils            ");
    print("        System is now loading...        ");
    print("                                        ");
    printf("              Version: %s              ", DET_g_Version);
    print("                                        ");
    print("               By: DEntisT              ");
    print("                                        ");
    print("|======================================|");
    print("                                        ");
    print("                                        ");
    print("                                        ");
    print("                                        ");
    print("                                        ");
    print("                                        ");
}