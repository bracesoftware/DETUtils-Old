# d_interiors.inc
SA:MP Interiors - an easy way to create custom interiors.

![interiors](img/d_interiors.png)

[Go back to home page...](README.md)

## How to start to use?

### Interior creation
------------------------------------------
To create a interior with *d_interiors*, make sure you use *CreateCustomInterior* function.

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
------------------------------------------
- Whenever *CreateCustomInterior* is called, it automatically sends debug messages in the console.

### Interior callbacks
------------------------------------------
#### OnInteriorActionPerformed

- It's called whenever player enters or exits a **certain** interior. In order to use the callback, you need to specify interior's name and player's ID. Little example is shown below.

```pawn
public OnInteriorActionPerformed(playerid, interiorid, actionid)
{
    new string[256];
    if(actionid == INTERIOR_ACTION_ENTER)
    {
        format(string, 256, "%sYou entered %s, %s. Interior id: %i [%i]", 
            ReturnStringColour(g_GrayColour),
            GetInteriorName(interiorid),
            _ReturnPlayerName(playerid), 
            GetInteriorIDByName(GetInteriorName(interiorid)),
            interiorid);
        SendClientMessage(playerid, -1, string);
        return 1;
    }
    else if(actionid == INTERIOR_ACTION_EXIT)
    {
        format(string, 256, "%sYou exited %s, %s. Interior id: %i [%i]", 
            ReturnStringColour(g_GrayColour),
            GetInteriorName(interiorid),
            _ReturnPlayerName(playerid), 
            GetInteriorIDByName(GetInteriorName(interiorid)),
            interiorid);
        SendClientMessage(playerid, -1, string);
        return 1;
    }
    return 0;
}
```

#### OnPlayerEnterInterior

- This is called whenever player enters any interior. Can be used for big variety stuff. Uses only one parameter - *playerid*.

Example:
```pawn
public OnPlayerEnterInterior(playerid)
{
  new message[256];
  format(message, 256, "%s opens the door and enters the object.", ReturnPlayerName(playerid));
  SendMessageInRange(3.0, playerid, message, -1);
  return 1;
}
```

#### OnPlayerExitInterior

- This is called whenever player exits any interior.

```pawn
public OnPlayerExitInterior(playerid)
{
  new message[256];
  format(message, 256, "%s opens the door and leaves the place.", ReturnPlayerName(playerid));
  SendMessageInRange(3.0, playerid, message, -1);
  return 1;
}
```

**TIP:** Functions *ReturnPlayerName* and *SendMessageInRange* are extra library functions. Include DETUtils to use them.

## API ( programming interface )

### Functions
------------------------------------------
*d_interiors.inc* also contains some handy functions, let's see.

**SetPlayerCustomInterior**
------------------------------------------
- This function sets player's interior. Interior id can be seen after certain interior is created - thanks to debug messages!

**WARNING**: Interior id will be always same unless it is not created on callback *OnGameModeInit* or you changed interior creating algorithm.

Parameters:

  - playerid (integer)
  - custom_interiorid (integer) 

Example:

```pawn
static Your_Function(p,i)
{
  SetPlayerCustomInterior(p, i);
  return 1;
}
```
**GetLastInteriorIDUsed**
------------------------------------------
- Gets last interior id which was used to assign interior data to.

**WARNING**: Works best and properly after using ``CreateCustomInterior``, because ``CreateCustomInterior`` updates the ID.

**SetInteriorEntranceCustomAngles**
------------------------------------------
- This function sets interior entrance and exit position angles.

Parameters:

  - interiorid (integer)
  - angle_a (float)
  - angle_b (float)

Example:

```pawn
public OnGameModeInit()
{
  CreateCustomInterior("PoliceStation", 243.66, 345.21, 12.78, 9.0, 4564.8, 12.8, 1, 0, 1, 0);
  SetInteriorEntranceCustomAngles(GetLastInteriorIDUsed(), 234.453, 0.23);
  return 1;
}
```
**ClearPlayerInteriorData**
------------------------------------------
- The thing this function does is really simple. Clears interior id data which is assigned to player's data.

Parameters:
 
 - playerid (integer)

**NOTE**: This is called usually on callback *OnPlayerDisconnect*.

Example:

```pawn
public OnPlayerDisconnect(playerid, reason)
{
  ClearPlayerInteriorData(playerid);
  return 1;
}
```
**IsPlayerInCustomInterior**
------------------------------------------
- Also, one simple function - checks if is player in one of custom interiors declared.

- If yes, returns *true*, else returns *false*.

Parameters:

  - playerid (integer)

```pawn
if(IsPlayerInCustomInterior(playerid)) return SendClientMessage(playerid, -1, "You're in interior.");
```

**CreateCustomInteriorEx**
------------------------------------------
- This is just a function successor, this function does the same thing *CreateCustomInterior* does. Only difference is that *CreateCustomInteriorEx* creates 3D label and pickup on entrance and exit point.

Parameters: same as on CreateCustomInterior

## Messages from creator

### Warnings
------------------------------------------
- No warnings - yet.

### Notes
------------------------------------------
***Streamer***

- Make sure you have *streamer.inc* include file for *CreateCustomInteriorEx*.
------------------------------------------

***Making filterscript with d_interiors?***

- Well, I have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *d_interiors*.

------------------------------------------
***Compatibility mode***
- d_interiors have compatibility mode! Enable it using:

```pawn
#define A_INTS_COMPATIBILITY_MODE
#include <d_interiors>
```
It tehnically disables all of custom syntax and keywords, replacing them with upper-case, double-underscore-suffixed versions - so:

```pawn
interior MyInterior(playerid)
{
  return 1;
}
```
... is now:

```pawn
INTERIOR__ MyInterior(playerid)
{
  return 1;
}
```
