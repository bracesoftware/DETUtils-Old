# a_interiors.inc
SA:MP Interiors - an easy way to create custom interiors.

[Go back to home page...](README.md)

## How to start to use?

### Interior creation

To create a interior with *a_interiors*, make sure you use *CreateCustomInterior* function.

Let's see how it works:

```pawn

public OnGameModeInit()
{
  CreateCustomInterior("PoliceStation", 243.66, 345.21, 12.78, 9.0, 4564.8, 12.8, 1, 0, 1, 0);
  return 1;
}

```

... and - that's it, interior entrance is created on coordinates *243.66,345.21,12.78*, and interior exit on coordinates 9.0, 4564.8, 12.8. And whenever player press key which he use to enter a car near entrance coordinates given, he will be *teleported* on coordinates of interior exit.

**WARNING**: Note that these coordinates aren't really coordinates of police station in the game. This was just an example for parameters.

### Interior debugging

- Whenever *CreateCustomInterior* is called, it automatically sends debug messages onto the console.

### Interior functions

- There is one really useful feature, in my opinion - literal interior functions.

- These literal interior functions are called whenever player enters/exits specific interior.

Little example:

```pawn

interior PoliceStation(playerid)
{
  if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER))
  {
    SendClientMessage(playerid, -1, "You entered police station.");
  }
  else if(IsInteriorActionPerformed(INTERIOR_ACTION_ENTER))
  {
    SendClientMessage(playerid, -1, "You exited police station.");
  }
  return 1;
}

```

## API ( programming interface )

### Functions

*a_interiors.inc* also contains some handy functions, let's see.

**CallLocalCommand**

- This function does nothing besides returning command function call.

Parameters:

   - command_name (string)
   - specifiers (string)
   - command_firstparam (integner)
   - command_secparam (string)
  
Example:

```pawn
CallLocalCommand("mycommand", "is", playerid, inputtext);
```
**GetDebuggedCommandName**

- This function gets the name of debugged command.

Parameters: noone

Example:

```pawn
debug command mycmd()
{
  print("Command %s successfully called.", GetDebuggedCommandName());
  return 1;
}
```

**CallRemoteCommand**

- Simply, *CallRemoteCommand* works same as *CallLocalCommand* (it has same parameters etc.) - but the command can be called from anywhere. Even, from another file.

## Messages from creator

### Warnings

- No warnings - yet.

### Notes

***Making filterscript with a_interiors?***
- Well, we have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *a_interiors*.
