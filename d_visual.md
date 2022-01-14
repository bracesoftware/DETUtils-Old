# d_visual.inc
- Library or libraries whose contain functions whose provide in-game visible effects.

[Go back to home page...](README.md)

## Usage

- Usage is really simple. *d_visual.inc* provides very few functions whose can be used for roleplay purposes!

**NOTE**: These libraries require *streamer*.

## API ( programming interface )

### CreateDroppedGun

- This function creates the gun object which can be picked up either destroyed by player.

Example:

```pawn
public OnGameModeInit()
{
  // Create AKM with 100 ammo on coordinates 811.1299, -1616.0647, 13.5469:
  CreateDroppedGun(30, 100, 811.1299, -1616.0647, 13.5469);
  return 1;
}
```

### ``public`` OnPlayerPickUpGun

- Callback called whenever player picks up a certain gun.

```pawn
public OnPlayerPickUpGun(playerid)
{
    SendClientMessage(playerid, -1, "You picked up a gun.");
    return 1;
}
```
### ``public`` OnPlayerThrowGun

- Callback called whenever player throws away a certain gun.

```pawn
public OnPlayerThrowGun(playerid)
{
    SendClientMessage(playerid, -1, "You threw away a gun.");
    return 1;
}
```
**WARNING:** If player had any weapons, and he dies, he will lose all the weapons and those will be created as dropped guns on the coordinates he died on - so **OnPlayerThrowGun** will be called.

### ``public`` OnPlayerDestroyGun

- Callback called whenever player destroys a certain gun.

```pawn
public OnPlayerDestroyGun(playerid)
{
    SendClientMessage(playerid, -1, "You destroyed a gun.");
    return 1;
}
```

### SendMessageInRange

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

### RemovePlayerWeapon

- This function removes the certain player's weapon from certain weapon's slot.

Example:

```pawn
new weapon = GetPlayerWeapon(playerid);
RemovePlayerWeapon(playerid, weapon);
```

### IsValidWeapon

- Checks if is weapon an actual valid weapon. If the weapon ID is equal to or greater than 1 and equal to or less than 18, and if it is equal to or greater than 21 and equal to or less than 46, then that weapon is a valid weapon - otherwise not.

```pawn
static Weapon_IsValidWeapon(weapid) return IsValidWeapon(weapid);
```

### FadePlayerScreen

- This function fades player's screen. Player's screen becomes black and becomes brighter every 50 milliseconds.

```pawn
public OnPlayerSpawn(playerid)
{
  FadePlayerScreen(playerid);
  return 1;
}
```

### ``public`` OnPlayerScreenFade

- Callback called when ``FadePlayerScreen`` is used.

```pawn
public OnPlayerScreenFade(playerid)
{
    SendClientMessage(playerid, -1, "Your screen faded!");
    return 1;
}
```

### SetPlayerVehiclePos

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

## Built-in visual features
### Commands
#### /pickgun
- This command allows the player to pick up the gun if he is standing near it.
-----------------------------------------
#### /destroygun
- This one allows player to destroy the object of the gun.
-----------------------------------------
#### /throwgun
- This one, obviously, allows the player to throw a gun he is holding away.
- **NOTE**: This command has timer attached to it. Command is only operable every 30 seconds. If you are spamming with it, it will not work until the timer toggles player's ability to throw guns again.
-----------------------------------------
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
