/*
 * SA:MP | DEntisT's Utilites 
 * interior functions
 *
 *
 * Thanks to:
 *
 * @DEntisT (me) - actual include
 *                 from stratch
 *
 */

#if defined DEV_MODE

#include <a_samp>

#endif

#define DisableDefaultInteriors DisableInteriorEnterExits

#define MAX_INTERIORS 300

#if !defined IsValidString
        #define IsValidString(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

enum e_DETUtils_INTERIOR_DATA
{
    e_DETUtils_INTERIOR_NAME[32],

    Float:e_DETUtils_INTENTRANCE_X,
    Float:e_DETUtils_INTENTRANCE_Y,
    Float:e_DETUtils_INTENTRANCE_Z,
    Float:e_DETUtils_INTENTRANCE_A,

    Float:e_DETUtils_INTEXIT_X,
    Float:e_DETUtils_INTEXIT_Y,
    Float:e_DETUtils_INTEXIT_Z,
    Float:e_DETUtils_INTEXIT_A,

    e_DETUtils_INTERIOR_INTID,
    e_DETUtils_INTERIOR_INTID_OUT,
    e_DETUtils_INTERIOR_VWID,
    e_DETUtils_INTERIOR_VWID_OUT,

    e_DETUtils_INTERIOR_PICKUP,
    e_DETUtils_INTERIOR_PICKUPID,
    e_DETUtils_INTERIOR_3DLABEL,
    e_DETUtils_INTERIOR_3DLABELID
};

new gDETUtils_PlayersInterior[MAX_PLAYERS];

new gDETUtils_InteriorData[MAX_INTERIORS][e_DETUtils_INTERIOR_DATA];

new gDETUtils_Interiorid;

/*

                                                              
88        88                            88                    
88        88                            88                    
88        88                            88                    
88aaaaaaaa88   ,adPPYba,    ,adPPYba,   88   ,d8   ,adPPYba,  
88""""""""88  a8"     "8a  a8"     "8a  88 ,a8"    I8[    ""  
88        88  8b       d8  8b       d8  8888[       `"Y8ba,   
88        88  "8a,   ,a8"  "8a,   ,a8"  88`"Yba,   aa    ]8I  
88        88   `"YbbdP"'    `"YbbdP"'   88   `Y8a  `"YbbdP"'  
                                                              
                                                              

*/

#define DETUtils_INTERIORS_TRUE 1
#define DETUtils_INTERIORS_FALSE 0

#define INTERIOR_ACTION_ENTER 0
#define INTERIOR_ACTION_EXIT 1

gDETUtils_InteriorLoadingTime(const playerid)
{
    TogglePlayerControllable(playerid,true);
}

DETUtils_OnPlayerNearEntrance(playerid);
public DETUtils_OnPlayerNearEntrance(playerid)
{
    new DETUtils_InteriorFunctionName[100];
    new DETUtils_InteriorActionid;
    TogglePlayerControllable(playerid,false);
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            DETUtils_InteriorActionid = 0;
            format(DETUtils_InteriorFunctionName,sizeof(DETUtils_InteriorFunctionName),
                "%s@int",gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_NAME]);

            if(funcidx(DETUtils_InteriorFunctionName) != -1) CallLocalFunction(DETUtils_InteriorFunctionName,
                                                                "ii",playerid,DETUtils_InteriorActionid);

            SetPlayerInterior( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_INTID] );
            SetPlayerVirtualWorld( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID] );
            
            SetPlayerPos( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_X], gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Y], \
            gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Z] );
            
            SetPlayerFacingAngle( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_A] );
            SetCameraBehindPlayer( playerid );
            
            SetPlayerTime( playerid, 12, 0 );
            gDETUtils_InteriorLoadingTime(playerid);
            
            gDETUtils_PlayersInterior[ playerid ] = i;
            
        }
        else if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTEXIT_Z]) && \
        GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID])
        {
            SetPlayerVirtualWorld( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] );
            SetPlayerInterior( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_INTID_OUT] );
            
            SetPlayerPos( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], \
            gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z] );
            
            SetPlayerFacingAngle( playerid, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_A] );
            SetCameraBehindPlayer( playerid );
            gDETUtils_InteriorLoadingTime(playerid);

            DETUtils_InteriorActionid = 1;
            format(DETUtils_InteriorFunctionName,sizeof(DETUtils_InteriorFunctionName),
                "%s@int",gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_NAME]);

            if(funcidx(DETUtils_InteriorFunctionName) != -1) CallLocalFunction(DETUtils_InteriorFunctionName,"ii",playerid,DETUtils_InteriorActionid);

            gDETUtils_PlayersInterior[ playerid ] = -1;
        }
    }
    return DETUtils_INTERIORS_TRUE;
}

