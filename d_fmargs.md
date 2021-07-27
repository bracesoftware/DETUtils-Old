# d_fmargs.inc

Using *d_fmargs.inc* you can easily use specifiers in string-like type arguments of various SA:MP functions.

![specifiers-used-without-format](img/d_fmargs.png)

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
 
- SendRconCommand
## Messages from creator

### Warnings
------------------------------------------
- No warnings - yet.

### Notes
------------------------------------------
***Making filterscript with d_fmargs?***
------------------------------------------
- Well, I have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *d_fmargs*.
