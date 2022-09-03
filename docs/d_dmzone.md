# d_visual_dmzones.inc
SA:MP DeathMatch Zones - Provides the creation of deathmatch zones, adding and removing players from deathmatch zones.

[Go back to home page...](README.md)
## How to start to use?
- Start by creating a deathmatch zone.

```pawn
public OnGameModeInit()
{
       // Function.         // Zone name.      // First spawn coord set.     // Second spawn coord set.    // Third spawn coord set.
    CreateDeathMatchZone("Insane DeathMatch", 844.7139,-1614.3539,13.5391,  825.6589,-1614.8202,13.5469,  811.1299,-1616.0647,13.5469);
    return 1;
}
```
## API
### `public` OnDeathMatchZoneCreate
- Called whenever a deathmatch zone is created.

```pawn
public OnDeathMatchZoneCreate(zoneid, zonename[])
{
    printf("DM Zone `%s`[%i] created!", zonename, zoneid);
    return 1;
}
```
### `public` OnDeathMatchZoneDestroy
- Called whenever a deathmatch zone is destroyed.

```pawn
public OnDeathMatchZoneDestroy(zoneid, zonename[])
{
    printf("DM Zone `%s`[%i] destroyed!", zonename, zoneid);
    return 1;
}
```
### `CreateDeathMatchZone`
- Create a deathmatch zone.

### `GetPlayerDeathMatchZoneKills`
- Gets a number of kills player reached. Note that the function will return the value ONLY if the player is in the deathmatch zone. If not, it will return `-1`.

### `IsPlayerInDeathMatchZone`
- Check if the player in the deathmatch zone or not.

### `DestroyDeathMatchZone`
- Destroy a deathmatch zone.

### `IsValidDeathMatchZone`
- Check if the deathmatch zone is valid.

### `GetDeathMatchZoneIDByName`
- Get the deathmatch zone's ID by its name.

### `GetDeathMatchZoneName`
- Get the name of a certain deathmatch zone.

### `AddPlayerToDeathMatchZone`
- Add the player to certain deathmatch zone with a specific weapon set level.

```pawn
@command(.type = SLASH_COMMAND) dmjoin(playerid, params[])
{
    AddPlayerToDeathMatchZone(playerid, "Insane DeathMatch", 1, 10);
    return 1;
}
```
- Function parameters:
```pawn
native AddPlayerToDeathMatchZone(playerid, const name[], spawnid, kitlevel);
```
Parameter explanation:
- `playerid` - the player.
- `name[]` - name of the deathmatch zone.
- `spawnid` - the spawn coordinates set to set player's position on.
- `kitlevel` - weapon kit level.

#### Weapon kit levels
- There are 10 weapon kit levels - higher kit: better weapons.

#### Level 1
- Desert Eagle - 200 ammo
- Shotgun - 100 ammo

#### Level 2
- + MP5 - 400 ammo

#### Level 3
- + AK47 - 400 ammo

#### Level 4
- Instead of AK47: + M4 - 400 ammo

#### Level 5
- Same as level 3 with 50 more ammo for a Shotgun.

#### Level 6
- Same as level 4.

#### Level 7
- Same as level 4, but with max skills for M4.

#### Level 8
- Instead of MP5, new weapon - UZI.
- + Max skills for UZI.
- + 400 ammo for UZI.

#### Level 9
- Same as level 8.
- Instead of UZI, new weapon - Tec9.

#### Level 10
- Instead of Shotgun, new weapon - Sawnoff Shotgun.
- + Max skills for Sawnoff Shotgun.
- Instead of Tec9, new weapon - UZI.

**NOTE:** I didn't have that much ideas for weapon kit levels, contributions and changes are welcome.

### `RemovePlayerFromDeathMatchZone`
- Remove the player from deathmatch zone.

```pawn
@command(.type = SLASH_COMMAND) dmleave(playerid, params[])
{
    RemovePlayerFromDeathMatchZone(playerid);
    return 1;
}
```
## Messages from creator
### Warnings
### Notes
