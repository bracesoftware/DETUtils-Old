# d_fmargs.inc

Using *d_fmargs.inc* you can easily use specifiers in string-like type arguments of various SA:MP functions.

[Go back to home page...](README.md)

## Quick start

- Usage is really basic.

Example:

```pawn

public OnPlayerSpawn(playerid)
{
  SendClientMessage(playerid, -1, "You are spawned, %s.", ReturnPlayerName(playerid));
  return 1;
}
```
**TIP**: Function *ReturnPlayerName* is provided by extra library include *d_libtags.inc*.

## Warnings

- If you provide a specifier in a string, but not a value as well, calling the function will crash the server.

Bad code:
```pawn
public OnPlayerSpawn(playerid)
{
  SendClientMessage(playerid, -1, "You are spawned, %s."); // this crashes the server
  return 1;
}
```
Good code:
```pawn
public OnPlayerSpawn(playerid)
{
  SendClientMessage(playerid, -1, "You are spawned, %s.", ReturnPlayerName(playerid));
  return 1;
}
```
## API

Functions which will work like this after including *d_fmargs.inc* are:

| SA:MP functions      | Description                                                                                |
| -------------------- | ------------------------------------------------------------------------------------------ |
SendClientMessage      | - Sends a message to certain client. |
SendClientMessageToAll | - Sends a message to all players (clients). | 
GameTextForPlayer      | - Shows a GameText to certain player. |
GameTextForAll         | - Shows a GameText to all players. |
TextDrawCreate         | - Creates a global TextDraw. |
CreatePlayerTextDraw   | - Creates a player TextDraw. |
TextDrawSetString      | - Changes global TextDraw's string. |
PlayerTextDrawSetString| - Changes player TextDraw's string. |
SendRconCommand        | - Sends a RCON command to a server. |

## `sscanf`
- This include also provides a Pawn implementation of `sscanf` functions. Below, you can see an example on how to use these features:

```pawn
@command(.type = SLASH_COMMAND) sscanftest(playerid, params[])
{
	new id, array[2][3];
	
	if(sscanf do(params, array) == SSCANF_FAIL) // If sscanf fails (no spaces in a string)
	{
		return SendClientMessage(playerid, -1, "Sscanf failed.");
	}

	SendClientMessage(playerid, -1, "Sscanf succedeed.");

	return 1;
}
```

- You can disable these optional `sscanf` features using:

```pawn
#define DETUTIS_NO_SSCANF
```
