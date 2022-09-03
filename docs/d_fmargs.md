# d_fmargs.inc

Pawn FuncArgs - Using `d_fmargs` you can easily use specifiers in string-like type arguments of various SA:MP functions.

[Go back to home page...](README.md)

## How to start to use?

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

## API

Functions whose will work like this after including `detutils` are:

| SA:MP functions      | Description                                                                                |
| -------------------- | ------------------------------------------------------------------------------------------ |
SendClientMessage      | Sends a message to certain client. |
SendClientMessageToAll | Sends a message to all players (clients). | 
GameTextForPlayer      | Shows a GameText to certain player. |
GameTextForAll         | Shows a GameText to all players. |
TextDrawCreate         | Creates a global TextDraw. |
CreatePlayerTextDraw   | Creates a player TextDraw. |
TextDrawSetString      | Changes global TextDraw's string. |
PlayerTextDrawSetString| Changes player TextDraw's string. |
SendRconCommand        | Sends a RCON command to a server. |
Update3DTextLabelText  | Updates the 3D text label text.   |
UpdatePlayer3DTextLabelText | Updates the player 3D text label text. |

## `sscanf`
- This include also provides a Pawn implementation of `sscanf` functions. Below, you can see an example on how to use these features:

```pawn
@command(.type = SLASH_COMMAND) sscanftest(playerid, params[])
{
	new id, array[2][3];
	
	if(sscanf do(params, array, 2) == SSCANF_FAIL) // If sscanf fails (no spaces in a string)
	{
		return SendClientMessage(playerid, -1, "Sscanf failed.");
	}

	SendClientMessage(playerid, -1, "Sscanf succedeed.");

	return 1;
}
```

- You can disable these optional `sscanf` features using:

```pawn
#define DETUTILS_NO_SSCANF
```
Argument explanation:
```pawn
sscanf do(source, address, args = 1);
```
- `source` is a source string to get data from.
- `address` is an 2D array to assign data to.
- `args` is a count of given arguments in a string.
