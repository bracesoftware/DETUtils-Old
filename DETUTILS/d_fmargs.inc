/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides using format
 *   inside functions.
 *
 */

#if defined _INC_y_va

    #warning [samp-detutils]: (warning) - 'd_fmargs' is not compatible with 'y_va' include.

#endif

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

// for d_visual

enum enum_TextDrawData
{
    bool:Valid,
    Float:Pos[2],
    Float:OldPos[2]
}

new g_TextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];
new g_PlayerTextDrawData[MAX_TEXT_DRAWS][enum_TextDrawData];

static stock const d_fmargs_emitStuff;

#if defined d_fmargs_emitStuff

stock
    fmargs_SendClientMessage
(
    p_id,
    color,
    const _StringArgs[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 1;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        SendClientMessage
        (
            p_id,
            color,
            _unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 1;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        SendClientMessage
        (
            p_id,
            color,
            _StringArgs
        )
    ;
}

stock
    fmargs_SendClientMessageToAll
(
    color,
    const _StringArgs[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 2;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        SendClientMessageToAll
        (
            color,
            _unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 2;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return 
        SendClientMessageToAll
        (
            color, 
            _StringArgs
        )
    ;
}

#define DETUTILS_HOOK_FMARGS_GMT

#if defined DETUTILS_HOOK_FMARGS_GMT

stock
    fmargs_GameTextForPlayer
(
    i,
    
    const _StringArgs[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    new time = duration;
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 4);
        SetTimerEx("OnPlayerScreenUpdate", time, false, "ii", i, 5);
    }
    #if defined detutils_debug
    _Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
        
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
        #emit PUSH.S _StringArgs
        
        #emit PUSH.C 144
        
        #emit PUSH.C _unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForPlayer
        (
            i,
            
            _unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 3;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        GameTextForPlayer
        (
            i,
            
            _StringArgs,
            
            duration,
            
            style
        )
    ;
}

stock
    fmargs_GameTextForAll
(
    const _StringArgs[],
    
    duration,
    
    style,
    
    {Float,_}:...
)
{
    new time = duration;
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        for(new i; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i))
        {
            CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 4);
            SetTimerEx("OnPlayerScreenUpdate", time, false, "ii", i, 5);
        }
    }
    #if defined detutils_debug
    _Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
        
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
        #emit PUSH.S _StringArgs
        
        #emit PUSH.C 144
        
        #emit PUSH.C _unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        GameTextForAll
        (
            _unspecified_string,
            
            duration,
            
            style
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 4;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        GameTextForAll
        (
            _StringArgs,
            
            duration,
            
            style
        )
    ;
}

#endif

stock
    Text:fmargs_TextDrawCreate
(
    Float:x,
    Float:y,
    const _StringArgs[],
    {Float,_}:...
)
{
    new Text:textid;

    #if defined detutils_debug
    _Functionid = 5;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        textid = TextDrawCreate
        (
            x,
            y,
            _unspecified_string
        )
        ;
        #if defined detutils_complete_error_boom
        g_TextDrawData[textid][Pos][0] = x;
        g_TextDrawData[textid][Pos][1] = y;
        if(g_TextDrawData[textid][Pos][0] != g_TextDrawData[textid][OldPos][0] || g_TextDrawData[textid][Pos][1] != g_TextDrawData[textid][OldPos][1])
        {
            if(funcidx("OnPlayerScreenUpdate") != -1)
            {
                for(new i; i < MAX_PLAYERS; i++)
                {
                    CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 6);
                }
            }
        }
        g_TextDrawData[textid][OldPos][0] = x;
        g_TextDrawData[textid][OldPos][1] = y;
        #endif
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 5;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    
    textid = TextDrawCreate
        (
            x,
            y,
            _StringArgs
        )
    ;
    g_TextDrawData[textid][Pos][0] = x;
    g_TextDrawData[textid][Pos][1] = y;
    if(g_TextDrawData[textid][Valid] == 1 && 
    g_TextDrawData[textid][Pos][0] != g_TextDrawData[textid][OldPos][0] || g_TextDrawData[textid][Pos][1] != g_TextDrawData[textid][OldPos][1])
    {
        if(funcidx("OnPlayerScreenUpdate") != -1)
        {
            for(new i; i < MAX_PLAYERS; i++)
            {
                CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 6);
            }
        }
    }
    g_TextDrawData[textid][OldPos][0] = x;
    g_TextDrawData[textid][OldPos][1] = y;
    g_TextDrawData[textid][Valid] = 1;
    return textid;
}

