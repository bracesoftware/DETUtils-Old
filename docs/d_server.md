# d_server.inc
SA:MP Server - Generally server-related functions in one library.

[Go back to the home page...](../README.md)
## API
### `ArePlayerPedAnimsUsed`
- Checks if the player ped anims used in the server.
```pawn
if(ArePlayerPedAnimsUsed()) printf("Player ped anims are used.");
```
### public `OnPlayerClientCheckReceived`
```pawn
public OnPlayerClientCheckReceived(playerid, type, memaddr, memoffset, bytecount)
{
	printf("Client check on player id %i started.", playerid);
	return 1;
}
```
- This callback is called whenever a client check on a certain player starts to perform.

### `IsPlayerUsingPCClient`
- Checks if the player is using a standard PC client.

### `IsPlayerUsingAndroidClient`
- Checks if the player is using an Android client.

### `GetPlayerClient`
- Returns a player client ID.

```c
#define PLAYER_CLIENT_UNKNOWN -1
#define PLAYER_CLIENT_ANDROID 0
#define PLAYER_CLIENT_PC 1
```

## Notes
- You can disable Android check features by using:

```pawn
#define DETUTILS_NO_ANDROID_CHECK
```

### public `OnPlayerClientCheckPerformed`
- Called after the client check was performed.
```pawn
public OnPlayerClientCheckPerformed(playerid, actionid, memaddr, retndata)
{
	if(IsPlayerUsingAndroidClient(playerid))
	{
		SendClientMessage(playerid, -1, "You are using an Android client!");
	}
	if(IsPlayerUsingPCClient(playerid))
	{
		SendClientMessage(playerid, -1, "You are using an PC client!");
	}
	return 1;
}
```
