/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides 
 *   a dynamic race creation.
 *
 *
 */

#define MAX_RACES 200

enum DET_eRaceInfo
{
    Valid,
    Name[32],
    MaxPlayers,
    Players,
    FinishedPlayers,
    WinnerId,
    bool:Started,
    bool:Ended,
    Float:StartPos[3],
    Float:FinishPos[3],
    Place[MAX_PLAYERS],
    Float:FinishCPSize
}

new DET_g_RaceData[MAX_RACES][DET_eRaceInfo];

new 
    DET_g_PlayerRaceId[MAX_PLAYERS];

// Callbacks:

forward OnRaceCreate(racename[], maxplayers, Float:startX, Float:startY, Float:startZ,
    Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size);
forward OnRaceDestroy(racename[]);

forward OnPlayerJoinRace(playerid, racename[]);
forward OnPlayerLeaveRace(playerid, racename[]);
forward OnPlayerFinishRace(playerid, racename[], place);

forward OnRaceStart(racename[]);
forward OnRaceFinish(racename[]);

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

// Initializers:

stock CreateRace(const name[], maxplayers, Float:startX, Float:startY, Float:startZ,
    Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size = 5.0)
{
    for(new i; i < MAX_RACES; i++)
    {
        if(DET_g_RaceData[i][Valid] == 0)
        {
            DET_g_RaceData[i][Valid] = 1;
            strmid(DET_g_RaceData[i][Name], name, 0, 32);
            DET_g_RaceData[i][MaxPlayers] = maxplayers;

            DET_g_RaceData[i][StartPos][0] = startX;
            DET_g_RaceData[i][StartPos][1] = startY;
            DET_g_RaceData[i][StartPos][2] = startZ;

            DET_g_RaceData[i][FinishPos][0] = finishX;
            DET_g_RaceData[i][FinishPos][1] = finishY;
            DET_g_RaceData[i][FinishPos][2] = finishZ;

            DET_g_RaceData[i][FinishCPSize] = checkpoint_size;

            DET_g_RaceData[i][Started] = false;
            DET_g_RaceData[i][Ended] = false;

            CallLocalFunction("OnRaceCreate", "sifffffff", 
                name, // Name of a race.
                maxplayers, // Max amount of players in a race.
                startX, // Start pos: X
                startY, // Start pos: Y
                startZ, // Start pos: Z
                finishX, // Finish pos: X
                finishY, // Finish pos: Y
                finishZ, // Finish pos: Z
                checkpoint_size); // Finish CP size.

            return 1;
        }
    }
    return 0;
}

stock DestroyRace(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(DET_g_RaceData[i][Name], name))
        {
            DET_g_RaceData[i][Valid] = 0;
            strmid(DET_g_RaceData[i][Name], "__INVALID_RACE", 0, 32);
            DET_g_RaceData[i][MaxPlayers] = 0;

            DET_g_RaceData[i][Players] = 0;
            DET_g_RaceData[i][FinishedPlayers] = 0;

            DET_g_RaceData[i][StartPos][0] = 0.0000;
            DET_g_RaceData[i][StartPos][1] = 0.0000;
            DET_g_RaceData[i][StartPos][2] = 0.0000;

            DET_g_RaceData[i][FinishPos][0] = 0.0000;
            DET_g_RaceData[i][FinishPos][1] = 0.0000;
            DET_g_RaceData[i][FinishPos][2] = 0.0000;

            DET_g_RaceData[i][FinishCPSize] = 0.0000;

            DET_g_RaceData[i][Started] = false;
            DET_g_RaceData[i][Ended] = false;

            for(new playerid; playerid < MAX_PLAYERS; playerid++)
            {
                DET_g_RaceData[i][Place][playerid] = 0;
                if(DET_g_PlayerRaceId[playerid] == i)
                {
                    SpawnPlayer(playerid);
                    DisablePlayerRaceCheckpoint(playerid);
                    DET_g_PlayerRaceId[playerid] = -1;
                    TogglePlayerControllable(playerid, true);
                }
            }

            DET_g_RaceData[i][WinnerId] = -1;

            // After clearing all the data,
            // call the callback.

            CallLocalFunction("OnRaceDestroy", "s", name);

            return 1;
        }
    }
    return 0;
}

// Modifiers:

stock AddPlayerToRace(playerid, const name[])
{
    if(DET_g_PlayerRaceId[playerid] != -1) return 0;
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]) && DET_g_RaceData[i][Valid] == 1)
        {
            if(DET_g_RaceData[i][Started] == true) return 0;

            if(DET_g_RaceData[i][MaxPlayers] > DET_g_RaceData[i][Players])
            {
                DET_g_PlayerRaceId[playerid] = i;

                TogglePlayerControllable(playerid, false);
                SetPlayerPos(playerid, DET_g_RaceData[i][StartPos][0], 
                    DET_g_RaceData[i][StartPos][1],
                    DET_g_RaceData[i][StartPos][2]);

                DET_g_RaceData[i][Players]++;

                CallLocalFunction("OnPlayerJoinRace", "is", playerid, name);
                return 1;
            }
            else if(DET_g_RaceData[i][MaxPlayers] == DET_g_RaceData[i][Players])
            {
                return 0;
            }
        }
    }
    return 0;
}

