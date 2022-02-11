# SA:MP - DETUtils | Library limits

- Here, you can learn more about library limits. Below, you can see a list of DETUtils includes and learn more about limits built into them.

[Go back to home page...](README.md)

# Updates

- In upcoming updates, some limits may be reduced or eventually removed. But, due to existing SA:MP limits, that is not possible in bright future.

Check [open.mp official resources site](https://open.mp/docs/scripting/resources/limits) for more information about SA:MP limits!

# ``d_samp.inc`` includes
Check all limits below:
## d_anticheat.inc

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
### Maximum prefix length
Include code:
```pawn
decl Prefix:qmark = "?";
```
- Unfortunately, prefix can only contain 1 character.


## d_dmzone.inc

### Maximum number of DM zones
Include code:
```pawn
#define MAX_DM_ZONES 1000
```
- This limits the number of DM zones that can be created.

## d_filequeries.inc

### Maximum number of file queries
Include code:
```pawn
#if !defined MAX_FILE_QUERIES

    #define MAX_FILE_QUERIES 1000

#endif
```
- This limits the number of file queries that can be created. That's why I recomment to DELETE the player file queries when player disconnects.

## d_fmargs.inc

- No limits at the moment.

## d_properties.inc

### Maximum number of created properties
Include code:
```pawn
#if !defined MAX_PROPERTIES

#define MAX_PROPERTIES 300

#endif
```
- This limits the maximum number of custom properties that can be created, if you attempt to create a property with ID 301, function will return **0** - also if you have **detutils_debug** enabled, server will get an ingame warning which tells everyone on the server that maximum number of created properties has been reached.

## d_visual.inc

### Maximum number of created dropped guns
Include code:
```pawn
#if !defined MAX_DROPPED_GUNS

#define MAX_DROPPED_GUNS 2000

#endif
```

- This limits the maximum number of created dropped gun objects. If you attempt to create a dropped gun with an ID 2001, function will return **0** - also if you have **detutils_debug** enabled, server will get an ingame warning which tells everyone on the server that maximum number of created dropped gun objects has been reached.

## d_mapeditor.inc
### Maximum objects
Include code:
```pawn
#define MAX_OBJECTS 1000
```

- This limits the maximum number of created objects on the server. This is also a SA:MP limit.

## d_teams.inc
### Maximum objects
Include code:
```pawn
#define MAX_TEAMS 256
```

- This limits the maximum number of created teams on the server.
