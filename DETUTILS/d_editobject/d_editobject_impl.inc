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

#define EDITING_MODE_POS (0)
#define EDITING_MODE_ROT (1)

#define OBJECT_TYPE_GLOBAL (0)
#define OBJECT_TYPE_PLAYER (1)
#define OBJECT_TYPE_ATTACHED (2)

#define EDITING_RESPONSE_CANCEL (0)
#define EDITING_RESPONSE_FINAL (1)
#define EDITING_RESPONSE_UPDATE (2)

#define DETUTILS_EDITGLOBALOBJ_CALLBACK "OnPlayerEditGlobalObject"
#define DETUTILS_EDITPLAYEROBJ_CALLBACK "OnPlayerEditPlayerObject"

forward OnPlayerEditGlobalObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
forward OnPlayerEditPlayerObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);

#define DEFAULT_OBJECT_POS_UPDATE_RATE (0.01)



enum enum_PlayerEditObjInfo
{
    ObjectType,
    EditingMode,
    Float:UpdateRate,
    //Global and player objects
    EditedObject,
    Float:EditedObjectPos[3],
    Float:EditedObjectRot[3],
    Float:StartPos[3],
    Float:StartRot[3],
    bool:Editing,
    //Attached objects
    EditedBodyPart
}

new DET_g_PlayerEditObjInfo[MAX_PLAYERS][enum_PlayerEditObjInfo];

stock DET_g_ShowEditingMenu(playerid, bool:show)
{
    if(show)
    {
        DET_g_PlayerEditObjInfo[playerid][Editing] = true;
        for(new i; i < 30; i++)
        {
            TextDrawShowForPlayer(playerid, DET_g_EditObjectTD[i]);
        }
    }
    else if (!show)
    {
        DET_g_PlayerEditObjInfo[playerid][Editing] = false;
        for(new i; i < 30; i++)
        {
            TextDrawHideForPlayer(playerid, DET_g_EditObjectTD[i]);
        }
    }
    return 1;
}

DET_g_ShowMenuAgain(playerid, objectid, objecttype); public DET_g_ShowMenuAgain(playerid, objectid, objecttype)
{
    DET_g_ShowEditingMenu(playerid, true);
    DET_g_PlayerEditObjInfo[playerid][ObjectType] = objecttype;
    new Float:Float[3];
    new EditingMenuString[256];
    DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_POS;
    DET_g_PlayerEditObjInfo[playerid][UpdateRate] = DEFAULT_OBJECT_POS_UPDATE_RATE;

    //object data
    if(objecttype == OBJECT_TYPE_GLOBAL)
    {
        DET_g_PlayerEditObjInfo[playerid][EditedObject] = objectid;
        format(EditingMenuString,sizeof EditingMenuString,
            "~y~EDIOR: ~g~ON~w~~n~Editing object: ~r~%i",
            objectid);
        GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        
        GetObjectPos(objectid, Float[0], Float[1], Float[2]);
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2] = Float[2];

        DET_g_PlayerEditObjInfo[playerid][StartPos][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][StartPos][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][StartPos][2] = Float[2];
        
        GetObjectRot(objectid, Float[0], Float[1], Float[2]);
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2] = Float[2];

        DET_g_PlayerEditObjInfo[playerid][StartRot][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][StartRot][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][StartRot][2] = Float[2];
    }
    if(objecttype == OBJECT_TYPE_PLAYER)
    {
        DET_g_PlayerEditObjInfo[playerid][EditedObject] = objectid;
        format(EditingMenuString,sizeof EditingMenuString,
            "~y~EDIOR: ~g~ON~w~~n~Editing player~n~object: ~r~%i",
            objectid);
        GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        
        GetPlayerObjectPos(playerid, objectid, Float[0], Float[1], Float[2]);
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2] = Float[2];

        DET_g_PlayerEditObjInfo[playerid][StartPos][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][StartPos][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][StartPos][2] = Float[2];
        
        GetPlayerObjectRot(playerid, objectid, Float[0], Float[1], Float[2]);
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2] = Float[2];

        DET_g_PlayerEditObjInfo[playerid][StartRot][0] = Float[0];
        DET_g_PlayerEditObjInfo[playerid][StartRot][1] = Float[1];
        DET_g_PlayerEditObjInfo[playerid][StartRot][2] = Float[2];
    }

    return 1;
}

stock PlayerEditObject(playerid, objectid)
{
    SetTimerEx("DET_g_ShowMenuAgain", 1000, false, "ii", playerid, objectid, OBJECT_TYPE_GLOBAL);
    return 1;
}

stock PlayerEditPlayerObject(playerid, objectid)
{
    SetTimerEx("DET_g_ShowMenuAgain", 1000, false, "ii", playerid, objectid, OBJECT_TYPE_PLAYER);
    return 1;
}

stock PlayerEditAttachedObject(playerid, objectid)
{
    SetTimerEx("DET_g_ShowMenuAgain", 1000, false, "ii", playerid, objectid, OBJECT_TYPE_ATTACHED);
    return 1;
}

stock SetPlayerEditUpdateRate(playerid, Float:rate)
{
    DET_g_PlayerEditObjInfo[playerid][UpdateRate] = rate;
    return 1;
}

