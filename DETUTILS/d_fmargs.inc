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
    
    The Original Code is SA:MP | DETUtils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:
    DEntisT

Thanks:
    Zeex - ideas and ZCMD
    open.mp team - ideas, support, help during development

Very special thanks to:
    Thiadmer - PAWN, whose limits continue to amaze me!
    Kye/Kalcor - SA:MP
    SA:MP Team past, present and future - SA:MP
    open.mp team present and future - SA:MP

Optional plugins:
    Incognito - streamer

*/

#if defined DEV_MODE

#include <a_samp>

#endif

#if defined d_fmargs_included
    #endinput
#endif

#define d_fmargs_included

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

/*
                                         
88                                   88  
88                                   88  
88                                   88  
88  88,dPYba,,adPYba,   8b,dPPYba,   88  
88  88P'   "88"    "8a  88P'    "8a  88  
88  88      88      88  88       d8  88  
88  88      88      88  88b,   ,a8"  88  
88  88      88      88  88`YbbdP"'   88  
                        88               
                        88               
*/

stock
    fmargs_SendClientMessage
(
    p_id,
    color,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 1;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start
 
        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        SendClientMessage
        (
            p_id,
            color,
            utils_unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 1;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        SendClientMessage
        (
            p_id,
            color,
            utils_message_string
        )
    ;
}

stock
    fmargs_SendClientMessageToAll
(
    color,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 2;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start
 
        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        SendClientMessageToAll
        (
            color,
            utils_unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 2;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        SendClientMessageToAll
        (
            color,
            utils_message_string
        )
    ;
}

stock
    fmargs_GameTextForPlayer
(
    i,
    
    const utils_message_string[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            
            end > start;
            
            end -= 4
        )
        {
            #emit LREF.pri end
            
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        
        #emit PUSH.C 144
        
        #emit PUSH.C utils_unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForPlayer
        (
            i,
            
            utils_unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        GameTextForPlayer
        (
            i,
            
            utils_message_string,
            
            duration,
            
            style
        )
    ;
}

stock
    fmargs_GameTextForAll
(
    const utils_message_string[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            
            end > start;
            
            end -= 4
        )
        {
            #emit LREF.pri end
            
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        
        #emit PUSH.C 144
        
        #emit PUSH.C utils_unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForAll
        (
            utils_unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        GameTextForAll
        (
            utils_message_string,
            
            duration,
            
            style
        )
    ;
}

stock
    fmargs_TextDrawCreate
(
    Float:x,
    Float:y,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 5;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start
 
        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        TextDrawCreate
        (
            x,
            y,
            utils_unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 5;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        TextDrawCreate
        (
            x,
            y,
            utils_message_string
        )
    ;
}

stock
    fmargs_CreatePlayerTextDraw
(
    i,
    Float:x,
    Float:y,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 6;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start
 
        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        CreatePlayerTextDraw
        (
            i,
            x,
            y,
            utils_unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 6;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    return
        CreatePlayerTextDraw
        (
            i,
            x,
            y,
            utils_message_string
        )
    ;
}

stock
    fmargs_TextDrawSetString
(
    Text:id,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 7;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format

        TextDrawSetString
        (
            id,
            utils_unspecified_string
        )
        ;

        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 7;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    return
        TextDrawSetString
        (
            id,
            utils_message_string
        )
    ;
}

stock
    fmargs_PlayerTextDrawSetString
(
    i,
    Text:id,
    const utils_message_string[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 8;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        start,
        end,
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            end > start;
            end -= 4
        )
        {
            #emit LREF.pri end
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        #emit PUSH.C 144
        #emit PUSH.C utils_unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format

        PlayerTextDrawSetString
        (
            i,id,
            utils_unspecified_string
        )
        ;

        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 8;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    return
        PlayerTextDrawSetString
        (
            i,id,
            utils_message_string
        )
    ;
}

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

#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif

#define SendClientMessage fmargs_SendClientMessage

#if defined _ALS_SendClientMessageToAll
    #undef SendClientMessageToAll
#else
    #define _ALS_SendClientMessageToAll
#endif

#define SendClientMessageToAll fmargs_SendClientMessageToAll

#if defined _ALS_GameTextForPlayer
    #undef GameTextForPlayer
#else
    #define _ALS_GameTextForPlayer
#endif

#define GameTextForPlayer fmargs_GameTextForPlayer

#if defined _ALS_GameTextForAll
    #undef GameTextForAll
#else
    #define _ALS_GameTextForAll
#endif

#define GameTextForAll fmargs_GameTextForAll

#if defined _ALS_TextDrawCreate
    #undef TextDrawCreate
#else
    #define _ALS_TextDrawCreate
#endif

#define TextDrawCreate fmargs_TextDrawCreate

#if defined _ALS_CreatePlayerTextDraw
    #undef CreatePlayerTextDraw
#else
    #define _ALS_CreatePlayerTextDraw
#endif

#define CreatePlayerTextDraw fmargs_CreatePlayerTextDraw

#if defined _ALS_TextDrawSetString
    #undef TextDrawSetString
#else
    #define _ALS_TextDrawSetString
#endif

#define TextDrawSetString fmargs_TextDrawSetString

#if defined _ALS_PlayerTextDrawSetString
    #undef PlayerTextDrawSetString
#else
    #define _ALS_PlayerTextDrawSetString
#endif

#define PlayerTextDrawSetString fmargs_PlayerTextDrawSetString

static AnnounceLibraryLoaded_fmargs()
{
    print("|======================================|");
    print("              d_fmargs.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_fmargs.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_fmargs.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_fmargs();
    a_fmargs_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_fmargs_main

#else

#define detutils_fmargs_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_fmargs();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_fmargs.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_fmargs.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_fmargs_OnfsInit") != -1)
    {
        CallLocalFunction("a_fmargs_OnfsInit", "i", playerid);
    }
    return detutils_fmargs_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_fmargs_OnfsInit

forward a_fmargs_OnfsInit();

#endif

stock
    fmargs_SendRconCommand
(
    const utils_message_string[],
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    utils_Functionid = 9;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", utils_Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        utils_unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri utils_message_string
        
        #emit STOR.pri start

        for
        (
            end = start + (args - 12);
            
            end > start;
            
            end -= 4
        )
        {
            #emit LREF.pri end
            
            #emit PUSH.pri
        }
        #emit PUSH.S utils_message_string
        
        #emit PUSH.C 144
        
        #emit PUSH.C utils_unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        SendRconCommand
        (
            utils_unspecified_string
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    utils_Functionid = 9;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", utils_Functionid);
    #endif
    return
        SendRconCommand
        (
            utils_message_string
        )
    ;
}

#if defined _ALS_SendRconCommand
    #undef SendRconCommand
#else
    #define _ALS_SendRconCommand
#endif

#define SendRconCommand fmargs_SendRconCommand