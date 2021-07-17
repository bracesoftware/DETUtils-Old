#include <a_samp>
#define detutils_debug
#include "DETUTILS\d_commands"
#include "DETUTILS\d_interiors"

main()
{
	print("gamemode loaded");
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
    SendClientMessage(playerid, -1, "You entered bank.");
    return 1;
  }
  else if(IsInteriorActionPerformed(INTERIOR_ACTION_EXIT))
  {
    SendClientMessage(playerid, -1, "You exited bank.");
    return 1;
  }
  return 1;
}

/*

Everything works fine as it should.

*/
