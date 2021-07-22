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
    
#define DEV_MODE
#if defined DEV_MODE

#include <a_samp>

#endif

#if defined d_data_included
    #endinput
#endif

#define d_data_included

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

#define utils_MaxStringLength 255
#define utils_RegistrationDialog 1
#define utils_LoginDialog 2
#define utils_SuccessFirst 3
#define utils_SuccessSec 4

#define utils_DatabasePath "../DETUTILS/Database/%s.utils"

#define utils_WhiteColor "{FFFFFF}"
#define utils_RedColor "{F81414}"
#define utils_GreenColor "{00FF22}"
#define utils_LightBlueColor "{00CED1}"

enum utils_PlayerDataEnumeration
{
    pPass,
    pCash,
    pAdmin,
    pKills,
    pDeaths
}
new utils_g_PlayerData[MAX_PLAYERS][utils_PlayerDataEnumeration];

stock utils_Int(utils_FileName[],utils_DataKey[]) 
{
   return strval(utils_Get(utils_FileName,utils_DataKey));
}

stock utils_Get(utils_FileName[],utils_DataKey[]) 
{
    new utils_TmpresFileData[utils_MaxStringLength];
    
    new utils_DataKey_length = strlen(utils_DataKey);
    if (utils_DataKey_length==0 || utils_DataKey_length+2>utils_MaxStringLength) return utils_TmpresFileData;
    
    new File:utils_FileOhnd;
    utils_FileOhnd=fopen(utils_FileName,io_read);
    if (!utils_FileOhnd) return utils_TmpresFileData;
    
    while (fread(utils_FileOhnd,utils_TmpresFileData)) {
        if (
            utils_TmpresFileData[utils_DataKey_length]=='='
            && !strcmp(utils_TmpresFileData, utils_DataKey, true, utils_DataKey_length) 
        ) 
        {
            utils_StripNewLine(utils_TmpresFileData);
            strmid(utils_TmpresFileData, utils_TmpresFileData, utils_DataKey_length + 1, 
                strlen(utils_TmpresFileData), utils_MaxStringLength);
            fclose(utils_FileOhnd);
            return utils_TmpresFileData;
        }
    }
    fclose(utils_FileOhnd);
    return utils_TmpresFileData;
}

forward utils_LoadData(playerid);
public utils_LoadData(playerid)
{
    new utils:File = utils_Open(Userutils_DatabasePath(playerid));
    utils_Int("Password",utils_g_PlayerData[playerid][pPass]);
    utils_Int("Cash",utils_g_PlayerData[playerid][pCash]);
    utils_Int("Admin",utils_g_PlayerData[playerid][pAdmin]);
    utils_Int("Kills",utils_g_PlayerData[playerid][pKills]);
    utils_Int("Deaths",utils_g_PlayerData[playerid][pDeaths]);
    utils_Close(File);
    return 1;
}

stock Userutils_DatabasePath(playerid)
{
    new string[128],playername[MAX_PLAYER_NAME];
    GetPlayerName(playerid,playername,sizeof(playername));
    format(string,sizeof(string),utils_DatabasePath,playername);
    return string;
}

stock utils_StripNewLine(string[]) 
{
    new len = strlen(string);
    if (string[0]==0) return ;
    if ((string[len - 1] == '\n') || 
        (string[len - 1] == '\r')) {
        string[len - 1] = 0;
        if (string[0]==0) return ;
        if ((string[len - 2] == '\n') || 
            (string[len - 2] == '\r')) string[len - 2] = 0;
    }
}