stock DET_g_EndPlayerEditMode(playerid)
{
    DET_g_ShowEditingMenu(playerid, false);
    DET_g_PlayerEditObjInfo[playerid][EditedObject] = -1;
    DET_g_PlayerEditObjInfo[playerid][EditedBodyPart] = -1;
    DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_POS;
    DET_g_PlayerEditObjInfo[playerid][UpdateRate] = DEFAULT_OBJECT_POS_UPDATE_RATE;
    DET_g_PlayerEditObjInfo[playerid][ObjectType] = OBJECT_TYPE_GLOBAL;

    new Float:Float[3];

    Float[0] = 0.0;
    Float[1] = 0.0;
    Float[2] = 0.0;
    
    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0] = Float[0];
    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1] = Float[1];
    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2] = Float[2];

    DET_g_PlayerEditObjInfo[playerid][StartPos][0] = Float[0];
    DET_g_PlayerEditObjInfo[playerid][StartPos][1] = Float[1];
    DET_g_PlayerEditObjInfo[playerid][StartPos][2] = Float[2];
    
    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0] = Float[0];
    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1] = Float[1];
    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2] = Float[2];

    DET_g_PlayerEditObjInfo[playerid][StartRot][0] = Float[0];
    DET_g_PlayerEditObjInfo[playerid][StartRot][1] = Float[1];
    DET_g_PlayerEditObjInfo[playerid][StartRot][2] = Float[2];
    return 1;
}

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    CallLocalFunction("DET_OnPlayerClickEditingMenu", "ii", playerid, _:clickedid);
    if(funcidx("d_editobj_opctd") != -1)
    {
        CallLocalFunction("d_editobj_opctd", "ii", playerid, _:clickedid);
    }
    return 1;
}

#if defined _ALS_OnPlayerClickTextDraw
    #undef OnPlayerClickTextDraw
#else
    #define _ALS_OnPlayerClickTextDraw
#endif

#define OnPlayerClickTextDraw( d_editobj_opctd(

forward d_editobj_opctd(playerid, Text:clickedid);

