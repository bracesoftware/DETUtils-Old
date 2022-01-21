/*
 * 
 * SA:MP DEntisT's Utilities
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library providing 
 *   map editing in-game.
 *
 *
 */

#tryinclude "d_extra\d_libtags.inc"

#if !defined d_extra_included
    #error [samp-detutils]: (error) - You are missing "d_extra\d_libtags.inc" in your "include\DETUTILS" folder.
#endif

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

#define DETUTILS_PATH_OBJECTS "detutils_objects/%i.ini"

#if !defined DETUTILS_DIALOG_MAPEDITOR

#define DETUTILS_DIALOG_MAPEDITOR 1

#endif

#if !defined DETUTILS_DIALOG_MAPEDIT_CREATE

#define DETUTILS_DIALOG_MAPEDIT_CREATE 2

#endif

#if !defined DETUTILS_DIALOG_MAPEDIT_DSTRY

#define DETUTILS_DIALOG_MAPEDIT_DSTRY 3

#endif

#if !defined DETUTILS_DIALOG_MAPEDIT_EDIT

#define DETUTILS_DIALOG_MAPEDIT_EDIT 4

#endif

enum enum_ObjectData
{
    Float:Pos[3],
    Float:RotPos[3],
    ObjectID,
    Text3D:Label,
    GtaObjID
}

enum enum_MapEditorPlayerData
{
    ObjectEditing
}

new g_ObjectData[MAX_OBJECTS][enum_ObjectData];
new g_MapEditorPlayerData[MAX_PLAYERS][enum_MapEditorPlayerData];

stock ShowMapEditorMenuToPlayer(playerid)
{
    ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDITOR, DIALOG_STYLE_LIST, 
        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_CHOICES, 
        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);
    return 1;
}

static stock d_me_GetNearestObject(playerid)
{
    for(new i; i < MAX_OBJECTS; i++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, g_ObjectData[i][Pos][0],g_ObjectData[i][Pos][1],g_ObjectData[i][Pos][2]))
        {
            return i;
        }
    }
    return -1;
}

public OnPlayerConnect(playerid)
{
    g_MapEditorPlayerData[playerid][ObjectEditing] = -1;
    if(funcidx("d_me_playerconnect") != -1)
    {
        CallLocalFunction("d_me_playerconnect", "i", playerid);
    }
    return 1;
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect d_me_playerconnect

forward d_me_playerconnect(playerid);


public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == DETUTILS_DIALOG_MAPEDITOR)
    {
        if(response)
        {
            switch(listitem)
            {
                case 0:
                {
                    ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_CREATE, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_OBJID, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);       
                }
                case 1:
                {
                    ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_DSTRY, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_DSTRY, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);
                }
                case 2:
                {
                    ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_EDIT, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_EDIT, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);
                }
            }
        }
    }
    if(dialogid == DETUTILS_DIALOG_MAPEDIT_CREATE)
    {
        if(response)
        {
            new parameters[128], idx;

            new objid; 

            parameters = strtok(inputtext, idx);

            if(strlen(parameters) == 0) return ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_CREATE, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_OBJID, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);  

            objid = strval(parameters);

            for( new i = 1; i < MAX_OBJECTS; i++ )
            {
                new file[ 40 ];
                format(file, sizeof( file ), DETUTILS_PATH_OBJECTS, i);
                if( !fexist( file ) )
                {
                    new Float:x, Float:y, Float:z, Float:angle, label_string[256];
                    GetPlayerPos( playerid, x, y, z); 
                    GetPlayerFacingAngle( playerid, angle);
                    
                    g_ObjectData[i][Pos][ 0 ] = x;
                    g_ObjectData[i][Pos][ 1 ] = y;
                    g_ObjectData[i][Pos][ 2 ] = z;
                    g_ObjectData[i][RotPos][ 0 ] = 0;
                    g_ObjectData[i][RotPos][ 1 ] = 0;
                    g_ObjectData[i][RotPos][ 2 ] = 0;
                    g_ObjectData[i][GtaObjID] = objid;
                    g_ObjectData[i][ObjectID] = CreateObject(g_ObjectData[i][GtaObjID], x+2, y, z+0.6, 0.0, 0.0, angle);

                    format(label_string, sizeof label_string,
                        "[samp-detutils]: (map editor)\n\nScript object ID: %i\nPosition: %f, %f, %f\nRotation: %f, %f, %f", 
                        i, g_ObjectData[i][Pos][ 0 ], g_ObjectData[i][Pos][ 1 ], g_ObjectData[i][Pos][ 2 ],
                        g_ObjectData[i][RotPos][ 0 ], g_ObjectData[i][RotPos][ 1 ], g_ObjectData[i][RotPos][ 2 ]);

                    g_ObjectData[i][Label] = Create3DTextLabel(label_string, -1, x+2,y+0.6,z, 30.0, GetPlayerVirtualWorld(playerid));

                    g_MapEditorPlayerData[playerid][ObjectEditing] = i;
                    
                    EditObject(playerid, g_ObjectData[i][ObjectID]);
                    d_me_SaveObject(i);
                    break;
                }
            }
        }
    }
    if(dialogid == DETUTILS_DIALOG_MAPEDIT_DSTRY)
    {
        if(response)
        {
            new parameters[128], idx;

            new objid; 

            parameters = strtok(inputtext, idx);

            if(strlen(parameters) == 0) return ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_DSTRY, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_DSTRY, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);  

            objid = strval(parameters);

            if(IsValidObject(g_ObjectData[objid][ObjectID]))
            {
                DestroyObject(g_ObjectData[objid][ObjectID]);
            }

            Delete3DTextLabel(g_ObjectData[objid][Label]);

            g_ObjectData[ objid ][ Pos ][ 0 ] = 0;
            g_ObjectData[ objid ][ Pos ][ 1 ] = 0;
            g_ObjectData[ objid ][ Pos ][ 2 ] = 0;
            g_ObjectData[ objid ][ RotPos ][ 0 ] = 0;
            g_ObjectData[ objid ][ RotPos ][ 1 ] = 0;
            g_ObjectData[ objid ][ RotPos ][ 2 ] = 0;

            new fstring[ 64 ];
            format( fstring, sizeof( fstring ), DETUTILS_PATH_OBJECTS, objid );
            if( fexist( fstring ) ) { fremove( fstring ); }
        }
    }
    if(dialogid == DETUTILS_DIALOG_MAPEDIT_EDIT)
    {
        if(response)
        {
            new parameters[128], idx;

            new objid; 

            parameters = strtok(inputtext, idx);

            if(strlen(parameters) == 0) return ShowPlayerDialog(playerid, DETUTILS_DIALOG_MAPEDIT_EDIT, DIALOG_STYLE_INPUT, 
                        DETUTILS_TEXT_MAPEDITOR_CAPTION, DETUTILS_TEXT_MAPEDITOR_EDIT, 
                        DETUTILS_TEXT_DIALOG_CONFIRM, DETUTILS_TEXT_EXITDIALOG);  

            objid = strval(parameters);

            EditObject(playerid, g_ObjectData[objid][ObjectID]);
        }
    }

    if(funcidx("d_me_dialogresponse") != -1)
    {
        CallLocalFunction("d_me_dialogresponse", "iiiis", playerid, dialogid, response, listitem, inputtext);
    }
    return 1;
}

