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

Debug output:


[22:15:23] [samp-detutils]: (debug) - ongminit :: Commands init...
[22:15:25] Interior 'Bank' successfully created, entrance is set to: 811.129882, -1616.064697, 13.546899.
[22:15:25] [samp-detutils]: (debug) - Interior created.
[22:15:25] [samp-detutils]: (debug) - Saved interior name.
[22:15:25] Interior 'Bank' has an id 1.
[22:15:25] [samp-detutils]: (debug) - Interior id assigned.
[22:15:25] [samp-detutils]: (debug) - Entrance coordinates assigned to interior data.
[22:15:25] [samp-detutils]: (debug) - Exit coordinates assigned to interior data.
[22:15:25] [samp-detutils]: (debug) - Virtual world and interiorids assigned to custom interior.
[22:15:25] [samp-detutils]: (debug) - Internal interior data assigned.
[22:15:25] |======================================|
[22:15:25]             d_interiors.inc             
[22:15:25]           Successfully loaded!          
[22:15:25]                                         
[22:15:25]                By: DEntisT              
[22:15:25] |======================================|
[22:15:25] [samp-detutils]: (debug) - ongminit :: Commands loading finished.
[22:15:25] |======================================|
[22:15:25]              d_commands.inc             
[22:15:25]           Successfully loaded!          
[22:15:25]                                         
[22:15:25]                By: DEntisT              
[22:15:25] |======================================|
[22:15:25] |======================================|
[22:15:25]               d_fmargs.inc              
[22:15:25]           Successfully loaded!          
[22:15:25]                                         
[22:15:25]                By: DEntisT              
[22:15:25] |======================================|
[22:15:25] gamemode loaded.
[22:15:25] Number of vehicle models: 0
[22:15:47] [connection] 127.0.0.1:58457 requests connection cookie.
[22:15:48] [connection] incoming connection: 127.0.0.1:58457 id: 0
[22:15:48] [join] Unity has joined the server (0:127.0.0.1)
[22:15:48] [samp-detutils]: (debug) - fmargs :: Function id : 1 successfully called.
[22:15:48] [samp-detutils]: (debug) - fmargs :: Function id : 2 successfully called.
[22:15:48] [samp-detutils]: (debug) - playerupdate :: Gametext shown.
[22:15:53] [samp-detutils]: (debug) - fmargs :: Function id : 1 successfully called.
[22:15:53] [samp-detutils]: (debug) - nearintcallback :: Player entered the interior with id : 1.
[22:15:53] [samp-detutils]: (debug) - tpcll :: Player ( id : 0 ) is now controlable.
[22:15:53] [samp-detutils]: (debug) - keystate :: OnPlayerNearEntrance called successfully.
[22:15:54] [samp-detutils]: (debug) - tpcll :: Player ( id : 0 ) is now controlable.
[22:15:54] [samp-detutils]: (debug) - nearintcallback :: Player exited the interior with id : 1.
[22:15:54] [samp-detutils]: (debug) - fmargs :: Function id : 1 successfully called.
[22:15:54] [samp-detutils]: (debug) - keystate :: OnPlayerNearEntrance called successfully.
[22:15:59] [samp-detutils]: (debug) - keystate :: util function 'ResOnUpdateBool' called successfully.
[22:15:59] [samp-detutils]: (debug) - opct :: Successfully declared variables.
[22:15:59] [samp-detutils]: (debug) - opct :: cmdtext[] validated.
[22:15:59] [samp-detutils]: (debug) - opct :: Formatted function strings successfully.
[22:15:59] Command /sayhi worked.
[22:15:59] [samp-detutils]: (debug) - opct :: Called custom debug function : sayhi@dbg.
[22:15:59] [samp-detutils]: (debug) - opct :: position variable validated.
[22:15:59] [samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2
[22:15:59] [samp-detutils]: (debug) - fmargs :: Function id : 1 successfully called.
[22:16:03] [samp-detutils]: (debug) - opct :: Successfully declared variables.
[22:16:03] [samp-detutils]: (debug) - opct :: cmdtext[] validated.
[22:16:03] [samp-detutils]: (debug) - opct :: Formatted function strings successfully.
[22:16:03] Alias command /hi also worked.
[22:16:03] [samp-detutils]: (debug) - opct :: Called custom debug function : hi@dbg.
[22:16:03] [samp-detutils]: (debug) - opct :: position variable validated.
[22:16:03] [samp-detutils]: (debug) - opct :: OnPlayerCommandText(playerid, cmdtext[]) returned function call. ID: 2
[22:16:03] [samp-detutils]: (debug) - fmargs :: Function id : 1 successfully called.
[22:16:12] [samp-detutils]: (debug) - playerupdate :: Gametext shown.
[22:16:23] [samp-detutils]: (debug) - keystate :: util function 'ResOnUpdateBool' called successfully.
[22:16:25] [samp-detutils]: (debug) - playerupdate :: Gametext shown.
[22:16:36] [samp-detutils]: (debug) - keystate :: util function 'ResOnUpdateBool' called successfully.
[22:16:36] [samp-detutils]: (debug) - playerupdate :: Gametext shown.
[22:16:44] [samp-detutils]: (debug) - ClearPlayerInteriorData called successfully.
[22:16:44] [samp-detutils]: (debug) - ClearPlayerInteriorData action successfully performed.
[22:16:44] [samp-detutils]: (debug) - playerdiscc :: Player interior data cleared.
[22:16:44] [part] Unity has left the server (0:1)
[22:16:47] [samp-detutils]: (debug) - keystate :: util function 'ResOnUpdateBool' called successfully.

*/
