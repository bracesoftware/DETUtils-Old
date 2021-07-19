#define DEV_MODE
#define detutils_debug

#include "DETUTILS\d_interiors"
#include "DETUTILS\d_commands"
#include "DETUTILS\d_fmargs"

main()
{
    print("gamemode loaded.");
}

public OnPlayerSpawn(playerid)
{
    SendClientMessage(playerid, -1, "Welcome %s, your id is %i", ReturnPlayerName(playerid), playerid);
    SendClientMessageToAll(-1, "Player %s with id %i joined", ReturnPlayerName(playerid), playerid);
    return 1;
}

command sayhi(playerid,params[])
{
    SendClientMessage(playerid, -1, "Hi %s", ReturnPlayerName(playerid));
    return 1;
}

alias command hi(playerid,params[]) = sayhi;

debug command sayhi()
{
	print("Command /sayhi worked.");
	return 1;
}

debug command hi()
{
	print("Alias command /hi also worked.");
	return 1;
}

public OnGameModeInit()
{
    DisableDefaultInteriors();
    CreateCustomInterior("Bank", 811.1299,-1616.0647,13.5469, 644.6613,-1496.7572,14.8386, 0,0,0,0);
    return 1;
}

public OnPlayerConnect(playerid)
{
    SetSpawnInfo(playerid, 0, 0, 811.1299,-1616.0647,13.5469, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;
}

interior Bank(playerid)
{
    if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER))
    {
        SendClientMessage(playerid, -1, "You entered bank, %s.", ReturnPlayerName(playerid));
        return 1;
    }
    else if(IsInteriorActionPerformed(INTERIOR_ACTION_EXIT))
    {
        SendClientMessage(playerid, -1, "You exited bank, %s.", ReturnPlayerName(playerid));
        return 1;
    }
    return 1;
}

/*

Everything works fine as it should.

*/