public OnPlayerDisconnect(playerid, reason)
{
    ClearPlayerInteriorData(playerid);
    if(funcidx("aint_ALS_OnPlayerDisconnect") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerDisconnect", "ii", playerid, reason);
    }
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif

#define OnPlayerDisconnect aint_ALS_OnPlayerDisconnect

forward aint_ALS_OnPlayerDisconnect(playerid, reason);

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if( newkeys == KEY_SECONDARY_ATTACK)
    {
        if(GetPlayerState(playerid) == 1)
        {
            DETUtils_OnPlayerNearEntrance(playerid);
        }

        if( GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_NONE && \
        GetPlayerSpecialAction(playerid ) != SPECIAL_ACTION_CUFFED)
        {
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        }
    }
    if(funcidx("aint_ALS_OnPlayerKeyStateChange") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerKeyStateChange", "iii", playerid, newkeys, oldkeys);
    }
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif

#define OnPlayerKeyStateChange aint_ALS_OnPlayerKeyStateChange

forward aint_ALS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);

public OnPlayerUpdate(playerid)
{
    for(new i; i < MAX_INTERIORS; i++)
    {
        if( IsPlayerInRangeOfPoint( playerid, 1.5, gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_X], \
        gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Y], gDETUtils_InteriorData[ i ][e_DETUtils_INTENTRANCE_Z]) \
        && GetPlayerVirtualWorld( playerid ) == gDETUtils_InteriorData[ i ][e_DETUtils_INTERIOR_VWID_OUT] \
        && !IsPlayerInAnyVehicle( playerid ))
        {
            new DETUtils_InteriorName[100];
            format(DETUtils_InteriorName,sizeof(DETUtils_InteriorName),"Property: %s",gDETUtils_InteriorData[ i ][ e_DETUtils_INTERIOR_NAME ]);
            
            GameTextForPlayer(playerid, DETUtils_InteriorName, 5000, 2);
        }
    }
    if(funcidx("aint_ALS_OnPlayerUpdate") != -1)
    {
        CallLocalFunction("aint_ALS_OnPlayerUpdate", "i", playerid);
    }
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate aint_ALS_OnPlayerUpdate

forward aint_ALS_OnPlayerUpdate(playerid);

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

stock Create3DLabelAndPickup( 
        const DETUtils_LabelString[], 
        Float:DETUtils_xPosition, 
        Float:DETUtils_yPosition, 
        Float:DETUtils_zPosition, 
        DETUtils_Interior, 
        DETUtils_VirtualWorld, 
        DETUtils_Pickupid, 
        Float:DETUtils_LabelRadius ) 
{
    if(IsValidString(DETUtils_LabelString))
        return DETUtils_INTERIORS_FALSE;

    if(DETUtils_Interior < 0)
        return DETUtils_INTERIORS_FALSE;

    if(DETUtils_VirtualWorld < 0)
        return DETUtils_INTERIORS_FALSE;

    if(DETUtils_LabelRadius <= 0)
        return DETUtils_INTERIORS_FALSE;

    if(DETUtils_Pickupid < 0)
        return DETUtils_INTERIORS_FALSE;

    CreateDynamic3DTextLabel(
                            DETUtils_LabelString, 
                            0x0059FFAA, 
                            DETUtils_xPosition, 
                            DETUtils_yPosition, 
                            DETUtils_zPosition, 
                            DETUtils_LabelRadius, 
                            INVALID_PLAYER_ID, 
                            INVALID_VEHICLE_ID, 
                            0, 
                            DETUtils_VirtualWorld, 
                            DETUtils_Interior, 
                            -1, 
                            20.0);
    CreateDynamicPickup(
                    DETUtils_Pickupid, 
                    1, 
                    DETUtils_xPosition, 
                    DETUtils_yPosition, 
                    DETUtils_zPosition, 
                    DETUtils_VirtualWorld, 
                    DETUtils_Interior);

    return DETUtils_INTERIORS_TRUE;
}

