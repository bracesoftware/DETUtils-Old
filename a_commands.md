# a_commands.inc
SA:MP Commands - a "built-in" fast and easy way to create commands.

[Go back to home page...](README.md)

## How to start to use?

### Command declaration

To declare a command, you need to use ``command`` keyword.

Let's see how it works:

```pawn

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

## API ( programming interface )

### Functions

*a_commands.inc* also contains some handy functions, let's see.

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
- a_commands also have backwards compatibility, incase you are upgrading from iZCMD/ZCMD, the ``CMD:`` keyword will still work as nothing changed. But, we still recommend creating your future commands using ``command`` and ``alias`` keywords.

***Compatibility mode***
- a_commands have compatibility mode! Enable it using:

```pawn
#define A_CMDS_COMPATIBILITY_MODE
#include <a_commands>
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
***Making filterscript with a_commands?***
- Well, we have good news for you, because there is also new filterscript support feature. 

- So, if you're making a filterscript - make sure you use:

```pawn
#define FILTERSCRIPT
```
... before including *a_commands*.
