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

## Warning

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
# API ( programming interface )

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
