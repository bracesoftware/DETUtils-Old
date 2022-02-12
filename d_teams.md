# d_teams.inc
SA:MP Teams - Create teams, add or remove players from them, enable friendly fire for deathmatch zones, create team commands and team properties.

[Go back to home page...](README.md)
## How to start to use?
- Start to use by creating a team.
```pawn
CreateTeam("Amazing people");
```
- After you've created a team, add the player to that team.

```pawn
@command(.type = SLASH_COMMAND) joinamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You're now amazing.");
    AddPlayerToTeam(playerid, "Amazing people");
    return 1;
}
```
- You can create a normal slash command so the player can join the team at anytime. To remove a player from a team, use a same function.

```pawn
@command(.type = SLASH_COMMAND) quitamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You aren't amazing anymore.");
    AddPlayerToTeam(playerid, "NO_TEAM"); // 'NO_TEAM' is a 'hardcoded' internal team which can't be deleted or either recreated.
    // To remove player from a team, just use 'NO_TEAM' for a team name.
    return 1;
}
```
## API and features
- Let's take a look at all of the include features, including visual ones and scripting functions.
---------------------------------
### Features
---------------------------------
### Team commands
- Including `d_teams.inc` extends the some of the possibilities provided by `d_commands.inc`. Though, now you can create special team commands, whose can be used only by a certain team's members. Let's create one for a team we made in the example above:

```pawn
@command(.type = TEAM_COMMAND, .team = "Amazing people") amiamazing(playerid, params[])
{
    SendClientMessage(playerid, -1, "You are amazing!");
    return 1;
}
```
### Team properties
- Also, including *d_teams.inc* extends the capabilities of *d_properties.inc*, which means you can also create team properties - properties whose can be accessed only by a certain team. Creating those properties is easy to do, you only add an extra parameter next to property name - team name. So to create a property for a team we made in the example:

```pawn
CreatePropertyEntranceForTeam("Your Interior", "Amazing people", 825.6589,-1614.8202,13.5469, 0, 0, true, INTERIOR_CUSTOM, 0.0000, 0.0000, 4.0000, 1, 1);
```
---------------------------------
### Functions
---------------------------------
### `CreateTeam`
- Create a team.

### `DeleteTeam`
- Delete a team.

```pawn
DeleteTeam("Amazing people");
```

### `GetTeamMemberCount`
- Get the member count of a certain team.
```pawn
GetTeamMemberCount("Amazing people");
```

### `AddPlayerToTeam`
- Add (set) player to a certain team.

### `CreatePropertyEntranceForTeam`
- Create a property for a certain team. Note that this works ONLY if the file `d_properties.inc` is included.
## Messages from creator
### Warnings
1. Players within the same team cannot harm each other.
2. `AddPlayerToTeam` only sets player's team at ONCE, which means player can't be a member of more than one team.
3. Player's team is set to `NO_TEAM` after the player disconnects.
### Notes
- No important notes yet.
