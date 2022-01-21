# d_mapeditor.inc

SA:MP Map Editor - edit San Andreas yourself in the game

# How to start to use?

# API (programming interface)

- There are only few functions though. But really important for the system to work, also are really efficient in commands.
## ShowMapEditorMenuToPlayer
- Shows player a dialog with map editor options.
```pawn
 decl Command:mapeditor(playerid, params[])
{
    ShowMapEditorMenuToPlayer(playerid);
    return 1;
}
```
## ShowObjectInfoLabels
- Used to show everyone on the server, in the specified virtual world, object info labels. They contain info about object's ID, object's rotation offset and object's **x, y and z** coordinates!
```pawn
decl Command:labelon(playerid, params[])
{
    ShowObjectInfoLabels(GetPlayerVirtualWorld(playerid));
    return 1;
}
```
## HideObjectInfoLabels
- Used to hide object info labels.
```pawn
decl Command:labeloff(playerid, params[])
{
    HideObjectInfoLabels();
    return 1;
}
```

# Messages from creator

## Warnings

## Notes
