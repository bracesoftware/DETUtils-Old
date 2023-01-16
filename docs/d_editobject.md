# d_editobject.inc
SA:MP Object Edit - New `EditObject()`/`EditPlayerObject()` system with many more features.

[Go back to the home page...](../README.md)

## How to start to use?
- `d_editobject.inc` currently supports only global and player objects. Support for attached objects will be made soon.

- To start editing an object, use `PlayerEditObject`:

```pawn
PlayerEditObject(playerid, objectid);
```

- This will show the player an object editing menu. After the player confirms or cancels an edit, or simply moves the object, callback `OnPlayerEditGlobalObject` with many parameters.

```pawn
public OnPlayerEditGlobalObject(playerid, objectid, response,
		Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
	return 1;
}
```

- If player was editing a player object, `OnPlayerEditPlayerObject` instead.

### Editing response

- Whenever the player interacts with editing menu, `OnPlayerEdit<Global/Player>Object` will be called, with an certain response ID - there are 3 response IDs:

1. `EDITING_RESPONSE_CANCEL` - Player has canceled the changes he has done to the object. Object will be automatically reset to the starting positions.
2. `EDITING_RESPONSE_FINAL` - Object position has been saved and applied. Editing menu will disappear.
3. `EDITING_RESPONSE_UPDATE` - Object's position has changed.

### Update rate

- Update rate is a rate object's position and rotation are changing at whenever player moves the object. Player can change his update rate by interacting with the editing menu, or you can change it using `SetPlayerEditUpdateRate`. Default update rate is `0.1`.

```
SetPlayerEditUpdateRate(playerid, 1.90);
```

