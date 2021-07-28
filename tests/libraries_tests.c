#define DEV_MODE
#define detutils_debug
#define detutils_sscanf

#include "DETUTILS\d_interiors"
#include "DETUTILS\d_commands"
#include "DETUTILS\d_fmargs"
#include "DETUTILS\d_visual"

main()
{
    print("gamemode loaded.");
}

public OnPlayerSpawn(playerid)
{
    SendClientMessage(playerid, -1, "Welcome %s, your id is %i", _ReturnPlayerName(playerid), playerid);
    SendClientMessageToAll(-1, "Player %s with id %i joined", _ReturnPlayerName(playerid), playerid);
    return 1;
}

enum Enums
{
    Admin
}

new Player[MAX_PLAYERS][Enums];

command sayhi (playerid,params[])
{
    new parameters[128], idx;

    new action; 

    parameters = strtok(params, idx);

    if(strlen(parameters) == 0) return SendClientMessage(playerid, 0xFFFFFFFF, "Usage: /sayhi <action>");

    action = strval(parameters);

    if(action == 1)
    {
        SendClientMessage(playerid, -1, "Hi, %s.", _ReturnPlayerName(playerid));
    }
    else if(action != 1)
    {
        SendClientMessage(playerid, -1, "No HI for you!");
    }
    return 1;
}

alias command hi (playerid,params[]) = sayhi;

admin command ac (playerid,params[])
{
    SendClientMessage(playerid, -1, "You're admin.");
    return 1;
}

command untiltest(playerid, params[])
{
    new i;
    until(i = 50)
    {
        i++;
        printf("%i", i);
    }
    SendClientMessage(playerid, -1, "i is now 50.");
    return 1;
}

debug command sayhi ()
{
    if(GetCommandDebugState() == COMMAND_DEBUG_STATE_RECEIVED)
    {
        printf("Command %s received.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_READY)
    {
        printf("Command %s ready.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_PERFORMED)
    {
        printf("Command %s performed.", GetDebuggedCommandName());
        return 1;
    }
    return 0;
}

debug command hi ()
{
    if(GetCommandDebugState() == COMMAND_DEBUG_STATE_RECEIVED)
    {
        printf("Command %s received.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_READY)
    {
        printf("Command %s ready.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_PERFORMED)
    {
        printf("Command %s performed.", GetDebuggedCommandName());
        return 1;
    }
    return 0;
}

prefixed command test (playerid, params[], "&")
{
    SendClientMessage(playerid, -1, "Amazing %s, this custom-prefixed command worked.", _ReturnPlayerName(playerid));
    return 1;
}

prefixed command TEST(playerid, params[], "&")
{
    SendClientMessage(playerid, -1, "WORKS!");
    return 1;
}

public OnPrefixedCommandReceived(playerid, cmdtext[])
{
    SendClientMessage(playerid, -1, "%s, your command was received. (%s)", _ReturnPlayerName(playerid), cmdtext);
    return 1;
}

public OnPrefixedCommandPerformed(playerid, cmdtext[], success)
{
    if(!success)
    {
        SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
    }
    return 1;
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{
    SendClientMessage(playerid, -1, "%s, your command was received. (%s)", _ReturnPlayerName(playerid), cmdtext);
    return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
    if(!success)
    {
        SendClientMessage(playerid, -1, "Command %s doesn't exist.", cmdtext);
    }
    return 1;
}

prefixed command dear (playerid, params[], "@")
{
    SendClientMessage(playerid, -1, "%s said hi.", _ReturnPlayerName(playerid));
    return 1;
}

prefixed command hi (playerid, params[], "#")
{
    SendClientMessage(playerid, -1, "Hi man");
    return 1;
}

create role AdminRole (playerid, Player[playerid][Admin] == 1);

command makeadmin (playerid, params[])
{
    SendClientMessage(playerid, -1, "You're now an administrator.");
    Player[playerid][Admin] = 1;
    return 1;
}

role command clearchat (playerid, params[], AdminRole)
{
    for(new i; i < 20; i++)
        SendClientMessage(playerid, -1, "");

    SendClientMessage(playerid, -1, "You cleared the chat.");
    return 1;
}

public OnGameModeInit()
{
    DisableDefaultInteriors();
    CreateCustomInteriorEx("Bank", 811.1299,-1616.0647,13.5469, 644.6613,-1496.7572,14.8386, 0,0,0,0);
    CreateDroppedGun(30,999,811.1299,-1616.0647,13.5469);
    return 1;
}

public OnPlayerConnect(playerid)
{
    if(!IsPlayerUsingAndroidClient(playerid)) return SendClientMessage(playerid, -1, "You're using a computer to play SA:MP, great!");
    SetSpawnInfo(playerid, 0, 0, 811.1299,-1616.0647,13.5469, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;
}

public OnPlayerClientCheckReceived(playerid)
{
    printf("Successfully performed client check on player id %i.", playerid);
    return 1;
}

interior Bank (playerid)
{
    if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER))
    {
        SendClientMessage(playerid, -1, "You entered bank, %s.", _ReturnPlayerName(playerid));
        return 1;
    }
    else if(IsInteriorActionPerformed(INTERIOR_ACTION_EXIT))
    {
        SendClientMessage(playerid, -1, "You exited bank, %s.", _ReturnPlayerName(playerid));
        return 1;
    }
    return 1;
}

public OnCustomInteriorCreated(customintid)
{
    printf("Interior created! ID: %i", customintid);
    return 1;
}
