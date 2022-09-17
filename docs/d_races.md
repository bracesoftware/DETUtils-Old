# d_races.inc
SA:MP Races - Create races, add and remove players from them, start them and end them.

[Go back to the home page...](../README.md)

## How to start to use?
- The most basic example on getting started with using the library:

```pawn
public OnRaceCreate(racename[], maxplayers, Float:startX, Float:startY, Float:startZ,
    Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size)
{
    printf("OnRaceCreate: %s, %i, %f,%f,%f,%f,%f,%f,%f", racename, 
        maxplayers, Float:startX, Float:startY, Float:startZ,
        Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size);
    return 1;
}

public OnPlayerJoinRace(playerid, racename[])
{
    fmargs_SendClientMessage(playerid, -1, "You joined the race %s!", racename);
    return 1;
}

public OnPlayerLeaveRace(playerid, racename[])
{
    fmargs_SendClientMessage(playerid, -1, "You left the race %s!", racename);
    return 1;
}

public OnPlayerFinishRace(playerid, racename[], place)
{
    fmargs_SendClientMessage(playerid, -1, "Congrats! You finished %s! Your place: %ith", racename, place);
    return 1;
}

public OnRaceStart(racename[])
{
    fmargs_SendClientMessageToAll(-1, "Race %s started", racename);
    return 1;
}

public OnRaceFinish(racename[])
{
    fmargs_SendClientMessageToAll(-1, "Race %s finished", racename);
    return 1;
}

@command(.type = SLASH_COMMAND) joinrace(playerid, params[])
{
    CreateRace("My race", 1, 811.1299,-1616.0647,13.5469,825.6589,-1614.8202,13.5469);
    AddPlayerToRace(playerid, "My race");
    StartRace("My race");
    return 1;
}
```

## API (functions)

### `CreateRace`
```pawn
native CreateRace(const name[], maxplayers, Float:startX, Float:startY, Float:startZ, Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size = 5.0);
```

### `DestroyRace`
```pawn
native DestroyRace(const name[]);
```

### `AddPlayerToRace`
```pawn
native AddPlayerToRace(playerid, const name[]);
```

### `StartRace`
```pawn
native StartRace(const name[]);
```

## API (public callbacks)

### `OnRaceCreate`
```pawn
public OnRaceCreate(racename[], maxplayers, Float:startX, Float:startY, Float:startZ, Float:finishX, Float:finishY, Float:finishZ, Float:checkpoint_size)
{
    return 1;
}
```

### `OnRaceDestroy`
```pawn
public OnRaceDestroy(racename[])
{
    return 1;
}

### `OnPlayerJoinRace`
```pawn
public OnPlayerJoinRace(playerid, racename[])
{
    return 1;
}
```

### `OnPlayerLeaveRace`
```pawn
public OnPlayerLeaveRace(playerid, racename[])
{
    return 1;
}
```

### `OnPlayerFinishRace`
```pawn
public OnPlayerFinishRace(playerid, racename[], place)
{
    return 1;
}
```

### `OnRaceStart`
```pawn
public OnRaceStart(racename[])
{
    return 1;
}
```

### `OnRaceFinish`
```pawn
public OnRaceFinish(racename[])
{
    return 1;
}
```
