# d_dmzone.inc
SA:MP DeathMatch Zones - Provides the creation of deathmatch zones, adding and removing players from deathmatch zones.

[Go back to home page...](README.md)
## How to start to use?
## API
### `public` OnDeathMatchZoneCreate
- Called whenever a deathmatch zone is created.
### `public` OnDeathMatchZoneDestroy
- Called whenever a deathmatch zone is destroyed.
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

### `RemovePlayerFromDeathMatchZone`
- Remove the player from deathmatch zone.
## Messages from creator
### Warnings
### Notes
