# d_fmargs.inc

Using *d_fmargs.inc* you can easily use specifiers in string-like type arguments of various SA:MP functions.

[Go back to home page...](README.md)

# Usage

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

# API ( programming interface )

Functions which will work like this after including *d_fmargs.inc* are:

- SendClientMessage 

- SendClientMessageToAll 

- GameTextForPlayer 

- GameTextForAll 

- TextDrawCreate 

- CreatePlayerTextDraw 

- TextDrawSetString 

- PlayerTextDrawSetString 
