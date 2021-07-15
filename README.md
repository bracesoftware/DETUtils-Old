# a_commands
A little update to SA:MP standard scripting library - a "built-in" fast  and easy way to create commands with actual Pawn syntax.

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

***CallLocalCommand***

- This command does nothing besides returning command function call.

Parameters:

  command_name (string)
  specifiers (string)
  command_firstparam (integner)
  command_secparam (string)
  
Example:

```pawn
CallLocalCommand("mycommand", "is", playerid, inputtext);
```
