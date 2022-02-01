# Parsing in ``d_commands``

- As I mentioned, parsing is analysing functions.

- In order to provide ``d_commands``' users an easier experience while tracking down bugs, I added new parsing feature to the include - which was VERY hard to make. Took me few days, by the way. What I was talking about is ``code-parse.inc`` include written by Y_Less.

- ``code-parse`` provides tons of useful macros used to analyse script functions. That is also done in ``d_commands``.

# Features

## Scripting

- There is no change in the macro looks. But internally looked at them, there is a another ton of macros hidden in the includes.

## Parser effects

- Now we came to the point, as I said already - few times, parsing is analysing functions, this can be anything related to the functions, but we're talking about the argument counting. Which means, every command's arguments are counted at compile-time and stored in the server cache during run-time, allowing the processor to check for VALID command headers and invalid ones - we're looking for those.

- So, in every example code I declared the command like this:
```pawn
@command(.type = SLASH_COMMAND) COMMAND_NAME(playerid, params[])
{
  SendClientMessage(playerid, -1, "Cool message.");
  // Or some other cool code.
  return 1;
}
```
As you can see, I only provide **playerid** and **params[]**, one integer argument and one array argument - in total 2 arguments. And that is the only one correct way, though you can name ``playerid`` and ``params[]`` different, something like ``player`` and ``parameters`` or whatever alike - you only need to make sure first parameter is the integer and the second one is an array.

- Though, adding more arguments to the header can cause problems such as unexpected crashing and unknown bugs. That's why I added this.

So - whenever you declare a command like this;
```pawn
@command(.type = SLASH_COMMAND) COMMAND_NAME(playerid, params[], &data, Float:coord, _:somethingelse)
{
  return 1;
}
```
... or:
```pawn
@command(.type = SLASH_COMMAND) COMMAND_NAME(playerid)
{
  return 1;
}
```
... or even this:
```pawn
@command(.type = SLASH_COMMAND) COMMAND_NAME()
{
  return 1;
}
```
... and try to execute it in-game; you'll get an error in console saying this:

```
*** [samp-detutils]: (cmd parse) - Calling parse function: 'P@_cmd'
*** [samp-detutils]: (cmd parse) - Parsing a command : cmd with 3 params.
*** [samp-detutils]: (cmd parse) - Met an unexpected or unknown argument in 
the command header while parsing.
Command: cmd
Make sure that your command header looks like this:
@command(...) CMD_NAME__(playerid, params[]) {...}
```

In order to try this; I made the following command (read the comments):
```pawn
@command(.type = SLASH_COMMAND) cmd(playerid, params[], help) // Added `help` in order to test parsing.
{
    // There is no code since it won't get executed anyways,
    // since the parser function for the command will stop the processor
    // from processing the command, aka this code.
    
    return 1; // this code
}
```
