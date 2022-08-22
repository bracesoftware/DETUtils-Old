# d_anticheat.inc
SA:MP AntiCheat - basic anti-cheating system used to fight off the most famous hacks used by cheaters on various servers.

[Go back to home page...](README.md)
## How to start to use?

- You do not need to worry about anything right now, just by including **d_samp.inc**, your anti-cheat system is ready to use after you start the script.

- Anti-Cheat is built into these functions below:

| SA:MP functions      | Anti-Cheat function   | Description                                                        |
| -------------------- | -----------------------|------------------------------------------------------------------- |
| GivePlayerMoney      | saves the money variable        | - Gives a player certain amount of money.                          |
| SetPlayerSkin        | saves the skin id          | - Sets a certain skin for a certain player.                        |
| SetPlayerPos         | saves player's position    | - Sets player's position.             |
| SetPlayerHealth      | saves player's health | - Sets player's health.         |
| SetPlayerArmour      | saves player's armour | - Sets player's armour.         |
| ShowPlayerDialog     | saves player's dialog ID shown | - Shows dialog to player.         |
| ShowMenuForPlayer    | saves player's shown menu ID | - Shows a menu for player. |

## API (programming interface)

- As I said, functions above are just replacements, or rather **hooks** which are used by anti-cheat system. But, there is more - they're shown below.

### Callback - ``OnPlayerCheatDetected``

- Called if player is cheating or unknown player statistics variable modification is detected. Callback is using *playerid* and *cheattype* parameters.

```pawn
public OnPlayerCheatDetected(playerid, cheattype)
{
    if(cheattype == CHEAT_TYPE_MONEY)
    {
        SendClientMessage(playerid, -1, "Stop using money hack, you could've just robbed a bank - but we got you!");
        
        // Code.
    }
    else if(cheattype == CHEAT_TYPE_SKINCHANGER)
    {
        SendClientMessage(playerid, -1, "Don't dare to change your skin this way ever again!");
        
        // Code.
    }
    return 1;
}
```

### SendPlayerCheatCheck
- Check player for cheats, all-in-one function.

```pawn
SendPlayerCheatCheck(playerid, CHEAT_TYPE_(...));
```

--------------------------------------------

### CheckPlayerMoney

- Used to check player's money. If player used third party softwares to change amount of money he has, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_MONEY**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerMoney(playerid);
  return 1;
}
```

**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerSkin

- Used to check player's skin. If player used third party softwares to change his skin, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_SKINCHANGER**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerMoney(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerPos

- Used to check if is player using teleport hacks. If player used third party softwares to change his position, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_TELEPORT**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerPos(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerPing

- Used to check player's ping. If player's ping is higher than 250, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_HIGHPING**. Though, this isn't a cheat - it's just a detecting player's high ping which can make anti-cheat system send fake cheat reports by an accident.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerPing(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerHealth

- Used to check player's health. If player used third party softwares to change his health, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_HEALTH**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerHealth(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerArmour

- Used to check player's armour. If player used third party softwares to change his armour, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_ARMOUR**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerArmour(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerSpeed

- Used to check player's speed. If player's speed is too high, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_SPEEDHACK**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerSpeed(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerDialog

- Used to check player's dialog ID shown. If dialog ID player responded to is different from the dialog ID shown to the player by the script, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_DIALOG**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerDialog(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### CheckPlayerMenu

- Used to check player's menu ID shown. If menu ID player responded to is different from the menu ID shown to the player by the script, anti-cheat system will detect that and call **OnPlayerCheatDetected** with cheat type **CHEAT_TYPE_MENU**.

```pawn
public OnPlayerUpdate(playerid)
{
  CheckPlayerMenu(playerid);
  return 1;
}
```
**NOTE:** Read *Messages from creator* part for more information.

### ToggleAntiCheatSystem

- Used to toggle anti-cheat system on or off. Efficient in commands and also if you don't want to use **d_anticheat.inc** at all.

```pawn
@command(.type = SLASH_COMMAND) acon(p, p[])
{
    ToggleAntiCheatSystem(true);
    return 1;
}

@command(.type = SLASH_COMMAND) acoff(p, p[])
{
    ToggleAntiCheatSystem(false);
    return 1;
}
```

**TIP:** Anti-Cheat is, by default, turned on after including **d_samp.inc**!

## Messages from creator

### Cheat checking

- When **ToggleAntiCheatSystem(false);** is executed, all cheat checking functions such as *CheckPlayerMoney* or *CheckPlayerSkin* etc., will not work (which is the point, this is just a quick reminder). Make sure your anti-cheat system is on so all cheat checking functions can work.

### Contribution

- As you can see, this system is currently really small and is far away from being done, the point is to wipe all the cheaters from SA:MP scene and make the game fun and exciting. The way you can help is to *contribute* to the project - add more stuff and do a pull request!

### Debugging

- If ``detutils_debug`` is enabled, ``d_anticheat.inc`` contains built-in command **/acstats** which displays a dialog with player's information details, like health, money or armour - useful feature for testing.

### Warnings

#### Automatic cheat checking

- Yes, ``d_anticheat`` has automatic cheat checking, as I mentioned before - just by including **d_samp.inc**, your anti-cheat system is ready to use. This means that when you compile with ``d_anticheat.inc`` included, anticheat will work and check all players online for cheats, but keep in mind that cheat checking is performed only every **1** minute.

#### Debugging dialog

- Debugging dialog mentioned above will use dialog ID **0**.

Include code:
```pawn
#define DIALOG_ID_ACSTATS 0
```

- But don't worry, you can modify this value before including **d_samp.inc** - just use:

```pawn
#define detutils_debug
#define DIALOG_ID_ACSTATS Your_Value

#include <a_samp>

// Other includes...

#include <d_samp>
