# SA:MP - DETUtils | Library limits

- Here, you can learn more about library limits. Below, you can see a list of DETUtils includes and learn more about limits built into them.

[Go back to home page...](README.md)

# Updates

- In upcoming updates, some limits may be reduced or eventually removed. But, due to existing SA:MP limits, that is not possible in bright future.

Check [open.mp](https://open.mp/) for more information about SA:MP limits!

# ``d_samp.inc`` includes

## d_anticheat.inc

- No limits at the moment.

## d_colours.inc

- No limits at the moment.

## d_commands.inc

### Maximum function name
Include code:
```pawn
#if !defined MAX_FUNC_NAME

#define MAX_FUNC_NAME (32)

#endif
```
- This limits the number of characters in function name, if the number of characters in a certain function's name is larger than **32**, then you will get an error. This is also a Pawn limit, which explains why I've added this definition to my script as well.

## d_fmargs.inc

- No limits at the moment.

## d_interiors.inc

### Maximum number of created interiors
Include code:
```pawn
#if !defined MAX_INTERIORS

#define MAX_INTERIORS 300

#endif
```
- This limits the maximum number of custom interiors that can be created, if you attempt to create an interior with ID 301, function will return **0** - also if you have **detutils_debug** enabled, server will get an ingame warning which tells everyone on the server that maximum number of created interiors has been reached.

## d_outline.inc

- Include file is empty and has no functionality.

## d_visual.inc

### Maximum number of created dropped guns
Include code:
```pawn
#if !defined MAX_DROPPED_GUNS

#define MAX_DROPPED_GUNS 2000

#endif
```

- This limits the maximum number of created dropped gun objects. If you attempt to create a dropped gun with an ID 2001, function will return **0** - also if you have **detutils_debug** enabled, server will get an ingame warning which tells everyone on the server that maximum number of created dropped gun objects has been reached.
