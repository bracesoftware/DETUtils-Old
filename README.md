# List of includes:
List of *stdlibEx* includes.
# a_commands
SA:MP Commands - a "built-in" fast and easy way to create commands.

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

## API ( programming interface )

### Functions

*a_commands.inc* also contains some handy functions, let's see.

**CallLocalCommand**

- This command does nothing besides returning command function call.

Parameters:

   - command_name (string)
   - specifiers (string)
   - command_firstparam (integner)
   - command_secparam (string)
  
Example:

```pawn
CallLocalCommand("mycommand", "is", playerid, inputtext);
```

## Messages from creator

### Warnings

1. Make sure that whenever you create commands using the ``command`` keyword, the command name does not contain capital letters. Otherwise, unfortunately - server will recognize the command as unknown.

### Notes

***Backwards compatibility***
- a_commands also have backwards compatibility, incase you are upgrading from iZCMD/ZCMD, the ``CMD:`` keyword will still work as nothing changed. But, we still recommend creating your future commands using ``command`` and ``alias`` keywords.