stock CreateCustomInterior(
        const DETUtils_InteriorName[], 
        Float:DETUtils_xEntrance, 
        Float:DETUtils_yEntrance, 
        Float:DETUtils_zEntrance, 
        Float:DETUtils_xExit, 
        Float:DETUtils_yExit, 
        Float:DETUtils_zExit, 
        DETUtils_eInteriorid, 
        DETUtils_xInteriorid, 
        DETUtils_eVirtualWorldid, 
        DETUtils_xVirtualWorldid)
{
    printf("Interior '%s' successfully created, entrance is set to: %f, %f, %f.",
            DETUtils_InteriorName,
            Float:DETUtils_xEntrance, 
            Float:DETUtils_yEntrance, 
            Float:DETUtils_zEntrance);

    gDETUtils_Interiorid++;

    strmid(gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_NAME], 
            DETUtils_InteriorName, 
            0, 
            strlen(DETUtils_InteriorName), 
            255);

    printf("Interior '%s' has an id %d.",DETUtils_InteriorName,gDETUtils_Interiorid);

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_X] = DETUtils_xEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Y] = DETUtils_yEntrance;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTENTRANCE_Z] = DETUtils_zEntrance;

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_X] = DETUtils_xExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Y] = DETUtils_yExit;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTEXIT_Z] = DETUtils_zExit;

    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID] = DETUtils_eInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_INTID_OUT] = DETUtils_xInteriorid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID] = DETUtils_eVirtualWorldid;
    gDETUtils_InteriorData[gDETUtils_Interiorid][e_DETUtils_INTERIOR_VWID_OUT] = DETUtils_xVirtualWorldid;

    new DETUtils_EntranceLabelString[300];
    format(DETUtils_EntranceLabelString,sizeof(DETUtils_EntranceLabelString),"{ffffff}[ %s ]\n"col_white"Enter here!",DETUtils_InteriorName);

    Create3DLabelAndPickup(DETUtils_EntranceLabelString, DETUtils_xEntrance,DETUtils_yEntrance,DETUtils_zEntrance, -1, -1, 19133, 2.0);

    Create3DLabelAndPickup("Exit here!", DETUtils_xExit,DETUtils_yExit,DETUtils_zExit, -1, -1, 19133, 2.0);
    return DETUtils_INTERIORS_TRUE;
}

stock bool:IsPlayerInCustomInterior(playerid)
{
    if(gDETUtils_PlayersInterior[ playerid ] = -1) return false;
    else return true;
}

stock ClearPlayerInteriorData(playerid)
{
    gDETUtils_PlayersInterior[playerid] = -1;
    return DETUtils_INTERIORS_TRUE;
}

stock SetInteriorEntranceCustomAngles(
        const DETUtils_CustomInteriorid,
        Float:DETUtils_aAngle,
        Float:DETUtils_bAngle)
{
    gDETUtils_InteriorData[DETUtils_CustomInteriorid][e_DETUtils_INTENTRANCE_A] = DETUtils_aAngle;
    gDETUtils_InteriorData[DETUtils_CustomInteriorid][e_DETUtils_INTEXIT_A] = DETUtils_bAngle;
    return DETUtils_INTERIORS_TRUE;
}

/*

                                                                                                 
88888888888                                                          db         88888888ba   88  
88                          ,d                                      d88b        88      "8b  88  
88                          88                                     d8'`8b       88      ,8P  88  
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,         d8'  `8b      88aaaaaa8P'  88  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8        d8YaaaaY8b     88""""""'    88  
88              )888(       88     88          ,adPPPPP88       d8""""""""8b    88           88  
88            ,d8" "8b,     88,    88          88,    ,88      d8'        `8b   88           88  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8     d8'          `8b  88           88  
                                                                                                 
                                                                                                 
*/

#define interior%0(%1) \
    forward%0@int(%1,DETUtils_Actionid); \
    public%0@int(%1,DETUtils_Actionid)

stock SetPlayerCustomInterior(DETUtils_p_Playerid, pDETUtils_Interiorid)
{
    if(pDETUtils_Interiorid < -1)
        return DETUtils_INTERIORS_FALSE;

    gDETUtils_PlayersInterior[DETUtils_p_Playerid] = pDETUtils_Interiorid;
    return DETUtils_INTERIORS_TRUE;
}

#define IsInteriorActionPerformed(%0) \
    DETUtils_Actionid == %0

static AnnounceLibraryLoaded_int()
{
    print("|======================================|");
    print("            a_interiors.inc             ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    AnnounceLibraryLoaded_int();
    a_int_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_int_main

#else

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_int();
    return DETUtils_INTERIORS_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_int_OnFilterScriptInit

forward a_int_OnFilterScriptInit();

#endif