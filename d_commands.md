# d_commands.inc
SA:MP Commands - a "built-in" fast and easy way to create commands.

[Go back to home page...](README.md)

## How to start to use?

### Command declaration

To declare a command, you need to use ``command`` keyword.

Let's see how it works:

```php

command mycommand(playerid, params[])
{
  SendClientMessage(playerid, -1, "{ffffff}Your very first command works!");
  return 1;
}

```

... and - that's it, command is declared, and whenever someone sends */mycommand* to chat, a message saying "Your very first command works!" appears.

### Command aliasing

There is also way to declare alias of a specific command.

You can do it using ``alias`` keyword, an example:

```pawn

alias command mycmd(playerid, params[]) = mycommand;

```

### Command debugging

There is also a way to debug commands!

Advanced debugging can be done using ``debug`` keyword.

Example:

```pawn
debug command mycmd()
{
  print("Command %s successfully called.", GetDebuggedCommandName());
  return 1;
}
```
### Debug states

- For advanced debugging, one ``print`` isn't enough - right? That is why I added command debug states. Command debug is called 3 times after player submits to execute a command, so there are three debug states.

- Debug states:

- ``COMMAND_DEBUG_STATE_RECEIVED`` - command processor received command and command parameters
- ``COMMAND_DEBUG_STATE_READY`` - command is ready to be performed
- ``COMMAND_DEBUG_STATE_PERFORMED`` - command performed successfully

**How to use states?**

- To use states, you need to use **GetCommandDebugState**. Here's how to do it:

```pawn
debug command mycmd ()
{
    if(GetCommandDebugState() == COMMAND_DEBUG_STATE_RECEIVED)
    {
        printf("Command %s received.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_READY)
    {
        printf("Command %s ready.", GetDebuggedCommandName());
        return 1;
    }
    else if(GetCommandDebugState() == COMMAND_DEBUG_STATE_PERFORMED)
    {
        printf("Command %s performed.", GetDebuggedCommandName());
        return 1;
    }
	return 0;
}
```

### Admin commands

*d_commands* also lets you to create admin commands.

You can do it easily and fast mixing ``admin`` and ``command`` keywords.

Example:

```pawn
admin command admincheck(playerid,params[])
{
  SendClientMessage(playerid, -1, "You're admin.");
  return 1;
}
```

**INFO**: If player is not logged in as RCON administrator, function will return *false* (0) and send client message saying: **"SERVER: Unknown command."**

### Commands with custom prefix

*d_commands* also arrive with brand new system with custom-prefixed commands.
Create commands like those using two keywords and one extra parameter - fast and easy.

- Let's see how to do it:

```pawn
prefixed command mycmd(playerid, params[], "!")
{
  SendClientMessage(playerid, -1, "This worked, %s.", ReturnPlayerName(playerid));
  return 1;
}
```

Now, whenever player sends ``!mycmd`` to chat, command will be executed (performed).

**INFO**: To use custom-prefixed commands, you also need to use new built-in **/chatmode** command. This built-in command toggles the ability of a player to execute these commands.

**WARNING**: This type of commands cannot be debugged using ``debug command``.

### Commands with custom permissions

*d_commands* also allows you to create commands that require certain permissions / conditions to be executed. This is really nice feature if you're making administrator system, V.I.P. system or anything else that has to do with the user system.

- Let's see how to create **roles**. To create role you need to use ``create role`` keywords.

- Let's declare some variables:

```pawn
enum Enums
{
  Money,
  Bank,
  Deaths,
  Kills,
	Admin
}

new Player[MAX_PLAYERS][Enums];
```

- Now, let's create a role.

```pawn
create role AdminRole(playerid, Player[playerid][Admin] == 1);
```

- Now, we have our role - let's use it in our command.
- To create role commands, you need to use ``role command`` keywords.

```php
role command clearchat(playerid, params[], AdminRole)
{
	for(new i; i < 20; i++)
		SendClientMessage(playerid, -1, "");

	SendClientMessage(playerid, -1, "You cleared the chat.");
	return 1;
}
```

Now, we created a command which requires ``AdminRole`` role to be executed - performed.

**NOTE**: If role command's conditions are not met, command will return ``0`` (false) and will send client message saying: **"SERVER: Unknown command."**

## API ( programming interface )

### Functions

*d_commands.inc* also contains some handy functions, let's see.

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

1. Make sure that whenever you create commands using the ``command`` keyword, the command name does not contain capital letters. Otherwise, unfortunately - server will recognize the command as unknown.

### Notes

***Backwards compatibility***
- d_commands also have backwards compatibility, incase you are upgrading from iZCMD/ZCMD, the ``CMD:`` keyword will still work as nothing changed. But, I still recommend creating your future commands using ``command`` and ``alias`` keywords.

***Compatibility mode***
- d_commands have compatibility mode! Enable it using:

```pawn
#define A_CMDS_COMPATIBILITY_MODE
#include <DETUTILS\d_commands>
```
It tehnically disables all of custom syntax and keywords, replacing them with upper-case, double-underscore-suffixed versions - so:

```pawn
debug command mycmd()
{
  return 1;
}
```
... is now:

```pawn
DEBUG__COMMAND__ mycmd()
{
  return 1;
}
```
***Making filterscript with d_commands?***
- Well, I have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *d_commands*.