#if defined _ALS_OnDialogResponse
    #undef OnDialogResponse
#else
    #define _ALS_OnDialogResponse
#endif

#define OnDialogResponse d_me_dialogresponse

forward d_me_dialogresponse(playerid, dialogid, response, listitem, inputtext[]);

public OnPlayerEditObject(playerid, playerobject, objectid, response, 
    Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
{
    if(g_MapEditorPlayerData[playerid][ObjectEditing] != -1)
    {
        new objid = g_MapEditorPlayerData[playerid][ObjectEditing];

        g_ObjectData[objid][Pos][ 0 ] = fX;
        g_ObjectData[objid][Pos][ 1 ] = fY;
        g_ObjectData[objid][Pos][ 2 ] = fZ;
        g_ObjectData[objid][RotPos][ 0 ] = fRotX;
        g_ObjectData[objid][RotPos][ 1 ] = fRotY;
        g_ObjectData[objid][RotPos][ 2 ] = fRotZ;

        Delete3DTextLabel(g_ObjectData[objid][Label]);

        new label_string[256];

        format(label_string, sizeof label_string,
            "[samp-detutils]: (map editor)\n\nScript object ID: %i\nPosition: %f, %f, %f\nRotation: %f, %f, %f", 
            objid, g_ObjectData[objid][Pos][ 0 ], g_ObjectData[objid][Pos][ 1 ], g_ObjectData[objid][Pos][ 2 ],
            g_ObjectData[objid][RotPos][ 0 ], g_ObjectData[objid][RotPos][ 1 ], g_ObjectData[objid][RotPos][ 2 ]);

        g_ObjectData[objid][Label] = Create3DTextLabel(label_string, -1, 
            g_ObjectData[objid][Pos][ 0 ],g_ObjectData[objid][Pos][ 1 ],
            g_ObjectData[objid][Pos][ 2 ], 30.0, GetPlayerVirtualWorld(playerid));

        g_MapEditorPlayerData[playerid][ObjectEditing] = -1;
        d_me_SaveObject(objid);
    }

    if(funcidx("d_me_editobject") != -1)
    {
        CallLocalFunction("d_me_editobject", "iiiiffffff", 
            playerid, playerobject, objectid, response, Float:fX, Float:fY, 
            Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ );
    }
    return 1;
}

#if defined _ALS_OnPlayerEditObject
    #undef OnPlayerEditObject
#else
    #define _ALS_OnPlayerEditObject
#endif

#define OnPlayerEditObject d_me_editobject

forward d_me_editobject(playerid, playerobject, objectid, response, 
    Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);

public OnGameModeInit()
{
    for(new i; i < MAX_OBJECTS; i++) d_me_LoadObjects(i);

    if(funcidx("d_me_gminit") != -1)
    {
        CallLocalFunction("d_me_gminit", "");
    }
    return 1;
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit d_me_gminit

forward d_me_gminit();

static d_me_SplitString(const strsrc[], strdest[][], delimiter)
{
    new i, li;
    new aNum;
    new len;
    while(i <= strlen(strsrc))
    {
        if(strsrc[i]==delimiter || i==strlen(strsrc))
        {
            len = strmid(strdest[aNum], strsrc, li, i, 128);
            strdest[aNum][len] = 0;
            li = i+1;
            aNum++;
        }
        i++;
    }
    return 1;
}

static d_me_LoadObjects(id)
{
    new d_ArrayCoordinates[19][64],file_name[100];
    format(file_name, sizeof file_name,
        DETUTILS_PATH_OBJECTS, id);
    new strFromFile2[128];
    if(!fexist(file_name)) return 0;
    new File: file = fopen(file_name, io_read);
    if (file)
    {
        fread(file, strFromFile2);
        d_me_SplitString(strFromFile2, d_ArrayCoordinates, ',');
        g_ObjectData[id][Pos][0] = strval(d_ArrayCoordinates[0]);
        g_ObjectData[id][Pos][1] = strval(d_ArrayCoordinates[1]);
        g_ObjectData[id][Pos][2] = strval(d_ArrayCoordinates[2]);
        g_ObjectData[id][RotPos][0] = strval(d_ArrayCoordinates[3]);
        g_ObjectData[id][RotPos][0] = strval(d_ArrayCoordinates[4]);
        g_ObjectData[id][RotPos][0] = strval(d_ArrayCoordinates[5]);
        g_ObjectData[id][GtaObjID] = strval(d_ArrayCoordinates[6]);
        
        fclose(file);
    }
    g_ObjectData[id][ObjectID] = CreateObject(g_ObjectData[id][GtaObjID], g_ObjectData[id][Pos][0], g_ObjectData[id][Pos][1], g_ObjectData[id][Pos][2],g_ObjectData[id][RotPos][0], g_ObjectData[id][RotPos][1], g_ObjectData[id][RotPos][2]);
    return 1;
}

stock ShowObjectInfoLabels(worldid)
{
    new label_string[256];
    for(new id; id < MAX_OBJECTS; id++)
    {
        format(label_string, sizeof label_string,
        "[samp-detutils]: (map editor)\n\nScript object ID: %i\nPosition: %f, %f, %f\nRotation: %f, %f, %f", 
        id, g_ObjectData[id][Pos][ 0 ], g_ObjectData[id][Pos][ 1 ], g_ObjectData[id][Pos][ 2 ],
        g_ObjectData[id][RotPos][ 0 ], g_ObjectData[id][RotPos][ 1 ], g_ObjectData[id][RotPos][ 2 ]);

        g_ObjectData[id][Label] = Create3DTextLabel(label_string, -1, g_ObjectData[id][Pos][0], g_ObjectData[id][Pos][1], g_ObjectData[id][Pos][2], 30.0, worldid);
    }
    return 1;
}

stock HideObjectInfoLabels()
{
    for(new id; id < MAX_OBJECTS; id++)
    {
        Delete3DTextLabel(g_ObjectData[id][Label]);
    }
    return 1;
}

forward d_me_SaveObject(loopid);
public d_me_SaveObject(loopid)
{
    new string[228], file_name[100];
    format(file_name, sizeof file_name,
        DETUTILS_PATH_OBJECTS, loopid);
    new id = loopid;
    format(string, sizeof(string), 
        "%f,%f,%f,%f,%f,%f,%i",
        g_ObjectData[id][Pos][0], g_ObjectData[id][Pos][1], g_ObjectData[id][Pos][2],
        g_ObjectData[id][RotPos][0], g_ObjectData[id][RotPos][1], g_ObjectData[id][RotPos][2],
        g_ObjectData[id][GtaObjID]);
    new File: file2 = fopen(file_name, io_write);
    fwrite(file2, string);
    fclose(file2);
    return 1;
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

static AnnounceLibraryLoaded_mapeditor()
{
    LoadDETUtilsScript(DETUTILS_SCRIPT_MAPEDITOR);
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_mapeditor.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_mapeditor.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_mapeditor();
    a_mapeditor_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_mapeditor_main

#else

#define detutils_mapeditor_TRUE 1

public OnFilterScriptInit()
{
    AnnounceLibraryLoaded_mapeditor();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_mapeditor.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_mapeditor.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_mapeditor_OnfsInit") != -1)
    {
        CallLocalFunction("a_mapeditor_OnfsInit", "i", playerid);
    }
    return detutils_mapeditor_TRUE;
}

#if defined _ALS_OnFilterScriptInit
    #undef OnFilterScriptInit
#else
    #define _ALS_OnFilterScriptInit
#endif

#define OnFilterScriptInit a_mapeditor_OnfsInit

forward a_mapeditor_OnfsInit();

#endif