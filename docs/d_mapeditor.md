# d_mapeditor.inc

SA:MP Map Editor - Edit San Andreas yourself in the game.

[Go back to the home page...](../README.md)

## How to start to use?

- Look at examples below.

## API (programming interface)

- There are only few functions though. But really important for the system to work, also are really efficient in commands.
### `ShowMapEditorMenuToPlayer`
- Shows player a dialog with map editor options.
```pawn
@command(.type = SLASH_COMMAND) mapeditor(playerid, params[]) 
{
    ShowMapEditorMenuToPlayer(playerid);
    return 1;
}
```
### `ShowObjectInfoLabels`
- Used to show everyone on the server, in the specified virtual world, object info labels. They contain info about object's ID, object's rotation offset and object's **x, y and z** coordinates!
```pawn
@command(.type = SLASH_COMMAND) labelon(playerid, params[])
{
    ShowObjectInfoLabels(GetPlayerVirtualWorld(playerid));
    return 1;
}
```
### `HideObjectInfoLabels`
- Used to hide object info labels.
```pawn
@command(.type = SLASH_COMMAND) labeloff(playerid, params[])
{
    HideObjectInfoLabels();
    return 1;
}
```

## Messages from creator

### Warnings
- No warnings yet.
### Notes
#### Beta version
- This is in beta stage, please, if you find any issues - report them.

#### Object saving and loading
- In order to save your work properly, in your server's **scriptfiles** folder, you need to make another folder called **detutils_objects**. In that folder, *-.ini* files with object information and data are saved. Besides that note, you don't need to worry about anything else - objects are automatically loaded and saved.