stock
    PlayerText:fmargs_CreatePlayerTextDraw
(
    i,
    Float:x,
    Float:y,
    const _StringArgs[],
    {Float,_}:...
)
{
    new PlayerText:textid;
    #if defined detutils_debug
    _Functionid = 6;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args
 
    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format
 
        textid = CreatePlayerTextDraw
        (
            i,
            x,
            y,
            _unspecified_string
        )
        ;
 
        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 6;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    
    textid = CreatePlayerTextDraw
        (
            i,
            x,
            y,
            _StringArgs
        )
    ;
    g_PlayerTextDrawData[textid][Pos][0] = x;
    g_PlayerTextDrawData[textid][Pos][1] = y;
    if(g_PlayerTextDrawData[textid][Valid] == 1 && 
    g_PlayerTextDrawData[textid][Pos][0] != g_PlayerTextDrawData[textid][OldPos][0] || g_PlayerTextDrawData[textid][Pos][1] != g_PlayerTextDrawData[textid][OldPos][1])
    {
        if(funcidx("OnPlayerScreenUpdate") != -1)
        {
            for(new i; i < MAX_PLAYERS; i++)
            {
                CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 7);
            }
        }
    }
    g_PlayerTextDrawData[textid][OldPos][0] = x;
    g_PlayerTextDrawData[textid][OldPos][1] = y;
    g_PlayerTextDrawData[textid][Valid] = 1;
    return textid;
}

stock
    Text:fmargs_TextDrawSetString
(
    Text:id,
    const _StringArgs[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 7;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format

        TextDrawSetString
        (
            id,
            _unspecified_string
        )
        ;

        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 7;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        TextDrawSetString
        (
            id,
            _StringArgs
        )
    ;
}

stock
    PlayerText:fmargs_PlayerTextDrawSetString
(
    i,
    PlayerText:id,
    const _StringArgs[],
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 8;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        start,
        end,
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
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
        #emit PUSH.S _StringArgs
        #emit PUSH.C 144
        #emit PUSH.C _unspecified_string
        #emit PUSH.C args
        #emit SYSREQ.C format

        PlayerTextDrawSetString
        (
            i,id,
            _unspecified_string
        )
        ;

        #emit LCTRL 5
        #emit SCTRL 4
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 8;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        PlayerTextDrawSetString
        (
            i,id,
            _StringArgs
        )
    ;
}

stock
    fmargs_SendRconCommand
(
    const _StringArgs[],
    
    {Float,_}:...
)
{
    #if defined detutils_debug
    _Functionid = 9;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
    #endif
    static
        args,
        
        start,
        
        end,
        
        _unspecified_string[144]
    ;
    #emit LOAD.S.pri 8
    
    #emit STOR.pri args

    if (
        args > 12
    )
    {
        #emit ADDR.pri _StringArgs
        
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
        #emit PUSH.S _StringArgs
        
        #emit PUSH.C 144
        
        #emit PUSH.C _unspecified_string
        
        #emit PUSH.C args
        
        #emit SYSREQ.C format

        SendRconCommand
        (
            _unspecified_string
        )
        ;

        #emit LCTRL 5
        
        #emit SCTRL 4
        
        #emit RETN
    }
    #if defined detutils_debug
    _Functionid = 9;
    printf("[samp-detutils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
    #endif
    return
        SendRconCommand
        (
            _StringArgs
        )
    ;
}

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
/*
#define fmargs_SendClientMessage%4(%0,%1,%3) \
    new scm[512];format(scm,sizeof scm, %3);SendClientMessage(%0,%1,scm)
*/
#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif

#define SendClientMessage fmargs_SendClientMessage
/*
#define fmargs_SendClientMessageToAll%4(%1,%3) \
    new scma[512];format(scma,sizeof scma, %3);SendClientMessageToAll(%1,scma)*/

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

#if defined _ALS_SendRconCommand
    #undef SendRconCommand
#else
    #define _ALS_SendRconCommand
#endif

#define SendRconCommand fmargs_SendRconCommand

// init code

static void:AnnounceLibraryLoaded_fmargs()
{
    LoadDETUtilsScript(DETUTILS_SCRIPT_FMARGS);
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