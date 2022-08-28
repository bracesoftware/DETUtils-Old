# d_factions.inc
SA:MP Factions - Create factions, add or remove players from them, enable friendly fire for deathmatch zones, create faction commands and faction properties.

[Go back to home page...](README.md)
## How to start to use?
- Start to use by creating a team.
```pawn
CreateFaction("Amazing people");
```
- After you've created a faction, add the player to that faction.

```pawn
@command(.type = SLASH_COMMAND) joinamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You're now amazing.");
    AddPlayerToFaction(playerid, "Amazing people");
    return 1;
}
```
- You can create a normal slash command so the player can join the faction at anytime. To remove a player from a faction, use a same function.

```pawn
@command(.type = SLASH_COMMAND) quitamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You aren't amazing anymore.");
    SetPlayerFaction(playerid, "NO_FACTION"); // 'NO_FACTION' is a 'hardcoded' internal faction which can't be deleted or either recreated.
    // To remove player from a faction, just use 'NO_FACTION' for a faction name.
    return 1;
}
```
## API and features
- Let's take a look at all of the include features, including visual ones and scripting functions.

### Features
- New features regarding to other libraries!
### Faction commands
- Including `d_factions.inc` extends the some of the possibilities provided by `d_commands.inc`. Though, now you can create special faction commands, whose can be used only by a certain faction's members. Let's create one for a faction we made in the example above:

```pawn
@command(.type = FACTION_COMMAND, .faction = "Amazing people") amiamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You are amazing!");
    return 1;
}
```
### Faction properties
- Also, including *d_factions.inc* extends the capabilities of *d_properties.inc*, which means you can also create factions properties - properties whose can be accessed only by a certain factions. Creating those properties is easy to do, you only add an extra parameter next to property name - factions name. So to create a property for a faction we made in the example:

```pawn
CreateFactionPropertyEntrance("Your Interior", "Amazing people", 825.6589,-1614.8202,13.5469, 0, 0, true, INTERIOR_CUSTOM, 0.0000, 0.0000, 4.0000, 1, 1);
```
### Faction permissions
- Including `d_factions` will give you new **faction permissions**. When a faction permission is set, all of the certain faction members will have THOSE permissions. Modifying permissions for a player which is in a faction will not work. You can modify permissions only for factions using:

```pawn
SetFactionMemberPermissionInteger("Amazing people", DEFAULT_PLAYER_PERMISSIONS);
```

### Functions
- Functions provided.
### `CreateFaction`
- Create a faction.

### `DeleteFaction`
- Delete a faction.

```pawn
DeleteFaction("Amazing people");
```

### `GetFactionMemberCount`
- Get the member count of a certain faction.
```pawn
GetFactionMemberCount("Amazing people");
```

### `SetPlayerFaction`
- Set the player's current faction.

### `GetPlayerFaction`
- Get the player's faction.

```pawn
new faction[32];
GetPlayerFaction(playerid, faction);
// Now you're supposed to use the "faction" string
```

### `CreateFactionPropertyEntrance`
- Create a property for a certain faction. Note that this works ONLY if the file `d_properties.inc` is included.

### `public` OnFactionCreate
- Called whenever a certain faction is created.

```pawn
public OnFactionCreate(factionid, factionname[])
{
    printf("Team '%s'[%i] created.", factionname, factionid);
    return 1;
}
```
### `public` OnFactionDelete
- Called whenever a certain faction is deleted.

```pawn
public OnFactionDelete(factionid, factionname[])
{
    printf("Team '%s'[%i] deleted.", factionname, factionid);
    return 1;
}
```
## Messages from creator
### Warnings
1. Players within the same faction cannot harm each other.
2. `SetPlayerFaction` only sets player's faction at ONCE, which means player can't be a member of more than one faction.
3. Player's faction is set to `NO_FACTION` after the player disconnects.
### Notes
- No important notes yet.
