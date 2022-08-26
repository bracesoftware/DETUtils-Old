# d_visual.inc
SA:MP Visual - Library or libraries whose contain functions whose provide in-game visible effects such as weapon features and deathmatch zones!

[Go back to home page...](README.md)

## Usage

- Usage is really simple. *d_visual.inc* provides very few functions whose can be used for roleplay purposes!

## API ( programming interface )

### `CreateDroppedWeapon`

- This function creates the weapon object which can be either picked up or destroyed by the player.

Example:

```pawn
public OnGameModeInit()
{
  // Create AKM with 100 ammo on coordinates 811.1299, -1616.0647, 13.5469:
  CreateDroppedWeapon(30, 100, 811.1299, -1616.0647, 13.5469);
  return 1;
}
```

### ``public`` OnPlayerPickUpDroppedWeapon

- Callback called whenever the player picks up a certain dropped weapon.

```pawn
public OnPlayerPickUpDroppedWeapon(playerid)
{
    SendClientMessage(playerid, -1, "You picked up a gun.");
    return 1;
}
```
### ``public`` OnPlayerDropWeapon

- Callback called whenever the player drops away a certain weapon.

```pawn
public OnPlayerDropWeapon(playerid)
{
    SendClientMessage(playerid, -1, "You threw away a gun.");
    return 1;
}
```

### ``public`` OnPlayerDestroyDroppedWeapon

- Callback called whenever the player destroys a certain dropped weapon.

```pawn
public OnPlayerDestroyDroppedWeapon(playerid)
{
    SendClientMessage(playerid, -1, "You destroyed a gun.");
    return 1;
}
```

### `SendMessageInRange`

- This function allows you to send the message only to the players within the certain range (radius).

```pawn
public OnPlayerExitInterior(playerid)
{
  new message[256];
  format(message, 256, "%s opens the door and leaves the place.", ReturnPlayerName(playerid));
  SendMessageInRange(3.0, playerid, message, -1);
  return 1;
}
```

### `RemovePlayerWeapon`

- This function removes the certain player's weapon from certain weapon's slot.

Example:

```pawn
new weapon = GetPlayerWeapon(playerid);
RemovePlayerWeapon(playerid, weapon);
```

### `IsValidWeapon`

- Checks if is weapon an actual valid weapon. If the weapon ID is equal to or greater than 1 and equal to or less than 18, and if it is equal to or greater than 21 and equal to or less than 46, then that weapon is a valid weapon - otherwise not.

```pawn
static Weapon_IsValidWeapon(weapid) return IsValidWeapon(weapid);
```

### ``public`` OnPlayerScreenUpdate

- Called whenever the player's screen gets updated - that update can be textdraw and gametext visibility for now.
```pawn
public OnPlayerScreenUpdate(playerid, updatetype)
{
    if(updatetype == SCREEN_UPDATE_PLAYER_TD_SHOW)
    {
        SendClientMessage(playerid, -1, "Player TD shown.");
    }
    if(updatetype == SCREEN_UPDATE_PLAYER_TD_HIDE)
    {
        SendClientMessage(playerid, -1, "Player TD hidden.");
    }
    if(updatetype == SCREEN_UPDATE_GLOBAL_TD_SHOW)
    {
        SendClientMessage(playerid, -1, "Global TD shown.");
    }
    if(updatetype == SCREEN_UPDATE_GLOBAL_TD_HIDE)
    {
        SendClientMessage(playerid, -1, "Global TD hidden.");
    }
    if(updatetype == SCREEN_UPDATE_GAMETEXT_SHOW)
    {
        SendClientMessage(playerid, -1, "GameText shown.");
    }
    if(updatetype == SCREEN_UPDATE_GAMETEXT_HIDE)
    {
        SendClientMessage(playerid, -1, "GameText hidden.");
    }
    if(updatetype == SCREEN_UPDATE_GTD_CHANGE_POS)
    {
        SendClientMessage(playerid, -1, "Global TD changed position.");
    }
    if(updatetype == SCREEN_UPDATE_PTD_CHANGE_POS)
    {
        SendClientMessage(playerid, -1, "Player TD changed position.");
    }
    return 1;
}
```

### `SetPlayerVehiclePos`

- This function sets player's and player's vehicle's position.

```pawn
public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER)
    {
        SetPlayerVehiclePos(playerid, 825.6589,-1614.8202,13.5469);
    }
    return 1;
}
```

### `PreloadAnimationLibrary`

- This function preloads the certain animation library which is, sometimes, neccessary for applying animation from certain animation libraries.

```pawn
PreloadAnimationLibrary(playerid, "PED");
```
### ``public`` OnPlayerWeaponChange
- Below, you can see the usage of it, and explanation of it.
```pawn
public OnPlayerWeaponChange(playerid, oldweapon, newweapon)
{
    new oldweap[32], newweap[32]; // Create 2 strings for weapon names.
    GetWeaponName(oldweapon, oldweap, sizeof oldweap); // Get weapon name of the old weapon.
    GetWeaponName(newweapon, newweap, sizeof newweap); // Get weapon name of the new weapon.
    if(oldweapon == 0) // If player didn't have any weapon...
    {
        format(oldweap, sizeof oldweap, "none"); // ... format `oldweap` string. 
    }
    if(newweapon == 0) // Or, if the new weapon is my hand...
    {
        format(newweap, sizeof newweap, "none"); // ... format `newweap` string.
    }
    SendClientMessage(playerid, -1, "You changed your weapon from %s to %s.", oldweap, newweap); // Send the message.
    return 1;
}
```
Results are, if I, for example picked AK47 while holding Desert Eagle:
```
You changed your weapon from Desert Eagle to AK47.
```
## Built-in visual features
### Special action features
```pawn
@command(.type = SLASH_COMMAND) pickgun(playerid, params[]) 
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_PICKUP_WEAPON); // Pick up nearby dropped weapon.
    return 1;
}

@command(.type = SLASH_COMMAND) dropgun(playerid, params[]) 
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DROP_WEAPON); // Drop weapon which the player is holding.
    return 1;
}

@command(.type = SLASH_COMMAND) destroygun(playerid, params[]) 
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DESTROY_WEAPON); // Destroy nearby dropped weapon.
    return 1;
}
```
- ``d_visual`` also hooks ``SetPlayerSpecialAction`` native in order to import some new action IDs into it. You can check the code shown above in order to see new action IDs added. 
### Headshot system
- The library contains sniper rifle headshot system. Whenever player shoots another player into the head with sniper rifle, new callback **OnPlayerScoreSniperHeadshot** will be called.

```pawn
public OnPlayerScoreSniperHeadshot(playerid, killedid)
{
    new message[256];
    format(message, 256, "You killed %s by headshot.", ReturnPlayerName(killedid));
    SendClientMessage(playerid, -1, message);
    return 1;
}
```

### `d_visual_dmzones.inc`

- `d_visual_dmzones` is a `d_visual` "module" which provides the deathmatch zone creation and management. Read more about it [here](d_dmzone.md)!