stock udb_hash(buf[]) {
    new length=strlen(buf);
    new s1 = 1;
    new s2 = 0;
    new n;
    for (n=0; n<length; n++)
    {
       s1 = (s1 + buf[n]) % 65521;
       s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}

public OnPlayerConnect(playerid)
{
    if(fexist(Userutils_DatabasePath(playerid)))
    {
        CallLocalFunction("utils_LoadData", "i", playerid);
        ShowPlayerDialog(playerid, utils_LoginDialog, DIALOG_STYLE_INPUT,""utils_WhiteColor"Login",""utils_WhiteColor"Ukucajte sifru dabi se ulogovali.","Login","Izadji");
    }
    else
    {
        ShowPlayerDialog(playerid, utils_RegistrationDialog, DIALOG_STYLE_INPUT,""utils_WhiteColor"Registracija...",""utils_WhiteColor"Ukucajte sifru kako bi se registrovali","Register","Izadji");
    }
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    switch( dialogid )
    {
        case utils_RegistrationDialog:
        {
            if (!response) return Kick(playerid);
            if(response)
            {
                if(!strlen(inputtext)) return ShowPlayerDialog(playerid, 
                    utils_RegistrationDialog, DIALOG_STYLE_INPUT, 
                    ""utils_WhiteColor"Registracija...",""utils_RedColor"Ukucali ste pogresnu lozinku.\n \
                    "utils_WhiteColor"Ukucajte sifru kako bi registrovali nov akaunt","Register","Izadji");
                new utils:File = utils_Open(Userutils_DatabasePath(playerid));
                utils_SetTag(File,"data");
                utils_WriteInt(File,"Password",udb_hash(inputtext));
                utils_WriteInt(File,"Cash",0);
                utils_WriteInt(File,"Admin",0);
                utils_WriteInt(File,"Kills",0);
                utils_WriteInt(File,"Deaths",0);
                utils_Close(File);

                SetSpawnInfo(playerid, 0, 0, 1958.33, 1343.12, 15.36, 269.15, 0, 0, 0, 0, 0, 0);
                SpawnPlayer(playerid);
                ShowPlayerDialog(playerid, utils_SuccessFirst, DIALOG_STYLE_MSGBOX,
                    ""utils_WhiteColor"Dobrodosli!",""utils_GreenColor"Uspesno ste se registrovali!","Ok","");
            }
        }

        case utils_LoginDialog:
        {
            if ( !response ) return Kick ( playerid );
            if( response )
            {
                if(udb_hash(inputtext) == utils_g_PlayerData[playerid][pPass])
                {
                    utils_ParseFile(Userutils_DatabasePath(playerid), "LoadUser_%s", .bExtra = true, .extra = playerid);
                    GivePlayerMoney(playerid, utils_g_PlayerData[playerid][pCash]);
                    ShowPlayerDialog(playerid, utils_SuccessSec, DIALOG_STYLE_MSGBOX,
                        ""utils_WhiteColor"Dobrodosli!",""utils_GreenColor"Uspesnos te se ulogovali!","Ok","");
                }
                else
                {
                    ShowPlayerDialog(playerid, utils_LoginDialog, DIALOG_STYLE_INPUT,
                        ""utils_WhiteColor"Login",""utils_RedColor"Ukucali ste pogresnu sifru.\n"utils_WhiteColor" \
                        Ukucajte sifru kako bi se ulogovali.","Login","Izadji");
                }
                return 1;
            }
        }
    }
    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    new utils:File = utils_Open(Userutils_DatabasePath(playerid));
    utils_SetTag(File,"data");
    utils_WriteInt(File,"Cash",GetPlayerMoney(playerid));
    utils_WriteInt(File,"Admin",utils_g_PlayerData[playerid][pAdmin]);
    utils_WriteInt(File,"Kills",utils_g_PlayerData[playerid][pKills]);
    utils_WriteInt(File,"Deaths",utils_g_PlayerData[playerid][pDeaths]);
    utils_Close(File);
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    utils_g_PlayerData[killerid][pKills]++;
    utils_g_PlayerData[playerid][pDeaths]++;
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

static AnnounceLibraryLoaded_data()
{
    print("|======================================|");
    print("                d_data.inc              ");
    print("          Successfully loaded!          ");
    print("                                        ");
    print("               By: DEntisT              ");
    print("|======================================|");
}

#if !defined FILTERSCRIPT

main()
{
    #if defined detutils_debug
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    AnnounceLibraryLoaded_data();
    a_data_main();
}

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif

#define main a_data_main

#else

#define detutils_data_TRUE 1

public OnFilterScriptutilst()
{
    AnnounceLibraryLoaded_data();
    #if defined detutils_debug
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_data.log", "[samp-detutils]: (debug) - Loaded.");
    #endif
    if(funcidx("a_data_Onfsutilst") != -1)
    {
        CallLocalFunction("a_data_Onfsutilst", "i", playerid);
    }
    return detutils_data_TRUE;
}

#if defined _ALS_OnFilterScriptutilst
    #undef OnFilterScriptutilst
#else
    #define _ALS_OnFilterScriptutilst
#endif

#define OnFilterScriptutilst a_data_Onfsutilst

forward a_data_Onfsutilst();

#endif