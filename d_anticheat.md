# d_anticheat.inc
SA:MP AntiChat - basic anti-cheating system used to fight off the most famous hacks used by cheaters on verious servers.

[Go back to home page...](README.md)
## How to start to use?

- You do not need to worry about anything right now, just by including **d_samp.inc**, your anti-cheat system is ready to use after you start the script.

- Anti-Cheat is built into these functions below:

| SA:MP functions      | Anti-Cheat function   | Description                                                        |
| -------------------- | -----------------------|------------------------------------------------------------------- |
| GivePlayerMoney      | saves the money variable        | - Gives a player certain amount of money.                          |
| SetPlayerSkin        | saves the skin id          | - Sets a certain skin for a certain player.                        |

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

### ToggleAntiCheatSystem

- Used to toggle anti-cheat system on or off. Efficient in commands and also if you don't want to use **d_anticheat.inc** at all.

```pawn
new Command:acon(playerid,params[])
{
    ToggleAntiCheatSystem(true);
    return 1;
}

new Command:acoff(playerid,params[])
{
    ToggleAntiCheatSystem(false);
    return 1;
}
```

**TIP:** Anti-Cheat is, by default, turned on after including **d_samp.inc**!

## Messages from creator

### Cheat checking

- When **ToggleAntiCheatSystem(false);** is executed, all cheat checking functions such as *CheckPlayerMoney* or *CheckPlayerSkin* will not work (which is the point, this is just a quick reminder). Make sure your anti-cheat system is on so all cheat checking functions can work.

### Contribution

- As you can see, this system is currently really small and is far away from being done, the point is to wipe all the cheaters from SA:MP scene and make the game fun and exciting. The way you can help is to *contribute* to the project - add more stuff and do a pull request!
