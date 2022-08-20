/*
 * 
 * DETUtils
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

    #warning [DETUtils]: (warning) - 'd_fmargs' is not compatible with 'y_va' include.

#endif

#include "d_fmargs_sscanf"

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
    Valid,
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 1;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 1;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 2;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 2;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    
    @DETUTILSFMARGS_TAGS__:...
)
{
    new time = duration;
    if(funcidx("OnPlayerScreenUpdate") != -1)
    {
        CallLocalFunction("OnPlayerScreenUpdate", "ii", i, 4);
        SetTimerEx("OnPlayerScreenUpdate", time, false, "ii", i, 5);
    }
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 3;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 3;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    
    @DETUTILSFMARGS_TAGS__:...
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 4;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 4;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    new Text:textid;

    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 5;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 5;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    new PlayerText:textid;
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 6;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 6;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 7;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 7;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    @DETUTILSFMARGS_TAGS__:...
)
{
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 8;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 8;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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
    
    @DETUTILSFMARGS_TAGS__:...
)
{
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 9;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully called.", _Functionid);
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
    #if defined DETUTILS_DEBUG_MODE
    _Functionid = 9;
    printf("[DETUtils]: (debug) - fmargs :: Function id : %i successfully performed.", _Functionid);
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

public OnDETUtilsInit()
{
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_fmargs.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_fmargs.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    LoadDETUtilsScript(DETUTILS_SCRIPT_FMARGS);
    if(funcidx("d_fmargs_detutilsinit") != -1)
    {
        CallLocalFunction("d_fmargs_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_fmargs_detutilsinit(

forward d_fmargs_detutilsinit();