stock RemovePlayerFromRace(playerid)
{
    if(DET_g_PlayerRaceId[playerid] == -1) return 0;
    
    new raceid = DET_g_PlayerRaceId[playerid];

    DET_g_RaceData[raceid][Players]--;
    DET_g_RaceData[raceid][FinishedPlayers]++;
    DET_g_PlayerRaceId[playerid] = -1;

    TogglePlayerControllable(playerid, true);
    SpawnPlayer(playerid);
    DisablePlayerRaceCheckpoint(playerid);

    CallLocalFunction("OnPlayerLeaveRace", "is", playerid, DET_g_RaceData[raceid][Name]);

    if(DET_g_RaceData[raceid][FinishedPlayers] == DET_g_RaceData[raceid][MaxPlayers] && 
    DET_g_RaceData[raceid][Players] == 0) // If they're the last player...
    {
        DET_g_RaceData[raceid][Ended] = true; // Race ends.
        CallLocalFunction("OnRaceFinish", "s", 
            DET_g_RaceData[raceid][Name]);
    }
    return 1;
}

stock StartRace(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]) && DET_g_RaceData[i][Valid] == 1)
        {
            if(DET_g_RaceData[i][Started] == true) return 0;

            DET_g_RaceData[i][Started] = true;

            for(new playerid; playerid < MAX_PLAYERS; playerid++)
            {
                if(DET_g_PlayerRaceId[playerid] == i)
                {
                    SetPlayerRaceCheckpoint(playerid, 
                        1,
                        DET_g_RaceData[i][FinishPos][0],
                        DET_g_RaceData[i][FinishPos][1],
                        DET_g_RaceData[i][FinishPos][2],
                        DET_g_RaceData[i][FinishPos][0],
                        DET_g_RaceData[i][FinishPos][1],
                        DET_g_RaceData[i][FinishPos][2],
                        DET_g_RaceData[i][FinishCPSize]);

                    TogglePlayerControllable(playerid, true);
                }
            }

            CallLocalFunction("OnRaceStart", "s", name);
            return 1;
        }
    }
    return 0;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
    new raceid = DET_g_PlayerRaceId[playerid];
    if(DET_g_PlayerRaceId[playerid] != -1) // In case of anything.
    {
        DET_g_RaceData[raceid][Players]--;
        DET_g_RaceData[raceid][FinishedPlayers]++;
        DET_g_PlayerRaceId[playerid] = -1;
        DET_g_RaceData[raceid][Place][playerid] = DET_g_RaceData[raceid][FinishedPlayers];
        if(DET_g_RaceData[raceid][Place][playerid] == 1)
        {
            DET_g_RaceData[raceid][WinnerId] = playerid;
        }
        SpawnPlayer(playerid);
        DisablePlayerRaceCheckpoint(playerid);
        CallLocalFunction("OnPlayerFinishRace", "isi", playerid, DET_g_RaceData[raceid][Name],
            DET_g_RaceData[raceid][Place][playerid]);
        if(DET_g_RaceData[raceid][FinishedPlayers] == DET_g_RaceData[raceid][MaxPlayers] && 
            DET_g_RaceData[raceid][Players] == 0) // If they're the last player...
        {
            DET_g_RaceData[raceid][Ended] = true; // Race ends.
            CallLocalFunction("OnRaceFinish", "s", 
                DET_g_RaceData[raceid][Name]);
        }
        return 1;
    }
    if(funcidx("d_races_operc") != -1)
    {
        CallLocalFunction("d_races_operc", "i", playerid);
    }
    return 1;
}

#if defined _ALS_OnPlayerEnterRaceCP
    #undef OnPlayerEnterRaceCheckpoint
#else
    #define _ALS_OnPlayerEnterRaceCP
#endif

#define OnPlayerEnterRaceCheckpoint( d_races_operc(

forward d_races_operc(playerid);

// Value returners:

stock GetRaceRemainingPlayers(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]))
        {
            return DET_g_RaceData[i][Players];
        }
    }
    return 0;
}

stock GetRaceWinnerID(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]))
        {
            return DET_g_RaceData[i][WinnerId];
        }
    }
    return -1;
}

stock GetRaceMaxPlayers(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]))
        {
            return DET_g_RaceData[i][MaxPlayers];
        }
    }
    return -1;
}

stock GetRaceFinishedPlayers(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]))
        {
            return DET_g_RaceData[i][FinishedPlayers];
        }
    }
    return -1;
}

stock GetPlayerRace(playerid)
{
    return DET_g_PlayerRaceId[playerid];
}

stock bool:IsValidRace(id)
{
    return bool:(DET_g_RaceData[id][Valid]);
}

stock bool:IsValidRaceName(const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(!strcmp(name, DET_g_RaceData[i][Name]))
        {
            return true;
        }
    }
    return false;
}

stock GetRaceNameByID(id, dest[], size = sizeof dest)
{
    if(IsValidRace(id) == false) return 0;
    strmid(dest, DET_g_RaceData[id][Name], 0, size);
    return 1;
}

// Booleans:

stock bool:IsPlayerInRace(playerid, const name[])
{
    for(new i; i < MAX_RACES; i++)
    {
        if(DET_g_PlayerRaceId[playerid] == i)
        {
            return true;
        }
    }
    return false;
}

stock bool:IsPlayerInAnyRace(playerid)
{
    return DET_g_PlayerRaceId[playerid] != -1;
}