forward DET_OnPlayerClickEditingMenu(playerid, Text:textid);
public DET_OnPlayerClickEditingMenu(playerid, Text:textid)
{
    new EditingMenuString[256];
    //global objects
    if(DET_g_PlayerEditObjInfo[playerid][ObjectType] == OBJECT_TYPE_GLOBAL)
    {
        //////////////////////EditingMode SELECTION////////////////////////
        if(textid == DET_g_EditObjectTD[7])
        {
            GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~POSITION", 2000, 5);
            DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_POS;
        }
        if(textid == DET_g_EditObjectTD[8])
        {
            GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~ROTATION", 2000, 5);
            DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_ROT;
        }
        //////////////////////X POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[11])// oduzima x
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                
                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[12])// dodaje x
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        //////////////////////Y POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[13])// oduzima y
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[14])// dodaje y
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        //////////////////////Z POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[15])// oduzima z
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[16])// dodaje z
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if((textid != DET_g_EditObjectTD[18]) && (textid != DET_g_EditObjectTD[19]))
        {
            CallLocalFunction(DETUTILS_EDITGLOBALOBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_UPDATE,
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
        }
        ///////////////FINISH EDITING//////////////////
        if(textid == DET_g_EditObjectTD[18])
        {
            CallLocalFunction(DETUTILS_EDITGLOBALOBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_FINAL,
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

            GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~FINAL", 2000, 5);

            DET_g_EndPlayerEditMode(playerid);
        }
        if(textid == DET_g_EditObjectTD[19])
        {
            SetObjectPos(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][0], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][1],
                DET_g_PlayerEditObjInfo[playerid][StartPos][2]);

            SetObjectRot(DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][0], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][1],
                DET_g_PlayerEditObjInfo[playerid][StartRot][2]);

            CallLocalFunction(DETUTILS_EDITGLOBALOBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_CANCEL,
                DET_g_PlayerEditObjInfo[playerid][StartPos][0], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][1],
                DET_g_PlayerEditObjInfo[playerid][StartPos][2],
                DET_g_PlayerEditObjInfo[playerid][StartRot][0], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][1],
                DET_g_PlayerEditObjInfo[playerid][StartRot][2]);

            GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~CANCELED", 2000, 5);

            DET_g_EndPlayerEditMode(playerid);
        }
        ////////////////////////////UPDATE RATE/////////////////////////
        if(textid == DET_g_EditObjectTD[23]) //oduzima update rate
        {
            DET_g_PlayerEditObjInfo[playerid][UpdateRate] = 
            DET_g_PlayerEditObjInfo[playerid][UpdateRate]-DEFAULT_OBJECT_POS_UPDATE_RATE;

            format(EditingMenuString,sizeof EditingMenuString,
                "~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(-)",
                DET_g_PlayerEditObjInfo[playerid][UpdateRate]);
            GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        }
        if(textid == DET_g_EditObjectTD[24]) //dodaje update rate
        {
            DET_g_PlayerEditObjInfo[playerid][UpdateRate] = 
            DET_g_PlayerEditObjInfo[playerid][UpdateRate]+DEFAULT_OBJECT_POS_UPDATE_RATE;

            format(EditingMenuString,sizeof EditingMenuString,
                "~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(+)",
                DET_g_PlayerEditObjInfo[playerid][UpdateRate]);
            GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        }
    }
    //player objects
    if(DET_g_PlayerEditObjInfo[playerid][ObjectType] == OBJECT_TYPE_PLAYER)
    {
        //////////////////////EditingMode SELECTION////////////////////////
        if(textid == DET_g_EditObjectTD[7])
        {
            GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~POSITION", 2000, 5);
            DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_POS;
        }
        if(textid == DET_g_EditObjectTD[8])
        {
            GameTextForPlayer(playerid, "~y~EDITING MODE: ~w~ROTATION", 2000, 5);
            DET_g_PlayerEditObjInfo[playerid][EditingMode] = EDITING_MODE_ROT;
        }
        //////////////////////X POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[11])// oduzima x
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                
                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[12])// dodaje x
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~~r~%.2f~w~, %.2f, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        //////////////////////Y POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[13])// oduzima y
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[14])// dodaje y
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, ~r~%.2f~w~, %.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        //////////////////////Z POSITION/ROTATION////////////////////////
        if(textid == DET_g_EditObjectTD[15])// oduzima z
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]-DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if(textid == DET_g_EditObjectTD[16])// dodaje z
        {
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_POS)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) POS:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
            if(DET_g_PlayerEditObjInfo[playerid][EditingMode] == EDITING_MODE_ROT)
            {
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]=
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]+DET_g_PlayerEditObjInfo[playerid][UpdateRate];
                SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

                format(EditingMenuString,sizeof EditingMenuString,
                    "~y~OBJECT (~w~%i~y~) ROT:~w~~n~%.2f, %.2f, ~r~%.2f",
                    DET_g_PlayerEditObjInfo[playerid][EditedObject],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                    DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
                GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
            }
        }
        if((textid != DET_g_EditObjectTD[18]) && (textid != DET_g_EditObjectTD[19]))
        {
            CallLocalFunction(DETUTILS_EDITPLAYEROBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_UPDATE,
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);
        }
        ///////////////FINISH EDITING//////////////////
        if(textid == DET_g_EditObjectTD[18])
        {
            CallLocalFunction(DETUTILS_EDITPLAYEROBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_FINAL,
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectPos][2],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][0], 
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][1],
                DET_g_PlayerEditObjInfo[playerid][EditedObjectRot][2]);

            GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~FINAL", 2000, 5);

            DET_g_EndPlayerEditMode(playerid);
        }
        if(textid == DET_g_EditObjectTD[19])
        {
            SetPlayerObjectPos(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][0], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][1],
                DET_g_PlayerEditObjInfo[playerid][StartPos][2]);

            SetPlayerObjectRot(playerid, DET_g_PlayerEditObjInfo[playerid][EditedObject], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][0], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][1],
                DET_g_PlayerEditObjInfo[playerid][StartRot][2]);

            CallLocalFunction(DETUTILS_EDITPLAYEROBJ_CALLBACK, "iiiffffff", 
                playerid,DET_g_PlayerEditObjInfo[playerid][EditedObject],EDITING_RESPONSE_CANCEL,
                DET_g_PlayerEditObjInfo[playerid][StartPos][0], 
                DET_g_PlayerEditObjInfo[playerid][StartPos][1],
                DET_g_PlayerEditObjInfo[playerid][StartPos][2],
                DET_g_PlayerEditObjInfo[playerid][StartRot][0], 
                DET_g_PlayerEditObjInfo[playerid][StartRot][1],
                DET_g_PlayerEditObjInfo[playerid][StartRot][2]);

            GameTextForPlayer(playerid, "~y~EDITING RESPONSE: ~w~~n~CANCELED", 2000, 5);

            DET_g_EndPlayerEditMode(playerid);
        }
        ////////////////////////////UPDATE RATE/////////////////////////
        if(textid == DET_g_EditObjectTD[23]) //oduzima update rate
        {
            DET_g_PlayerEditObjInfo[playerid][UpdateRate] = DET_g_PlayerEditObjInfo[playerid][UpdateRate]-DEFAULT_OBJECT_POS_UPDATE_RATE;

            format(EditingMenuString,sizeof EditingMenuString,
                "~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(-)",
                DET_g_PlayerEditObjInfo[playerid][UpdateRate]);
            GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        }
        if(textid == DET_g_EditObjectTD[24]) //dodaje update rate
        {
            DET_g_PlayerEditObjInfo[playerid][UpdateRate] = DET_g_PlayerEditObjInfo[playerid][UpdateRate]+DEFAULT_OBJECT_POS_UPDATE_RATE;

            format(EditingMenuString,sizeof EditingMenuString,
                "~y~UPDATE RATE ~n~~w~CHANGED: ~r~%.2f ~w~(+)",
                DET_g_PlayerEditObjInfo[playerid][UpdateRate]);
            GameTextForPlayer(playerid, EditingMenuString, 2000, 5);
        }
    }
    return 1;
}